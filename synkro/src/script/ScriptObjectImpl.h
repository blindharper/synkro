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
// Purpose: Generic script object implementation.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_SCRIPTOBJECTIMPL_
#define _SYNKRO_SCRIPT_SCRIPTOBJECTIMPL_


#include "config.h"
#include <core/ObjectImpl.h>


namespace synkro
{


namespace script
{


// Generic script object implementation.
template <class T>
class ScriptObjectImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	ScriptObjectImpl( IScriptMachine* machine );
	virtual ~ScriptObjectImpl();

	// IScriptObject methods.
	virtual IScriptMachine*									GetMachine() const;

protected:
	IScriptMachine*											_machine;
};


#include "ScriptObjectImpl.inl"


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_SCRIPTOBJECTIMPL_
