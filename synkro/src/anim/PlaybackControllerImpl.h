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
	PlaybackControllerImpl( IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener );
	virtual ~PlaybackControllerImpl();

	// IController methods.
	virtual void											Start( Bool start );
	virtual void											Update( Double delta );	

	// IPlaybackController methods.
	virtual void											SetSpeed( Double speed );
	virtual void											SetOffset( Double offset );
	virtual void											SetMode( const AnimationMode& mode );
	virtual void											SetDirection( const AnimationDirection& direction );
	virtual void											SetLoopCount( UInt loopCount );
	virtual Double											GetSpeed() const;
	virtual Double											GetOffset() const;
	virtual AnimationMode									GetMode() const;
	virtual AnimationDirection								GetDirection() const;
	virtual UInt											GetLoopCount() const;
	virtual UInt											GetIteration() const;

	// BaseAnimationController methods.
	void													PostUpdate();

protected:
	AnimationListener*										_listener;
	AnimationMode											_mode;
	AnimationDirection										_direction;
	Double													_dir;
	Double													_speed;
	Double													_offset;
	Double													_length;
	UInt													_loopCount;
	UInt													_iteration;

	template<class I, class P>
	I*														GetTrack( I* track, const P& prop );
};


#include "PlaybackControllerImpl.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_PLAYBACKCONTROLLERIMPL_
