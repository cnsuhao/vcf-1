//FindDialog.cpp


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ModelViewKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"
#include "FindDialog.h"
#include "TextEditDocument.h"

using namespace VCF;


FindDialog::FindDialog()
{
	setWidth( 500 );
	setHeight( 200 );
	setCaption( "Find" );

	Rect clientRect = this->getClientBounds();
	
	
	double y = UIToolkit::getUIMetricValue( UIMetricsManager::mtWindowBorderDelta );
	double x = clientRect.right_ - (100 + UIToolkit::getUIMetricValue( UIMetricsManager::mtWindowBorderDelta ));

	find_ = new CommandButton();
	find_->setBounds( x, y, 100, find_->getPreferredHeight() );
	find_->setCaption( "&Find" );	
	add( find_ );

	y += find_->getHeight() + UIToolkit::getUIMetricValue( UIMetricsManager ::mtControlVerticalSpacing );

	find_->ButtonClicked += new ClassProcedure1<ButtonEvent*,FindDialog>(this,&FindDialog::findClicked, "FindDialog::findClicked" );

	
	cancel_ = new CommandButton();
	cancel_->setBounds( x, y, 100, cancel_->getPreferredHeight() );
	cancel_->setCaption( "Close" );
	cancel_->setCommandType( BC_CANCEL );
	add( cancel_ );
	

	

	y = UIToolkit::getUIMetricValue( UIMetricsManager::mtWindowBorderDelta );
	x = find_->getLeft() - (275 + UIToolkit::getUIMetricValue( UIMetricsManager::mtControlHorizontalSpacing ));

	searchStrings_ = new StdStringsChoiceType::Control();
	
	searchString_ = (StdStringsChoiceType::Control*)searchStrings_;

	searchString_->setBounds( &Rect(x, y, x+275, y+searchString_->getPreferredHeight()) );

	add( searchString_ );

	searchString_->setComboBoxStyle( cbsDropDownWithEdit );


	x = UIToolkit::getUIMetricValue( UIMetricsManager::mtControlHorizontalSpacing );

	Label* label = new Label();
	label->setCaption( "Search for:" );
	label->setBounds( x, y, 
						(searchString_->getLeft() - UIToolkit::getUIMetricValue( UIMetricsManager::mtControlHorizontalSpacing )) - x,
						searchString_->getHeight() );
	add( label );	

	
	y += label->getHeight() + UIToolkit::getUIMetricValue( UIMetricsManager::mtControlVerticalSpacing );

	caseSensitive_ = new StdBoolType::Control();

	caseSensitive_->setCaption( "Match Case" );
	caseSensitive_->setBounds( x, y, 175, caseSensitive_->getPreferredHeight() );
	add( caseSensitive_ );
	y += caseSensitive_->getHeight() + UIToolkit::getUIMetricValue( UIMetricsManager::mtControlVerticalSpacing )/2.0;

	matchWordOnly_ = new StdBoolType::Control();
	matchWordOnly_->setCaption( "Match Word only" );
	matchWordOnly_->setBounds( x, y, 175, matchWordOnly_->getPreferredHeight() );
	add( matchWordOnly_ );
	y += matchWordOnly_->getHeight() + UIToolkit::getUIMetricValue( UIMetricsManager::mtControlVerticalSpacing )/2.0;

	
	find_->setDefault(true);

	double newHeight = getHeight() + (y - clientRect.getHeight());

	setHeight( newHeight );

	searchString_->setFocused();
}

FindDialog::~FindDialog()
{

}

void FindDialog::findClicked( ButtonEvent* e )
{	
	findInfo_.caseSensitive_ = caseSensitive_;
	findInfo_.matchWordOnly_ = matchWordOnly_;
	findInfo_.searchString_ = searchString_;	

	bool addString = true;
	ListModel* listModel = searchString_->getListModel();
	VCF::Enumerator<VariantData>* items = listModel->getItems();
	while ( items->hasMoreElements() ) {
		VariantData item = items->nextElement();
		if ( findInfo_.searchString_ == item ) {
			addString = false;
			break;
		}
	}

	if ( addString ) {
		listModel->insert( 0, findInfo_.searchString_ );
	}

	findInfo_.searchStrings_ = searchStrings_;

	TextEditDocument* doc = (TextEditDocument*)DocumentManager::getDocumentManager()->getCurrentDocument();
	if ( !doc->find( findInfo_ ) ) {
		Dialog::showMessage( "Couldn't find string \"" + findInfo_.searchString_ + "\"" );
	}
	else {
		//doc->setSelectionRange( findInfo_.position_, findInfo_.searchString_.size() );
		findInfo_.position_ += findInfo_.searchString_.size();
	}

}

