#ifndef _VCF_TABLEMODEL_H__
#define _VCF_TABLEMODEL_H__
//TableModel.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */




#ifndef _VCF_ABSTRACTMODEL_H__
#include "vcf/ApplicationKit/AbstractModel.h"
#endif // _VCF_ABSTRACTMODEL_H__



namespace VCF{

class TableCellItem;

class TableModelListener;

typedef Enumerator<TableCellItem*> TableRowItemEnumerator;



/**
\class CellID TableModel.h "vcf/ApplicationKit/TableModel.h"
*/
class APPLICATIONKIT_API CellID {
public:
	CellID():row(-1), column(-1){}

	CellID( int r, int c ):row(r), column(c){}

	bool isValid() const {
		return ((row>=0) && (column>=0)) ? true : false;
	}
	operator bool () const {
		return isValid();
	}

	bool operator==( const CellID& rhs ) const {
		return (row == rhs.row) && (column == rhs.column);
	}

	bool operator!=( const CellID& rhs ) const {
		return (row != rhs.row) || (column != rhs.column);
	}

public:
	int row;
	int column;
};



/**
\class TableModel TableModel.h "vcf/ApplicationKit/TableModel.h"
@delegates	
	@del TableModel::TableCellAdded
	@del TableModel::TableCellDeleted
	@del TableModel::TableCellsSelected
	@del TableModel::TableRowsAdded
	@del TableModel::TableRowsDeleted
	@del TableModel::TableColumnsAdded
	@del TableModel::TableColumnsDeleted

*/

class APPLICATIONKIT_API TableModel  {
public:

	virtual ~TableModel(){};

	/**
	@delegate TableCellAdded
	@event TableModelEvent
	*/
	DELEGATE(TableCellAdded)

	/**
	@delegate TableCellDeleted
	@event TableModelEvent
	*/
	DELEGATE(TableCellDeleted)

	/**
	@delegate TableCellsSelected
	@event TableModelEvent
	*/
	DELEGATE(TableCellsSelected)

	/**
	@delegate TableRowAdded
	@event TableModelEvent
	*/
	DELEGATE(TableRowsAdded)

	/**
	@delegate TableRowDeleted
	@event TableModelEvent
	*/
	DELEGATE(TableRowsDeleted)

	/**
	@delegate TableColumnAdded
	@event TableModelEvent
	*/
	DELEGATE(TableColumnsAdded)

	/**
	@delegate TableColumnDeleted
	@event TableModelEvent
	*/
	DELEGATE(TableColumnsDeleted)
	
    virtual void empty() {;}
    virtual void addRow() = 0;

	virtual void insertRow( const uint32& afterRow ) = 0;

	virtual void addRows( const uint32& count ) = 0;

	virtual void deleteRow( const uint32& row ) = 0;

    virtual void addColumn() = 0;

	virtual void insertColumn( const uint32& afterColumn ) = 0;

	virtual void addColumns( const uint32& count ) = 0;

	virtual void deleteColumn( const uint32& column ) = 0;

	virtual bool isCellEditable( const uint32& row, const uint32& column ) = 0;

	virtual TableCellItem* getItem( const uint32& row, const uint32& column ) = 0;

	virtual uint32 getRowCount() = 0;

	virtual uint32 getColumnCount() = 0;

	virtual TableRowItemEnumerator* getRowItemEnumerator( const uint32& row ) = 0;

	/**
	*this is overriden to provide TableModels derivations
	*control over what kind of item get created
	*at any cell in the table.
	*@param uint32 - the row being created
	*/
	virtual TableCellItem* createCell( const uint32& row, const uint32& column ) = 0;

	virtual TableCellItem* setSelectedCell( const bool& val, const uint32& row, const uint32& column ) = 0;

	virtual void setFocusedCell( const uint32& row, const uint32& column ) = 0;

	virtual TableCellItem* getFocusedCell() = 0;


	virtual void setSelectedRange( const bool& val, const uint32& startRow, const uint32& startColumn,
									const uint32& endRow, const uint32& endColumn ) = 0;

	virtual void setFixedColumnsCount( const uint32& count ) = 0;

	virtual void setFixedRowsCount( const uint32& count ) = 0;

	virtual uint32 getFixedColumnsCount() = 0;

