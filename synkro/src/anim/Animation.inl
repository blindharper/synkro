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
// Purpose: Implements generic animation.
//==============================================================================
SYNKRO_INLINE UInt Animation::GetTrackCount() const
{
	return _tracks.Size();
}

SYNKRO_INLINE IAnimationTrack* Animation::GetTrack( UInt index ) const
{
	assert( index < _tracks.Size() );

	if ( index >= _tracks.Size() )
		throw lang::OutOfRangeException( index, _tracks.Size() );

	return _tracks[index];
}

SYNKRO_INLINE IAnimationTrack* Animation::GetTrack( const lang::String& name ) const
{
	return _indexes.ContainsKey(name) ? GetTrack( _indexes[name] ) : nullptr;
}

SYNKRO_INLINE lang::String Animation::GetName() const
{
	return _name;
}
