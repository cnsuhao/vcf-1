
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
#include "vcf/GraphicsKit/GraphicsKit.h"
#include "vcf/GraphicsKit/AggCommon.h"


using namespace VCF;

BasicFill::BasicFill():
	opacity_(1.0),
	context_(NULL),
	antiAlias_(true)
{

}

BasicFill::~BasicFill()
{

}



void BasicFill::render( Path* path )
{
	if ( (NULL != context_) && (NULL != path) ){
		context_->setColor( &color_ );
		
		
		Matrix2D* currentXFrm = context_->getCurrentTransform();
		Enumerator<PathPoint>* points = path->getPoints( currentXFrm );

		std::vector<Point> pts;

		/**
		JC:
		Thanks to Marcello, we have resolved the VC7/7.1 stack corruption
		bug! Apparently, due to some trickery on my part which involved 
		const PathPoint& pt = points->nextElement();
		This was causing some weird problems due to referencing a temporary
		copy of the PathPoint. Marcello found this and discovered that if we replaced 
		that with the a simply assignment to the variables below, we have no more
		problems! Many, many, many thanks to Marcello for tracking this down and 
		fixing it!!!
		*/

		PathPoint pt, p2, c1, c2; 

		agg::rendering_buffer* renderingBuffer = context_->getRenderingBuffer();
		if ( (NULL == renderingBuffer) || (!antiAlias_) ){
			

			while ( true == points->hasMoreElements() ) {
				pt = points->nextElement();

				switch ( pt.type_ ){
					case PathPoint::ptMoveTo: {	
						if ( !pts.empty() ) {
							context_->polyline( pts );
						}
						pts.clear();
						pts.push_back( pt.point_ );
					}
					break;

					case PathPoint::ptLineTo: {						
						//context_->lineTo( pt.point_.x_, pt.point_.y_ );
						pts.push_back( pt.point_ );
					}
					break;

					case PathPoint::ptQuadTo: {
						
						
						c1 = points->nextElement();
						
						c2 = points->nextElement();
						
						p2 = points->nextElement();

						context_->curve( pt.point_.x_, pt.point_.y_,
											c1.point_.x_, c1.point_.y_,
											c2.point_.x_, c2.point_.y_,
											p2.point_.x_, p2.point_.y_ );
					}
					break;

					case PathPoint::ptCubicTo: {
						
					}
					break;

					case PathPoint::ptClose: {
						pts.push_back( pt.point_ );
						context_->polyline( pts );
						
						pts.clear();
					}
					break;
				}
			}

			if ( !pts.empty() ) {
				context_->polyline( pts );
				pts.clear();
			}

			context_->fillPath();
		}
		else {
		
			typedef agg::renderer_scanline<agg::span_solid_rgba8, pixfmt> renderer_solid;

			renderer_solid renderer( *renderingBuffer );
				

			agg::path_storage fillPath;
			

			agg::rasterizer_scanline_aa<agg::scanline_u8, agg::gamma8> rasterizer;
			
			
			while ( true == points->hasMoreElements() ) {
				pt = points->nextElement();

				switch ( pt.type_ ){
					case PathPoint::ptMoveTo: {						
						fillPath.move_to( pt.point_.x_, pt.point_.y_ );
					}
					break;

					case PathPoint::ptLineTo: {						
						fillPath.line_to( pt.point_.x_, pt.point_.y_ );
					}
					break;

					case PathPoint::ptQuadTo: {
						
						fillPath.move_to( pt.point_.x_, pt.point_.y_ );
						
						c1 = points->nextElement();
						
						c2 = points->nextElement();
						
						p2 = points->nextElement();
						fillPath.curve4( c1.point_.x_, c1.point_.y_,
										c2.point_.x_, c2.point_.y_,
										p2.point_.x_, p2.point_.y_ );
					}
					break;

					case PathPoint::ptCubicTo: {
						
					}
					break;

					case PathPoint::ptClose: {
						fillPath.close_polygon();						
					}
					break;
				}
			}
			
			agg::conv_curve<agg::path_storage> smooth(fillPath);
			
			//agg::conv_stroke<agg::conv_curve<agg::path_storage> >  stroke(smooth);

			rasterizer.add_path( smooth );
			
			renderer.attribute(agg::rgba(color_.getRed(),color_.getGreen(),color_.getBlue(),opacity_));
			
			rasterizer.render(renderer);
		}
	}
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:40:30  ddiego
*migration towards new directory structure
*
*Revision 1.12.2.1  2004/04/06 17:49:15  marcelloptr
*killed the last resisting 'const PathPoint&' still buzzing around
*
*Revision 1.12  2004/04/06 00:01:46  ddiego
*Marcellos fix for the VC7/7.1 stack corruption bug
*caused by my code. Many, many, many thanks to Marcello for
*spending the time to track this down and fix it.
*
*Revision 1.11  2003/12/18 05:16:01  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.10.2.1  2003/10/02 04:50:52  ddiego
*changes to ensure the code compiles on linux. made a bunch of updates to
*the makefiles
*
*Revision 1.10  2003/08/09 02:56:45  ddiego
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
*Revision 1.9.2.6  2003/08/08 03:21:36  ddiego
*got rid of some miscellaneous graphics files
*
*Revision 1.9.2.5  2003/07/28 23:49:58  ddiego
*check in of the weekend's work from July 25
*learned how to use agg image renedering, now have to integrate it into the
*GraphicsKit - alos enabled setting a viewable bounds that sets the agg cliprect
*as well, useful for later optimizations
*
*Revision 1.9.2.4  2003/07/24 04:10:44  ddiego
*added fixes for the following tasks:
*Task #82279 ApplicationKit: add static methods to singleton objects
*Task #82277 FoundationKit: add static methods to singleton objects
*this required a bunch of changes in terms of getting rid of older style code
*
*Revision 1.9.2.3  2003/07/21 03:08:30  ddiego
*added bezier curve editing to Sketchit, fixed a bug in not saving
*bitmaps, added PackageInfo to the ApplicationKit
*
*Revision 1.9.2.2  2003/07/16 04:59:07  ddiego
*added some changes to the fil and stroke classes to allow changing whether
*they use anti-aliasing or not. Also implemented Matrix2D::invert(),
*plus properly implemented clone() on the DefaultMenuItem class.
*
*Revision 1.9.2.1  2003/07/05 04:04:45  ddiego
*added more AGG support
*  added a common AGG header to use when accessing the AGG API directly
*  see the graphics/AggCommon.h header for this
*  Made some minor changes to Path to work a bit simpler
*  Implemented Polygon completely,
*  Implemented BasicFill and BasicStroke - using AGG
*
*Revision 1.9  2003/05/17 20:37:19  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.8.10.1  2003/03/23 03:23:55  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.8  2002/09/12 03:26:05  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.7.6.1  2002/08/06 02:57:36  ddiego
*added base X11 files for GraphicsKit and made sure that the GraphicsKit compiles
*under linux (GCC). There is now a new dir under build/xmake called GraphicsKit
*where the xmake build script lives. This checkin also includes the base X11
*include (as part of GraphicsKitPrivate.h), as well as linking to the X11 libs
*
*Revision 1.7  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.6.4.1  2002/04/03 19:37:17  zzack
*include style changed
*
*Revision 1.6  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/





