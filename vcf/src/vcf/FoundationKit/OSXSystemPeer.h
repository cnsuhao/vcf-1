/**
Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
	Redistributions of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.

	Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in
	the documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
 OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 NB: This software will not save the world.
 */
 
#ifndef _VCF_OSXSYSTEMPEER_H__
#define _VCF_OSXSYSTEMPEER_H__


namespace VCF
{

class OSXSystemPeer : public SystemPeer
{
public:
	OSXSystemPeer();
	virtual ~OSXSystemPeer();
	
	virtual unsigned long getTickCount();

	virtual void sleep( const uint32& milliseconds );

	virtual bool doesFileExist( const String& fileName );

	virtual String getCurrentWorkingDirectory();

	virtual String getEnvironmentVariable( const String& variableName );

	virtual void setCurrentWorkingDirectory( const String& currentDirectory );
    
    virtual void setDateToSystemTime( DateTime* date );

	virtual void setDateToLocalTime( DateTime* date );

	virtual void setCurrentThreadLocale( Locale* locale );

protected:
	struct timezone timeZone_;
	struct timeval time_;
};

};


/**
*CVS Log info
 *$Log$
 *Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
 *migration towards new directory structure
 *
 *Revision 1.4.2.1  2004/04/26 21:58:43  marcelloptr
 *changes for dir reorganization: _VCF_MACRO_H__
 *
 *Revision 1.4  2004/04/03 15:48:42  ddiego
 *Merged over code from the 0-6-3 branch.
 *
 *Revision 1.3.4.1  2004/02/21 03:27:06  ddiego
 *updates for OSX porting
 *
 *Revision 1.3  2003/08/09 02:56:44  ddiego
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
 *Revision 1.2.2.1  2003/06/23 23:16:55  ddiego
 *added some furtther implementation for the osx port
 *
 *Revision 1.2  2003/05/17 20:37:12  ddiego
 *this is the checkin for the 0.6.1 release - represents the merge over from
 *the devmain-0-6-0 branch plus a few minor bug fixes
 *
 *Revision 1.1.2.1  2003/05/15 03:01:01  ddiego
 *added initial osx source( FoundationKit only),
 *plus some fixes to compile under GCC 3.x compilers
 *
 */



#endif // _VCF_OSXSYSTEMPEER_H__


