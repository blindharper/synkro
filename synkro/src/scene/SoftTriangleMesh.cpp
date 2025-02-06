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
// Purpose: Software solid mesh implementation.
//==============================================================================
#include "config.h"
#include "SoftTriangleMesh.h"
#include "SoftTriangleSet.h"
#include <mat/SoftOpaqueMaterial.h>
#include <mat/MultiMaterial.h>
#include <io/IStream.h>
#include <io/Path.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


SoftTriangleMesh::SoftTriangleMesh( BaseSceneManager* sceneManager, ISkeleton* skeleton, UInt subsetCount ) :
	MeshImpl<ITriangleMesh>( nullptr, nullptr, String::Empty ),
	_sceneManager( sceneManager ),
	_skeleton( skeleton )
{
	if ( subsetCount > 1 )
	{
		IMultiMaterial* material = new MultiMaterial( subsetCount );
		for ( UInt i = 0; i < subsetCount; ++i )
		{
			material->SetSubset( i, new SoftOpaqueMaterial() );
		}
		_material = material;
	}
	else
	{
		_material = new SoftOpaqueMaterial();
	}
}

ITriangleMesh* SoftTriangleMesh::AsTriangle() const
{
	return (ITriangleMesh*)this;
}

INodeAnimationController* SoftTriangleMesh::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return nullptr;
}

ITriangleMesh* SoftTriangleMesh::CreateInstance( INode* parent, const Matrix4x4& transform, const Color& color )
{
	return nullptr;
}

ITriangleSet* SoftTriangleMesh::CreateTriangleList( const String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const Matrix4x4& transform )
{
	return CreateTriangleSet( name, vertexCount, indexCount, adjacency, transform );
}

ITriangleSet* SoftTriangleMesh::CreateTriangleStrip( const String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const Matrix4x4& transform )
{
	return CreateTriangleSet( name, vertexCount, indexCount, adjacency, transform );
}

ITriangleSet* SoftTriangleMesh::CreateTriangleSet( const String& name, const Range& range )
{
	if ( _base.Primitive == nullptr )
		throw InvalidOperationException( L"Base primitive does not exist." );

	ITriangleSet* subset = new SoftTriangleSet( (SoftTriangleSet*)_base.Primitive.AsPtr(), 0, 0, range );
	_subsets.Add( SubsetDesc(subset, _base.Primitive, name) );
	return subset;
}

void SoftTriangleMesh::Save( IStream* stream, const DataMode& mode, const MeshCodec& type )
{
	_sceneManager->SaveMesh( this, stream, mode, type );
}

void SoftTriangleMesh::Save( IStream* stream, const DataMode& mode )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	if ( !type.IsEmpty() )
	{
		Save( stream, mode, MeshCodec(type) );
	}
}

ISkeleton* SoftTriangleMesh::GetSkeleton() const
{
	return _skeleton;
}

IVisualMaterial* SoftTriangleMesh::GetMaterial() const
{
	return _material;
}

IScene* SoftTriangleMesh::GetScene() const
{
	return nullptr;
}

ITriangleMeshBatch* SoftTriangleMesh::AsBatch() const
{
	return nullptr;
}

ITriangleSet* SoftTriangleMesh::CreateTriangleSet( const String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const Matrix4x4& transform )
{
	P(ITriangleSet) subset = new SoftTriangleSet( (SoftTriangleSet*)_base.Primitive.AsPtr(), vertexCount, indexCount, Range(0, 0) );
	if ( name.IsNull() )
	{
		if ( _base.Primitive != nullptr )
			throw InvalidOperationException( L"Base primitive already exists." );

		_base.Primitive = subset;
		_base.Primitive->SetTransform( transform );
	}
	else
	{
		if ( _base.Primitive != nullptr )
			throw InvalidOperationException( L"Only reference primitives are allowed after the base primitive has been created." );

		_subsets.Add( SubsetDesc(subset, transform, name) );
	}
	return subset;
}
	

} // scene


} // synkro
