#ifndef _VCF_RECT_H__
#define _VCF_RECT_H__
//Rect.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */


namespace VCF{

#define RECT_CLASSID		"ED88C096-26AB-11d4-B539-00C04F0196DA"

/*
\class Rect Rect.h "vcf/GraphicsKit/Rect.h"
*a Rect class represents the four coordinates of a
*2 dimensional rectangle (left, top, right, and bottom). The
*values are stored as double for maximum precision.
*/
class GRAPHICSKIT_API Rect : public Object, public Persistable {
public:
	double bottom_;
	double right_;
	double top_;
	double left_;

public:

	Rect( const double & left, const double & top, const double & right, const double & bottom );

	Rect( const Rect& rect );

	Rect();

	double getLeft() const {
		return left_;
	};

	void setLeft( const double& left ){
		left_ = left;
	};

	double getTop() const {
		return top_;
	};

	void setTop( const double& top ){
		top_ = top;
	};

	double getRight() const {
		return right_;
	};

	void setRight( const double& right ){
		right_ = right;
	};

	double getBottom() const {
		return bottom_;
	};

	void setBottom( const double& bottom ){
		bottom_ = bottom;
	};

	/**
	*the width of the rectangle, or the value
	*returned from abs(right - left)
	*/
	double getWidth() const ;

	/**
	*the height of the rectangle, or the value
	*returned from abs(bottom - top)
	*/
	double getHeight() const ;

	/**
	*sets the left, top, right, and bottom all at once
	*/
	void setRect( const double & left, const double & top, const double & right, const double & bottom );
	void setRect( const Rect & rect );

	/**
	*sets the left, top, right, and bottom all at once using the two opposite corners
	*/
	void setRect ( const Point& topleft, const Point& bottomright );

	/**
	* gets a reference to this Rect instance itself.
	*to be used as conversion operator without introducing ambiguity between operators
	*/
	Rect& getRect(void);

	/**
	*changes the origin of a rectangle, i.e. its top left corner,
	*but not its size.
	*/
	void setOrigin(  const double& left, const double& top );
	void setOrigin( const Point& topleft );

	/**
	*changes the size of a rectangle, i.e. its width and its height,
	*but not its origin.
	*/
	void setSize(  const double& width, const double& height );
	void setWidth( const double& width );
	void setHeight( const double& height );

	/**
	*normalizes the rectangles coordinates so that
	*/
	void normalize();

	/**
	*tells if the rect is mormalized, i.e. if the top is
	*less than the bottom, and the left is less than the right.
	*/
	bool isNormalized() const;

	/**
	*tells if the rect is mormalized, i.e. if the top is
	*less than the bottom, and the left is less than the right.
	*/
	bool isEmpty() const;
	void setEmpty();

	bool isNull() const;
	void setNull();


	void offset( const double& dx, const double& dy );
	void offset( const Point& _offsetPt );

	/**
	*inflates the rectangle
	*@param double the amount to increase (or decrease if the value is negative)
	*the left and right coordinates
	*@param double the amount to increase (or decrease if the value is negative)
	*the top and bottom coordinates
	*/
	void inflate(const double & x, const double & y);

	/**
	*inflates the rectangle
	*@param double the amount to increase (or decrease if the value is negative)
	*for all the four edges
	*/
	void inflate( const double & left, const double & top, const double & right, const double & bottom );

	/**
	*inflates the rectangle
	*@param double the amount to increase (or decrease if the value is negative)
	*for all the four edges as given by a rectangle
	*/
	void inflate( const Rect& rect );

	void add( const Rect* rect );

	void subtract( const Rect* rect );

	/**
	*creates the Rect intersection of this instance with another rectangle
	*/
	Rect makeIntersection( const Rect* rect );

	/**
	*not implemented yet
	*/
	Rect makeUnion( const Rect* rect );

	Point getTopLeft(void) const;
	Point getTopRight(void) const;
	Point getBottomLeft(void) const;
	Point getBottomRight(void) const;

