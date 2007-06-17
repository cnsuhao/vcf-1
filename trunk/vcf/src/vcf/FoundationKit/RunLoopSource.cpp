
//
// Copyright 2000-2007 The VCF Project.
// Please see License.txt in the top level directory
// where you installed the VCF.
//

#include <vcf/FoundationKit/FoundationKit.h>
#include <vcf/FoundationKit/RunLoopSourcePeer.h>
#include <vcf/FoundationKit/RunLoopSource.h>

using namespace VCF;

RunLoopSource::RunLoopSource()
    : peer_( SystemToolkit::createRunLoopSourcePeer( this ) )
{
}

RunLoopSource::~RunLoopSource()
{
}

void RunLoopSource::setRunLoop( RunLoop* runLoop )
{
    
}

void RunLoopSource::perform()
{
    performImpl();
}

void RunLoopSource::cancel()
{
    cancelImpl();
}

void RunLoopSource::fire()
{
    peer_->fire();
}
