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
// Purpose: Implements keyboard description.
//==============================================================================
#include "config.h"
#include <input/KeyboardDesc.h>


namespace synkro
{


namespace input
{


KeyboardDesc::KeyboardDesc() :
	KeyCount( 0 )
{
}

KeyboardDesc::KeyboardDesc( const lang::String& name, UInt keyCount ) :
	Name( name ),
	KeyCount( keyCount )
{
}


} // input


} // synkro
