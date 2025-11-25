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
	AnimationSet( BaseAnimationSystem* animationSystem, const lang::String& name ) SYNKRO_NOEXCEPT;

	// IAnimationSet methods.
	void													Save( io::IStream* stream, const AnimationCodec& type );
	void													Save( io::IStream* stream );
	void													SaveAsync( io::IStream* stream, const AnimationCodec& type );
	void													SaveAsync( io::IStream* stream );
	IAnimation*												CreateAnimation( const lang::String& name );
	IAnimation*												GetActiveAnimation() const SYNKRO_NOEXCEPT;
	UInt													GetAnimationCount() const SYNKRO_NOEXCEPT;
	IAnimation*												GetAnimation( UInt index ) const;
	IAnimation*												GetAnimation( const lang::String& name ) const;
	Double													GetLength() const SYNKRO_NOEXCEPT;
	lang::String											GetName() const SYNKRO_NOEXCEPT;

private:
	typedef lang::MapPair<lang::String, UInt>				IndexEntry;

	lang::Vector<P(IAnimation)>								_animations;
	lang::MapCI<lang::String, UInt>							_indexes;
	BaseAnimationSystem*									_animationSystem;
	P(IAnimation)											_activeAnimation;
	lang::String											_name;
};


#include "AnimationSet.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATIONSET_
