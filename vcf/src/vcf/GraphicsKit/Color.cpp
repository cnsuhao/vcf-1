/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.15  2003/12/18 05:16:01  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.14.2.3  2003/11/10 01:57:43  ddiego
*add a fromString methods to StingUtils
*added some minor fixes to list box control and added a SelectionChanged
*Delegate to it
*add some minor fixes ot ComboBoxControl
*added an unknownColor() method to ColorNames class
*
*Revision 1.14.2.2  2003/10/20 03:40:25  ddiego
* made some minor changes fixed a bug in color where we forget to actually
*assign hls/hsv values.
*
*Revision 1.14.2.1  2003/08/26 01:20:23  marcelloptr
*removed inline keyword in Color.cpp in front of some ColorSpace memeber functions definitions
*
*Revision 1.14  2003/08/09 02:56:45  ddiego
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
*Revision 1.13.2.1  2003/07/24 04:10:44  ddiego
*added fixes for the following tasks:
*Task #82279 ApplicationKit: add static methods to singleton objects
*Task #82277 FoundationKit: add static methods to singleton objects
*this required a bunch of changes in terms of getting rid of older style code
*
*Revision 1.13  2003/05/17 20:37:20  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.12.2.2  2003/04/17 04:29:50  ddiego
*updated scintilla, added gtk support for the application kit, with stubs
*for the basic peers.
*
*Revision 1.12.2.1  2003/03/12 03:11:59  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.12  2003/02/26 04:30:46  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.11.2.8  2003/01/08 04:25:56  marcelloptr
*ColorNames static map and Color::s_ now use String instead than String* - VCF_LARGE_COLOR_LIST introduced
*
*Revision 1.11.2.7  2003/01/08 00:19:50  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.11.2.6  2002/12/31 07:02:17  ddiego
*trying to track issues with parenting in X. Made some fixes in the Color class
*and the ContextPeer class to work in gcc/X
*
*Revision 1.11.2.5  2002/12/30 21:48:07  ddiego
*miscellaneous fixes to the ColorNames class. Adjusted the way it looks up colors
*and got rid of some of the extern variables, also removed the pragma lib in the
*color.cpp file
*
*: ----------------------------------------------------------------------
*
*Revision 1.11.2.4  2002/12/30 00:24:13  ddiego
*made some minor modifications to Marcello's additions to the Color class
*Also modified the Application class to work with hooking OS Native event
*in a more general way.
*
*Revision 1.11.2.3  2002/12/28 22:51:32  marcelloptr
*Color Spaces transformations and Color Names
*
*Revision 1.11.2.2  2002/12/27 23:04:46  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.11.2.1  2002/11/28 05:12:04  ddiego
*modifications to allow the VCF to compile with MinGW. This also cleans up
*some warnings with GCC - should improve the linux side as well.
*In addition this checkin includes new files for building the VCF under
*the DevC++ IDE. these are in the vcf/build/devcpp directory.
*
*Revision 1.11  2002/11/18 00:46:09  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.10.4.1  2002/09/28 22:22:46  ddiego
*added some support for font info and determinging the names on the system
*
*Revision 1.10  2002/09/12 03:26:05  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.9.12.1  2002/08/06 02:57:36  ddiego
*added base X11 files for GraphicsKit and made sure that the GraphicsKit compiles
*under linux (GCC). There is now a new dir under build/xmake called GraphicsKit
*where the xmake build script lives. This checkin also includes the base X11
*include (as part of GraphicsKitPrivate.h), as well as linking to the X11 libs
*
*Revision 1.9  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

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
#include "vcf/GraphicsKit/GraphicsKit.h"


// NORMALIZED_HUE has the advantage that it is normalized between 0 and 1
//	but !NORMALIZED_HUE seems to me to have the advantage that a small change in luminosity doesn't find colors with different Hue when H is in [1-1/6, 1] ( like crimson )
//#define NORMALIZED_HUE



using namespace VCF;


#define VCF_RGB(r,g,b) ((ulong32)(((uchar)(r)|((ushort)((uchar)(g))<<8))|(((ulong32)(uchar)(b))<<16)))



std::map<ColorNames::ColorID, String> ColorNames::nameMap;
EnumeratorMapContainer<std::map<ColorNames::ColorID, String>, String > ColorNames::nameMapContainer;

String ColorNames::unknownColorName;


const double ColorSpace::HueCriticalMax	= HUECRITICALMAX;	// Hue > HueCriticalMax => rgb.R > 1;
const int	ColorSpace::RGBMax			= RGBMAX;			// This is what Windows in the Display Properties dialog uses in the ColorPicker tool.
const int	ColorSpace::HSLMax			= HSLMAX;			// max r/g/b value is 255 in Windows


Color::Color()
{
	r_ = 0.0;	
	g_ = 0.0;
	b_ = 0.0;
	setColorDbg();
}

Color::Color( const Color& color )
{
	b_ = color.b_;
	g_ = color.g_;
	r_ = color.r_;

	setColorDbg();
}

Color::Color( const double & val1, const double & val2, const double & val3, ColorType type )
{
	
	
	switch ( type ) {
		case ctRGB : {					
			r_ = val1;
			g_ = val2;
			b_ = val3;
		}
		break;

		case ctHLS : {
			ColorSpace::HSLtype hls;
			hls.H = val1;
			hls.L = val2;
			hls.S = val3;
			
			ColorSpace::RGBtype rgb = ColorSpace::HSLToRGB( hls );
			
			r_ = rgb.R;
			g_ = rgb.G;
			b_ = rgb.B;			
		}
		break;

		case ctHSV : {
			ColorSpace::HSVtype hsv;
			hsv.H = val1;
			hsv.S = val2;
			hsv.V = val3;
			
			ColorSpace::RGBtype rgb = ColorSpace::HSVToRGB( hsv );
			
			r_ = rgb.R;
			g_ = rgb.G;
			b_ = rgb.B;			
		}
		break;		
	}
	
	setColorDbg();
}

Color::Color( const double & c, const double & m, const double & y, const double & k )
{
	setColorDbg();
}

Color::Color( const unsigned char & r, const unsigned char & g, const unsigned char & b )
{
	r_ = ((double)r) / 255.0; 
	g_ = ((double)g) / 255.0; 
	b_ = ((double)b) / 255.0; 
	setColorDbg();
}

Color::Color(const unsigned long & color, ColorFormat cf )
{	

	switch ( cf ) {
		case cfARGB : {
			r_ = ((unsigned char*)&color)[2] / 255.0;	
			g_ = ((unsigned char*)&color)[1] / 255.0;
			b_ = ((unsigned char*)&color)[0] / 255.0;		
		}
		break;
		
		case cfABGR : {
			r_ = ((unsigned char*)&color)[0] / 255.0;	
			g_ = ((unsigned char*)&color)[1] / 255.0;
			b_ = ((unsigned char*)&color)[2] / 255.0;		
		}
		break;
	}	
	
	setColorDbg();

}



void Color::getHSV( double & h, double & s, double & v ) const
{
	ColorSpace::HSVtype hsv;
	ColorSpace::RGBtype rgb;
	rgb.R = r_;
	rgb.G = g_;
	rgb.B = b_;
	
	hsv = ColorSpace::RGBToHSV( rgb );
	
	h = hsv.H;
	s = hsv.S;
	v = hsv.V;	
}

void Color::getHLS( double & h, double & l, double & s ) const
{
	ColorSpace::HSLtype hls;
	ColorSpace::RGBtype rgb;
	rgb.R = r_;
	rgb.G = g_;
	rgb.B = b_;
	
	hls = ColorSpace::RGBToHSL( rgb );
	
	h = hls.H;
	l = hls.L;
	s = hls.S;	
}

void Color::getCMYK( double & c, double & m, double & y, double & k ) const
{

}

void Color::getRGB( unsigned char & r, unsigned char & g, unsigned char & b ) const
{
	r = (unsigned char)(r_ * 255 + 0.5);
	g = (unsigned char)(g_ * 255 + 0.5);
	b = (unsigned char)(b_ * 255 + 0.5);
}

void Color::getRGB( double & r, double & g, double & b ) const
{
	r = r_;
	g = g_;
	b = b_;
}

unsigned long Color::getRGB( ColorFormat cf ) const
{	
	unsigned long rgb = 0;
	
	switch ( cf ) {
		case cfARGB : {			
			((unsigned char*)(&rgb))[2] = (unsigned char)(r_ * 255 + 0.5);
			((unsigned char*)(&rgb))[1] = (unsigned char)(g_ * 255 + 0.5);
			((unsigned char*)(&rgb))[0] = (unsigned char)(b_ * 255 + 0.5);			
		}
		break;
		
		case cfABGR : {
			((unsigned char*)(&rgb))[0] = (unsigned char)(r_ * 255 + 0.5);
			((unsigned char*)(&rgb))[1] = (unsigned char)(g_ * 255 + 0.5);
			((unsigned char*)(&rgb))[2] = (unsigned char)(b_ * 255 + 0.5);			
		}
		break;
	}	
	
	return rgb;
}

void Color::getLab() const
{

}

void Color::getYUV() const
{

}


void Color::setHSV( const double & h, const double & s, const double & v )
{
	ColorSpace::HSVtype hsv;
	hsv.H = h;
	hsv.S = s;
	hsv.V = v;
	
	ColorSpace::RGBtype rgb = ColorSpace::HSVToRGB( hsv );
	
	r_ = rgb.R;
	g_ = rgb.G;
	b_ = rgb.B;	

	setColorDbg();
}

void Color::setHLS( const double & h, const double & l, const double & s )
{
	ColorSpace::HSLtype hls;
	hls.H = h;
	hls.L = l;
	hls.S = s;
	
	ColorSpace::RGBtype rgb = ColorSpace::HSLToRGB( hls );
	
	r_ = rgb.R;
	g_ = rgb.G;
	b_ = rgb.B;	

	setColorDbg();
}

void Color::setCMYK( const double & c, const double & m, const double & y, const double & k )
{
	setColorDbg();
}

void Color::setRGB( const unsigned char & r, const unsigned char & g, const unsigned char & b )
{
	r_ = ((double)r) / 255.0; 
	g_ = ((double)g) / 255.0; 
	b_ = ((double)b) / 255.0; 
	setColorDbg();
}

void Color::setRGB( const double & r, const double & g, const double & b)
{
	r_ = r;
	g_ = g;
	b_ = b;
	setColorDbg();
}

void Color::setRGB( const unsigned long& rgb, ColorFormat cf )
{
	switch ( cf ) {
		case cfARGB : {
			r_ = ((unsigned char*)&rgb)[2] / 255.0;	
			g_ = ((unsigned char*)&rgb)[1] / 255.0;
			b_ = ((unsigned char*)&rgb)[0] / 255.0;		
		}
		break;
		
		case cfABGR : {
			r_ = ((unsigned char*)&rgb)[0] / 255.0;	
			g_ = ((unsigned char*)&rgb)[1] / 255.0;
			b_ = ((unsigned char*)&rgb)[2] / 255.0;		
		}
		break;
	}	
	
	setColorDbg();
}

void Color::setLab()
{
	setColorDbg();
}

void Color::setYUV()
{
	setColorDbg();
}


void Color::brighter()
{
	setColorDbg();
}


void Color::darker()
{
	setColorDbg();
}

double Color::getRed() const
{
	return r_;
}

double Color::getGreen() const
{
	return g_;
}

double Color::getBlue() const
{
	return b_;
}

void Color::copy( const Color* color )
{
	if ( NULL != color ){
		r_ = color->getRed();
		g_ = color->getGreen();
		b_ = color->getBlue();

		setColorDbg();
	}
}

void Color::copy( const Color& color )
{
	r_ = color.getRed();
	g_ = color.getGreen();
	b_ = color.getBlue();

	setColorDbg();
}

Color* Color::getColor( const int& gray ) {
	return GraphicsToolkit::getColorFromColormap( gray );
}

Color* Color::getColor( const String& colorName )
{
	return GraphicsToolkit::getColorFromColormap( colorName );
}

Color* Color::getColorMatch( const Color& color )
{
	return GraphicsToolkit::getColorMatchFromColormap( color );
}

Color Color::getColorContrast( const Color& clrRef, double deltaL/*=0.3*/ )
{
	return GraphicsToolkit::getColorContrast( clrRef, deltaL );
}



const String Color::getColorNameFromMap( Color& color ) {
	
	return GraphicsToolkit::getColorNameFromMap( color );
}

void Color::setRed( const double& red )
{
	r_ = red;
	setColorDbg();
}

void Color::setGreen( const double& green )
{
	g_ = green;
	setColorDbg();
}

void Color::setBlue( const double& blue )
{
	b_ = blue;
	setColorDbg();
}

int Color::getLuminosity() const {
	unsigned char r, g, b;
	getRGB (r, g, b);
	int rgbMax = maxVal<>( maxVal<>(r,g), b);
	int rgbMin = minVal<>( minVal<>(r,g), b);
	return (int) (double) (((rgbMax+rgbMin) * ColorSpace::HSLMax) + ColorSpace::RGBMax ) / (2 * ColorSpace::RGBMax);
}

void Color::getInvertedRGB( unsigned char & r, unsigned char & g, unsigned char & b ) const
{
	r = (unsigned char)( (1.0 - r_ ) * 255 + 0.5);
	g = (unsigned char)( (1.0 - g_ ) * 255 + 0.5);
	b = (unsigned char)( (1.0 - b_ ) * 255 + 0.5);
}

void Color::getInvertedRGB( double & r, double & g, double & b ) const
{
	r =  ( 1.0 - r_ );
	g =  ( 1.0 - g_ );
	b =  ( 1.0 - b_ );
}

unsigned long Color::getInvertedRGB( ColorFormat cf ) const
{	
	unsigned long rgb = 0;
	
	switch ( cf ) {
		case cfARGB : {			
			((unsigned char*)(&rgb))[2] = (unsigned char)( (1.0 - r_ ) * 255 + 0.5);
			((unsigned char*)(&rgb))[1] = (unsigned char)( (1.0 - g_ ) * 255 + 0.5);
			((unsigned char*)(&rgb))[0] = (unsigned char)( (1.0 - b_ ) * 255 + 0.5);
		}
		break;
		
		case cfABGR : {
			((unsigned char*)(&rgb))[0] = (unsigned char)( (1.0 - r_ ) * 255 + 0.5);
			((unsigned char*)(&rgb))[1] = (unsigned char)( (1.0 - g_ ) * 255 + 0.5);
			((unsigned char*)(&rgb))[2] = (unsigned char)( (1.0 - b_ ) * 255 + 0.5);
		}
		break;
	}	
	
	return rgb;
}

void Color::invert() {
	// change the color to its complement
	r_ =  ( 1.0 - r_ );
	g_ =  ( 1.0 - g_ );
	b_ =  ( 1.0 - b_ );

	setColorDbg();
}


///////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// class ColorSpace  -  implementation

//////////////////
// Helper function to compute the luminosity for an RGB color.
// Measures how bright the color is. I use this so I can draw the caption
// text using the user's chosen color, unless it's too dark. See MSDN for
// definition of luminosity and how to compute it.
//
int ColorSpace::getLuminosity( const Color& color )
{
	int r = (int)(color.getRed() * 255.0);
	int g = (int)(color.getGreen() * 255.0);
	int b = (int)(color.getBlue() * 255.0);
	int rgbMax = maxVal<>( maxVal<>(r,g), b);
	int rgbMin = minVal<>( minVal<>(r,g), b);
	return (int) (double) (((rgbMax+rgbMin) * ColorSpace::HSLMax) + ColorSpace::RGBMax ) / (2 * ColorSpace::RGBMax);
}

