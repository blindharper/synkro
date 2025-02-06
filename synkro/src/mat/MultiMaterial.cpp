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
#include "config.h"
#include "MultiMaterial.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace mat
{


MultiMaterial::MultiMaterial( UInt size ) :
	_materials( A(P(ISimpleMaterial)) )
{
	assert( size > 0 );

	_materials.SetSize( size );
}

IVisualMaterialAnimationController* MultiMaterial::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return nullptr;
}

ITriangleSet* MultiMaterial::CreateTriangleList( ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency )
{
	assert( index < _materials.Size() );

	return _materials[index]->CreateTriangleList( mesh, 0, vertexCount, indexCount, adjacency );
}

ITriangleSet* MultiMaterial::CreateTriangleStrip( ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency )
{
	assert( index < _materials.Size() );

	return _materials[index]->CreateTriangleStrip( mesh, 0, vertexCount, indexCount, adjacency );
}

IVisualMaterial* MultiMaterial::CreateInstance( ITriangleMeshBatch* batch, UInt index )
{
	return nullptr;
}

void MultiMaterial::Assign( ITriangleMesh* mesh, ISceneRenderObject* object, UInt index )
{
	assert( index < _materials.Size() );

	AsBaseMaterial( _materials[index].AsPtr() )->Assign( mesh, object, 0 );
}

void MultiMaterial::SetIndex( UInt index )
{
}

void MultiMaterial::SetParam( const String& name, const String& value )
{
}

void MultiMaterial::OnDiffuseMapSet()
{
}

void MultiMaterial::OnOpacityMapSet()
{
}


} // mat


} // synkro
