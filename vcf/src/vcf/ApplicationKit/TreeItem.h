#ifndef _VCF_TREEITEM_H__
#define _VCF_TREEITEM_H__
//TreeItem.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */




namespace VCF {

class Color;


#define TREEITEM_CLASSID		"3126B223-2819-11d4-B53A-00C04F0196DA"
/**
\class TreeItem TreeItem.h "vcf/ApplicationKit/TreeItem.h" 
*/
class APPLICATIONKIT_API TreeItem : public Item {
public:

	class APPLICATIONKIT_API SubItem : public Object {
	public:
		SubItem( TreeItem* ownerItem ) : data_(NULL){
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
			return caption_;
		}

		void setCaption( const String& caption ) {
			caption_ = caption;
			ownerItem_->subItemChanged( this );
		}

		virtual bool canPaint() {
			return false;
		}

		virtual void paint( GraphicsContext* context, Rect* paintRect ) {

		}

	protected:
		String caption_;
		void* data_;
		TreeItem* ownerItem_;
	};


	TreeItem(){

	};

	virtual ~TreeItem(){};

	virtual Color* getTextColor() = 0;

	virtual void setTextColor(Color* color) = 0;

	virtual void setTextBold(const bool& bold) = 0;

	virtual bool getTextBold() = 0;

	virtual bool isLeaf() = 0;

	virtual bool isRoot() = 0;

	virtual bool isExpanded() = 0;

	/* expand this tree item.
	*@param const bool& isExpanded, true if it expands, false to collapse it.
	*/
	virtual void expand( const bool& isExpanded ) = 0;

	/* expand this tree item.and all its children recursively.
	*@param const bool& isExpanded, true to expand, false to collapse.
	*/
	virtual void expandAllChildren( const bool& isExpanded ) = 0;

	virtual TreeItem* getParent() = 0;

	virtual void setParent( TreeItem* parent ) = 0;

	virtual TreeItem* getNextChildNodeItem() = 0;

	virtual TreeItem* getPrevChildNodeItem() = 0;

	virtual String getCaption() = 0;

	virtual ulong32 getLevel() = 0;

	virtual void setCaption( const String& caption ) = 0;

	virtual uint32 getChildCount() = 0;
	
	virtual Enumerator<TreeItem*>* getChildren() = 0;

	virtual void addChild( TreeItem* child ) = 0;

	virtual void insertChild( const unsigned long& index, TreeItem* child ) = 0;

	virtual void deleteChild( TreeItem* child ) = 0;

	virtual void deleteChildAtIndex( const unsigned long& index ) = 0;

	virtual void clearChildren() = 0;

	virtual long getSelectedImageIndex() = 0;

	virtual void setSelectedImageIndex( const long& selectedImageIndex ) = 0;

	virtual long getExpandedImageIndex() = 0;

	virtual void setExpandedImageIndex( const long& expandedImageIndex ) = 0;

	virtual void addSubItem( const String& caption, void* data ) = 0;

	virtual void addSubItem( SubItem* subItem ) = 0;

	virtual void removeSubItem( const ulong32& index ) = 0;

	virtual Enumerator<SubItem*>* getSubItems() = 0;

	virtual SubItem* getSubItem( const ulong32& index ) = 0;

	virtual ulong32 getSubItemCount() = 0;

	virtual void subItemChanged( SubItem* item ) = 0;
};


}; //namespace VCF


/**
*CVS Log info
*$Log$
*Revision 1.3.2.1  2006/03/14 02:25:47  ddiego
*large amounts of source docs updated.
*
*Revision 1.3  2005/07/09 23:14:56  ddiego
*merging in changes from devmain-0-6-7 branch.
*
*Revision 1.2.4.2  2005/06/29 03:46:13  ddiego
*more osx tree and list coding.
*
*Revision 1.2.4.1  2005/01/31 02:08:05  marcelloptr
*member function expandAllChildren() added
*
*Revision 1.2  2004/08/07 02:49:10  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.3  2004/06/06 07:05:31  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.2  2004/04/29 03:43:15  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:19  ddiego
*migration towards new directory structure
*
*Revision 1.16.4.1  2004/04/26 21:58:21  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.16  2003/12/18 05:15:57  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.15.4.1  2003/09/12 00:09:32  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.15  2003/05/17 20:37:04  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.14.2.2  2003/03/23 03:23:45  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.14.2.1  2003/03/12 03:09:48  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.14  2003/02/26 04:30:38  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.13.14.2  2002/12/27 23:04:33  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.13.14.1  2002/12/02 00:38:34  ddiego
*more fixes to get the ApplicationKit to compile under mingw. Everything now
*compiles OK at this point.
*
*Revision 1.13  2002/05/09 03:10:42  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.12.4.1  2002/04/27 15:43:05  ddiego
*removed ApplicationKit.h and optimized header includes as
*well as adding better include guard support
*
*Revision 1.12  2002/03/13 01:26:26  ddiego
*fixes to the TreeListControl
*plus fix for bug [ 529012 ] typecombo crash in the ComboBoxControl. Caused
*by not checking a null pointer in the UIToolkits' methods for getting the
*next and previous control
*
*Revision 1.11  2002/02/27 04:16:11  ddiego
*add sub items to TreeItem class for teh tree list control
*added fixes to the RemoteObject stuff
*
*Revision 1.10  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_TREEITEM_H__


