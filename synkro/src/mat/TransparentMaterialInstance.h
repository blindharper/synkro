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
// Purpose: Transparent material instance implementation.
//==============================================================================
#ifndef _SYNKRO_MAT_TRANSPARENTMATERIALINSTANCE_
#define _SYNKRO_MAT_TRANSPARENTMATERIALINSTANCE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/IContext.h>
#include <mat/ITransparentMaterial.h>
#include <mat/ISimpleMaterialAnimationController.h>
#include "BaseMaterial.h"


namespace synkro
{


namespace mat
{


// Transparent material instance implementation.
class TransparentMaterialInstance :
	public core::ObjectImpl<ITransparentMaterial>,
	public BaseMaterial
{
public:
	// Constructor.
	TransparentMaterialInstance( core::IContext* context, scene::ITriangleMeshBatch* batch, ITransparentMaterial* material, UInt index );

	// IVisualMaterial methods.
	IVisualMaterialAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	scene::ITriangleSet*									CreateTriangleList( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency );
	scene::ITriangleSet*									CreateTriangleStrip( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency );
	void													SetColored( Bool colored );
	Bool													IsColored() const;
	UInt													GetSubsetCount() const;
	ISimpleMaterial*										AsSimple() const;
	IMultiMaterial*											AsMulti() const;

	// ISimpleMaterial methods.
	void													SetLightingModel( const LightingModel& model );
	void													SetDiffuseColor( const img::Color& color );
	void													SetAmbientColor( const img::Color& color );
	void													SetEmissiveColor( const img::Color& color );
	void													SetSpecularColor( const img::Color& color );
	void													SetSpecularPower( Float power );
	void													SetTilingHorizontal( UInt tiling );
	void													SetTilingVertical( UInt tiling );
	LightingModel											GetLightingModel() const;
	void													GetDiffuseColor( img::Color& color ) const;
	void													GetAmbientColor( img::Color& color ) const;
	void													GetEmissiveColor( img::Color& color ) const;
	void													GetSpecularColor( img::Color& color ) const;
	Float													GetSpecularPower() const;
	UInt													GetTilingHorizontal() const;
	UInt													GetTilingVertical() const;
	IMaterialMap*											GetDiffuseMap() const;
	IOpaqueMaterial*										AsOpaque() const;
	ITransparentMaterial*									AsTransparent() const;

	// ITransparentMaterial methods.
	void													SetOpacity( Float opacity );
	void													SetColorSourceMode( const gfx::BlendMode& mode );
	void													SetAlphaSourceMode( const gfx::BlendMode& mode );
	void													SetColorDestinationMode( const gfx::BlendMode& mode );
	void													SetAlphaDestinationMode( const gfx::BlendMode& mode );
	void													SetColorOperation( const gfx::BlendOperation& operation );
	void													SetAlphaOperation( const gfx::BlendOperation& operation );
	Float													GetOpacity() const;
	gfx::BlendMode											GetColorSourceMode() const;
	gfx::BlendMode											GetAlphaSourceMode() const;
	gfx::BlendMode											GetColorDestinationMode() const;
	gfx::BlendMode											GetAlphaDestinationMode() const;
	gfx::BlendOperation										GetColorOperation() const;
	gfx::BlendOperation										GetAlphaOperation() const;
	IMaterialMap*											GetOpacityMap() const;
	ITransparentMaterial*									Clone() const;

	// BaseMaterial methods.
	IVisualMaterial*										CreateInstance( scene::ITriangleMeshBatch* batch, UInt index );
	void													Assign( scene::ITriangleMesh* mesh, gfx::ISceneRenderObject* object, UInt index );
	void													SetIndex( UInt index );
	void													SetParam( const lang::String& name, const lang::String& value );
	void													OnDiffuseMapSet();
	void													OnOpacityMapSet();

private:
	core::IContext*											_context;
	P(ISimpleMaterialAnimationController)					_ctrlAnimation;
	scene::ITriangleMeshBatch*								_batch;
	ITransparentMaterial* 									_material;
	UInt													_index;
	img::Color												_colorDiffuse;
};


#include "TransparentMaterialInstance.inl"


} // mat


} // synkro


#endif // _SYNKRO_MAT_TRANSPARENTMATERIALINSTANCE_
