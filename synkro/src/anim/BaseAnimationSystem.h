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
// Purpose: Base animation system.
//==============================================================================
#ifndef _SYNKRO_ANIM_BASEANIMATIONSYSTEM_
#define _SYNKRO_ANIM_BASEANIMATIONSYSTEM_


#include "config.h"
#include <anim/AnimationCodec.h>
#include <anim/AnimationTrack.h>
#include <anim/AnimationDataType.h>


namespace synkro
{


namespace anim
{


// Base animation system.
class BaseAnimationSystem
{
public:
	virtual void											AddController( IPlaybackAnimationController* controller ) = 0;
	virtual void											AddController( IRecordAnimationController* controller ) = 0;
	virtual void											RemoveController( IPlaybackAnimationController* controller ) = 0;
	virtual void											RemoveController( IRecordAnimationController* controller ) = 0;
	virtual void											AddStopEvent( IAnimationController* sender, AnimationListener* listener ) = 0;
	virtual void											AddLoopEvent( IAnimationController* sender, AnimationListener* listener ) = 0;
	virtual IExpressionScript*								CreateScriptInternal( const lang::String& expression ) = 0;
	virtual IAnimationTrack*								CreateTrack( const lang::String& name, const AnimationTrack& type, const AnimationDataType& dataType ) = 0;
	virtual void											SaveAnimation( const IAnimationSet* animation, io::IStream* stream, const AnimationCodec& type ) = 0;
	virtual void											SaveAnimation( const IAnimationSet* animation, io::IStream* stream ) = 0;
	virtual void											SaveAnimationAsync( const IAnimationSet* animation, io::IStream* stream, const AnimationCodec& type ) = 0;
	virtual void											SaveAnimationAsync( const IAnimationSet* animation, io::IStream* stream ) = 0;
};


// Casts object to BaseAnimationSystem.
#define AsBaseAnimationSystem( OBJ ) dynamic_cast<BaseAnimationSystem*>( OBJ )


} // anim


} // synkro


#endif // _SYNKRO_ANIM_BASEANIMATIONSYSTEM_
