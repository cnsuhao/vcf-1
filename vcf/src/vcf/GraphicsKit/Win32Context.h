/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.23.4.1  2004/04/26 21:58:43  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.23  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.22.2.2  2003/10/28 04:06:11  ddiego
*updated the GraphicsContext and ContextPeer classes to support
*slider control drawing. adjusted the Slider control accordingly.
*Also changed some of the GraphicsKit headers to conform to the
*current header style.
*
*Revision 1.22.2.1  2003/09/05 21:03:39  ddiego
*moved the various control destructor's to protected scope
*migrated code into destroy() overridden methods
*----------------------------------------------------------------------
*
*Revision 1.22  2003/08/09 02:56:44  ddiego
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
*Revision 1.21.2.2  2003/06/16 03:09:39  ddiego
*beginning to add support for AGG into the VCF GraphicsKit
*added some missing files
*added some changes to the new version of xmake
*
*Revision 1.21.2.1  2003/06/05 03:48:53  ddiego
*added a way to get part of a graphics context into an image - no
*implementation yet.
*
*Revision 1.21  2003/05/17 20:37:12  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.20.2.3  2003/05/13 03:57:13  ddiego
*cleaned up the GraphicsKit, got rid of some old crap files, cleaned
*up the ContextPeer so that tehre are fewer methods to implement, and
*moved the repetitive fillPath and strokePath code that was copied into
*all the context peers back into the GraphicsContext where it belongs
*
*Revision 1.20.2.2  2003/03/23 03:23:50  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.20.2.1  2003/03/12 03:11:09  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.20  2003/02/26 04:30:40  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.19.2.4  2003/02/24 05:42:18  ddiego
*moved the code for the VariantData calss into it's own header
*migrated to the new event style using Delegates instead of relying on
*the ugly macros that we were using before - same functionality though
*made sure everything still works and compiles, including neccessary
*changes in the VCF Builder so that it creates code in the new style
*This changes to teh new style of using Delegates completes task 58837
*
*Revision 1.19.2.3  2003/01/08 00:19:46  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.19.2.2  2002/12/28 21:51:18  marcelloptr
*Fixes and improvements for WM_COPYDATA, Point, Rect, Size, GraphicsContext and StringUtils
*
*Revision 1.19.2.1  2002/12/27 23:04:40  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.19  2002/11/18 00:46:08  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.18.10.2  2002/09/30 21:08:18  ddiego
*piddling stuff
*
*Revision 1.18.10.1  2002/09/27 23:38:35  ddiego
*added support for geting various layout information
*added support for drawing various graphics UI primitives like scroll buttons
*tabs, tab pages, etc, partially to have this support in place for use
*in MacOSX.
*Also added scrolling buttons to TabbedPages, this fixes task 56652 in the
*ApplicationKit list
*
*Revision 1.18  2002/05/09 03:10:43  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.17.4.1  2002/04/27 15:52:19  ddiego
*Changed a bunch of files include and made it a bit faster and added better include
*guards in the common headers
*
*Revision 1.17  2002/01/31 05:46:14  ddiego
*fixed resource leak with GraphicsContexts used as memory GC's
*Works fine in 98 with no drop of GDI resources.
*
*Revision 1.16  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

/**
*Copyright (c) 2000-2001, Jim Crafton
*All rights reserved.
*Redistribution and use in source and binary forms, with or without
*modification, are permitted provided that the following conditions
*are met:
*	Redistributions of source code must retain the above copyright
*	notice, this list of conditions and the following disclaimer.
*
*	Redistributions in binary form must reproduce the above copyright
*	notice, this list of conditions and the following disclaimer in 
*	the documentation and/or other materials provided with the distribution.
*
*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
*AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
*OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
*PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
*SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*NB: This software will not save the world.
*/

// Win32Context.h: interface for the Win32Context class.

#ifndef _VCF_WIN32CONTEXT_H__
#define _VCF_WIN32CONTEXT_H__


#include <deque>

namespace VCF
{


class GRAPHICSKIT_API Win32Image;
/**
*A Context provides the lowest level graphics interface to the
*native systems 2D drawing operations. Based loosely on PostScript,
*a Context takes a series of of drawing operations, or commands 
*(lineTo, moveTo, etc), and then executes them by either filling or
*strokeing the path(s) that result from the commands. Thus calling 
*ellipse() will not draw anything till the strokePath() or fillPath()
*methods have been called. All path commands should add their information
*to a stack of some sort that is then looped through and executed
*using the appropriate native graphics calls. At each path command
*a test should be made as to whether the buffer should be cleared.
*The buffer should be cleared only after the stroke of fill methods
*have been  called. For example:
*
*<p><pre>
*	ellipse(23,23,45,67) //added to buffer 
*	moveTo(89,100) //add to buffer
*	lineTo(300,40) //add to buffer
*	strokePath()
*	fillPath()
*	rectangle(200,300,400,400)//buffer cleared, then add to buffer
*</pre></p>
*/
class GRAPHICSKIT_API Win32Context  : public Object, public ContextPeer {
public:
	Win32Context();
	/**
	*Creates a new HDC from scratch
	*/
	Win32Context( const unsigned long& width, const unsigned long& height );	

	Win32Context( const unsigned long& contextID );	

	virtual ~Win32Context();

	virtual void setContext( GraphicsContext* context );

	virtual GraphicsContext* getContext();	

	virtual unsigned long getContextID();

	virtual void setContextID( const unsigned long& handle );
	
	virtual void textAt( const Rect& bounds, const String & text, const long& drawOptions=0 );	

	virtual double getTextWidth( const String& text );

	virtual double getTextHeight( const String& text );

    virtual void rectangle(const double & x1, const double & y1, const double & x2, const double & y2);

