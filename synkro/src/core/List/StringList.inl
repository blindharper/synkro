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
// Purpose: String list implementation.
//==============================================================================
SYNKRO_INLINE UInt StringList::GetSize() const
{
	return _strings.Size();
}

SYNKRO_INLINE lang::String StringList::Get( UInt index ) const
{
	assert( index < _strings.Size() );

	if ( index >= _strings.Size() )
		throw lang::OutOfRangeException( index, _strings.Size() );

	return _strings[index];
}
