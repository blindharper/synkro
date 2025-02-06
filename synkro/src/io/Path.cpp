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
// Purpose: Defines file system path.
//==============================================================================
#include "config.h"
#include "Path.h"
#include <core/Platform.h>
#include <internal/SizeOf.h>
#include <io.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------


static Bool PathExists( const String& path, Bool* dir )
{
	*dir = false;

	Char chars[260] = {};
	_wfinddata_t fileinfo;
	intptr_t handle = _wfindfirst( path.TrimEnd(L"/\\").GetChars(0, 260, chars), &fileinfo );
	if ( handle != -1 )
	{
		*dir = ( (_A_SUBDIR & fileinfo.attrib) != 0 );
		_findclose( handle );
	}

	return (handle != -1);
}

static UInt GetDirectoryEntries( const String& path, const String& mask, Vector<String>* entries, Bool dir )
{
	String fullpath = synkro::io::Path::Combine( path, mask );

	Char chars[260] = {};
	_wfinddata_t fileinfo;
	intptr_t handle = _wfindfirst( fullpath.GetChars(0, 260, chars), &fileinfo );
	if ( handle != -1 )
	{
		do
		{
			if ( fileinfo.name[0] != L'.' )
			{
				if ( ((_A_SUBDIR & fileinfo.attrib) != 0) == dir )
					entries->Add( fileinfo.name );
			}
		} while ( 0 == _wfindnext( handle, &fileinfo ) );

		_findclose( handle );
	}
	return entries->Size();
}


namespace synkro
{


namespace io
{


const Char Path::Delimiter = Platform::PathDelimiter;


String Path::GetName() const
{
	UInt start = _path.Replace(L'\\', L'/').LastIndexOf(L'/');
	return (start != none) ? _path.Substring(start+1) : _path;
}

String Path::GetExtension() const
{
	const UInt start = _path.LastIndexOf(L'.');
	return (start != none) ? _path.Substring(start) : String::Empty;
}

String Path::GetExtensionWoDot() const
{
	const UInt start = _path.LastIndexOf(L'.');
	return (start != none) ? _path.Substring(start+1) : String::Empty;
}

String Path::GetNameWoExtension() const
{
	const UInt idxDot = _path.LastIndexOf(L'.');
	return (idxDot != none) ? _path.Substring(0, idxDot) : _path;
}

String Path::GetBase() const
{
	UInt end = _path.Replace(L'\\', L'/').Trim(L"/").IndexOf(L'/');
	return (end != none) ? _path.Substring(0, end) : String::Empty;
}

String Path::GetParent() const
{
	UInt end = _path.Replace(L'\\', L'/').Trim(L"/").LastIndexOf(L'/');
	return (end != none) ? _path.Substring(0, end) : String::Empty;
}

String Path::RemoveBase() const
{
	UInt end = _path.Replace(L'\\', L'/').Trim(L"/").IndexOf(L'/');
	return (end != none) ? _path.Substring(end+1) : String::Empty;
}

Bool Path::Exists() const
{
	Bool dir;
	return PathExists( _path, &dir );
}

void Path::Initialize()
{
	const Char* const strings[] =
	{
		L".", L":", L"*", L"/", L"\\",
		L"/\\", L"..", L"..\\", L"*?|<>"
	};
	constexpr UInt count = SizeOf( strings );
	for ( UInt i = 0; i < count; ++i )
	{
		String(strings[i]).MakePermanent();
	}
}

Bool Path::IsValid( const String& path )
{
	return path.IndexOfAny( L"*?|<>" ) == none;
}

Bool Path::IsAbsolute( const String& path )
{
	return path.StartsWith(Delimiter) || (path.Length() > 2) && (path[1] == L':') && (path[2] == Delimiter);
}

Bool Path::IsDirectory( const String& path )
{
	Bool dir;
	return PathExists( path, &dir ) && dir;
}

Bool Path::IsFile( const String& path )
{
	Bool dir;
	return PathExists( path, &dir ) && !dir;
}

String Path::Combine( const String& path1, const String& path2 )
{
	String sep = L"/\\";

	String first = path1.TrimEnd( sep ).Replace( L'/', Delimiter );
	String second = path2.TrimStart( sep ).Replace( L'/', Delimiter );

	while ( second.StartsWith(L"..") )
	{
		second = second.TrimStart( L"." );
		second = second.TrimStart( L"/\\" );
		Path pathFirst( first );
		first = pathFirst.GetParent();
	}

	return first + String(Delimiter) + second;
}

String Path::MakeAbsolute( const String& base, const String& path )
{
	if ( Path::IsAbsolute(path) )
		return path;

	Path pathBase( base );
	if ( path.StartsWith(L"..\\") )
	{
		return MakeAbsolute( pathBase.GetParent(), path.Substring(3) );
	}

	return Path::Combine( pathBase.GetPath(), path );
}

UInt Path::GetDirs( const String& path, Vector<String>* dirs )
{
	return GetDirectoryEntries( path, L"*", dirs, true );
}

UInt Path::GetFiles( const String& path, const String& mask, Vector<String>* files )
{
	return GetDirectoryEntries( path, mask, files, false );
}


} // io


} // synkro
