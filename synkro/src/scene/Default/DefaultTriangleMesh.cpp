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
// Purpose: Default triangle mesh implementation.
//==============================================================================
#include "config.h"
#include "DefaultTriangleMesh.h"
#include "DefaultTriangleSet.h"
#include "DefaultScene.h"
#include <gfx/PrimitiveTypeConst.h>
#include <mat/BaseMaterial.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


DefaultTriangleMesh::DefaultTriangleMesh( DefaultScene* scene, IVisualMaterial* material, ISkeleton* skeleton ) :
	_scene( scene ),
	_parent( nullptr ),
	_transformDirty( true ),
	_scale( 1.0f ),
	_yaw( 0.0f ),
	_pitch( 0.0f ),
	_roll( 0.0f ),
	_subsets( A(P(ITriangleSet)) ),
	_base( false ),
	_material( material ),
	_skeleton( skeleton )
{
}

DefaultTriangleMesh::~DefaultTriangleMesh()
{
	_scene->RemoveMesh( this );
}

ITriangleSet* DefaultTriangleMesh::CreateTriangleList( const String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const Matrix4x4& transform )
{
	return CreateTriangleSet( PrimitiveType::TriangleList, name, vertexCount, indexCount, adjacency, transform );
}

ITriangleSet* DefaultTriangleMesh::CreateTriangleStrip( const String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const Matrix4x4& transform )
{
	return CreateTriangleSet( PrimitiveType::TriangleStrip, name, vertexCount, indexCount, adjacency, transform );
}

ITriangleSet* DefaultTriangleMesh::CreateTriangleSet( const String& name, const Range& range )
{
	if ( _base == nullptr )
		throw InvalidOperationException( L"Base primitive does not exist." );

	P(ITriangleSet) subset;
	if ( _subsets.IsEmpty() )
	{
		subset = _base;
		subset->SetElementRange( range );
	}
	else
	{
		ISceneRenderObject* object = _base->GetRenderObject()->GetQueue()->CreateObject( _base->GetRenderObject()->GetData(), false );
		const UInt index = (_subsets.Size() < _material->GetSubsetCount()) ? _subsets.Size() : _material->GetSubsetCount()-1;
		AsBaseMaterial( _material.AsPtr() )->Assign( this, object, index );
		subset = new DefaultTriangleSet( object, range.Start, range.Length );
	}
	Matrix4x4 transform;
	_base->GetTransform( transform );
	subset->SetTransform( transform );
	_subsets.Add( subset );
	return subset;
}

void DefaultTriangleMesh::Save( IStream* stream, const DataMode& mode, const MeshCodec& type )
{
	// Do nothing.
}

void DefaultTriangleMesh::Save( IStream* stream, const DataMode& mode )
{
	// Do nothing.
}

ITriangleSet* DefaultTriangleMesh::CreateTriangleSet( const PrimitiveType& type, const String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const Matrix4x4& transform )
{
	UInt index = (_subsets.Size() < _material->GetSubsetCount()) ? _subsets.Size() : _material->GetSubsetCount()-1;
	P(ITriangleSet) subset;
	switch ( type )
	{
		case PRIMITIVE_TYPE_TRIANGLE_LIST:
			subset = _material->CreateTriangleList( this, index, vertexCount, indexCount, adjacency );
			break;

		case PRIMITIVE_TYPE_TRIANGLE_STRIP:
			subset = _material->CreateTriangleStrip( this, index, vertexCount, indexCount, adjacency );
			break;
	}

	if ( name.IsNull() )
	{
		if ( _base != nullptr )
			throw InvalidOperationException( L"Base primitive already exists." );

		subset->Show( false );
		subset->SetTransform( transform );
		_base = subset;
	}
	else
	{
		if ( _base != nullptr )
			throw InvalidOperationException( L"Only reference primitives are allowed after the base primitive has been created." );

		subset->SetTransform( transform );
		_subsets.Add( subset );
	}
	return subset;
}
	

} // scene


} // synkro
