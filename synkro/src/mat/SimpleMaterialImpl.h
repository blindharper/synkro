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
#ifndef _SYNKRO_MAT_SIMPLEMATERIALIMPL_
#define _SYNKRO_MAT_SIMPLEMATERIALIMPL_


#include "config.h"
#include "VisualMaterialImpl.h"
#include "MaterialDesc.h"
#include <mat/IMaterialMap.h>


namespace synkro
{


namespace mat
{


// Simple material implementation.
template <class T>
class SimpleMaterialImpl :
	public VisualMaterialImpl<T>
{
public:
	// Constructor & destructor.
	SimpleMaterialImpl( core::IContext* context );
	virtual ~SimpleMaterialImpl();

	// IVisualMaterial methods.
	virtual ISimpleMaterial*								AsSimple() const;

	// ISimpleMaterial methods.
	virtual void											SetLightingModel( const LightingModel& lightingModel );
	virtual void											SetDiffuseColor( const img::Color& color );
	virtual void											SetAmbientColor( const img::Color& color );
	virtual void											SetEmissiveColor( const img::Color& color );
	virtual void											SetSpecularColor( const img::Color& color );
	virtual void											SetSpecularPower( Float power );
	virtual void											SetTilingHorizontal( UInt tiling );
	virtual void											SetTilingVertical( UInt tiling );
	virtual LightingModel									GetLightingModel() const;
	virtual void											GetDiffuseColor( img::Color& color ) const;
	virtual void											GetAmbientColor( img::Color& color ) const;
	virtual void											GetEmissiveColor( img::Color& color ) const;
	virtual void											GetSpecularColor( img::Color& color ) const;
	virtual Float											GetSpecularPower() const;
	virtual UInt											GetTilingHorizontal() const;
	virtual UInt											GetTilingVertical() const;
	virtual IMaterialMap*									GetDiffuseMap() const;
	virtual IOpaqueMaterial*								AsOpaque() const;
	virtual ITransparentMaterial*							AsTransparent() const;

protected:
	typedef lang::MapPair<MaterialKey, MaterialDesc>		MaterialEntry;

	lang::Map<MaterialKey, MaterialDesc>					_materials;
	LightingModel											_lightingModel;
	img::Color												_colorDiffuse;
	img::Color												_colorAmbient;
	img::Color												_colorEmissive;
	img::Color												_colorSpecular;
	Float													_specularPower;
	UInt													_tilingHorizontal;
	UInt													_tilingVertical;
	gfx::ProgramParam*										_paramTilingHorizontal;
	gfx::ProgramParam*										_paramTilingVertical;
	P(IMaterialMap)											_diffuseMap;
};


#include "SimpleMaterialImpl.inl"


} // mat


} // synkro


#endif // _SYNKRO_MAT_SIMPLEMATERIALIMPL_
