
#ifndef _HORIZONTALLAYOUTCONTAINER_H__
#define _HORIZONTALLAYOUTCONTAINER_H__


/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/



#if _MSC_VER > 1000
#   pragma once
#endif





namespace VCF {

class /*APPLICATIONKIT_API*/ HorizontalLayoutContainer : public StandardContainer {
public:

	HorizontalLayoutContainer() : maximizeLastRow_(false){
		
		setBorderWidth( UIToolkit::getUIMetricsManager()->getPreferredSpacingFor(UIMetricsManager::stContainerBorderDelta) );

		setNumberOfColumns(2);

		setColumnWidth( 0, 100 );

		setColumnWidth( 1, 100 );

		setColumnTweenWidth( 0, UIToolkit::getUIMetricsManager()->getPreferredSpacingFor(UIMetricsManager::stControlHorizontalSpacing) );


		setMaxRowHeight( UIToolkit::getUIMetricsManager()->getDefaultHeightFor( UIMetricsManager::htLabelHeight ) );

		setRowSpacerHeight( UIToolkit::getUIMetricsManager()->getPreferredSpacingFor(UIMetricsManager::stControlVerticalSpacing) );
	}

	void setNumberOfColumns( int numColumns ) {
		columns_.clear();
		columnTweens_.clear();

		columns_.resize( numColumns, 0.0 );

		columnTweens_.resize( numColumns-1, 0.0 );  
	}

	int getNumberOfColumns() const {
		return columns_.size();
	}

	void setColumnWidth( int index, double width ) {
		columns_[index] = width;
	}

	int getColumnWidth( int index ) const {
		return columns_[index];
	}

	void setColumnTweenWidth( int index, double width ) {
		columnTweens_[index] = width;
	}

	int getColumnTweenWidth( int index ) const {
		return columnTweens_[index];
	}

	void setMaxRowHeight( double val ) {
		maxRowHeight_ = val;
	}

	double getMinimumVisibleHeight() {		

		double result = 0.0;
		std::vector<Control*>::iterator it = controls_.begin();
		int colCount = columns_.size();

		int col = 0;

		result = maxRowHeight_;		

		while ( it != controls_.end() ) {
			Control* control = *it;
			col ++;
			if ( col >= colCount ) {
				col = 0;
				result += (maxRowHeight_ + rowSpacerHeight_);
			}
			it ++;
		}

		return result;
	}


	virtual void resizeChildren( Control* control ) {
		VCF::Rect clientBounds = controlContainer_->getClientBounds();

		if ( clientBounds.isEmpty() ) {
			return; //nothing to do, so just exit the function
		}

		clientBounds.setRect( clientBounds.left_ + leftBorderWidth_,
			clientBounds.top_ + topBorderHeight_,
			clientBounds.right_ - rightBorderWidth_,
			clientBounds.bottom_ - bottomBorderHeight_ );


		std::vector<Control*>::iterator it = controls_.begin();

		int colCount = columns_.size();
		int tweenCount = columnTweens_.size();

		int col = 0;
		int tween = 0;
		VCF::Rect cell = clientBounds;
		cell.right_ = cell.left_ + columns_[col];

		cell.bottom_ = cell.top_ + maxRowHeight_;

		int rowCount = (controls_.size() / columns_.size()) + (controls_.size() % columns_.size());
		int row = 0;
		while ( it != controls_.end() ) {

			Control* control = *it;


			if ( col == (colCount-1) ) {
				cell.right_ = clientBounds.right_;
			}

			if ( (row == (rowCount-1)) && maximizeLastRow_ ) {
				cell.bottom_ = clientBounds.bottom_;
			}

			control->setBounds( &cell );


			col ++;



			if ( col >= colCount ) {
				col = 0;
				tween = 0;

				cell.offset( 0, maxRowHeight_ + rowSpacerHeight_ );

				cell.left_ = clientBounds.left_;

				cell.right_ = cell.left_ + columns_[col];

				row ++;
			}
			else {
				cell.offset( cell.getWidth() + columnTweens_[tween], 0 );
				tween ++;
			}  


			it ++;
		}
	}


	bool getMaximizeLastRow() {
		return maximizeLastRow_;
	}

	void setMaximizeLastRow( bool val ) {
		maximizeLastRow_ = val;
	}

	void setRowSpacerHeight( double val ) {
		rowSpacerHeight_ = val;
	}

	std::vector<double> columns_;
	std::vector<double> columnTweens_;

	double maxRowHeight_;
	double rowSpacerHeight_;
	bool maximizeLastRow_;
};


};







/**
*CVS Log info
*$Log$
*Revision 1.1.2.3  2004/11/17 04:52:48  ddiego
*added some minor fixes to win32 resource loading, and added 2 new examples that demonstrate basic resource loading and basic usage of dialogs.
*
*Revision 1.1.2.2  2004/09/07 03:57:04  ddiego
*misc tree control update
*
*Revision 1.1.2.1  2004/08/31 04:12:12  ddiego
*cleaned up the GraphicsContext class - made more pervasive use
*of transformation matrix. Added common print dialog class. Fleshed out
*printing example more.
*
*/



#endif //_HORIZONTALLAYOUTCONTAINER_H__






