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
#include "config.h"
#include "Win32Directory.h"
#include "Win32Stream.h"
#include <io/Path.h>


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


Win32Directory::Win32Directory( IStreamDirectory* parent, const String& path, Bool recursive, ILog* log ) :
	StreamDirectoryImpl<IStreamDirectory>( parent, path ),
	Logger( log, LogFacility::StreamSystem )
{
	HANDLE hFind = nullptr;
	WIN32_FIND_DATAW wfd;
	wchar_t filename[MAX_PATH];

	// Get files.
	Zero( &wfd );
	String pathFiles = Path::Combine( _path, L"*" );
	pathFiles.GetChars( 0, MAX_PATH, filename );
	hFind = ::FindFirstFileW( filename, &wfd );
	if ( hFind != INVALID_HANDLE_VALUE )
	{
		while ( ::FindNextFileW(hFind, &wfd) == TRUE )
		{
			// Skip current & parent folders.
			if ( wfd.cFileName[0] == L'.' )
				continue;

			// Skip hidden files.
			if ( (wfd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) == FILE_ATTRIBUTE_HIDDEN )
				continue;

			// Add path.
			if ( (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY )
			{
				if ( recursive )
				{
					String fullpath = Path::Combine( _path, wfd.cFileName );
					LogInfo( MessagePriority::Low, Formatter::Format(L"Adding path {0,q}...", fullpath) );
					_dirs.Add( new Win32Directory(this, fullpath, recursive, _log) );
				}
			}
			else
			{
				String fullpath = (_path.Length() > 2) ? Path::Combine( _path, wfd.cFileName ) : wfd.cFileName;
				_streams.Add( new Win32Stream(this, fullpath) );
			}
		}

		::FindClose( hFind );
	}
}

Win32Directory::Win32Directory( IStreamDirectory* parent, const String& path, ILog* log ) :
	StreamDirectoryImpl<IStreamDirectory>( parent, path ),
	Logger( log, LogFacility::StreamSystem )
{
	LogInfo( MessagePriority::Low, Formatter::Format(L"Creating path {0,q}...", path) );

	CreatePath( path );
}

IStreamDirectory* Win32Directory::CreateDirectory( const String& name )
{
	IStreamDirectory* dir = GetDirectory( name );
	if ( dir == nullptr )
	{
		Path pathName( name );
		String strBase = pathName.GetBase();
		if ( !strBase.IsEmpty() )
		{
			String fullpath = Path::Combine( _path, strBase );
			IStreamDirectory* dir0 = new Win32Directory( this, fullpath, _log );
			String strName = pathName.RemoveBase();
			if ( !strName.IsEmpty() )
			{
				dir = dir0->CreateDirectory( strName );
			}
			_dirs.Add( dir0 );
		}
		else
		{
			String fullpath = Path::Combine( _path, name );
			dir = new Win32Directory( this, fullpath, _log );
			_dirs.Add( dir );
		}
	}
	return dir;
}

IStream* Win32Directory::CreateStream( const String& name )
{
	IStream* str = GetStream( name );
	if ( str == nullptr )
	{
		Path pathName( name );
		String parent = pathName.GetParent();
		if ( !parent.IsEmpty() )
		{
			IStreamDirectory* dir = CreateDirectory( parent );
			str = dir->CreateStream( pathName.GetName() );
		}
		else
		{
			String fullpath = Path::Combine( _path, name );
			str = new Win32Stream( this, fullpath );
			_streams.Add( str );
		}
	}
	return str;
}

void Win32Directory::CreatePath( const String& path )
{
	Char buf[1024] = {};
	path.GetChars( 0, 1024, buf );
	::CreateDirectoryW( buf, nullptr );
	if ( !Path::IsDirectory(path) )
		throw IoException( String::Format(L"Failed to create directory {0,q}", path) );
}


} // io


} // synkro