	Point getCenter(void) const;
	Point getCenterLeft(void) const;
	Point getCenterTop(void) const;
	Point getCenterRight(void) const;
	Point getCenterBottom(void) const;

	/**
	*tells if the point lay within this rectangle's coordinates
	*Any point on the top or on the left border of the rectangle 
	*is considered inside the rectangle.
	*@return bool, true if the point is within the rectangle's coordinates,
	*otherwise false
	*/
	bool containsPt( Point* point ) const;

	/**
	*tells if the point lay within this rectangle's coordinates
	*a given tolerance is admitted in order to consider the point inside the rectangle.
	*Again any point on the top or on the left border of the rectangle 
	*within the given tolerance is considered inside the rectangle.
	*/
	bool containsPtCloseTo( Point* point, const double& tolerance ) const;

	/**
	*tells if the point lay within this rectangle's coordinates
	*Any point on the border of the rectangle is <b>not</b> considered inside the rectangle.
	*/
	bool containsPtOpen( Point* point ) const;

	/**
	*tells if the point lay within this rectangle's coordinates
	*Any point on the border of the rectangle <b>is</b> considered inside the rectangle.
	*/
	bool containsPtClose( Point* point ) const;

	/**
	*tells if the specified rectangle fall inside the bound of this Rect instance.
	*/
	bool containsRect( Rect* rect ) const ;

	/**
	*tells if the specified rectangle fall inside the bound of this Rect instance.
	*This is always false though if a border of one rectangle is part of a border 
	*of the other rectangle.
	*/
	bool containsRectOpen( Rect* rect ) const ;

	/**
	*tells if the specified rectangle fall inside the bound of this Rect instance.
	*This is true even if a border of one rectangle is part of a border
	*of the other rectangle.
	*/
	bool containsRectClose( Rect* rect ) const ;

	// assignment operator
	Rect& operator= ( const Rect& rect );

	// comparison operators
	bool operator == ( const Rect& rectToCompare ) const;
	bool operator != ( const Rect& rectToCompare ) const;

	// unary operators
	Rect operator+ () const;
	Rect operator- () const;

	Rect& operator+= (const Rect& rc);
	Rect& operator-= (const Rect& rc);
	Rect& operator*= (const Rect& rc);
	Rect& operator/= (const Rect& rc);

	// binary operators
	Rect operator+ (const Rect& rc) const;
	Rect operator- (const Rect& rc) const;
	Rect operator* (const Rect& rc) const;
	Rect operator/ (const Rect& rc) const;

	// unary scalar operators
	Rect& operator+= (const double d);
	Rect& operator-= (const double d);
	Rect& operator*= (const double d);
	Rect& operator/= (const double d);

	// binary scalar operators
	Rect operator+ (const double d) const;
	Rect operator- (const double d) const;
	Rect operator* (const double d) const;
	Rect operator/ (const double d) const;


	/**
	*returns a String giving the infos about this Rect instance.
	*/
	virtual String toString() const;

	/**
	*writes the object to the specified output stream
	*/
	virtual void saveToStream( OutputStream * stream );

	/**
	*reads the object from the specified input stream
	*/
	virtual void loadFromStream( InputStream * stream );


