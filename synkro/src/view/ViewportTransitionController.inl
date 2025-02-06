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
// Purpose: Viewport transition controller implementation.
//==============================================================================
SYNKRO_INLINE void ViewportTransitionController::Clear()
{
	_keys.Clear();
}

SYNKRO_INLINE void ViewportTransitionController::SetLoopCount( UInt loopCount )
{
	_loopCount = loopCount;
}

SYNKRO_INLINE UInt ViewportTransitionController::GetKeyCount() const
{
	return _keys.Size();
}

SYNKRO_INLINE Double ViewportTransitionController::GetKeyTime( UInt index ) const
{
	assert( index < _keys.Size() );

	if ( index >= _keys.Size() )
		throw lang::OutOfRangeException( index, _keys.Size() );

	return _keys[index].Time;
}

SYNKRO_INLINE TransitionEffect ViewportTransitionController::GetKeyEffect( UInt index ) const
{
	assert( index < _keys.Size() );

	if ( index >= _keys.Size() )
		throw lang::OutOfRangeException( index, _keys.Size() );

	return _keys[index].Effect;
}

SYNKRO_INLINE IViewport* ViewportTransitionController::GetKeyViewport( UInt index ) const
{
	assert( index < _keys.Size() );

	if ( index >= _keys.Size() )
		throw lang::OutOfRangeException( index, _keys.Size() );

	return _keys[index].Viewport;
}

SYNKRO_INLINE UInt ViewportTransitionController::GetLoopCount() const
{
	return _loopCount;
}

SYNKRO_INLINE Double ViewportTransitionController::GetLength() const
{
	return (_keys.Size() > 0) ? _keys.Last()->Time : 0.0;
}
