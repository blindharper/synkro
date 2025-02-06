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
// Purpose: Logical script object implementation.
//==============================================================================
#include "config.h"
#include "ScriptObject.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace script
{


ScriptObject::ScriptObject( IScriptMachine* machine, IScriptObject* object ) :
	_machine( machine ),
	_object( object )
{
}

IScriptMachine* ScriptObject::GetMachine() const
{
	return _machine;
}


} // script


} // synkro
