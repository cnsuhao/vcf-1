#ifndef _VCF_WIN32OBJECT_H__
#define _VCF_WIN32OBJECT_H__
//Win32Object.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


namespace VCF
{

#define SIMPLE_VIEW				WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN
#define BORDERED_VIEW			WS_CHILD | WS_BORDER | WS_CLIPSIBLINGS | WS_CLIPCHILDREN
#define SIMPLE_DIALOG			WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN
#define FRAME_WINDOW			WS_OVERLAPPEDWINDOW

class Control;

class APPLICATIONKIT_API Win32Object : public ObjectWithEvents
{
public:
	Win32Object();
	virtual ~Win32Object();

	void registerWin32Class( const String& className, WNDPROC wndProc );

	static void addRegisterWin32Class( const String& className );

	/**
	*Checks whether the class has been registered. Performs a
	*std::find() using the registeredWindowClasses_ static list
	*/
	bool isRegistered();

	/**
	*called before the create window is called. Overide this to change the
	*styleMask_ and exStyleMask_ values for determing the initial look of the window
	*/
	virtual void createParams();

	/**
	*This is where the window is actually created. Called from constructors
	*/
	void init();

	virtual LRESULT handleEventMessages( UINT message, WPARAM wParam, LPARAM lParam, WNDPROC defaultWndProc = NULL);

	static Win32Object* getWin32ObjectFromHWND( HWND hwnd );

	static void registerWin32Object( Win32Object* wndObj );

	HWND getHwnd();

	LRESULT defaultWndProcedure( UINT message, WPARAM wParam, LPARAM lParam );

	void setCreated( const bool& creationComplete );

	bool isCreated();

	void setPeerControl( Control* control );

	Control* getPeerControl();

	virtual bool acceptsWMCommandMessages(){
		return false;
	}
protected:
	void destroyWindowHandle();

	static std::vector< String > registeredWindowClasses_;
	static std::map<HWND, Win32Object*> windowMap_;
	DWORD styleMask_;
	DWORD exStyleMask_;
	/**
	*this actually contains the current window proc
	*/
	WNDPROC wndProc_;
	/**
	*this contains the window proc used for window
	*subclassing or just performing the default
	*behaviour. By default it is set
	*to point to ::DefWindowProc()
	*/
	WNDPROC defaultWndProc_;
	HWND hwnd_;
	bool created_;
	Control* peerControl_;
};



};


/**
*CVS Log info
*$Log$
*Revision 1.1.2.3  2004/06/06 07:05:31  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.2  2004/04/29 03:43:16  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:21  ddiego
*migration towards new directory structure
*
*Revision 1.13.4.2  2004/04/26 21:58:44  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.13.4.1  2004/04/21 02:17:23  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.13  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.12.2.2  2003/10/31 05:06:23  ddiego
*added toolbar impl
*
*Revision 1.12.2.1  2003/09/12 00:09:33  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.12  2003/08/09 02:56:44  ddiego
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
*Revision 1.11.2.1  2003/05/27 04:45:32  ddiego
*doing some code cleanup to fix some bugs in the way dialogs and popups
*work in Win32 port. Cleaned up the ControlPeer and DialogPeer interfaces
*a bit.
*
*Revision 1.11  2003/05/17 20:37:13  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.10.22.2  2003/03/23 03:23:50  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.10.22.1  2003/03/12 03:11:25  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.10  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_WIN32OBJECT_H__


