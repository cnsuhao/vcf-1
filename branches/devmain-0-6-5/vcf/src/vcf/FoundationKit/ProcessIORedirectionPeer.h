#if     _MSC_VER > 1000
#pragma once
#endif


#ifndef _VCF_PROCESSIOREDIRECTIONPEER_H__
#define _VCF_PROCESSIOREDIRECTIONPEER_H__

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
//ProcessIORedirectionPeer.h


namespace VCF {

class ProcessWithRedirectedIO;
/**
This defines the interface for a redirecting process input/ouput.
At this time only output redirection is supported. In other words
the process is created such that the normal output to stdout is captured
and an event is fired whenever there is output data ready to be consumed,
(i.e. an "OutputReady" event so to speak).
*/
class FRAMEWORK_API ProcessIORedirectionPeer : public ProcessPeer {
public:
	virtual ~ProcessIORedirectionPeer(){};
	
	/**
	Add an event handler. This event handler will be "invoked" 
	when there is a new OutputReady event that needs to be fired
	@param EventHandler the event handler to add to the process
	*/
	virtual void addOutputReadyHandler( EventHandler* eventHandler ) = 0;
	
	/**
	Removes an event handler.
	*/
	virtual void removeOutputReadyHandler( EventHandler* eventHandler ) = 0;

	/**
	sets the peer's ProcessWithRedirectedIO process instance. When an
	OutputReady event occurs, the ProcessWithRedirectedIO instance is what
	will be used as the source of the event, <i><b>not</b></i> the peer itself.
	*/
	virtual void setProcess( ProcessWithRedirectedIO* process ) = 0;
};

};

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.4.4.1  2004/04/26 21:58:41  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.4  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.3.6.1  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*Revision 1.3  2003/02/26 04:30:40  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.2.2.1  2003/01/08 00:19:45  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.2  2002/11/17 18:09:41  ddiego
*removing hte old Contextpeer.h file - to make way for the "new"
*ContextPeer.h - gotta love case sensitive file systems :)
*
*Revision 1.1.2.2  2002/09/17 21:32:59  ddiego
*added the build menus for building files and projects
*
*Revision 1.1.2.1  2002/09/17 18:48:34  ddiego
*added support in the VCF FoundationKit for redirecting io in a process
*
*/


#endif // _VCF_PROCESSIOREDIRECTIONPEER_H__


