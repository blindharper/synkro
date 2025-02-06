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
// Purpose: Implements list widget item.
//==============================================================================
#include "config.h"
#include <ui/ListItem.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


ListItem::ListItem( const String& text, Pointer data ) :
	Text( text ),
	Data( data )
{
}

ListItem::ListItem( const String& text ) :
	Text( text ),
	Data( null )
{
}

ListItem::ListItem() :
	Text( String::Empty ),
	Data( null )
{
}


} // ui


} // synkro
