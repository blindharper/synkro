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
// Purpose: Implements mouse description.
//==============================================================================
#include "config.h"
#include <input/MouseDesc.h>


namespace synkro
{


namespace input
{


MouseDesc::MouseDesc() :
	AxisCount( 0 ),
	ButtonCount( 0 )
{
}

MouseDesc::MouseDesc( const lang::String& name, UInt axisCount, UInt buttonCount ) :
	Name( name ),
	AxisCount( axisCount ),
	ButtonCount( buttonCount )
{
}


} // input


} // synkro
