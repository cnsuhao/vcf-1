#ifndef _VCF_OSXCONTROL_H__
#define _VCF_OSXCONTROL_H__
//OSXControl.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


namespace VCF {


class OSXControl : public Object, public ControlPeer {
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

	virtual long getHandleID();

	virtual void create( Control* owningControl );

	virtual void destroyControl();

    virtual String getText() {
		return String();
	}

    virtual void setText( const String& text ){};

    virtual void setBounds( Rect* rect );

	virtual bool beginSetBounds( const ulong32& numberOfChildren );

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

	virtual void repaint( Rect* repaintRect=NULL );

	virtual void keepMouseEvents();

	virtual void releaseMouseEvents();

	virtual void translateToScreenCoords( Point* pt );

	virtual void translateFromScreenCoords( Point* pt );
	
	virtual void setBorder( Border* border );

	static void setCurrentCreateHIView( TView* view );

	static TView* getCurrentCreateHIView() {
		return OSXControl::currentCreatedView;
	}
protected:
	TView* hiView_;
	Control* control_;
	EventHandlerRef handlerRef_;
	MouseState mouseState_;
	
	OSStatus handleOSXEvent( EventHandlerCallRef nextHandler, EventRef theEvent );

	static TView* currentCreatedView;

	static EventHandlerUPP getEventHandlerUPP();
	static OSStatus handleOSXEvents(EventHandlerCallRef nextHandler, EventRef theEvent, void* userData);
};


}; //end of namespace VCF


/**
*CVS Log info
*$Log$
*Revision 1.1.2.8  2004/07/27 04:26:04  ddiego
*updated devmain-0-6-5 branch with osx changes
*
*Revision 1.1.2.7  2004/06/07 03:07:07  ddiego
*more osx updates dealing with mouse handling
*
*Revision 1.1.2.6  2004/06/06 07:05:30  marcelloptr
*changed macros, text reformatting, copyright sections
*
*/


#endif // _VCF_OSXCONTROL_H__


