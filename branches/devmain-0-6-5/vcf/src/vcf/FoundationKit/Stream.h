#if     _MSC_VER > 1000
#pragma once
#endif


#ifndef _VCF_STREAM_H__
#define _VCF_STREAM_H__


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

/* Generated by Together */



namespace VCF{

/**
*seek types
*/
enum SeekType{
	stSeekFromStart=0,
	stSeekFromRelative,
	stSeekFromEnd
};

/**
*file acess
*/
enum FileStreamAccessType{
	fsDontCare = 0, //same as read/write for now
	fsRead,
	fsWrite,
	fsReadWrite
};

/**
*forward declared, see Persistable.h
*/
class Persistable; 

/**
*forward declared, see FileStream.h
*/
//class FileStream;


/**
*Stream interface defines a core set of funcationality for streams 
*in the Visual Component Framework derived Streams should support "stream chaining", 
*the ability of the stream constructor to support an incoming stream from 
*someother stream object. For example:
*	<p><pre>
*		MyStream s = new MyStream( new MemStream( new GZIPStream( SomeBigDataObject ) ) );
*	</pre></p>
*	assuming SomeBigDataObject supports Persistable, then the object is read into the
*	GZIPStream and compressed, the compressed bytes are sent to the Memory stream, and
*	then this is sent to MyStream.
*
*Streams are meant as alternative to the C++ streams, though in some 
*cases they may extend the standard C++ stream library. 
*
*@author Jim Crafton
*@version 1.0
*/
class FRAMEWORK_API Stream {
public: 
    
    /*
	Stream(Stream * incomingChainedStream){
		
	};
	*/

	virtual ~Stream(){};

	virtual void seek(const unsigned long& offset, const SeekType& offsetFrom)=0;

	/**
	*returns the size of the stream. The size represents the 
	*number of bytes that have been <b>written</b>, or <b>read</b> to/from the stream
	*/
    virtual unsigned long getSize() =0;

	/**
	*returns a pointer to the buffer that holds the stream memory
	*/
	virtual char* getBuffer() = 0;

	/**
	*this is a global offset from the beggining of the stream
	*/
	virtual ulong32 getCurrentSeekPos() = 0;
};

/**
*InputStream, basic interface describing the requirements to 
*support streaming data into a stream. Support for the basic 
*primitive types is done through the extraction operator( >> ),
*as well as providing support for the Persistable interface,
*and reading in an arbitrary chunk of memory
*/
class FRAMEWORK_API InputStream : public Stream /*,public std::istream */{
public:	

	virtual ~InputStream(){};

	// new introduced by tiziano
	virtual bool isEOS() = 0;
	
	virtual void read( char* bytesToRead, unsigned long sizeOfBytes ) = 0;

	virtual void read( Persistable* persistableObject ) ;

	virtual void read( short& val ) ;
	
	virtual void read( long& val ) ;

	virtual void read( int& val ) ;

	virtual void read( bool& val ) ;

	virtual void read( char& val ) ;

	virtual void read( float& val ) ;

	virtual void read( double& val ) ;

	virtual void read( String& val ) ;

	InputStream& operator>>( short& val );	

	InputStream& operator>>( long& val );

	InputStream& operator>>( int& val );

	InputStream& operator>>( bool& val );

	InputStream& operator>>( char& val );

	InputStream& operator>>( float& val );

	InputStream& operator>>( double& val );	

	InputStream& operator>>( String& val );

	InputStream& operator>>( Persistable* val );
};

/**
*OutputStream, basic interface describing the requirements to 
*support streaming data into a stream. Support for the basic 
*primitive types is done through the insertion operator( << ),
*as well as providing support for the Persistable interface,
*and writing out an arbitrary chunk of memory
*/
class FRAMEWORK_API OutputStream : public Stream /*, public std::ostream */{
public:
	virtual ~OutputStream(){};

	virtual void write( const char* bytesToWrite, unsigned long sizeOfBytes )=0;

	virtual void write( Persistable* persistableObject );
	
	virtual void write( const short& val );
	
	virtual void write( const long& val );

	virtual void write( const int& val );

	virtual void write( const bool& val );

	virtual void write( const char& val );

	virtual void write( const float& val );

	virtual void write( const double& val );

	virtual void write( const String& val );

	OutputStream& operator<<( const short& val );

	OutputStream& operator<<( const long& val );

	OutputStream& operator<<( const int& val );

	OutputStream& operator<<( const bool& val );

	OutputStream& operator<<( const char& val );

	OutputStream& operator<<( const float& val );

	OutputStream& operator<<( const double& val );

	OutputStream& operator<<( const String& val );

	OutputStream& operator<<( Persistable* val );
};



};

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.13.4.1  2004/04/26 21:58:45  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.13  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.12.4.1  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*Revision 1.12  2003/05/17 20:37:15  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.11.22.2  2003/03/23 03:23:52  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.11.22.1  2003/03/12 03:11:45  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.11  2002/02/28 01:07:09  ddiego
*fixed bug [ 523259 ] InputStream::read(String&) is incorrect
*added new virtual function Stream::getCurrentSeekPos to help fix the problem.
*Made apropriate changes to all stream headers and implementation to account
*for thisd
*
*Revision 1.10  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

#endif // _VCF_STREAM_H__


