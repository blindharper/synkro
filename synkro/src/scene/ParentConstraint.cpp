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
#include "config.h"
#include "ParentConstraint.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


ParentConstraint::ParentConstraint( INode* node, INode* parent, const Matrix4x4& transform ) :
	_node( node ),
	_transform( transform )
{
	_oldParent = node->GetParent();
	SetParent( parent );
}

void ParentConstraint::Apply()
{
	if ( _parent != nullptr )
	{
		_node->SetParent( _parent );

		// TODO: !!!
		/*math::Matrix4x4 parentTransform;
		_parent->GetTransform( parentTransform );

		math::Matrix4x4 nodeTransform = parentTransform * _transform;
		_node->SetTransform( nodeTransform );*/
	}
}


} // scene


} // synkro
