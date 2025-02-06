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
// Purpose: Opaque material implementation.
//==============================================================================
#ifndef _SYNKRO_MAT_OPAQUEMATERIAL_
#define _SYNKRO_MAT_OPAQUEMATERIAL_


#include "config.h"
#include "SimpleMaterialImpl.h"
#include <mat/IOpaqueMaterial.h>
#include <mat/ISimpleMaterialAnimationController.h>
#include "BaseMaterial.h"


namespace synkro
{


namespace mat
{


// Opaque material implementation.
class OpaqueMaterial :
	public SimpleMaterialImpl<IOpaqueMaterial>,
	public BaseMaterial
{
public:
	// Constructors.
	OpaqueMaterial( core::IContext* context, const LightingModel& model );
	OpaqueMaterial( const OpaqueMaterial& other );

	// IVisualMaterial methods.
	IVisualMaterialAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

	// ISimpleMaterial methods.
	void													SetDiffuseColor( const img::Color& color );
	void													SetAmbientColor( const img::Color& color );
	void													SetEmissiveColor( const img::Color& color );
	void													SetSpecularColor( const img::Color& color );
	void													SetSpecularPower( Float power );
	void													SetTilingHorizontal( UInt tiling );
	void													SetTilingVertical( UInt tiling );
	IOpaqueMaterial*										AsOpaque() const;

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

	// Other methods.
	scene::ITriangleSet*									CreateTriangleSet( const gfx::PrimitiveType& type, scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency );
	void													Assign( gfx::ISceneRenderObject* object, MaterialDesc* mat );

private:
	P(ISimpleMaterialAnimationController)					_ctrlAnimation;
	Bool													_twoSided;
	Bool													_wireframe;
	P(gfx::IResourceSet)									_vertexResources;
	P(gfx::IParameterSet)									_fragmentParams;
	P(gfx::IResourceSet)									_fragmentResources;
	P(gfx::ISamplerStateSet)								_fragmentSamplers;
	gfx::ProgramParam*										_paramAmountDiffuse;

	void													CreateStates();
	void													UpdateVertexParameters();
	void													SetVertexParameters( MaterialDesc* mat );
	void													SetVertexResources( MaterialDesc* mat );
	void													SetFragmentParameters( MaterialDesc* mat );
	void													SetFragmentResources( MaterialDesc* mat );
	MaterialKey												GetKey( scene::ITriangleMesh* mesh );
	MaterialDesc*											FindMaterial( const MaterialKey& key );
};


#include "OpaqueMaterial.inl"


} // mat


} // synkro


#endif // _SYNKRO_MAT_OPAQUEMATERIAL_
