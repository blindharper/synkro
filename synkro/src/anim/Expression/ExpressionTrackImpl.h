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
// Purpose: Generic expression track implementation.
//==============================================================================
#ifndef _SYNKRO_ANIM_EXPRESSIONTRACKIMPL_
#define _SYNKRO_ANIM_EXPRESSIONTRACKIMPL_


#include "config.h"
#include <anim/AnimationTrackImpl.h>
#include <anim/IExpressionBoolTrack.h>
#include <anim/IExpressionColorTrack.h>
#include <anim/IExpressionColorGradientTrack.h>
#include <anim/IExpressionFloatTrack.h>
#include <anim/IExpressionFloatRectTrack.h>
#include <anim/IExpressionIntTrack.h>
#include <anim/IExpressionMatrix4x4Track.h>
#include <anim/IExpressionPointTrack.h>
#include <anim/IExpressionQuaternionTrack.h>
#include <anim/IExpressionRangeTrack.h>
#include <anim/IExpressionRectTrack.h>
#include <anim/IExpressionSizeTrack.h>
#include <anim/IExpressionVector3Track.h>
#include <anim/IExpressionScript.h>
#include <anim/ExpressionParam.h>


namespace synkro
{


namespace anim
{


// Generic expression track implementation.
template <class T, class K, class P, class V, UInt D>
class ExpressionTrackImpl :
	public AnimationTrackImpl<T, D>
{
public:
	// Constructor & destructor.
	ExpressionTrackImpl( const lang::String& name, IExpressionScript* script );
	virtual ~ExpressionTrackImpl();

	// I<V>Track methods.
	virtual void											GetValue( Double time, typename V& value ) const;
	virtual typename K*										AsKeyframed() const;
	virtual typename P*										AsProcedural() const;
	virtual typename T*										AsExpression() const;

	// IExpression<V>Track methods.
	virtual void											SetLength( Double length );
	virtual IExpressionScript*								GetScript() const;

protected:
	P(IExpressionScript)									_script;
	ExpressionParam*										_paramTime;
};


#include "ExpressionTrackImpl.inl"


typedef class ExpressionTrackImpl<IExpressionBoolTrack, IKeyframedBoolTrack, IProceduralBoolTrack, Bool, TYPE_BOOL> ExpressionBoolTrack;
typedef class ExpressionTrackImpl<IExpressionColorTrack, IKeyframedColorTrack, IProceduralColorTrack, img::Color, TYPE_COLOR> ExpressionColorTrack;
typedef class ExpressionTrackImpl<IExpressionColorGradientTrack, IKeyframedColorGradientTrack, IProceduralColorGradientTrack, img::ColorGradient, TYPE_COLOR_GRADIENT> ExpressionColorGradientTrack;
typedef class ExpressionTrackImpl<IExpressionFloatTrack, IKeyframedFloatTrack, IProceduralFloatTrack, Float, TYPE_FLOAT> ExpressionFloatTrack;
typedef class ExpressionTrackImpl<IExpressionFloatRectTrack, IKeyframedFloatRectTrack, IProceduralFloatRectTrack, lang::RectF, TYPE_FLOAT_RECT> ExpressionFloatRectTrack;
typedef class ExpressionTrackImpl<IExpressionIntTrack, IKeyframedIntTrack, IProceduralIntTrack, Int, TYPE_INT> ExpressionIntTrack;
typedef class ExpressionTrackImpl<IExpressionMatrix4x4Track, IKeyframedMatrix4x4Track, IProceduralMatrix4x4Track, math::Matrix4x4, TYPE_MATRIX4X4> ExpressionMatrix4x4Track;
typedef class ExpressionTrackImpl<IExpressionPointTrack, IKeyframedPointTrack, IProceduralPointTrack, lang::Point, TYPE_POINT> ExpressionPointTrack;
typedef class ExpressionTrackImpl<IExpressionQuaternionTrack, IKeyframedQuaternionTrack, IProceduralQuaternionTrack, math::Quaternion, TYPE_QUATERNION> ExpressionQuaternionTrack;
typedef class ExpressionTrackImpl<IExpressionRangeTrack, IKeyframedRangeTrack, IProceduralRangeTrack, lang::Range, TYPE_RANGE> ExpressionRangeTrack;
typedef class ExpressionTrackImpl<IExpressionRectTrack, IKeyframedRectTrack, IProceduralRectTrack, lang::Rect, TYPE_RECT> ExpressionRectTrack;
typedef class ExpressionTrackImpl<IExpressionSizeTrack, IKeyframedSizeTrack, IProceduralSizeTrack, lang::Size, TYPE_SIZE> ExpressionSizeTrack;
typedef class ExpressionTrackImpl<IExpressionVector3Track, IKeyframedVector3Track, IProceduralVector3Track, math::Vector3, TYPE_VECTOR3> ExpressionVector3Track;


} // anim


} // synkro


#endif // _SYNKRO_ANIM_EXPRESSIONTRACKIMPL_
