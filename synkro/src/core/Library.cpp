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
// Purpose: Library wrapper.
//==============================================================================
#include "config.h"
#include "Library.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


Library::Library( const String& path )
{
	constexpr UInt SIZE = 260;
	char buf[SIZE] = {};
	path.GetBytes( buf, SIZE );
	_dll.Open( buf );

	_funcGetName			= (SYNKRO_FUNC_GETSTRING)_dll.GetSymbol( "SynkroLibGetName" );
	_funcGetDescription		= (SYNKRO_FUNC_GETSTRING)_dll.GetSymbol( "SynkroLibGetDescription" );
	_funcGetAuthor			= (SYNKRO_FUNC_GETSTRING)_dll.GetSymbol( "SynkroLibGetAuthor" );
	_funcGetCopyright		= (SYNKRO_FUNC_GETSTRING)_dll.GetSymbol( "SynkroLibGetCopyright" );
	_funcGetComment			= (SYNKRO_FUNC_GETSTRING)_dll.GetSymbol( "SynkroLibGetComment" );
	_funcGetLanguage		= (SYNKRO_FUNC_GETSTRING)_dll.GetSymbol( "SynkroLibGetLanguage" );
	_funcGetCoreVersion		= (SYNKRO_FUNC_GETUINT)_dll.GetSymbol( "SynkroLibGetCoreVersion" );
	_funcGetVersion			= (SYNKRO_FUNC_GETUINT)_dll.GetSymbol( "SynkroLibGetVersion" );
	_funcIsPerf				= (SYNKRO_FUNC_GETBOOL)_dll.GetSymbol( "SynkroLibGetPerf" );
	_funcIsDebug			= (SYNKRO_FUNC_GETBOOL)_dll.GetSymbol( "SynkroLibGetDebug" );
	_funcGetResourceCount	= (SYNKRO_FUNC_GETUINT)_dll.GetSymbol( "SynkroLibGetResourceCount" );
	_funcGetResource		= (SYNKRO_FUNC_GETRESOURCE)_dll.GetSymbol( "SynkroLibGetResource" );
	_funcGetFactoryCount	= (SYNKRO_FUNC_GETUINT)_dll.GetSymbol( "SynkroLibGetFactoryCount" );
	_funcGetFactory			= (SYNKRO_FUNC_GETFACTORY)_dll.GetSymbol( "SynkroLibGetFactory" );
	_funcGetStringCount		= (SYNKRO_FUNC_GETUINT)_dll.GetSymbol( "SynkroLibGetStringCount" );
	_funcGetStringName		= (SYNKRO_FUNC_GETSTRING_INDEX)_dll.GetSymbol( "SynkroLibGetStringName" );
	_funcGetStringValue		= (SYNKRO_FUNC_GETSTRING_INDEX)_dll.GetSymbol( "SynkroLibGetStringValue" );
}

Library::~Library()
{
	_dll.Close();
}


} // core


} // synkro
