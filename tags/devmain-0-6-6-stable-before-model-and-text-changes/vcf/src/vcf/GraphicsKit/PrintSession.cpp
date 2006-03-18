//PrintSession.cpp

#include "vcf/GraphicsKit/GraphicsKit.h"
#include "vcf/GraphicsKit/PrintSession.h"
#include "vcf/GraphicsKit/PrintSessionPeer.h"


using namespace VCF;

PrintSession::PrintSession():
	peer_(NULL),
	errorDuringPrinting_(false),
	currentPage_(PrintSession::UnknownPage)
{	
	peer_ = GraphicsToolkit::createPrintSessionPeer();
	if ( NULL == peer_ ) {

	}
}

PrintSession::~PrintSession()
{
	delete peer_;
}

String PrintSession::getTitle()
{
	return title_;
}

void PrintSession::setTitle( const String& title )
{
	title_ = title;
	peer_->setTitle( title_ );
}

void PrintSession::setDefaultPageSettings()
{
	peer_->setDefaultPageSettings();
}

Size PrintSession::getPageSize()
{
	return peer_->getPageSize();
}

void PrintSession::setPageSize( const Size& pageSize )
{
	peer_->setPageSize(pageSize);
}

void PrintSession::setStandardPageSize( const PageSize& pageSize )
{
	peer_->setStandardPageSize(pageSize);
}

void PrintSession::setStartPage( const ulong32& startPage )
{
	peer_->setStartPage(startPage);
}

ulong32 PrintSession::getStartPage()
{
	return peer_->getStartPage();
}

void PrintSession::setEndPage( const ulong32& endPage )
{
	peer_->setEndPage(endPage);
}

ulong32 PrintSession::getEndPage()
{
	return peer_->getEndPage();
}

Rect PrintSession::getPageDrawingRect()
{
	return peer_->getPageDrawingRect();
}

void PrintSession::setPageDrawingRect( const Rect& drawingRect )
{
	peer_->setPageDrawingRect( drawingRect );
}


PrintInfoHandle PrintSession::getPrintInfoHandle()
{
	return peer_->getPrintInfoHandle();
}

void PrintSession::setPrintInfoHandle( PrintInfoHandle info )
{
	peer_->setPrintInfoHandle( info );
}

void PrintSession::abort()
{
	peer_->abort();
}

PrintContext* PrintSession::beginPrintingDocument()
{
	errorDuringPrinting_ = false;
	PrintContext* result = peer_->beginPrintingDocument();

	result->setViewableBounds( getPageDrawingRect() );

	PrintEvent event( this, result, PrintSession::UnknownPage, PrintingBegunEvent );
	PrintingBegun.fireEvent( &event );

	return result;
}

void PrintSession::endPrintingDocument()
{
	try {
		peer_->endPrintingDocument();

		PrintEvent event( this, NULL, PrintSession::UnknownPage, PrintingFinishedEvent );
		PrintingFinished.fireEvent( &event );
	}
	catch ( BasicException& ) {
		errorDuringPrinting_ = true;
	}
}

void PrintSession::beginPage( PrintContext* context )
{
	try {
		peer_->beginPage( context );
		PrintEvent event( this, context, currentPage_, PageBegunEvent );
		PageBegun.fireEvent( &event );
	}
	catch ( BasicException& ) {
		errorDuringPrinting_ = true;
	}
}

void PrintSession::endPage( PrintContext* context )
{
	try {
		peer_->endPage( context );
		PrintEvent event( this, context, currentPage_, PageDoneEvent );
		PageDone.fireEvent( &event );
	}
	catch ( BasicException& ) {
		errorDuringPrinting_ = true;
	}
}

void PrintSession::runDefaultPrintLoop() 
{
	errorDuringPrinting_ = false;

	currentPage_ = PrintSession::UnknownPage;

	int firstPage = this->getStartPage();
	int lastPage = this->getEndPage();


	PrintContext* printCtx = beginPrintingDocument();
	if ( NULL == printCtx ) {
		throw RuntimeException( MAKE_ERROR_MSG_2("Failed to create a Printer Context") );
	}

	int page = firstPage;
	while ( page <= lastPage ) {

		currentPage_ = page;

		beginPage( printCtx );

		endPage( printCtx );		
		
		page++;
	}


	endPrintingDocument();

	printCtx->free();
}


