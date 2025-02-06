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
#include "config.h"
#include "Win32StreamSystem.h"
#include "Win32Directory.h"
#include "Win32Stream.h"


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


Win32StreamSystem::Win32StreamSystem( ILog* log ) :
	StreamSystemImpl<IStreamSystem>( log )
{
}

Bool Win32StreamSystem::Update( Double delta )
{
	return true;
}

IStreamDirectory* Win32StreamSystem::MapDirectory( const String& path, Bool recursive )
{
	IStreamDirectory* dir = nullptr;

	if ( Path::IsDirectory(path) )
	{
		dir = new Win32Directory( nullptr, path, recursive, _log );
		_dirs.Add( dir );
	}

	return dir;
}

IStreamDirectory* Win32StreamSystem::BuildDirectory( const String& path )
{
	return new Win32Directory( nullptr, path, _log );
}

IStream* Win32StreamSystem::MapStream( const String& path )
{
	return Path::IsFile(path) ? new Win32Stream( nullptr, path ) : nullptr;
}

IStream* Win32StreamSystem::CreateStream( const String& name )
{
	return new Win32Stream( nullptr, name );
}


} // io


} // synkro