ColorSpace::HSVtype ColorSpace::RGBToHSV( const RGBtype& rgb ) 
{ 
	// Code from: 
	//	Alvy Ray Smith and Eric Ray Lyons. HWB - A more intuitive hue-based color model. Journal of Graphics Tools, 1(1):3-17, 1996 
	//	http://www.acm.org/jgt/papers/SmithLyons96/

	// RGB are each on [0, 1]. S and V are returned on [0, 1] and H is  
	// returned on [0, 6]. Exception: H is returned UNDEFINED if S==0.  
	double R, G, B;
	SPLIT_RGB(rgb, R, G, B);
	double dMax, dMin, f;  
	int i;  
	HSVtype hsv;  

	dMin = minVal<>( minVal<>(R, G), B);  
	dMax = maxVal<>( maxVal<>(R, G), B);  
	if (dMax == dMin) {
		MAKE_HSV ( hsv, ColorSpace::hue_undefined, 0, dMax );
		return hsv;
	}

	f = (R == dMin) ? G - B : ((G == dMin) ? B - R : R - G);  
	i = (R == dMin) ? 3 : ((G == dMin) ? 5 : 1);  

	MAKE_HSV( hsv, i - f /(dMax - dMin), (dMax - dMin)/dMax, dMax );
	return hsv;
} 

ColorSpace::RGBtype ColorSpace::HSVToRGB( const HSVtype& hsv ) 
{
	// Code from: 
	//	Alvy Ray Smith and Eric Ray Lyons. HWB - A more intuitive hue-based color model. Journal of Graphics Tools, 1(1):3-17, 1996 
	//	http://www.acm.org/jgt/papers/SmithLyons96/

	// H is given on [0, 6] or UNDEFINED. S and V are given on [0, 1].  
	// RGB are each returned on [0, 1].  
	double h, s, v;
	SPLIT_HSV(hsv, h, s, v);
	double m, n, f;  
	int i;  
	RGBtype rgb;  

	if ( h == ColorSpace::hue_undefined ) {
		MAKE_RGB(rgb, v, v, v);
		return rgb;
	}

	i = static_cast<int>(floor(h));
	f = h - i;  
	if (!(i & 1)) {
		f = 1 - f; // if i is even  
	}
	m = v * (1 - s);  
	n = v * (1 - s * f);  
	switch (i) {  
		case 6:	// no break here !
		case 0: 
			MAKE_RGB(rgb, v, n, m);  
			break;
		case 1: 
			MAKE_RGB(rgb, n, v, m);  
			break;
		case 2: 
			MAKE_RGB(rgb, m, v, n)  
			break;
		case 3: 
			MAKE_RGB(rgb, m, n, v);  
			break;
		case 4: 
			MAKE_RGB(rgb, n, m, v);  
			break;
		case 5: 
			MAKE_RGB(rgb, v, m, n);  
			break;
	}
	
	return rgb;
} 

double ColorSpace::HueToColorValue( double Hue, const double dMin, const double dMax )
{
    double V;

	if (Hue < 0) {
		Hue = Hue + 1;
	} else {
		if (Hue > 1) {
			Hue = Hue - 1;
		}
	}

	if (6 * Hue < 1)
	{
		V = dMin + (dMax - dMin) * Hue * 6;
	} 
	else 
	{
		if (2 * Hue < 1) 
		{
			V = dMax;
		} 
		else 
		{
			if (3 * Hue < 2) 
			{
				V = dMin + (dMax - dMin) * (2/3 - Hue) * 6;
			} 
			else 
			{
				V = dMin;
			}
		}
	}

	return V;
    //return static_cast<byte>(floor (ColorSpace::RGBMax * V));	//round
}

ColorSpace::HSLtype ColorSpace::HSLRangeToHSL ( const HSLrangetype& hslRange )
{
	HSLtype hsl;
	//the casting is necessary
	hsl.H = (double) hslRange.H / (ColorSpace::HSLMax-1);
	hsl.S = (double) hslRange.S / ColorSpace::HSLMax;
	hsl.L = (double) hslRange.L / ColorSpace::HSLMax;

	return hsl;
}

ColorSpace::HSLrangetype ColorSpace::HSLToHSLRange ( const HSLtype& hsl )
{
	HSLrangetype hslRange;
  hslRange.H = static_cast<int>( floor ( hsl.H * (ColorSpace::HSLMax - 1) ) );	//round
  hslRange.S = static_cast<int>( floor ( hsl.S * ColorSpace::HSLMax ) );				//round
  hslRange.L = static_cast<int>( floor ( hsl.L * ColorSpace::HSLMax ) );				//round
	return hslRange;
}

double HueToColorValue ( double h, double dMin, double dMax ) {
	double v;

	if ( h < 0 ) {
		h += 1;
	} else if ( h > 1 ) {
		h -= 1;
	}

	if ( 6 * h < 1 ) {
    v = dMin + (dMax - dMin) * h * 6;
	} else if ( 2 * h < 1 ) {
      v = dMin;
	} else if ( 3 * h < 2 ) {
		v = dMin + (dMax - dMin) * (2/3 - h) * 6;
	} else {
		v = dMin;
	}

	return v;
}

ColorSpace::RGBtype ColorSpace::HSLToRGB ( const HSLtype& hsl )
{
	//from: http://www.undu.com/DN971201/00000019.htm and http://www.undu.com/DN971201/00000021.htm
	//from: http://www.vbaccelerator.com/codelib/gfx/clrman1.htm

	double H, S, L;
	SPLIT_HSL(hsl, H, S, L);

	double dMin, dMax;
	double R, G, B;

	if (S == 0)
	{
		//Achromatic case:

			//commented: H has been probably set manually. But this is not harmful anyway.
			//#ifdef _DEBUG
			//	if ( H == ColorSpace::hue_undefined) {
			//		StringUtils::traceWithArgs("HSLToRGB: Warning: function used with S==0 (h=%f, s=%f, l=%f\n", H, S, L );
			//		//assert( H == ColorSpace::hue_undefined );
			//	}
			//#endif

		R = L;	//L;	//static_cast<byte>(floor (ColorSpace::RGBMax * L));	//round		//changed !
		G = L;	//R;																//changed !
		B = L;	//R;																//changed !
	} 
	else 
	{
		//Chromatic case: 

#ifdef SKIP_WRONG_VERSION
			//delta = Max-Min 
			if (L <= 0.5) {
				//s = (Max - Min) / (Max + Min) 
				// Get Min value: 
					dMax = L * (1 + S);
					//dMin = L * (1 - S) ;
				} else {
					// s = (Max - Min) / (2 - Max - Min) 
				// Get Min value: 
					dMax = L + S - L * S;
					//dMin = L - S * (1 - L) ;
				}
			dMin = 2 * L - dMax;
			// Get the Max value: 
			//dMax = 2 * L - dMin ;

			// Now depending on sector we can evaluate the h,l,s: 
			R = HueToColorValue (H + 1/3, dMin, dMax);
			G = HueToColorValue (H, dMin, dMax);
			B = HueToColorValue (H - 1/3, dMin, dMax);
#else
				//delta = Max-Min 
				if (L <= 0.5) {
					//s = (Max - Min) / (Max + Min) 
					// Get Min value: 
					//dMax = L * (1 + S);
						dMin = L * (1 - S) ;
				} else {
						// s = (Max - Min) / (2 - Max - Min) 
					// Get Min value: 
					//dMax = L + S - L * S;
						dMin = L - S * (1 - L) ;
				}
				//dMin = 2 * L - dMax;
				// Get the Max value: 
				dMax = 2 * L - dMin ;

				// Now depending on sector we can evaluate the h,l,s: 
				//	R = HueToColourValue (H + 1/3, dMin, dMax);
				//	G = HueToColourValue (H, dMin, dMax);
				//	B = HueToColourValue (H - 1/3, dMin, dMax);

					//here we have H in [0-1], not in [0-6], so...
#ifdef NORMALIZED_HUE
				if ( ColorSpace::HueCriticalMax < H ) {
					H = H - 1;
				}
				H = H * 6;
#endif

				// Now depending on sector we can evaluate the H,L,S:
				if (H < 1) {
					R = dMax ;
					if (H < 0) { 
						G = dMin ;
						B = G - H * (dMax - dMin) ;
					} else {
						B = dMin ;
						G = H * (dMax - dMin) + B ;
					}
				} else if (H < 3) {
					G = dMax ;
					if (H < 2) {
						B = dMin ;
						R = B - (H - 2) * (dMax - dMin) ;
					} else {
						R = dMin ;
						B = (H - 2) * (dMax - dMin) + R ;
					}
				} else {
					B = dMax ;
					if (H < 4) {
						R = dMin ;
						G = R - (H - 4) * (dMax - dMin) ;
					} else {
						G = dMin ;
						R = (H - 4) * (dMax - dMin) + G ;
					}
				}
#endif
  }

	RGBtype rgb;
	MAKE_RGB (rgb, R, G, B);
  return rgb;
}

//		Coding the HLS Model
//	
//		Normally Hue is expressed as an angle between 0-360 to describe the colour 
//		and a value between 0 and 1 to describe Hue and Saturation. 
//		I have missed out the conversion to an angle in this implementation 
//		so the Hue works as follows: 
//				Hue Value Colour 
//				-1 Magenta 
//				0 Red 
//				1 Yellow 
//				2 Green 
//				3 Aqua 
//				4 Blue 
//				5 Magenta 

ColorSpace::HSLtype ColorSpace::RGBToHSL( const RGBtype& rgb )
{
	double R = rgb.R, G = rgb.G, B = rgb.B;

	double D, dMax, dMin;
	double H, S, L;
	HSLtype hsl;

	dMax = maxVal<> (R, maxVal<> (G, B));
	dMin = minVal<> (R, minVal<> (G, B));

	// calculate luminosity (this is the lightness)
	L = (dMax + dMin) / 2;

	// Next calculate saturation
	if (dMax == dMin)	// it's gray
	{
		// Achromatic case
		H = ColorSpace::hue_undefined; // it's actually undefined	//changed by M.P.
		S = 0;

		// commented: this is in my opinion the best solution: L unchanged, as adopted originally 
		//		in http://www.undu.com/DN971201/00000021.htm by RGBToHSL(), but L = dMin in RGBToHSV()
		//L = dMin;	// commented
	} 
	else 
	{
		// Chromatic case
		D = dMax - dMin;

			// first calculate Saturation
		if (L < 0.5) {
			S = D / (dMax + dMin);
		} else {
			S = D / (2 - dMax - dMin);
		}

			// then calculate Hue
		if (R == dMax) {
			H = (G - B) / D;				// resulting color is between yellow and magenta
		} else if (G == dMax) {
			H  = 2 + (B - R) /D;		// resulting color is between cyan and yellow
		} else {
			H = 4 + (R - G) / D;		// resulting color is between magenta and cyan
		}

		//this next part is missed in http://www.undu.com/DN971201/00000021.htm because H is in [0-6]; but we want it in [0-1]
#ifdef NORMALIZED_HUE
		H = H / 6;
		if (H < 0) {
			H = H + 1;
		}
#endif
	}

	MAKE_HSL(hsl, H, S, L);
	return hsl;
}

ColorSpace::RGBrangetype ColorSpace::RGBToRGBRange( const RGBtype& rgb )
{
	RGBrangetype rgbRange;
	MAKE_RGB( rgbRange, static_cast<int>(rgb.R * ColorSpace::RGBMax + 0.5),		// + 0.5 to compensate rounding errors + static_cast<int>( ((double)(3.0/255))*255 = 2) !
						static_cast<int>(rgb.G * ColorSpace::RGBMax + 0.5), 
						static_cast<int>(rgb.B * ColorSpace::RGBMax + 0.5) );
	return rgbRange;
}

ColorSpace::RGBtype ColorSpace::RGBRangeToRGB(const RGBrangetype& rgbRange)
{
	RGBtype rgb;
	MAKE_RGB ( rgb, (double)rgbRange.R / ColorSpace::RGBMax, 
					(double)rgbRange.G / ColorSpace::RGBMax, 
					(double)rgbRange.B / ColorSpace::RGBMax );	// casting is necessary
	return rgb;
}

ulong32 ColorSpace::RGBToColorLong (const RGBtype& rgb)
{
	return VCF_RGB( rgb.R * ColorSpace::RGBMax, rgb.G * ColorSpace::RGBMax, rgb.B * ColorSpace::RGBMax );
}

ColorSpace::RGBtype ColorSpace::ColorLongToRGB ( const ulong32 color )
{
	RGBtype rgb;
	Color c(color);
	//the casting is necessary
	rgb.R = (double) (c.getRed() * 255.0) / ColorSpace::RGBMax;				// red..
	rgb.G = (double) (c.getGreen() * 255.0) / ColorSpace::RGBMax;				// ..green
	rgb.B = (double) (c.getBlue() * 255.0) / ColorSpace::RGBMax;				// ..blue color vals
	return rgb;
}

ulong32 ColorSpace::HSLToColorLong (const HSLtype& hsl)
{
	RGBtype rgb;
	rgb = HSLToRGB (hsl);

	return VCF_RGB(rgb.R * ColorSpace::RGBMax, rgb.G * ColorSpace::RGBMax, rgb.B * ColorSpace::RGBMax);
}

ColorSpace::HSLtype ColorSpace::ColorLongToHSL ( const ulong32 color )
{
	RGBtype rgb;
	//the casting is necessary
	Color c(color);
	rgb.R = (double) (c.getRed() * 255.0) / ColorSpace::RGBMax;
	rgb.G = (double) (c.getGreen() * 255.0) / ColorSpace::RGBMax;
	rgb.B = (double) (c.getBlue() * 255.0) / ColorSpace::RGBMax;

	return RGBToHSL(rgb);
}

ColorSpace::RGBtype ColorSpace::HSLRangeToRGB ( const HSLrangetype& hslRange )
{
	HSLtype hsl = HSLRangeToHSL(hslRange);
	return HSLToRGB (hsl);
}

ColorSpace::HSLrangetype ColorSpace::RGBToHSLRange ( const RGBtype& rgb )
{
	HSLtype hsl;
	hsl = RGBToHSL (rgb);

	HSLrangetype hslRange = HSLToHSLRange(hsl);
	return hslRange;
}

ulong32 ColorSpace::HSLRangeToColorLong ( const HSLrangetype& hslRange )
{
	RGBtype rgb = HSLRangeToRGB (hslRange);
	return VCF_RGB(rgb.R, rgb.G, rgb.B);
}

ColorSpace::HSLrangetype ColorSpace::ColorLongToHSLRange ( ulong32 color )
{
	RGBtype rgb;
	Color c(color);
	//the casting is necessary
	rgb.R = (double) (c.getRed() * 255.0) / ColorSpace::RGBMax;
	rgb.G = (double) (c.getGreen() * 255.0)/ ColorSpace::RGBMax;
	rgb.B = (double) (c.getBlue() * 255.0) / ColorSpace::RGBMax;

	return RGBToHSLRange (rgb);
}

