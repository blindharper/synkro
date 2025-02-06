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
// Purpose: Default slider widget implementation.
//==============================================================================
SYNKRO_INLINE void DefaultSlider::SetMinPosition( UInt minPosition )
{
	_minPosition = minPosition;

	if ( _position < _minPosition )
	{
		SetPosition( _minPosition );
	}
}

SYNKRO_INLINE void DefaultSlider::SetMaxPosition( UInt maxPosition )
{
	_maxPosition = maxPosition;

	if ( _position > _maxPosition )
	{
		SetPosition( _maxPosition );
	}
}

SYNKRO_INLINE Orientation DefaultSlider::GetOrientation() const
{
	return _orientation;
}

SYNKRO_INLINE UInt DefaultSlider::GetMinPosition() const
{
	return _minPosition;
}

SYNKRO_INLINE UInt DefaultSlider::GetMaxPosition() const
{
	return _maxPosition;
}

SYNKRO_INLINE UInt DefaultSlider::GetPosition() const
{
	return _position;
}

SYNKRO_INLINE void DefaultSlider::GetThumbSize( lang::Size& size ) const
{
	size.Width = _rectThumb.Width();
	size.Height = _rectThumb.Height();
}

SYNKRO_INLINE void DefaultSlider::UpdateRect()
{
	CalcRect();
	UpdateSize();
	UpdateRails();
	SetPosition( _position );
}
