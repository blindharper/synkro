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
SYNKRO_INLINE SimpleMaterialAnimationControllerImpl<T>::SimpleMaterialAnimationControllerImpl( ISimpleMaterial* material, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener ) :
	anim::PlaybackControllerImpl<T>( animationSystem, animation, listener ),
	_material( material )
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
		_trackDiffuse->GetValue( _time, diffuse );
		_material->SetDiffuseColor( diffuse );
	}

	if ( _trackAmbient != nullptr )
	{
		img::Color ambient;
		_trackAmbient->GetValue( _time, ambient );
		_material->SetAmbientColor( ambient );
	}

	if ( _trackEmissive != nullptr )
	{
		img::Color emissive;
		_trackEmissive->GetValue( _time, emissive );
		_material->SetEmissiveColor( emissive );
	}

	if ( _trackSpecular != nullptr )
	{
		img::Color specular;
		_trackSpecular->GetValue( _time, specular );
		_material->SetSpecularColor( specular );
	}

	if ( _trackSpecularPower != nullptr )
	{
		Float power;
		_trackSpecularPower->GetValue( _time, power );
		_material->SetSpecularPower( power );
	}
}

template <class T>
SYNKRO_INLINE void SimpleMaterialAnimationControllerImpl<T>::SetAnimation( anim::IAnimation* animation )
{
	// Call base implementation.
	anim::PlaybackControllerImpl<T>::SetAnimation( animation );

	_trackDiffuse		= GetTrack( _trackDiffuse, SimpleMaterialProperty::DiffuseColor );
	_trackAmbient		= GetTrack( _trackAmbient, SimpleMaterialProperty::AmbientColor );
	_trackEmissive		= GetTrack( _trackEmissive, SimpleMaterialProperty::EmissiveColor );
	_trackSpecular		= GetTrack( _trackSpecular, SimpleMaterialProperty::SpecularColor );
	_trackSpecularPower	= GetTrack( _trackSpecularPower, SimpleMaterialProperty::SpecularPower );
}

template <class T>
SYNKRO_INLINE ISimpleMaterialAnimationController* SimpleMaterialAnimationControllerImpl<T>::AsSimple() const
{
	return (ISimpleMaterialAnimationController*)this;
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateDiffuseColorTrack()
{
	return (_trackDiffuse = (_trackDiffuse == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::DiffuseColor.ToString()) : _trackDiffuse)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateDiffuseColorTrack( const anim::AnimationTrack& type )
{
	return (_trackDiffuse = (_trackDiffuse == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::DiffuseColor.ToString(), type) : _trackDiffuse)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateDiffuseColorTrack( anim::IExpressionScript* script )
{
	return (_trackDiffuse = (_trackDiffuse == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::DiffuseColor.ToString(), script) : _trackDiffuse)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateDiffuseColorTrack( const lang::String& expression )
{
	return (_trackDiffuse = (_trackDiffuse == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::DiffuseColor.ToString(), expression) : _trackDiffuse)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateAmbientColorTrack()
{
	return (_trackAmbient = (_trackAmbient == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::AmbientColor.ToString()) : _trackAmbient)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateAmbientColorTrack( const anim::AnimationTrack& type )
{
	return (_trackAmbient = (_trackAmbient == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::AmbientColor.ToString(), type) : _trackAmbient)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateAmbientColorTrack( anim::IExpressionScript* script )
{
	return (_trackAmbient = (_trackAmbient == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::AmbientColor.ToString(), script) : _trackAmbient)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateAmbientColorTrack( const lang::String& expression )
{
	return (_trackAmbient = (_trackAmbient == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::AmbientColor.ToString(), expression) : _trackAmbient)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateEmissiveColorTrack()
{
	return (_trackEmissive = (_trackEmissive == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::EmissiveColor.ToString()) : _trackEmissive)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateEmissiveColorTrack( const anim::AnimationTrack& type )
{
	return (_trackEmissive = (_trackEmissive == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::EmissiveColor.ToString(), type) : _trackEmissive)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateEmissiveColorTrack( anim::IExpressionScript* script )
{
	return (_trackEmissive = (_trackEmissive == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::EmissiveColor.ToString(), script) : _trackEmissive)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateEmissiveColorTrack( const lang::String& expression )
{
	return (_trackEmissive = (_trackEmissive == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::EmissiveColor.ToString(), expression) : _trackEmissive)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularColorTrack()
{
	return (_trackSpecular = (_trackSpecular == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::SpecularColor.ToString()) : _trackSpecular)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularColorTrack( const anim::AnimationTrack& type )
{
	return (_trackSpecular = (_trackSpecular == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::SpecularColor.ToString(), type) : _trackSpecular)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularColorTrack( anim::IExpressionScript* script )
{
	return (_trackSpecular = (_trackSpecular == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::SpecularColor.ToString(), script) : _trackSpecular)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionColorTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularColorTrack( const lang::String& expression )
{
	return (_trackSpecular = (_trackSpecular == nullptr) ? _animation->CreateColorTrack(SimpleMaterialProperty::SpecularColor.ToString(), expression) : _trackSpecular)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularPowerTrack()
{
	return (_trackSpecularPower = (_trackSpecularPower == nullptr) ? _animation->CreateFloatTrack(SimpleMaterialProperty::SpecularPower.ToString()) : _trackSpecularPower)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularPowerTrack( const anim::AnimationTrack& type )
{
	return (_trackSpecularPower = (_trackSpecularPower == nullptr) ? _animation->CreateFloatTrack(SimpleMaterialProperty::SpecularPower.ToString(), type) : _trackSpecularPower)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularPowerTrack( anim::IExpressionScript* script )
{
	return (_trackSpecularPower = (_trackSpecularPower == nullptr) ? _animation->CreateFloatTrack(SimpleMaterialProperty::SpecularPower.ToString(), script) : _trackSpecularPower)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* SimpleMaterialAnimationControllerImpl<T>::CreateSpecularPowerTrack( const lang::String& expression )
{
	return (_trackSpecularPower = (_trackSpecularPower == nullptr) ? _animation->CreateFloatTrack(SimpleMaterialProperty::SpecularPower.ToString(), expression) : _trackSpecularPower)->AsExpression();
}

template <class T>
SYNKRO_INLINE ITransparentMaterialAnimationController* SimpleMaterialAnimationControllerImpl<T>::AsTransparent() const
{
	return nullptr;
}
