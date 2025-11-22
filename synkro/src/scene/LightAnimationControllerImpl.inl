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
SYNKRO_INLINE LightAnimationControllerImpl<T>::LightAnimationControllerImpl( ILight* light, anim::IAnimationSystem* animationSystem, anim::IAnimationSet* animations, anim::AnimationListener* listener ) :
	NodeAnimationControllerImpl<T>( light, animationSystem, animations, listener ),
	_light( light ),
	_trackDiffuse( nullptr ),
	_trackAmbient( nullptr ),
	_trackSpecular( nullptr ),
	_trackIntensity( nullptr ),
	_trackAvailability( nullptr )
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
		_trackAvailability->GetValue( CurrentTime(), enabled );
		_light->Enable( enabled );
	}

	if ( !_light->IsEnabled() )
		return;

	if ( _trackDiffuse != nullptr )
	{
		img::Color color;
		_trackDiffuse->GetValue( CurrentTime(), color );
		_light->SetDiffuseColor( color );
	}

	if ( _trackAmbient != nullptr )
	{
		img::Color color;
		_trackAmbient->GetValue( CurrentTime(), color );
		_light->SetAmbientColor( color );
	}

	if ( _trackSpecular != nullptr )
	{
		img::Color color;
		_trackSpecular->GetValue( CurrentTime(), color );
		_light->SetSpecularColor( color );
	}

	if ( _trackIntensity != nullptr )
	{
		Float intensity;
		_trackIntensity->GetValue( CurrentTime(), intensity );
		_light->SetIntensity( intensity );
	}
}

template <class T>
SYNKRO_INLINE ILightAnimationController* LightAnimationControllerImpl<T>::AsLight() const
{
	return (ILightAnimationController*)this;
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* LightAnimationControllerImpl<T>::CreateDiffuseColorTrack()
{
	return (_trackDiffuse = _animations->GetActiveAnimation()->CreateColorTrack( LightProperty::DiffuseColor.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* LightAnimationControllerImpl<T>::CreateDiffuseColorTrack( const anim::AnimationTrack& type )
{
	return (_trackDiffuse = _animations->GetActiveAnimation()->CreateColorTrack( LightProperty::DiffuseColor.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* LightAnimationControllerImpl<T>::CreateDiffuseColorTrack( anim::IExpressionScript* script )
{
	return (_trackDiffuse = _animations->GetActiveAnimation()->CreateColorTrack( LightProperty::DiffuseColor.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* LightAnimationControllerImpl<T>::CreateDiffuseColorTrack( const lang::String& expression )
{
	return (_trackDiffuse = _animations->GetActiveAnimation()->CreateColorTrack( LightProperty::DiffuseColor.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* LightAnimationControllerImpl<T>::CreateAmbientColorTrack()
{
	return (_trackAmbient = _animations->GetActiveAnimation()->CreateColorTrack( LightProperty::AmbientColor.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* LightAnimationControllerImpl<T>::CreateAmbientColorTrack( const anim::AnimationTrack& type )
{
	return (_trackAmbient = _animations->GetActiveAnimation()->CreateColorTrack( LightProperty::AmbientColor.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* LightAnimationControllerImpl<T>::CreateAmbientColorTrack( anim::IExpressionScript* script )
{
	return (_trackAmbient = _animations->GetActiveAnimation()->CreateColorTrack( LightProperty::AmbientColor.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* LightAnimationControllerImpl<T>::CreateAmbientColorTrack( const lang::String& expression )
{
	return (_trackAmbient = _animations->GetActiveAnimation()->CreateColorTrack( LightProperty::AmbientColor.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* LightAnimationControllerImpl<T>::CreateSpecularColorTrack()
{
	return (_trackSpecular = _animations->GetActiveAnimation()->CreateColorTrack( LightProperty::SpecularColor.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* LightAnimationControllerImpl<T>::CreateSpecularColorTrack( const anim::AnimationTrack& type )
{
	return (_trackSpecular = _animations->GetActiveAnimation()->CreateColorTrack( LightProperty::SpecularColor.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* LightAnimationControllerImpl<T>::CreateSpecularColorTrack( anim::IExpressionScript* script )
{
	return (_trackSpecular = _animations->GetActiveAnimation()->CreateColorTrack( LightProperty::SpecularColor.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* LightAnimationControllerImpl<T>::CreateSpecularColorTrack( const lang::String& expression )
{
	return (_trackSpecular = _animations->GetActiveAnimation()->CreateColorTrack( LightProperty::SpecularColor.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* LightAnimationControllerImpl<T>::CreateIntensityTrack()
{
	return (_trackIntensity = _animations->GetActiveAnimation()->CreateFloatTrack( LightProperty::Intensity.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* LightAnimationControllerImpl<T>::CreateIntensityTrack( const anim::AnimationTrack& type )
{
	return (_trackIntensity = _animations->GetActiveAnimation()->CreateFloatTrack( LightProperty::Intensity.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* LightAnimationControllerImpl<T>::CreateIntensityTrack( anim::IExpressionScript* script )
{
	return (_trackIntensity = _animations->GetActiveAnimation()->CreateFloatTrack( LightProperty::Intensity.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* LightAnimationControllerImpl<T>::CreateIntensityTrack( const lang::String& expression )
{
	return (_trackIntensity = _animations->GetActiveAnimation()->CreateFloatTrack( LightProperty::Intensity.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedBoolTrack* LightAnimationControllerImpl<T>::CreateAvailabilityTrack()
{
	return (_trackAvailability = _animations->GetActiveAnimation()->CreateBoolTrack( LightProperty::Availability.ToString()) )->AsKeyframed();
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

template <class T>
SYNKRO_INLINE void LightAnimationControllerImpl<T>::UpdateTracks()
{
	// Call base implementation.
	NodeAnimationControllerImpl<T>::UpdateTracks();

	_trackDiffuse		= GetTrack( _trackDiffuse, LightProperty::DiffuseColor );
	_trackAmbient		= GetTrack( _trackAmbient, LightProperty::AmbientColor );
	_trackSpecular		= GetTrack( _trackSpecular, LightProperty::SpecularColor );
	_trackIntensity		= GetTrack( _trackIntensity, LightProperty::Intensity );
	_trackAvailability	= GetTrack( _trackAvailability, LightProperty::Availability );	
}