ColorSpace::HWBtype ColorSpace::RGBToHWB( const RGBtype& rgb ) 
{
	// Code from: 
	//	Alvy Ray Smith and Eric Ray Lyons. HWB - A more intuitive hue-based color model. Journal of Graphics Tools, 1(1):3-17, 1996 
	//	http://www.acm.org/jgt/papers/SmithLyons96/

	// RGB are each on [0, 1]. W and B are returned on [0, 1] and H is  
	// returned on [0, 6]. Exception: H is returned UNDEFINED if W == 1 - B.  
	double R, G, B;
	SPLIT_RGB (rgb, R, G, B);
	double w, v, b, f;  
	int i;  
	HWBtype hwb;  

	w = minVal<>( minVal<>(R, G), B);  
	v = maxVal<>( maxVal<>(R, G), B);  
	b = 1 - v;

	if (v == w) 
	{
		// Achromatic case
		MAKE_HWB( hwb, ColorSpace::hue_undefined, w, b );
	} 
	else 
	{
		// Chromatic case
		f = (R == w) ? G - B : ((G == w) ? B - R : R - G);  
		i = (R == w) ? 3 : ((G == w) ? 5 : 1);  

		MAKE_HWB( hwb, i - f /(v - w), w, b );
	}

	return hwb;
}

ColorSpace::RGBtype ColorSpace::HWBToRGB( const HWBtype& hwb ) 
{
	// Code from: 
	//	Alvy Ray Smith and Eric Ray Lyons. HWB - A more intuitive hue-based color model. Journal of Graphics Tools, 1(1):3-17, 1996 
	//	http://www.acm.org/jgt/papers/SmithLyons96/

	// H is given on [0, 6] or UNDEFINED. W and B are given on [0, 1].  
	// RGB are each returned on [0, 1].  
	double h, w, b;
	SPLIT_HWB(hwb, h, w, b);
	double v, n, f;  
	int i;  
	RGBtype rgb;  

	v = 1 - b;  
	if ( h == ColorSpace::hue_undefined ) 
	{
		// Achromatic case
		MAKE_RGB(rgb, v, v, v);
	}
	else
	{
		// Chromatic case
		i = static_cast<int>(floor(h));
		f = h - i;  
		if (i & 1) {
		 f = 1 - f; // if i is odd  
		}
		n = w + f * (v - w); // linear interpolation between w and v  
		switch (i) {  
		case 6: 	// no break here ! 
		case 0: 
			MAKE_RGB(rgb, v, n, w);  
			break;
		case 1: 
			MAKE_RGB(rgb, n, v, w);
			break;
		case 2: 
			MAKE_RGB(rgb, w, v, n);  
			break;
		case 3: 
			MAKE_RGB(rgb, w, n, v);  
			break;
		case 4: 
			MAKE_RGB(rgb, n, w, v);  
			break;
		case 5: 
			MAKE_RGB(rgb, v, w, n);  
			break;
		}
	}

	return rgb;
}

//////////////////////////////////////////////////////////////////////
//

void ColorSpace::changeHue( HSLtype& hsl, const double& deltaH ) {
	double H2 = hsl.H + deltaH;
#ifdef NORMALIZED_HUE
	if ( H2 > ColorSpace::HueCriticalMax) {
		H2 -= 1;
	}
#else
	if ( H2 > 5 ) {
		H2 -= 1;
	}
#endif
	//	if ( H2 < 0) {
	//		H2 = 0;
	//	}
	hsl.H = H2;
}

double ColorSpace::getChanged( const double& initialVal, const double& percent )
{
	//if p===percentage: we add p to what is between the actual value 
	//										and we subtract what is between the actual value and 0

	double val = initialVal;
	double pct = percent;

	if ( pct > 1 ) {
		pct = 1;
	}

	if ( pct != 0 ) {
		if ( pct > 0 ) {
			//we add p to what is between the actual value 
			//	more: x + (1-x)*p === x*(1-p) + p
			val = val * ( 1-pct ) + pct;
		} else {
			// we subtract what is between the actual value and 0
			//	less: x - x*p  === x*(1-p)
			val *= ( 1+pct );
		}
	}

	return val;
}

void ColorSpace::changeHSV ( HSVtype& hsv, const double& percentH, const double& percentS, const double& percentV )
{
	// suggested with colors: 0.0/ 0.0 / 0.71428571428571
	// suggested with grays:  0.0/ 0.0 / 0.33333333333333
	hsv.H = getChanged( hsv.H, percentH );	// better color
	hsv.S = getChanged( hsv.S, percentS );	// better color
	hsv.V = getChanged( hsv.V, percentV );
}

void ColorSpace::changeHSL ( HSLtype& hsl, const double& percentH, const double& percentS, const double& percentL )
{
	// suggested with colors: 0.0/ 0.0 / -0.71428571428571
	// suggested with grays:  0.0/ 0.0 / -0.33333333333333
	hsl.H = getChanged( hsl.H, percentH );	// better color
	hsl.S = getChanged( hsl.S, percentS );	// better color
	hsl.L = getChanged( hsl.L, percentL );	// this counts too
}

void ColorSpace::changeHWB ( HWBtype& hwb, const double& percentH, const double& percentW, const double& percentB )
{
	// suggested with colors: 0.0/ 0.0 / 0.71428571428571
	// suggested with grays:  0.0/ 0.0 / 0.33333333333333
	hwb.H = getChanged( hwb.H, percentH );	//better color
	hwb.W = getChanged( hwb.W, percentW );
	hwb.B = getChanged( hwb.B, percentB );
}


