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
// Purpose: Text description.
//==============================================================================
#ifndef _SYNKRO_OVER_TEXTDESC_
#define _SYNKRO_OVER_TEXTDESC_


#include "config.h"
#include <lang/String.h>
#include <lang/Point.h>
#include <lang/Rect.h>
#include <math/Math.h>
#include <img/ColorGradient.h>


namespace synkro
{


namespace over
{


// Text description.
class TextDesc
{
public:
	// Constructors.
	TextDesc( const lang::String& text, const lang::Point& location, const img::ColorGradient& gradient );
	TextDesc();

	lang::String											Text;
	lang::Point												Location;
	Float													Orientation;	// In radians
	Float													Scale;
	lang::Rect												Rect;
	lang::Point												Center;
	Bool													CenterEnabled;
	img::ColorGradient										Gradient;
	img::Color												Color;
	Float													Opacity;
	Bool													Wrapped;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_TEXTDESC_
