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
// Purpose: Curve node implementation.
//==============================================================================
SYNKRO_INLINE void Curve::SetColor( const img::Color& color )
{
	_curve.SetColor( color );
}

SYNKRO_INLINE UInt Curve::GetPointCount() const
{
	return _points.Size();
}

SYNKRO_INLINE void Curve::GetPoint( UInt index, math::Vector3& point ) const
{
	ValidateIndex( index );

	point = _points[index].Position;
}

SYNKRO_INLINE Float Curve::GetTension( UInt index ) const
{
	ValidateIndex( index );

	return _points[index].Tension;
}

SYNKRO_INLINE Float Curve::GetContinuity( UInt index ) const
{
	ValidateIndex( index );

	return _points[index].Continuity;
}

SYNKRO_INLINE Float Curve::GetBias( UInt index ) const
{
	ValidateIndex( index );

	return _points[index].Bias;
}

SYNKRO_INLINE void Curve::GetColor( img::Color& color ) const
{
	color = _color;
}
