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
// Purpose: Simple viewport filter implementation.
//==============================================================================
#include "config.h"
#include "SimpleFilter.h"
#include "SimpleFilterAnimationController.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


SimpleFilter::SimpleFilter( IViewport* viewport, IAnimationSystem* animationSystem, IProgram* program ) :
	ViewportFilterImpl<ISimpleFilter>( viewport, animationSystem, program )
{
	_paramValue = _params->GetParam( L"p_value" );
	SetValue( 0.0f );
}

IViewportFilterAnimationController* SimpleFilter::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new SimpleFilterAnimationController( this, _animationSystem, animation, listener ) : _ctrlAnimation;
}


} // view


} // synkro
