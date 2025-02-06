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
#include "config.h"
#include "ScriptSystemEx.h"
#include "ScriptMachine.h"


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace script
{


ScriptSystemEx::ScriptSystemEx( ILog* log ) :
	_machines( A(P(ScriptMachine)) ),
	_factory( nullptr ),
	_system( nullptr ),
	Logger( log, LogFacility::ScriptSystem )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating script system...") );
}

ScriptSystemEx::~ScriptSystemEx()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying script system...") );
}

Bool ScriptSystemEx::Update( Double delta )
{
	return true;
}

IScriptMachine* ScriptSystemEx::CreateMachine( const String& name )
{
	// Make sure machine name is unique.
	if ( GetMachine( name ) != nullptr )
		throw BadArgumentException( L"Script machine with this name already exists", L"name", name );

	// Create script machine.
	ScriptMachine* machine = new ScriptMachine( _system->CreateMachine(name) );
	_machines.Add( machine );
	return machine;
}

void ScriptSystemEx::Initialize( IScriptSystemFactory* factory )
{
	// Re-create network system, if needed.
	if ( factory != _factory )
	{
		_factory = factory;
		_system = nullptr;
		_system = factory->Create( _log );
	}
}


} // script


} // synkro
