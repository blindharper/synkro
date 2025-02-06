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
// Purpose: Generic light implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE LightImpl<T>::LightImpl( ISceneEx* scene, core::IContext* context, const lang::String& name, Bool visualize ) :
	NodeImpl<T>( scene, context, name, visualize ),
	_enabled( true ),
	_diffuseColor( img::Color::White ),
	_ambientColor( img::Color::Black ),
	_specularColor( img::Color::Black ),
	_intensity( 1.0f )
{
}

template <class T>
SYNKRO_INLINE LightImpl<T>::~LightImpl()
{
}

template <class T>
SYNKRO_INLINE ILight* LightImpl<T>::AsLight() const
{
	return (ILight*)this;
}

template <class T>
SYNKRO_INLINE void LightImpl<T>::Enable( Bool enable )
{
	_enabled = enable;
}

template <class T>
SYNKRO_INLINE void LightImpl<T>::SetDiffuseColor( const img::Color& color )
{
	_diffuseColor = color;
}

template <class T>
SYNKRO_INLINE void LightImpl<T>::SetAmbientColor( const img::Color& color )
{
	_ambientColor = color;
}

template <class T>
SYNKRO_INLINE void LightImpl<T>::SetSpecularColor( const img::Color& color )
{
	_specularColor = color;
}

template <class T>
SYNKRO_INLINE void LightImpl<T>::SetIntensity( Float intensity )
{
	_intensity = Clamp( intensity, 0.0f, 1.0f );
}

template <class T>
SYNKRO_INLINE Bool LightImpl<T>::IsEnabled() const
{
	return _enabled;
}

template <class T>
SYNKRO_INLINE void LightImpl<T>::GetDiffuseColor( img::Color& color ) const
{
	color = _diffuseColor;
}

template <class T>
SYNKRO_INLINE void LightImpl<T>::GetAmbientColor( img::Color& color ) const
{
	color = _ambientColor;
}

template <class T>
SYNKRO_INLINE void LightImpl<T>::GetSpecularColor( img::Color& color ) const
{
	color = _specularColor;
}

template <class T>
SYNKRO_INLINE Float LightImpl<T>::GetIntensity() const
{
	return _intensity;
}

template <class T>
SYNKRO_INLINE IConeLight* LightImpl<T>::AsCone() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IDirectLight* LightImpl<T>::AsDirect() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IOmniLight* LightImpl<T>::AsOmni() const
{
	return nullptr;
}
