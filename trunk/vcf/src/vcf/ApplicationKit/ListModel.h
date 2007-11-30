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


#define LIST_MODEL_CONST				900

#define LIST_MODEL_CONTENTS_DELETED		CUSTOM_EVENT_TYPES + LIST_MODEL_CONST + 1
#define LIST_MODEL_ITEM_CHANGED			CUSTOM_EVENT_TYPES + LIST_MODEL_CONST + 2
#define LIST_MODEL_ITEM_ADDED			CUSTOM_EVENT_TYPES + LIST_MODEL_CONST + 3
#define LIST_MODEL_ITEM_DELETED			CUSTOM_EVENT_TYPES + LIST_MODEL_CONST + 4


/**
\class ListModelEvent ListModel.h "vcf/ApplicationKit/ListModel.h"
*/
class APPLICATIONKIT_API ListModelEvent : public Event {
public:
	ListModelEvent( Object* source ):Event(source),item(NULL){}

	ListModelEvent( Object* source, const uint32& eventType ):Event(source,eventType),
		item(NULL){}

	ListModelEvent( Object* source, VariantData* i ):Event(source),item(i){}

	ListModelEvent( Object* source, const uint32& eventType, VariantData* i ):Event(source,eventType),
		item(i){}

	ListModelEvent( const ListModelEvent& rhs ):Event(rhs),item(NULL) {
		*this = rhs;
	}

	virtual ~ListModelEvent(){}


	ListModelEvent& operator=( const ListModelEvent& rhs ) {
		Event::operator =( rhs );
		item = rhs.item;
		return *this;
	}

	virtual Object* clone( bool deep=false ) {
		return new ListModelEvent(*this);
	}

	VariantData* item;
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
a list of items should do. It does not \emnot inherit from the Model class
directly. This is to allow different implementations different base classes.
For example, you might have a simple list model that inherits/implements the 
Model class, and the ListModel class. This would be suitable for most controls.
However you might want a fancier implementation, perhaps that is based 
off of the Document and ListModel classes. This would still allow you to 
use the same control with either style.
@delegates
	@del ListModel::ModelEmptied
	@del ListModel::ModelValidate
	@del ListModel::ContentsChanged
	@del ListModel::ItemAdded
	@del ListModel::ItemR
*/
class APPLICATIONKIT_API ListModel : public Model  {
public:

	ListModel(){

	};

	virtual ~ListModel(){};

    /**
	@delegate  ContentsChanged
	@event ListModelEvent
	@eventtype LIST_MODEL_CONTENTS_DELETED
	*/
	DELEGATE(ListModelDelegate,ContentsChanged)

	/**
	@delegate ItemAdded fired when an item is added to the list model
	@event ListModelEvent
	*/
	DELEGATE(ListModelDelegate,ItemAdded)

	/**
	@delegate ItemDeleted fired when an item is removed from the list model
	@event ListModelEvent
	*/
	DELEGATE(ListModelDelegate,ItemDeleted)

	

	virtual void addItem( const VariantData& item ) = 0;
	virtual void insertItem( const uint32 & index, const VariantData& item ) = 0;
    
	virtual void deleteItem( const VariantData& item ) = 0;
	virtual void deleteItemAtIndex( const uint32 & index ) = 0;

	virtual VariantData getItem( const uint32& index ) = 0;	
	virtual String getItemAsString( const uint32& index ) = 0;

	virtual void setItem( const uint32& index, const VariantData& item ) = 0;
	virtual void setItemAsString( const uint32& index, const String& item ) = 0;

	virtual bool getItems( std::vector<VariantData>& items ) = 0;

	/**
	*returns the number of the items in the model
	*/
	virtual uint32 getCount() = 0;
};

}


#endif // _VCF_LISTMODEL_H__

/**
$Id$
*/
