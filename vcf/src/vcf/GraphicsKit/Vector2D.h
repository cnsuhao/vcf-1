

#if     _MSC_VER > 1000
#pragma once
#endif


#ifndef _VCF_VECTOR2D_H__
#define _VCF_VECTOR2D_H__


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



namespace VCF {

class GRAPHICSKIT_API Vector2D {

public:
	Vector2D();

	virtual ~Vector2D();

};

}; //end of namespace VCF



/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.8.4.1  2004/04/26 21:58:40  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.8  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.7.4.1  2003/10/28 04:06:11  ddiego
*updated the GraphicsContext and ContextPeer classes to support
*slider control drawing. adjusted the Slider control accordingly.
*Also changed some of the GraphicsKit headers to conform to the
*current header style.
*
*Revision 1.7  2003/05/17 20:37:10  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.6.10.1  2003/03/23 03:23:48  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.6  2002/09/12 03:26:04  ddiego
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




#endif // _VCF_VECTOR2D_H__


