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
SYNKRO_INLINE void LookAtConstraint::Enable( Bool enable )
{
	// Call base implementation.
	core::ConstraintImpl<ILookAtConstraint>::Enable( enable );

	_constraint.Show( enable );
}

SYNKRO_INLINE void LookAtConstraint::SetTarget( INode* target )
{
	if ( target != nullptr )
	{
		assert( _node != target );
		if ( _node == target )
			throw lang::InvalidOperationException( L"Node cannot observe itself." );

		assert( _node->GetSceneEx() == target->GetSceneEx() );
		if ( _node->GetSceneEx() != target->GetSceneEx() )
			throw lang::InvalidOperationException( L"Both observer and target must belong to the same scene." );
	}

	_target = target;
	_constraint.Show( _enabled && (_target != nullptr) );
}

SYNKRO_INLINE INode* LookAtConstraint::GetTarget() const
{
	return _target;
}