	virtual uint32 getFixedRowsCount() = 0;

	virtual void clearSelection() = 0;

	virtual Enumerator<TableCellItem*>* getSelectedCells() = 0;

	virtual CellID getCellIDForItem( TableCellItem* item ) = 0;


};

};


/**
*CVS Log info
*$Log$
*Revision 1.3.4.1  2006/03/14 02:25:47  ddiego
*large amounts of source docs updated.
*
*Revision 1.3  2004/12/01 04:31:38  ddiego
*merged over devmain-0-6-6 code. Marcello did a kick ass job
*of fixing a nasty bug (1074768VCF application slows down modal dialogs.)
*that he found. Many, many thanks for this Marcello.
*
*Revision 1.2.2.3  2004/10/05 03:48:57  kiklop74
*Another minor fix
*
*Revision 1.2.2.2  2004/10/05 02:48:22  kiklop74
*Added needed changes that will enable Borland compiler to compile RTTI for ApplicationKit
*
*Revision 1.2.2.1  2004/09/21 23:41:24  ddiego
*made some big changes to how the base list, tree, text, table, and tab models are laid out. They are not just plain interfaces. The actual
*concrete implementations of them now derive from BOTH Model and the specific
*tree, table, etc model interface.
*Also made some fixes to the way the text input is handled for a text control.
*We now process on a character by character basis and modify the model one
*character at a time. Previously we were just using brute force and setting
*the whole models text. This is more efficent, though its also more complex.
*
*Revision 1.2  2004/08/07 02:49:10  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.3  2004/06/06 07:05:31  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.2  2004/04/29 03:43:14  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:19  ddiego
*migration towards new directory structure
*
*Revision 1.10.2.2  2004/04/26 21:58:21  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.10  2004/04/03 15:48:40  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.9.2.8  2004/03/01 05:58:54  ddiego
*and even MORE updates to the TableControl. Most of the core functionality from Chris Maunder's CGridCtrl has been migrated over, and is functional. Item editing and item dragging is still not done. Had to make a minor change to the AbstractScroallable class to allow it have vertical and/or horizontal delegate's set in order to notify them of position changes. This was needed by the TableControl to properly update the top left non fixed cell calculation. The performance is kind of slow ( :) ) in debug mode, but quite snappy in release.
*
*Revision 1.9.2.7  2004/02/26 05:10:38  ddiego
*more table control work
*
*Revision 1.9.2.6  2004/02/19 04:52:34  ddiego
*more progress made with TableControl
*
*Revision 1.9.2.5  2004/02/15 20:24:01  ddiego
*intial Locales implementation is now checked in. This adds several new classes, namely:
*The LocalePeer, which is the OS generic peer for interfacing with teh OS for lcoale support
*The Locale class which provides locale support for the vcf
*The Win32LocalePeer which provides a basic Win32 implementation for locale support
*The UnicodeString class, which is a near identical class to the std::string class and provides a wrapper around a std::basic_string<wchar_t>. This also adds support for translating to and from ansi strings, and supporting text encoding via a TextEncoder class.
*The TextCodec class which allows for custom text codec for encoding or decoding text.
*The MessageLoader class which is used to provide localized string translation
*The StringsMessageLoader which provides a basic implementation of string loading and translation that is compatible with Apples .strings resource files.
*
*Revision 1.9.2.4  2004/02/02 04:38:36  ddiego
*more table codin'
*
*Revision 1.9.2.3  2004/01/30 22:08:08  ddiego
*more fixes to the table model and table control
*
*Revision 1.9.2.2  2004/01/30 05:08:14  ddiego
*added more rearrangements for the table control
*
*Revision 1.9.2.1  2004/01/29 22:26:47  ddiego
*table fixes, this still needs some more work
*
*Revision 1.9  2003/12/18 05:15:57  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.8.4.1  2003/09/12 00:09:32  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.8  2003/05/17 20:37:04  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.7.16.1  2003/03/23 03:23:45  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.7  2002/05/09 03:10:42  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.6.4.1  2002/04/27 15:42:56  ddiego
*removed ApplicationKit.h and optimized header includes as
*well as adding better include guard support
*
*Revision 1.6  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_TABLEMODEL_H__


