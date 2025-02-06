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
// Purpose: Animation controller for text pool.
//==============================================================================
#ifndef _SYNKRO_OVER_TEXTPOOLANIMATIONCONTROLLER_
#define _SYNKRO_OVER_TEXTPOOLANIMATIONCONTROLLER_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include <over/ITextPoolAnimationController.h>


namespace synkro
{


namespace over
{


// Animation controller for text.
class TextPoolAnimationController :
	public anim::PlaybackControllerImpl<ITextPoolAnimationController>
{
public:
	// Constructor.
	TextPoolAnimationController( ITextPool* pool, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// ITextPoolAnimationController methods.
	anim::IKeyframedPointTrack*								CreateOffsetTrack();

private:
	ITextPool*												_pool;
	anim::IAnimationPointTrack*								_trackOffset;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_TEXTPOOLANIMATIONCONTROLLER_
