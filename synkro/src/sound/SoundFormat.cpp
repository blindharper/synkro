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
// Purpose: Defines sound format.
//==============================================================================
#include "config.h"
#include <sound/SoundFormat.h>
#include <lang/BadArgumentException.h>
#include <lang/OutOfRangeException.h>
#include <lang/Parser.h>
#include <math/Math.h>
#include <internal/Zero.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace sound
{


static UInt TokHz( UInt value )
{
	return CastUInt(Math::Trunc( CastFloat(value) * 0.001f ));
}

static UInt ToHz( UInt value )
{
	switch ( value )
	{
		case 11:	return 11025;
		case 22:	return 22050;
		case 44:	return 44100;
		case 88:	return 88200;
	}
	return value*1000;
}

//------------------------------------------------------------------------------

class SoundFormatList
{
public:
	SoundFormatList() :
		_formatCount( 0 )
	{
		Zero( &_formats, 64*sizeof(SoundFormat) );
	}

	UInt GetSize()
	{
		if ( _formatCount == 0 )
			Init();

		return _formatCount;
	}

	const SoundFormat& GetFormat( UInt index )
	{
		if ( _formatCount == 0 )
			Init();

		return _formats[index];
	}

private:
	void Init()
	{		
		_formats[_formatCount++] = SoundFormat( 44100, 16, 2 );
		_formats[_formatCount++] = SoundFormat( 44100, 16, 1 );
		_formats[_formatCount++] = SoundFormat( 44100,  8, 2 );
		_formats[_formatCount++] = SoundFormat( 44100,  8, 1 );
		_formats[_formatCount++] = SoundFormat( 22050, 16, 2 );
		_formats[_formatCount++] = SoundFormat( 22050, 16, 1 );
		_formats[_formatCount++] = SoundFormat( 22050,  8, 2 );
		_formats[_formatCount++] = SoundFormat( 22050,  8, 1 );
		_formats[_formatCount++] = SoundFormat( 11025, 16, 2 );
		_formats[_formatCount++] = SoundFormat( 11025, 16, 1 );
		_formats[_formatCount++] = SoundFormat( 11025,  8, 2 );
		_formats[_formatCount++] = SoundFormat( 11025,  8, 1 );
	}

	SoundFormat _formats[64];
	UInt _formatCount;
} _formats;

//------------------------------------------------------------------------------

const SoundFormat SoundFormat::Unknown( 0, 0, 0 );
const SoundFormat SoundFormat::Stereo44kHz16bit( 44100, 16, 2 );
const SoundFormat SoundFormat::Mono44kHz16bit( 44100, 16, 1 );
const SoundFormat SoundFormat::Stereo44kHz8bit( 44100, 8, 2 );
const SoundFormat SoundFormat::Mono44kHz8bit( 44100, 8, 1 );
const SoundFormat SoundFormat::Stereo22kHz16bit( 22050, 16, 2 );
const SoundFormat SoundFormat::Mono22kHz16bit( 22050, 16, 1 );
const SoundFormat SoundFormat::Stereo22kHz8bit( 22050, 8, 2 );
const SoundFormat SoundFormat::Mono22kHz8bit( 22050, 8, 1 );
const SoundFormat SoundFormat::Stereo11kHz16bit( 11025, 16, 2 );
const SoundFormat SoundFormat::Mono11kHz16bit( 11025, 16, 1 );
const SoundFormat SoundFormat::Stereo11kHz8bit( 11025, 8, 2 );
const SoundFormat SoundFormat::Mono11kHz8bit( 11025, 8, 1 );


SoundFormat::SoundFormat( UInt samplesPerSecond, UInt bitsPerSample, const SoundChannel& channels, UInt channelCount ) :
	SamplesPerSecond( samplesPerSecond ),
	BitsPerSample( bitsPerSample ),
	ChannelCount( channelCount ),
	Channels( channels )
{
}

SoundFormat::SoundFormat( UInt samplesPerSecond, UInt bitsPerSample, const SoundChannel& channels ) :
	SamplesPerSecond( samplesPerSecond ),
	BitsPerSample( bitsPerSample ),
	ChannelCount( channels.Bits() ),
	Channels( channels )
{
	assert( channels != SoundChannel::Unknown );

	if ( channels == SoundChannel::Unknown )
		throw BadArgumentException( L"Bad sound format channels.", L"channels" );
}

SoundFormat::SoundFormat( UInt samplesPerSecond, UInt bitsPerSample, UInt channelCount ) :
	SamplesPerSecond( samplesPerSecond ),
	BitsPerSample( bitsPerSample ),
	ChannelCount( channelCount )
{
	switch ( channelCount )
	{
		case 1:	Channels = SoundChannel::Mono; break;
		case 2:	Channels = SoundChannel::Stereo; break;
		case 3:	Channels = SoundChannel::Three; break;
		case 4:	Channels = SoundChannel::Quad; break;
		case 5:	Channels = SoundChannel::Five; break;
		case 6:	Channels = SoundChannel::Six; break;
		case 7:	Channels = SoundChannel::Seven; break;
		case 8:	Channels = SoundChannel::EightSurround; break;
		case 9:	Channels = SoundChannel::NineSurround; break;
		case 10:Channels = SoundChannel::TenSurround; break;
		case 11:Channels = SoundChannel::ElevenSurround; break;
		default: break;
	}
}

SoundFormat::SoundFormat( const String& format )
{
	Int s; Int b; Int c;
	if ( !Parser::Parse(format, L"{0}kHz{1}bit{2}Ch", s, b, c) )
		throw BadArgumentException( String::Format(L"Bad sound format: {0}", format), L"format" );

	SamplesPerSecond = ToHz(CastUInt(s)); BitsPerSample = CastUInt(b); ChannelCount = CastUInt(c);
}

SoundFormat::SoundFormat() :
	SamplesPerSecond( 0 ),
	BitsPerSample( 0 ),
	ChannelCount( 0 )
{
}

Bool SoundFormat::operator==( const SoundFormat& other ) const
{
	return (SamplesPerSecond == other.SamplesPerSecond) && (BitsPerSample == other.BitsPerSample) && (ChannelCount == other.ChannelCount);
}

Bool SoundFormat::operator!=( const SoundFormat& other ) const
{
	return !operator==( other );
}

UInt SoundFormat::BytesPerSample() const
{
	return BitsPerSample >> 3;
}

String SoundFormat::ToString() const
{
	return String::Format( L"{0}kHz{1}bit{2}Ch", TokHz(SamplesPerSecond), BitsPerSample, ChannelCount );
}

UInt SoundFormat::GetFormatCount()
{
	return _formats.GetSize();
}

void SoundFormat::GetFormat( UInt index, SoundFormat& format )
{
	assert( index < GetFormatCount() );

	if ( index >= GetFormatCount() )
		throw OutOfRangeException( index, GetFormatCount() );

	format = _formats.GetFormat( index );
}


} // sound


} // synkro
