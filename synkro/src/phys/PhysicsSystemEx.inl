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
// Purpose: Extended physics system.
//==============================================================================
SYNKRO_INLINE ULong PhysicsSystemEx::GetEnvironmentCount() const
{
	return _environments.Size();
}

SYNKRO_INLINE IPhysicsEnvironment* PhysicsSystemEx::GetEnvironment( ULong index ) const
{
	assert( index < _environments.Size() );

	if ( index >= _environments.Size() )
		throw lang::OutOfRangeException( index, _environments.Size() );

	return _environments[index];
}

SYNKRO_INLINE IPhysicsEnvironment* PhysicsSystemEx::GetEnvironment( const lang::String& name ) const
{
	for ( UInt i = 0; i < _environments.Size(); ++i )
	{
		if ( name.EqualsTo(_environments[i]->GetName(), true) )
			return _environments[i];
	}
	return nullptr;
}
