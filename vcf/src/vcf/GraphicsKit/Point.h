
#if     _MSC_VER > 1000
#pragma once
#endif



#ifndef _VCF_POINT_H__
#define _VCF_POINT_H__

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

/* Generated by Together */


namespace VCF{

/**
*represents a 2 dimensional coordinate (x and y)
and stores the data as doubles, for maximum precision.
*/
class GRAPHICSKIT_API Point: public Object {
public:
    Point(const double & x, const double & y);

	Point();

	Point( const Point& pt ) : Object(pt), x_(pt.x_), y_(pt.y_){		

	}

	Point& operator = ( const Point& pt ) {
		x_ = pt.x_;
		y_ = pt.y_;
		return *this;
	}
	/**
	*the x coordinate of the point - specifies horizontal
	*values
	*/
    double x_;

	/**
	*the y coordinate of the point - specifies vertical 
	*values
	*/
    double y_;

	void init();

	/**
	*operator == overload for comparing two Points
	*/
	bool operator == ( const Point& pointToCompare )const{
		bool result = false;
		
		result = (this->x_ == pointToCompare.x_) &&
			     (this->y_ == pointToCompare.y_);

		return result;
	};

	/**
	*determines if the x and y coordinates specified are within the 
	*tolerance range
	*@param double x coordinate
	*@param double y coordinate
	*@param double the tolerance to use
	*@return true if the x and y coordinates are with the tolerance, other wise 
	*false. 
	*/
	bool closeTo( const double& x, const double& y, const double& tolerance=1.0 );

	bool closeTo( const Point& pt, const double& tolerance=1.0 );

	virtual String toString();



	Point& getPoint( void );
	void setPoint( const Point& point );

	bool isNull() const;
	void setNull();

	Point& offset( const double& _offset );		// added for clarity of use
	Point& offset( const Point& _offsetPt );	// added for clarity of use

	// comparison
	bool isInBetween ( const Point& pt1, const Point& pt2 );
	bool isInBetweenOpen ( const Point& pt1, const Point& pt2 );
	bool isInBetweenClose ( const Point& pt1, const Point& pt2 );

	// comparison operators
	bool operator != ( const Point& pointToCompare )const ;

	bool operator <= ( const Point& pointToCompare )const ;
	bool operator < ( const Point& pointToCompare )const ;
	bool operator >= ( const Point& pointToCompare )const ;
	bool operator > ( const Point& pointToCompare )const ;

	// unary operators
	Point& operator+= ( const Point& pt );
	Point& operator-= ( const Point& pt );
	Point& operator*= ( const Point& pt );
	Point& operator/= ( const Point& pt );

	// binary operators
	Point operator+ ( const Point& pt ) const ;
	Point operator- ( const Point& pt ) const ;
	Point operator* ( const Point& pt ) const ;
	Point operator/ ( const Point& pt ) const ;

	// unary scalar operators
	Point& operator+= ( const double d );
	Point& operator-= ( const double d );
	Point& operator*= ( const double d );
	Point& operator/= ( const double d );

