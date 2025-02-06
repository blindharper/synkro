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
SYNKRO_INLINE LuaRestoreStack::LuaRestoreStack( lua_State* lua ) :
	_lua( lua ),
	_top( lua_gettop(_lua) )
{
}

SYNKRO_INLINE LuaRestoreStack::~LuaRestoreStack()
{
	lua_settop( _lua, _top );
}
