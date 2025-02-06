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
// Purpose: 2D sound implementation.
//==============================================================================
#include "config.h"
#include "Sound2D.h"
#include <sound/SoundCodecContext.h>
#include <sound/ISoundCodec.h>
#include <io/IStream.h>
#include <lang/Vector.h>


//------------------------------------------------------------------------------

using namespace synkro::audio;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace sound
{


Sound2D::Sound2D( IAudioSystemEx* audioSystem, ISoundCodec* codec, IStream* stream ) :
	_player( nullptr ),
	_length( 0.0 )
{
	// Create sound buffer.
	SoundCodecContext context( stream, false );
	SoundFormat soundFormat;
	_length = codec->Load( &context, soundFormat );
	_player = audioSystem->GetPlayer( soundFormat );
	_buffer = _player->CreateSoundBuffer( soundFormat, _length, 1 );

	// Fill buffer with data.
	IAudioChunk* chunk = _buffer->GetChunk( 0 );
	Vector<Byte> data( A(Byte) );
	data.SetSize( chunk->GetSize() );
	Byte* d = data.Begin();
	const UInt size = codec->Decode( &context, &d, data.Size() );
	chunk->Write( d, size );
}


} // sound


} // synkro
