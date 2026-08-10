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
// Purpose: Default angle widget implementation.
//==============================================================================
SYNKRO_INLINE void DefaultAngle::SetMaxValue( Float maxValue )
{
	_maxValue = maxValue;
}

SYNKRO_INLINE void DefaultAngle::SetValue( Float value )
{
	_value = value;
	UpdateThumb();
}

SYNKRO_INLINE Float DefaultAngle::GetMaxValue() const
{
	return _maxValue;
}

SYNKRO_INLINE Float DefaultAngle::GetValue() const
{
	return _value;
}

SYNKRO_INLINE void DefaultAngle::UpdateRect()
{
	CalcRect();
	UpdateCircle();
	UpdateThumb();
	SetValue( _value );
}
