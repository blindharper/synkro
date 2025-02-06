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
#include "config.h"
#include "ColorFilter.h"
#include "ColorFilterAnimationController.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


ColorFilter::ColorFilter( IViewport* viewport, IAnimationSystem* animationSystem, IProgram* program ) :
	ViewportFilterImpl<IColorFilter>( viewport, animationSystem, program )
{
	_paramColor = _params->GetParam( L"p_color" );
	SetColor( Color::White );
}

IViewportFilterAnimationController* ColorFilter::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new ColorFilterAnimationController( this, _animationSystem, animation, listener ) : _ctrlAnimation;
}


} // view


} // synkro
