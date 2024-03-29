//Component.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/VFFInputStream.h"
#include "vcf/FoundationKit/Dictionary.h"

static int ComponentTagID = 0;

namespace VCF
{

Component::Component():
	owner_(NULL),
	componentState_(Component::csUnknown | Component::csUsesLocaleStrings),
	tag_(ComponentTagID),
	//action_(NULL),
	settings_(NULL)
{
	ComponentTagID++;
	componentContainer_.initContainer( components_ );

	setCreated();
}

Component::Component( Component* owner ):
	owner_(NULL),
	componentState_(Component::csUnknown | Component::csUsesLocaleStrings),
	tag_(ComponentTagID),
	//action_(NULL),
	settings_(NULL)
{
	ComponentTagID++;
	componentContainer_.initContainer( components_ );

	setCreated();

	owner->addComponent( this );
}

Component::Component( const String& name, Component* owner ):
	owner_(NULL),
	componentState_(Component::csUnknown | Component::csUsesLocaleStrings),
	tag_(ComponentTagID),
	//action_(NULL),
	settings_(NULL)
{
	ComponentTagID++;
	componentContainer_.initContainer( components_ );

	setCreated();

	setName( name );
	owner->addComponent( this );
}

Component::Component( const String& name ):
	owner_(NULL),
	componentState_(Component::csUnknown | Component::csUsesLocaleStrings),
	tag_(ComponentTagID),
	//action_(NULL),
	settings_(NULL)
{
	ComponentTagID++;
	componentContainer_.initContainer( components_ );

	setCreated();

	setName( name );
}



Component::~Component()
{
	delete settings_;
}



void Component::free()
{
	destroy();
	delete this;
}

void Component::destroy()
{
	if ( !(Component::csDestroying & componentState_) ) {
		VCF::ComponentEvent e( this, Component::COMPONENT_DESTROYED );

		handleEvent( &e );
	}

	std::vector<Component*>::iterator componentIter = components_.begin();
	while ( componentIter != components_.end() ){
		Component* component = *componentIter;
		component->free();
		component = NULL;
		componentIter++;
	}
	components_.clear();
}

String Component::getName()
{
	return name_;
}

void Component::setName( const String& name )
{
	name_ = name;
}

void Component::handleEvent( Event* event )
{
	if ( NULL != event ){
		uint32 eventType = event->getType();

		switch ( eventType ){

			case Component::COMPONENT_CREATED:{
				setNormal();

				ComponentEvent* componentEvent = (ComponentEvent*)event;

				afterCreate( componentEvent);
				ComponentCreated( componentEvent );
			}
			break;

			case Component::COMPONENT_DESTROYED:{
				ComponentEvent* componentEvent = (ComponentEvent*)event;

				//notify all the child component of the component destroy
				std::vector<Component*>::iterator it = components_.begin();
				while ( it != components_.end() ){
					Component* child = *it;
					VCF::ComponentEvent e( child, Component::COMPONENT_DESTROYED );
					child->handleEvent( &e );
					it ++;
				}

				beforeDestroy( componentEvent );
				ComponentDestroyed( componentEvent );
			}
			break;

			case Component::COMPONENT_LOADED : {
				ComponentEvent* componentEvent = (ComponentEvent*)event;
				ComponentLoaded( componentEvent );
			}
			break;

			case Component::COMPONENT_SAVED : {
				ComponentEvent* componentEvent = (ComponentEvent*)event;
				ComponentSaved( componentEvent );
			}
			break;
		}
	}
}

void Component::beforeDestroy( ComponentEvent* event )
{
	setComponentState( Component::csDestroying );
}


uint32 Component::getComponentState() const
{
	return componentState_;
}

void Component::setComponentState( const uint32& componentState )
{
	//check for design mode here since we have async creation handling
	//at the moment
	bool designing = isDesigning();

	componentState_ = componentState;

	if ( !(componentState & Component::csDesigning) ) {
		if ( designing ) {
			componentState_ |= Component::csDesigning;
		}
		else {
			componentState_ &= ~Component::csDesigning;
		}
	}

	std::vector<Component*>::iterator it = components_.begin();
	while ( it != components_.end() ){
		Component* child = *it;
		child->setComponentState( componentState_ );
		it ++;
	}
}

void Component::addComponent( Component* component )
{
	//prevent adding duplicates
	std::vector<Component*>::iterator found  = std::find( components_.begin(), components_.end(), component );
	if ( found == components_.end() ){
		if ( NULL != component->owner_ ) {
			component->owner_->removeComponent( component );
		}
		component->owner_ = this;
		components_.push_back( component );

		ComponentEvent e(this,Component::COMPONENT_ADDED);
		e.setChildComponent( component );
		ComponentAdded( &e );
		handleEvent( &e );
	}
}

void Component::addNewComponent( Component* component )
{
	addComponent( component );
}

void Component::removeComponent( Component* component )
{
	std::vector<Component*>::iterator found  = std::find( components_.begin(), components_.end(), component );
	if ( found != components_.end() ){
		ComponentEvent e(this,Component::COMPONENT_REMOVED);
		e.setChildComponent( component );
		ComponentRemoved( &e );
		handleEvent( &e );

		(*found)->owner_ = NULL;
		components_.erase( found );
	}
}

void Component::removeFromOwner( const bool& freeInstance )
{
	Component* owner = getOwner();
	if ( NULL != owner ) {
		owner->removeComponent( this );
		if ( freeInstance ) {
			free();
		}
	}
}

Enumerator<Component*>* Component::getComponents()
{
	return componentContainer_.getEnumerator();
}

uint32 Component::getComponentCount() const
{
	return components_.size();
}

Component* Component::findComponent( const String& componentName, const bool& recursive )
{
	Component* result = NULL;

	if ( componentName == this->getName() ) {
		result = this;
	}
	else {

		//this is very slow !! for the moment !
		std::vector<Component*>::iterator it = components_.begin();
		while ( it != components_.end() ){
			Component* child = *it;
			if ( child->getName() == componentName ){
				result = child;
				break;
			}
			else if (recursive) {
				//call the child component's findComponent
				result = child->findComponent( componentName, recursive );
				if ( NULL != result ) {
					break;
				}
			}
			++ it;
		}
	}

	return result;
}

void Component::afterCreate( ComponentEvent* event )
{

}


/**
*this is a recursive funtion to try and bind a variable name with a particular
*component. This is potentially a fairly expensize operation, because we have to
*recursively search through all the components of the starting component, and
*then through all of it's child controls if the component is a Control Container.
*/
bool Component::bindVariable( Component** variablePtr, const String& variableName )
{
	*variablePtr = NULL;

	bool result = (variableName == getName());
	if ( true == result ) {
		*variablePtr = this;
	}
	if ( false == result ) {
		/**
		*search components first
		*if that fails then try controls - if we are a container
		*/
		Enumerator<Component*>* components = getComponents();
		while ( true == components->hasMoreElements() ) {
			Component* component = components->nextElement();
			if ( variableName == component->getName() ) {
				*variablePtr = component;
				result = true;
			}
			else {
				result = component->bindVariable( variablePtr, variableName );
			}
			if ( true == result ) {
				break;
			}
		}
	}
	return result;
}

bool Component::registerComponent( const String& componentClassName, const String& category )
{
	bool result = false;

	Class* componentClass = ClassRegistry::getClass( componentClassName );
	if ( NULL != componentClass ){
		std::map<String,std::vector<Class*>*>::iterator found = registeredComponentMap->find( category );
		std::vector<Class*>* categoryList = NULL;
		if ( found == registeredComponentMap->end() ){
			categoryList = new std::vector<Class*>();
			registeredCategory->push_back( category );
		}
		else {
			categoryList = found->second;
		}
		if ( NULL != categoryList ){
			categoryList->push_back( componentClass );
			(*Component::registeredComponentMap)[category] = categoryList;
			result = true;
		}
	}

	return result;
}

Enumerator<Class*>* Component::getComponentClassesForCategory( const String& category )
{
	Enumerator<Class*>* result = NULL;
	//registeredCompContainer
	std::map<String,std::vector<Class*>*>::iterator found = registeredComponentMap->find( category );
	if ( found != registeredComponentMap->end() ){
		std::vector<Class*>* categoryList = found->second;
		if ( NULL != categoryList ){
			registeredCompContainer->initContainer( *categoryList );
			result = registeredCompContainer->getEnumerator();
		}
	}
	return result;
}

Enumerator<String>* Component::getRegisteredComponentCategories()
{
	registeredCategoryContainer->initContainer( *registeredCategory );
	return registeredCategoryContainer->getEnumerator();
}

void Component::initComponentRegistrar()
{
	registeredComponentMap = new std::map<String,std::vector<Class*>*>();
	registeredCategory = new std::vector<String>();
	registeredCategoryContainer = new EnumeratorContainer<std::vector<String>,String>();
	registeredCompContainer = new EnumeratorContainer<std::vector<Class*>,Class*>();
}

void Component::clearRegistedComponents()
{
	std::map<String,std::vector<Class*>*>::iterator it = registeredComponentMap->begin();
	while ( it != registeredComponentMap->end() ){
		std::vector<Class*>* compList = it->second;
		delete compList;
		compList = NULL;
		it++;
	}
	registeredComponentMap->clear();

	registeredCategory->clear();

	delete registeredCategoryContainer;
	registeredCategoryContainer = NULL;

	delete registeredCompContainer;
	registeredCompContainer = NULL;

	delete registeredComponentMap;
	registeredComponentMap = NULL;

	delete registeredCategory;
	registeredCategory = NULL;
}

void Component::loading()
{
	componentState_ |= Component::csLoading;
}

void Component::saving()
{
	componentState_ |= Component::csSaving;
}

void Component::loaded()
{
	if ( componentState_ & Component::csLoading ) {
		componentState_ &= ~Component::csLoading;
		ComponentEvent e( this, Component::COMPONENT_LOADED );

		handleEvent( &e );
	}
}

void Component::saved()
{
	if ( componentState_ & Component::csSaving ) {
		componentState_ &= ~Component::csSaving;
		ComponentEvent e( this, Component::COMPONENT_SAVED );
		handleEvent( &e );
	}
}

bool Component::isNormal() const
{
	return (Component::csNormal & componentState_) ? true : false;
}

bool Component::isDestroying() const
{
	return (Component::csDestroying & componentState_) ? true : false;
}

bool Component::isLoading() const
{
	return (Component::csLoading & componentState_) ? true : false;
}

bool Component::isSaving() const
{
	return (Component::csSaving & componentState_) ? true : false;
}

bool Component::isDesigning() const
{
	return (Component::csDesigning & componentState_) ? true : false;
}

bool Component::isCreated() const
{
	return (Component::csCreated & componentState_) ? true : false;
}

void Component::setCreated()
{
	setComponentState( Component::csCreated );
}

void Component::setNormal()
{
	setComponentState( Component::csNormal );
}

void Component::setDestroying()
{
	setComponentState( Component::csDestroying );
}

void Component::setDesigning( const bool& designing )
{
	if ( designing != isDesigning() ) {
		if ( designing ) {
			setComponentState( componentState_ | Component::csDesigning );
		}
		else {
			setComponentState( componentState_ & ~Component::csDesigning );
		}
	}
}


bool Component::getUseLocaleStrings() const
{
	return (Component::csUsesLocaleStrings & componentState_) ? true : false;
}

void Component::setUseLocaleStrings( const bool& val )
{
	if ( val ) {
		setComponentState( componentState_ | Component::csUsesLocaleStrings );
	}
	else {
		setComponentState( componentState_ & ~Component::csUsesLocaleStrings );
	}

	std::vector<Component*>::iterator componentIter = components_.begin();
	while ( componentIter != components_.end() ){
		Component* component = *componentIter;
		component->setUseLocaleStrings( val );
		componentIter++;
	}
}

String Component::generateComponentName(Component* instance)
{
	VCF_ASSERT( NULL != instance );

	String result = instance->getName();
	if ( result.empty() ) {

		result = instance->getClassName();

		if ( result.empty() ) {
			result = Format( "instance_0x%p" ) % instance;
		}
		else {
			String tmp = result;
			size_t idx = tmp.find_last_of( "::" );
			if ( idx != String::npos ) {
				tmp = tmp.substr( idx +1, tmp.length()-(idx+1) );
			}

			result = tmp;

			result.erase(0,1);

			result = StringUtils::lowerCase(tmp.substr(0,1)) + result;
		}


		Component* root = instance->getOwner();
		if ( NULL != root ) {
			while ( root != NULL ) {
				if ( root->getOwner() != NULL ) {
					root = root->getOwner();
				}
				else {
					break;
				}
			}

			bool done = false;
			int count = 0;
			String tmp = result;
			while ( !done ) {
				if ( root->findComponent( result, true ) != NULL ) {
					count ++;
					result = tmp + Format("%d") % count;					
				}
				else {
					done = true;
				}
			}
		}
	}



	

	return result;
}

void Component::initFromFragment( const String& vffString )
{
	Class* clazz = getClass(); //note that if we have no Class instance for this component,
	//then the RTTI look up won't work and we won't be able to process the vff fragment. 
	//if that's the case then we simply ignore it and do nothing.
	if ( clazz != NULL ) {
		if ( !vffString.empty() ) {

			//check for object block

			String vffContent = vffString;
			StringUtils::trimWhiteSpaces( vffContent );
			if ( vffContent.length() > 6 ) {
				if ( StringUtils::lowerCase(vffContent.substr(0,6)) != "object" ) {
					String name = getName();
					if ( name.empty() ) {
						name = Component::generateComponentName(this);
					}

					vffContent = String("object ") + name + " : " + clazz->getClassName() + " \r\n" +
									vffContent + "\r\n end";

				}
			}

			BasicInputStream bis( vffContent );
			VFFInputStream vis( &bis );
			vis.readComponentInstance( this );
		}
	}
	else {
		StringUtils::trace( "No Class found for this component!\n" );
	}
}

void Component::initFromResource()
{
	Component::initComponent(this);
}

void Component::initComponent( Component* instance, Class* clazz, Class* rootClazz, ResourceBundle* resBundle )
{
	if ( (clazz->getID() == COMPONENT_CLASSID) || (clazz == rootClazz) ) {
		return;
	}

	Component::initComponent( instance, clazz->getSuperClass(), rootClazz, resBundle );

	Component::initComponent( instance, clazz, resBundle );
}

void Component::initComponent( Component* instance, ResourceBundle* resBundle )
{
	Component::initComponent( instance, instance->getClass(), NULL, resBundle );
}

void Component::initComponent( Component* instance, Class* clazz, ResourceBundle* resBundle )
{
	if ( (clazz->getID() == COMPONENT_CLASSID) ) {
		return;
	}

	String resourceName;
	ResourceBundle* bundle = resBundle;
	if ( NULL == bundle ) {
		bundle = System::getResourceBundle();
	}

	String vffContents;

	resourceName = clazz->getClassName();

	//strip out namespace
	size_t pos = resourceName.find( "::" );
	while ( pos != String::npos ) {
		resourceName = resourceName.replace( pos, 2, "." );
		pos = resourceName.find( "::" );
	}

	vffContents = bundle->getVFF(resourceName);


	if ( !vffContents.empty() ) {
		BasicInputStream bis( vffContents );
		VFFInputStream vis( &bis );
		vis.readNewComponentInstance( instance );
	}
}


Component* Component::createComponentFromResources( Class* clazz, Class* rootClazz, ResourceBundle* resBundle )
{
	Component* result = NULL;

	VCF_ASSERT( clazz != NULL );

	try {
		Object* newObject = clazz->createInstance();

		result = dynamic_cast<Component*>(newObject);

		if ( NULL != result ) {


			Component::initComponent( result, clazz, rootClazz, resBundle );

			result->loaded();
		}
		else {
			delete newObject;
		}
	}
	catch ( BasicException& ) {

	}

	return result;
}

Dictionary* Component::getSettings() const
{
	return settings_;
}

uint32 Component::getSettingNames( std::vector<String>& names )
{
	if ( NULL != settings_ ) {
		Dictionary::Enumerator* items = settings_->getEnumerator();

		while ( items->hasMoreElements() ) {
			Dictionary::pair item = items->nextElement();

			const String& name = item.first;

			names.push_back( name );
		}
	}
	return names.size();
}

ComponentSetting* Component::getSetting( const String& name ) const
{
	ComponentSetting* result = NULL;

	if ( isLoading() && NULL == settings_ ) {
		settings_ = new Dictionary();
		settings_->setOwnsObjectValues(true);
	}

	if ( NULL != settings_ ) {

		if ( isLoading() && !settings_->keyExists( name ) ) {
			result = new ComponentSetting();
			settings_->insert( name, result );
		}

		VariantData& v = settings_->get( name );

		if ( pdUndefined != v.type ) {
			VCF_ASSERT( v.type == pdObject );

			if ( pdObject == v.type ) {
				Object* object = v;
				//verify that we are REALLY a setting!
				result = dynamic_cast<ComponentSetting*>(object);
			}
		}

	}

	return result;
}

ComponentSetting* Component::assignSetting( const String& settingName, const String& valueName,
										const VariantData& v )
{
	ComponentSetting* result = NULL;

	result = getSetting( settingName );

	if ( NULL == result ) {
		result = new ComponentSetting();
	}


	result->name = valueName;
	result->value = v;

	setSetting( settingName, result );

	return result;
}

ComponentSetting* Component::assignSetting( const String& settingName, const String& valueName )
{
	ComponentSetting* result = NULL;

	result = getSetting( settingName );

	if ( NULL == result ) {
		result = new ComponentSetting();
	}


	result->name = valueName;

	Class* clazz = this->getClass();
	VCF_ASSERT( NULL != clazz );

	if ( NULL == clazz ) {
		delete result;

		throw RuntimeException( MAKE_ERROR_MSG_2("No class was found for this component instance. Did you register the component with the ClassRegistry?") );
	}

	Property* property = clazz->getProperty( valueName );

	VCF_ASSERT( NULL != property );

	if ( NULL == property ) {
		delete result;

		throw RuntimeException( MAKE_ERROR_MSG_2("Invalid value name for setting, no such property found that corresponds to this name.") );
	}

	VariantData* propVal = property->get();
	if ( propVal != NULL ) {
		result->value = *propVal;
	}

	setSetting( settingName, result );

	return result;
}

void Component::setSetting( const String& settingName, ComponentSetting* setting )
{
	if ( NULL == settings_ ) {
		settings_ = new Dictionary();
		settings_->setOwnsObjectValues(true);
	}

	settings_->insert( settingName, setting );
}


void Component::getAppNameAndKey( String& appName, String& key )
{
	const CommandLine& cmdLine = FoundationKit::getCommandLine();

	FilePath programName = cmdLine.getArgument(0);

	appName = programName.getBaseName();
	String companyName;
	key = "Software\\";

	ResourceBundle* bundle = System::getResourceBundle();
	if ( NULL != bundle ) {
		ProgramInfo* info = bundle->getProgramInfo();
		if ( NULL != info ) {
			String s = info->getProgramName();
			if ( !s.empty() ) {
				appName = s;
			}

			s = info->getCompany();
			if ( !s.empty() ) {
				companyName = s;
			}

			delete info;
		}
	}


	//need a way to generate platform
	//neutral reg keys!!!!!
	//These are window specific for now!
	key = String("Software\\");	
	if ( !companyName.empty() ) {
		key += companyName + "\\";
	}
	key += appName + "\\";
}


void Component::initializeSettings( const bool& recursive )
{

	if ( NULL != settings_ ) {
		Registry reg;

		String appName;
		String key;

		getAppNameAndKey( appName, key );


		Class* clazz = this->getClass();

		VCF_ASSERT( NULL != clazz );

		if ( NULL == clazz ) {
			throw RuntimeException( MAKE_ERROR_MSG_2("No class was found for this component instance. Did you register the component with the ClassRegistry?") );
		}


		Dictionary::Enumerator* items = settings_->getEnumerator();

		while ( items->hasMoreElements() ) {
			Dictionary::pair item = items->nextElement();

			const String& name = item.first;

			VariantData& v = item.second;

			if ( pdObject == v.type ) {
				Object* obj = v;
				if ( NULL != obj ) {
					ComponentSetting* setting = dynamic_cast<ComponentSetting*>(obj);
					if ( NULL != setting ) {
						if ( ComponentSetting::sUser == setting->scope ) {
							reg.setRoot( RKT_CURRENT_USER );
						}
						else if ( ComponentSetting::sLocal == setting->scope ) {
							reg.setRoot( RKT_LOCAL_MACHINE );
						}

						if ( reg.openKey( key + setting->section ) ) {
							try {

								Property* property = clazz->getProperty( setting->name );

								if ( NULL != property ) {
									setting->value.type = property->getType();
								}

								switch ( setting->value.type ) {
									case pdString : {
										setting->value = reg.getStringValue(name);
									}
									break;

									case pdULong : case pdLong : case pdUInt : case pdInt : {
										setting->value = reg.getIntValue(name);
									}
									break;

									case pdDouble : {
										setting->value = (double)reg.getIntValue(name);
									}
									break;

									case pdFloat : {
										setting->value = (float)reg.getIntValue(name);
									}
									break;

									case pdBool : {
										setting->value = reg.getBoolValue(name);
									}
									break;

									default : {
										StringUtils::trace("Unsupported data type for: " + name);
										continue; //skip to next element
									}
									break;
								}

								if ( NULL != property ) {
									property->set( &setting->value );
								}
							}
							catch (...){
								StringUtils::trace("No value found for: " + name);
								continue; //skip to next element
							}
						}
					}
				}
			}
		}
	}


	if ( recursive ) {
		std::vector<Component*>::iterator it = components_.begin();
		while ( it != components_.end() ){
			Component* child = *it;

			child->initializeSettings( recursive );

			++ it;
		}
	}
}

void Component::storeSettings( const bool& recursive )
{
	VCF_ASSERT( !isDestroying() );

	if ( NULL != settings_ ) {
		Registry reg;

		String appName;
		String key;

		getAppNameAndKey( appName, key );


		Class* clazz = this->getClass();

		VCF_ASSERT( NULL != clazz );

		if ( NULL == clazz ) {
			throw RuntimeException( MAKE_ERROR_MSG_2("No class was found for this component instance. Did you register the component with the ClassRegistry?") );
		}


		Dictionary::Enumerator* items = settings_->getEnumerator();

		while ( items->hasMoreElements() ) {
			Dictionary::pair item = items->nextElement();
			const String& name = item.first;

			VariantData& v = item.second;

			if ( pdObject == v.type ) {
				Object* obj = v;
				if ( NULL != obj ) {
					ComponentSetting* setting = dynamic_cast<ComponentSetting*>(obj);
					if ( NULL != setting ) {
						if ( ComponentSetting::sUser == setting->scope ) {
							reg.setRoot( RKT_CURRENT_USER );
						}
						else if ( ComponentSetting::sLocal == setting->scope ) {
							reg.setRoot( RKT_LOCAL_MACHINE );
						}

						if ( reg.openKey( key + setting->section, true ) ) {
							Property* property = clazz->getProperty( setting->name );

							if ( NULL != property ) {
								VariantData* propVal = property->get();
								if ( propVal ) {
									setting->value = *propVal;
								}
							}

							try {
								switch ( setting->value.type ) {
									case pdString : {
										String val = setting->value;
										reg.setValue( val, name);
									}
									break;

									case pdULong : case pdLong : case pdUInt : case pdInt : {
										uint32 val = setting->value;
										reg.setValue( val, name);
									}
									break;

									case pdDouble : {
										uint32 val = (double)setting->value;
										reg.setValue( val, name);
									}
									break;

									case pdFloat : {
										uint32 val = (float)setting->value;
										reg.setValue( val, name);
									}
									break;

									case pdBool : {
										bool val = setting->value;
										reg.setValue( val, name);
									}
									break;

									default : {
										StringUtils::trace("Unsupported data type for: " + name);
										continue; //skip to next element
									}
									break;
								}
							}
							catch (...){
								StringUtils::trace("No value found for: " + name);
								continue; //skip to next element
							}
						}
					}
				}
			}
		}
	}

	if ( recursive ) {
		std::vector<Component*>::iterator it = components_.begin();
		while ( it != components_.end() ){
			Component* child = *it;

			child->storeSettings( recursive );

			++ it;
		}
	}
}

bool Component::generatePropertyValue( const String& fullPropertyName, Property* property, VariantData* value, String& strValue )
{
	return false;
}

} // namespace VCF

/**
$Id$
*/
