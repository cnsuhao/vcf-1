//ControlsApplication.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "ControlsApplication.h"
#include "MainWindow.h"



using namespace VCF;



ControlsApplication::ControlsApplication( int argc, char** argv ):
	Application( argc, argv )

{
	
}

ControlsApplication::~ControlsApplication()
{
	
}

bool ControlsApplication::initRunningApplication(){
	bool result = Application::initRunningApplication();
	MainWindow* mainWindow = new MainWindow();
	
	setMainWindow(mainWindow);
	mainWindow->setBounds( &Rect( 50.0, 50.0, 650.0, 600.0 ) );
	mainWindow->setVisible( true );
	mainWindow->setCaption( "Controls" );
	
	return result;
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/08/30 03:50:47  dougtinkham
*added copyright
*
*/