/**
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.4.8.1  2004/04/26 21:58:42  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.4  2003/05/17 20:37:12  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.3.14.3  2003/04/19 22:22:56  ddiego
*tested the code developed in windows using gtk in linux. Seems to work ok except for a
*few minor compiler glitches. Had to comment out the partial specialization for
*floating point image bits in include/graphics/ImageBits.h. Also made some
*adjustments in the makefiles for building the GraphicsKit and ApplicationKit
*from the build/make/Makefile.
*
*Revision 1.3.14.2  2003/03/23 03:23:49  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.3.14.1  2003/03/12 03:10:56  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.3  2002/05/28 03:03:15  ddiego
*added another test: FileStreaming to test out the FileStream class in
*linux. Added some changes to the LinuxFileStream class. Also added the
*LinuxLibraryPeer so the Library class now works in linux.
*
*Revision 1.2  2002/05/09 03:10:43  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.1.4.1  2002/03/26 04:46:10  cesarmello
*Linux headers
*
*Revision 1.1  2002/01/28 02:04:54  cesarmello
*Linux file peer implementation
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

// LinuxFileStream.h

#ifndef _VCF_LINUXFILESTREAM_H__
#define _VCF_LINUXFILESTREAM_H__


//#include "FileStreamPeer.h"


namespace VCF
{
/**
* This is going to based on the C runtime's fopen/fread/fwrite stream
*API for now.
*/
class FRAMEWORK_API LinuxFileStream : public FileStreamPeer  
{
public:
	LinuxFileStream( const String& filename, const FileStreamAccessType& accessType );	

	virtual ~LinuxFileStream();
	
	virtual void seek( const unsigned long& offset, const SeekType& offsetFrom );

	virtual unsigned long getSize();

	virtual void read( char* bytesToRead, unsigned long sizeOfBytes );

	virtual void write( const char* bytesToWrite, unsigned long sizeOfBytes );

	virtual char* getBuffer();
private:
	FILE* fileHandle_;
	VCF::String filename_;
	String translateAccessType( const FileStreamAccessType& accessType );
	int translateSeekTypeToMoveType( const SeekType& offsetFrom );
};


};

#endif // _VCF_LINUXFILESTREAM_H__


