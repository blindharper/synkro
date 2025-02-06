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
#include "config.h"
#include "TextDesc.h"


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace over
{


TextDesc::TextDesc( const String& text, const Point& location, const ColorGradient& gradient ) :
	Text( text ),
	Location( location ),
	Gradient( gradient ),
	Color( gradient.Start ),
	Orientation( 0.0f ),
	Scale( 1.0f ),
	CenterEnabled( false ),
	Opacity( 1.0f ),
	Wrapped( false )
{
}

TextDesc::TextDesc() :
	Orientation( 0.0f ),
	Scale( 1.0f ),
	CenterEnabled( false ),
	Opacity( 1.0f ),
	Wrapped( false )
{
}


} // over


} // synkro
