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
// Purpose: Stream set implementation.
//==============================================================================
SYNKRO_INLINE void StreamSet::Clear()
{
	_streams.Clear();
}

SYNKRO_INLINE void StreamSet::Add( IStream* stream )
{
	_streams.Add( stream );
}

SYNKRO_INLINE UInt StreamSet::GetSize() const
{
	return _streams.Size();
}

SYNKRO_INLINE IStream* StreamSet::Get( UInt index ) const
{
	assert( index < _streams.Size() );

	if ( index >= _streams.Size() )
		throw lang::OutOfRangeException( index, _streams.Size() );

	return _streams[index];
}

SYNKRO_INLINE UInt StreamSet::IndexOf( IStream* stream ) const
{
	return _streams.IndexOf( stream );
}
