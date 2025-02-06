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
#ifndef _SYNKRO_SCRIPT_SCRIPTOBJECT_
#define _SYNKRO_SCRIPT_SCRIPTOBJECT_


#include "config.h"
#include <core/ObjectImpl.h>
#include <script/IScriptObject.h>


namespace synkro
{


namespace script
{


// Logical script object implementation.
class ScriptObject :
	public core::ObjectImpl<IScriptObject>
{
public:
	// Constructor.
	ScriptObject( IScriptMachine* machine, IScriptObject* object );

	// IScriptObject methods.
	void													Execute( io::IStream* script );
	void													AddMethods( const ScriptMethod** methods, UInt methodCount );
	IScriptMachine*											GetMachine() const;

private:
	friend class ScriptMachine;
	friend class ScriptParam;

	IScriptMachine*											_machine;
	P(IScriptObject)										_object;
};


#include "ScriptObject.inl"


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_SCRIPTOBJECT_
