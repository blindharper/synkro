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
// Purpose: Opaque software material implementation.
//==============================================================================
#ifndef _SYNKRO_MAT_SOFTOPAQUEMATERIAL_
#define _SYNKRO_MAT_SOFTOPAQUEMATERIAL_


#include "config.h"
#include "SimpleMaterialImpl.h"
#include <mat/IOpaqueMaterial.h>
#include <mat/BaseMaterial.h>


namespace synkro
{


namespace mat
{


// Opaque software material implementation.
class SoftOpaqueMaterial :
	public SimpleMaterialImpl<IOpaqueMaterial>,
	public BaseMaterial
{
public:
	// Constructors.
	SoftOpaqueMaterial();
	SoftOpaqueMaterial( const SoftOpaqueMaterial& other );

	// IVisualMaterial methods.
	IVisualMaterialAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

	// ISimpleMaterial methods.
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

private:
	Bool													_twoSided;
	Bool													_wireframe;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_SOFTOPAQUEMATERIAL_
