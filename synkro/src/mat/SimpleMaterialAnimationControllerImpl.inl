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
// Purpose: Animation controller for generic simple material.
//==============================================================================
template <class T>
SYNKRO_INLINE SimpleMaterialAnimationControllerImpl<T>::SimpleMaterialAnimationControllerImpl( ISimpleMaterial* material, anim::IAnimationSystem* animationSystem, anim::IAnimationSet* animations, anim::AnimationListener* listener ) :
	anim::PlaybackControllerImpl<T>( animationSystem, animations, listener ),
	_material( material ),
	_trackDiffuse( nullptr ),
	_trackAmbient( nullptr ),
	_trackEmissive( nullptr ),
	_trackSpecular( nullptr ),
	_trackSpecularPower( nullptr )
{
}

template <class T>
SYNKRO_INLINE SimpleMaterialAnimationControllerImpl<T>::~SimpleMaterialAnimationControllerImpl()
{
}

template <class T>
SYNKRO_INLINE void SimpleMaterialAnimationControllerImpl<T>::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<T>::Update( delta );

	// Update material.
	if ( _trackDiffuse != nullptr )
	{
		img::Color diffuse;
		_trackDiffuse->GetValue( CurrentTime(), diffuse );
		_material->SetDiffuseColor( diffuse );
	}

	if ( _trackAmbient != nullptr )
	{
		img::Color ambient;
		_trackAmbient->GetValue( CurrentTime(), ambient );
		_material->SetAmbientColor( ambient );
	}

	if ( _trackEmissive != nullptr )
	{
		img::Color emissive;
		_trackEmissive->GetValue( CurrentTime(), emissive );
		_material->SetEmissiveColor( emissive );
	}

	if ( _trackSpecular != nullptr )
	{
		img::Color specular;
		_trackSpecular->GetValue( CurrentTime(), specular );
		_material->SetSpecularColor( specular );
	}

	if ( _trackSpecularPower != nullptr )
	{
		Float power;
		_trackSpecularPower->GetValue( CurrentTime(), power );
		_material->SetSpecularPower( power );
	}
}

template <class T>
SYNKRO_INLINE ISimpleMaterialAnimationController* SimpleMaterialAnimationControllerImpl<T>::AsSimple() const
{
	return (ISimpleMaterialAnimationController*)this;
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateDiffuseColorTrack()
{
	return (_trackDiffuse = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::DiffuseColor.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateDiffuseColorTrack( const anim::AnimationTrack& type )
{
	return (_trackDiffuse = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::DiffuseColor.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateDiffuseColorTrack( anim::IExpressionScript* script )
{
	return (_trackDiffuse = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::DiffuseColor.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateDiffuseColorTrack( const lang::String& expression )
{
	return (_trackDiffuse = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::DiffuseColor.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateAmbientColorTrack()
{
	return (_trackAmbient = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::AmbientColor.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateAmbientColorTrack( const anim::AnimationTrack& type )
{
	return (_trackAmbient = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::AmbientColor.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateAmbientColorTrack( anim::IExpressionScript* script )
{
	return (_trackAmbient = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::AmbientColor.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateAmbientColorTrack( const lang::String& expression )
{
	return (_trackAmbient = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::AmbientColor.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateEmissiveColorTrack()
{
	return (_trackEmissive = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::EmissiveColor.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateEmissiveColorTrack( const anim::AnimationTrack& type )
{
	return (_trackEmissive = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::EmissiveColor.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateEmissiveColorTrack( anim::IExpressionScript* script )
{
	return (_trackEmissive = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::EmissiveColor.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateEmissiveColorTrack( const lang::String& expression )
{
	return (_trackEmissive = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::EmissiveColor.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularColorTrack()
{
	return (_trackSpecular = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::SpecularColor.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularColorTrack( const anim::AnimationTrack& type )
{
	return (_trackSpecular = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::SpecularColor.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularColorTrack( anim::IExpressionScript* script )
{
	return (_trackSpecular = _animations->GetActiveAnimation()->CreateColorTrack(SimpleMaterialProperty::SpecularColor.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularColorTrack( const lang::String& expression )
{
	return (_trackSpecular = _animations->GetActiveAnimation()->CreateColorTrack( SimpleMaterialProperty::SpecularColor.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularPowerTrack()
{
	return (_trackSpecularPower = _animations->GetActiveAnimation()->CreateFloatTrack( SimpleMaterialProperty::SpecularPower.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularPowerTrack( const anim::AnimationTrack& type )
{
	return (_trackSpecularPower = _animations->GetActiveAnimation()->CreateFloatTrack( SimpleMaterialProperty::SpecularPower.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularPowerTrack( anim::IExpressionScript* script )
{
	return (_trackSpecularPower = _animations->GetActiveAnimation()->CreateFloatTrack( SimpleMaterialProperty::SpecularPower.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularPowerTrack( const lang::String& expression )
{
	return (_trackSpecularPower = _animations->GetActiveAnimation()->CreateFloatTrack( SimpleMaterialProperty::SpecularPower.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE ITransparentMaterialAnimationController* SimpleMaterialAnimationControllerImpl<T>::AsTransparent() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE void SimpleMaterialAnimationControllerImpl<T>::UpdateTracks()
{
	_trackDiffuse		= GetTrack( _trackDiffuse, SimpleMaterialProperty::DiffuseColor );
	_trackAmbient		= GetTrack( _trackAmbient, SimpleMaterialProperty::AmbientColor );
	_trackEmissive		= GetTrack( _trackEmissive, SimpleMaterialProperty::EmissiveColor );
	_trackSpecular		= GetTrack( _trackSpecular, SimpleMaterialProperty::SpecularColor );
	_trackSpecularPower	= GetTrack( _trackSpecularPower, SimpleMaterialProperty::SpecularPower );
}
