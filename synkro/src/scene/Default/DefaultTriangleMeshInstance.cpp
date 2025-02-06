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
// Purpose: Default triangle mesh node instance implementation.
//==============================================================================
#include "config.h"
#include "DefaultTriangleMeshInstance.h"
#include <scene/NodeAnimationController.h>
#include <scene/ParentConstraint.h>
#include <scene/LookAtConstraint.h>
#include <scene/BaseMeshBatch.h>
#include <mat/BaseMaterial.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
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


DefaultTriangleMeshInstance::DefaultTriangleMeshInstance( ITriangleMeshBatch* batch, IVisualMaterial* material, ISkeleton* skeleton, const String& name, UInt index, const Matrix4x4& transform ) :
	_batch( batch ),
	_material( material ),
	_skeleton( skeleton ),
	_index( index ),
	_visible( true )
{
}

DefaultTriangleMeshInstance::~DefaultTriangleMeshInstance()
{
	_batch->RemoveInstance( _index );
}

INodeAnimationController* DefaultTriangleMeshInstance::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return nullptr;
}

IParentConstraint* DefaultTriangleMeshInstance::CreateParentConstraint( INode* parent, const Matrix4x4& transform )
{
	return nullptr;
}

ILookAtConstraint* DefaultTriangleMeshInstance::CreateLookAtConstraint( INode* target )
{
	return nullptr;
}

void DefaultTriangleMeshInstance::Save( IStream* stream, const DataMode& mode, const MeshCodec& type )
{
	// Do nothing.
}

void DefaultTriangleMeshInstance::Save( IStream* stream, const DataMode& mode )
{
	// Do nothing.
}

void DefaultTriangleMeshInstance::SetIndex( UInt index )
{
	AsBaseMaterial( _material.AsPtr() )->SetIndex( _index = index );
}


} // scene


} // synkro
