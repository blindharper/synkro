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
#include "config.h"
#include "LookAtConstraint.h"
#include <scene/ISceneEx.h>


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


LookAtConstraint::LookAtConstraint( IGraphicsSystemEx* graphicsSystem, INode* node, INode* target ) :
	_node( node ),
	_target( target )
{
	if ( _node->GetSceneEx()->GetDebugMode().IsSet(DebugMode::Constraints) )
	{
		_constraint.Create( graphicsSystem, _node->GetSceneEx(), 2, 0, Color::Red );
		_constraint.SetTransform( Matrix4x4::Identity );
	}
	SetTarget( target );
}

void LookAtConstraint::Apply()
{
	if ( _target != nullptr )
	{
		Matrix4x4 transTarget; Vector3 posTarget;
		_target->GetWorldTransform( transTarget );
		posTarget = transTarget.Translation();
		_node->LookAt( posTarget );

		if ( _enabled && _constraint.IsCreated() )
		{
			Matrix4x4 transNode; Vector3 posNode;
			_node->GetWorldTransform( transNode );
			posNode = transNode.Translation();

			Vector3 points[] =
			{
				Vector3( posNode ),
				Vector3( posTarget ),
			};
			_constraint.SetVertices( points, 2 );
		}
	}
}


} // scene


} // synkro
