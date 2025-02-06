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
// Purpose: Emboss filter implementation.
//==============================================================================
#include "config.h"
#include "EmbossFilter.h"
#include "EmbossFilterAnimationController.h"
#include <math/Math.h>
#include <math/Vector2.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


EmbossFilter::EmbossFilter( IViewport* viewport, IAnimationSystem* animationSystem, IProgram* program ) :
	Kernel3x3FilterImpl<IEmbossFilter>( viewport, animationSystem, program )
{
	_paramWeights = _params->GetParam( L"p_weights" );
	_paramDepth = _params->GetParam( L"p_depth" );
	SetDepth( 0.5f );
	SetAngle( 0.0f );
}

IViewportFilterAnimationController* EmbossFilter::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new EmbossFilterAnimationController( this, _animationSystem, animation, listener ) : _ctrlAnimation;
}

void EmbossFilter::SetAngle( Float angle )
{
	// Pixel indices in program.
	//
	// 0 1 2
	// 3 4 5
	// 6 7 8
	_angle = Clamp( angle, 0.0f, 360.0f );
	angle = Math::ToRadians( angle );
	const Vector2 light( Math::Cos(angle), Math::Sin(angle) );

	Vector2 normals[] = 
	{
		Vector2( -1.0f,  1.0f ), Vector2( 0.0f,  1.0f ), Vector2( 1.0f,  1.0f ),
		Vector2( -1.0f,  0.0f ), Vector2( 0.0f,  0.0f ), Vector2( 1.0f,  0.0f ),
		Vector2( -1.0f, -1.0f ), Vector2( 0.0f, -1.0f ), Vector2( 1.0f, -1.0f ),
	};

	for ( UInt i = 0; i < 9; ++i )
	{
		normals[i].Normalize();
		_weights[i] = -normals[i] * light;
	}
	_params->Set( _paramWeights, _weights, 9 );
}


} // view


} // synkro
