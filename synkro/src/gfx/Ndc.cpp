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
// Purpose: Defines normalized device coordinates.
//==============================================================================
#include "config.h"
#include "Ndc.h"


//------------------------------------------------------------------------------

using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Ndc::Ndc( IRenderWindow* window, UInt screenWidth, UInt screenHeight ) :
	_window( window ),
	_screenWidth( screenWidth ),
	_screenHeight( screenHeight )
{
	Update();
}

void Ndc::Update()
{
	if ( _window != nullptr )
	{
		_screenWidth = CastFloat(_window->GetWidth());
		_screenHeight = CastFloat(_window->GetHeight());
	}
	_factorWidth = 1.0f/_screenWidth;
	_factorHeight = 1.0f/_screenHeight;
}


} // gfx


} // synkro
