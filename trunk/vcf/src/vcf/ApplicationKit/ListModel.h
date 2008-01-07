#ifndef _VCF_LISTMODEL_H__
#define _VCF_LISTMODEL_H__
//ListModel.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif



namespace VCF  {




	enum ListModelEvents {
		LIST_MODEL_CONST		=		900,
		lmeContentsDeleted = CUSTOM_EVENT_TYPES + LIST_MODEL_CONST + 1,
		lmeItemChanged,
		lmeItemAdded,
		lmeItemRemoved,
		lmeSubItemAdded,
		lmeSubItemRemoved,
		lmeSubItemChanged,
	};

/**
\class ListModelEvent ListModel.h "vcf/ApplicationKit/ListModel.h"
*/
class APPLICATIONKIT_API ListModelEvent : public ModelEvent {
public:
	ListModelEvent( Object* source ):ModelEvent(source),item(NULL),index((uint32)-1),subIndex((uint32)-1){}

	ListModelEvent( Object* source, const uint32& eventType ):ModelEvent(source,eventType),
		item(NULL){}

	ListModelEvent( Object* source, VariantData* i ):ModelEvent(source),item(i),index((uint32)-1),subIndex((uint32)-1){}

	ListModelEvent( Object* source, const uint32& eventType, VariantData* i ):ModelEvent(source,eventType),
		item(i),index((uint32)-1),subIndex((uint32)-1){}

	ListModelEvent( const ListModelEvent& rhs ):ModelEvent(rhs),item(NULL),index((uint32)-1),subIndex((uint32)-1) {
		*this = rhs;
	}

	virtual ~ListModelEvent(){}


	ListModelEvent& operator=( const ListModelEvent& rhs ) {
		Event::operator =( rhs );
		item = rhs.item;
		index = rhs.index;
		subIndex = rhs.subIndex;
		return *this;
	}

	virtual Object* clone( bool deep=false ) {
		return new ListModelEvent(*this);
	}

	bool isValidIndex() const ;

	VariantData* item;
	uint32 index;
	uint32 subIndex;
};






/**
*ListModelDelegate
handles the following:
\li onListModelContentsChanged
\li onItemAdded
\li onItemDeleted
*/
typedef Delegate1<ListModelEvent*> ListModelDelegate; 
typedef ListModelDelegate::ProcedureType ListModelHandler;

#define LISTMODEL_CLASSID "820C1F79-4FDD-42A8-9B80-C17E050569F5"


/**
\class ListModel ListModel.h "vcf/ApplicationKit/ListModel.h"
The List model is a interface for describing what a model that implements
a list of items should do. 
@delegates
	@del ListModel::ContentsChanged
	@del ListModel::ItemAdded
	@del ListModel::ItemRemoved
*/
class APPLICATIONKIT_API ListModel : public Model  {
public:

	
	enum {
		IndexNotFound = (uint32)-1,
		InvalidIndex = (uint32)-1
	};


	ListModel(){

	};

	virtual ~ListModel(){};

	/**
	@delegate ItemAdded fired when an item is added to the list model
	@event ListModelEvent
	*/
	DELEGATE(ListModelDelegate,ItemAdded)

	/**
	@delegate ItemDeleted fired when an item is removed from the list model
	@event ListModelEvent
	*/
	DELEGATE(ListModelDelegate,ItemRemoved)

	
	virtual VariantData getValue( const VariantData& key=VariantData::null() );

	virtual String getValueAsString( const VariantData& key=VariantData::null() );

	virtual void setValue( const VariantData& value, const VariantData& key=VariantData::null() );

	virtual void setValueAsString( const String& value, const VariantData& key=VariantData::null() );



	virtual void add( const VariantData& item ) = 0;
	virtual void insert( const uint32 & index, const VariantData& item ) = 0;
    
	virtual void remove( const VariantData& item ) = 0;
	virtual void removeAtIndex( const uint32& index ) = 0;

	virtual VariantData get( const uint32& index ) = 0;	
	virtual String getAsString( const uint32& index ) = 0;

	virtual uint32 getIndexOf( const VariantData& item ) = 0;

	virtual void set( const uint32& index, const VariantData& item, bool addMissingValues ) = 0;
	virtual void setAsString( const uint32& index, const String& item, bool addMissingValues ) = 0;

	virtual bool getItems( std::vector<VariantData>& items ) = 0;
	virtual Enumerator<VariantData>* getItems() = 0;

	virtual bool getRange( const uint32& start, const uint32& end, std::vector<VariantData>& items ) = 0;	

	/**
	*returns the number of the items in the model
	*/
	virtual uint32 getCount() = 0;

