//WhatsThisHelpEvent.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


//WhatsThisHelpEvent.h


#include "vcf/ApplicationKit/ApplicationKit.h"


using namespace VCF;


WhatsThisHelpEvent::WhatsThisHelpEvent( Object* source, const String& helpString ):
	Event( source, WHAT_THIS_EVENT_TYPE )
{
	helpString_ = helpString;
}

WhatsThisHelpEvent::~WhatsThisHelpEvent()
{

}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 03:43:15  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:20  ddiego
*migration towards new directory structure
*
*Revision 1.3  2003/05/17 20:37:19  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.2.22.3  2003/03/23 06:46:01  marcelloptr
*minor fixes
*
*Revision 1.2.22.2  2003/03/23 03:23:55  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.2.22.1  2003/03/12 03:11:57  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.2  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

