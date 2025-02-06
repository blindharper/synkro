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
// Purpose: Point mesh batch implementation.
//==============================================================================
#include "config.h"
#include "PointMeshBatch.h"
#include "PointMeshInstance.h"
#include "MeshBatchAnimationControllerImpl.h"
#include "PointSet.h"
#include <gfx/ISceneRenderQueue.h>
#include <gfx/ILineRenderQueue.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/IParameterSet.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/DataAccess.h>
#include <gfx/DataUsage.h>
#include <scene/IScene.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


PointMeshBatch::PointMeshBatch( ISceneEx* scene, IContext* context, const String& name, UInt capacity ) :
	MeshBatchImpl<IPointMeshBatch, IPointMesh>( scene, context, AsBaseScene(scene)->GetPointMeshName(name), capacity )
{
}

INodeAnimationController* PointMeshBatch::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new PointMeshBatchAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

IPointSet* PointMeshBatch::CreatePointList( const String& name, UInt count, Float size, const ColorMode& colorMode, const Matrix4x4& transform )
{
	IProgram* program = _context->GetGraphicsSystem()->GetProgram( L"line.instanced" );
	gfx::IPrimitive* data = _context->GetGraphicsSystem()->GetDevice()->CreatePrimitive( program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::PointList, IndexType::None, count, 0, _instances.Capacity(), 0, true, false );
	ILineRenderQueue* queue = _scene->GetRenderQueue()->GetLineQueue();
	ILineRenderObject* object = queue->CreateObject( data );
	// TODO: size!!!
	if ( !name.IsNull() )
	{
		object->SetVertexParameters( program->GetVertexStage()->GetParameters()->Clone(object->ID(), true) );
	}
	P(IPointSet) subset = new PointSet( _context, object, 0, 0, size );
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

IPointSet* PointMeshBatch::CreatePointSet( const String& name, const Range& range )
{
	if ( _base.Primitive == nullptr )
		throw InvalidOperationException( L"Base primitive does not exist." );

	PointSet* base = (PointSet*)_base.Primitive.AsPtr();
	IPointSet* subset = base->CreateSubset( range.Start, range.Length );
	_subsets.Add( SubsetDesc(subset, _base.Primitive, name) );
	return subset;
}

void PointMeshBatch::SetColor( const Color& color )
{
	throw InvalidOperationException();
}

IPointMesh* PointMeshBatch::CreateInstance( INode* parent, const Matrix4x4& transform, const Color& color )
{
	assert( _instances.Size() < _instances.Capacity() );

	if ( _instances.Size() >= _instances.Capacity() )
		throw InvalidOperationException( L"Instance capacity is exceeded." );

	IPointMesh* instance = new PointMeshInstance( _context, this, String::Format(L"{0}.{1}", _name, _instances.Size()), _instances.Size(), transform );
	_instances.Add( InstanceDesc(parent, instance, transform, color) );
	SetInstanceTransform( _instances.Size()-1, transform );
	SetInstanceColor( _instances.Size()-1, color );
	SetRange( Range(0, _instances.Size()) );
	return instance;
}

void PointMeshBatch::RemoveInstance( UInt index )
{
	assert( _instances.Size() > 0 );

	for ( UInt i = index+1; i < _instances.Size(); ++i )
	{
		_instances[i-1] = _instances[i];
		SetInstanceTransform( i-1, _instances[i].Transform );
		SetInstanceColor( i-1, _instances[i].Color );
		((PointMeshInstance*)_instances[i-1].Mesh)->SetIndex( i-1 );
	}
	_instances.Remove( _instances.Size()-1 );
	SetRange( Range(0, _instances.Size()) );
}

void PointMeshBatch::SetInstanceTransform( UInt index, const Matrix4x4& transform )
{
	assert( index < _instances.Size() );

	Matrix4x4 worldTransform;
	Matrix4x4 primitiveTransform;
	IPointMesh* instance = _instances[index].Mesh->AsPoint();
	instance->GetWorldTransform( worldTransform );

	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		_subsets[i].Primitive->GetTransform( primitiveTransform );
		Matrix4x4 subsetTransform = worldTransform * primitiveTransform;
		_subsets[i].Primitive->SetInstanceTransform( index, subsetTransform );
	}
	_instances[index].Transform = transform;
}

void PointMeshBatch::SetInstanceColor( UInt index, const Color& color )
{
	assert( index < _instances.Size() );

	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		_subsets[i].Primitive->SetInstanceColor( index, color );
	}
	_instances[index].Color = color;
}

void PointMeshBatch::Update()
{
	NodeImpl<IPointMeshBatch>::ApplyConstraints( _ctrlAnimation );

	for ( UInt i = 0; i < _instances.Size(); ++i )
	{
		AsBaseNode( _instances[i].Mesh )->Update();
	}
}
	

} // scene


} // synkro
