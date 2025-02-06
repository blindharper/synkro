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
// Purpose: Defines whole number size.
//==============================================================================
#include "config.h"
#include <lang/Size.h>


namespace synkro
{


namespace lang
{


Size::Size( UInt width, UInt height ) :
	Width( width ),
	Height( height )
{
}

Size::Size( const Size& other ) :
	Width( other.Width ),
	Height( other.Height )
{
}

Size::Size() :
	Width( 0 ),
	Height( 0 )
{
}

Size& Size::Set( UInt width, UInt height )
{
	Width = width;
	Height = height;
	return *this;
}

Size& Size::operator=( const Size& other )
{
	return Set( other.Width, other.Height );
}

Bool Size::operator==( const Size& other ) const
{
	return (Width == other.Width) && (Height == other.Height);
}

Bool Size::operator!=( const Size& other ) const
{
	return (Width != other.Width) || (Height != other.Height);
}

Bool Size::IsEmpty() const
{
	return (Width == 0) || (Height == 0);
}


} // lang


} // synkro
