
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

#include "vcf/FoundationKit/FoundationKit.h"
using namespace VCF;

Thread::Thread():
	canContinue_(true),
	runnableObject_(NULL),
	peer_(NULL),
	autoDelete_(true),
	autoDeleteRunnable_(false),
	stopped_(false)
{	
	peer_ = SystemToolkit::createThreadPeer( this );
	if ( NULL == peer_ ) {
		throw NoPeerFoundException();	
	}
}

Thread::Thread( Runnable* runnableObject ):
	canContinue_(true),
	runnableObject_(runnableObject),
	peer_(NULL),
	autoDelete_(true),
	autoDeleteRunnable_(true),
	stopped_(false)
{	
	peer_ = SystemToolkit::createThreadPeer( this );
	if ( NULL == peer_ ) {
		throw NoPeerFoundException();	
	}
}

Thread::Thread( Runnable* runnableObject, const bool& autoDelete ):
	canContinue_(true),
	runnableObject_(runnableObject),
	peer_(NULL),
	autoDelete_(autoDelete),
	autoDeleteRunnable_(false),
	stopped_(false)
{	
	peer_ = SystemToolkit::createThreadPeer( this );
	if ( NULL == peer_ ) {
		throw NoPeerFoundException();	
	}
}

Thread::Thread( const bool& autoDelete ):
	canContinue_(true),
	runnableObject_(NULL),
	peer_(NULL),
	autoDelete_(autoDelete),
	autoDeleteRunnable_(false),
	stopped_(false)
{	
	peer_ = SystemToolkit::createThreadPeer( this );
	if ( NULL == peer_ ) {
		throw NoPeerFoundException();	
	}
}

Thread::Thread( Runnable* runnableObject, const bool& autoDeleteRunnable,
			const bool& autoDelete ):
	canContinue_(true),
	runnableObject_(runnableObject),
	peer_(NULL),
	autoDelete_(autoDelete),
	autoDeleteRunnable_(autoDeleteRunnable),
	stopped_(false)
{
	peer_ = SystemToolkit::createThreadPeer( this );
	if ( NULL == peer_ ) {
		throw NoPeerFoundException();	
	}
}

Thread::~Thread()
{
	canContinue_ = false;
	autoDelete_ = false;
	
	//stop();

	if ( NULL != peer_ ){
		delete peer_;
	}

	peer_ = NULL;

	if ( autoDeleteRunnable_ ) {
		delete runnableObject_;
	}
}

bool Thread::run()
{
	bool result = false;
	if ( NULL != runnableObject_ ){
		result = runnableObject_->run();
	}
	else {

	}
	return result;	
}


void Thread::stop()
{	
	//set this to true immediately
	stopped_ = true;
	/**
	this sets the canContinue_
	member to false which should get picked up in the 
	implementers run() method signifying they should exit the
	method, ASAP
	*/
	canContinue_ = false;

	if ( NULL != runnableObject_ ){
		runnableObject_->stop();
	}

	/**
	A blocking call - will wait for the thread to stop
	(or become "unsignaled" in Win32 API terms).
	*/
	peer_->stop();

	/**
	Now clean up here if neccessary
	*/
	if ( true == autoDelete_ )	{
		free();
	}
}

bool Thread::start()
{
	return peer_->start();
}

void Thread::sleep( uint32 milliseconds )
{
	peer_->sleep( milliseconds );
}

uint32 Thread::getThreadID()
{
	return peer_->getThreadID();
}

uint32 Thread::getOwningProcessID()
{
	return peer_->getOwningProcessID();
}

bool Thread::isActive()
{
	return peer_->isActive();
}


void Thread::pause()
{
	peer_->pause();
}

Waitable::WaitResult Thread::wait()
{
	return (Waitable::WaitResult) peer_->wait();
}

Waitable::WaitResult Thread::wait( uint32 milliseconds )
{
	return (Waitable::WaitResult) peer_->wait(milliseconds);
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:41  ddiego
*migration towards new directory structure
*
*Revision 1.21  2004/04/03 15:48:50  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.20.2.2  2004/03/11 22:20:00  ddiego
*added condition implementation to FoundationKit.
*added a Conditions example to the examples directory.
*
*Revision 1.20.2.1  2004/02/19 04:52:35  ddiego
*more progress made with TableControl
*
*Revision 1.20  2003/12/18 05:16:02  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.19.2.4  2003/08/18 19:52:39  ddiego
*changed the Container from being a class you derive from to a separate
*intance that is created and assigned dynamically to any Control.
*
*Revision 1.19.2.3  2003/08/14 01:13:24  ddiego
*added the Thread::pause method back
*
*Revision 1.19.2.2  2003/08/13 21:43:01  ddiego
*thread stuff - fixed bug in auto deleting
*
*Revision 1.19.2.1  2003/08/13 02:18:32  ddiego
*changed the way you start up the ApplicationKit a bit. now pass
*in the argc/argv parameters to the application instance constructor
*
*Revision 1.19  2003/08/09 02:56:46  ddiego
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
*Revision 1.18.2.1  2003/07/24 04:10:45  ddiego
*added fixes for the following tasks:
*Task #82279 ApplicationKit: add static methods to singleton objects
*Task #82277 FoundationKit: add static methods to singleton objects
*this required a bunch of changes in terms of getting rid of older style code
*
*Revision 1.18  2003/05/17 20:37:42  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.17.2.2  2003/03/23 03:23:59  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.17.2.1  2003/03/12 03:12:50  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.17  2003/02/26 04:30:53  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.16.2.3  2003/02/06 00:22:04  catwallader
*Added thread methods: isActive(), isDetached(), join(), exit(), yield() and detach().  Fleshed out PosixThread::stop().
*
*Revision 1.16.2.2  2003/01/30 22:32:23  catwallader
*Added the PosixThread class.  Modified Makefiles and toolkit files to accomodate it.
*
*Revision 1.16.2.1  2002/12/27 23:04:57  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.16  2002/11/18 00:46:09  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.15.8.1  2002/09/18 21:50:57  ddiego
*added more support for building a project and displaying results in gui
*
*Revision 1.15  2002/06/25 01:25:28  ddiego
*added some fixes and documentation to the Thread class
*also added methods to allow for getting the peer classes on the
*Thread, Semeaphore, and Mutex classes. added peer methods for
*retrieving the handleID for a thread,semaphore, or mutex
*
*Revision 1.14  2002/05/09 03:10:45  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.13.4.1  2002/03/20 21:56:57  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.13  2002/03/18 00:20:44  ddiego
*made changes to foundation kit stuff so that the thread, mutex, semaphore, registry,
*file, filestream, and library class all call the SystemToolkit to create their peer
*instances.
*
*Revision 1.12  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/




