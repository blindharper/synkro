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
// Purpose: Transparent material implementation.
//==============================================================================
#ifndef _SYNKRO_MAT_TRANSPARENTMATERIAL_
#define _SYNKRO_MAT_TRANSPARENTMATERIAL_


#include "config.h"
#include "SimpleMaterialImpl.h"
#include <mat/ITransparentMaterial.h>
#include <mat/ISimpleMaterialAnimationController.h>
#include "BaseMaterial.h"


namespace synkro
{


namespace mat
{


// Transparent material implementation.
class TransparentMaterial :
	public SimpleMaterialImpl<ITransparentMaterial>,
	public BaseMaterial
{
public:
	// Constructors.
	TransparentMaterial( core::IContext* context, const LightingModel& model );
	TransparentMaterial( const TransparentMaterial& other );

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

	// Other methods.
	scene::ITriangleSet*									CreateTriangleSet( const gfx::PrimitiveType& type, scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency );
	void													Assign( gfx::ISceneRenderObject* object, MaterialDesc* mat );

private:
	P(ISimpleMaterialAnimationController)					_ctrlAnimation;
	P(IMaterialMap)											_opacityMap;
	P(gfx::IParameterSet)									_fragmentParams;
	P(gfx::IResourceSet)									_fragmentResources;
	P(gfx::ISamplerStateSet)								_fragmentSamplers;
	gfx::ProgramParam*										_paramAmountDiffuse;
	gfx::ProgramParam*										_paramAmountOpacity;
	Float													_opacity;
	gfx::BlendMode											_colorSourceMode;
	gfx::BlendMode											_alphaSourceMode;
	gfx::BlendMode											_colorDestinationMode;
	gfx::BlendMode											_alphaDestinationMode;
	gfx::BlendOperation										_colorOperation;
	gfx::BlendOperation										_alphaOperation;

	void													CreateStates();
	void													UpdateVertexParameters();
	void													EnableBlend( Bool enable );
	void													SetFragmentParameters( MaterialDesc* mat );
	void													SetFragmentResources( MaterialDesc* mat );
	void													SetVertexParameters( MaterialDesc* mat );
	MaterialKey												GetKey( scene::ITriangleMesh* mesh );
	MaterialDesc*											FindMaterial( const MaterialKey& key );
};


#include "TransparentMaterial.inl"


} // mat


} // synkro


#endif // _SYNKRO_MAT_TRANSPARENTMATERIAL_
