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
// Purpose: Defines range object.
//==============================================================================
#include "config.h"
#include <lang/Range.h>


namespace synkro
{


namespace lang
{


Range::Range( UInt start, UInt length ) SYNKRO_NOEXCEPT :
	Start( start ),
	Length( length )
{
}

Range::Range( UInt length ) SYNKRO_NOEXCEPT :
	Start( 0 ),
	Length( length )
{
}

Range::Range( const Range& other ) SYNKRO_NOEXCEPT :
	Start( other.Start ),
	Length( other.Length )
{
}

Range::Range() SYNKRO_NOEXCEPT :
	Start( 0 ),
	Length( 0 )
{
}

Range& Range::Set( UInt start, UInt length ) SYNKRO_NOEXCEPT
{
	Start = start;
	Length = length;
	return *this;
}

Range& Range::operator=( const Range& other ) SYNKRO_NOEXCEPT
{
	return Set( other.Start, other.Length );
}

Bool Range::operator==( const Range& other ) const SYNKRO_NOEXCEPT
{
	return (Start == other.Start) && (Length == other.Length);
}

Bool Range::operator!=( const Range& other ) const SYNKRO_NOEXCEPT
{
	return (Start != other.Start) || (Length != other.Length);
}


} // lang


} // synkro
