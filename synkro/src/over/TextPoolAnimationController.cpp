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


TextPoolAnimationController::TextPoolAnimationController( ITextPool* pool, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	PlaybackControllerImpl<ITextPoolAnimationController>( animationSystem, animation, listener ),
	_pool( pool )
{
	SetAnimation( _animation );
}

void TextPoolAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<ITextPoolAnimationController>::Update( delta );

	// Update text pool.
	if ( _trackOffset != nullptr )
	{
		Point offset;
		_trackOffset->GetValue( _time, offset );
		_pool->SetOffset( offset );
	}
}

void TextPoolAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	PlaybackControllerImpl<ITextPoolAnimationController>::SetAnimation( animation );

	_trackOffset = GetTrack( _trackOffset, TextPoolProperty::Offset );
}

IKeyframedPointTrack* TextPoolAnimationController::CreateOffsetTrack()
{
	return (_trackOffset = (_trackOffset == nullptr) ? _animation->CreatePointTrack(TextPoolProperty::Offset.ToString()) : _trackOffset)->AsKeyframed();
}


} // over


} // synkro
