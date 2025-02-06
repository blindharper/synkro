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
// Purpose: Generic keyframed animation track implementation.
//==============================================================================
template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE KeyframedTrackImpl<T, P, E, V, D>::KeyframedTrackImpl( const lang::String& name ) :
	AnimationTrackImpl<T, D>( name ),
	_keys( A(Key) )
{
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE KeyframedTrackImpl<T, P, E, V, D>::~KeyframedTrackImpl()
{
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE void KeyframedTrackImpl<T, P, E, V, D>::GetValue( Double time, typename V& value ) const
{
	if ( _keys.Size() > 1 )
	{
		UInt key1 = none; UInt key2 = none;
		if ( GetFork(time, key1, key2) )
		{
			Double d = (time - _keys[key1].Time)/(_keys[key2].Time - _keys[key1].Time);
			switch ( _keys[key2].Interpolation )
			{
				case INTERPOLATION_STEPPED:
					d = 1.0f;
					break;

				case INTERPOLATION_LINEAR:
					break;

				case INTERPOLATION_EASE:
					d = math::CubicBezier::Ease.Solve( d );
					break;

				case INTERPOLATION_EASE_IN:
					d = math::CubicBezier::EaseIn.Solve( d );
					break;

				case INTERPOLATION_EASE_OUT:
					d = math::CubicBezier::EaseOut.Solve( d );
					break;

				case INTERPOLATION_EASE_IN_OUT:
					d = math::CubicBezier::EaseInOut.Solve( d );
					break;
			}
			value = Lerp( _keys[key1].Value, _keys[key2].Value, d );
		}
		else
		{
			value = (key1 != 0) ? _keys[key1].Value : ((key2 != none) ? _keys[key2].Value : _keys[0].Value);
		}
	}
	else if ( _keys.Size() > 0 )
	{
		value = _keys[0].Value;
	}
	else
	{
		value = V();
	}
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE Double KeyframedTrackImpl<T, P, E, V, D>::GetLength() const
{
	return (_keys.Size() > 0) ? _keys.Last()->Time : 0.0;
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE typename T* KeyframedTrackImpl<T, P, E, V, D>::AsKeyframed() const
{
	return (typename T*)this;
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE typename P* KeyframedTrackImpl<T, P, E, V, D>::AsProcedural() const
{
	return nullptr;
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE typename E* KeyframedTrackImpl<T, P, E, V, D>::AsExpression() const
{
	return nullptr;
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE void KeyframedTrackImpl<T, P, E, V, D>::Clear()
{
	_keys.Clear();
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE void KeyframedTrackImpl<T, P, E, V, D>::SetKey( Double time, const typename V& value, const Interpolation& interpolation )
{
	if ( time >= GetLength() )
	{
		_keys.Add( Key(time, value, interpolation) );
	}
	else
	{
		UInt count = _keys.Size();
		for ( UInt i = 0; i < count; ++i )
		{
			if ( _keys[i].Time == time )
			{
				_keys[i].Value			= value;
				_keys[i].Interpolation	= interpolation;
				return;
			}
		}

		_keys.SetSize( count+1 );
		_keys[count-1] = _keys[count-2];

		for ( UInt i = 0, j = 0; i < count-2; ++i, ++j )
		{
			if ( (_keys[i].Time < time) && (time < _keys[i+1].Time) )
			{
				_keys[j] = Key( time, value, interpolation );
			}
			else
			{
				_keys[j] = _keys[i];
			}
		}
	}
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE void KeyframedTrackImpl<T, P, E, V, D>::SetKey( Double time, const typename V& value )
{
	SetKey( time, value, Interpolation::Linear );
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE UInt KeyframedTrackImpl<T, P, E, V, D>::GetKeyCount() const
{
	return _keys.Size();
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE Double KeyframedTrackImpl<T, P, E, V, D>::GetKeyTime( UInt index ) const
{
	assert( index < _keys.Size() );

	if ( index >= _keys.Size() )
		throw lang::OutOfRangeException( index, _keys.Size() );

	return _keys[index].Time;
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE Interpolation KeyframedTrackImpl<T, P, E, V, D>::GetKeyInterpolation( UInt index ) const
{
	assert( index < _keys.Size() );

	if ( index >= _keys.Size() )
		throw lang::OutOfRangeException( index, _keys.Size() );

	return _keys[index].Interpolation;
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE void KeyframedTrackImpl<T, P, E, V, D>::GetKeyValue( UInt index, typename V& value ) const
{
	assert( index < _keys.Size() );

	if ( index >= _keys.Size() )
		throw lang::OutOfRangeException( index, _keys.Size() );

	value = _keys[index].Value;
}

template <class T, class P, class E, class V, UInt D>
SYNKRO_INLINE Bool KeyframedTrackImpl<T, P, E, V, D>::GetFork( Double time, UInt& key1, UInt& key2 ) const
{
	key1 = none; key2 = none;

	for ( UInt i = 0; i < _keys.Size(); ++i )
	{
		if ( time > _keys[i].Time )
		{
			key1 = i;
		}
		else if ( time < _keys[i].Time )
		{
			key2 = i;
		}
		else if ( time == _keys[i].Time )
		{
			key1 = i;
			return false;
		}

		if ( (key1 != none) && (key2 != none) )
			return true;
	}

	key1 = 0;
	key2 = _keys.Size()-1;
	return false;
}
