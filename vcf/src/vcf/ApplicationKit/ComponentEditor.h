#ifndef _VCF_COMPONENTEDITOR_H__
#define _VCF_COMPONENTEDITOR_H__
//ComponentEditor.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


namespace VCF  {

class Command;
class Component;
class Control;

/**
\par
A ComponentEditor is an interface used to edit
an entire component at once, as opposed to a PropertyEditor
which only edits a single property of a specific component or
object.
*/
class APPLICATIONKIT_API ComponentEditor : public Interface  {
public:
	virtual ~ComponentEditor(){};

	enum ComponentAttributes {
		caNone						= 0x00000,
		caSeparator					= 0x10000,
		caHasParentIndex			= 0x00001,
		caUsesModalDialogForEditing	= 0x00002,
	};

	/**
	This is called immediately after the component has been
	created, after the caller has made the setComponent() call
	on the editor
	*/
	virtual void initialize() = 0;

	/**
	This method returns a mask of potential attributes
	for the command at the given index.
	*/
	virtual int getAttributes( const ulong32& index ) = 0;

	/**
	Returns the index value of the command's parent
	if one exists. If no parent exists, then the value
	returned is -1. Most comamnds will \em not have a 
	parent. However this is used if you have a complex
	set of commands that make sense to nest in a heirarchy.
	*/
	virtual int getCommandParentIndex( const ulong32& index ) = 0;

	/**
	Retreives a new command instance associated with this index
	@param ulong32 index of the command to retrieve
	@return Command* returns a \em NEW instance of the 
	Command object to be associated with the given index. 
	\par
	\em Note: It is the \em callers responsibility
	to clean up memory and the caller owns the command 
	after this call.
	*/
	virtual Command* createCommand( const ulong32& index ) = 0;

	/**
	Returns the number of unique commands associated with this
	component editor
	@return ulong32 the number of commands for the editor
	*/
	virtual ulong32 getCommandCount() = 0;

	/**
	Returns the editors default command index. This is
	the command that will be executed when the component is
	double clicked on. Return a value of -1 to indicate that 
	there is no default command index.
	*/
	virtual int getDefaultCommandIndex() = 0;

	/**
	@return Component the component this Editor is currently attached
	to.
	*/
	virtual Component* getComponent() = 0;

	/**
	Sets the component for this editor
	*/
	virtual void setComponent( Component* component ) = 0;

	virtual void copy() = 0;

	//attributes 

	bool isSeparator( const ulong32& index ) {
		return (getAttributes( index ) & ComponentEditor::caSeparator) ? true : false;
	}

	bool hasParentIndex( const ulong32& index ) {
		return (getAttributes( index ) & ComponentEditor::caHasParentIndex) ? true : false;
	}

	bool usesModalDialogForEditing( const ulong32& index ) {
		return (getAttributes( index ) & ComponentEditor::caUsesModalDialogForEditing) ? true : false;
	}

};


/**
\par
A ControlEditor is an additional interface used to edit
an entire \em Control instance at once, as opposed to a 
PropertyEditor which only edits a single property of a 
specific component or object. 
\par
The ControlEditor interface provides several extra methods 
specific to editing controls.
*/
class APPLICATIONKIT_API ControlEditor : public Interface  {
public:
	virtual ~ControlEditor() {};

	/**
	indicates whether the passed in parent is OK for this editor's
	control to use.
	@param Control* a pointer to the potential parent to be
	evaluated by the editor for this control.
	@return bool returns false if the parent is unacceptable, for instance
	if it were the wrong type of class, or true if it is OK to use the parent
	for this control.
	*/
	virtual bool isParentValid( Control* parent ) = 0;

	/**
	@return Control the control this Editor is currently attached
	to.
	*/
	virtual Control* getControl() = 0;

	/**
	Sets the control for this editor
	*/
	virtual void setControl( Control* control ) = 0;

	/**
	called from the designer whenever a mouse down event is generated by
	the control in design mode.
	*/
	virtual void mouseDown( MouseEvent* event ) = 0;

	/**
	called from the designer whenever a mouse move event is generated by
	the control in design mode.
	*/
	virtual void mouseMove( MouseEvent* event ) = 0;

	/**
	called from the designer whenever a mouse up event is generated by
	the control in design mode.
	*/
	virtual void mouseUp( MouseEvent* event ) = 0;

	/**
	called from the designer whenever a mouse double click event is generated 
	by the control in design mode.
	*/
	virtual void mouseDblClick( MouseEvent* event ) = 0;
};

}; //end of namespace VCF


/**
*CVS Log info
*$Log$
*Revision 1.2.6.1  2005/08/28 05:14:17  ddiego
*small changes to component editor class.
*
*Revision 1.2  2004/08/07 02:49:06  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.3  2004/06/06 07:05:29  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.2  2004/04/29 03:43:12  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:15  ddiego
*migration towards new directory structure
*
*Revision 1.4.4.1  2004/04/26 21:58:18  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.4  2003/12/18 05:15:56  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.3.26.2  2003/09/21 04:15:34  ddiego
*moved the cvs info data to teh bottom of the header instead of the
*top so it is easier to get to the actual header class declarations
*instead of having to wade through all the cvs info stuff.
*
*Revision 1.3.26.1  2003/09/12 00:09:32  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.3  2002/02/15 03:18:39  ddiego
*minor niggles to make the VCF Builder compiles
*
*Revision 1.2  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_COMPONENTEDITOR_H__

