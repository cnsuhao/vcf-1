/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.10.4.1  2004/04/21 02:17:26  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.10  2003/12/18 05:16:02  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.9.4.2  2003/08/27 20:11:49  ddiego
*adjustments to how hte DataObject class work and copy/paste
*
*Revision 1.9.4.1  2003/08/25 03:46:38  ddiego
*some fixes to some of the stream impls
*
*Revision 1.9  2003/05/17 20:37:23  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.8.16.1  2003/03/12 03:12:08  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.8  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.7.4.1  2002/03/20 21:56:56  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.7  2002/02/28 05:08:34  ddiego
*added tests for remote objects, plus another subtle fix for BasicInputStream
*for seek positioning
*
*Revision 1.6  2002/02/28 01:07:23  ddiego
*fixed bug [ 523259 ] InputStream::read(String&) is incorrect
*added new virtual function Stream::getCurrentSeekPos to help fix the problem.
*Made apropriate changes to all stream headers and implementation to account
*for thisd
*
*Revision 1.5  2002/01/24 01:46:49  ddiego
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

// BasicInputStream.cpp

#include "vcf/FoundationKit/FoundationKit.h"
using namespace VCF;

BasicInputStream::BasicInputStream()
{
	init();
}

BasicInputStream::BasicInputStream( const String& textBuffer )
{
	init();
	/**
	JC
	WARNING !!!! 
	We are treating this like ascii strings!!!
	*/
	inStream_.write( textBuffer.ansi_c_str(), textBuffer.size() );
	inStream_.setSeekPos( 0 );
	totalStreamSize_ = textBuffer.size();
}

BasicInputStream::BasicInputStream( const char* dataBuffer, const unsigned long& dataBufferSize )
{	
	init();
	inStream_.write( dataBuffer, dataBufferSize );
	inStream_.setSeekPos( 0 );
	totalStreamSize_ = dataBufferSize;
}

BasicInputStream::BasicInputStream( InputStream* inStream )
{
	init();
	inputStream_ = inStream;	
}


void BasicInputStream::init()
{
	inputStream_ = NULL;
	totalStreamSize_ = 0;
}

BasicInputStream::~BasicInputStream()
{
	
}

void BasicInputStream::seek(const unsigned long& offset, const SeekType& offsetFrom)
{
	if ( NULL != inputStream_ ) {
		inputStream_->seek( offset, offsetFrom );
	}

	switch ( offsetFrom ) {
		case stSeekFromStart: {
			inStream_.setSeekPos( offset );
		}
		break;

		case stSeekFromEnd: {			
			inStream_.setSeekPos( inStream_.getSize() - offset );
		}
		break;

		case stSeekFromRelative: {			
			inStream_.setSeekPos( inStream_.getSeekPos() + offset );
		}
		break;
	}
}

unsigned long BasicInputStream::getSize()
{
	return inStream_.getSize();
}

char* BasicInputStream::getBuffer()
{
	return inStream_.getBuffer();
}

void BasicInputStream::read( char* bytesToRead, unsigned long sizeOfBytes )
{
	if ( NULL != inputStream_ ){
		inputStream_->read( bytesToRead, sizeOfBytes );
		inStream_.write( bytesToRead, sizeOfBytes );
	}
	else {
		inStream_.read( bytesToRead, sizeOfBytes );
	}	
}

ulong32 BasicInputStream::getCurrentSeekPos()
{
	if ( NULL != inputStream_ ) {
		return inputStream_->getCurrentSeekPos();
	}
	return inStream_.getSeekPos();
}

bool BasicInputStream::isEOS()
{
	if ( NULL != inputStream_ ) {
		return inputStream_->getCurrentSeekPos() == (inputStream_->getSize()-1);
	}
	return inStream_.getSeekPos() == (totalStreamSize_-1);
}

