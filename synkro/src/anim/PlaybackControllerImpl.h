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
// Purpose: Generic playback animation controller implementation.
//==============================================================================
#ifndef _SYNKRO_ANIM_PLAYBACKCONTROLLERIMPL_
#define _SYNKRO_ANIM_PLAYBACKCONTROLLERIMPL_


#include "config.h"
#include "AnimationControllerImpl.h"
#include "BaseAnimationController.h"
#include "AnimationModeConst.h"
#include <anim/AnimationMode.h>
#include <anim/AnimationDirection.h>
#include <lang/Vector.h>


namespace synkro
{


namespace anim
{


// Generic playback animation controller implementation.
template <class T>
class PlaybackControllerImpl :
	public AnimationControllerImpl<T>,
	public BaseAnimationController
{
public:
	// Constructor & destructor.
	PlaybackControllerImpl( IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener );
	virtual ~PlaybackControllerImpl();

	// IController methods.
	virtual void											Start( Bool start );
	virtual void											Update( Double delta );	

	// IAnimationController methods.
	virtual void											SetAnimations( IAnimationSet* animations );

	// IPlaybackController methods.
	virtual void											SetSpeed( Double speed );
	virtual void											SetOffset( Double offset ) SYNKRO_NOEXCEPT;
	virtual void											SetMode( const AnimationMode& mode ) SYNKRO_NOEXCEPT;
	virtual void											SetDirection( const AnimationDirection& direction ) SYNKRO_NOEXCEPT;
	virtual void											SetLoopCount( UInt loopCount ) SYNKRO_NOEXCEPT;
	virtual Double											GetSpeed() const SYNKRO_NOEXCEPT;
	virtual Double											GetOffset() const SYNKRO_NOEXCEPT;
	virtual AnimationMode									GetMode() const SYNKRO_NOEXCEPT;
	virtual AnimationDirection								GetDirection() const SYNKRO_NOEXCEPT;
	virtual UInt											GetLoopCount() const SYNKRO_NOEXCEPT;
	virtual UInt											GetIteration() const SYNKRO_NOEXCEPT;

	// BaseAnimationController methods.
	virtual void											PostUpdate();

	// Other methods.
	virtual void											UpdateTracks();
	Double													CurrentTime() const SYNKRO_NOEXCEPT;
	void													GetAnimationsLengths();
	void													GetCurrentAnimation();

protected:
	AnimationListener*										_listener;
	AnimationMode											_mode;
	AnimationDirection										_direction;
	Double													_dir;
	Double													_speed;
	Double													_offset;
	Double													_length;
	Double													_currentTime;
	lang::Vector<Double>									_times;
	UInt													_loopCount;
	UInt													_iteration;
	P(IAnimation)											_currentAnimation;

	template<class I, class P>
	I*														GetTrack( I* track, const P& prop );
};


#include "PlaybackControllerImpl.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_PLAYBACKCONTROLLERIMPL_
