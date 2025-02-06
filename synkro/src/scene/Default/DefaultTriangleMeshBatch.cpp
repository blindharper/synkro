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
// Purpose: Default triangle mesh batch implementation.
//==============================================================================
#include "config.h"
#include "DefaultTriangleMeshBatch.h"
#include "DefaultTriangleMeshInstance.h"
#include "DefaultTriangleSet.h"
#include <gfx/PrimitiveTypeConst.h>
#include <gfx/ISceneRenderObject.h>
#include <gfx/ISceneRenderQueue.h>
#include <gfx/IPrimitiveEx.h>
#include <mat/BaseMaterial.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
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


DefaultTriangleMeshBatch::DefaultTriangleMeshBatch( DefaultScene* scene, IVisualMaterial* material, ISkeleton* skeleton, UInt capacity ) :
	_scene( scene ),
	_material( material ),
	_skeleton( skeleton ),
	_subsets( A(P(ITriangleSet)) ),
	_instances( A(P(ITriangleMesh)), capacity ),
	_range( 0 )
{
}

INodeAnimationController* DefaultTriangleMeshBatch::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	throw NotSupportedException();
}

IParentConstraint* DefaultTriangleMeshBatch::CreateParentConstraint( INode* parent, const Matrix4x4& transform )
{
	throw NotSupportedException();
}

ILookAtConstraint* DefaultTriangleMeshBatch::CreateLookAtConstraint( INode* target )
{
	throw NotSupportedException();
}

ITriangleSet* DefaultTriangleMeshBatch::CreateTriangleList( const String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const Matrix4x4& transform )
{
	return CreateTriangleSet( PrimitiveType::TriangleList, name, vertexCount, indexCount, adjacency, transform );
}

ITriangleSet* DefaultTriangleMeshBatch::CreateTriangleStrip( const String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const Matrix4x4& transform )
{
	return CreateTriangleSet( PrimitiveType::TriangleStrip, name, vertexCount, indexCount, adjacency, transform );
}

ITriangleSet* DefaultTriangleMeshBatch::CreateTriangleSet( const String& name, const Range& range )
{
	if ( _base == nullptr )
		throw InvalidOperationException( L"Base primitive does not exist." );

	P(ITriangleSet) subset;
	ITriangleSet* base = _base->AsTriangleSet();
	if ( _subsets.IsEmpty() )
	{
		base->SetElementRange( range );
		subset = base;
	}
	else
	{
		ISceneRenderObject* object = base->GetRenderObject()->GetQueue()->CreateObject( base->GetRenderObject()->GetData(), false );
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

void DefaultTriangleMeshBatch::Save( IStream* stream, const DataMode& mode, const MeshCodec& type )
{
	throw NotSupportedException();
}

void DefaultTriangleMeshBatch::Save( IStream* stream, const DataMode& mode )
{
	throw NotSupportedException();
}

ITriangleMesh* DefaultTriangleMeshBatch::CreateInstance( INode* parent, const Matrix4x4& transform, const Color& color )
{
	assert( _instances.Size() < _instances.Capacity() );

	if ( _instances.Size() >= _instances.Capacity() )
		throw InvalidOperationException( L"Instance capacity is exceeded." );

	IVisualMaterial* material = AsBaseMaterial( _material.AsPtr() )->CreateInstance( this, _instances.Size() );
	ITriangleMesh* instance = new DefaultTriangleMeshInstance( this, material, _skeleton, String::Format(L"Mesh Batch{0}", _instances.Size()), _instances.Size(), transform );
	_instances.Add( instance );
	SetInstanceColor( _instances.Size()-1, color );
	SetRange( Range(0, _instances.Size()) );
	return instance;
}

void DefaultTriangleMeshBatch::RemoveInstance( UInt index )
{
	UInt last = _instances.Size()-1;
	_instances[index] = _instances[last];
	((DefaultTriangleMeshInstance*)_instances[index].AsPtr())->SetIndex( index );
	_instances.SetSize( _instances.Size()-1 );
	SetRange( Range(0, _instances.Size()) );
}

void DefaultTriangleMeshBatch::SetInstanceTransform( UInt index, const Matrix4x4& transform )
{
	Matrix4x4 worldTransform;
	Matrix4x4 primitiveTransform;
	_instances[index]->GetWorldTransform( worldTransform );
	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		_subsets[i]->GetTransform( primitiveTransform );
		const Matrix4x4 subsetTransform = worldTransform * primitiveTransform;
		_subsets[i]->SetInstanceTransform( index, subsetTransform );
	}
}

void DefaultTriangleMeshBatch::SetInstanceColor( UInt index, const Color& color )
{
	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		_subsets[i]->SetInstanceColor( index, color );
	}
}

ITriangleSet* DefaultTriangleMeshBatch::CreateTriangleSet( const PrimitiveType& type, const String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const Matrix4x4& transform )
{
	UInt index = (_subsets.Size() < GetMaterial()->GetSubsetCount()) ? _subsets.Size() : GetMaterial()->GetSubsetCount()-1;
	ITriangleSet* subset = nullptr;
	switch ( type )
	{
		case PRIMITIVE_TYPE_TRIANGLE_LIST:
			subset = this->_material->CreateTriangleList( this, index, vertexCount, indexCount, adjacency );
			break;

		case PRIMITIVE_TYPE_TRIANGLE_STRIP:
			subset = this->_material->CreateTriangleStrip( this, index, vertexCount, indexCount, adjacency );
			break;
	}

	if ( name.IsNull() )
	{
		if ( _base != nullptr )
			throw InvalidOperationException( L"Base primitive already exists." );

		subset->Show( false );
		_base = subset;
		_base->SetTransform( transform );
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
