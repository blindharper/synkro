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
// Purpose: Implements binary stream.
//==============================================================================
#include "config.h"
#include "BinaryStream.h"
#include "SeekOriginConst.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


BinaryStream::BinaryStream( const Byte* data, UInt size ) :
	StreamImpl<IStream>( nullptr, String::Empty ),
	_buffer( A(Byte), size ),
	_position( 0L )
{
	if ( data != nullptr )
	{
		_buffer.Add( data, size );
	}
}

BinaryStream::BinaryStream( IStreamDirectory* directory ) :
	StreamImpl<IStream>( directory, String::Empty ),
	_buffer( A(Byte) ),
	_position( 0L )
{
}

BinaryStream::BinaryStream() :
	StreamImpl<IStream>( nullptr, String::Empty ),
	_buffer( A(Byte) ),
	_position( 0L )
{
}

void BinaryStream::Open( const OpenMode& mode )
{
	// Skip if reopening in the same mode.
	if ( mode == _mode )
		return;

	// Call base implementation.
	StreamImpl<IStream>::Open( mode );

	// Set initial position.
	if ( _mode == OpenMode::Append )
	{
		_position = _buffer.Size();
	}
	else if ( _mode == OpenMode::Write )
	{
		_buffer.Clear();
		_position = 0L;
	}
	else
	{
		_position = 0L;
	}
}

void BinaryStream::Flush()
{
	// Do nothing.
}

UInt BinaryStream::Read( void* data, UInt size )
{
	assert( _mode.IsSet(OpenMode::Read) );

	// Sanity check.
	if ( _mode.IsNotSet(OpenMode::Read) )
		throw IoException( L"Stream is not open for reading." );

	// Read elements.
	UInt sz = GetLength() - _position;
	if ( sz > size )
	{
		sz = size;
	}

	if ( sz > 0 )
	{
		_buffer.Get( _position, (Byte*)data, sz );
		_position += sz;
	}
	return sz;
}

UInt BinaryStream::Write( const void* data, UInt size )
{
	assert( _mode.IsSet(OpenMode::Write) || _mode.IsSet(OpenMode::Append) );

	// Sanity check.
	if ( _mode.IsNotSet(OpenMode::Write) && _mode.IsNotSet(OpenMode::Append) )
		throw IoException( L"Stream is not open for writing." );

	// Copy elements.
	_buffer.Add( (const Byte*)data, CastUInt(size) );

	// Update stream position.
	_position += size;

	return size;
}

Int BinaryStream::Seek( Int bytes, const SeekOrigin& origin )
{
	UInt posOld = _position;
	Int pos = 0L;
	switch ( origin )
	{
		case SEEK_ORIGIN_START:
			pos = bytes;
			break;

		case SEEK_ORIGIN_CURRENT:
			pos = _position + bytes;
			break;

		case SEEK_ORIGIN_END:
			pos = _buffer.Size() - bytes;
			break;
	}
	_position = max( 0, min(CastUInt(pos), _buffer.Size()-1) );
	return Int(_position-posOld);
}

Bool BinaryStream::Reset()
{
	_position = 0;
	return true;
}

void BinaryStream::SetLength( UInt length )
{
	_buffer.SetSize( length );
	_position = max( 0L, min(_position, _buffer.Size()-1) );
}

UInt BinaryStream::GetLength() const
{
	return _buffer.Size();
}

UInt BinaryStream::GetPosition() const
{
	return _position;
}


} // io


} // synkro
