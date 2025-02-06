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
// Purpose: Win32 file stream.
//==============================================================================
#include "config.h"
#include "Win32Stream.h"
#include <io/Path.h>
#include <io/SeekOriginConst.h>
#include <io/FileNotFoundException.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


Win32Stream::Win32Stream( IStreamDirectory* directory, const String& path ) :
	StreamImpl<IStream>( directory, PathToName(path) ),
	_file( nullptr ),
	_fileMapping( nullptr ),
	_data( nullptr ),
	_size( 0L ),
	_pos( 0L )
{
	_dir = PathToDir( path );
}

void Win32Stream::Open( const OpenMode& mode )
{
	// Skip if reopening in the same mode.
	if ( mode == _mode )
		return;

	// Call base implementation.
	StreamImpl<IStream>::Open( mode );

	DWORD dwDesiredAccess = 0;
	DWORD dwShareMode = FILE_SHARE_READ;
	DWORD dwCreationDisposition = 0;
	DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL;

	// Set access mode.
	if ( _accessMode == AccessMode::Sequential )
	{
		dwFlagsAndAttributes |= FILE_FLAG_SEQUENTIAL_SCAN;
	}
	else if ( _accessMode == AccessMode::Random )
	{
		dwFlagsAndAttributes |= FILE_FLAG_RANDOM_ACCESS;
	}

	// Build open mode.
	if ( mode.IsSet(OpenMode::Append) )
	{
		dwCreationDisposition = OPEN_ALWAYS;
		dwDesiredAccess |= FILE_APPEND_DATA | SYNCHRONIZE;
		if ( mode.IsSet(OpenMode::Read) )
			dwDesiredAccess |= FILE_GENERIC_READ;
	}
	else if ( mode.IsSet(OpenMode::Read) )
	{
		dwCreationDisposition = OPEN_EXISTING;
		dwDesiredAccess |= FILE_GENERIC_READ;
		if ( mode.IsSet(OpenMode::Write) )
		{
			dwCreationDisposition = OPEN_ALWAYS;
			dwDesiredAccess |= FILE_GENERIC_WRITE;
		}
	}
	else if ( mode.IsSet(OpenMode::Write) )
	{
		dwCreationDisposition = CREATE_ALWAYS;
		dwDesiredAccess |= FILE_GENERIC_WRITE;
	}

	// Try opening file.
	Char buf[260] = {};
	String fullpath = (_dir.Length() > 2) ? Path::Combine( _dir, _name ) : _name;
	if ( (_file = ::CreateFileW(fullpath.GetChars(0, 260, buf), dwDesiredAccess, dwShareMode, nullptr, dwCreationDisposition, dwFlagsAndAttributes, nullptr)) == INVALID_HANDLE_VALUE )
		throw FileNotFoundException( String::Format(L"Failed to open file for {0}.", ((dwDesiredAccess & GENERIC_READ)==GENERIC_READ)?L"reading":L"writing"), _name );

	// Create file mapping for read-only access.
	_size = CastUInt( ::GetFileSize(_file, nullptr) );
	if ( (mode == OpenMode::Read) && (_size > 0L) )
	{
		_fileMapping = ::CreateFileMapping( _file, nullptr, PAGE_READONLY, 0, 0, nullptr );
		if ( _fileMapping != nullptr )
		{
			_data = (Byte*)::MapViewOfFile( _fileMapping, FILE_MAP_READ, 0, 0, _size );
			if ( _data == nullptr )
			{
				::CloseHandle( _fileMapping );
			}
		}
	}
}

void Win32Stream::Close()
{
	// Call base implementation.
	StreamImpl<IStream>::Close();

	// Remove file mapping.
	if ( _fileMapping != nullptr )
	{
		::UnmapViewOfFile( _data );
		::CloseHandle( _fileMapping );
		_fileMapping = nullptr;
		_data = nullptr;
	}

	// CLose file handle.
	if ( _file != nullptr )
	{
		Flush();
		::CloseHandle( _file );
		_file = nullptr;
		_pos = 0L;
	}
}