	// binary scalar operators
	Point operator+ ( const double d ) const ;
	Point operator- ( const double d ) const ;
	Point operator* ( const double d ) const ;
	Point operator/ ( const double d ) const ;

};

///////////////////////////////////////////////////////////////////////////////
// inline

inline Point& Point::getPoint( void ) {
	return *this;
}

inline void Point::setPoint( const Point& point ) {
	x_ = point.x_;
	y_ = point.y_;
}

inline bool Point::isNull() const {
	return (x_ == 0) && (y_ == 0);
}

inline void Point::setNull() {
	x_ = 0;  y_ = 0;
}

inline Point& Point::offset( const double& _offset ) {
	return this->operator+= ( _offset );
}

inline Point& Point::offset( const Point& _offsetPt ) {
	return this->operator+= ( _offsetPt );
}

// comparison operators
inline bool Point::isInBetween ( const Point& pt1, const Point& pt2 ) {
	return ( pt1 <= *this && *this< pt2 );
};

inline bool Point::isInBetweenOpen ( const Point& pt1, const Point& pt2 ) {
	return ( pt1 < *this && *this< pt2 );
};

inline bool Point::isInBetweenClose ( const Point& pt1, const Point& pt2 ) {
	return ( pt1 <= *this && *this<= pt2 );
};

// comparison operators
inline bool Point::operator != ( const Point& pointToCompare )const {
	return ((this->x_ != pointToCompare.x_) ||
			(this->y_ != pointToCompare.y_));
};

inline bool Point::operator <= ( const Point& pointToCompare )const {
	return ((this->x_ <= pointToCompare.x_) &&
			(this->y_ <= pointToCompare.y_));
};
inline bool Point::operator < ( const Point& pointToCompare )const {
	return ((this->x_ < pointToCompare.x_) &&
			(this->y_ < pointToCompare.y_));
};
inline bool Point::operator >= ( const Point& pointToCompare )const {
	return ((this->x_ >= pointToCompare.x_) &&
			(this->y_ > pointToCompare.y_));
};
inline bool Point::operator > ( const Point& pointToCompare )const {
	return ((this->x_ > pointToCompare.x_) &&
			(this->y_ > pointToCompare.y_));
};

// unary operators
inline Point& Point::operator+= ( const Point& pt ) {
	x_ += pt.x_;
	y_ += pt.y_;
	return *this;
}

inline Point& Point::operator-= ( const Point& pt ) {
	x_ -= pt.x_;
	y_ -= pt.y_;
	return *this;
}

inline Point& Point::operator*= ( const Point& pt ) {
	x_ *= pt.x_;
	y_ *= pt.y_;
	return *this;
}

inline Point& Point::operator/= ( const Point& pt ) {
	x_ /= pt.x_;
	y_ /= pt.y_;
	return *this;
}

// binary operators
inline Point Point::operator+(const Point& pt) const {
	Point ps = *this;
	ps += pt;
	return ps;
}

inline Point Point::operator-(const Point& pt) const {
	Point ps = *this;
	ps -= pt;
	return ps;
}

inline Point Point::operator*(const Point& pt) const {
	Point ps = *this;
	ps *= pt;
	return ps;
}

inline Point Point::operator/(const Point& pt) const {
	Point ps = *this;
	ps /= pt;
	return ps;
}

// unary scalar operators
inline Point& Point::operator+= ( const double d ) {
	x_ += d;
	y_ += d;
	return *this;
}

inline Point& Point::operator-= ( const double d ) {
	x_ -= d;
	y_ -= d;
	return *this;
}

inline Point& Point::operator*= ( const double d ) {
	x_ *= d;
	y_ *= d;
	return *this;
}

inline Point& Point::operator/= ( const double d ) {
	x_ /= d;
	y_ /= d;
	return *this;
}

// binary scalar operators
inline Point Point::operator+(const double d) const {
	Point ps = *this;
	ps += d;
	return ps;
}

inline Point Point::operator-(const double d) const {
	Point ps = *this;
	ps -= d;
	return ps;
}

inline Point Point::operator*(const double d) const {
	Point ps = *this;
	ps *= d;
	return ps;
}

inline Point Point::operator/(const double d) const {
	Point ps = *this;
	ps /= d;
	return ps;
}

};


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.12.4.1  2004/04/26 21:58:21  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.12  2003/12/18 05:15:57  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.11.2.1  2003/10/28 04:06:10  ddiego
*updated the GraphicsContext and ContextPeer classes to support
*slider control drawing. adjusted the Slider control accordingly.
*Also changed some of the GraphicsKit headers to conform to the
*current header style.
*
*Revision 1.11  2003/08/09 02:56:42  ddiego
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
*Revision 1.10.2.1  2003/05/30 04:13:10  ddiego
*added the commandLine class
*changed the intialization functions for teh FoundationKit, GraphicsKit, and
*ApplicationKit to take command line parameters
*FoundationKit now allows you to retreive the commandline (it's stored)
*start up has changed from appMain() to main()
*added a custom GTK widget class for use in the various GTK peers - this will
*allow us to specify absolute positioning and let the VCF handle layout
*issues
*Miscellaneous clean in various interfaces
*removed the Rect, Point, and Size classes from the FoundationKit
*and moved them to the GraphicsKit
*
*Revision 1.10  2003/05/17 20:37:03  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.9.2.2  2003/03/23 03:23:45  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.9.2.1  2003/03/12 03:09:41  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.9  2003/02/26 04:30:38  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.8.14.2  2002/12/28 21:50:46  marcelloptr
*Fixes and improvements for WM_COPYDATA, Point, Rect, Size, GraphicsContext and StringUtils
*
*Revision 1.8.14.1  2002/11/28 05:12:04  ddiego
*modifications to allow the VCF to compile with MinGW. This also cleans up
*some warnings with GCC - should improve the linux side as well.
*In addition this checkin includes new files for building the VCF under
*the DevC++ IDE. these are in the vcf/build/devcpp directory.
*
*Revision 1.8  2002/03/31 19:54:33  ddiego
*fixed a release bug in the TreeListControl
*made sure that saving the state of a Frame works correctly
*
*Revision 1.7  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

#endif // _VCF_POINT_H__


