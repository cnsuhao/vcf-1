#ifndef _VCF_DATAOBJECT_H__
#define _VCF_DATAOBJECT_H__
//DataObject.h

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


#define  STRING_DATA_TYPE			"text/plain"
#define  RTF_DATA_TYPE				"text/rtf"
#define	 INTEGER_DATA_TYPE			"text/x-vcf-integer"
#define	 OBJECT_DATA_TYPE			"application/x-vcf-object"
#define	 FILE_DATA_TYPE				"application/x-vcf-file"
#define	 BYTE_STREAM_DATA_TYPE		"application/octet-stream"
#define	 IMAGE_DATA_TYPE			"image/x-vcf-image"
#define	 COMPONENT_DATA_TYPE		"text/x-vcf-vff"


class APPLICATIONKIT_API BinaryPersistable : public Object, public Persistable {
public:
	BinaryPersistable( const unsigned char* dataToInitWith, const unsigned long& dataSize ):
		data_(NULL), dataSize_(dataSize) {

		if ( 0 == dataSize_ ) {
			throw RuntimeException( "Cannot create a BinaryPersistable with 0 length data size" );
		}

		data_ = new unsigned char[dataSize];
		if ( NULL != dataToInitWith ) {
			memcpy( data_, dataToInitWith, dataSize);
		}
	}

	virtual ~BinaryPersistable() {
		delete [] data_;
	}

	virtual void saveToStream( OutputStream * stream )	{
		stream->write( data_, dataSize_ );
	}

    virtual void loadFromStream( InputStream * stream ) {
		stream->read( data_, dataSize_ );
	}

	unsigned char* getData() {
		return data_;
	}

	unsigned long getSize() {
		return dataSize_;
	}
protected:
	unsigned char* data_;
	unsigned long dataSize_;
};

/**
*A DataObject represents a data object in the clipboard.
*Can be streamed out to a stream
*/
class APPLICATIONKIT_API DataObject : public Object {

public:
	//DataObject( const char* dataToInitWith, const unsigned long& dataSize, const String& dataType );

	DataObject();

	virtual ~DataObject();

	void init();

	void addSupportedDataType( const String& dataType, Persistable* dataRepresentation );

	bool isTypeSupported( const String& dataType );

	bool saveToStream( const String& dataType, OutputStream * stream );

	bool loadFromStream( const String& dataType, InputStream * stream );

	Enumerator<String>* getSupportedDataTypes();

protected:
	std::vector<String> types_;
	EnumeratorContainer<std::vector<String>, String> typesContainer_;
	std::map<String,Persistable*> dataMap_;
};


class APPLICATIONKIT_API TextDataObject : public DataObject {
public:
	TextDataObject( const String& text="" );

	virtual ~TextDataObject();

	String getTextData();
protected:
	String text_;
};


class APPLICATIONKIT_API ImageDataObject : public DataObject {
public:
	ImageDataObject( Image* image=NULL );

	virtual ~ImageDataObject();

	Image* getImageData();

protected:
	Image* image_;
};


};


/**
*CVS Log info
*$Log$
*Revision 1.2.6.1  2005/09/21 02:21:53  ddiego
*started to integrate jpeg support directly into graphicskit.
*
*Revision 1.2  2004/08/07 02:49:07  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.3  2004/06/06 07:05:29  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.2  2004/04/29 03:43:13  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:16  ddiego
*migration towards new directory structure
*
*Revision 1.3.4.1  2004/04/26 21:58:18  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.3  2003/12/18 05:15:57  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.2.2.4  2003/10/24 04:03:36  ddiego
*More header musical chairs
*
*Revision 1.2.2.3  2003/09/21 04:15:34  ddiego
*moved the cvs info data to teh bottom of the header instead of the
*top so it is easier to get to the actual header class declarations
*instead of having to wade through all the cvs info stuff.
*
*Revision 1.2.2.2  2003/09/12 00:09:32  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.2.2.1  2003/08/27 20:11:49  ddiego
*adjustments to how hte DataObject class work and copy/paste
*
*Revision 1.2  2003/08/09 02:56:42  ddiego
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
*Revision 1.1.2.2  2003/06/27 03:10:58  ddiego
*got rid of some redundant junk in the Clipboard and DataObject
*classes. Instead of a rather dippy use of the DataType calss, we now simply
*use pure mime-types to identify the various "flavours" of data.
*
*Revision 1.1.2.1  2003/06/16 03:09:39  ddiego
*beginning to add support for AGG into the VCF GraphicsKit
*added some missing files
*added some changes to the new version of xmake
*
*Revision 1.4  2003/05/17 20:37:00  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.3.2.2  2003/03/23 03:23:44  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.3.2.1  2003/03/12 03:09:20  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.3  2003/02/26 04:30:37  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.2.14.1  2002/12/25 22:06:15  ddiego
*whole bunch of little changes to the header files used by the ApplicationKit
*to get rid of no newline warnings by gcc.
*fixes to various event handlers in the ApplicationKit to compile with gcc
*since gcc does not like a member function pointer without the "&"
*addressof operator.
*Added initial file for the X11 UIToolkit implementation
*
*Revision 1.2  2002/05/09 03:10:42  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.1.2.1  2002/04/27 15:41:50  ddiego
*removed ApplicationKit.h and optimized header includes as
*well as adding better include guard support
*
*Revision 1.11  2002/02/14 05:04:52  ddiego
*documentation...
*
*Revision 1.10  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_DATAOBJECT_H__


