#ifndef _VCF_DEFAULTTREEITEM_H__
#define _VCF_DEFAULTTREEITEM_H__
//DefaultTreeItem.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */


#ifndef _VCF_TREEITEM_H__
#	include "vcf/ApplicationKit/TreeItem.h"
#endif // _VCF_TREEITEM_H__


namespace VCF
{

class TreeModel;

#define DEFAULTTREEITEM_CLASSID		"3126B224-2819-11d4-B53A-00C04F0196DA"

class APPLICATIONKIT_API DefaultTreeItem : public TreeItem {
public:
	enum TreeEvents {
		teItemExpanded = ITEM_EVENT_CHANGED + 200
	};

	DefaultTreeItem( const String& caption, Control* owningControl, TreeModel* model );

	DefaultTreeItem( const String& caption );

	DefaultTreeItem();

	virtual ~DefaultTreeItem();

	DELEGATE(ItemPaint);
	DELEGATE(ItemChanged);
	DELEGATE(ItemSelected);
	DELEGATE(ItemAdded);
	DELEGATE(ItemDeleted);

	virtual void addItemPaintHandler( EventHandler* handler ){
		ItemPaint += handler;
	}

	virtual void addItemChangedHandler( EventHandler* handler ){
		ItemChanged += handler;
	}

	virtual void addItemSelectedHandler( EventHandler* handler ){
		ItemSelected += handler;
	}

	virtual void addItemAddedHandler( EventHandler* handler ){
		ItemAdded += handler;
	}

	virtual void addItemDeletedHandler( EventHandler* handler ){
		ItemDeleted += handler;
	}

	virtual void removeItemPaintHandler( EventHandler* handler ){
		ItemPaint -= handler;
	}

	virtual void removeItemChangedHandler( EventHandler* handler ){
		ItemChanged -= handler;
	}

	virtual void removeItemSelectedHandler( EventHandler* handler ){
		ItemSelected -= handler;
	}

	virtual void removeItemAddedHandler( EventHandler* handler ){
		ItemAdded -= handler;
	}

	virtual void removeItemDeletedHandler( EventHandler* handler ){
		ItemDeleted -= handler;
	}


	virtual bool containsPoint( Point * pt );

    virtual unsigned long getIndex();

    virtual void* getData();

	virtual void setData( void* data );

    virtual Color* getTextColor();

    virtual void setTextColor(Color* color);

    virtual void setTextBold(const bool& bold);

    virtual bool getTextBold();

    virtual bool isLeaf();

	virtual bool isRoot();

    virtual TreeItem* getParent();

	virtual void setParent( TreeItem* parent );

    virtual TreeItem* getNextChildNodeItem();

    virtual TreeItem* getPrevChildNodeItem();

    virtual String getCaption();

	virtual void setCaption( const String& caption );

	virtual Enumerator<TreeItem*>* getChildren();

	void init();

	virtual void addChild( TreeItem* child );

	virtual void insertChild( const unsigned long& index, TreeItem* child );

	virtual void deleteChild( TreeItem* child );

	virtual void deleteChildAtIndex( const unsigned long& index );

	virtual void clearChildren();

	virtual Model* getModel();

	virtual void setModel( Model* model );

	virtual void setIndex( const unsigned long& index );

	virtual void paint( GraphicsContext* context, Rect* paintRect );

	virtual bool isSelected();

	virtual void setSelected( const bool& selected );

	virtual bool isExpanded() {
		return isExpanded_;
	}

	virtual void expand( const bool& isExpanded );

	virtual ulong32 getLevel();

	virtual Rect* getBounds() {
		return &bounds_;
	}

	virtual Control* getControl() {
		return owningControl_;
	}

	virtual long getImageIndex() {
		return imageIndex_;
	}

	virtual void setImageIndex( const long& imageIndex );

	virtual void setControl( Control* control );

	virtual long getSelectedImageIndex() {
		return selectedImageIndex_;
	}

	virtual void setSelectedImageIndex( const long& selectedImageIndex );

	virtual long getExpandedImageIndex() {
		return expandedImageIndex_;
	}

	virtual void setExpandedImageIndex( const long& expandedImageIndex );

	virtual bool canPaint() {
		return true;
	}

	virtual long getState(){
		return state_;
	}

	virtual void setState( const long& state );

	virtual void setBounds( Rect* bounds );

	/**
	*not supported
	*/
	virtual long getStateImageIndex(){
		return stateImageIndex_;
	};

	virtual void setStateImageIndex( const long& index );

	virtual void addSubItem( const String& caption, void* data );

