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
#ifndef _SYNKRO_ANIM_KEYFRAMEDTRACKIMPL_
#define _SYNKRO_ANIM_KEYFRAMEDTRACKIMPL_


#include "config.h"
#include <anim/AnimationTrackImpl.h>
#include <anim/IKeyframedBoolTrack.h>
#include <anim/IKeyframedColorGradientTrack.h>
#include <anim/IKeyframedColorTrack.h>
#include <anim/IKeyframedFloatRectTrack.h>
#include <anim/IKeyframedFloatTrack.h>
#include <anim/IKeyframedIntTrack.h>
#include <anim/IKeyframedMatrix4x4Track.h>
#include <anim/IKeyframedPointTrack.h>
#include <anim/IKeyframedQuaternionTrack.h>
#include <anim/IKeyframedRangeTrack.h>
#include <anim/IKeyframedRectTrack.h>
#include <anim/IKeyframedSizeTrack.h>
#include <anim/IKeyframedVector3Track.h>
#include "InterpolationConst.h"
#include <lang/Vector.h>
#include <math/CubicBezier.h>


namespace synkro
{


namespace anim
{


// Generic keyframed animation track implementation.
template <class T, class P, class E, class V, UInt D>
class KeyframedTrackImpl :
	public AnimationTrackImpl<T, D>
{
public:
	// Constructor & destructor.
	KeyframedTrackImpl( const lang::String& name );
	virtual ~KeyframedTrackImpl();

	// IAnimation<T>Track methods.
	virtual void											GetValue( Double time, typename V& value ) const;
	virtual Double											GetLength() const;
	virtual typename T*										AsKeyframed() const;
	virtual typename P*										AsProcedural() const;
	virtual typename E*										AsExpression() const;
	
	// IKeyframed<V>Track methods.
	virtual void											Clear();
	virtual void											SetKey( Double time, const typename V& value, const Interpolation& interpolation );
	virtual void											SetKey( Double time, const typename V& value );
	virtual UInt											GetKeyCount() const;
	virtual Double											GetKeyTime( UInt index ) const;
	virtual Interpolation									GetKeyInterpolation( UInt index ) const;
	virtual void											GetKeyValue( UInt index, typename V& value ) const;

protected:
	struct Key
	{
		Key( Double time, const typename V& value, const Interpolation& interpolation ) :
			Time( time ),
			Value( value ),
			Interpolation( interpolation )
		{
		}

		Key() :
			Time( 0.0 ),
			Value( V() ),
			Interpolation( Interpolation::Linear )
		{
		}

		Double				Time;
		V					Value;
		Interpolation		Interpolation;
	};

	lang::Vector<Key>										_keys;

	Bool													GetFork( Double time, UInt& key1, UInt& key2 ) const;
};


#include "KeyframedTrackImpl.inl"


typedef class KeyframedTrackImpl<IKeyframedBoolTrack, IProceduralBoolTrack, IExpressionBoolTrack, Bool, TYPE_BOOL> KeyframedBoolTrack;
typedef class KeyframedTrackImpl<IKeyframedColorTrack, IProceduralColorTrack, IExpressionColorTrack, img::Color, TYPE_COLOR> KeyframedColorTrack;
typedef class KeyframedTrackImpl<IKeyframedColorGradientTrack, IProceduralColorGradientTrack, IExpressionColorGradientTrack, img::ColorGradient, TYPE_COLOR_GRADIENT> KeyframedColorGradientTrack;
typedef class KeyframedTrackImpl<IKeyframedFloatTrack, IProceduralFloatTrack, IExpressionFloatTrack, Float, TYPE_FLOAT> KeyframedFloatTrack;
typedef class KeyframedTrackImpl<IKeyframedFloatRectTrack, IProceduralFloatRectTrack, IExpressionFloatRectTrack, lang::RectF, TYPE_FLOAT_RECT> KeyframedFloatRectTrack;
typedef class KeyframedTrackImpl<IKeyframedIntTrack, IProceduralIntTrack, IExpressionIntTrack, Int, TYPE_INT> KeyframedIntTrack;
typedef class KeyframedTrackImpl<IKeyframedMatrix4x4Track, IProceduralMatrix4x4Track, IExpressionMatrix4x4Track, math::Matrix4x4, TYPE_MATRIX4X4> KeyframedMatrix4x4Track;
typedef class KeyframedTrackImpl<IKeyframedPointTrack, IProceduralPointTrack, IExpressionPointTrack, lang::Point, TYPE_POINT> KeyframedPointTrack;
typedef class KeyframedTrackImpl<IKeyframedQuaternionTrack, IProceduralQuaternionTrack, IExpressionQuaternionTrack, math::Quaternion, TYPE_QUATERNION> KeyframedQuaternionTrack;
typedef class KeyframedTrackImpl<IKeyframedRangeTrack, IProceduralRangeTrack, IExpressionRangeTrack, lang::Range, TYPE_RANGE> KeyframedRangeTrack;
typedef class KeyframedTrackImpl<IKeyframedRectTrack, IProceduralRectTrack, IExpressionRectTrack, lang::Rect, TYPE_RECT> KeyframedRectTrack;
typedef class KeyframedTrackImpl<IKeyframedSizeTrack, IProceduralSizeTrack, IExpressionSizeTrack, lang::Size, TYPE_SIZE> KeyframedSizeTrack;
typedef class KeyframedTrackImpl<IKeyframedVector3Track, IProceduralVector3Track, IExpressionVector3Track, math::Vector3, TYPE_VECTOR3> KeyframedVector3Track;



} // anim


} // synkro


#endif // _SYNKRO_ANIM_KEYFRAMEDTRACKIMPL_
