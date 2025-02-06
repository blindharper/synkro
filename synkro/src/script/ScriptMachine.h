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
#ifndef _SYNKRO_SCRIPT_SCRIPTMACHINE_
#define _SYNKRO_SCRIPT_SCRIPTMACHINE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <script/IScriptMachine.h>


namespace synkro
{


namespace script
{


// Logical script machine implementation.
class ScriptMachine :
	public core::ObjectImpl<IScriptMachine>
{
public:
	// Constructor.
	ScriptMachine( IScriptMachine* machine );

	// IScriptMachine methods.
	void													Execute( io::IStream* script );
	void													Execute( const lang::String& script );
	IScriptObject*											CreateObject( void* object, io::IStream* script, const ScriptMethod** methods, UInt methodCount );
	void													SetContext( IScriptObject* context );
	IScriptObject*											GetContext() const;
	lang::String											GetName() const;

private:
	P(IScriptMachine)										_machine;
};


#include "ScriptMachine.inl"


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_SCRIPTMACHINE_
