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
// Purpose: Helper class for Lua stack restoration.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_LUARESTORESTACK_
#define _SYNKRO_SCRIPT_LUARESTORESTACK_


#include "config.h"
#include "Lua.h"


namespace synkro
{


namespace script
{


// Lua stack restorator.
class LuaRestoreStack
{
public:
	// Constructor & destructor.
	LuaRestoreStack( lua_State* lua );
	~LuaRestoreStack();

private:
	lua_State*												_lua;
	int														_top;

	LuaRestoreStack( const LuaRestoreStack& );
	LuaRestoreStack& operator=( const LuaRestoreStack& );
};


#include "LuaRestoreStack.inl"


} // script


} // synkro



#endif // _SYNKRO_SCRIPT_LUARESTORESTACK_