	/**
	*This is only here because the RTTI functions are not "const safe" - kind of
	* stupid - will fix later.
	*/
	double _getLeft()   { return left_; };
	double _getTop()    { return top_; };
	double _getRight()  { return right_; };
	double _getBottom() { return bottom_; };
	double _getWidth()  { return fabs( right_ - left_ ); }
	double _getHeight() { return fabs( bottom_ - top_ ); };
};



///////////////////////////////////////////////////////////////////////////////
// inline implementation for Rect class

inline Rect::Rect( const double & left, const double & top, const double & right, const double & bottom ) {
	setRect( left, top, right, bottom );
}

inline Rect::Rect() {
	setRect( 0.0, 0.0, 0.0, 0.0 );
}

inline double Rect::getWidth() const {
	return fabs( right_ - left_ );
}

inline double Rect::getHeight() const {
	return fabs( bottom_ - top_ );
}

inline void Rect::setRect ( const Rect& rect ) {
	setRect( rect.left_, rect.top_, rect.right_, rect.bottom_ );
}

inline void Rect::setRect( const double & left, const double & top, const double & right, const double & bottom ) {
	left_   = left;
	right_  = right;
	top_    = top;
	bottom_ = bottom;
}

inline void Rect::setRect ( const Point& topleft, const Point& bottomright ) {
	setRect( topleft.x_, topleft.y_, bottomright.x_, bottomright.y_ );
}

inline Rect& Rect::getRect(void) {
	// conversion operator
	return ( *this );
}

inline void Rect::setNull() {
	setRect( 0.0, 0.0, 0.0, 0.0 );
}

inline bool Rect::isNull() const {
	return ( (left_ == 0.0) && (top_ == 0.0) && (right_ == 0.0) && (bottom_ == 0.0) );
}

inline void Rect::setEmpty() {
	setRect( left_, top_, left_, top_ );
}

inline bool Rect::isEmpty() const {
	return ( (getWidth() <= 0.0) || (getHeight() <= 0.0) );
}

inline bool Rect::isNormalized() const {
	return ( left_ <= right_ && top_ <= bottom_ );
}

inline void Rect::setOrigin(  const double& left, const double& top ){
	right_  += left - left_;
	bottom_ += top - top_;
	left_   = left;
	top_    = top;
};

inline void Rect::setOrigin( const Point& topleft ){
	right_  += topleft.x_ - left_;
	bottom_ += topleft.y_ - top_;
	left_   = topleft.x_;
	top_    = topleft.y_;
};

inline void Rect::setSize(  const double& width, const double& height ){
	right_  = left_ + width;
	bottom_ = top_ + height;
};

inline void Rect::setWidth( const double& width ){
	right_ = left_ + width;
};

inline void Rect::setHeight( const double& height ){
	bottom_ = top_ + height;
};

inline void Rect::offset( const double& dx, const double& dy ) {
	left_   += dx;
	right_  += dx;

	top_    += dy;
	bottom_ += dy;
}

inline void Rect::offset( const Point& _offsetPt ) {
	offset(_offsetPt.x_, _offsetPt.y_);
};

// assignment operator
inline Rect& Rect::operator= ( const Rect& rect ) {
	setRect( rect );
	return *this;
}

inline void Rect::inflate( const double & x, const double & y ) {
	left_   += (-x);
	right_  += x;

	top_    += (-y);
	bottom_ += y;
}

inline void Rect::inflate( const double & left, const double & top, const double & right, const double & bottom ) {
	left_   += (-left);
	right_  += right;
	top_    += (-top);
	bottom_ += bottom;
}

inline void Rect::inflate( const Rect& rect ) {
	left_   += (-rect.left_);
	right_  += rect.right_;
	top_    += (-rect.top_);
	bottom_ += rect.bottom_;
}

inline Point Rect::getTopLeft(void) const {
	return Point ( left_, top_ );
}

inline Point Rect::getTopRight(void) const {
	return Point ( right_, top_ );
}

inline Point Rect::getBottomLeft(void) const {
	return Point ( left_, bottom_ );
}

inline Point Rect::getBottomRight(void) const {
	return Point ( right_, bottom_ );
}

inline Point Rect::getCenter(void) const {
	return Point ( (left_ + right_) / 2 , (top_ + bottom_) / 2 );
}

inline Point Rect::getCenterLeft(void) const {
	return Point ( left_ , (top_ + bottom_) / 2 );
}

inline Point Rect::getCenterTop(void) const {
	return Point ( (left_ + right_) / 2 , top_ );
}

inline Point Rect::getCenterRight(void) const {
	return Point ( right_ , (top_ + bottom_) / 2 );
}

inline Point Rect::getCenterBottom(void) const {
	return Point ( (left_ + right_) / 2 , bottom_ );
}

// comparison operators
inline bool Rect::operator == ( const Rect& rectToCompare ) const {
	return ( (bottom_ == rectToCompare.bottom_) &&
		       (right_  == rectToCompare.right_) &&
		       (top_    == rectToCompare.top_) &&
		       (left_   == rectToCompare.left_) );
}

inline bool Rect::operator != ( const Rect& rectToCompare ) const {
	return ( ! operator ==( rectToCompare ) );
}

// unary operators
inline Rect Rect::operator+ () const {
	return *this;
}

inline Rect Rect::operator- () const {
	Rect rc (-left_, -top_, -right_, -bottom_);
	return rc;
}

inline Rect& Rect::operator+= (const Rect& rc) {
	left_ += rc.left_;
	top_ += rc.top_;
	right_ += rc.right_;
	bottom_ += rc.bottom_;
	return *this;
}

inline Rect& Rect::operator-= (const Rect& rc) {
	left_ -= rc.left_;
	top_ -= rc.top_;
	right_ -= rc.right_;
	bottom_ -= rc.bottom_;
	return *this;
}

inline Rect& Rect::operator*= (const Rect& rc) {
	left_ *= rc.left_;
	top_ *= rc.top_;
	right_ *= rc.right_;
	bottom_ *= rc.bottom_;
	return *this;
}

inline Rect& Rect::operator/= (const Rect& rc) {
	left_ /= rc.left_;
	top_ /= rc.top_;
	right_ /= rc.right_;
	bottom_ /= rc.bottom_;
	return *this;
}


// binary operators
inline Rect Rect::operator+ (const Rect& rc) const {
	Rect rs = *this;
	rs += rc;
	return rs;
}

inline Rect Rect::operator- (const Rect& rc) const {
	Rect rs = *this;
	rs -= rc;
	return rs;
}

inline Rect Rect::operator* (const Rect& rc) const {
	Rect rs = *this;
	rs *= rc;
	return rs;
}

inline Rect Rect::operator/ (const Rect& rc) const {
	Rect rs = *this;
	rs /= rc;
	return rs;
}


// unary scalar operators
inline Rect& Rect::operator+= (const double d) {
	left_ += d;
	top_ += d;
	right_ += d;
	bottom_ += d;
	return *this;
}

inline Rect& Rect::operator-= (const double d) {
	left_ -= d;
	top_ -= d;
	right_ -= d;
	bottom_ -= d;
	return *this;
}

inline Rect& Rect::operator*= (const double d) {
	left_ *= d;
	top_ *= d;
	right_ *= d;
	bottom_ *= d;
	return *this;
}

inline Rect& Rect::operator/= (const double d) {
	left_ /= d;
	top_ /= d;
	right_ /= d;
	bottom_ /= d;
	return *this;
}

// binary scalar operators
inline Rect Rect::operator+ (const double d) const {
	Rect rs = *this;
	rs += d;
	return rs;
}

inline Rect Rect::operator- (const double d) const {
	Rect rs = *this;
	rs -= d;
	return rs;
}

inline Rect Rect::operator* (const double d) const {
	Rect rs = *this;
	rs *= d;
	return rs;
}

inline Rect Rect::operator/ (const double d) const {
	Rect rs = *this;
	rs /= d;
	return rs;
}


}; // namespace VCF


