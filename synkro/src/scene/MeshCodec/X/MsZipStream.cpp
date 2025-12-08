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
// Purpose: MS compressed stream.
//==============================================================================
#include "config.h"
#include "MsZipStream.h"
#include <io/BinaryStream.h>
#include <lang/Vector.h>


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


MsZipStream::MsZipStream( IStream* stream, Bool binary, Int windowBits ) :
	_stream( stream ),
	_size( 0 )
{
	// Skip MSZIP file header.
	_stream->Seek( 6, SeekOrigin::Current );

	// Remember start position.
	const UInt startPosition = _stream->GetPosition();
	
	// Estimate decompressed size.
	UShort offset; UShort magic;
	UInt length = _stream->GetLength();
	while ( _stream->GetPosition()+3 < length )
	{
		// Read block offset.
		offset = 0;
		_stream->Read( &offset, sizeof(UShort) );

		// Read block magic.
		magic = 0;
		_stream->Read( &magic, sizeof(UShort) );
		if ( magic != MSZIP_MAGIC )
			throw Exception( L"Wrong MSZIP header." );

		// Advance to the next block.
		_stream->Seek( CastInt(offset), SeekOrigin::Current );
		_size += MSZIP_BLOCK_SIZE;
	}

	// Rewind underlying stream to the start.
	const UInt endPosition = _stream->GetPosition();
	const Int len = -CastInt(endPosition - startPosition);
	_stream->Seek( len, SeekOrigin::Current );

	// Setup zlib stream.
	_zStream.opaque = Z_NULL;
	_zStream.zalloc = Z_NULL;
	_zStream.zfree = Z_NULL;
	_zStream.data_type = binary ? Z_BINARY : Z_ASCII;

	if ( windowBits == 0 )
	{
		inflateInit( &_zStream );
	}
	else
	{
		inflateInit2( &_zStream, windowBits );
	}
}

IStream* MsZipStream::Decompress()
{
	Vector<Byte> compressed( A(Byte), _stream->GetLength()-(16+6) );
	compressed.SetSize( compressed.Capacity() );
	_stream->Read( compressed.Begin(), compressed.Size() );

	Vector<Byte> data( A(Byte), _size+1 );
	data.SetSize( data.Capacity() );
	Byte* out = data.Begin();

	Byte* ptr = compressed.Begin();
	Byte* ptrEnd = ptr + compressed.Size();

	UShort offset;
	while ( (ptr+3) < ptrEnd )
	{
		// Read block offset.
		offset = *((UShort*)ptr);
		ptr += 4;

		// Decompress data.
		out += DecompressBlock( ptr, offset, out, MSZIP_BLOCK_SIZE );
		ptr += offset;
	}

	// Return decompressed stream.
	IStream* stream = new BinaryStream( data.Begin(), data.Size() );
	stream->Open( OpenMode::Read );
	return stream;
}

size_t MsZipStream::DecompressBlock( const void* data, size_t in, Byte* out, size_t availableOut )
{
	// Push data to the stream.
	_zStream.next_in = (Bytef*)data;
	_zStream.avail_in = (uInt)in;
	_zStream.next_out = (Bytef*)out;
	_zStream.avail_out = (uInt)availableOut;

	// Decompress data.
	const int ret = ::inflate( &_zStream, Z_SYNC_FLUSH );
	if ( (ret != Z_OK) && (ret != Z_STREAM_END) )
		throw Exception( L"Failed to decompress MSZIP-compressed data." );

	::inflateReset( &_zStream );
	::inflateSetDictionary( &_zStream, (const Bytef*)out, (uInt)availableOut - _zStream.avail_out );

	return availableOut - (size_t)_zStream.avail_out;
}


} // scene


} // synkro