	virtual bool supportsSubItems() {
		return false;
	}

	virtual void insertSubItem( const uint32& index, const uint32 & subItemIndex, const VariantData& value ) {}
	virtual void removeSubItem( const uint32& index, const uint32 & subItemIndex ){}

	virtual VariantData getSubItem( const uint32& index, const uint32& subItemIndex ) {		
		return VariantData::null();
	}

	virtual String getSubItemAsString( const uint32& index, const uint32& subItemIndex ) {
		return String();
	}

	virtual void setSubItem( const uint32& index, const uint32& subItemIndex, const VariantData& value, bool addMissingValues ){}

	virtual void setSubItemAsString( const uint32& index, const uint32& subItemIndex, const String& value, bool addMissingValues ){}

	virtual uint32 getSubItemsCount( const uint32& index ) {
		return 0;	
	}

	virtual bool getSubItems( const uint32& index, std::vector<VariantData>& items ){
		items.clear();
		return false;
	}



	void insertSubItemAtKey( const String& key, const VariantData& value ) {
		size_t pos = key.find(",");
		if ( pos != String::npos ) {
			uint32 idx = StringUtils::fromStringAsUInt( key.substr(0,pos) );
			uint32 idx2 = StringUtils::fromStringAsUInt( key.substr(pos+1,key.size()-(pos+1)) );

			insertSubItem( idx, idx2, value );
		}
	}

	void removeSubItemAtKey( const String& key ) {
		size_t pos = key.find(",");
		if ( pos != String::npos ) {
			uint32 idx = StringUtils::fromStringAsUInt( key.substr(0,pos) );
			uint32 idx2 = StringUtils::fromStringAsUInt( key.substr(pos+1,key.size()-(pos+1)) );

			removeSubItem( idx, idx2 );
		}
	}

	VariantData getSubItemAtKey( const String& key ) {		
		size_t pos = key.find(",");
		if ( pos != String::npos ) {
			uint32 idx = StringUtils::fromStringAsUInt( key.substr(0,pos) );
			uint32 idx2 = StringUtils::fromStringAsUInt( key.substr(pos+1,key.size()-(pos+1)) );

			return getSubItem( idx, idx2 );
		}

		return VariantData::null();
	}

	String getSubItemAsStringAtKey( const String& key ) {		
		size_t pos = key.find(",");
		if ( pos != String::npos ) {
			uint32 idx = StringUtils::fromStringAsUInt( key.substr(0,pos) );
			uint32 idx2 = StringUtils::fromStringAsUInt( key.substr(pos+1,key.size()-(pos+1)) );

			return getSubItemAsString( idx, idx2 );
		}

		return String();
	}

	void setSubItemAtKey( const String& key, const VariantData& value, bool addMissingValues ) {
		size_t pos = key.find(",");
		if ( pos != String::npos ) {
			uint32 idx = StringUtils::fromStringAsUInt( key.substr(0,pos) );
			uint32 idx2 = StringUtils::fromStringAsUInt( key.substr(pos+1,key.size()-(pos+1)) );

			setSubItem( idx, idx2, value, addMissingValues );
		}
	}

	void setSubItemAsStringAtKey( const String& key, const String& value, bool addMissingValues ) {
		size_t pos = key.find(",");
		if ( pos != String::npos ) {
			uint32 idx = StringUtils::fromStringAsUInt( key.substr(0,pos) );
			uint32 idx2 = StringUtils::fromStringAsUInt( key.substr(pos+1,key.size()-(pos+1)) );

			setSubItemAsString( idx, idx2, value, addMissingValues );
		}
	}

	uint32 getSubItemsCountAtKey( const String& key ) {
		return getSubItemsCount( StringUtils::fromStringAsUInt(key) );	
	}
};








inline bool ListModelEvent::isValidIndex() const 
{
	return index != ListModel::InvalidIndex;
}



inline VariantData ListModel::getValue( const VariantData& key )
{
	if ( key.isInteger() ) {
		return get( key );
	}

	return Model::getValue();
}

inline String ListModel::getValueAsString( const VariantData& key )
{
	if ( key.isInteger() ) {
		return getAsString( key );
	}

	return Model::getValueAsString();
}

inline void ListModel::setValue( const VariantData& value, const VariantData& key )
{
	if ( key.isInteger() ) {
		set( key, value, false );
	}
}

inline void ListModel::setValueAsString( const String& value, const VariantData& key )
{
	if ( key.isInteger() ) {
		setAsString( key, value, false );
	}
}


};


#endif // _VCF_LISTMODEL_H__

/**
$Id$
*/
