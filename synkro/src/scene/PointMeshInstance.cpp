//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: http://synkro.org Email: mailto:blindharper70@gmail.com
//
// Purpose: Point mesh node instance implementation.
//==============================================================================
#include "config.h"
#include "PointMeshInstance.h"
#include "NodeAnimationController.h"
#include "ParentConstraint.h"
#include "LookAtConstraint.h"
#include "PointMesh.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


PointMeshInstance::PointMeshInstance( IContext* context, IPointMeshBatch* batch, const String& name, UInt index, const Matrix4x4& transform ) :
	NodeImpl<IPointMesh>( batch->GetSceneEx(), context, AsBaseScene(batch->GetSceneEx())->GetPointMeshName(name) ),
	_batch( batch ),
	_index( index ),
	_visible( true )
{
}

PointMeshInstance::~PointMeshInstance()
{
	_batch->RemoveInstance( _index );
}

INodeAnimationController* PointMeshInstance::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new NodeAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

IParentConstraint* PointMeshInstance::CreateParentConstraint( INode* parent, const Matrix4x4& transform )
{
	return (_parentConstraint == nullptr) ? _parentConstraint = new ParentConstraint( this, parent, transform ) : _parentConstraint;
}

ILookAtConstraint* PointMeshInstance::CreateLookAtConstraint( INode* target )
{
	return (_lookAtConstraint == nullptr) ? _lookAtConstraint = new LookAtConstraint( _context->GetGraphicsSystem(), this, target ) : _lookAtConstraint;
}

void PointMeshInstance::Update()
{
	NodeImpl<IPointMesh>::ApplyConstraints( _ctrlAnimation );

	if ( !_visible )
		return;

	_batch->SetInstanceTransform( _index, _transform );
}

void PointMeshInstance::SetIndex( UInt index )
{
	_index = index;
}


} // scene


} // synkro
