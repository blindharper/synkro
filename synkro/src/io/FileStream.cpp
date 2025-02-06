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
// Purpose: Implements file-based stream.
//==============================================================================
#include "config.h"
#include "FileStream.h"
#include "Path.h"
#include <io/FileNotFoundException.h>
#include <io.h>
#include <share.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


FileStream::FileStream( const String& path ) :
	StreamImpl<IStream>( nullptr, PathToName(path) ),
	_stream( nullptr )
{
	_dir = PathToDir( path );
}

void FileStream::Open( const OpenMode& mode )
{
	// Skip if reopening in the same mode.
	if ( mode == _mode )
		return;

	// Call base implementation.
	StreamImpl<IStream>::Open( mode );

	// Build open mode string.
	Char mod[8] = {}; UInt idx = 0;
	if ( mode.IsSet(OpenMode::Append) )
	{
		mod[idx++] = 'a';
		mod[idx++] = 'b';
		if ( mode.IsSet(OpenMode::Read) )
			mod[idx++] = '+';
	}
	else if ( mode.IsSet(OpenMode::Read) )
	{
		mod[idx++] = 'r';
		mod[idx++] = 'b';
		if ( mode.IsSet(OpenMode::Write) )
			mod[idx++] = '+';
	}
	else if ( mode.IsSet(OpenMode::Write) )
	{
		mod[idx++] = 'w';
		mod[idx++] = 'b';
	}
	mod[idx++] = 0;

	// Try opening file.
	Char buf[260] = {};
	String fullpath = (_dir.Length() > 2) ? Path::Combine( _dir, _name ) : _name;
	fullpath.GetChars( 0, 260, buf );
	if ( !(_stream = _wfsopen(buf, mod, _SH_DENYWR)) )
	{
		if ( (mod[0] == L'r') && (mod[2] == L'+') )
		{
			mod[0] = L'w';
			_stream = _wfsopen( buf, mod, _SH_DENYWR );
		}

		if ( !_stream )
			throw FileNotFoundException( String::Format(L"Failed to open file for {0}.", (mod[0]==L'r')?L"reading":L"writing"), _name );
	}
}

void FileStream::Close()
{
	// Call base implementation.
	StreamImpl<IStream>::Close();

	if ( _stream != nullptr )
	{
		fflush( _stream );
		fclose( _stream );
		_stream = nullptr;
	}
}

void FileStream::Flush()
{
	assert( _stream != nullptr );

	if ( fflush( _stream ) == EOF )
		throw IoException( String::Format(L"Cannot flush file stream {0}.", _name) );
}

UInt FileStream::Read( void* data, UInt size )
{
	assert( _stream != nullptr );

	UInt bytes = 0;
	try
	{
		bytes = CastUInt( fread(data, 1, size, _stream) );
	}
	catch ( ... )
	{
		throw IoException( String::Format(L"Failed to read from file {0}.", _name) );
	}
	return bytes;
}

UInt FileStream::Write( const void* data, UInt size )
{
	assert( _stream != nullptr );

	return CastUInt( fwrite(data, 1, size, _stream) );
}

Int FileStream::Seek( Int bytes, const SeekOrigin& origin )
{
	assert( _stream != nullptr );

	fpos_t from, to;
	fgetpos( _stream, &from );
	fseek( _stream, bytes, (int)origin );
	fgetpos( _stream, &to );

	return CastInt(to-from);
}

Bool FileStream::Reset()
{
	assert( _stream != nullptr );

	return ( fseek(_stream, 0, SEEK_SET) == 0 );
}

void FileStream::SetLength( UInt length )
{
	assert( _stream != nullptr );

	const int d = _fileno( _stream );
	_chsize( d, (long)length );
}

Bool FileStream::Exists() const
{
	FILE* stream;

	Char buf[260] = {};
	String fullpath = (_dir.Length() > 2) ? Path::Combine( _dir, _name ) : _name;
	fullpath.GetChars( 0, 260, buf );
	if ( stream = _wfsopen(buf, L"rb", _SH_DENYWR) )
	{
		fclose( stream );
		return true;
	}
	return false;
}

UInt FileStream::GetLength() const
{
	assert( _stream != nullptr );

	const int d = _fileno( _stream );
	return CastUInt( _filelength(d) );
}

UInt FileStream::GetPosition() const
{
	assert( _stream != nullptr );

	return CastUInt( ftell(_stream) );
}

String FileStream::PathToDir( const String& path )
{
	Path file( path );
	return file.GetParent();
}

String FileStream::PathToName( const String& path )
{
	Path file( path );
	String dir = file.GetParent();
	return (dir.Length() > 2) ? file.GetName() : path;
}


} // io


} // synkro
