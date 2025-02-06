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
#include "config.h"
#include "ScriptMachine.h"
#include "ScriptObject.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace script
{


ScriptMachine::ScriptMachine( IScriptMachine* machine ) :
	_machine( machine )
{
}

IScriptObject* ScriptMachine::CreateObject( void* object, io::IStream* script, const ScriptMethod** methods, UInt methodCount )
{
	return new ScriptObject( this, _machine->CreateObject(object, script, methods, methodCount) );
}

void ScriptMachine::SetContext( IScriptObject* context )
{
	_machine->SetContext( ((ScriptObject*)context)->_object );
}


} // script


} // synkro
