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
// Purpose: Logical audio buffer chunk.
//==============================================================================
SYNKRO_INLINE void AudioChunk::Write( const Byte* data, UInt size )
{
	if ( _readonly )
		throw lang::InvalidOperationException( L"Cannot write to read-only audio chunk." );

	_chunk->Write( data, size );
}

SYNKRO_INLINE void AudioChunk::Read( Byte* data, UInt size ) const
{
	if ( !_readonly )
		throw lang::InvalidOperationException( L"Cannot read from write-only audio chunk." );

	_chunk->Read( data, size );
}

SYNKRO_INLINE UInt AudioChunk::GetSize() const
{
	return _chunk->GetSize();
}

SYNKRO_INLINE Bool AudioChunk::IsProcessing() const
{
	return _chunk->IsProcessing();
}
