#ifndef _VCF_INVALIDPEER_H__
#define _VCF_INVALIDPEER_H__
//InvalidPeer.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


namespace VCF
{
/**
\class InvalidPeer InvalidPeer.h "vcf/FoundationKit/InvalidPeer.h"
*/
class InvalidPeer : public BasicException{
public:

	InvalidPeer( const String & message ):
	  BasicException( message ){};

	InvalidPeer():
		BasicException( NO_PEER ){};

	InvalidPeer( const String & message, const int lineNumber ):
		BasicException(message, lineNumber){};

	virtual ~InvalidPeer() throw() {};
};


};


/**
*CVS Log info
*$Log$
*Revision 1.3  2006/04/07 02:35:34  ddiego
*initial checkin of merge from 0.6.9 dev branch.
*
*Revision 1.2.6.1  2006/03/12 22:01:40  ddiego
*doc updates.
*
*Revision 1.2  2004/08/07 02:49:13  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.2  2004/04/29 04:07:08  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.6.4.1  2004/04/26 21:58:38  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.6  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.5.4.1  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*/


#endif // _VCF_INVALIDPEER_H__


