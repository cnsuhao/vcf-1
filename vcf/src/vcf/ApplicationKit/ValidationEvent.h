#ifndef _VCF_VALIDATIONEVENT_H__
#define _VCF_VALIDATIONEVENT_H__
//ValidationEvent.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */


namespace VCF{
/**
\class ValidationEvent ValidationEvent.h "vcf/ApplicationKit/ValidationEvent.h"  
*/
class APPLICATIONKIT_API ValidationEvent : public VCF::Event {
public:

	ValidationEvent( Object* source ): Event(source),validationSuccessful_(true){}

	ValidationEvent( const ValidationEvent& rhs ):Event(rhs) {
		*this = rhs;
	}

	virtual ~ValidationEvent() {}


	ValidationEvent& operator=( const ValidationEvent& rhs ) {
		validationSuccessful_ = rhs.validationSuccessful_;
		return *this;
	}

	bool isValidationSuccessful() {
		return this->validationSuccessful_;
	}


	void setValidationSuccessful( const bool& validationSuccessful ) {
		this->validationSuccessful_ = validationSuccessful;
	}

	virtual Object* clone( bool deep=false ) {
		return new ValidationEvent(*this);
	}
private:
	bool validationSuccessful_;
};






/**
*ModelValidationEventHandler
*handles the following:
*onModelValidate
*/
template <class SOURCE_TYPE>
class ModelValidationEventHandler : public EventHandlerInstance<SOURCE_TYPE,ValidationEvent> {
public:
	ModelValidationEventHandler( SOURCE_TYPE* source,
		_typename_ EventHandlerInstance<SOURCE_TYPE,ValidationEvent>::OnEventHandlerMethod handlerMethod,
		const String& handlerName="") :
			EventHandlerInstance<SOURCE_TYPE,ValidationEvent>( source, handlerMethod, handlerName ) {

	}

};



};


#endif // _VCF_VALIDATIONEVENT_H__

/**
$Id$
*/
