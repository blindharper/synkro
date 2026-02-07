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
// Purpose: Triangle mesh implementation.
//==============================================================================
#include "config.h"
#include "TriangleMesh.h"
#include "NodeAnimationController.h"
#include "ParentConstraint.h"
#include "LookAtConstraint.h"
#include "TriangleSet.h"
#include <phys/IRigidActor.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::input;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::phys;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


TriangleMesh::TriangleMesh( ITriangleMesh* mesh, ISceneEx* scene, IContext* context, const String& name, ISkeleton* skeleton ) :
	MeshImpl<ITriangleMesh>( scene, context, AsBaseScene(scene)->GetTriangleMeshName(name), true ),
	_mesh( mesh ),
	_skeleton( skeleton ),
	_boneTransforms( A(Matrix4x4) )
{
	if ( _skeleton != nullptr )
	{
		_boneTransforms.SetSize( _skeleton->GetBoneCount() );
	}
}

INodeAnimationController* TriangleMesh::CreateAnimationController( IAnimationSet* animations, AnimationListener* listener )
{
	// Prevent creating animation controller if dynamic simulations are here.
	if ( GetActor() != nullptr )
		throw InvalidOperationException( L"Cannot create animation controller. Physics actor is non-null." );

	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new NodeAnimationController( this, _context->GetAnimationSystem(), animations, listener ) : _ctrlAnimation;
}

IParentConstraint* TriangleMesh::CreateParentConstraint( INode* parent, const Matrix4x4& transform )
{
	return (_parentConstraint == nullptr) ? _parentConstraint = new ParentConstraint( this, parent, transform ) : _parentConstraint;
}

ILookAtConstraint* TriangleMesh::CreateLookAtConstraint( INode* target )
{
	return (_lookAtConstraint == nullptr) ? _lookAtConstraint = new LookAtConstraint( _context->GetGraphicsSystem(), this, target ) : _lookAtConstraint;
}

void TriangleMesh::GetWorldTransform( Matrix4x4& transform ) const
{
	IRigidActor* rigidActor = (GetActor() != nullptr) ? GetActor()->AsRigid() : nullptr;
	if ( rigidActor != nullptr )
	{
		rigidActor->GetWorldTransform( transform );
	}
	else
	{
		MeshImpl<ITriangleMesh>::GetWorldTransform( transform );
	}
}

ITriangleSet* TriangleMesh::CreateTriangleList( const String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const Matrix4x4& transform )
{
	ITriangleSet* set = _mesh->CreateTriangleList( name, vertexCount, indexCount, adjacency, transform );
	P(ITriangleSet) subset = new TriangleSet( set, _context, _scene->GetDebugMode(), 0, 0 );
	return RegisterSubset( subset, name, transform );
}

ITriangleSet* TriangleMesh::CreateTriangleStrip( const String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const Matrix4x4& transform )
{
	ITriangleSet* set = _mesh->CreateTriangleStrip( name, vertexCount, indexCount, adjacency, transform );
	P(ITriangleSet) subset = new TriangleSet( set, _context, _scene->GetDebugMode(), 0, 0 );
	return RegisterSubset( subset, name, transform );
}

ITriangleSet* TriangleMesh::CreateTriangleSet( const String& name, const Range& range )
{
	ITriangleSet* set = _mesh->CreateTriangleSet( name, range );
	P(ITriangleSet) subset = new TriangleSet( set, _context, _scene->GetDebugMode(), range.Start, range.Length );
	_subsets.Add( SubsetDesc(subset, _base.Primitive, name) );
	return subset;
}

void TriangleMesh::Save( IStream* stream, const DataMode& mode, const MeshCodec& type )
{
	throw NotSupportedException();
}

void TriangleMesh::Save( IStream* stream, const DataMode& mode )
{
	throw NotSupportedException();
}

void TriangleMesh::SetActor( IActor* actor )
{
	assert( actor != nullptr );

	// Prevent setting actor if animation controller is here.
	if ( _ctrlAnimation != nullptr )
		throw InvalidOperationException( L"Cannot set actor. Animation controller is non-null." );

	_actor = actor;
}

void TriangleMesh::Update()
{
	// Get mesh world transform either from physics or from node hierarchy.
	IRigidActor* rigidActor = (GetActor() != nullptr) ? GetActor()->AsRigid() : nullptr;
	if ( rigidActor == nullptr )
	{
		NodeImpl<ITriangleMesh>::ApplyConstraints( _ctrlAnimation );
	}
	Matrix4x4 worldTransform;
	GetWorldTransform( worldTransform );

	// Set bone transforms.
	if ( _skeleton != nullptr )
	{
		Matrix4x4* transforms = _boneTransforms.Begin();
		_skeleton->GetBoneTransforms( worldTransform, &transforms, _boneTransforms.Size() );
		for ( UInt i = 0; i < _subsets.Size(); ++i )
		{
			_subsets[i].Primitive->AsTriangleSet()->SetBoneTransforms( _boneTransforms.Begin(), _boneTransforms.Size() );
		}
	}

	// Set subset transforms.
	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		_subsets[i].Primitive->SetOwnerTransform( worldTransform );
	}

	if ( _gizmo.IsCreated() )
	{
		_gizmo.SetTransform( worldTransform );
	}
}

ITriangleSet* TriangleMesh::RegisterSubset( ITriangleSet* subset, const String& name, const Matrix4x4& transform )
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
