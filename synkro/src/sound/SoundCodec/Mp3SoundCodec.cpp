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
// Purpose: Mp3 sound codec.
//==============================================================================
#include "config.h"
#include "Mp3SoundCodec.h"
#include <io/IStream.h>


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace sound
{


Double Mp3SoundCodec::Load( SoundCodecContext* context, SoundFormat& format )
{
	// Call base implementation.
	SoundCodecImpl<ISoundCodec>::Load( context, format );

	// Create encoding context.
	Mp3Context* ctx = new Mp3Context();
	context->Data = (Byte*)ctx;

	// Skip ID3 tag at the beginning, if one exists.
	char buf[10]; UInt position = 0;
	UInt read = context->Stream->Read( buf, 10 );
	if ( (read == 10) && Compare(buf, "ID3", 3) )
	{
		position = (buf[6] << 21) | (buf[7] << 14) | (buf[8] << 7) | buf[9];
		position += 10;
		ctx->DataStart = position;
	}
	context->Stream->Seek( ctx->DataStart, SeekOrigin::Start );

	// Scan the first frame.
	mad_synth_init( &ctx->Synth );
	mad_stream_init( &ctx->Stream );
	mad_frame_init( &ctx->Frame );
	UInt sampleCount = 0; UInt size = 0;
	if ( !ReadFrame(context, &size, &sampleCount) )
	{
		throw Exception( "Failed to read mp3 data." );
	}
	ctx->ChannelCount = (ctx->Frame.header.mode == MAD_MODE_SINGLE_CHANNEL) ? 1 : 2;

	// Scan the rest of frames and remember data size.
	UInt totalSampleCount = 0;
	do
	{
		// Update current position.
		totalSampleCount += sampleCount;
		position += size;
	} while ( ReadFrame(context, &size, &sampleCount) );
	totalSampleCount += sampleCount;
	position += size;

	// Allocate temporary buffer for sound chunks.
	ctx->TempLength = sizeof(mad_fixed_t) * ctx->Frame.header.samplerate / 10;
	ctx->Temp = new Byte[ctx->TempLength];
	Zero( ctx->Temp, ctx->TempLength );

	// Rewind to the beginning.
	context->Stream->Seek( ctx->DataStart, SeekOrigin::Start );

	format.SamplesPerSecond = ctx->Frame.header.samplerate;
	format.BitsPerSample = 16;
	format.ChannelCount = ctx->ChannelCount;

	// Calculate track duration in seconds.
	return CastDouble(totalSampleCount) / CastDouble(ctx->Frame.header.samplerate);
}

void Mp3SoundCodec::Save( SoundCodecContext* context, const SoundFormat& format )
{
	// Call base implementation.
	SoundCodecImpl<ISoundCodec>::Save( context, format );

	// Use LAME encoder.
}

UInt Mp3SoundCodec::Decode( SoundCodecContext* context, Byte** data, UInt size )
{
	ReadFrame( context );
	const UInt read = Read( context, *data, size );
	if ( read == 0 )
	{
		Mp3Context* ctx = (Mp3Context*)context->Data;
		context->Stream->Seek( ctx->DataStart, SeekOrigin::Start );
	}
	return read;
}

UInt Mp3SoundCodec::Encode( SoundCodecContext* context, const Byte* data, UInt size )
{
	// Use LAME encoder.
	return 0;
}

UInt Mp3SoundCodec::Scale( mad_fixed_t sample )
{
	sample += (1 << (MAD_F_FRACBITS - 16));

	if ( sample >= MAD_F_ONE )
		sample = MAD_F_ONE - 1;
	else if (sample < -MAD_F_ONE )
		sample = -MAD_F_ONE;

	return sample >> (MAD_F_FRACBITS + 1 - 16);
}

UInt Mp3SoundCodec::Read( SoundCodecContext* context, Byte* buffer, UInt size )
{
	UInt read = 0;

	Mp3Context* ctx = (Mp3Context*)context->Data;

	// Use previously read data.
	if ( ctx->TempLength > 0 )
	{
		Copy( buffer, ctx->Temp, ctx->TempLength );
		read = ctx->TempLength;
		ctx->TempLength = 0;
	}

	// Read next frame data.
	while ( read < size )
	{
		mad_synth_frame( &ctx->Synth, &ctx->Frame );
		struct mad_pcm *pcm = &ctx->Synth.pcm;
		mad_fixed_t *left = pcm->samples[0];
		mad_fixed_t *right = pcm->samples[1];
		
		UShort *data = (UShort*)(buffer + read);
		UShort *dataTmp = (UShort*)(ctx->Temp + ctx->TempLength);
		for ( Int length = pcm->length; length > 0; --length )
		{
			if ( read < size )
			{
				read += ctx->ChannelCount * 2;
				*data++ = Scale(*left++);
				if ( ctx->ChannelCount == 2 )
				{
					*data++ = Scale( *right++ );
				}
			}
			else
			{
				ctx->TempLength += ctx->ChannelCount * 2;
				*dataTmp++ = Scale(*left++);
				if ( ctx->ChannelCount == 2 )
				{
					*dataTmp++ = Scale( *right++ );
				}
			}
		}

		if ( !ReadFrame(context) )
			return 0;
	}
	return read;
}

Bool Mp3SoundCodec::ReadFrame( SoundCodecContext* context, UInt* size, UInt* sampleCount )
{
	*size = 0L;
	*sampleCount = 0L;
	Mp3Context* ctx = (Mp3Context*)context->Data;

	while ( true )
	{
		UInt ret = context->Stream->Read( &ctx->Buffer[ctx->BufferLength], BUFFER_SIZE-ctx->BufferLength );
		if ( (ret == 0) && (ctx->BufferLength == 0) )
			break;

		ctx->BufferLength += ret;

		while ( true )
		{
			mad_stream_buffer( &ctx->Stream, ctx->Buffer, ctx->BufferLength );
			ret = mad_frame_decode( &ctx->Frame, &ctx->Stream );
			if ( ctx->Stream.next_frame != 0 )
			{
				*size = CastUInt((Byte*)ctx->Stream.next_frame - ctx->Buffer);
				UInt length = ctx->Buffer + ctx->BufferLength - (Byte*)ctx->Stream.next_frame;
				memmove( ctx->Buffer, ctx->Stream.next_frame, length );
				ctx->BufferLength = length;
			}
			if ( ret == 0 )
			{
				*sampleCount = 32 * MAD_NSBSAMPLES(&ctx->Frame.header);
				if ( ctx->Frame.options & MAD_OPTION_HALFSAMPLERATE )
				{
					*sampleCount /= 2;
				}
				return true;
			}

			if ( ret == -1 )
			{
				*size = ctx->BufferLength;
				return false;
			}
		}
	}
	return false;
}

Bool Mp3SoundCodec::ReadFrame( SoundCodecContext* context )
{
	UInt size = 0; UInt sampleCount = 0;
	return ReadFrame( context, &size, &sampleCount );
}


} // sound


} // synkro
