/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.21.4.1  2004/04/12 19:33:13  ddiego
*fixed throw exception bug
*
*Revision 1.21  2003/12/18 05:16:02  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.20.2.3  2003/08/25 03:46:38  ddiego
*some fixes to some of the stream impls
*
*Revision 1.20.2.2  2003/08/11 19:41:15  marcelloptr
*bugfix [786946] FileOutputStream always erases the file when it opens it
*
*Revision 1.20.2.1  2003/08/11 19:07:05  marcelloptr
*bug 786924 - FileInputStream access fixed
*
*Revision 1.20  2003/08/09 02:56:46  ddiego
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
*Revision 1.19.2.1  2003/07/24 04:10:45  ddiego
*added fixes for the following tasks:
*Task #82279 ApplicationKit: add static methods to singleton objects
*Task #82277 FoundationKit: add static methods to singleton objects
*this required a bunch of changes in terms of getting rid of older style code
*
*Revision 1.19  2003/05/17 20:37:24  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.18.2.2  2003/03/23 04:06:34  marcelloptr
*minor fixes
*
*Revision 1.18.2.1  2003/03/12 03:12:10  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.18  2003/02/26 04:30:47  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.17.2.1  2002/12/27 23:04:47  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.17  2002/11/18 00:46:09  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.16.8.1  2002/10/04 05:02:54  ddiego
*added beggining support for add new classes. Basic GUI is now in place.
*Also preliminary support for class templates and class wizards
*some documentation done on the format for the XML based class template
*
*Revision 1.16  2002/05/28 03:03:15  ddiego
*added another test: FileStreaming to test out the FileStream class in
*linux. Added some changes to the LinuxFileStream class. Also added the
*LinuxLibraryPeer so the Library class now works in linux.
*
*Revision 1.15  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.14.4.1  2002/03/20 21:56:56  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.14  2002/03/18 00:20:44  ddiego
*made changes to foundation kit stuff so that the thread, mutex, semaphore, registry,
*file, filestream, and library class all call the SystemToolkit to create their peer
*instances.
*
*Revision 1.13  2002/02/28 01:07:23  ddiego
*fixed bug [ 523259 ] InputStream::read(String&) is incorrect
*added new virtual function Stream::getCurrentSeekPos to help fix the problem.
*Made apropriate changes to all stream headers and implementation to account
*for thisd
*
*Revision 1.12  2002/01/28 02:09:03  cesarmello
*Linux file peer
*
*Revision 1.11  2002/01/24 01:46:49  ddiego
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

//FileStream.cpp
#include "vcf/FoundationKit/FoundationKit.h"
using namespace VCF;


FileStreamBase::FileStreamBase():
	currentSeekPos_(0),
	fsPeer_(NULL),
	access_(fsDontCare)
{

}

FileStreamBase::~FileStreamBase()
{

}

void FileStreamBase::init()
{
	fsPeer_ = SystemToolkit::createFileStreamPeer( filename_, access_ );
	if ( NULL == fsPeer_ ) {
		throw NoPeerFoundException();	
	}
}

void FileStreamBase::close()
{
	if ( NULL != fsPeer_ ) {
		delete fsPeer_;
		fsPeer_ = NULL;
	}
}

void FileStreamBase::open( const String& filename, FileStreamAccessType accessType )
{
	filename_ = filename;
	access_ = accessType;
	if ( NULL != fsPeer_ ){
		delete fsPeer_;
	}
	fsPeer_ = NULL;

	init();
}


FileInputStream::FileInputStream( const String& filename )
{
	filename_ = filename;
	access_ = fsRead;
	try {
		init();
	}
	catch ( BasicException& ){
		throw;
	}
}


FileInputStream::~FileInputStream()
{
	close();
}

void FileInputStream::open( const String& filename )
{
	FileStreamBase::open( filename, fsRead );
}


void FileInputStream::seek(const unsigned long& offset, const SeekType& offsetFrom )
{
	fsPeer_->seek( offset, offsetFrom );

	switch ( offsetFrom ) {
		case stSeekFromStart: {
			currentSeekPos_ = offset;
		}
		break;

		case stSeekFromEnd: {
			currentSeekPos_ = fsPeer_->getSize() - offset;
		}
		break;

		case stSeekFromRelative: {
			currentSeekPos_ += offset;
		}
		break;
	}
}

unsigned long FileInputStream::getSize()
{
	return fsPeer_->getSize();
}

char* FileInputStream::getBuffer()
{
	return fsPeer_->getBuffer();
}

void FileInputStream::read( char* bytesToRead, unsigned long sizeOfBytes )
{
	fsPeer_->read( bytesToRead, sizeOfBytes );
	
	currentSeekPos_ += sizeOfBytes;
}


ulong32 FileInputStream::getCurrentSeekPos()
{	
	return currentSeekPos_;
}






FileOutputStream::FileOutputStream( const String& filename, const bool & append/*=false*/ )
{
	filename_ = filename;
	if ( append ) {
		access_ = fsReadWrite;
	} else {
		access_ = fsWrite;
	}
	try {
		init();
	}
	catch ( BasicException& e ){
		throw e;
	}
	
	//else throw exception ?
}


FileOutputStream::~FileOutputStream()
{
	close();
}



void FileOutputStream::open( const String& filename, const bool & append/*=false*/ )
{
	if ( append ) {
		FileStreamBase::open( filename, fsReadWrite );
	} else {
		FileStreamBase::open( filename, fsWrite );
	}
}


void FileOutputStream::seek(const unsigned long& offset, const SeekType& offsetFrom )
{
	if ( NULL == fsPeer_ ){
		throw InvalidPeer( MAKE_ERROR_MSG_2(NO_PEER) );
	};	

	fsPeer_->seek( offset, offsetFrom );

	switch ( offsetFrom ) {
		case stSeekFromStart: {
			currentSeekPos_ = offset;
		}
		break;

		case stSeekFromEnd: {
			currentSeekPos_ = fsPeer_->getSize() - offset;
		}
		break;

		case stSeekFromRelative: {
			currentSeekPos_ += offset;
		}
		break;
	}
}



unsigned long FileOutputStream::getSize()
{
	return fsPeer_->getSize();
}

char* FileOutputStream::getBuffer()
{
	return fsPeer_->getBuffer();
}

void FileOutputStream::write( const char* bytesToWrite, unsigned long sizeOfBytes )
{
	fsPeer_->write( bytesToWrite, sizeOfBytes );

	currentSeekPos_ += sizeOfBytes;
}


ulong32 FileOutputStream::getCurrentSeekPos()
{	
	return currentSeekPos_;
}


