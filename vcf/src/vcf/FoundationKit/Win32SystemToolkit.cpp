//Win32SystemToolkit.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"
#include "vcf/FoundationKit/ProcessIORedirectionPeer.h"
#include "vcf/FoundationKit/Win32ProcessIORedirector.h"

#include "vcf/FoundationKit/LocalePeer.h"
#include "vcf/FoundationKit/Win32LocalePeer.h"
#include "vcf/FoundationKit/Win32Condition.h"
#include "vcf/FoundationKit/ResourceBundlePeer.h"
#include "vcf/FoundationKit/Win32ResourceBundle.h"



using namespace VCF;


Win32SystemToolkit::Win32SystemToolkit()
{

}

Win32SystemToolkit::~Win32SystemToolkit()
{

}

ProcessPeer* Win32SystemToolkit::internal_createProcessPeer( Process* process )
{
	ProcessPeer* result = NULL;

	result = new Win32ProcessPeer();

	return result;
}

ProcessIORedirectionPeer* Win32SystemToolkit::internal_createProcessIORedirectionPeer( ProcessWithRedirectedIO* process )
{
	ProcessIORedirectionPeer * result = new Win32ProcessIORedirector();
	result->setProcess( process );

	return result;
}

ThreadPeer* Win32SystemToolkit::internal_createThreadPeer( Thread* thread )
{
	ThreadPeer* result = NULL;

	return new Win32Thread( thread );
}

SystemPeer* Win32SystemToolkit::internal_createSystemPeer()
{
	return new Win32SystemPeer();
}

SemaphorePeer* Win32SystemToolkit::internal_createSemaphorePeer( long initialCount, long maxCount )
{
	return new Win32SemaphorePeer( initialCount, maxCount );
}

RegistryPeer* Win32SystemToolkit::internal_createRegistryPeer( Registry* registry )
{
	return new Win32Registry();
}

MutexPeer* Win32SystemToolkit::internal_createMutexPeer( Mutex* mutex )
{
	return new Win32Mutex();
}

ConditionPeer* Win32SystemToolkit::internal_createConditionPeer( Condition* condition )
{
	return new Win32Condition(condition);
}

LibraryPeer* Win32SystemToolkit::internal_createLibraryPeer( Library* library )
{
	return new Win32LibraryPeer();
}

FilePeer* Win32SystemToolkit::internal_createFilePeer( File* file )
{
	return new Win32FilePeer( file );
}

FileStreamPeer* Win32SystemToolkit::internal_createFileStreamPeer( const String& filename, const FileStreamAccessType& accessType )
{
	return new Win32FileStream( filename, accessType );
}

FileStreamPeer* Win32SystemToolkit::internal_createFileStreamPeer( File* file )
{
	return new Win32FileStream( file );
}

LocalePeer* Win32SystemToolkit::internal_createLocalePeer()
{
	return new Win32LocalePeer();
}

ResourceBundlePeer* Win32SystemToolkit::internal_createResourceBundlePeer()
{
	return new Win32ResourceBundle();
}

/**
*CVS Log info
*$Log$
*Revision 1.2.2.1  2004/08/27 03:50:46  ddiego
*finished off therest of the resource refactoring code. We
*can now load in resoruces either from the burned in data in the .exe
*or from resource file following the Apple bundle layout scheme.
*
*Revision 1.2  2004/08/07 02:49:16  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.4  2004/07/29 02:39:14  ddiego
*fixed a bug with File::getINputStream and File::getOutputStream.
*
*Revision 1.1.2.3  2004/07/18 14:45:19  ddiego
*integrated Marcello's new File/Directory API changes into both
*the FoundationKit and the ApplicationKit. Many, many thanks go out
*to Marcello for a great job with this. This adds much better file searching
*capabilities, with many options for how to use it and extend it in the
*future.
*
*Revision 1.1.2.2  2004/04/29 04:07:14  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:29:41  ddiego
*migration towards new directory structure
*
*Revision 1.8  2004/04/03 15:48:48  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.7.2.2  2004/03/11 22:20:00  ddiego
*added condition implementation to FoundationKit.
*added a Conditions example to the examples directory.
*
*Revision 1.7.2.1  2004/02/15 20:24:02  ddiego
*intial Locales implementation is now checked in. This adds several new classes, namely:
*The LocalePeer, which is the OS generic peer for interfacing with teh OS for lcoale support
*The Locale class which provides locale support for the vcf
*The Win32LocalePeer which provides a basic Win32 implementation for locale support
*The UnicodeString class, which is a near identical class to the std::string class and provides a wrapper around a std::basic_string<wchar_t>. This also adds support for translating to and from ansi strings, and supporting text encoding via a TextEncoder class.
*The TextCodec class which allows for custom text codec for encoding or decoding text.
*The MessageLoader class which is used to provide localized string translation
*The StringsMessageLoader which provides a basic implementation of string loading and translation that is compatible with Apples .strings resource files.
*
*Revision 1.7  2003/12/18 05:16:01  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.6.2.1  2003/08/13 21:42:49  ddiego
*thread stuff - fixed bug in auto deleting
*
*Revision 1.6  2003/08/09 02:56:46  ddiego
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
*Revision 1.5.2.1  2003/07/24 04:10:45  ddiego
*added fixes for the following tasks:
*Task #82279 ApplicationKit: add static methods to singleton objects
*Task #82277 FoundationKit: add static methods to singleton objects
*this required a bunch of changes in terms of getting rid of older style code
*
*Revision 1.5  2003/05/17 20:37:39  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.4.2.1  2003/03/12 03:12:42  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.4  2003/02/26 04:30:52  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.3.2.3  2003/02/24 05:42:19  ddiego
*moved the code for the VariantData calss into it's own header
*migrated to the new event style using Delegates instead of relying on
*the ugly macros that we were using before - same functionality though
*made sure everything still works and compiles, including neccessary
*changes in the VCF Builder so that it creates code in the new style
*This changes to teh new style of using Delegates completes task 58837
*
*Revision 1.3.2.2  2002/12/28 01:56:22  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.3.2.1  2002/12/27 23:04:55  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.3  2002/11/18 00:46:09  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.2.10.1  2002/09/17 18:48:36  ddiego
*added support in the VCF FoundationKit for redirecting io in a process
*
*Revision 1.2  2002/05/09 03:10:45  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.1.2.1  2002/03/20 21:56:57  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.1  2002/03/18 05:35:17  ddiego
*forgot to add the Win32SystemToolkit code!
*
*/


