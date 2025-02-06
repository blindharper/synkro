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
// Purpose: Color viewport filter implementation.
//==============================================================================
SYNKRO_INLINE void ColorFilter::SetColor( const img::Color& color )
{
	_params->Set( _paramColor, ToVector(color, 1.0f) );
}

SYNKRO_INLINE void ColorFilter::GetColor( img::Color& color ) const
{
	math::Vector4 vec;
	_params->Get( _paramColor, &vec );
	color = ToColor( vec );
}

SYNKRO_INLINE IColorFilter* ColorFilter::AsColor() const
{
	return (IColorFilter*)this;
}
