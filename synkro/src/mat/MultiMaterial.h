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
// Purpose: Multi material implementation.
//==============================================================================
#ifndef _SYNKRO_MAT_MULTIMATERIAL_
#define _SYNKRO_MAT_MULTIMATERIAL_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <mat/IMultiMaterial.h>
#include <mat/ISimpleMaterial.h>
#include <gfx/PrimitiveType.h>
#include "BaseMaterial.h"


namespace synkro
{


namespace mat
{


// Multi material implementation.
class MultiMaterial :
	public core::ObjectImpl<IMultiMaterial>,
	public BaseMaterial
{
public:
	// Constructors.
	MultiMaterial( UInt size );

	// IVisualMaterial methods.
	IVisualMaterialAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	scene::ITriangleSet*									CreateTriangleList( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency );
	scene::ITriangleSet*									CreateTriangleStrip( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency );
	void													SetColored( Bool colored );
	Bool													IsColored() const;
	UInt													GetSubsetCount() const;
	ISimpleMaterial*										AsSimple() const;
	IMultiMaterial*											AsMulti() const;
	
	// IMultiMaterial methods.
	void													SetSubset( UInt index, ISimpleMaterial* material );
	ISimpleMaterial*										GetSubset( UInt index ) const;
	IMultiMaterial*											Clone() const;

	// BaseMaterial methods.
	IVisualMaterial*										CreateInstance( scene::ITriangleMeshBatch* batch, UInt index );
	void													Assign( scene::ITriangleMesh* mesh, gfx::ISceneRenderObject* object, UInt index );
	void													SetIndex( UInt index );
	void													SetParam( const lang::String& name, const lang::String& value );
	void													OnDiffuseMapSet();
	void													OnOpacityMapSet();

private:
	lang::Vector<P(ISimpleMaterial)>						_materials;
};


#include "MultiMaterial.inl"


} // mat


} // synkro


#endif // _SYNKRO_MAT_MULTIMATERIAL_
