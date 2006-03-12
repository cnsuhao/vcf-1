#ifndef _VCF_MEMORYSTREAM_H__
#define _VCF_MEMORYSTREAM_H__
//MemoryStream.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */


namespace VCF{


/**
\class MemoryStream MemoryStream.h "vcf/FoundationKit/MemoryStream.h"
A MemoryStream a stream for in memory data for both reading
and writing
*/
class FOUNDATIONKIT_API MemoryStream : public VCF::InputStream, public VCF::OutputStream, public VCF::Object {
public:
	MemoryStream();

	/**
	*This constructor is used in stream chaining.
	*The flow goes from the MemoryStream to the outStream.
	*So if a write is called on the MemoryStream, it simply
	*passes it to the outStream's write() method
	*/
	MemoryStream( OutputStream* outStream );

	/**
	*This constructor is used in stream chaining.
	*The flow goes from the MemoryStream to the inStream.
	*So if a read is called on the MemoryStream, it simply
	*passes it to the inStream's read() method
	*/
	MemoryStream( InputStream* inStream );

	virtual ~MemoryStream();

	virtual char* getBuffer(){
		return NULL;
	};

	virtual void seek(const unsigned long& offset, const SeekType& offsetFrom);

    virtual unsigned long getSize();

	virtual ulong32 getCurrentSeekPos() ;

	virtual void write( Persistable* persistableObject );

	virtual unsigned long write( const unsigned char* bytesToWrite, unsigned long sizeOfBytes );

	virtual unsigned long read( unsigned char* bytesToRead, unsigned long sizeOfBytes );

	void init();

	virtual bool isEOS()
	{
		// stub impl.
		return false;
	}
private:
	CharMemStream stream_;
	OutputStream* outputStream_;
	InputStream* inputStream_;
	unsigned long size_;
	ulong32 currentSeekPos_;
};

};


/**
*CVS Log info
*$Log$
*Revision 1.2.6.2  2006/03/12 22:01:40  ddiego
*doc updates.
*
*Revision 1.2.6.1  2005/09/21 02:21:53  ddiego
*started to integrate jpeg support directly into graphicskit.
*
*Revision 1.2  2004/08/07 02:49:13  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.3  2004/06/06 07:05:32  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.2  2004/04/29 04:07:08  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.11.4.1  2004/04/26 21:58:45  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.11  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.10.4.1  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*Revision 1.10  2003/05/17 20:37:15  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.9.22.1  2003/03/12 03:11:45  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.9  2002/02/28 01:07:09  ddiego
*fixed bug [ 523259 ] InputStream::read(String&) is incorrect
*added new virtual function Stream::getCurrentSeekPos to help fix the problem.
*Made apropriate changes to all stream headers and implementation to account
*for thisd
*
*Revision 1.8  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_MEMORYSTREAM_H__


