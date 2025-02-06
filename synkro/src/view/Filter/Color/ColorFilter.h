//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Color viewport filter implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_COLORFILTER_
#define _SYNKRO_VIEW_COLORFILTER_


#include "config.h"
#include <view/Filter/ViewportFilterImpl.h>
#include <view/IColorFilter.h>
#include <view/IColorFilterAnimationController.h>


namespace synkro
{


namespace view
{


// Color viewport filter implementation.
class ColorFilter :
	public ViewportFilterImpl<IColorFilter>
{
public:
	// Constructor.
	ColorFilter( IViewport* viewport, anim::IAnimationSystem* animationSystem, gfx::IProgram* program );

	// IViewportFilter methods.
	IViewportFilterAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

	// IColorFilter methods.
	void													SetColor( const img::Color& color );
	void													GetColor( img::Color& color ) const;
	IColorFilter*											AsColor() const;

private:
	P(IColorFilterAnimationController)						_ctrlAnimation;
	gfx::ProgramParam*										_paramColor;
};


#include "ColorFilter.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_COLORFILTER_