void Win32Stream::Flush()
{
	if ( _file != nullptr )
	{
		::FlushFileBuffers( _file );
	}
}

UInt Win32Stream::Read( void* data, UInt size )
{
	assert( _file != nullptr );

	DWORD bytes = 0;
	try
	{
		if ( _fileMapping != nullptr )
		{
			if ( _pos < _size )
			{
				Copy( (Byte*)data, _data+_pos, size );
				bytes = size;
			}
		}
		else
		{
			BOOL ok = ::ReadFile( _file, data, size, &bytes, nullptr );
		}
	}
	catch ( ... )
	{
		throw IoException( String::Format(L"Failed to read from file {0}.", _name) );
	}
	_pos += bytes;
	return CastUInt(bytes);
}

UInt Win32Stream::Write( const void* data, UInt size )
{
	assert( _file != nullptr );

	DWORD bytes = 0;
	BOOL ok = ::WriteFile( _file, data, size, &bytes, nullptr );
	_pos += bytes;
	return CastUInt(bytes);
}

Int Win32Stream::Seek( Int bytes, const SeekOrigin& origin )
{
	assert( _file != nullptr );

	if ( _fileMapping != nullptr )
	{
		const UInt from = _pos;
		switch ( origin )
		{
			case SEEK_ORIGIN_START:
				_pos = CastUInt(bytes);
				break;

			case SEEK_ORIGIN_CURRENT:
				_pos += bytes;
				break;

			case SEEK_ORIGIN_END:
				_pos = _size - bytes;
				break;
		}
		return CastLong(_pos) - CastLong(from);
	}
	else
	{
		const DWORD from = (DWORD)_pos;
		_pos = ::SetFilePointer( _file, (LONG)bytes, nullptr, (DWORD)origin );
		return CastLong(_pos) - CastLong(from);
	}
}

Bool Win32Stream::Reset()
{
	assert( _file != nullptr );

	if ( _fileMapping != nullptr )
	{
		_pos = 0L;
		return true;
	}
	else
	{
		Bool ok = (::SetFilePointer(_file, 0L, nullptr, FILE_BEGIN) == 0);
		if ( ok )
		{
			_pos = 0L;
		}
		return ok;
	}
}

void Win32Stream::Delete()
{
	constexpr UInt SIZE = 260;
	Char buf[SIZE] = {};
	String fullpath = (_dir.Length() > 2) ? Path::Combine( _dir, _name ) : _name;
	Close();
	::DeleteFileW( fullpath.GetChars(0, SIZE, buf) );
}

void Win32Stream::SetLength( UInt length )
{
	assert( _file != nullptr );

	const DWORD dwPos = ::SetFilePointer( _file, (LONG)length, nullptr, FILE_BEGIN );
	if ( dwPos == (DWORD)length )
	{
		::SetEndOfFile( _file );
	}
}

Bool Win32Stream::Exists() const
{
	Char buf[260] = {};
	String fullpath = (_dir.Length() > 2) ? Path::Combine( _dir, _name ) : _name;
	HANDLE file = ::CreateFileW( fullpath.GetChars( 0, 260, buf ), FILE_GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL|FILE_FLAG_RANDOM_ACCESS, nullptr );
	if ( file != INVALID_HANDLE_VALUE )
	{
		::CloseHandle( file );
		return true;
	}
	return false;
}

UInt Win32Stream::GetLength() const
{
	return (_file != nullptr) ? CastUInt(::GetFileSize(_file, nullptr)) : 0L;
}

UInt Win32Stream::GetPosition() const
{
	return _pos;
}

String Win32Stream::PathToDir( const String& path )
{
	Path file( path );
	return file.GetParent();
}

String Win32Stream::PathToName( const String& path )
{
	Path file( path );
	String dir = file.GetParent();
	return (dir.Length() > 2) ? file.GetName() : path;
}


} // io


} // synkro
