//ImageViewer.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"
#include "vcf/ApplicationKit/EtchedBorder.h"

using namespace VCF;


class ImageViewerWindow : public Window {
public:
	ImageViewerWindow() : currentImage_(NULL){
		setCaption( "ImageViewer" );

		//lets create a menu

		//create the menu bar - this will hold the menu items
		MenuBar* menuBar = new MenuBar();

		//set the window's menu bar
		setMenuBar( menuBar );

		//add the menu to this window's components
		addComponent( menuBar );

		/**
		create menu items, first arguemtn is the menu item name,
		then the parent,
		then the owning menu bar
		*/
		MenuItem* fileMenu = new DefaultMenuItem( "File", menuBar->getRootMenuItem(), menuBar );
		MenuItem* fileOpenImageMenu = new DefaultMenuItem( "Open Image...", fileMenu, menuBar );

		//add our event handler to the menu item
		fileOpenImageMenu->MenuItemClicked +=
			new MenuItemEventHandler<ImageViewerWindow>( this,&ImageViewerWindow::openImage, "ImageViewerWindow::openImage" );



		//set the border of the window, this will give us a nice etched border
		EtchedBorder* bdr = new EtchedBorder();
		bdr->setEdgeStyle( GraphicsContext::etSunken );
		setBorder( bdr );

	}

	virtual ~ImageViewerWindow(){
		if ( NULL != currentImage_ ) {
			delete currentImage_;
		}
	};


	virtual void paint( GraphicsContext* ctx ) {
		Window::paint(ctx);

		ctx->setClippingRect( &ctx->getViewableBounds() );

		Rect r = getClientBounds();

		if ( NULL != currentImage_ ) {
			/**
			if we have an image, draw it centered within the available client
			rect
			*/
			Rect imageRect(0,0,currentImage_->getWidth(),currentImage_->getHeight());

			imageRect.offset( r.getWidth()/2 - imageRect.getWidth()/2,
								r.getHeight()/2 - imageRect.getHeight()/2 );

			ctx->drawImageWithinBounds( &imageRect, currentImage_ );
		}
	}

	void openImage( MenuItemEvent* e ) {
		CommonFileOpenDialog dlg( this );

		//get the available image loader extensions
		std::vector< std::pair<String,String> > contentTypes;

		/**
		this will get a list of all current available types that
		can currently be loaded by the VCF. The list is a series
		of std::pair objects. the std::pair.first element is a string
		that represents the file extension, and the std::pair.second
		represents a string that is the mime type for the extension
		*/
		GraphicsToolkit::getAvailableImageTypes( contentTypes );
		std::vector< std::pair<String,String> >::iterator it = contentTypes.begin();

		/*
		For each type, add a new filter to the dialog
		*/
		while ( it != contentTypes.end() ) {
			std::pair<String,String>& type = *it;

			dlg.addFilter( type.second + " (*." + type.first + " )", "*." + type.first );
			it ++;
		}


		if ( dlg.execute() ) {
			if ( NULL != currentImage_ ) {
				//delete our old image
				delete currentImage_;
			}

			//create a new image from the file name
			currentImage_ = GraphicsToolkit::createImage( dlg.getFileName() );
			repaint(); //repaint ourselves to update the new image
		}
	}

	Image* currentImage_;
};




class ImageViewerApplication : public Application {
public:

	ImageViewerApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();

		Window* mainWindow = new ImageViewerWindow();
		setMainWindow(mainWindow);
		mainWindow->setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );
		mainWindow->show();

		return result;
	}



};


int main(int argc, char *argv[])
{
	Application* app = new ImageViewerApplication( argc, argv );

	Application::main();

	return 0;
}


/**
*CVS Log info
*$Log$
*Revision 1.7.2.4  2006/03/23 01:25:37  dougtinkham
*modified centering of image
*
*Revision 1.7.2.3  2006/03/16 18:45:26  kdmix
*setVisible(true) removed from constructor of the main window.
*
*Revision 1.7.2.2  2005/09/02 01:01:19  ddiego
*changed some of the common dialogs around, was using a less clear class name.
*
*Revision 1.7.2.1  2005/07/23 21:45:37  ddiego
*merged in marcellos changes from the 0-6-7 dev branch.
*
*Revision 1.6.2.2  2005/06/06 02:34:03  ddiego
*menu changes to better support win32 and osx.
*
*Revision 1.6.2.1  2005/03/06 22:50:54  ddiego
*overhaul of RTTI macros. this includes changes to various examples to accommadate the new changes.
*
*Revision 1.6  2004/12/01 04:15:07  ddiego
*merged over devmain-0-6-6 code. Marcello did a kick ass job
*of fixing a nasty bug (1074768VCF application slows down modal dialogs.)
*that he found. Many, many thanks for this Marcello.
*
*Revision 1.5  2004/08/20 23:59:16  ddiego
*minor fix to listboxcontrol
*
*Revision 1.4.2.1  2004/10/07 15:03:33  kiklop74
*Fixed building issues with bcb
*
*Revision 1.4  2004/08/07 02:47:29  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.3.2.4  2004/04/29 03:40:54  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*/


