/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.3.8.1  2004/04/26 21:58:42  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.3  2003/05/17 20:37:12  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.2.10.2  2003/03/23 03:23:50  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.2.10.1  2003/03/12 03:11:04  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.2  2002/09/12 03:26:04  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.1.4.1  2002/08/06 02:57:36  ddiego
*added base X11 files for GraphicsKit and made sure that the GraphicsKit compiles
*under linux (GCC). There is now a new dir under build/xmake called GraphicsKit
*where the xmake build script lives. This checkin also includes the base X11
*include (as part of GraphicsKitPrivate.h), as well as linking to the X11 libs
*
*Revision 1.1  2002/05/27 15:58:22  ddiego
*added linux peer classes for the FoundationKit port to linux
*this now means the FoundationKit will start up correctly on
*linu thought it is still not 100% functional yet
*
*/

// LinuxSemaphorePeer.h: interface for the LinuxSemaphorePeer class.

/**
Copyright (c) 2000-2001, Jim Crafton
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
	Redistributions of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.

	Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in
	the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

NB: This software will not save the world.
*/

#ifndef _VCF_LINUXSEMAPHOREPEER_H__
#define _VCF_LINUXSEMAPHOREPEER_H__

namespace VCF
{


/**
*Class LinuxSemaphorePeer documentation
Implements the base SemaphorePeer class
used for synchronizing access to threaded
resources
*/
/**
*Class LinuxSemaphorePeer
*@author Jim Crafton, May 26 2002
*/
class LinuxSemaphorePeer : public VCF::Object, public VCF::SemaphorePeer
{
public:
	LinuxSemaphorePeer(long initialCount , long maxCount);

	virtual ~LinuxSemaphorePeer();

	virtual bool lock();

	virtual bool unlock();

	virtual uint32 getHandleID() {
		return handle_;
	}
protected:
	uint32 handle_;

};
} // end of namespace VCF

#endif // _VCF_LINUXSEMAPHOREPEER_H__


