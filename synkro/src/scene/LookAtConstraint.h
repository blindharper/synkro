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
// Purpose: "Look at" constraint implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_LOOKATCONSTRAINT_
#define _SYNKRO_SCENE_LOOKATCONSTRAINT_


#include "config.h"
#include <core/ConstraintImpl.h>
#include <scene/ILookAtConstraint.h>
#include <scene/INode.h>
#include "DebugHelper.h"


namespace synkro
{


namespace scene
{


// "Look at" constraint implementation.
class LookAtConstraint :
	public core::ConstraintImpl<ILookAtConstraint>
{
public:
	// Constructor.
	LookAtConstraint( gfx::IGraphicsSystemEx* graphicsSystem, INode* node, INode* target );

	// IConstraint methods.
	void													Apply();
	void													Enable( Bool enable );

	// ILookAtConstraint methods.
	void													SetTarget( INode* target );
	INode*													GetTarget() const;

private:
	INode*													_node;
	INode*													_target;
	DebugHelper												_constraint;
};


#include "LookAtConstraint.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_LOOKATCONSTRAINT_
