#ifndef _VCF_TREECONTROL_H__
#define _VCF_TREECONTROL_H__
//TreeControl.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */




#ifndef _VCF_TREEMODEL_H__
#	include "vcf/ApplicationKit/TreeModel.h"
#endif // _VCF_TREEMODEL_H__

#ifndef _VCF_TREEITEM_H__
#	include "vcf/ApplicationKit/TreeItem.h"
#endif // _VCF_TREEITEM_H__

#ifndef _VCF_TREEMODELEVENT_H__
#	include "vcf/ApplicationKit/TreeModelEvent.h"
#endif // _VCF_TREEMODELEVENT_H__




namespace VCF {


class TreePeer;

class ImageList;

class ModelEvent;


#define TREECONTROL_CLASSID			"ED88C09C-26AB-11d4-B539-00C04F0196DA"

#define TREEITEM_SELECTED	CUSTOM_EVENT_TYPES + ITEM_CONST + 20
#define TREEITEM_EXPANDED	CUSTOM_EVENT_TYPES + ITEM_CONST + 21

class APPLICATIONKIT_API TreeControl : public VCF::Control {
public:

	TreeControl();
	virtual ~TreeControl();


	enum TreeControlEvents {
		ITEM_STATECHANGE_REQUESTED = CUSTOM_EVENT_TYPES + ITEM_CONST + 10
	};

	DELEGATE(ItemSelected);
	DELEGATE(ItemStateChangeRequested);
	DELEGATE(ItemExpanded);

	virtual void handleEvent( Event* event );

	double getItemIndent();

	void setItemIndent( const double& indent );

	void setTreeModel(TreeModel * model);

	TreeModel* getTreeModel();

	ImageList* getImageList();

	ImageList* getStateImageList();

	void setImageList( ImageList* imageList );

	void setStateImageList( ImageList* imageList );

	virtual void paint( GraphicsContext * context );

	void init();

	TreeItem* findItem( Point* pt );

	void addItem( TreeItem* parent, TreeItem* item );

	TreeItem* addItem( TreeItem* parent, const String& caption=L"", const ulong32 imageIndex=0 );

	void removeItem( TreeItem* item );

	TreeItem* getSelectedItem();

	Rect getItemImageRect( TreeItem* item );

	bool getAllowLabelEditing();

	void setAllowLabelEditing( const bool& allowLabelEditing );
protected:
	TreeItem* hitTestForItem( Point* pt, TreeItem* item );

	void onTreeItemPaint( ItemEvent* event );

	void onTreeRootNodeChanged( TreeModelEvent* event );

	void onTreeNodeAdded( TreeModelEvent* event );

	void onTreeNodeDeleted( TreeModelEvent* event );

	void onModelEmptied( ModelEvent* event );


	TreePeer * treePeer_;
	ImageList* imageList_;
	ImageList* stateImageList_;
	TreeModel* treeModel_;
	TreeItem* currentSelectedItem_;


};

}; //namespace VCF


/**
*CVS Log info
*$Log$
*Revision 1.2.4.2  2004/12/22 03:35:21  marcelloptr
*just reformatting
*
*Revision 1.2  2004/08/07 02:49:10  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.5  2004/07/22 04:18:58  ddiego
*fixed bug 995642 delete LoalePeer in Locale, and added some miscellaneous changes to the QTPlayer. Also fixing (not finished yet) a bug that
*prevents the TreePeer from being properly notified when the tree model's
*item is deleted.
*
*Revision 1.1.2.4  2004/07/16 05:07:18  ddiego
*added support for editing labels on a tree control
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
*Revision 1.21.4.1  2004/04/26 21:58:21  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.21  2003/12/18 05:15:57  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.20.2.3  2003/09/12 00:09:32  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.20.2.2  2003/09/06 19:45:45  ddiego
*changes to ensure that the destroy() is properly called.
*Destructors were moved back to pbulic scope in case that was causing a bug.
*Moving them all(all teh component derived classes) to private scope causes
*a complete failure in hte VC6 compiler. Alas...
*So destructors are present, and modal dialogs can still be created on the
*stack, but almost any other component should be created on the heap, and
*gotten rid of via free() NOT using operator delete directly.
*also moved the vcs info to the end of the file for some of the headers
*This will be an ongoing process.
*
*Revision 1.20.2.1  2003/09/05 21:03:39  ddiego
*moved the various control destructor's to protected scope
*migrated code into destroy() overridden methods
*----------------------------------------------------------------------
*
*Revision 1.20  2003/08/09 02:56:42  ddiego
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
*Revision 1.19.2.1  2003/06/28 04:43:20  ddiego
*cleaned up the vcf/include/events directory and got rid of files, moving
*some of the various event handler template classes into the same header
*that the event handler's event is associated with
*also made some changes to properly take advantage of a Control's View, if it
*is set.
*
*Revision 1.19  2003/05/17 20:37:04  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.18.2.1  2003/03/12 03:09:47  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.18  2003/02/26 04:30:38  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.17.8.2  2003/02/24 05:42:18  ddiego
*moved the code for the VariantData calss into it's own header
*migrated to the new event style using Delegates instead of relying on
*the ugly macros that we were using before - same functionality though
*made sure everything still works and compiles, including neccessary
*changes in the VCF Builder so that it creates code in the new style
*This changes to teh new style of using Delegates completes task 58837
*
*Revision 1.17.8.1  2002/12/25 22:38:00  ddiego
*more stupid fixes to get rid of the damn gcc no newline warning...grrr...
*
*Revision 1.17  2002/09/12 03:26:03  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.16.6.1  2002/09/05 04:31:46  ddiego
*fixed hte bug in hte VCFInputStream, nested class instances will now
*read in correctly.
*Also added code to properly update the name manager whenever a new form is
*loaded up to prevent name collision within ina a form class. Fixed
*a bit of selection code in the TreeControl class as well.
*
*Revision 1.16  2002/05/09 03:10:42  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.15.4.1  2002/04/27 15:43:02  ddiego
*removed ApplicationKit.h and optimized header includes as
*well as adding better include guard support
*
*Revision 1.15  2002/02/20 04:07:49  ddiego
*consolidated event handling code a bit
*introduced a virtual handleEvent() method to Component
*clean up some of the event constants, so they are now localized in the
*appropriate control classes.
*
*Revision 1.14  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_TREECONTROL_H__


