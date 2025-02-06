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
// Purpose: Logical script machine implementation.
//==============================================================================
SYNKRO_INLINE void ScriptMachine::Execute( io::IStream* script )
{
	assert( script != nullptr );

	_machine->Execute( script );
}

SYNKRO_INLINE void ScriptMachine::Execute( const lang::String& script )
{
	assert( script != lang::String::Empty );

	_machine->Execute( script );
}

SYNKRO_INLINE IScriptObject* ScriptMachine::GetContext() const
{
	return _machine->GetContext();
}

SYNKRO_INLINE lang::String ScriptMachine::GetName() const
{
	return _machine->GetName();
}
