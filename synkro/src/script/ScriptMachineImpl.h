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
// Purpose: Generic script machine implementation.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_SCRIPTMACHINEIMPL_
#define _SYNKRO_SCRIPT_SCRIPTMACHINEIMPL_


#include "config.h"
#include <core/ObjectImpl.h>


namespace synkro
{


namespace script
{


// Generic script machine implementation.
template <class T>
class ScriptMachineImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	ScriptMachineImpl( const lang::String& name );
	virtual ~ScriptMachineImpl();

	// IScriptMachine methods.
	virtual void											SetContext( IScriptObject* context );
	virtual IScriptObject*									GetContext() const;
	virtual lang::String									GetName() const;

protected:
	lang::String											_name;
	IScriptObject*											_context;
};


#include "ScriptMachineImpl.inl"


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_SCRIPTMACHINEIMPL_
