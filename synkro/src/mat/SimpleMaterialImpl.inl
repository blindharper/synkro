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
// Purpose: Simple material implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE SimpleMaterialImpl<T>::SimpleMaterialImpl( core::IContext* context ) :
	VisualMaterialImpl<T>( context ),
	_materials( A(MaterialEntry) ),
	_lightingModel( LightingModel::Gouraud ),
	_colorDiffuse( img::Color::White ),
	_colorAmbient( img::Color::DarkGray ),
	_colorSpecular( img::Color::Black ),
	_colorEmissive( img::Color::Black ),
	_specularPower( 0.0f ),
	_tilingHorizontal( 1 ),
	_tilingVertical( 1 ),
	_paramTilingHorizontal( nullptr ),
	_paramTilingVertical( nullptr )
{
}

template <class T>
SYNKRO_INLINE SimpleMaterialImpl<T>::~SimpleMaterialImpl()
{
}

template <class T>
SYNKRO_INLINE ISimpleMaterial* SimpleMaterialImpl<T>::AsSimple() const
{
	return (ISimpleMaterial*)this;
}

template <class T>
SYNKRO_INLINE void SimpleMaterialImpl<T>::SetLightingModel( const LightingModel& lightingModel )
{
	_lightingModel = lightingModel;
}

template <class T>
SYNKRO_INLINE void SimpleMaterialImpl<T>::SetDiffuseColor( const img::Color& color )
{
	_colorDiffuse = color;
}

template <class T>
SYNKRO_INLINE void SimpleMaterialImpl<T>::SetAmbientColor( const img::Color& color )
{
	_colorAmbient = color;
}

template <class T>
SYNKRO_INLINE void SimpleMaterialImpl<T>::SetEmissiveColor( const img::Color& color )
{
	_colorEmissive = color;
}

template <class T>
SYNKRO_INLINE void SimpleMaterialImpl<T>::SetSpecularColor( const img::Color& color )
{
	_colorSpecular = color;
}

template <class T>
SYNKRO_INLINE void SimpleMaterialImpl<T>::SetSpecularPower( Float power )
{
	_specularPower = power;
}

template <class T>
SYNKRO_INLINE void SimpleMaterialImpl<T>::SetTilingHorizontal( UInt tiling )
{
	if ( tiling == 0 )
		throw lang::BadArgumentException( L"Material map tiling should be greater than zero.", L"tiling", L"0" );

	_tilingHorizontal = tiling;
}

template <class T>
SYNKRO_INLINE void SimpleMaterialImpl<T>::SetTilingVertical( UInt tiling )
{
	if ( tiling == 0 )
		throw lang::BadArgumentException( L"Material map tiling should be greater than zero.", L"tiling", L"0" );

	_tilingVertical = tiling;
}

template <class T>
SYNKRO_INLINE LightingModel SimpleMaterialImpl<T>::GetLightingModel() const
{
	return _lightingModel;
}

template <class T>
SYNKRO_INLINE void SimpleMaterialImpl<T>::GetDiffuseColor( img::Color& color ) const
{
	color = _colorDiffuse;
}

template <class T>
SYNKRO_INLINE void SimpleMaterialImpl<T>::GetAmbientColor( img::Color& color ) const
{
	color = _colorAmbient;
}

template <class T>
SYNKRO_INLINE void SimpleMaterialImpl<T>::GetEmissiveColor( img::Color& color ) const
{
	color = _colorEmissive;
}

template <class T>
SYNKRO_INLINE void SimpleMaterialImpl<T>::GetSpecularColor( img::Color& color ) const
{
	color = _colorSpecular;
}

template <class T>
SYNKRO_INLINE Float SimpleMaterialImpl<T>::GetSpecularPower() const
{
	return _specularPower;
}

template <class T>
SYNKRO_INLINE UInt SimpleMaterialImpl<T>::GetTilingHorizontal() const
{
	return _tilingHorizontal;
}

template <class T>
SYNKRO_INLINE UInt SimpleMaterialImpl<T>::GetTilingVertical() const
{
	return _tilingVertical;
}

template <class T>
SYNKRO_INLINE IMaterialMap* SimpleMaterialImpl<T>::GetDiffuseMap() const
{
	return _diffuseMap;
}

template <class T>
SYNKRO_INLINE IOpaqueMaterial* SimpleMaterialImpl<T>::AsOpaque() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ITransparentMaterial* SimpleMaterialImpl<T>::AsTransparent() const
{
	return nullptr;
}
