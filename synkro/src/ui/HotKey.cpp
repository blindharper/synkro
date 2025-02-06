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
// Purpose: Defines hot key.
//==============================================================================
#include "config.h"
#include <ui/HotKey.h>


namespace synkro
{


namespace ui
{


const HotKey HotKey::None = HotKey();


HotKey::HotKey( const input::Key& key, Bool control, Bool shift, Bool alt ) :
	Key( key ),
	Control( control ),
	Shift( shift ),
	Alt( alt )
{
}

HotKey::HotKey( const input::Key& key, Bool control, Bool shift ) :
	Key( key ),
	Control( control ),
	Shift( shift ),
	Alt( false )
{
}

HotKey::HotKey( const input::Key& key, Bool control ) :
	Key( key ),
	Control( control ),
	Shift( false ),
	Alt( false )
{
}

HotKey::HotKey( const input::Key& key ) :
	Key( key ),
	Control( false ),
	Shift( false ),
	Alt( false )
{
}

HotKey::HotKey() :
	Key( input::Key::Unknown ),
	Control( false ),
	Shift( false ),
	Alt( false )
{
}

Bool HotKey::operator==( const HotKey& other ) const
{
	return (Key == other.Key) && (Control == other.Control) && (Shift == other.Shift) && (Alt == other.Alt);
}

Bool HotKey::operator!=( const HotKey& other ) const
{
	return !operator==( other );
}


} // ui


} // synkro
