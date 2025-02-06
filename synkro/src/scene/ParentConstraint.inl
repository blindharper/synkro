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
SYNKRO_INLINE void ParentConstraint::Enable( Bool enable )
{
	// Call base implementation.
	core::ConstraintImpl<IParentConstraint>::Enable( enable );

	if ( !_enabled )
	{
		_parent = _oldParent;
		Apply();
	}
}

SYNKRO_INLINE void ParentConstraint::SetParent( INode* parent )
{
	if ( parent != nullptr )
	{
		assert( _node != parent );
		if ( _node == parent )
			throw lang::InvalidOperationException( L"Node cannot be a parent of itself." );

		assert( _node->GetSceneEx() == parent->GetSceneEx() );
		if ( _node->GetSceneEx() != parent->GetSceneEx() )
			throw lang::InvalidOperationException( L"Both child and parent must belong to the same scene." );
	}

	_parent = parent;
}

SYNKRO_INLINE INode* ParentConstraint::GetParent() const
{
	return _parent;
}

SYNKRO_INLINE void ParentConstraint::GetTransform( math::Matrix4x4& transform ) const
{
	transform = _transform;
}
