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
// Purpose: Defines base stream reader.
//==============================================================================
SYNKRO_INLINE StreamReader::StreamReader( IStream* stream ) :
	_stream( stream )
{
	if ( _stream != nullptr )
	{
		_stream->Open( OpenMode::Read );
	}
}

SYNKRO_INLINE StreamReader::~StreamReader()
{
	Close();
}

SYNKRO_INLINE UInt StreamReader::Read( void* data, UInt size )
{
	assert( _stream != nullptr );

	return _stream->Read( data, size );
}

SYNKRO_INLINE void StreamReader::Close()
{
	if ( _stream != nullptr )
	{
		_stream->Close();
	}
}

SYNKRO_INLINE IStream* StreamReader::GetStream() const
{
	return _stream;
}

SYNKRO_INLINE Bool StreamReader::Eos() const
{
	assert( _stream != nullptr );

	const UInt length = _stream->GetLength();
	const UInt pos = _stream->GetPosition();

	return (length == 0) || (pos >= length);
}
