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
// Purpose: Implements animation set.
//==============================================================================
#ifndef _SYNKRO_ANIM_ANIMATIONSET_
#define _SYNKRO_ANIM_ANIMATIONSET_


#include "config.h"
#include <lang/Map.h>
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <anim/IAnimationSet.h>
#include <anim/IAnimation.h>
#include "BaseAnimationSystem.h"


namespace synkro
{


namespace anim
{


// Animation set implementation.
class AnimationSet :
	public core::ObjectImpl<IAnimationSet>
{
public:
	// Constructor.
	AnimationSet( BaseAnimationSystem* animationSystem, const lang::String& name );

	// IAnimationSet methods.
	void													Save( io::IStream* stream, const AnimationCodec& type );
	void													Save( io::IStream* stream );
	void													SaveAsync( io::IStream* stream, const AnimationCodec& type );
	void													SaveAsync( io::IStream* stream );
	IAnimation*												CreateAnimation( const lang::String& name );
	UInt													GetAnimationCount() const;
	IAnimation*												GetAnimation( UInt index ) const;
	IAnimation*												GetAnimation( const lang::String& name ) const;
	lang::String											GetName() const;

private:
	typedef lang::MapPair<lang::String, UInt>				IndexEntry;

	lang::Vector<P(IAnimation)>								_animations;
	lang::MapCI<lang::String, UInt>						_indexes;
	BaseAnimationSystem*									_animationSystem;
	lang::String											_name;
};


#include "AnimationSet.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATIONSET_
