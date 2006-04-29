//DropTarget.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


/* Generated by Together */

#include "vcf/ApplicationKit/ApplicationKit.h"



using namespace VCF;

DropTarget::DropTarget( Control* control )
{
	targetContainer_.initContainer( targets_ );

	dropTargetPeer_ = UIToolkit::createDropTargetPeer();
	if ( NULL != dropTargetPeer_ ){
		dropTargetPeer_->setDropTarget( this );
	}
	else {
		throw InvalidPeer( MAKE_ERROR_MSG_2("Unable to create DropTarget peer") );
	}

	addTargetControl( control );
}

DropTarget::DropTarget()
{
	targetContainer_.initContainer( targets_ );

	dropTargetPeer_ = UIToolkit::createDropTargetPeer();
	if ( NULL != dropTargetPeer_ ){
		dropTargetPeer_->setDropTarget( this );
	}
	else {
		throw InvalidPeer( MAKE_ERROR_MSG_2("Unable to create DropTarget peer") );
	}
}

DropTarget::DropTarget( Component* owner ):
	Component( owner )
{
	targetContainer_.initContainer( targets_ );

	dropTargetPeer_ = UIToolkit::createDropTargetPeer();
	if ( NULL != dropTargetPeer_ ){
		dropTargetPeer_->setDropTarget( this );
	}
	else {
		throw InvalidPeer( MAKE_ERROR_MSG_2("Unable to create DropTarget peer") );
	}
}

DropTarget::DropTarget( const String& name, Component* owner ):
	Component( name, owner )
{
	targetContainer_.initContainer( targets_ );

	dropTargetPeer_ = UIToolkit::createDropTargetPeer();
	if ( NULL != dropTargetPeer_ ){
		dropTargetPeer_->setDropTarget( this );
	}
	else {
		throw InvalidPeer( MAKE_ERROR_MSG_2("Unable to create DropTarget peer") );
	}
}

DropTarget::DropTarget( const String& name ):
	Component( name )
{
	targetContainer_.initContainer( targets_ );

	dropTargetPeer_ = UIToolkit::createDropTargetPeer();
	if ( NULL != dropTargetPeer_ ){
		dropTargetPeer_->setDropTarget( this );
	}
	else {
		throw InvalidPeer( MAKE_ERROR_MSG_2("Unable to create DropTarget peer") );
	}
}

DropTarget::~DropTarget()
{
	if ( NULL != dropTargetPeer_ ){
		delete dropTargetPeer_;
		dropTargetPeer_ = NULL;
	}
}

void DropTarget::handleEvent( Event* event )
{

	if ( NULL != event ){
		unsigned long eventType = event->getType();
		switch ( eventType ){
			case DropTarget::DRAG_ENTERED : {
				DropTargetEntered.fireEvent( event );
			}
			break;

			case DropTarget::DRAG_LEFT : {
				DropTargetLeft.fireEvent( event );
			}
			break;

			case DropTarget::DRAGGING_OVER : {
				DropTargetDraggingOver.fireEvent( event );
			}
			break;

			case DropTarget::DRAG_DROPPED : {
				DropTargetDropped.fireEvent( event );
			}
			break;

			default : {
				Component::handleEvent( event );
			}
			break;
		}
	}
}

DropTargetPeer* DropTarget::getDropTargetPeer()
{
	return this->dropTargetPeer_;
}


Control* DropTarget::getTarget()
{
	Control* result = NULL;
	if ( !targets_.empty() ) {
		result = targets_.front();
	}

	return result;
}


Enumerator<Control*>* DropTarget::getTargets()
{
	return targetContainer_.getEnumerator();
}

void DropTarget::addTargetControl( Control* control )
{
	targets_.push_back( control );
	dropTargetPeer_->registerTarget( control );
}

void DropTarget::removeTargetControl( Control* control )
{
	std::vector<Control*>::iterator found = std::find( targets_.begin(), targets_.end(), control );
	if ( found != targets_.end() ) {
		dropTargetPeer_->unregisterTarget( control );
		targets_.erase( found );
	}
}


/**
$Id$
*/
