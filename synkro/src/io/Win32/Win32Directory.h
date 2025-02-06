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
// Purpose: Win32 stream directory.
//==============================================================================
#ifndef _SYNKRO_IO_WIN32DIRECTORY_
#define _SYNKRO_IO_WIN32DIRECTORY_


#include "config.h"
#include <io/StreamDirectoryImpl.h>
#include <io/IStreamDirectory.h>


namespace synkro
{


namespace io
{


// Win32 stream directory.
class Win32Directory :
	public StreamDirectoryImpl<IStreamDirectory>,
	public Logger
{
public:
	// Constructors.
	Win32Directory( IStreamDirectory* parent, const lang::String& path, Bool recursive, diag::ILog* log );
	Win32Directory( IStreamDirectory* parent, const lang::String& path, diag::ILog* log );

	// IStreamDirectory methods.
	IStreamDirectory*										CreateDirectory( const lang::String& name );
	IStream*												CreateStream( const lang::String& name );

private:
	void													CreatePath( const lang::String& path );
};


} // io


} // synkro


#endif // _SYNKRO_IO_WIN32DIRECTORY_
