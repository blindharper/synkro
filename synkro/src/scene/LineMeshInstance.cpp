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
// Purpose: Line mesh node instance implementation.
//==============================================================================
#include "config.h"
#include "LineMeshInstance.h"
#include "NodeAnimationController.h"
#include "ParentConstraint.h"
#include "LookAtConstraint.h"
#include "LineMesh.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


LineMeshInstance::LineMeshInstance( IContext* context, ILineMeshBatch* batch, const String& name, UInt index, const Matrix4x4& transform ) :
	NodeImpl<ILineMesh>( batch->GetSceneEx(), context, AsBaseScene(batch->GetSceneEx())->GetLineMeshName(name) ),
	_batch( batch ),
	_index( index ),
	_visible( false )
{
}

LineMeshInstance::~LineMeshInstance()
{
	_batch->RemoveInstance( _index );
}

INodeAnimationController* LineMeshInstance::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new NodeAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

IParentConstraint* LineMeshInstance::CreateParentConstraint( INode* parent, const Matrix4x4& transform )
{
	return (_parentConstraint == nullptr) ? _parentConstraint = new ParentConstraint( this, parent, transform ) : _parentConstraint;
}

ILookAtConstraint* LineMeshInstance::CreateLookAtConstraint( INode* target )
{
	return (_lookAtConstraint == nullptr) ? _lookAtConstraint = new LookAtConstraint( _context->GetGraphicsSystem(), this, target ) : _lookAtConstraint;
}

void LineMeshInstance::Update()
{
	NodeImpl<ILineMesh>::ApplyConstraints( _ctrlAnimation );

	if ( !_visible )
		return;

	_batch->SetInstanceTransform( _index, _transform );
}

void LineMeshInstance::SetIndex( UInt index )
{
	_index = index;
}


} // scene


} // synkro
