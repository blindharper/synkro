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
// Purpose: Defines normalized device coordinates.
//==============================================================================
SYNKRO_INLINE math::Vector2 Ndc::Convert( const math::Vector2& value )
{
	return math::Vector2( 2.0f*value.x*_factorWidth, -2.0f*value.y*_factorHeight );
}

SYNKRO_INLINE math::Vector4 Ndc::Convert( const math::Vector4& value )
{
	return math::Vector4( (2.0f*value.x*_factorWidth)-1.0f, 1.0f-(2.0f*value.y*_factorHeight), value.z, 1.0f );
}

SYNKRO_INLINE math::Vector4 Ndc::Convert2( const math::Vector4& value )
{
	return math::Vector4( (value.x+1.0f)*0.5f*_screenWidth, -(value.y-1.0f)*0.5f*_screenHeight, value.z, 1.0f );
}
