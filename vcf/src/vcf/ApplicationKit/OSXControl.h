#ifndef _VCF_OSXCONTROL_H__
#define _VCF_OSXCONTROL_H__
//OSXControl.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/



namespace VCF {
	class OSXControl;
};


@interface VCFControlView : NSView
{
	
}


@end


namespace VCF {




class OSXControl : public ControlPeer, public ObjectWithCallbacks {
public:
	enum MouseState{
		msNoState=0,
		msDown,
		msUp,
		msEntered,
		msExited
	};
	
	OSXControl( Control* control );

	virtual ~OSXControl();

	virtual OSHandleID getHandleID();

	virtual void create( Control* owningControl );

	virtual void destroyControl();

	virtual String getText() {
		return String();
	}

	virtual void setText( const String& text ){};

	virtual void setBounds( Rect* rect );

	virtual bool beginSetBounds( const uint32& numberOfChildren );

	virtual void endSetBounds();

	virtual Rect getBounds();

	virtual void setVisible( const bool& visible );

	virtual bool getVisible();

	virtual Control* getControl();

	virtual void setControl( Control* component );

	virtual void setCursor( Cursor* cursor );

	virtual void setParent( Control* parent );

	virtual Control* getParent();

	virtual bool isFocused();

	virtual void setFocused();

	virtual bool isEnabled();

	virtual void setEnabled( const bool& enabled );

	virtual void setFont( Font* font );

	virtual void repaint( Rect* repaintRect, const bool& immediately );
	
	virtual void keepMouseEvents();

	virtual void releaseMouseEvents();

	virtual void translateToScreenCoords( Point* pt );

	virtual void translateFromScreenCoords( Point* pt );
	
	virtual void setBorder( Border* border );
	
	virtual void preChildPaint( GraphicsContext* graphicsContext, Control* child, Rect* childClipRect );
	
	virtual void postChildPaint( GraphicsContext* graphicsContext, Control* child, Rect* oldClipRect );
	
	void internal_paint( const NSRect& r );
	
	static void setViewForPeer( NSView* view, OSXControl* peer );
	static OSXControl* getPeerForView( NSView* view );
	
	static void handleEventForView( NSView* view, NSEvent* event );
	static void handleSetFrame( NSView* view, const NSRect& rect );
	
	virtual void doEventForView( NSView* view, NSEvent* event );
	virtual void doSetFrame( NSView* view, const NSRect& rect );
protected:
	Control* control_;	
	MouseState mouseState_;
	::Point lastMousePt_;	
	NSView* view_;
	 
};


}; //end of namespace VCF


#endif // _VCF_OSXCONTROL_H__

/**
$Id$
*/
