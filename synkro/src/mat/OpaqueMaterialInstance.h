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
// Purpose: Opaque material instance implementation.
//==============================================================================
#ifndef _SYNKRO_MAT_OPAQUEMATERIALINSTANCE_
#define _SYNKRO_MAT_OPAQUEMATERIALINSTANCE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/IContext.h>
#include <mat/IOpaqueMaterial.h>
#include <mat/ISimpleMaterialAnimationController.h>
#include "BaseMaterial.h"


namespace synkro
{


namespace mat
{


// Opaque material instance implementation.
class OpaqueMaterialInstance :
	public core::ObjectImpl<IOpaqueMaterial>,
	public BaseMaterial
{
public:
	// Constructor.
	OpaqueMaterialInstance( core::IContext* context, scene::ITriangleMeshBatch* batch, IOpaqueMaterial* material, UInt index );

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

	// IOpaqueMaterial methods.
	void													SetTwoSided( Bool twoSided );
	void													SetWireframe( Bool wireframe );
	Bool													IsTwoSided() const;
	Bool													IsWireframe() const;
	IOpaqueMaterial*										Clone() const;

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
	IOpaqueMaterial* 										_material;
	UInt													_index;
	img::Color												_colorDiffuse;
};


#include "OpaqueMaterialInstance.inl"


} // mat


} // synkro


#endif // _SYNKRO_MAT_OPAQUEMATERIALINSTANCE_
