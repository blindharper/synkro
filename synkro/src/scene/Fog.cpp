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
// Purpose: Fog effect implementation.
//==============================================================================
#include "config.h"
#include "Fog.h"
#include "FogAnimationController.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::img;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


Fog::Fog( IContext* context ) :
	_context( context )
{
	_state.FogColor.w = 1.0f;
	SetType( FogType::Linear );
	SetColor( Color::LightGray );
	SetDensity( 0.01f );
	SetStart( 0.0f );
	SetEnd( 100.0f );
}

IFogAnimationController* Fog::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new FogAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}


} // scene


} // synkro
