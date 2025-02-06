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
// Purpose: Defines zip file based stream.
//==============================================================================
SYNKRO_INLINE void ZipStream::Open( const OpenMode& mode )
{
	// Skip if reopening in the same mode.
	if ( mode == _mode )
		return;

	// Prevent opening with read-write access.
	if ( mode.IsSet(OpenMode::Read) && mode.IsSet(OpenMode::Write) )
		throw IoException( lang::String::Format(L"Cannot open stream {0,q} for both reading and writing.", _path) );

	// Call base implementation.
	StreamImpl<IStream>::Open( mode );

	if ( !_zip->FileOpen(_path, mode) )
		throw IoException( lang::String::Format(L"Cannot open stream {0,q}.", _path) );
}

SYNKRO_INLINE void ZipStream::Close()
{
	// Call base implementation.
	StreamImpl<IStream>::Close();

	_zip->FileClose();
	_pos = 0L;
}

SYNKRO_INLINE void ZipStream::Flush()
{
	// Do nothing.
}

SYNKRO_INLINE UInt ZipStream::Read( void* data, UInt size )
{
	UInt bytes = _zip->FileRead( data, size );
	_pos += bytes;
	return bytes;
}

SYNKRO_INLINE UInt ZipStream::Write( const void* data, UInt size )
{
	UInt bytes = _zip->FileWrite( data, size );
	_pos += bytes;
	return bytes;
}

SYNKRO_INLINE Int ZipStream::Seek( Int bytes, const SeekOrigin& origin )
{
	UInt cnt = _zip->FileSeek( _path, _size, _pos, bytes, origin );
	_pos += cnt;
	return cnt;
}

SYNKRO_INLINE Bool ZipStream::Reset()
{
	Bool ok = _zip->FileReset( _path );
	if ( ok )
	{
		_pos = 0L;
	}
	return ok;
}

SYNKRO_INLINE void ZipStream::SetLength( UInt length )
{
	throw lang::NotSupportedException( L"Zip streams do not support setting length explicitly." );
}

SYNKRO_INLINE UInt ZipStream::GetLength() const
{
	return _size;
}

SYNKRO_INLINE UInt ZipStream::GetPosition() const
{
	return _pos;
}