ColorNames::ColorNames()
{
    ColorNames::nameMapContainer.initContainer(ColorNames::nameMap);
    
#ifdef VCF_LARGE_COLOR_LIST

    //shades of gray
    //color name r/g/b hex bg/fg color sample
    ColorNames::nameMap[   black                    ] = "black"                 ;   // 0xFF000000   //  0;0;0       
    ColorNames::nameMap[   grey                     ] = "grey"                  ;   // 0xFFBEBEBE   //  190;190;190 
    ColorNames::nameMap[   dimgray                  ] = "dimgray"               ;   // 0xFF696969   //  105;105;105 // frequently mispelled as dimgrey
    ColorNames::nameMap[   lightgray                ] = "lightgray"             ;   // 0xFFD3D3D3   //  211;211;211 
    ColorNames::nameMap[   lightslategrey           ] = "lightslategrey"        ;   // 0xFF778899   //  119;136;153 
    ColorNames::nameMap[   slategray                ] = "slategray"             ;   // 0xFF708090   //  112;128;144 
    ColorNames::nameMap[   slategray1               ] = "slategray1"            ;   // 0xFFC6E2FF   //  198;226;255 
    ColorNames::nameMap[   slategray2               ] = "slategray2"            ;   // 0xFFB9D3EE   //  185;211;238 
    ColorNames::nameMap[   slategray3               ] = "slategray3"            ;   // 0xFF9FB6CD   //  159;182;205 
    ColorNames::nameMap[   slategray4               ] = "slategray4"            ;   // 0xFF6C7B8B   //  108;123;139 
    ColorNames::nameMap[   slategrey                ] = "slategrey"             ;   // 0xFF708090   //  112;128;144 
    ColorNames::nameMap[   grey0                    ] = "grey0"                 ;   // 0xFF000000   //  0;0;0       
    ColorNames::nameMap[   grey1                    ] = "grey1"                 ;   // 0xFF030303   //  3;3;3       
    ColorNames::nameMap[   grey2                    ] = "grey2"                 ;   // 0xFF050505   //  5;5;5       
    ColorNames::nameMap[   grey3                    ] = "grey3"                 ;   // 0xFF080808   //  8;8;8       
    ColorNames::nameMap[   grey4                    ] = "grey4"                 ;   // 0xFF0A0A0A   //  10;10;10    
    ColorNames::nameMap[   grey5                    ] = "grey5"                 ;   // 0xFF0D0D0D   //  13;13;13    
    ColorNames::nameMap[   grey6                    ] = "grey6"                 ;   // 0xFF0F0F0F   //  15;15;15    
    ColorNames::nameMap[   grey7                    ] = "grey7"                 ;   // 0xFF121212   //  18;18;18    
    ColorNames::nameMap[   grey8                    ] = "grey8"                 ;   // 0xFF141414   //  20;20;20    
    ColorNames::nameMap[   grey98                   ] = "grey98"                ;   // 0xFF171717   //  23;23;23    
    ColorNames::nameMap[   grey10                   ] = "grey10"                ;   // 0xFF1A1A1A   //  26;26;26    
    ColorNames::nameMap[   grey11                   ] = "grey11"                ;   // 0xFF1C1C1C   //  28;28;28    
    ColorNames::nameMap[   grey12                   ] = "grey12"                ;   // 0xFF1F1F1F   //  31;31;31    
    ColorNames::nameMap[   grey13                   ] = "grey13"                ;   // 0xFF212121   //  33;33;33    
    ColorNames::nameMap[   grey14                   ] = "grey14"                ;   // 0xFF242424   //  36;36;36    
    ColorNames::nameMap[   grey15                   ] = "grey15"                ;   // 0xFF262626   //  38;38;38    
    ColorNames::nameMap[   grey16                   ] = "grey16"                ;   // 0xFF292929   //  41;41;41    
    ColorNames::nameMap[   grey17                   ] = "grey17"                ;   // 0xFF2B2B2B   //  43;43;43    
    ColorNames::nameMap[   grey18                   ] = "grey18"                ;   // 0xFF2E2E2E   //  46;46;46    
    ColorNames::nameMap[   grey19                   ] = "grey19"                ;   // 0xFF303030   //  48;48;48    
    ColorNames::nameMap[   grey20                   ] = "grey20"                ;   // 0xFF333333   //  51;51;51    
    ColorNames::nameMap[   grey21                   ] = "grey21"                ;   // 0xFF363636   //  54;54;54    
    ColorNames::nameMap[   grey22                   ] = "grey22"                ;   // 0xFF383838   //  56;56;56    
    ColorNames::nameMap[   grey23                   ] = "grey23"                ;   // 0xFF3B3B3B   //  59;59;59    
    ColorNames::nameMap[   grey24                   ] = "grey24"                ;   // 0xFF3D3D3D   //  61;61;61    
    ColorNames::nameMap[   grey25                   ] = "grey25"                ;   // 0xFF404040   //  64;64;64    
    ColorNames::nameMap[   grey26                   ] = "grey26"                ;   // 0xFF424242   //  66;66;66    
    ColorNames::nameMap[   grey27                   ] = "grey27"                ;   // 0xFF454545   //  69;69;69    
    ColorNames::nameMap[   grey28                   ] = "grey28"                ;   // 0xFF474747   //  71;71;71    
    ColorNames::nameMap[   grey29                   ] = "grey29"                ;   // 0xFF4A4A4A   //  74;74;74    
    ColorNames::nameMap[   grey30                   ] = "grey30"                ;   // 0xFF4D4D4D   //  77;77;77    
    ColorNames::nameMap[   grey31                   ] = "grey31"                ;   // 0xFF4F4F4F   //  79;79;79    
    ColorNames::nameMap[   grey32                   ] = "grey32"                ;   // 0xFF525252   //  82;82;82    
    ColorNames::nameMap[   grey33                   ] = "grey33"                ;   // 0xFF545454   //  84;84;84    
    ColorNames::nameMap[   grey34                   ] = "grey34"                ;   // 0xFF575757   //  87;87;87    
    ColorNames::nameMap[   grey35                   ] = "grey35"                ;   // 0xFF595959   //  89;89;89    
    ColorNames::nameMap[   grey36                   ] = "grey36"                ;   // 0xFF5C5C5C   //  92;92;92    
    ColorNames::nameMap[   grey37                   ] = "grey37"                ;   // 0xFF5E5E5E   //  94;94;94    
    ColorNames::nameMap[   grey38                   ] = "grey38"                ;   // 0xFF616161   //  97;97;97    
    ColorNames::nameMap[   grey39                   ] = "grey39"                ;   // 0xFF636363   //  99;99;99    
    ColorNames::nameMap[   grey40                   ] = "grey40"                ;   // 0xFF666666   //  102;102;102 
    ColorNames::nameMap[   grey41                   ] = "grey41"                ;   // 0xFF696969   //  105;105;105 
    ColorNames::nameMap[   grey42                   ] = "grey42"                ;   // 0xFF6B6B6B   //  107;107;107 
    ColorNames::nameMap[   grey43                   ] = "grey43"                ;   // 0xFF6E6E6E   //  110;110;110 
    ColorNames::nameMap[   grey44                   ] = "grey44"                ;   // 0xFF707070   //  112;112;112 
    ColorNames::nameMap[   grey45                   ] = "grey45"                ;   // 0xFF737373   //  115;115;115 
    ColorNames::nameMap[   grey46                   ] = "grey46"                ;   // 0xFF757575   //  117;117;117 
    ColorNames::nameMap[   grey47                   ] = "grey47"                ;   // 0xFF787878   //  120;120;120 
    ColorNames::nameMap[   grey48                   ] = "grey48"                ;   // 0xFF7A7A7A   //  122;122;122 
    ColorNames::nameMap[   grey49                   ] = "grey49"                ;   // 0xFF7D7D7D   //  125;125;125 
    ColorNames::nameMap[   grey50                   ] = "grey50"                ;   // 0xFF7F7F7F   //  127;127;127 
    ColorNames::nameMap[   grey51                   ] = "grey51"                ;   // 0xFF828282   //  130;130;130 
    ColorNames::nameMap[   grey52                   ] = "grey52"                ;   // 0xFF858585   //  133;133;133 
    ColorNames::nameMap[   grey53                   ] = "grey53"                ;   // 0xFF878787   //  135;135;135 
    ColorNames::nameMap[   grey54                   ] = "grey54"                ;   // 0xFF8A8A8A   //  138;138;138 
    ColorNames::nameMap[   grey55                   ] = "grey55"                ;   // 0xFF8C8C8C   //  140;140;140 
    ColorNames::nameMap[   grey56                   ] = "grey56"                ;   // 0xFF8F8F8F   //  143;143;143 
    ColorNames::nameMap[   grey57                   ] = "grey57"                ;   // 0xFF919191   //  145;145;145 
    ColorNames::nameMap[   grey58                   ] = "grey58"                ;   // 0xFF949494   //  148;148;148 
    ColorNames::nameMap[   grey59                   ] = "grey59"                ;   // 0xFF969696   //  150;150;150 
    ColorNames::nameMap[   grey60                   ] = "grey60"                ;   // 0xFF999999   //  153;153;153 
    ColorNames::nameMap[   grey61                   ] = "grey61"                ;   // 0xFF9C9C9C   //  156;156;156 
    ColorNames::nameMap[   grey62                   ] = "grey62"                ;   // 0xFF9E9E9E   //  158;158;158 
    ColorNames::nameMap[   grey63                   ] = "grey63"                ;   // 0xFFA1A1A1   //  161;161;161 
    ColorNames::nameMap[   grey64                   ] = "grey64"                ;   // 0xFFA3A3A3   //  163;163;163 
    ColorNames::nameMap[   grey65                   ] = "grey65"                ;   // 0xFFA6A6A6   //  166;166;166 
    ColorNames::nameMap[   grey66                   ] = "grey66"                ;   // 0xFFA8A8A8   //  168;168;168 
    ColorNames::nameMap[   grey67                   ] = "grey67"                ;   // 0xFFABABAB   //  171;171;171 
    ColorNames::nameMap[   grey68                   ] = "grey68"                ;   // 0xFFADADAD   //  173;173;173 
    ColorNames::nameMap[   grey69                   ] = "grey69"                ;   // 0xFFB0B0B0   //  176;176;176 
    ColorNames::nameMap[   grey70                   ] = "grey70"                ;   // 0xFFB3B3B3   //  179;179;179 
    ColorNames::nameMap[   grey71                   ] = "grey71"                ;   // 0xFFB5B5B5   //  181;181;181 
    ColorNames::nameMap[   grey72                   ] = "grey72"                ;   // 0xFFB8B8B8   //  184;184;184 
    ColorNames::nameMap[   grey73                   ] = "grey73"                ;   // 0xFFBABABA   //  186;186;186 
    ColorNames::nameMap[   grey74                   ] = "grey74"                ;   // 0xFFBDBDBD   //  189;189;189 
    ColorNames::nameMap[   grey75                   ] = "grey75"                ;   // 0xFFBFBFBF   //  191;191;191 
    ColorNames::nameMap[   grey76                   ] = "grey76"                ;   // 0xFFC2C2C2   //  194;194;194 
    ColorNames::nameMap[   grey77                   ] = "grey77"                ;   // 0xFFC4C4C4   //  196;196;196 
    ColorNames::nameMap[   grey78                   ] = "grey78"                ;   // 0xFFC7C7C7   //  199;199;199 
    ColorNames::nameMap[   grey79                   ] = "grey79"                ;   // 0xFFC9C9C9   //  201;201;201 
    ColorNames::nameMap[   grey80                   ] = "grey80"                ;   // 0xFFCCCCCC   //  204;204;204 
    ColorNames::nameMap[   grey81                   ] = "grey81"                ;   // 0xFFCFCFCF   //  207;207;207 
    ColorNames::nameMap[   grey82                   ] = "grey82"                ;   // 0xFFD1D1D1   //  209;209;209 
    ColorNames::nameMap[   grey83                   ] = "grey83"                ;   // 0xFFD4D4D4   //  212;212;212 
    ColorNames::nameMap[   grey84                   ] = "grey84"                ;   // 0xFFD6D6D6   //  214;214;214 
    ColorNames::nameMap[   grey85                   ] = "grey85"                ;   // 0xFFD9D9D9   //  217;217;217 
    ColorNames::nameMap[   grey86                   ] = "grey86"                ;   // 0xFFDBDBDB   //  219;219;219 
    ColorNames::nameMap[   grey87                   ] = "grey87"                ;   // 0xFFDEDEDE   //  222;222;222 
    ColorNames::nameMap[   grey88                   ] = "grey88"                ;   // 0xFFE0E0E0   //  224;224;224 
    ColorNames::nameMap[   grey89                   ] = "grey89"                ;   // 0xFFE3E3E3   //  227;227;227 
    ColorNames::nameMap[   grey90                   ] = "grey90"                ;   // 0xFFE5E5E5   //  229;229;229 
    ColorNames::nameMap[   grey91                   ] = "grey91"                ;   // 0xFFE8E8E8   //  232;232;232 
    ColorNames::nameMap[   grey92                   ] = "grey92"                ;   // 0xFFEBEBEB   //  235;235;235 
    ColorNames::nameMap[   grey93                   ] = "grey93"                ;   // 0xFFEDEDED   //  237;237;237 
    ColorNames::nameMap[   grey94                   ] = "grey94"                ;   // 0xFFF0F0F0   //  240;240;240 
    ColorNames::nameMap[   grey95                   ] = "grey95"                ;   // 0xFFF2F2F2   //  242;242;242 
    ColorNames::nameMap[   grey96                   ] = "grey96"                ;   // 0xFFF5F5F5   //  245;245;245 
    ColorNames::nameMap[   grey97                   ] = "grey97"                ;   // 0xFFF7F7F7   //  247;247;247 
    ColorNames::nameMap[   grey98                   ] = "grey98"                ;   // 0xFFFAFAFA   //  250;250;250 
    ColorNames::nameMap[   grey99                   ] = "grey99"                ;   // 0xFFFCFCFC   //  252;252;252 
    ColorNames::nameMap[   grey100                  ] = "grey100"               ;   // 0xFFFFFFFF   //  255;255;255 
                                                                                             
    //shades of blue                                                                         
    //color name r/g/b hex bg/fg color sample
    ColorNames::nameMap[   aliceblue                ] = "aliceblue"             ;   // 0xFFF0F8FF   //  240;248;255 
    ColorNames::nameMap[   blueviolet               ] = "blueviolet"            ;   // 0xFF8A2BE2   //  138;43;226  
    ColorNames::nameMap[   cadetblue                ] = "cadetblue"             ;   // 0xFF5F9EA0   //  95;158;160  
    ColorNames::nameMap[   cadetblue1               ] = "cadetblue1"            ;   // 0xFF98F5FF   //  152;245;255 
    ColorNames::nameMap[   cadetblue2               ] = "cadetblue2"            ;   // 0xFF8EE5EE   //  142;229;238 
    ColorNames::nameMap[   cadetblue3               ] = "cadetblue3"            ;   // 0xFF7AC5CD   //  122;197;205 
    ColorNames::nameMap[   cadetblue4               ] = "cadetblue4"            ;   // 0xFF53868B   //  83;134;139  
    ColorNames::nameMap[   cornflowerblue           ] = "cornflowerblue"        ;   // 0xFF6495ED   //  100;149;237 
    ColorNames::nameMap[   darkslateblue            ] = "darkslateblue"         ;   // 0xFF483D8B   //  72;61;139   
    ColorNames::nameMap[   darkturquoise            ] = "darkturquoise"         ;   // 0xFF00CED1   //  0;206;209   
    ColorNames::nameMap[   deepskyblue              ] = "deepskyblue"           ;   // 0xFF00BFFF   //  0;191;255   
    ColorNames::nameMap[   deepskyblue1             ] = "deepskyblue1"          ;   // 0xFF00BFFF   //  0;191;255   
    ColorNames::nameMap[   deepskyblue2             ] = "deepskyblue2"          ;   // 0xFF00B2EE   //  0;178;238   
    ColorNames::nameMap[   deepskyblue3             ] = "deepskyblue3"          ;   // 0xFF009ACD   //  0;154;205   
    ColorNames::nameMap[   deepskyblue4             ] = "deepskyblue4"          ;   // 0xFF00688B   //  0;104;139   
    ColorNames::nameMap[   dodgerblue               ] = "dodgerblue"            ;   // 0xFF1E90FF   //  30;144;255  
    ColorNames::nameMap[   dodgerblue1              ] = "dodgerblue1"           ;   // 0xFF1E90FF   //  30;144;255  
    ColorNames::nameMap[   dodgerblue2              ] = "dodgerblue2"           ;   // 0xFF1C86EE   //  28;134;238  
    ColorNames::nameMap[   dodgerblue3              ] = "dodgerblue3"           ;   // 0xFF1874CD   //  24;116;205  
    ColorNames::nameMap[   dodgerblue4              ] = "dodgerblue4"           ;   // 0xFF104E8B   //  16;78;139   
    ColorNames::nameMap[   lightblue                ] = "lightblue"             ;   // 0xFFADD8E6   //  173;216;230 
    ColorNames::nameMap[   lightblue1               ] = "lightblue1"            ;   // 0xFFBFEFFF   //  191;239;255 
    ColorNames::nameMap[   lightblue2               ] = "lightblue2"            ;   // 0xFFB2DFEE   //  178;223;238 
    ColorNames::nameMap[   lightblue3               ] = "lightblue3"            ;   // 0xFF9AC0CD   //  154;192;205 
    ColorNames::nameMap[   lightblue4               ] = "lightblue4"            ;   // 0xFF68838B   //  104;131;139 
    ColorNames::nameMap[   lightcyan                ] = "lightcyan"             ;   // 0xFFE0FFFF   //  224;255;255 
    ColorNames::nameMap[   lightcyan1               ] = "lightcyan1"            ;   // 0xFFE0FFFF   //  224;255;255 
    ColorNames::nameMap[   lightcyan2               ] = "lightcyan2"            ;   // 0xFFD1EEEE   //  209;238;238 
    ColorNames::nameMap[   lightcyan3               ] = "lightcyan3"            ;   // 0xFFB4CDCD   //  180;205;205 
    ColorNames::nameMap[   lightcyan4               ] = "lightcyan4"            ;   // 0xFF7A8B8B   //  122;139;139 
    ColorNames::nameMap[   lightskyblue             ] = "lightskyblue"          ;   // 0xFF87CEFA   //  135;206;250 
    ColorNames::nameMap[   lightskyblue1            ] = "lightskyblue1"         ;   // 0xFFB0E2FF   //  176;226;255 
    ColorNames::nameMap[   lightskyblue2            ] = "lightskyblue2"         ;   // 0xFFA4D3EE   //  164;211;238 
    ColorNames::nameMap[   lightskyblue3            ] = "lightskyblue3"         ;   // 0xFF8DB6CD   //  141;182;205 
    ColorNames::nameMap[   lightskyblue4            ] = "lightskyblue4"         ;   // 0xFF607B8B   //  96;123;139  
    ColorNames::nameMap[   lightslateblue           ] = "lightslateblue"        ;   // 0xFF8470FF   //  132;112;255 
    ColorNames::nameMap[   lightsteelblue           ] = "lightsteelblue"        ;   // 0xFFB0C4DE   //  176;196;222 
    ColorNames::nameMap[   lightsteelblue1          ] = "lightsteelblue1"       ;   // 0xFFCAE1FF   //  202;225;255 
    ColorNames::nameMap[   lightsteelblue2          ] = "lightsteelblue2"       ;   // 0xFFBCD2EE   //  188;210;238 
    ColorNames::nameMap[   lightsteelblue3          ] = "lightsteelblue3"       ;   // 0xFFA2B5CD   //  162;181;205 
    ColorNames::nameMap[   lightsteelblue4          ] = "lightsteelblue4"       ;   // 0xFF6E7B8B   //  110;123;139 
    ColorNames::nameMap[   mediumaquamarine         ] = "mediumaquamarine"      ;   // 0xFF66CDAA   //  102;205;170 
    ColorNames::nameMap[   mediumblue               ] = "mediumblue"            ;   // 0xFF0000CD   //  0;0;205     
    ColorNames::nameMap[   mediumslateblue          ] = "mediumslateblue"       ;   // 0xFF7B68EE   //  123;104;238 
    ColorNames::nameMap[   mediumturquoise          ] = "mediumturquoise"       ;   // 0xFF48D1CC   //  72;209;204  
    ColorNames::nameMap[   midnightblue             ] = "midnightblue"          ;   // 0xFF191970   //  25;25;112   
    ColorNames::nameMap[   navyblue                 ] = "navyblue"              ;   // 0xFF000080   //  0;0;128     
    ColorNames::nameMap[   paleturquoise            ] = "paleturquoise"         ;   // 0xFFAFEEEE   //  175;238;238 
    ColorNames::nameMap[   paleturquoise1           ] = "paleturquoise1"        ;   // 0xFFBBFFFF   //  187;255;255 
    ColorNames::nameMap[   paleturquoise2           ] = "paleturquoise2"        ;   // 0xFFAEEEEE   //  174;238;238 
    ColorNames::nameMap[   paleturquoise3           ] = "paleturquoise3"        ;   // 0xFF96CDCD   //  150;205;205 
    ColorNames::nameMap[   paleturquoise4           ] = "paleturquoise4"        ;   // 0xFF668B8B   //  102;139;139 
    ColorNames::nameMap[   powderblue               ] = "powderblue"            ;   // 0xFFB0E0E6   //  176;224;230 
    ColorNames::nameMap[   royalblue                ] = "royalblue"             ;   // 0xFF4169E1   //  65;105;225  
    ColorNames::nameMap[   royalblue1               ] = "royalblue1"            ;   // 0xFF4876FF   //  72;118;255  
    ColorNames::nameMap[   royalblue2               ] = "royalblue2"            ;   // 0xFF436EEE   //  67;110;238  
    ColorNames::nameMap[   royalblue3               ] = "royalblue3"            ;   // 0xFF3A5FCD   //  58;95;205   
    ColorNames::nameMap[   royalblue4               ] = "royalblue4"            ;   // 0xFF27408B   //  39;64;139   
    ColorNames::nameMap[   royalblue5               ] = "royalblue5"            ;   // 0xFF002266   //  00;34;102   
    ColorNames::nameMap[   skyblue                  ] = "skyblue"               ;   // 0xFF87CEEB   //  135;206;235 
    ColorNames::nameMap[   skyblue1                 ] = "skyblue1"              ;   // 0xFF87CEFF   //  135;206;255 
    ColorNames::nameMap[   skyblue2                 ] = "skyblue2"              ;   // 0xFF7EC0EE   //  126;192;238 
    ColorNames::nameMap[   skyblue3                 ] = "skyblue3"              ;   // 0xFF6CA6CD   //  108;166;205 
    ColorNames::nameMap[   skyblue4                 ] = "skyblue4"              ;   // 0xFF4A708B   //  74;112;139  
    ColorNames::nameMap[   slateblue                ] = "slateblue"             ;   // 0xFF6A5ACD   //  106;90;205  
    ColorNames::nameMap[   slateblue1               ] = "slateblue1"            ;   // 0xFF836FFF   //  131;111;255 
    ColorNames::nameMap[   slateblue2               ] = "slateblue2"            ;   // 0xFF7A67EE   //  122;103;238 
    ColorNames::nameMap[   slateblue3               ] = "slateblue3"            ;   // 0xFF6959CD   //  105;89;205  
    ColorNames::nameMap[   slateblue4               ] = "slateblue4"            ;   // 0xFF473C8B   //  71;60;139   
    ColorNames::nameMap[   steelblue                ] = "steelblue"             ;   // 0xFF4682B4   //  70;130;180  
    ColorNames::nameMap[   steelblue1               ] = "steelblue1"            ;   // 0xFF63B8FF   //  99;184;255  
    ColorNames::nameMap[   steelblue2               ] = "steelblue2"            ;   // 0xFF5CACEE   //  92;172;238  
    ColorNames::nameMap[   steelblue3               ] = "steelblue3"            ;   // 0xFF4F94CD   //  79;148;205  
    ColorNames::nameMap[   steelblue4               ] = "steelblue4"            ;   // 0xFF36648B   //  54;100;139  
    ColorNames::nameMap[   aquamarine               ] = "aquamarine"            ;   // 0xFF7FFFD4   //  127;255;212 
    ColorNames::nameMap[   aquamarine1              ] = "aquamarine1"           ;   // 0xFF7FFFD4   //  127;255;212 
    ColorNames::nameMap[   aquamarine2              ] = "aquamarine2"           ;   // 0xFF76EEC6   //  118;238;198 
    ColorNames::nameMap[   aquamarine3              ] = "aquamarine3"           ;   // 0xFF66CDAA   //  102;205;170 
    ColorNames::nameMap[   aquamarine4              ] = "aquamarine4"           ;   // 0xFF458B74   //  69;139;116  
    ColorNames::nameMap[   azure                    ] = "azure"                 ;   // 0xFFF0FFFF   //  240;255;255 
    ColorNames::nameMap[   azure1                   ] = "azure1"                ;   // 0xFFF0FFFF   //  240;255;255 
    ColorNames::nameMap[   azure2                   ] = "azure2"                ;   // 0xFFE0EEEE   //  224;238;238 
    ColorNames::nameMap[   azure3                   ] = "azure3"                ;   // 0xFFC1CDCD   //  193;205;205 
    ColorNames::nameMap[   azure4                   ] = "azure4"                ;   // 0xFF838B8B   //  131;139;139 
    ColorNames::nameMap[   blue                     ] = "blue"                  ;   // 0xFF0000FF   //  0;0;255     
    ColorNames::nameMap[   blue1                    ] = "blue1"                 ;   // 0xFF0000FF   //  0;0;255     
    ColorNames::nameMap[   blue2                    ] = "blue2"                 ;   // 0xFF0000EE   //  0;0;238     
    ColorNames::nameMap[   blue3                    ] = "blue3"                 ;   // 0xFF0000CD   //  0;0;205     
    ColorNames::nameMap[   blue4                    ] = "blue4"                 ;   // 0xFF00008B   //  0;0;139     
    ColorNames::nameMap[   cyan                     ] = "cyan"                  ;   // 0xFF00FFFF   //  0;255;255   
    ColorNames::nameMap[   cyan1                    ] = "cyan1"                 ;   // 0xFF00FFFF   //  0;255;255   
    ColorNames::nameMap[   cyan2                    ] = "cyan2"                 ;   // 0xFF00EEEE   //  0;238;238   
    ColorNames::nameMap[   cyan3                    ] = "cyan3"                 ;   // 0xFF00CDCD   //  0;205;205   
    ColorNames::nameMap[   cyan4                    ] = "cyan4"                 ;   // 0xFF008B8B   //  0;139;139   
    ColorNames::nameMap[   navy                     ] = "navy"                  ;   // 0xFF000080   //  0;0;128     
    ColorNames::nameMap[   turquoise                ] = "turquoise"             ;   // 0xFF40E0D0   //  64;224;208  
    ColorNames::nameMap[   turquoise1               ] = "turquoise1"            ;   // 0xFF00F5FF   //  0;245;255   
    ColorNames::nameMap[   turquoise2               ] = "turquoise2"            ;   // 0xFF00E5EE   //  0;229;238   
    ColorNames::nameMap[   turquoise3               ] = "turquoise3"            ;   // 0xFF00C5CD   //  0;197;205   
    ColorNames::nameMap[   turquoise4               ] = "turquoise4"            ;   // 0xFF00868B   //  0;134;139   
    ColorNames::nameMap[   darkslategray            ] = "darkslategray"         ;   // 0xFF2F4F4F   //  47;79;79    
    ColorNames::nameMap[   darkslategray1           ] = "darkslategray1"        ;   // 0xFF97FFFF   //  151;255;255 
    ColorNames::nameMap[   darkslategray2           ] = "darkslategray2"        ;   // 0xFF8DEEEE   //  141;238;238 
    ColorNames::nameMap[   darkslategray3           ] = "darkslategray3"        ;   // 0xFF79CDCD   //  121;205;205 
    ColorNames::nameMap[   darkslategray4           ] = "darkslategray4"        ;   // 0xFF528B8B   //  82;139;139  
                                                                                         
    //shades of brown                                                                    
    //color name r/g/b hex bg/fg color sample
    ColorNames::nameMap[   rosybrown                ] = "rosybrown"             ;   // 0xFFBC8F8F   //  188;143;143 
    ColorNames::nameMap[   rosybrown1               ] = "rosybrown1"            ;   // 0xFFFFC1C1   //  255;193;193 
    ColorNames::nameMap[   rosybrown2               ] = "rosybrown2"            ;   // 0xFFEEB4B4   //  238;180;180 
    ColorNames::nameMap[   rosybrown3               ] = "rosybrown3"            ;   // 0xFFCD9B9B   //  205;155;155 
    ColorNames::nameMap[   rosybrown4               ] = "rosybrown4"            ;   // 0xFF8B6969   //  139;105;105 
    ColorNames::nameMap[   saddlebrown              ] = "saddlebrown"           ;   // 0xFF8B4513   //  139;69;19   
    ColorNames::nameMap[   sandybrown               ] = "sandybrown"            ;   // 0xFFF4A460   //  244;164;96  
    ColorNames::nameMap[   beige                    ] = "beige"                 ;   // 0xFFF5F5DC   //  245;245;220 
    ColorNames::nameMap[   brown                    ] = "brown"                 ;   // 0xFFA52A2A   //  165;42;42   
    ColorNames::nameMap[   brown1                   ] = "brown1"                ;   // 0xFFFF4040   //  255;64;64   
    ColorNames::nameMap[   brown2                   ] = "brown2"                ;   // 0xFFEE3B3B   //  238;59;59   
    ColorNames::nameMap[   brown3                   ] = "brown3"                ;   // 0xFFCD3333   //  205;51;51   
    ColorNames::nameMap[   brown4                   ] = "brown4"                ;   // 0xFF8B2323   //  139;35;35   
    ColorNames::nameMap[   burlywood                ] = "burlywood"             ;   // 0xFFDEB887   //  222;184;135 
    ColorNames::nameMap[   burlywood1               ] = "burlywood1"            ;   // 0xFFFFD39B   //  255;211;155 
    ColorNames::nameMap[   burlywood2               ] = "burlywood2"            ;   // 0xFFEEC591   //  238;197;145 
    ColorNames::nameMap[   burlywood3               ] = "burlywood3"            ;   // 0xFFCDAA7D   //  205;170;125 
    ColorNames::nameMap[   burlywood4               ] = "burlywood4"            ;   // 0xFF8B7355   //  139;115;85  
    ColorNames::nameMap[   chocolate                ] = "chocolate"             ;   // 0xFFD2691E   //  210;105;30  
    ColorNames::nameMap[   chocolate1               ] = "chocolate1"            ;   // 0xFFFF7F24   //  255;127;36  
    ColorNames::nameMap[   chocolate2               ] = "chocolate2"            ;   // 0xFFEE7621   //  238;118;33  
    ColorNames::nameMap[   chocolate3               ] = "chocolate3"            ;   // 0xFFCD661D   //  205;102;29  
    ColorNames::nameMap[   chocolate4               ] = "chocolate4"            ;   // 0xFF8B4513   //  139;69;19   
    ColorNames::nameMap[   peru                     ] = "peru"                  ;   // 0xFFCD853F   //  205;133;63  
    ColorNames::nameMap[   tan                      ] = "tan"                   ;   // 0xFFD2B48C   //  210;180;140 
    ColorNames::nameMap[   tan1                     ] = "tan1"                  ;   // 0xFFFFA54F   //  255;165;79  
    ColorNames::nameMap[   tan2                     ] = "tan2"                  ;   // 0xFFEE9A49   //  238;154;73  
    ColorNames::nameMap[   tan3                     ] = "tan3"                  ;   // 0xFFCD853F   //  205;133;63  
    ColorNames::nameMap[   tan4                     ] = "tan4"                  ;   // 0xFF8B5A2B   //  139;90;43   
                                                                                             
    //shades of green                                                                        
    //color name r/g/b hex bg/fg color sample
    ColorNames::nameMap[   darkgreen                ] = "darkgreen"             ;   // 0xFF006400   //  0;100;0     
    ColorNames::nameMap[   darkkhaki                ] = "darkkhaki"             ;   // 0xFFBDB76B   //  189;183;107 
    ColorNames::nameMap[   darkolivegreen           ] = "darkolivegreen"        ;   // 0xFF556B2F   //  85;107;47   
    ColorNames::nameMap[   darkolivegreen1          ] = "darkolivegreen1"       ;   // 0xFFCAFF70   //  202;255;112 
    ColorNames::nameMap[   darkolivegreen2          ] = "darkolivegreen2"       ;   // 0xFFBCEE68   //  188;238;104 
    ColorNames::nameMap[   darkolivegreen3          ] = "darkolivegreen3"       ;   // 0xFFA2CD5A   //  162;205;90  
    ColorNames::nameMap[   darkolivegreen4          ] = "darkolivegreen4"       ;   // 0xFF6E8B3D   //  110;139;61  
    ColorNames::nameMap[   darkseagreen             ] = "darkseagreen"          ;   // 0xFF8FBC8F   //  143;188;143 
    ColorNames::nameMap[   darkseagreen1            ] = "darkseagreen1"         ;   // 0xFFC1FFC1   //  193;255;193 
    ColorNames::nameMap[   darkseagreen2            ] = "darkseagreen2"         ;   // 0xFFB4EEB4   //  180;238;180 
    ColorNames::nameMap[   darkseagreen3            ] = "darkseagreen3"         ;   // 0xFF9BCD9B   //  155;205;155 
    ColorNames::nameMap[   darkseagreen4            ] = "darkseagreen4"         ;   // 0xFF698B69   //  105;139;105 
    ColorNames::nameMap[   forestgreen              ] = "forestgreen"           ;   // 0xFF228B22   //  34;139;34   
    ColorNames::nameMap[   greenyellow              ] = "greenyellow"           ;   // 0xFFADFF2F   //  173;255;47  
    ColorNames::nameMap[   lawngreen                ] = "lawngreen"             ;   // 0xFF7CFC00   //  124;252;0   
    ColorNames::nameMap[   lightseagreen            ] = "lightseagreen"         ;   // 0xFF20B2AA   //  32;178;170  
    ColorNames::nameMap[   limegreen                ] = "limegreen"             ;   // 0xFF32CD32   //  50;205;50   
    ColorNames::nameMap[   mediumseagreen           ] = "mediumseagreen"        ;   // 0xFF3CB371   //  60;179;113  
    ColorNames::nameMap[   mediumspringgreen        ] = "mediumspringgreen"     ;   // 0xFF00FA9A   //  0;250;154   
    ColorNames::nameMap[   mintcream                ] = "mintcream"             ;   // 0xFFF5FFFA   //  245;255;250 
    ColorNames::nameMap[   olivedrab                ] = "olivedrab"             ;   // 0xFF6B8E23   //  107;142;35  
    ColorNames::nameMap[   olivedrab1               ] = "olivedrab1"            ;   // 0xFFC0FF3E   //  192;255;62  
    ColorNames::nameMap[   olivedrab2               ] = "olivedrab2"            ;   // 0xFFB3EE3A   //  179;238;58  
    ColorNames::nameMap[   olivedrab3               ] = "olivedrab3"            ;   // 0xFF9ACD32   //  154;205;50  
    ColorNames::nameMap[   olivedrab4               ] = "olivedrab4"            ;   // 0xFF698B22   //  105;139;34  
    ColorNames::nameMap[   palegreen                ] = "palegreen"             ;   // 0xFF98FB98   //  152;251;152 
    ColorNames::nameMap[   palegreen1               ] = "palegreen1"            ;   // 0xFF9AFF9A   //  154;255;154 
    ColorNames::nameMap[   palegreen2               ] = "palegreen2"            ;   // 0xFF90EE90   //  144;238;144 
    ColorNames::nameMap[   palegreen3               ] = "palegreen3"            ;   // 0xFF7CCD7C   //  124;205;124 
    ColorNames::nameMap[   palegreen4               ] = "palegreen4"            ;   // 0xFF548B54   //  84;139;84   
    ColorNames::nameMap[   seagreen                 ] = "seagreen"              ;   // 0xFF2E8B57   //  46;139;87   
    ColorNames::nameMap[   seagreen1                ] = "seagreen1"             ;   // 0xFF54FF9F   //  84;255;159  
    ColorNames::nameMap[   seagreen2                ] = "seagreen2"             ;   // 0xFF4EEE94   //  78;238;148  
    ColorNames::nameMap[   seagreen3                ] = "seagreen3"             ;   // 0xFF43CD80   //  67;205;128  
    ColorNames::nameMap[   seagreen4                ] = "seagreen4"             ;   // 0xFF2E8B57   //  46;139;87   
    ColorNames::nameMap[   springgreen              ] = "springgreen"           ;   // 0xFF00FF7F   //  0;255;127   
    ColorNames::nameMap[   springgreen1             ] = "springgreen1"          ;   // 0xFF00FF7F   //  0;255;127   
    ColorNames::nameMap[   springgreen2             ] = "springgreen2"          ;   // 0xFF00EE76   //  0;238;118   
    ColorNames::nameMap[   springgreen3             ] = "springgreen3"          ;   // 0xFF00CD66   //  0;205;102   
    ColorNames::nameMap[   springgreen4             ] = "springgreen4"          ;   // 0xFF008B45   //  0;139;69    
    ColorNames::nameMap[   yellowgreen              ] = "yellowgreen"           ;   // 0xFF9ACD32   //  154;205;50  
    ColorNames::nameMap[   chartreuse               ] = "chartreuse"            ;   // 0xFF7FFF00   //  127;255;0   
    ColorNames::nameMap[   chartreuse1              ] = "chartreuse1"           ;   // 0xFF7FFF00   //  127;255;0   
    ColorNames::nameMap[   chartreuse2              ] = "chartreuse2"           ;   // 0xFF76EE00   //  118;238;0   
    ColorNames::nameMap[   chartreuse3              ] = "chartreuse3"           ;   // 0xFF66CD00   //  102;205;0   
    ColorNames::nameMap[   chartreuse4              ] = "chartreuse4"           ;   // 0xFF458B00   //  69;139;0    
    ColorNames::nameMap[   green                    ] = "green"                 ;   // 0xFF00FF00   //  0;255;0     
    ColorNames::nameMap[   green1                   ] = "green1"                ;   // 0xFF00FF00   //  0;255;0     
    ColorNames::nameMap[   green2                   ] = "green2"                ;   // 0xFF00EE00   //  0;238;0     
    ColorNames::nameMap[   green3                   ] = "green3"                ;   // 0xFF00CD00   //  0;205;0     
    ColorNames::nameMap[   green4                   ] = "green4"                ;   // 0xFF008B00   //  0;139;0     
    ColorNames::nameMap[   khaki                    ] = "khaki"                 ;   // 0xFFF0E68C   //  240;230;140 
    ColorNames::nameMap[   khaki1                   ] = "khaki1"                ;   // 0xFFFFF68F   //  255;246;143 
    ColorNames::nameMap[   khaki2                   ] = "khaki2"                ;   // 0xFFEEE685   //  238;230;133 
    ColorNames::nameMap[   khaki3                   ] = "khaki3"                ;   // 0xFFCDC673   //  205;198;115 
    ColorNames::nameMap[   khaki4                   ] = "khaki4"                ;   // 0xFF8B864E   //  139;134;78  
                                                                                         
    //shades of orange                                                                   
    //color name r/g/b hex bg/fg color sample
    ColorNames::nameMap[   darkorange               ] = "darkorange"            ;   // 0xFFFF8C00   //  255;140;0   
    ColorNames::nameMap[   darkorange1              ] = "darkorange1"           ;   // 0xFFFF7F00   //  255;127;0   
    ColorNames::nameMap[   darkorange2              ] = "darkorange2"           ;   // 0xFFEE7600   //  238;118;0   
    ColorNames::nameMap[   darkorange3              ] = "darkorange3"           ;   // 0xFFCD6600   //  205;102;0   
    ColorNames::nameMap[   darkorange4              ] = "darkorange4"           ;   // 0xFF8B4500   //  139;69;0    
    ColorNames::nameMap[   darksalmon               ] = "darksalmon"            ;   // 0xFFE9967A   //  233;150;122 
    ColorNames::nameMap[   lightcoral               ] = "lightcoral"            ;   // 0xFFF08080   //  240;128;128 
    ColorNames::nameMap[   lightsalmon              ] = "lightsalmon"           ;   // 0xFFFFA07A   //  255;160;122 
    ColorNames::nameMap[   lightsalmon1             ] = "lightsalmon1"          ;   // 0xFFFFA07A   //  255;160;122 
    ColorNames::nameMap[   lightsalmon2             ] = "lightsalmon2"          ;   // 0xFFEE9572   //  238;149;114 
    ColorNames::nameMap[   lightsalmon3             ] = "lightsalmon3"          ;   // 0xFFCD8162   //  205;129;98  
    ColorNames::nameMap[   lightsalmon4             ] = "lightsalmon4"          ;   // 0xFF8B5742   //  139;87;66   
    ColorNames::nameMap[   peachpuff                ] = "peachpuff"             ;   // 0xFFFFDAB9   //  255;218;185 
    ColorNames::nameMap[   peachpuff1               ] = "peachpuff1"            ;   // 0xFFFFDAB9   //  255;218;185 
    ColorNames::nameMap[   peachpuff2               ] = "peachpuff2"            ;   // 0xFFEECBAD   //  238;203;173 
    ColorNames::nameMap[   peachpuff3               ] = "peachpuff3"            ;   // 0xFFCDAF95   //  205;175;149 
    ColorNames::nameMap[   peachpuff4               ] = "peachpuff4"            ;   // 0xFF8B7765   //  139;119;101 
    ColorNames::nameMap[   bisque                   ] = "bisque"                ;   // 0xFFFFE4C4   //  255;228;196 
    ColorNames::nameMap[   bisque1                  ] = "bisque1"               ;   // 0xFFFFE4C4   //  255;228;196 
    ColorNames::nameMap[   bisque2                  ] = "bisque2"               ;   // 0xFFEED5B7   //  238;213;183 
    ColorNames::nameMap[   bisque3                  ] = "bisque3"               ;   // 0xFFCDB79E   //  205;183;158 
    ColorNames::nameMap[   bisque4                  ] = "bisque4"               ;   // 0xFF8B7D6B   //  139;125;107 
    ColorNames::nameMap[   coral                    ] = "coral"                 ;   // 0xFFFF7F50   //  255;127;80  
    ColorNames::nameMap[   coral1                   ] = "coral1"                ;   // 0xFFFF7256   //  255;114;86  
    ColorNames::nameMap[   coral2                   ] = "coral2"                ;   // 0xFFEE6A50   //  238;106;80  
    ColorNames::nameMap[   coral3                   ] = "coral3"                ;   // 0xFFCD5B45   //  205;91;69   
    ColorNames::nameMap[   coral4                   ] = "coral4"                ;   // 0xFF8B3E2F   //  139;62;47   
    ColorNames::nameMap[   honeydew                 ] = "honeydew"              ;   // 0xFFF0FFF0   //  240;255;240 
    ColorNames::nameMap[   honeydew1                ] = "honeydew1"             ;   // 0xFFF0FFF0   //  240;255;240 
    ColorNames::nameMap[   honeydew2                ] = "honeydew2"             ;   // 0xFFE0EEE0   //  224;238;224 
    ColorNames::nameMap[   honeydew3                ] = "honeydew3"             ;   // 0xFFC1CDC1   //  193;205;193 
    ColorNames::nameMap[   honeydew4                ] = "honeydew4"             ;   // 0xFF838B83   //  131;139;131 
    ColorNames::nameMap[   orange                   ] = "orange"                ;   // 0xFFFFA500   //  255;165;0   
    ColorNames::nameMap[   orange1                  ] = "orange1"               ;   // 0xFFFFA500   //  255;165;0   
    ColorNames::nameMap[   orange2                  ] = "orange2"               ;   // 0xFFEE9A00   //  238;154;0   
    ColorNames::nameMap[   orange3                  ] = "orange3"               ;   // 0xFFCD8500   //  205;133;0   
    ColorNames::nameMap[   orange4                  ] = "orange4"               ;   // 0xFF8B5A00   //  139;90;0    
    ColorNames::nameMap[   salmon                   ] = "salmon"                ;   // 0xFFFA8072   //  250;128;114 
    ColorNames::nameMap[   salmon1                  ] = "salmon1"               ;   // 0xFFFF8C69   //  255;140;105 
    ColorNames::nameMap[   salmon2                  ] = "salmon2"               ;   // 0xFFEE8262   //  238;130;98  
    ColorNames::nameMap[   salmon3                  ] = "salmon3"               ;   // 0xFFCD7054   //  205;112;84  
    ColorNames::nameMap[   salmon4                  ] = "salmon4"               ;   // 0xFF8B4C39   //  139;76;57   
    ColorNames::nameMap[   sienna                   ] = "sienna"                ;   // 0xFFA0522D   //  160;82;45   
    ColorNames::nameMap[   sienna1                  ] = "sienna1"               ;   // 0xFFFF8247   //  255;130;71  
    ColorNames::nameMap[   sienna2                  ] = "sienna2"               ;   // 0xFFEE7942   //  238;121;66  
    ColorNames::nameMap[   sienna3                  ] = "sienna3"               ;   // 0xFFCD6839   //  205;104;57  
    ColorNames::nameMap[   sienna4                  ] = "sienna4"               ;   // 0xFF8B4726   //  139;71;38   
                                                                                             
    //shades of red                                                                          
    //color name r/g/b hex bg/fg color sample
    ColorNames::nameMap[   deeppink                 ] = "deeppink"              ;   // 0xFFFF1493   //  255;20;147  
    ColorNames::nameMap[   deeppink1                ] = "deeppink1"             ;   // 0xFFFF1493   //  255;20;147  
    ColorNames::nameMap[   deeppink2                ] = "deeppink2"             ;   // 0xFFEE1289   //  238;18;137  
    ColorNames::nameMap[   deeppink3                ] = "deeppink3"             ;   // 0xFFCD1076   //  205;16;118  
    ColorNames::nameMap[   deeppink4                ] = "deeppink4"             ;   // 0xFF8B0A50   //  139;10;80   
    ColorNames::nameMap[   hotpink                  ] = "hotpink"               ;   // 0xFFFF69B4   //  255;105;180 
    ColorNames::nameMap[   hotpink1                 ] = "hotpink1"              ;   // 0xFFFF6EB4   //  255;110;180 
    ColorNames::nameMap[   hotpink2                 ] = "hotpink2"              ;   // 0xFFEE6AA7   //  238;106;167 
    ColorNames::nameMap[   hotpink3                 ] = "hotpink3"              ;   // 0xFFCD6090   //  205;96;144  
    ColorNames::nameMap[   hotpink4                 ] = "hotpink4"              ;   // 0xFF8B3A62   //  139;58;98   
    ColorNames::nameMap[   indianred                ] = "indianred"             ;   // 0xFFCD5C5C   //  205;92;92   
    ColorNames::nameMap[   indianred1               ] = "indianred1"            ;   // 0xFFFF6A6A   //  255;106;106 
    ColorNames::nameMap[   indianred2               ] = "indianred2"            ;   // 0xFFEE6363   //  238;99;99   
    ColorNames::nameMap[   indianred3               ] = "indianred3"            ;   // 0xFFCD5555   //  205;85;85   
    ColorNames::nameMap[   indianred4               ] = "indianred4"            ;   // 0xFF8B3A3A   //  139;58;58   
    ColorNames::nameMap[   lightpink                ] = "lightpink"             ;   // 0xFFFFB6C1   //  255;182;193 
    ColorNames::nameMap[   lightpink1               ] = "lightpink1"            ;   // 0xFFFFAEB9   //  255;174;185 
    ColorNames::nameMap[   lightpink2               ] = "lightpink2"            ;   // 0xFFEEA2AD   //  238;162;173 
    ColorNames::nameMap[   lightpink3               ] = "lightpink3"            ;   // 0xFFCD8C95   //  205;140;149 
    ColorNames::nameMap[   lightpink4               ] = "lightpink4"            ;   // 0xFF8B5F65   //  139;95;101  
    ColorNames::nameMap[   mediumvioletred          ] = "mediumvioletred"       ;   // 0xFFC71585   //  199;21;133  
    ColorNames::nameMap[   mistyrose                ] = "mistyrose"             ;   // 0xFFFFE4E1   //  255;228;225 
    ColorNames::nameMap[   mistyrose1               ] = "mistyrose1"            ;   // 0xFFFFE4E1   //  255;228;225 
    ColorNames::nameMap[   mistyrose2               ] = "mistyrose2"            ;   // 0xFFEED5D2   //  238;213;210 
    ColorNames::nameMap[   mistyrose3               ] = "mistyrose3"            ;   // 0xFFCDB7B5   //  205;183;181 
    ColorNames::nameMap[   mistyrose4               ] = "mistyrose4"            ;   // 0xFF8B7D7B   //  139;125;123 
    ColorNames::nameMap[   orangered                ] = "orangered"             ;   // 0xFFFF4500   //  255;69;0    
    ColorNames::nameMap[   orangered1               ] = "orangered1"            ;   // 0xFFFF4500   //  255;69;0    
    ColorNames::nameMap[   orangered2               ] = "orangered2"            ;   // 0xFFEE4000   //  238;64;0    
    ColorNames::nameMap[   orangered3               ] = "orangered3"            ;   // 0xFFCD3700   //  205;55;0    
    ColorNames::nameMap[   orangered4               ] = "orangered4"            ;   // 0xFF8B2500   //  139;37;0    
    ColorNames::nameMap[   palevioletred            ] = "palevioletred"         ;   // 0xFFDB7093   //  219;112;147 
    ColorNames::nameMap[   palevioletred1           ] = "palevioletred1"        ;   // 0xFFFF82AB   //  255;130;171 
    ColorNames::nameMap[   palevioletred2           ] = "palevioletred2"        ;   // 0xFFEE799F   //  238;121;159 
    ColorNames::nameMap[   palevioletred3           ] = "palevioletred3"        ;   // 0xFFCD6889   //  205;104;137 
    ColorNames::nameMap[   palevioletred4           ] = "palevioletred4"        ;   // 0xFF8B475D   //  139;71;93   
    ColorNames::nameMap[   violetred                ] = "violetred"             ;   // 0xFFD02090   //  208;32;144  
    ColorNames::nameMap[   violetred1               ] = "violetred1"            ;   // 0xFFFF3E96   //  255;62;150  
    ColorNames::nameMap[   violetred2               ] = "violetred2"            ;   // 0xFFEE3A8C   //  238;58;140  
    ColorNames::nameMap[   violetred3               ] = "violetred3"            ;   // 0xFFCD3278   //  205;50;120  
    ColorNames::nameMap[   violetred4               ] = "violetred4"            ;   // 0xFF8B2252   //  139;34;82   
    ColorNames::nameMap[   firebrick                ] = "firebrick"             ;   // 0xFFB22222   //  178;34;34   
    ColorNames::nameMap[   firebrick1               ] = "firebrick1"            ;   // 0xFFFF3030   //  255;48;48   
    ColorNames::nameMap[   firebrick2               ] = "firebrick2"            ;   // 0xFFEE2C2C   //  238;44;44   
    ColorNames::nameMap[   firebrick3               ] = "firebrick3"            ;   // 0xFFCD2626   //  205;38;38   
    ColorNames::nameMap[   firebrick4               ] = "firebrick4"            ;   // 0xFF8B1A1A   //  139;26;26   
    ColorNames::nameMap[   pink                     ] = "pink"                  ;   // 0xFFFFC0CB   //  255;192;203 
    ColorNames::nameMap[   pink1                    ] = "pink1"                 ;   // 0xFFFFB5C5   //  255;181;197 
    ColorNames::nameMap[   pink2                    ] = "pink2"                 ;   // 0xFFEEA9B8   //  238;169;184 
    ColorNames::nameMap[   pink3                    ] = "pink3"                 ;   // 0xFFCD919E   //  205;145;158 
    ColorNames::nameMap[   pink4                    ] = "pink4"                 ;   // 0xFF8B636C   //  139;99;108  
    ColorNames::nameMap[   red                      ] = "red"                   ;   // 0xFFFF0000   //  255;0;0     
    ColorNames::nameMap[   red1                     ] = "red1"                  ;   // 0xFFFF0000   //  255;0;0     
    ColorNames::nameMap[   red2                     ] = "red2"                  ;   // 0xFFEE0000   //  238;0;0     
    ColorNames::nameMap[   red3                     ] = "red3"                  ;   // 0xFFCD0000   //  205;0;0     
    ColorNames::nameMap[   red4                     ] = "red4"                  ;   // 0xFF8B0000   //  139;0;0     
    ColorNames::nameMap[   tomato                   ] = "tomato"                ;   // 0xFFFF6347   //  255;99;71   
    ColorNames::nameMap[   tomato1                  ] = "tomato1"               ;   // 0xFFFF6347   //  255;99;71   
    ColorNames::nameMap[   tomato2                  ] = "tomato2"               ;   // 0xFFEE5C42   //  238;92;66   
    ColorNames::nameMap[   tomato3                  ] = "tomato3"               ;   // 0xFFCD4F39   //  205;79;57   
    ColorNames::nameMap[   tomato4                  ] = "tomato4"               ;   // 0xFF8B3626   //  139;54;38   
                                                                                         
    //shades of violet                                                                   
    //color name r/g/b hex bg/fg color sample
    ColorNames::nameMap[   darkorchid               ] = "darkorchid"            ;   // 0xFF9932CC   //  153;50;204  
    ColorNames::nameMap[   darkorchid1              ] = "darkorchid1"           ;   // 0xFFBF3EFF   //  191;62;255  
    ColorNames::nameMap[   darkorchid2              ] = "darkorchid2"           ;   // 0xFFB23AEE   //  178;58;238  
    ColorNames::nameMap[   darkorchid3              ] = "darkorchid3"           ;   // 0xFF9A32CD   //  154;50;205  
    ColorNames::nameMap[   darkorchid4              ] = "darkorchid4"           ;   // 0xFF68228B   //  104;34;139  
    ColorNames::nameMap[   darkviolet               ] = "darkviolet"            ;   // 0xFF9400D3   //  148;0;211   
    ColorNames::nameMap[   lavenderblush            ] = "lavenderblush"         ;   // 0xFFFFF0F5   //  255;240;245 
    ColorNames::nameMap[   lavenderblush1           ] = "lavenderblush1"        ;   // 0xFFFFF0F5   //  255;240;245 
    ColorNames::nameMap[   lavenderblush2           ] = "lavenderblush2"        ;   // 0xFFEEE0E5   //  238;224;229 
    ColorNames::nameMap[   lavenderblush3           ] = "lavenderblush3"        ;   // 0xFFCDC1C5   //  205;193;197 
    ColorNames::nameMap[   lavenderblush4           ] = "lavenderblush4"        ;   // 0xFF8B8386   //  139;131;134 
    ColorNames::nameMap[   mediumorchid             ] = "mediumorchid"          ;   // 0xFFBA55D3   //  186;85;211  
    ColorNames::nameMap[   mediumorchid1            ] = "mediumorchid1"         ;   // 0xFFE066FF   //  224;102;255 
    ColorNames::nameMap[   mediumorchid2            ] = "mediumorchid2"         ;   // 0xFFD15FEE   //  209;95;238  
    ColorNames::nameMap[   mediumorchid3            ] = "mediumorchid3"         ;   // 0xFFB452CD   //  180;82;205  
    ColorNames::nameMap[   mediumorchid4            ] = "mediumorchid4"         ;   // 0xFF7A378B   //  122;55;139  
    ColorNames::nameMap[   mediumpurple             ] = "mediumpurple"          ;   // 0xFF9370DB   //  147;112;219 
    ColorNames::nameMap[   mediumpurple1            ] = "mediumpurple1"         ;   // 0xFFAB82FF   //  171;130;255 
    ColorNames::nameMap[   mediumpurple2            ] = "mediumpurple2"         ;   // 0xFF9F79EE   //  159;121;238 
    ColorNames::nameMap[   mediumpurple3            ] = "mediumpurple3"         ;   // 0xFF8968CD   //  137;104;205 
    ColorNames::nameMap[   mediumpurple4            ] = "mediumpurple4"         ;   // 0xFF5D478B   //  93;71;139   
    ColorNames::nameMap[   lavender                 ] = "lavender"              ;   // 0xFFE6E6FA   //  230;230;250 
    ColorNames::nameMap[   magenta                  ] = "magenta"               ;   // 0xFFFF00FF   //  255;0;255   
    ColorNames::nameMap[   magenta1                 ] = "magenta1"              ;   // 0xFFFF00FF   //  255;0;255   
    ColorNames::nameMap[   magenta2                 ] = "magenta2"              ;   // 0xFFEE00EE   //  238;0;238   
    ColorNames::nameMap[   magenta3                 ] = "magenta3"              ;   // 0xFFCD00CD   //  205;0;205   
    ColorNames::nameMap[   magenta4                 ] = "magenta4"              ;   // 0xFF8B008B   //  139;0;139   
    ColorNames::nameMap[   maroon                   ] = "maroon"                ;   // 0xFFB03060   //  176;48;96   
    ColorNames::nameMap[   maroon1                  ] = "maroon1"               ;   // 0xFFFF34B3   //  255;52;179  
    ColorNames::nameMap[   maroon2                  ] = "maroon2"               ;   // 0xFFEE30A7   //  238;48;167  
    ColorNames::nameMap[   maroon3                  ] = "maroon3"               ;   // 0xFFCD2990   //  205;41;144  
    ColorNames::nameMap[   maroon4                  ] = "maroon4"               ;   // 0xFF8B1C62   //  139;28;98   
    ColorNames::nameMap[   orchid                   ] = "orchid"                ;   // 0xFFDA70D6   //  218;112;214 
    ColorNames::nameMap[   orchid1                  ] = "orchid1"               ;   // 0xFFFF83FA   //  255;131;250 
    ColorNames::nameMap[   orchid2                  ] = "orchid2"               ;   // 0xFFEE7AE9   //  238;122;233 
    ColorNames::nameMap[   orchid3                  ] = "orchid3"               ;   // 0xFFCD69C9   //  205;105;201 
    ColorNames::nameMap[   orchid4                  ] = "orchid4"               ;   // 0xFF8B4789   //  139;71;137  
    ColorNames::nameMap[   plum                     ] = "plum"                  ;   // 0xFFDDA0DD   //  221;160;221 
    ColorNames::nameMap[   plum1                    ] = "plum1"                 ;   // 0xFFFFBBFF   //  255;187;255 
    ColorNames::nameMap[   plum2                    ] = "plum2"                 ;   // 0xFFEEAEEE   //  238;174;238 
    ColorNames::nameMap[   plum3                    ] = "plum3"                 ;   // 0xFFCD96CD   //  205;150;205 
    ColorNames::nameMap[   plum4                    ] = "plum4"                 ;   // 0xFF8B668B   //  139;102;139 
    ColorNames::nameMap[   purple                   ] = "purple"                ;   // 0xFFA020F0   //  160;32;240  
    ColorNames::nameMap[   purple1                  ] = "purple1"               ;   // 0xFF9B30FF   //  155;48;255  
    ColorNames::nameMap[   purple2                  ] = "purple2"               ;   // 0xFF912CEE   //  145;44;238  
    ColorNames::nameMap[   purple3                  ] = "purple3"               ;   // 0xFF7D26CD   //  125;38;205  
    ColorNames::nameMap[   purple4                  ] = "purple4"               ;   // 0xFF551A8B   //  85;26;139   
    ColorNames::nameMap[   thistle                  ] = "thistle"               ;   // 0xFFD8BFD8   //  216;191;216 
    ColorNames::nameMap[   thistle1                 ] = "thistle1"              ;   // 0xFFFFE1FF   //  255;225;255 
    ColorNames::nameMap[   thistle2                 ] = "thistle2"              ;   // 0xFFEED2EE   //  238;210;238 
    ColorNames::nameMap[   thistle3                 ] = "thistle3"              ;   // 0xFFCDB5CD   //  205;181;205 
    ColorNames::nameMap[   thistle4                 ] = "thistle4"              ;   // 0xFF8B7B8B   //  139;123;139 
    ColorNames::nameMap[   violet                   ] = "violet"                ;   // 0xFFEE82EE   //  238;130;238 
                                                                                             
    //shades of white                                                                        
    //color name r/g/b hex bg/fg color sample
    ColorNames::nameMap[   antiquewhite             ] = "antiquewhite"          ;   // 0xFFFAEBD7   //  250;235;215 
    ColorNames::nameMap[   antiquewhite1            ] = "antiquewhite1"         ;   // 0xFFFFEFDB   //  255;239;219 
    ColorNames::nameMap[   antiquewhite2            ] = "antiquewhite2"         ;   // 0xFFEEDFCC   //  238;223;204 
    ColorNames::nameMap[   antiquewhite3            ] = "antiquewhite3"         ;   // 0xFFCDC0B0   //  205;192;176 
    ColorNames::nameMap[   antiquewhite4            ] = "antiquewhite4"         ;   // 0xFF8B8378   //  139;131;120 
    ColorNames::nameMap[   floralwhite              ] = "floralwhite"           ;   // 0xFFFFFAF0   //  255;250;240 
    ColorNames::nameMap[   ghostwhite               ] = "ghostwhite"            ;   // 0xFFF8F8FF   //  248;248;255 
    ColorNames::nameMap[   navajowhite              ] = "navajowhite"           ;   // 0xFFFFDEAD   //  255;222;173 
    ColorNames::nameMap[   navajowhite1             ] = "navajowhite1"          ;   // 0xFFFFDEAD   //  255;222;173 
    ColorNames::nameMap[   navajowhite2             ] = "navajowhite2"          ;   // 0xFFEECFA1   //  238;207;161 
    ColorNames::nameMap[   navajowhite3             ] = "navajowhite3"          ;   // 0xFFCDB38B   //  205;179;139 
    ColorNames::nameMap[   navajowhite4             ] = "navajowhite4"          ;   // 0xFF8B795E   //  139;121;94  
    ColorNames::nameMap[   oldlace                  ] = "oldlace"               ;   // 0xFFFDF5E6   //  253;245;230 
    ColorNames::nameMap[   whitesmoke               ] = "whitesmoke"            ;   // 0xFFF5F5F5   //  245;245;245 
    ColorNames::nameMap[   gainsboro                ] = "gainsboro"             ;   // 0xFFDCDCDC   //  220;220;220 
    ColorNames::nameMap[   ivory                    ] = "ivory"                 ;   // 0xFFFFFFF0   //  255;255;240 
    ColorNames::nameMap[   ivory1                   ] = "ivory1"                ;   // 0xFFFFFFF0   //  255;255;240 
    ColorNames::nameMap[   ivory2                   ] = "ivory2"                ;   // 0xFFEEEEE0   //  238;238;224 
    ColorNames::nameMap[   ivory3                   ] = "ivory3"                ;   // 0xFFCDCDC1   //  205;205;193 
    ColorNames::nameMap[   ivory4                   ] = "ivory4"                ;   // 0xFF8B8B83   //  139;139;131 
    ColorNames::nameMap[   linen                    ] = "linen"                 ;   // 0xFFFAF0E6   //  250;240;230 
    ColorNames::nameMap[   seashell                 ] = "seashell"              ;   // 0xFFFFF5EE   //  255;245;238 
    ColorNames::nameMap[   seashell1                ] = "seashell1"             ;   // 0xFFFFF5EE   //  255;245;238 
    ColorNames::nameMap[   seashell2                ] = "seashell2"             ;   // 0xFFEEE5DE   //  238;229;222 
    ColorNames::nameMap[   seashell3                ] = "seashell3"             ;   // 0xFFCDC5BF   //  205;197;191 
    ColorNames::nameMap[   seashell4                ] = "seashell4"             ;   // 0xFF8B8682   //  139;134;130 
    ColorNames::nameMap[   snow                     ] = "snow"                  ;   // 0xFFFFFAFA   //  255;250;250 
    ColorNames::nameMap[   snow1                    ] = "snow1"                 ;   // 0xFFFFFAFA   //  255;250;250 
    ColorNames::nameMap[   snow2                    ] = "snow2"                 ;   // 0xFFEEE9E9   //  238;233;233 
    ColorNames::nameMap[   snow3                    ] = "snow3"                 ;   // 0xFFCDC9C9   //  205;201;201 
    ColorNames::nameMap[   snow4                    ] = "snow4"                 ;   // 0xFF8B8989   //  139;137;137 
    ColorNames::nameMap[   wheat                    ] = "wheat"                 ;   // 0xFFF5DEB3   //  245;222;179 
    ColorNames::nameMap[   wheat1                   ] = "wheat1"                ;   // 0xFFFFE7BA   //  255;231;186 
    ColorNames::nameMap[   wheat2                   ] = "wheat2"                ;   // 0xFFEED8AE   //  238;216;174 
    ColorNames::nameMap[   wheat3                   ] = "wheat3"                ;   // 0xFFCDBA96   //  205;186;150 
    ColorNames::nameMap[   wheat4                   ] = "wheat4"                ;   // 0xFF8B7E66   //  139;126;102 
    ColorNames::nameMap[   white                    ] = "white"                 ;   // 0xFFFFFFFF   //  255;255;255 
                                                                                             
    //shades of yellow                                                                       
    //color name r/g/b hex bg/fg color sample
    ColorNames::nameMap[   blanchedalmond           ] = "blanchedalmond"        ;   // 0xFFFFEBCD   //  255;235;205 
    ColorNames::nameMap[   darkgoldenrod            ] = "darkgoldenrod"         ;   // 0xFFB8860B   //  184;134;11  
    ColorNames::nameMap[   darkgoldenrod1           ] = "darkgoldenrod1"        ;   // 0xFFFFB90F   //  255;185;15  
    ColorNames::nameMap[   darkgoldenrod2           ] = "darkgoldenrod2"        ;   // 0xFFEEAD0E   //  238;173;14  
    ColorNames::nameMap[   darkgoldenrod3           ] = "darkgoldenrod3"        ;   // 0xFFCD950C   //  205;149;12  
    ColorNames::nameMap[   darkgoldenrod4           ] = "darkgoldenrod4"        ;   // 0xFF8B6508   //  139;101;8   
    ColorNames::nameMap[   lemonchiffon             ] = "lemonchiffon"          ;   // 0xFFFFFACD   //  255;250;205 
    ColorNames::nameMap[   lemonchiffon1            ] = "lemonchiffon1"         ;   // 0xFFFFFACD   //  255;250;205 
    ColorNames::nameMap[   lemonchiffon2            ] = "lemonchiffon2"         ;   // 0xFFEEE9BF   //  238;233;191 
    ColorNames::nameMap[   lemonchiffon3            ] = "lemonchiffon3"         ;   // 0xFFCDC9A5   //  205;201;165 
    ColorNames::nameMap[   lemonchiffon4            ] = "lemonchiffon4"         ;   // 0xFF8B8970   //  139;137;112 
    ColorNames::nameMap[   lightgoldenrod           ] = "lightgoldenrod"        ;   // 0xFFEEDD82   //  238;221;130 
    ColorNames::nameMap[   lightgoldenrod1          ] = "lightgoldenrod1"       ;   // 0xFFFFEC8B   //  255;236;139 
    ColorNames::nameMap[   lightgoldenrod2          ] = "lightgoldenrod2"       ;   // 0xFFEEDC82   //  238;220;130 
    ColorNames::nameMap[   lightgoldenrod3          ] = "lightgoldenrod3"       ;   // 0xFFCDBE70   //  205;190;112 
    ColorNames::nameMap[   lightgoldenrod4          ] = "lightgoldenrod4"       ;   // 0xFF8B814C   //  139;129;76  
    ColorNames::nameMap[   lightgoldenrodyellow     ] = "lightgoldenrodyellow"  ;   // 0xFFFAFAD2   //  250;250;210 
    ColorNames::nameMap[   lightyellow              ] = "lightyellow"           ;   // 0xFFFFFFE0   //  255;255;224 
    ColorNames::nameMap[   lightyellow1             ] = "lightyellow1"          ;   // 0xFFFFFFE0   //  255;255;224 
    ColorNames::nameMap[   lightyellow2             ] = "lightyellow2"          ;   // 0xFFEEEED1   //  238;238;209 
    ColorNames::nameMap[   lightyellow3             ] = "lightyellow3"          ;   // 0xFFCDCDB4   //  205;205;180 
    ColorNames::nameMap[   lightyellow4             ] = "lightyellow4"          ;   // 0xFF8B8B7A   //  139;139;122 
    ColorNames::nameMap[   palegoldenrod            ] = "palegoldenrod"         ;   // 0xFFEEE8AA   //  238;232;170 
    ColorNames::nameMap[   papayawhip               ] = "papayawhip"            ;   // 0xFFFFEFD5   //  255;239;213 
    ColorNames::nameMap[   cornsilk                 ] = "cornsilk"              ;   // 0xFFFFF8DC   //  255;248;220 
    ColorNames::nameMap[   cornsilk1                ] = "cornsilk1"             ;   // 0xFFFFF8DC   //  255;248;220 
    ColorNames::nameMap[   cornsilk2                ] = "cornsilk2"             ;   // 0xFFEEE8CD   //  238;232;205 
    ColorNames::nameMap[   cornsilk3                ] = "cornsilk3"             ;   // 0xFFCDC8B1   //  205;200;177 
    ColorNames::nameMap[   cornsilk4                ] = "cornsilk4"             ;   // 0xFF8B8878   //  139;136;120 
    ColorNames::nameMap[   gold                     ] = "gold"                  ;   // 0xFFFFD700   //  255;215;0   
    ColorNames::nameMap[   gold1                    ] = "gold1"                 ;   // 0xFFFFD700   //  255;215;0   
    ColorNames::nameMap[   gold2                    ] = "gold2"                 ;   // 0xFFEEC900   //  238;201;0   
    ColorNames::nameMap[   gold3                    ] = "gold3"                 ;   // 0xFFCDAD00   //  205;173;0   
    ColorNames::nameMap[   gold4                    ] = "gold4"                 ;   // 0xFF8B7500   //  139;117;0   
    ColorNames::nameMap[   goldenrod                ] = "goldenrod"             ;   // 0xFFDAA520   //  218;165;32  
    ColorNames::nameMap[   goldenrod1               ] = "goldenrod1"            ;   // 0xFFFFC125   //  255;193;37  
    ColorNames::nameMap[   goldenrod2               ] = "goldenrod2"            ;   // 0xFFEEB422   //  238;180;34  
    ColorNames::nameMap[   goldenrod3               ] = "goldenrod3"            ;   // 0xFFCD9B1D   //  205;155;29  
    ColorNames::nameMap[   goldenrod4               ] = "goldenrod4"            ;   // 0xFF8B6914   //  139;105;20  
    ColorNames::nameMap[   moccasin                 ] = "moccasin"              ;   // 0xFFFFE4B5   //  255;228;181 
    ColorNames::nameMap[   yellow                   ] = "yellow"                ;   // 0xFFFFFF00   //  255;255;0   
    ColorNames::nameMap[   yellow1                  ] = "yellow1"               ;   // 0xFFFFFF00   //  255;255;0   
    ColorNames::nameMap[   yellow2                  ] = "yellow2"               ;   // 0xFFEEEE00   //  238;238;0   
    ColorNames::nameMap[   yellow3                  ] = "yellow3"               ;   // 0xFFCDCD00   //  205;205;0   
    ColorNames::nameMap[   yellow4                  ] = "yellow4"               ;   // 0xFF8B8B00   //  139;139;0   
                                                                                         
    //metal rgb according to netscape                    o netscape
    //color name r/g/b hex bg/fg color sample
    ColorNames::nameMap[   copper                   ] = "copper"                ;   // 0xFFB87333   //  184;115;51  
    ColorNames::nameMap[   gold                     ] = "gold"                  ;   // 0xFFCD7F32   //  205;127;50  
    ColorNames::nameMap[   silver                   ] = "silver"                ;   // 0xFFE6E8FA   //  230;232;250 

#else

    ColorNames::nameMap[   aliceblue                ] = "aliceblue";                 // 0x00F0F8FF
    ColorNames::nameMap[   antiquewhite             ] = "antiquewhite";              // 0x00FAEBD7
    ColorNames::nameMap[   aqua                     ] = "aqua";                      // 0x0000FFFF
    ColorNames::nameMap[   aquamarine               ] = "aquamarine";                // 0x007FFFD4
    ColorNames::nameMap[   azure                    ] = "azure";                     // 0x00F0FFFF
    ColorNames::nameMap[   beige                    ] = "beige";                     // 0x00F5F5DC
    ColorNames::nameMap[   bisque                   ] = "bisque";                    // 0x00FFE4C4
    ColorNames::nameMap[   black                    ] = "black";                     // 0x00000000
    ColorNames::nameMap[   blanchedalmond           ] = "blanchedalmond";            // 0x00FFEBCD
    ColorNames::nameMap[   blue                     ] = "blue";                      // 0x000000FF
    ColorNames::nameMap[   blueviolet               ] = "blueviolet";                // 0x008A2BE2
    ColorNames::nameMap[   brown                    ] = "brown";                     // 0x00A52A2A
    ColorNames::nameMap[   burlywood                ] = "burlywood";                 // 0x00DEB887
    ColorNames::nameMap[   cadetblue                ] = "cadetblue";                 // 0x005F9EA0
    ColorNames::nameMap[   chartreuse               ] = "chartreuse";                // 0x007FFF00
    ColorNames::nameMap[   chocolate                ] = "chocolate";                 // 0x00D2691E
    ColorNames::nameMap[   coral                    ] = "coral";                     // 0x00FF7F50
    ColorNames::nameMap[   cornflowerblue           ] = "cornflowerblue";            // 0x006495ED
    ColorNames::nameMap[   cornsilk                 ] = "cornsilk";                  // 0x00FFF8DC
    ColorNames::nameMap[   crimson                  ] = "crimson";                   // 0x00DC143C
    ColorNames::nameMap[   cyan                     ] = "cyan";                      // 0x0000FFFF
    ColorNames::nameMap[   darkblue                 ] = "darkblue";                  // 0x0000008B
    ColorNames::nameMap[   darkcyan                 ] = "darkcyan";                  // 0x00008B8B
    ColorNames::nameMap[   darkgoldenrod            ] = "darkgoldenrod";             // 0x00B8860B
    ColorNames::nameMap[   darkgray                 ] = "darkgray";                  // 0x00A9A9A9
    ColorNames::nameMap[   darkgreen                ] = "darkgreen";                 // 0x00006400
    ColorNames::nameMap[   darkkhaki                ] = "darkkhaki";                 // 0x00BDB76B
    ColorNames::nameMap[   darkmagenta              ] = "darkmagenta";               // 0x008B008B
    ColorNames::nameMap[   darkolivegreen           ] = "darkolivegreen";            // 0x00556B2F
    ColorNames::nameMap[   darkorange               ] = "darkorange";                // 0x00FF8C00
    ColorNames::nameMap[   darkorchid               ] = "darkorchid";                // 0x009932CC
    ColorNames::nameMap[   darkred                  ] = "darkred";                   // 0x008B0000
    ColorNames::nameMap[   darksalmon               ] = "darksalmon";                // 0x00E9967A
    ColorNames::nameMap[   darkseagreen             ] = "darkseagreen";              // 0x008FBC8B
    ColorNames::nameMap[   darkslateblue            ] = "darkslateblue";             // 0x00483D8B
    ColorNames::nameMap[   darkslategray            ] = "darkslategray";             // 0x002F4F4F
    ColorNames::nameMap[   darkturquoise            ] = "darkturquoise";             // 0x0000CED1
    ColorNames::nameMap[   darkviolet               ] = "darkviolet";                // 0x009400D3
    ColorNames::nameMap[   deeppink                 ] = "deeppink";                  // 0x00FF1493
    ColorNames::nameMap[   deepskyblue              ] = "deepskyblue";               // 0x0000BFFF
    ColorNames::nameMap[   dimgray                  ] = "dimgray";                   // 0x00696969
    ColorNames::nameMap[   dodgerblue               ] = "dodgerblue";                // 0x001E90FF
    ColorNames::nameMap[   firebrick                ] = "firebrick";                 // 0x00B22222
    ColorNames::nameMap[   floralwhite              ] = "floralwhite";               // 0x00FFFAF0
    ColorNames::nameMap[   forestgreen              ] = "forestgreen";               // 0x00228B22
    ColorNames::nameMap[   fuchsia                  ] = "fuchsia";                   // 0x00FF00FF
    ColorNames::nameMap[   gainsboro                ] = "gainsboro";                 // 0x00DCDCDC
    ColorNames::nameMap[   ghostwhite               ] = "ghostwhite";                // 0x00F8F8FF
    ColorNames::nameMap[   gold                     ] = "gold";                      // 0x00FFD700
    ColorNames::nameMap[   goldenrod                ] = "goldenrod";                 // 0x00DAA520
    ColorNames::nameMap[   gray                     ] = "gray";                      // 0x00808080
    ColorNames::nameMap[   green                    ] = "green";                     // 0x00008000
    ColorNames::nameMap[   greenyellow              ] = "greenyellow";               // 0x00ADFF2F
    ColorNames::nameMap[   honeydew                 ] = "honeydew";                  // 0x00F0FFF0
    ColorNames::nameMap[   hotpink                  ] = "hotpink";                   // 0x00FF69B4
    ColorNames::nameMap[   indianred                ] = "indianred";                 // 0x00CD5C5C
    ColorNames::nameMap[   indigo                   ] = "indigo";                    // 0x004B0082
    ColorNames::nameMap[   ivory                    ] = "ivory";                     // 0x00FFFFF0
    ColorNames::nameMap[   khaki                    ] = "khaki";                     // 0x00F0E68C
    ColorNames::nameMap[   lavender                 ] = "lavender";                  // 0x00E6E6FA
    ColorNames::nameMap[   lavenderblush            ] = "lavenderblush";             // 0x00FFF0F5
    ColorNames::nameMap[   lawngreen                ] = "lawngreen";                 // 0x007CFC00
    ColorNames::nameMap[   lemonchiffon             ] = "lemonchiffon";              // 0x00FFFACD
    ColorNames::nameMap[   lightblue                ] = "lightblue";                 // 0x00ADD8E6
    ColorNames::nameMap[   lightcoral               ] = "lightcoral";                // 0x00F08080
    ColorNames::nameMap[   lightcyan                ] = "lightcyan";                 // 0x00E0FFFF
    ColorNames::nameMap[   lightgoldenrodyellow     ] = "lightgoldenrodyellow";      // 0x00FAFAD2
    ColorNames::nameMap[   lightgray                ] = "lightgray";                 // 0x00D3D3D3
    ColorNames::nameMap[   lightgreen               ] = "lightgreen";                // 0x0090EE90
    ColorNames::nameMap[   lightpink                ] = "lightpink";                 // 0x00FFB6C1
    ColorNames::nameMap[   lightsalmon              ] = "lightsalmon";               // 0x00FFA07A
    ColorNames::nameMap[   lightseagreen            ] = "lightseagreen";             // 0x0020B2AA
    ColorNames::nameMap[   lightskyblue             ] = "lightskyblue";              // 0x0087CEFA
    ColorNames::nameMap[   lightslategray           ] = "lightslategray";            // 0x00778899
    ColorNames::nameMap[   lightsteelblue           ] = "lightsteelblue";            // 0x00B0C4DE
    ColorNames::nameMap[   lightyellow              ] = "lightyellow";               // 0x00FFFFE0
    ColorNames::nameMap[   lime                     ] = "lime";                      // 0x0000FF00
    ColorNames::nameMap[   limegreen                ] = "limegreen";                 // 0x0032CD32
    ColorNames::nameMap[   linen                    ] = "linen";                     // 0x00FAF0E6
    ColorNames::nameMap[   magenta                  ] = "magenta";                   // 0x00FF00FF
    ColorNames::nameMap[   maroon                   ] = "maroon";                    // 0x00800000
    ColorNames::nameMap[   mediumaquamarine         ] = "mediumaquamarine";          // 0x0066CDAA
    ColorNames::nameMap[   mediumblue               ] = "mediumblue";                // 0x000000CD
    ColorNames::nameMap[   mediumorchid             ] = "mediumorchid";              // 0x00BA55D3
    ColorNames::nameMap[   mediumpurple             ] = "mediumpurple";              // 0x009370DB
    ColorNames::nameMap[   mediumseagreen           ] = "mediumseagreen";            // 0x003CB371
    ColorNames::nameMap[   mediumslateblue          ] = "mediumslateblue";           // 0x007B68EE
    ColorNames::nameMap[   mediumspringgreen        ] = "mediumspringgreen";         // 0x0000FA9A
    ColorNames::nameMap[   mediumturquoise          ] = "mediumturquoise";           // 0x0048D1CC
    ColorNames::nameMap[   mediumvioletred          ] = "mediumvioletred";           // 0x00C71585
    ColorNames::nameMap[   midnightblue             ] = "midnightblue";              // 0x00191970
    ColorNames::nameMap[   mintcream                ] = "mintcream";                 // 0x00F5FFFA
    ColorNames::nameMap[   mistyrose                ] = "mistyrose";                 // 0x00FFE4E1
    ColorNames::nameMap[   moccasin                 ] = "moccasin";                  // 0x00FFE4B5
    ColorNames::nameMap[   navajowhite              ] = "navajowhite";               // 0x00FFDEAD
    ColorNames::nameMap[   navy                     ] = "navy";                      // 0x00000080
    ColorNames::nameMap[   oldlace                  ] = "oldlace";                   // 0x00FDF5E6
    ColorNames::nameMap[   olive                    ] = "olive";                     // 0x00808000
    ColorNames::nameMap[   olivedrab                ] = "olivedrab";                 // 0x006B8E23
    ColorNames::nameMap[   orange                   ] = "orange";                    // 0x00FFA500
    ColorNames::nameMap[   orangered                ] = "orangered";                 // 0x00FF4500
    ColorNames::nameMap[   orchid                   ] = "orchid";                    // 0x00DA70D6
    ColorNames::nameMap[   palegoldenrod            ] = "palegoldenrod";             // 0x00EEE8AA
    ColorNames::nameMap[   palegreen                ] = "palegreen";                 // 0x0098FB98
    ColorNames::nameMap[   paleturquoise            ] = "paleturquoise";             // 0x00AFEEEE
    ColorNames::nameMap[   palevioletred            ] = "palevioletred";             // 0x00DB7093
    ColorNames::nameMap[   papayawhip               ] = "papayawhip";                // 0x00FFEFD5
    ColorNames::nameMap[   peachpuff                ] = "peachpuff";                 // 0x00FFDAB9
    ColorNames::nameMap[   peru                     ] = "peru";                      // 0x00CD853F
    ColorNames::nameMap[   pink                     ] = "pink";                      // 0x00FFC0CB
    ColorNames::nameMap[   plum                     ] = "plum";                      // 0x00DDA0DD
    ColorNames::nameMap[   powderblue               ] = "powderblue";                // 0x00B0E0E6
    ColorNames::nameMap[   purple                   ] = "purple";                    // 0x00800080
    ColorNames::nameMap[   red                      ] = "red";                       // 0x00FF0000
    ColorNames::nameMap[   rosybrown                ] = "rosybrown";                 // 0x00BC8F8F
    ColorNames::nameMap[   royalblue                ] = "royalblue";                 // 0x004169E1
    ColorNames::nameMap[   saddlebrown              ] = "saddlebrown";               // 0x008B4513
    ColorNames::nameMap[   salmon                   ] = "salmon";                    // 0x00FA8072
    ColorNames::nameMap[   sandybrown               ] = "sandybrown";                // 0x00F4A460
    ColorNames::nameMap[   seagreen                 ] = "seagreen";                  // 0x002E8B57
    ColorNames::nameMap[   seashell                 ] = "seashell";                  // 0x00FFF5EE
    ColorNames::nameMap[   sienna                   ] = "sienna";                    // 0x00A0522D
    ColorNames::nameMap[   silver                   ] = "silver";                    // 0x00C0C0C0
    ColorNames::nameMap[   skyblue                  ] = "skyblue";                   // 0x0087CEEB
    ColorNames::nameMap[   slateblue                ] = "slateblue";                 // 0x006A5ACD
    ColorNames::nameMap[   slategray                ] = "slategray";                 // 0x00708090
    ColorNames::nameMap[   snow                     ] = "snow";                      // 0x00FFFAFA
    ColorNames::nameMap[   springgreen              ] = "springgreen";               // 0x0000FF7F
    ColorNames::nameMap[   steelblue                ] = "steelblue";                 // 0x004682B4
    ColorNames::nameMap[   tan                      ] = "tan";                       // 0x00D2B48C
    ColorNames::nameMap[   teal                     ] = "teal";                      // 0x00008080
    ColorNames::nameMap[   thistle                  ] = "thistle";                   // 0x00D8BFD8
    ColorNames::nameMap[   tomato                   ] = "tomato";                    // 0x00FF6347
    ColorNames::nameMap[   turquoise                ] = "turquoise";                 // 0x0040E0D0
    ColorNames::nameMap[   violet                   ] = "violet";                    // 0x00EE82EE
    ColorNames::nameMap[   wheat                    ] = "wheat";                     // 0x00F5DEB3
    ColorNames::nameMap[   white                    ] = "white";                     // 0x00FFFFFF
    ColorNames::nameMap[   whitesmoke               ] = "whitesmoke";                // 0x00F5F5F5
    ColorNames::nameMap[   yellow                   ] = "yellow";                    // 0x00FFFF00
    ColorNames::nameMap[   yellowgreen              ] = "yellowgreen";               // 0x009ACD32

#endif  // VCF_LARGE_COLOR_LIST

    ColorNames::nameMap[   defaultcolor             ] = "defaultcolor";              // 0x02000000 ( appears as black )
    ColorNames::nameMap[   transparent              ] = "transparent";               // 0xFF000000
    ColorNames::nameMap[   unknown                  ] = "unknown";                   // 0x01000000 ( appears as black )

    ColorNames::unknownColorName = "unknown";
}

Enumerator<String>* ColorNames::getColorIDs()
{
	return ColorNames::nameMapContainer.getEnumerator();
}

String ColorNames::at( ColorID colorID )
{
	return ColorNames::nameMap[colorID];
}


String ColorNames::unknownColor()
{
	return ColorNames::unknownColorName;
}


