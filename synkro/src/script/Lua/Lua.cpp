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
#include "config.h"
#include "Lua.h"


namespace synkro
{


namespace script
{


const Char* Lua::ToString( int type )
{
	switch ( type )
	{
		case LUA_TNIL:				return L"LUA_TNIL";
		case LUA_TBOOLEAN:			return L"LUA_TBOOLEAN";
		case LUA_TLIGHTUSERDATA:	return L"LUA_TLIGHTUSERDATA";
		case LUA_TNUMBER:			return L"LUA_TNUMBER";
		case LUA_TSTRING:			return L"LUA_TSTRING";
		case LUA_TTABLE:			return L"LUA_TTABLE";
		case LUA_TFUNCTION:			return L"LUA_TFUNCTION";
		case LUA_TUSERDATA:			return L"LUA_TUSERDATA";
		case LUA_TTHREAD:			return L"LUA_TTHREAD";
		default:					return L"LUA_TNONE";
	}
}


} // script


} // synkro
