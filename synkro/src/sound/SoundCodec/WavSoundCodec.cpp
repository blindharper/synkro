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
// Purpose: Wav sound codec.
//==============================================================================
#include "config.h"
#include "WavSoundCodec.h"
#include <io/IStream.h>


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


struct WavHdr
{
	char	id[4];
	DWORD	size;
	char	type[4];
};

struct Chunk
{
	char	id[4];
	DWORD	size;
};

struct FmtChunk
{
	USHORT	compression;
	USHORT	channels;
	ULONG	sampleRate;
	ULONG	avgBytesPerSec;
	USHORT	blockAlign;
	USHORT	bitsPerSample;
};


namespace synkro
{


namespace sound
{


Double WavSoundCodec::Load( SoundCodecContext* context, SoundFormat& format )
{
	// Call base implementation.
	SoundCodecImpl<ISoundCodec>::Load( context, format );

	// Create encoding context.
	WavContext* ctx = new WavContext();
	context->Data = (Byte*)ctx;

	UInt bytes = 0;

	WavHdr hdr = {};
	if ( (bytes = context->Stream->Read(&hdr, sizeof(WavHdr))) < sizeof(WavHdr) )
		throw Exception( String::Format(L"Bad wav stream: {0,q}", context->Stream->GetName()) );

	// Only support RIFF chunks.
	if ( !Compare(hdr.id, "RIFF", 4) )
		throw Exception( String::Format(L"Bad wav stream: {0,q}", context->Stream->GetName()) );

	// Only support WAVE resources.
	if ( !Compare(hdr.type, "WAVE", 4) )
		throw Exception( String::Format(L"Bad wav stream: {0,q}", context->Stream->GetName()) );

	// Read chunks.
	Chunk chunk = {};
	if ( (bytes = context->Stream->Read(&chunk, sizeof(Chunk))) < sizeof(Chunk) )
		throw Exception( String::Format(L"Bad wav stream: {0,q}", context->Stream->GetName()) );

	FmtChunk fmt = {};
	if ( Compare(chunk.id, "fmt ", 4) )
	{
		if ( (bytes = context->Stream->Read(&fmt, sizeof(FmtChunk))) < sizeof(FmtChunk) )
			throw Exception( String::Format(L"Bad wav stream: {0,q}", context->Stream->GetName()) );

		if ( fmt.compression != 1 )
			throw Exception( String::Format(L"Compressed wav stream {0,q} is not supported", context->Stream->GetName()) );
	}

	// Get data.
	UInt dataSize = 0;
	while ( context->Stream->GetPosition() < context->Stream->GetLength() )
	{
		if ( (bytes = context->Stream->Read(&chunk, sizeof(Chunk))) < sizeof(Chunk) )
			break;

		if ( Compare(chunk.id, "data", 4) )
		{
			if ( ctx->DataStart == 0 )
			{
				ctx->DataStart = context->Stream->GetPosition();
			}
			dataSize += chunk.size;
		}
		context->Stream->Seek( CastInt(chunk.size), SeekOrigin::Current );
	}
	context->Stream->Seek( ctx->DataStart, SeekOrigin::Start );

	format.SamplesPerSecond = fmt.sampleRate;
	format.BitsPerSample = fmt.bitsPerSample;
	format.ChannelCount = fmt.channels;

	return CastDouble(dataSize) / CastDouble(fmt.avgBytesPerSec);
}

void WavSoundCodec::Save( SoundCodecContext* context, const SoundFormat& format )
{
	// Call base implementation.
	SoundCodecImpl<ISoundCodec>::Save( context, format );

	WavHdr hdr;
	hdr.size = 0;
	Copy( hdr.id, "RIFF", 4 );
	Copy( hdr.type, "WAVE", 4 );
	context->Stream->Write( &hdr, sizeof(hdr) );

	Chunk chunk;
	chunk.size = 16;
	Copy( chunk.id, "fmt ", 4 );
	context->Stream->Write( &chunk, sizeof(chunk) );

	FmtChunk fmt;
	fmt.compression = 1;
	fmt.channels = format.ChannelCount;
	fmt.sampleRate = format.SamplesPerSecond;
	fmt.bitsPerSample = format.BitsPerSample;
	fmt.avgBytesPerSec = fmt.channels * fmt.sampleRate * fmt.bitsPerSample;
	fmt.blockAlign = fmt.channels * fmt.bitsPerSample >> 3;
	context->Stream->Write( &fmt, sizeof(fmt) );

	chunk.size = 0;
	Copy( chunk.id, "data", 4 );
	context->Stream->Write( &chunk, sizeof(chunk) );
}

UInt WavSoundCodec::Decode( SoundCodecContext* context, Byte** data, UInt size )
{
	const UInt bytes = context->Stream->Read( *data, size );
	if ( bytes == 0 )
	{
		WavContext* ctx = (WavContext*)context->Data;
		context->Stream->Seek( ctx->DataStart, SeekOrigin::Start );
	}
	return bytes;
}

UInt WavSoundCodec::Encode( SoundCodecContext* context, const Byte* data, UInt size )
{
	if ( data == nullptr )
	{
		// Write data size to context stream.
		context->Stream->Close();
		context->Stream->Open( OpenMode::ReadWrite );

		UInt size = context->Stream->GetLength()-16;
		context->Stream->Seek( 4, SeekOrigin::Start );
		context->Stream->Write( &size, sizeof(size) );

		size = context->Stream->GetLength()-40;
		context->Stream->Seek( 40, SeekOrigin::Start );
		context->Stream->Write( &size, sizeof(size) );

		return 0;
	}

	return context->Stream->Write( data, size );
}


} // sound


} // synkro
