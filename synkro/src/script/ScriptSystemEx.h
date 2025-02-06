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
#ifndef _SYNKRO_SCRIPT_SCRIPTSYSTEMEX_
#define _SYNKRO_SCRIPT_SCRIPTSYSTEMEX_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <script/IScriptSystemEx.h>
#include <script/IScriptSystemFactory.h>
#include "ScriptMachine.h"


namespace synkro
{


namespace script
{


// Extended scripting system.
class ScriptSystemEx :
	public core::ObjectImpl<IScriptSystemEx>,
	public Logger
{
public:
	// Constructor & destructor.
	ScriptSystemEx( diag::ILog* log );
	~ScriptSystemEx();

	// ISystem methods.
	Bool													Update( Double delta );

	// IScriptSystem methods.
	IScriptMachine*											CreateMachine( const lang::String& name );

	// IScriptSystemEx method.
	UInt													GetMachineCount() const;
	IScriptMachine*											GetMachine( UInt index ) const;
	IScriptMachine*											GetMachine( const lang::String& name ) const;

	// Other methods.
	void													Initialize( IScriptSystemFactory* factory );

private:
	lang::Vector<P(ScriptMachine)>							_machines;
	IScriptSystemFactory*									_factory;
	P(IScriptSystem)										_system;
};


#include "ScriptSystemEx.inl"


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_SCRIPTSYSTEMEX_
