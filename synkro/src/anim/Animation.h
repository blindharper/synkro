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
// Purpose: Implements generic animation.
//==============================================================================
#ifndef _SYNKRO_ANIM_ANIMATION_
#define _SYNKRO_ANIM_ANIMATION_


#include "config.h"
#include <lang/Map.h>
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <anim/IAnimation.h>
#include "BaseAnimationSystem.h"


namespace synkro
{


namespace anim
{


// Animation implementation.
class Animation :
	public core::ObjectImpl<IAnimation>
{
public:
	// Constructors.
	Animation( BaseAnimationSystem* animationSystem, const lang::String& name );
	Animation( BaseAnimationSystem* animationSystem );

	// IAnimation methods.
	IKeyframedBoolTrack*									CreateBoolTrack( const lang::String& name );
	IExpressionBoolTrack*									CreateBoolTrack( const lang::String& name, IExpressionScript* script );
	IExpressionBoolTrack*									CreateBoolTrack( const lang::String& name, const lang::String& expression );
	IKeyframedColorTrack*									CreateColorTrack( const lang::String& name );
	IExpressionColorTrack*									CreateColorTrack( const lang::String& name, IExpressionScript* script );
	IExpressionColorTrack*									CreateColorTrack( const lang::String& name, const lang::String& expression );
	IProceduralColorTrack*									CreateColorTrack( const lang::String& name, const AnimationTrack& type );	
	IKeyframedColorGradientTrack*							CreateColorGradientTrack( const lang::String& name );
	IExpressionColorGradientTrack*							CreateColorGradientTrack( const lang::String& name, IExpressionScript* script );
	IExpressionColorGradientTrack*							CreateColorGradientTrack( const lang::String& name, const lang::String& expression );
	IKeyframedFloatTrack*									CreateFloatTrack( const lang::String& name );
	IExpressionFloatTrack*									CreateFloatTrack( const lang::String& name, IExpressionScript* script );
	IExpressionFloatTrack*									CreateFloatTrack( const lang::String& name, const lang::String& expression );
	IProceduralFloatTrack*									CreateFloatTrack( const lang::String& name, const AnimationTrack& type );
	IKeyframedFloatRectTrack*								CreateFloatRectTrack( const lang::String& name );
	IExpressionFloatRectTrack*								CreateFloatRectTrack( const lang::String& name, IExpressionScript* script );
	IExpressionFloatRectTrack*								CreateFloatRectTrack( const lang::String& name, const lang::String& expression );
	IKeyframedIntTrack*										CreateIntTrack( const lang::String& name );
	IExpressionIntTrack*									CreateIntTrack( const lang::String& name, IExpressionScript* script );
	IExpressionIntTrack*									CreateIntTrack( const lang::String& name, const lang::String& expression );
	IKeyframedMatrix4x4Track*								CreateMatrix4x4Track( const lang::String& name );
	IExpressionMatrix4x4Track*								CreateMatrix4x4Track( const lang::String& name, IExpressionScript* script );
	IExpressionMatrix4x4Track*								CreateMatrix4x4Track( const lang::String& name, const lang::String& expression );
	IKeyframedPointTrack*									CreatePointTrack( const lang::String& name );
	IExpressionPointTrack*									CreatePointTrack( const lang::String& name, IExpressionScript* script );
	IExpressionPointTrack*									CreatePointTrack( const lang::String& name, const lang::String& expression );
	IKeyframedQuaternionTrack*								CreateQuaternionTrack( const lang::String& name );
	IExpressionQuaternionTrack*								CreateQuaternionTrack( const lang::String& name, IExpressionScript* script );
	IExpressionQuaternionTrack*								CreateQuaternionTrack( const lang::String& name, const lang::String& expression );
	IKeyframedRangeTrack*									CreateRangeTrack( const lang::String& name );
	IExpressionRangeTrack*									CreateRangeTrack( const lang::String& name, IExpressionScript* script );
	IExpressionRangeTrack*									CreateRangeTrack( const lang::String& name, const lang::String& expression );
	IKeyframedRectTrack*									CreateRectTrack( const lang::String& name );
	IExpressionRectTrack*									CreateRectTrack( const lang::String& name, IExpressionScript* script );
	IExpressionRectTrack*									CreateRectTrack( const lang::String& name, const lang::String& expression );
	IKeyframedSizeTrack*									CreateSizeTrack( const lang::String& name );
	IExpressionSizeTrack*									CreateSizeTrack( const lang::String& name, IExpressionScript* script );
	IExpressionSizeTrack*									CreateSizeTrack( const lang::String& name, const lang::String& expression );
	IKeyframedVector3Track*									CreateVector3Track( const lang::String& name );
	IExpressionVector3Track*								CreateVector3Track( const lang::String& name, IExpressionScript* script );
	IExpressionVector3Track*								CreateVector3Track( const lang::String& name, const lang::String& expression );
	IProceduralVector3Track*								CreateVector3Track( const lang::String& name, const AnimationTrack& type );
	UInt													GetTrackCount() const;
	IAnimationTrack*										GetTrack( UInt index ) const;
	IAnimationTrack*										GetTrack( const lang::String& name ) const;
	Double													GetLength() const;
	lang::String											GetName() const;

private:
	typedef lang::MapPair<lang::String, UInt>				IndexEntry;

	BaseAnimationSystem*									_animationSystem;
	lang::Vector<P(IAnimationTrack)>						_tracks;
	lang::MapCI<lang::String, UInt>							_indexes;
	lang::String											_name;

	void													PrepareValidate( IExpressionScript* script, const AnimationDataType& type );
	void													VerifyName( const lang::String& name ) const;
	void													AddTrack( IAnimationTrack* track );
};


#include "Animation.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATION_