/**
*CVS Log info
*$Log$
*Revision 1.4  2006/04/07 02:35:41  ddiego
*initial checkin of merge from 0.6.9 dev branch.
*
*Revision 1.3.4.1  2006/03/12 22:42:08  ddiego
*more doc updates - specific to graphicskit.
*
*Revision 1.3  2004/12/01 04:31:44  ddiego
*merged over devmain-0-6-6 code. Marcello did a kick ass job
*of fixing a nasty bug (1074768VCF application slows down modal dialogs.)
*that he found. Many, many thanks for this Marcello.
*
*Revision 1.2.2.2  2004/10/26 06:12:16  marcelloptr
*bugfix [1045603] forgotten const in Point and Rect; better formatting and documentation
*
*Revision 1.2  2004/08/07 02:49:18  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.2  2004/04/29 04:10:27  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.18.4.1  2004/04/26 21:58:21  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.18  2003/12/18 05:15:57  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.17.2.2  2003/10/28 04:06:10  ddiego
*updated the GraphicsContext and ContextPeer classes to support
*slider control drawing. adjusted the Slider control accordingly.
*Also changed some of the GraphicsKit headers to conform to the
*current header style.
*
*Revision 1.17.2.1  2003/09/12 16:46:33  ddiego
*finished adding header changes to improve compile speed (at least
*with MS VC++) and to get rid of some of the clutter that the RTTI macros
*add.
*But Where'd the RTTI info go!?!?
*Have no fear it's still there! It is now located in three .inl files, one
*for each kit. Each kit will consolidate it's RTTI decls in the following
*files:
*FoundationKit:
*  vcf/include/FoundationKitRTTI.inl
*GraphicsKit:
*  vcf/include/GraphicsKitRTTI.inl
*ApplicationKit:
*  vcf/include/ApplicationKitRTTI.inl
*
*Please alter these files as neeccessary to add/subtract/alter the various
*RTTI info. Each kit is also responsible for registering any of the class
*in the ClassRegistry.
*A side effect of this is that I had to alter the memory allocation for the
*VC6 build for the Application it went from /Zm120 to /Zm150. I find this
*pretty lame but I don't know what else to do. Hopefully this will improve
*compile times when using the Appkit in other programs.
*
*Revision 1.17  2003/08/09 02:56:42  ddiego
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
*Revision 1.16.2.1  2003/05/30 04:13:10  ddiego
*added the commandLine class
*changed the intialization functions for the FoundationKit, GraphicsKit, and
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
*Revision 1.16  2003/05/17 20:37:04  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.15.2.3  2003/05/15 03:01:00  ddiego
*added initial osx source( FoundationKit only),
*plus some fixes to compile under GCC 3.x compilers
*
*Revision 1.15.2.2  2003/05/13 03:57:12  ddiego
*cleaned up the GraphicsKit, got rid of some old crap files, cleaned
*up the ContextPeer so that tehre are fewer methods to implement, and
*moved the repetitive fillPath and strokePath code that was copied into
*all the context peers back into the GraphicsContext where it belongs
*
*Revision 1.15.2.1  2003/03/12 03:09:42  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.15  2003/02/26 04:30:38  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.14.2.5  2003/01/11 23:17:24  ddiego
*added extra functionality to the static makefile in vcf/build/make
*added some bug fixes to X11
*
*Revision 1.14.2.4  2003/01/08 23:51:03  marcelloptr
*forgotten functions in Rect and FileStream
*
*Revision 1.14.2.3  2002/12/30 03:59:25  ddiego
*more X11 porting code. Now have X11UIToolkit::runEventLoop partially implemented
*Can create and paint in a Window object! Woo hoo!
*Color class is crurently broken on linux, will fix pronto
*
*Revision 1.14.2.2  2002/12/28 21:50:46  marcelloptr
*Fixes and improvements for WM_COPYDATA, Point, Rect, Size, GraphicsContext and StringUtils
*
*Revision 1.14.2.1  2002/12/27 23:04:32  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.14  2002/11/18 00:46:07  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.13.10.1  2002/10/01 20:34:45  ddiego
*borders
*
*Revision 1.13  2002/05/09 03:10:42  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.12.4.2  2002/03/25 04:19:45  ddiego
*fixed some file checking problems in xmake and fixed some general
*code to be able to compile with GCC and Borland C++
*
*Revision 1.12.4.1  2002/03/20 21:56:55  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.12  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_RECT_H__