	virtual void addSubItem( SubItem* subItem );

	virtual void removeSubItem( const ulong32& index );

	virtual Enumerator<SubItem*>* getSubItems() {
		return enumSubItemsContainer_.getEnumerator();
	}

	virtual SubItem* getSubItem( const ulong32& index );

	virtual ulong32 getSubItemCount() {
		return subItems_.size();
	}

	virtual void subItemChanged( SubItem* item );

	virtual long getTag() {
		return tag_;
	}

	virtual void setTag( const long& tag ) {
		tag_ = tag;
	}

protected:
	virtual void changed( const ulong32& eventType=ITEM_EVENT_CHANGED  );

    bool textBold_;
    Color TextColor_;
	String caption_;
	TreeItem* parent_;
	void* userData_;
	TreeModel* treeModel_;
	long state_;
	unsigned long index_;
	EnumeratorContainer<std::vector<TreeItem*>,TreeItem*> enumContainer_;
	std::vector<TreeItem*> childNodeItems_;

	EnumeratorContainer<std::vector<SubItem*>,SubItem*> enumSubItemsContainer_;
	std::vector<SubItem*> subItems_;

	bool selected_;
	bool isExpanded_;
	Rect bounds_;
	Control* owningControl_;
	long imageIndex_;
	long selectedImageIndex_;
	long expandedImageIndex_;
	long stateImageIndex_;
	long tag_;
};

};


/**
*CVS Log info
*$Log$
*Revision 1.2  2004/08/07 02:49:07  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.3  2004/06/06 07:05:30  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.2  2004/04/29 03:43:13  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:16  ddiego
*migration towards new directory structure
*
*Revision 1.26.2.1  2004/04/26 21:58:19  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.26  2004/04/03 16:09:30  ddiego
*Found some more merge issues that needing resolving.
*
*Revision 1.25  2003/12/18 05:15:57  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.24.2.2  2003/09/17 21:23:24  ddiego
*added adjustmnents to win32 tree peer and drop target
*
*Revision 1.24.2.1  2003/09/12 00:09:32  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.24  2003/08/09 02:56:42  ddiego
*merge over from the devmain-0-6-1 branch
*Changes
*Features:
*-Added additional implementation to better support the MVC architecture in
*the VCF
*
*-Added a Document/View architecure that is similar to MFC's or NextSteps's
*Doc/View architectures
*
*-Integrated the Anti Grain Graphics library into the GraphicsKit. There is
*now basic support for it in terms of drawing vector shapes
*(fills and strokes). Image support will come in the next release
*
*-Added several documented graphics tutorials
*
*Bugfixes:
*
*[ 775744 ] wrong buttons on a dialog
*[ 585239 ] Painting weirdness in a modal dialog ?
*[ 585238 ] Modal dialog which makes a modal Dialog
*[ 509004 ] Opening a modal Dialog causes flicker
*[ 524878 ] onDropped not called for MLTcontrol
*
*Plus an issue with some focus and getting the right popup window to activate
*has also been fixed
*
*Revision 1.23.2.1  2003/06/30 02:53:15  ddiego
*Allow getting the selected filter from a CommonFileDialog
*Added a quitCurrentEventLoop to the UIToolkit to allow programatic
*termination of a program if there is no main window specified
*added a getTag method to the Item class
*
*Revision 1.23  2003/05/17 20:37:03  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.22.2.2  2003/03/23 03:23:45  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.22.2.1  2003/03/12 03:09:32  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.22  2003/02/26 04:30:37  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.21.14.3  2003/02/24 05:42:17  ddiego
*moved the code for the VariantData calss into it's own header
*migrated to the new event style using Delegates instead of relying on
*the ugly macros that we were using before - same functionality though
*made sure everything still works and compiles, including neccessary
*changes in the VCF Builder so that it creates code in the new style
*This changes to teh new style of using Delegates completes task 58837
*
*Revision 1.21.14.2  2002/12/27 23:04:31  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.21.14.1  2002/12/02 00:38:34  ddiego
*more fixes to get the ApplicationKit to compile under mingw. Everything now
*compiles OK at this point.
*
*Revision 1.21  2002/05/09 03:10:42  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*

*Revision 1.18.4.1  2002/04/27 15:42:14  ddiego
*removed ApplicationKit.h and optimized header includes as
*well as adding better include guard support
*

*Revision 1.18  2002/02/27 04:16:11  ddiego
*add sub items to TreeItem class for teh tree list control
*added fixes to the RemoteObject stuff
*
*Revision 1.17  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_DEFAULTTREEITEM_H__


