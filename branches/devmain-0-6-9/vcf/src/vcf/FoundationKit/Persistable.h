#ifndef _VCF_PERSISTABLE_H__
#define _VCF_PERSISTABLE_H__
//Persistable.h

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

class OutputStream;
class InputStream;

/**
\class Persistable Persistable.h "vcf/FoundationKit/Persistable.h"
*Persistable is a simple interface that objects that support persistence can
*implement. Persistable supports methods  saveToStream() and loadFromStream()
*/
class FOUNDATIONKIT_API Persistable {
public:

	virtual ~Persistable(){};

	/**
	*Write the object to the specified output stream
	*/
    virtual void saveToStream( OutputStream * stream ) = 0;

	/**
	**Read the object from the specified input stream
	*/
    virtual void loadFromStream( InputStream * stream ) = 0;


};

};


/**
*CVS Log info
*$Log$
*Revision 1.2.6.1  2006/03/12 22:01:40  ddiego
*doc updates.
*
*Revision 1.2  2004/08/07 02:49:14  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.3  2004/06/06 07:05:33  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.2  2004/04/29 04:07:12  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.8.4.1  2004/04/26 21:58:45  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.8  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.7.26.1  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*Revision 1.7  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_PERSISTABLE_H__


