#if     _MSC_VER > 1000
#pragma once
#endif



#ifndef _VCF_BASICFILL_H__
#define _VCF_BASICFILL_H__

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



namespace VCF{

/**
*
*/
class GRAPHICSKIT_API BasicFill : public Object, public Fill {
public:
	BasicFill();

	virtual ~BasicFill();

	virtual void setContext( GraphicsContext* context ) {
		context_ = context;
	}

    virtual void render( Path* path );

	Color getColor() {
		return color_;
	}

	void setColor( Color color ) {
		color_ = color;
	}

	double getOpacity() {
		return opacity_;
	}

	void setOpacity( const double& val ) {
		opacity_ = minVal<>( maxVal<>( val, 0.0 ), 1.0 );
	}

	bool allowAntiAlias() {
		return antiAlias_;
	}

	void setAllowAntiAlias( bool val ) {
		antiAlias_ = val;
	}
protected:

	double opacity_;
	Color color_;
	GraphicsContext* context_;
	bool antiAlias_;
};

};


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:40:30  ddiego
*migration towards new directory structure
*
*Revision 1.9.4.1  2004/04/26 21:58:38  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.9  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.8.2.1  2003/10/28 04:06:11  ddiego
*updated the GraphicsContext and ContextPeer classes to support
*slider control drawing. adjusted the Slider control accordingly.
*Also changed some of the GraphicsKit headers to conform to the
*current header style.
*
*Revision 1.8  2003/08/09 02:56:43  ddiego
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
*Revision 1.7.2.2  2003/07/16 04:59:07  ddiego
*added some changes to the fil and stroke classes to allow changing whether
*they use anti-aliasing or not. Also implemented Matrix2D::invert(),
*plus properly implemented clone() on the DefaultMenuItem class.
*
*Revision 1.7.2.1  2003/07/05 04:04:45  ddiego
*added more AGG support
*  added a common AGG header to use when accessing the AGG API directly
*  see the graphics/AggCommon.h header for this
*  Made some minor changes to Path to work a bit simpler
*  Implemented Polygon completely,
*  Implemented BasicFill and BasicStroke - using AGG
*
*Revision 1.7  2003/05/17 20:37:09  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.6.10.1  2003/03/23 03:23:48  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.6  2002/09/12 03:26:03  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.5.12.1  2002/08/06 02:57:35  ddiego
*added base X11 files for GraphicsKit and made sure that the GraphicsKit compiles
*under linux (GCC). There is now a new dir under build/xmake called GraphicsKit
*where the xmake build script lives. This checkin also includes the base X11
*include (as part of GraphicsKitPrivate.h), as well as linking to the X11 libs
*
*Revision 1.5  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

#endif // _VCF_BASICFILL_H__



