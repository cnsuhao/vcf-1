#ifndef _VCF_LISTITEM_H__
#define _VCF_LISTITEM_H__
//ListItem.h

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
/** @interface */

#define LISTITEM_CLASSID		"ED88C0AB-26AB-11d4-B539-00C04F0196DA"

#define LISTITEM_EVENT_SUBTITEM_ADDED		CUSTOM_EVENT_TYPES + ITEM_CONST + 7
#define LISTITEM_EVENT_SUBTITEM_DELETED		CUSTOM_EVENT_TYPES + ITEM_CONST + 8
#define LISTITEM_EVENT_SUBTITEM_CHANGED		CUSTOM_EVENT_TYPES + ITEM_CONST + 9



/**
\class ListItem ListItem.h "vcf/ApplicationKit/ListItem.h"
*/
class APPLICATIONKIT_API ListItem : public Item {
public:

	class APPLICATIONKIT_API SubItem : public Object {
	public:
		SubItem( ListItem* ownerItem ){
			ownerItem_ = ownerItem;
		}

		virtual ~SubItem(){};

		void* getData() {
			return data_;
		}

		void setData( void* data ) {
			data_ = data;
			ownerItem_->subItemChanged( this );
		}

		String getCaption() {
			if ( ownerItem_->getUseLocaleStrings() ) {
				return System::getCurrentThreadLocale()->translate( caption_ );
			}

			return caption_;
		}

		void setCaption( const String& caption ) {
			caption_ = caption;
			ownerItem_->subItemChanged( this );
		}

		virtual bool canPaint() {
			return false;
		}

		virtual void paint( GraphicsContext* context, Rect* rect, const uint32& column ){

		}

	protected:
		String caption_;
		void* data_;
		ListItem* ownerItem_;
	};


	DELEGATE(ItemDelegate,SubItemChanged);
	DELEGATE(ItemDelegate,SubItemAdded);
	DELEGATE(ItemDelegate,SubItemDeleted);


	ListItem(){

	};

	virtual ~ListItem(){};
	

	virtual String getCaption() = 0;

	virtual void setCaption( const String& caption ) = 0;

	virtual void addSubItem( const String& caption, void* data ) = 0;

	virtual void addSubItem( SubItem* subItem ) = 0;

	virtual void removeSubItem( const uint32& index ) = 0;

	virtual Enumerator<SubItem*>* getSubItems() = 0;

	virtual SubItem* getSubItem( const uint32& index ) = 0;

	virtual uint32 getSubItemCount() = 0;

	virtual void subItemChanged( SubItem* item ) = 0;
};

};


#endif // _VCF_LISTITEM_H__

/**
$Id$
*/
