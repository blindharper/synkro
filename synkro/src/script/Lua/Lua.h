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
// Purpose: LUA API.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_LUA_
#define _SYNKRO_SCRIPT_LUA_


#include "config.h"


extern "C"
{
#include <lua/lua.h>
#include <lua/lualib.h>
#include <lua/lauxlib.h>
}


namespace synkro
{


namespace script
{


// LUA API.
class Lua
{
public:
	static const Char*										ToString( int type );
};


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_LUA_
