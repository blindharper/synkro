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
// Purpose: Animation controller for scene.
//==============================================================================
#include "config.h"
#include "SceneAnimationController.h"
#include "SceneProperty.h"
#include <scene/ISceneEx.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


SceneAnimationController::SceneAnimationController( ISceneEx* scene, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	PlaybackControllerImpl<ISceneAnimationController>( animationSystem, animation, listener ),
	_scene( scene )
{
	SetAnimation( _animation );
}

void SceneAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<ISceneAnimationController>::Update( delta );

	// Update scene.
	if ( _trackAmbientColor != nullptr )
	{
		Color color;
		_trackAmbientColor->GetValue( _time, color );
		_scene->SetAmbientLightColor( color );
	}

	if ( _trackAmbientIntensity != nullptr )
	{
		Float intensity;
		_trackAmbientIntensity->GetValue( _time, intensity );
		_scene->SetAmbientLightIntensity( intensity );
	}
}

void SceneAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	PlaybackControllerImpl<ISceneAnimationController>::SetAnimation( animation );

	_trackAmbientColor		= GetTrack( _trackAmbientColor, SceneProperty::AmbientLightColor );
	_trackAmbientIntensity	= GetTrack( _trackAmbientIntensity, SceneProperty::AmbientLightIntensity );
}

IKeyframedColorTrack* SceneAnimationController::CreateAmbientLightColorTrack()
{
	return (_trackAmbientColor = (_trackAmbientColor == nullptr) ? _animation->CreateColorTrack(SceneProperty::AmbientLightColor.ToString()) : _trackAmbientColor)->AsKeyframed();
}

IProceduralColorTrack* SceneAnimationController::CreateAmbientLightColorTrack( const AnimationTrack& type )
{
	return (_trackAmbientColor = (_trackAmbientColor == nullptr) ? _animation->CreateColorTrack(SceneProperty::AmbientLightColor.ToString(), type) : _trackAmbientColor)->AsProcedural();
}

IExpressionColorTrack* SceneAnimationController::CreateAmbientLightColorTrack( IExpressionScript* script )
{
	return (_trackAmbientColor = (_trackAmbientColor == nullptr) ? _animation->CreateColorTrack(SceneProperty::AmbientLightColor.ToString(), script) : _trackAmbientColor)->AsExpression();
}

IExpressionColorTrack* SceneAnimationController::CreateAmbientLightColorTrack( const String& expression )
{
	return (_trackAmbientColor = (_trackAmbientColor == nullptr) ? _animation->CreateColorTrack(SceneProperty::AmbientLightColor.ToString(), expression) : _trackAmbientColor)->AsExpression();
}

IKeyframedFloatTrack* SceneAnimationController::CreateAmbientLightIntensityTrack()
{
	return (_trackAmbientIntensity = (_trackAmbientIntensity == nullptr) ? _animation->CreateFloatTrack(SceneProperty::AmbientLightIntensity.ToString()) : _trackAmbientIntensity)->AsKeyframed();
}

IProceduralFloatTrack* SceneAnimationController::CreateAmbientLightIntensityTrack( const AnimationTrack& type )
{
	return (_trackAmbientIntensity = (_trackAmbientIntensity == nullptr) ? _animation->CreateFloatTrack(SceneProperty::AmbientLightIntensity.ToString(), type) : _trackAmbientIntensity)->AsProcedural();
}

IExpressionFloatTrack* SceneAnimationController::CreateAmbientLightIntensityTrack( IExpressionScript* script )
{
	return (_trackAmbientIntensity = (_trackAmbientIntensity == nullptr) ? _animation->CreateFloatTrack(SceneProperty::AmbientLightIntensity.ToString(), script) : _trackAmbientIntensity)->AsExpression();
}

IExpressionFloatTrack* SceneAnimationController::CreateAmbientLightIntensityTrack( const String& expression )
{
	return (_trackAmbientIntensity = (_trackAmbientIntensity == nullptr) ? _animation->CreateFloatTrack(SceneProperty::AmbientLightIntensity.ToString(), expression) : _trackAmbientIntensity)->AsExpression();
}


} // scene


} // synkro
