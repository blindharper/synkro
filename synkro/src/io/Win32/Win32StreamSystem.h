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
// Purpose: Win32 stream system.
//==============================================================================
#ifndef _SYNKRO_IO_WIN32STREAMSYSTEM_
#define _SYNKRO_IO_WIN32STREAMSYSTEM_


#include "config.h"
#include <io/StreamSystemImpl.h>
#include <io/IStreamSystem.h>
#include <io/IStreamDirectoryFactory.h>


namespace synkro
{


namespace io
{


// Win32 stream system.
class Win32StreamSystem :
	public StreamSystemImpl<IStreamSystem>
{
public:
	// Constructor.
	Win32StreamSystem( diag::ILog* log );

	// ISystem methods.
	Bool													Update( Double delta );

	// IStreamSystem methods.
	IStreamDirectory*										MapDirectory( const lang::String& path, Bool recursive );
	IStreamDirectory*										BuildDirectory( const lang::String& path );
	IStream*												MapStream( const lang::String& path );
	IStream*												CreateStream( const lang::String& name );
};


} // io


} // synkro


#endif // _SYNKRO_IO_WIN32STREAMSYSTEM_
