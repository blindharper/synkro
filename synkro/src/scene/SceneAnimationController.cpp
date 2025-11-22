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


SceneAnimationController::SceneAnimationController( ISceneEx* scene, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	PlaybackControllerImpl<ISceneAnimationController>( animationSystem, animations, listener ),
	_scene( scene ),
	_trackAmbientColor( nullptr ),
	_trackAmbientIntensity( nullptr )
{
}

void SceneAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<ISceneAnimationController>::Update( delta );

	// Update scene.
	if ( _trackAmbientColor != nullptr )
	{
		Color color;
		_trackAmbientColor->GetValue( CurrentTime(), color );
		_scene->SetAmbientLightColor( color );
	}

	if ( _trackAmbientIntensity != nullptr )
	{
		Float intensity;
		_trackAmbientIntensity->GetValue( CurrentTime(), intensity );
		_scene->SetAmbientLightIntensity( intensity );
	}
}

IKeyframedColorTrack* SceneAnimationController::CreateAmbientLightColorTrack()
{
	return (_trackAmbientColor = _animations->GetActiveAnimation()->CreateColorTrack( SceneProperty::AmbientLightColor.ToString()) )->AsKeyframed();
}

IProceduralColorTrack* SceneAnimationController::CreateAmbientLightColorTrack( const AnimationTrack& type )
{
	return (_trackAmbientColor = _animations->GetActiveAnimation()->CreateColorTrack( SceneProperty::AmbientLightColor.ToString(), type) )->AsProcedural();
}

IExpressionColorTrack* SceneAnimationController::CreateAmbientLightColorTrack( IExpressionScript* script )
{
	return (_trackAmbientColor = _animations->GetActiveAnimation()->CreateColorTrack( SceneProperty::AmbientLightColor.ToString(), script) )->AsExpression();
}

IExpressionColorTrack* SceneAnimationController::CreateAmbientLightColorTrack( const String& expression )
{
	return (_trackAmbientColor = _animations->GetActiveAnimation()->CreateColorTrack( SceneProperty::AmbientLightColor.ToString(), expression) )->AsExpression();
}

IKeyframedFloatTrack* SceneAnimationController::CreateAmbientLightIntensityTrack()
{
	return (_trackAmbientIntensity = _animations->GetActiveAnimation()->CreateFloatTrack( SceneProperty::AmbientLightIntensity.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* SceneAnimationController::CreateAmbientLightIntensityTrack( const AnimationTrack& type )
{
	return (_trackAmbientIntensity = _animations->GetActiveAnimation()->CreateFloatTrack( SceneProperty::AmbientLightIntensity.ToString(), type) )->AsProcedural();
}

IExpressionFloatTrack* SceneAnimationController::CreateAmbientLightIntensityTrack( IExpressionScript* script )
{
	return (_trackAmbientIntensity = _animations->GetActiveAnimation()->CreateFloatTrack( SceneProperty::AmbientLightIntensity.ToString(), script) )->AsExpression();
}

IExpressionFloatTrack* SceneAnimationController::CreateAmbientLightIntensityTrack( const String& expression )
{
	return (_trackAmbientIntensity = _animations->GetActiveAnimation()->CreateFloatTrack( SceneProperty::AmbientLightIntensity.ToString(), expression) )->AsExpression();
}

void SceneAnimationController::UpdateTracks()
{
	_trackAmbientColor		= GetTrack( _trackAmbientColor, SceneProperty::AmbientLightColor );
	_trackAmbientIntensity	= GetTrack( _trackAmbientIntensity, SceneProperty::AmbientLightIntensity );
}


} // scene


} // synkro
