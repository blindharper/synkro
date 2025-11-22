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
// Purpose: Animation controller for transparent material.
//==============================================================================
#include "config.h"
#include "TransparentMaterialAnimationController.h"
#include "TransparentMaterialProperty.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace mat
{


TransparentMaterialAnimationController::TransparentMaterialAnimationController( ITransparentMaterial* transparentMaterial, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	SimpleMaterialAnimationControllerImpl<ITransparentMaterialAnimationController>( transparentMaterial, animationSystem, animations, listener ),
	_transparentMaterial( transparentMaterial ),
	_trackOpacity( nullptr )
{
}

void TransparentMaterialAnimationController::Update( Double delta )
{
	// Call base implementation.
	SimpleMaterialAnimationControllerImpl<ITransparentMaterialAnimationController>::Update( delta );

	// Update material.
	if ( _trackOpacity != nullptr )
	{
		Float opacity;
		_trackOpacity->GetValue( CurrentTime(), opacity );
		_transparentMaterial->SetOpacity( opacity );
	}
}

ITransparentMaterialAnimationController* TransparentMaterialAnimationController::AsTransparent() const
{
	return (ITransparentMaterialAnimationController*)this;
}

IKeyframedFloatTrack* TransparentMaterialAnimationController::CreateOpacityTrack()
{
	return (_trackOpacity = _animations->GetActiveAnimation()->CreateFloatTrack( TransparentMaterialProperty::Opacity.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* TransparentMaterialAnimationController::CreateOpacityTrack( const AnimationTrack& type )
{
	return (_trackOpacity = _animations->GetActiveAnimation()->CreateFloatTrack( TransparentMaterialProperty::Opacity.ToString(), type) )->AsProcedural();
}

IExpressionFloatTrack* TransparentMaterialAnimationController::CreateOpacityTrack( IExpressionScript* script )
{
	return (_trackOpacity = _animations->GetActiveAnimation()->CreateFloatTrack( TransparentMaterialProperty::Opacity.ToString(), script) )->AsExpression();
}

IExpressionFloatTrack* TransparentMaterialAnimationController::CreateOpacityTrack( const String& expression )
{
	return (_trackOpacity = _animations->GetActiveAnimation()->CreateFloatTrack( TransparentMaterialProperty::Opacity.ToString(), expression) )->AsExpression();
}

void TransparentMaterialAnimationController::UpdateTracks()
{
	// Call base implementation.
	SimpleMaterialAnimationControllerImpl<ITransparentMaterialAnimationController>::UpdateTracks();

	_trackOpacity = GetTrack( _trackOpacity, TransparentMaterialProperty::Opacity );
}


} // mat


} // synkro
