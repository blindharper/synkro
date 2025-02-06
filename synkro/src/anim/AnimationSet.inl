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
// Purpose: Implements animation set.
//==============================================================================
SYNKRO_INLINE UInt AnimationSet::GetAnimationCount() const
{
	return _animations.Size();
}

SYNKRO_INLINE IAnimation* AnimationSet::GetAnimation( UInt index ) const
{
	assert( index < _animations.Size() );

	if ( index >= _animations.Size() )
		throw lang::OutOfRangeException( index, _animations.Size() );

	return _animations[index];
}

SYNKRO_INLINE IAnimation* AnimationSet::GetAnimation( const lang::String& name ) const
{
	return _indexes.ContainsKey(name) ? GetAnimation( _indexes[name] ) : nullptr;
}

SYNKRO_INLINE lang::String AnimationSet::GetName() const
{
	return _name;
}
