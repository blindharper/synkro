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
#ifndef _SYNKRO_CORE_LIBRARY_
#define _SYNKRO_CORE_LIBRARY_


#include "config.h"
#include "ObjectImpl.h"
#include <core/ILibrary.h>
#include <internal/DynamicLibrary.h>


namespace synkro
{


namespace core
{


// Library module.
class Library :
	public ObjectImpl<ILibrary>
{
public:
	// Constructor & destructor.
	Library( const lang::String& path );
	~Library();

	// ILibrary methods.
	Bool													IsPerf() const;
	Bool													IsDebug() const;
	Bool													IsObject() const;
	Bool													IsString() const;
	Bool													IsResource() const;
	const Char*												GetName() const;
	const Char*												GetDescription() const;
	const Char*												GetAuthor() const;
	const Char*												GetCopyright() const;
	const Char*												GetComment() const;
	const Char*												GetLanguage() const;
	UInt													GetCoreVersion() const;
	UInt													GetVersion() const;
	UInt													GetResourceCount() const;
	IResource*												GetResource( UInt index ) const;
	UInt													GetFactoryCount() const;
	IFactory*												GetFactory( UInt index ) const;
	UInt													GetStringCount() const;
	const Char*												GetStringName( UInt index ) const;
	const Char*												GetStringValue( UInt index ) const;

	// Other methods.
	Bool													IsValid() const;

private:
	DynamicLibrary											_dll;
	SYNKRO_FUNC_GETBOOL										_funcIsPerf;
	SYNKRO_FUNC_GETBOOL										_funcIsDebug;
	SYNKRO_FUNC_GETSTRING									_funcGetName;
	SYNKRO_FUNC_GETSTRING									_funcGetDescription;
	SYNKRO_FUNC_GETSTRING									_funcGetAuthor;
	SYNKRO_FUNC_GETSTRING									_funcGetCopyright;
	SYNKRO_FUNC_GETSTRING									_funcGetComment;
	SYNKRO_FUNC_GETSTRING									_funcGetLanguage;
	SYNKRO_FUNC_GETUINT										_funcGetCoreVersion;
	SYNKRO_FUNC_GETUINT										_funcGetVersion;
	SYNKRO_FUNC_GETUINT										_funcGetResourceCount;
	SYNKRO_FUNC_GETRESOURCE									_funcGetResource;
	SYNKRO_FUNC_GETUINT										_funcGetFactoryCount;
	SYNKRO_FUNC_GETFACTORY									_funcGetFactory;
	SYNKRO_FUNC_GETUINT										_funcGetStringCount;
	SYNKRO_FUNC_GETSTRING_INDEX								_funcGetStringName;
	SYNKRO_FUNC_GETSTRING_INDEX								_funcGetStringValue;
};


#include "Library.inl"


} // core


} // synkro


#endif // _SYNKRO_CORE_LIBRARY_