	virtual void roundRect(const double & x1, const double & y1, const double & x2, const double & y2,
							 const double & xc, const double & yc);    

    virtual void ellipse(const double & x1, const double & y1, const double & x2, const double & y2 );

	virtual void arc(const double & x1, const double & y1, const double & x2, const double & y2, const double & x3, 
						 const double & y3, const double & x4, const double & y4);

/*
	virtual void pie(const double & x1, const double & y1, const double & x2, const double & y2, const double & x3, 
						 const double & y3, const double & x4, const double & y4);

	virtual void chord(const double & x1, const double & y1, const double & x2, const double & y2, const double & x3, 
						 const double & y3, const double & x4, const double & y4);
*/

    virtual void polyline(const std::vector<Point>& pts);

    virtual void curve(const double & x1, const double & y1, const double & x2, const double & y2,
                         const double & x3, const double & y3, const double & x4, const double & y4);

    virtual void lineTo(const double & x, const double & y);

    virtual void moveTo(const double & x, const double & y);

	void init();

	virtual void setOrigin( const double& x, const double& y );

	virtual Point getOrigin();

	virtual void copyContext( const Rect& sourceRect, 
								const Rect& destRect, 
								ContextPeer* sourceContext );

	virtual bool isMemoryContext();

	virtual bool prepareForDrawing( long drawingOperation );

	virtual void finishedDrawing( long drawingOperation );

	virtual void drawImage( const double& x, const double& y, Rect* imageBounds, Image* image );

	
	//utility functions
	void copyToImage( Win32Image* image );	

	virtual void checkHandle(){};
	
	virtual void releaseHandle();

	virtual bool isXORModeOn();

	virtual void setXORModeOn( const bool& XORModeOn );

	virtual void setTextAlignment( const bool& alignTobaseline );

	virtual bool isTextAlignedToBaseline();

	virtual void drawSelectionRect( Rect* rect );

	virtual void drawButtonRect( Rect* rect, const bool& isPressed );
	
	virtual void drawCheckboxRect( Rect* rect, const bool& isPressed );
		
	virtual void drawRadioButtonRect( Rect* rect, const bool& isPressed );

	virtual void drawVerticalScrollButtonRect( Rect* rect, const bool& topButton, const bool& isPressed );

	virtual void drawHorizontalScrollButtonRect( Rect* rect, const bool& leftButton, const bool& isPressed );

	virtual void setClippingPath( Path* clippingPath );

	virtual void setClippingRect( Rect* clipRect );

	/**
	Draws a button that is used to open up more details, for example 
	the button that opens up a tree node to reveal it's children, that is compliant
	with the native windowing systems default look and feel.
	On Win32 this is usually represented by the "+" and "-" look as found on
	the tree controls, while on OSX it is the little triangles
	*/
	virtual void drawDisclosureButton( Rect* rect, const long& state );

	/**
	Draws a tab, the part of the TabbedPages control that acts like a 
	little button to activate a page, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawTab( Rect* rect, const bool& selected, const String& caption );

	/**
	Draws a tab page - the page on which other controls for the page are 
	parented to, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawTabPage( Rect* rect );

	/**
	Draws a tick mark, like that used for a slider control, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawTickMarks( Rect* rect, const SliderInfo& sliderInfo  );

	/**
	Draws a slider thumb control, like that used for a slider control, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawSliderThumb( Rect* rect, const SliderInfo& sliderInfo );

	/**
	Draws a slider control, like that used for a slider control, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawSlider( Rect* rect, const SliderInfo& sliderInfo );

	/**
	Draws a header control that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawHeader( Rect* rect );

	/**
	draws edges, useful for separators, that is compliant
	with the native windowing systems default look and feel.
	use a mask or 1 or more values of type ContextPeer::EdgeType
	to indicate which sides of the rect to draw an edge on
	*/
	virtual void drawEdge( Rect* rect, const long& edgeSides, const long& edgeStyle );

	/**
	Draws a size gripper for resizing a control/window that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawSizeGripper( Rect* rect );

	/**
	Draws the background appropriate for a control that is compliant
	with the native windowing systems default look and feel.
	This is typically called first by a control to give it a standard
	look and feel in it's background before drawing any thing else
	*/
	virtual void drawControlBackground( Rect* rect );

	/**
	Draws the background appropriate for a window/frame that is compliant
	with the native windowing systems default look and feel.
	This is typically called first by a window/frame to give it a standard
	look and feel in it's background before drawing any thing else
	*/
	virtual void drawWindowBackground( Rect* rect );

	/**
	Draws the background appropriate for a menu item that is compliant
	with the native windowing systems default look and feel.
	This is typically called first by a menu item to give it a standard
	look and feel in it's background before drawing any thing else
	*/
	virtual void drawMenuItemBackground( Rect* rect, const bool& selected );
protected:
	
	HRGN clipRGN_;

	bool pathStarted_;	
	
	Point oldOrigin_;
	Point origin_;
	bool inFillPath_;
	HDC dc_;
	HBITMAP memBitmap_;
	HBITMAP originalBitmap_;

	HBRUSH currentHBrush_;
	HPEN currentHPen_;
	HFONT currentHFont_;

	int currentDCState_;

	bool isMemoryCtx_;
	GraphicsContext* context_;
	bool isXORModeOn_;
	double strokeWidth_;

	bool alignToBaseline_;

	HDC getDC();

	/**
	*Utility function to draw a transparent bitmap
	*/
	static void drawTransparentBitmap(HDC hdc, HBITMAP hBitmap, long xStart,
                           long yStart, COLORREF cTransparentColor);

	
};

};

#endif // _VCF_WIN32CONTEXT_H__


