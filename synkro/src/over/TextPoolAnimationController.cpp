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
#include "config.h"
#include "TextPoolAnimationController.h"
#include "TextPoolProperty.h"
#include <over/ITextPool.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace over
{


TextPoolAnimationController::TextPoolAnimationController( ITextPool* pool, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	PlaybackControllerImpl<ITextPoolAnimationController>( animationSystem, animations, listener ),
	_pool( pool ),
	_trackOffset( nullptr )
{
}

void TextPoolAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<ITextPoolAnimationController>::Update( delta );

	// Update text pool.
	if ( _trackOffset != nullptr )
	{
		Point offset;
		_trackOffset->GetValue( CurrentTime(), offset );
		_pool->SetOffset( offset );
	}
}

IKeyframedPointTrack* TextPoolAnimationController::CreateOffsetTrack()
{
	return (_trackOffset = _animations->GetActiveAnimation()->CreatePointTrack(TextPoolProperty::Offset.ToString()))->AsKeyframed();
}

void TextPoolAnimationController::UpdateTracks()
{
	_trackOffset = GetTrack( _trackOffset, TextPoolProperty::Offset );
}


} // over


} // synkro
