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
#ifndef _SYNKRO_GFX_NDC_
#define _SYNKRO_GFX_NDC_


#include "config.h"
#include <gfx/IRenderWindow.h>
#include <math/Vector2.h>
#include <math/Vector4.h>


namespace synkro
{


namespace gfx
{


// Normalized device coordinates.
class Ndc
{
public:
	// Constructor.
	Ndc( IRenderWindow* window, UInt screenWidth, UInt screenHeight );

	// Methods.
	void													Update();
	math::Vector2											Convert( const math::Vector2& value );
	math::Vector4											Convert( const math::Vector4& value );
	math::Vector4											Convert2( const math::Vector4& value );

private:
	IRenderWindow*											_window;
	Float													_screenWidth;
	Float													_screenHeight;
	Float													_factorWidth;
	Float													_factorHeight;
};


#include "Ndc.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_NDC_
