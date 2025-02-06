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
// Purpose: Audio environment implementation.
//==============================================================================
SYNKRO_INLINE void AudioEnvironment::SetListener( ISoundListener* listener )
{
	assert( listener != nullptr );

	_listener = listener;
}

SYNKRO_INLINE UInt AudioEnvironment::GetEmitterCount() const
{
	return _emitters.Size();
}

SYNKRO_INLINE ISoundEmitter* AudioEnvironment::GetEmitter( UInt index ) const
{
	assert( index < _emitters.Size() );

	if ( index >= _emitters.Size() )
		throw lang::OutOfRangeException( index, _emitters.Size() );

	return _emitters[index];
}

SYNKRO_INLINE ISoundListener* AudioEnvironment::GetListener() const
{
	return _listener;
}
