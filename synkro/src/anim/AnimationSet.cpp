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
#include "config.h"
#include "AnimationSet.h"
#include "Animation.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


AnimationSet::AnimationSet( BaseAnimationSystem* animationSystem, const String& name ) :
	_animations( A(P(IAnimation)) ),
	_indexes( A(IndexEntry) ),
	_animationSystem( animationSystem ),
	_name( name )
{
}

void AnimationSet::Save( IStream* stream, const AnimationCodec& type )
{
	_animationSystem->SaveAnimation( this, stream, type );
}

void AnimationSet::Save( IStream* stream )
{
	_animationSystem->SaveAnimation( this, stream );
}

void AnimationSet::SaveAsync( IStream* stream, const AnimationCodec& type )
{
	_animationSystem->SaveAnimationAsync( this, stream, type );
}

void AnimationSet::SaveAsync( IStream* stream )
{
	_animationSystem->SaveAnimationAsync( this, stream );
}

IAnimation* AnimationSet::CreateAnimation( const String& name )
{
	IAnimation* animation = new Animation( _animationSystem, name );
	_indexes[name] = _animations.Size();
	_animations.Add( animation );
	return animation;
}


} // anim


} // synkro
