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
// Purpose: Triangle mesh batch implementation.
//==============================================================================
#include "config.h"
#include "TriangleMeshBatch.h"
#include "TriangleMesh.h"
#include "TriangleSet.h"
#include "MeshBatchAnimationControllerImpl.h"
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
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


TriangleMeshBatch::TriangleMeshBatch( ITriangleMeshBatch* batch, ISceneEx* scene, IContext* context, const String& name, ISkeleton* skeleton, UInt capacity ) :
	MeshBatchImpl<ITriangleMeshBatch, ITriangleMesh>( scene, context, AsBaseScene(scene)->GetTriangleMeshName(name), capacity ),
	_batch( batch ),
	_skeleton( skeleton ),
	_boneTransforms( A(Matrix4x4) )
{
	if ( _skeleton != nullptr )
	{
		_boneTransforms.SetSize( MAX_BONE_COUNT*_instances.Capacity() );
	}
}

INodeAnimationController* TriangleMeshBatch::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new TriangleMeshBatchAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

ITriangleSet* TriangleMeshBatch::CreateTriangleList( const String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const Matrix4x4& transform )
{
	ITriangleSet* set = _batch->CreateTriangleList( name, vertexCount, indexCount, adjacency, transform );
	P(ITriangleSet) subset = new TriangleSet( set, _context, _scene->GetDebugMode(), 0, 0 );
	return RegisterSubset( subset, name, transform );
}

ITriangleSet* TriangleMeshBatch::CreateTriangleStrip( const String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const Matrix4x4& transform )
{
	ITriangleSet* set = _batch->CreateTriangleStrip( name, vertexCount, indexCount, adjacency, transform );
	P(ITriangleSet) subset = new TriangleSet( set, _context, _scene->GetDebugMode(), 0, 0 );
	return RegisterSubset( subset, name, transform );
}

ITriangleSet* TriangleMeshBatch::CreateTriangleSet( const String& name, const Range& range )
{
	ITriangleSet* set = _batch->CreateTriangleSet( name, range );
	P(ITriangleSet) subset = new TriangleSet( set, _context, _scene->GetDebugMode(), range.Start, range.Length );
	_subsets.Add( SubsetDesc(subset, _base.Primitive, name) );
	return subset;
}

void TriangleMeshBatch::Save( IStream* stream, const DataMode& mode, const MeshCodec& type )
{
	throw NotSupportedException();
}

void TriangleMeshBatch::Save( IStream* stream, const DataMode& mode )
{
	throw NotSupportedException();
}

ITriangleMesh* TriangleMeshBatch::CreateInstance( INode* parent, const Matrix4x4& transform, const Color& color )
{
	assert( _instances.Size() < _instances.Capacity() );

	if ( _instances.Size() >= _instances.Capacity() )
		throw InvalidOperationException( L"Instance capacity is exceeded." );

	ISkeleton* skeleton = (_skeleton != nullptr) ? _skeleton->Clone() : nullptr;
	ITriangleMesh* m = _batch->CreateInstance( parent, transform, color );
	ITriangleMesh* instance = new TriangleMesh( m, _scene, _context, String::Format(L"{0}.{1}", _name, _instances.Size()), skeleton );
	_instances.Add( InstanceDesc(parent, instance, transform, color) );
	SetInstanceColor( _instances.Size()-1, color );
	SetRange( Range(0, _instances.Size()) );
	return instance;
}

void TriangleMeshBatch::RemoveInstance( UInt index )
{
	assert( index < _instances.Size() );

	_batch->RemoveInstance( index );
	_instances.SetSize( _instances.Size()-1 );
	SetRange( Range(0, _instances.Size()) );
	
	// TODO: !!!
	/*UInt last = _instances.Size()-1;
	_instances[index] = _instances[last];
	SetInstanceTransform( index, _instances[last].Transform );
	SetInstanceColor( index, _instances[last].Color );
	((TriangleMeshInstance*)_instances[index].Mesh)->SetIndex( index );
	_instances.SetSize( _instances.Size()-1 );
	Range range;
	GetRange( range );
	if ( (range.Start < index) && (index < range.Start+range.Length) )
	{
		SetRange( Range(0, _instances.Size()) );
	}*/
}

void TriangleMeshBatch::SetInstanceTransform( UInt index, const Matrix4x4& transform )
{
	assert( index < _instances.Size() );

	Matrix4x4 worldTransform;
	Matrix4x4 primitiveTransform;
	_instances[index].Mesh->GetWorldTransform( worldTransform );
	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		_subsets[i].Primitive->GetTransform( primitiveTransform );
		const Matrix4x4 subsetTransform = worldTransform * primitiveTransform;
		_subsets[i].Primitive->SetInstanceTransform( index, subsetTransform );
	}
	_instances[index].Transform = transform;
}

void TriangleMeshBatch::SetInstanceColor( UInt index, const Color& color )
{
	assert( index < _instances.Size() );

	_batch->SetInstanceColor( index, color );
}

void TriangleMeshBatch::Update()
{
	NodeImpl<ITriangleMeshBatch>::ApplyConstraints( _ctrlAnimation );

	Matrix4x4 worldTransform;
	GetWorldTransform( worldTransform );

	// Set instances parents.
	Matrix4x4* transforms = _boneTransforms.Begin();
	for ( UInt i = 0; i < _instances.Size(); ++i )
	{
		if ( (_instances[i].Mesh != nullptr) && (_instances[i].Mesh->GetParent() == nullptr) )
		{
			_instances[i].Mesh->SetParent( _instances[i].Parent );
		}
		if ( _skeleton != nullptr )
		{
			_instances[i].Mesh->AsTriangle()->GetSkeleton()->GetBoneTransforms( worldTransform, &transforms, _skeleton->GetBoneCount() );
			transforms += MAX_BONE_COUNT;
		}
	}

	// Set bone transforms.
	if ( _skeleton != nullptr )
	{
		for ( UInt i = 0; i < _subsets.Size(); ++i )
		{
			_subsets[i].Primitive->AsTriangleSet()->SetBoneTransforms( _boneTransforms.Begin(), MAX_BONE_COUNT*_instances.Size() );
		}
	}

	// Set subset transforms.
	for ( UInt i = 0; i < _instances.Size(); ++i )
	{
		SetInstanceTransform( i, Matrix4x4::Identity );
	}
}

ITriangleSet* TriangleMeshBatch::RegisterSubset( ITriangleSet* subset, const String& name, const Matrix4x4& transform )
{
	if ( name.IsNull() )
	{
		if ( _base.Primitive != nullptr )
			throw InvalidOperationException( L"Base primitive already exists." );

		subset->Show( false );
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
