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
// Purpose: Parent constraint implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_PARENTCONSTRAINT_
#define _SYNKRO_SCENE_PARENTCONSTRAINT_


#include "config.h"
#include <core/ConstraintImpl.h>
#include <scene/IParentConstraint.h>
#include <scene/INode.h>


namespace synkro
{


namespace scene
{


// Parent constraint implementation.
class ParentConstraint :
	public core::ConstraintImpl<IParentConstraint>
{
public:
	// Constructor.
	ParentConstraint( INode* node, INode* parent, const math::Matrix4x4& transform );

	// IConstraint methods.
	void													Apply();
	void													Enable( Bool enable );

	// IParentConstraint methods.
	void													SetParent( INode* parent );
	INode*													GetParent() const;
	void													GetTransform( math::Matrix4x4& transform ) const;

private:
	INode*													_node;
	INode*													_parent;
	INode*													_oldParent;
	math::Matrix4x4											_transform;
};


#include "ParentConstraint.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_PARENTCONSTRAINT_
