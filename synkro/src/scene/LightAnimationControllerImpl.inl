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
// Purpose: Animation controller for generic light source.
//==============================================================================
template <class T>
SYNKRO_INLINE LightAnimationControllerImpl<T>::LightAnimationControllerImpl( ILight* light, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener ) :
	NodeAnimationControllerImpl<T>( light, animationSystem, animation, listener ),
	_light( light )
{
}

template <class T>
SYNKRO_INLINE LightAnimationControllerImpl<T>::~LightAnimationControllerImpl()
{
}

template <class T>
SYNKRO_INLINE void LightAnimationControllerImpl<T>::Update( Double delta )
{
	// Call base implementation.
	NodeAnimationControllerImpl<T>::Update( delta );

	// Update light.
	if ( _trackAvailability != nullptr )
	{
		Bool enabled;
		_trackAvailability->GetValue( _time, enabled );
		_light->Enable( enabled );
	}

	if ( !_light->IsEnabled() )
		return;

	if ( _trackDiffuse != nullptr )
	{
		img::Color color;
		_trackDiffuse->GetValue( _time, color );
		_light->SetDiffuseColor( color );
	}

	if ( _trackAmbient != nullptr )
	{
		img::Color color;
		_trackAmbient->GetValue( _time, color );
		_light->SetAmbientColor( color );
	}

	if ( _trackSpecular != nullptr )
	{
		img::Color color;
		_trackSpecular->GetValue( _time, color );
		_light->SetSpecularColor( color );
	}

	if ( _trackIntensity != nullptr )
	{
		Float intensity;
		_trackIntensity->GetValue( _time, intensity );
		_light->SetIntensity( intensity );
	}
}

template <class T>
SYNKRO_INLINE void LightAnimationControllerImpl<T>::SetAnimation( anim::IAnimation* animation )
{
	// Call base implementation.
	NodeAnimationControllerImpl<T>::SetAnimation( animation );

	_trackDiffuse		= GetTrack( _trackDiffuse, LightProperty::DiffuseColor );
	_trackAmbient		= GetTrack( _trackAmbient, LightProperty::AmbientColor );
	_trackSpecular		= GetTrack( _trackSpecular, LightProperty::SpecularColor );
	_trackIntensity		= GetTrack( _trackIntensity, LightProperty::Intensity );
	_trackAvailability	= GetTrack( _trackAvailability, LightProperty::Availability );	
}

template <class T>
SYNKRO_INLINE ILightAnimationController* LightAnimationControllerImpl<T>::AsLight() const
{
	return (ILightAnimationController*)this;
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* LightAnimationControllerImpl<T>::CreateDiffuseColorTrack()
{
	return (_trackDiffuse = (_trackDiffuse == nullptr) ? _animation->CreateColorTrack(LightProperty::DiffuseColor.ToString()) : _trackDiffuse)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* LightAnimationControllerImpl<T>::CreateDiffuseColorTrack( const anim::AnimationTrack& type )
{
	return (_trackDiffuse = (_trackDiffuse == nullptr) ? _animation->CreateColorTrack(LightProperty::DiffuseColor.ToString(), type) : _trackDiffuse)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* LightAnimationControllerImpl<T>::CreateDiffuseColorTrack( anim::IExpressionScript* script )
{
	return (_trackDiffuse = (_trackDiffuse == nullptr) ? _animation->CreateColorTrack(LightProperty::DiffuseColor.ToString(), script) : _trackDiffuse)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* LightAnimationControllerImpl<T>::CreateDiffuseColorTrack( const lang::String& expression )
{
	return (_trackDiffuse = (_trackDiffuse == nullptr) ? _animation->CreateColorTrack(LightProperty::DiffuseColor.ToString(), expression) : _trackDiffuse)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* LightAnimationControllerImpl<T>::CreateAmbientColorTrack()
{
	return (_trackAmbient = (_trackAmbient == nullptr) ? _animation->CreateColorTrack(LightProperty::AmbientColor.ToString()) : _trackAmbient)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* LightAnimationControllerImpl<T>::CreateAmbientColorTrack( const anim::AnimationTrack& type )
{
	return (_trackAmbient = (_trackAmbient == nullptr) ? _animation->CreateColorTrack(LightProperty::AmbientColor.ToString(), type) : _trackAmbient)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* LightAnimationControllerImpl<T>::CreateAmbientColorTrack( anim::IExpressionScript* script )
{
	return (_trackAmbient = (_trackAmbient == nullptr) ? _animation->CreateColorTrack(LightProperty::AmbientColor.ToString(), script) : _trackAmbient)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* LightAnimationControllerImpl<T>::CreateAmbientColorTrack( const lang::String& expression )
{
	return (_trackAmbient = (_trackAmbient == nullptr) ? _animation->CreateColorTrack(LightProperty::AmbientColor.ToString(), expression) : _trackAmbient)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* LightAnimationControllerImpl<T>::CreateSpecularColorTrack()
{
	return (_trackSpecular = (_trackSpecular == nullptr) ? _animation->CreateColorTrack(LightProperty::SpecularColor.ToString()) : _trackSpecular)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* LightAnimationControllerImpl<T>::CreateSpecularColorTrack( const anim::AnimationTrack& type )
{
	return (_trackSpecular = (_trackSpecular == nullptr) ? _animation->CreateColorTrack(LightProperty::SpecularColor.ToString(), type) : _trackSpecular)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* LightAnimationControllerImpl<T>::CreateSpecularColorTrack( anim::IExpressionScript* script )
{
	return (_trackSpecular = (_trackSpecular == nullptr) ? _animation->CreateColorTrack(LightProperty::SpecularColor.ToString(), script) : _trackSpecular)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* LightAnimationControllerImpl<T>::CreateSpecularColorTrack( const lang::String& expression )
{
	return (_trackSpecular = (_trackSpecular == nullptr) ? _animation->CreateColorTrack(LightProperty::SpecularColor.ToString(), expression) : _trackSpecular)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* LightAnimationControllerImpl<T>::CreateIntensityTrack()
{
	return (_trackIntensity = (_trackIntensity == nullptr) ? _animation->CreateFloatTrack(LightProperty::Intensity.ToString()) : _trackIntensity)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* LightAnimationControllerImpl<T>::CreateIntensityTrack( const anim::AnimationTrack& type )
{
	return (_trackIntensity = (_trackIntensity == nullptr) ? _animation->CreateFloatTrack(LightProperty::Intensity.ToString(), type) : _trackIntensity)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* LightAnimationControllerImpl<T>::CreateIntensityTrack( anim::IExpressionScript* script )
{
	return (_trackIntensity = (_trackIntensity == nullptr) ? _animation->CreateFloatTrack(LightProperty::Intensity.ToString(), script) : _trackIntensity)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* LightAnimationControllerImpl<T>::CreateIntensityTrack( const lang::String& expression )
{
	return (_trackIntensity = (_trackIntensity == nullptr) ? _animation->CreateFloatTrack(LightProperty::Intensity.ToString(), expression) : _trackIntensity)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedBoolTrack* LightAnimationControllerImpl<T>::CreateAvailabilityTrack()
{
	return (_trackAvailability = (_trackAvailability == nullptr) ? _animation->CreateBoolTrack(LightProperty::Availability.ToString()) : _trackAvailability)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE IConeLightAnimationController* LightAnimationControllerImpl<T>::AsCone() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IOmniLightAnimationController* LightAnimationControllerImpl<T>::AsOmni() const
{
	return nullptr;
}
