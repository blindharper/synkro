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
// Purpose: Extended scripting system.
//=============================================================================
SYNKRO_INLINE UInt ScriptSystemEx::GetMachineCount() const
{
	return _machines.Size();
}

SYNKRO_INLINE IScriptMachine* ScriptSystemEx::GetMachine( UInt index ) const
{
	assert( index < _machines.Size() );

	if ( index >= _machines.Size() )
		throw lang::OutOfRangeException( index, _machines.Size() );

	return _machines[index];
}

SYNKRO_INLINE IScriptMachine* ScriptSystemEx::GetMachine( const lang::String& name ) const
{
	for ( UInt i = 0; i < _machines.Size(); ++i )
	{
		if ( _machines[i]->GetName() == name )
			return _machines[i];
	}

	return nullptr;
}
