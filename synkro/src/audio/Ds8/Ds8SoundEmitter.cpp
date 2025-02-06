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
// Purpose: DirectSound 8 sound emitter.
//==============================================================================
#include "config.h"
#include "Ds8SoundEmitter.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


Ds8SoundEmitter::Ds8SoundEmitter( IDirectSound8* device, const SoundFormat& format, Double length ) :
	SoundEmitterImpl<ISoundEmitter, Ds8AudioChunk>( format, 1 ),
	_buffer( nullptr ),
	_buffer3D( nullptr ),
	_ptr1( nullptr ),
	_bytes1( 0 ),
	_ptr2( nullptr ),
	_bytes2( 0 )
{
	HRESULT hr = DS_OK;

	// Setup audio format.
	WAVEFORMATEX fmt;
	fmt.wFormatTag		= WAVE_FORMAT_PCM;
	fmt.nChannels		= format.ChannelCount;
	fmt.nSamplesPerSec	= format.SamplesPerSecond;
	fmt.wBitsPerSample	= format.BitsPerSample;
	fmt.nBlockAlign		= fmt.nChannels * fmt.wBitsPerSample >> 3;
	fmt.nAvgBytesPerSec = fmt.nSamplesPerSec * fmt.nBlockAlign;
	fmt.cbSize			= 0;
	_size = length * CastDouble(fmt.nAvgBytesPerSec);

	// Create buffer.
	DSBUFFERDESC desc;
	desc.dwSize			= sizeof(DSBUFFERDESC);
	desc.dwFlags		= DSBCAPS_CTRL3D | DSBCAPS_CTRLFX;
	desc.dwBufferBytes	= _size;
	desc.lpwfxFormat	= &fmt;
	desc.guid3DAlgorithm = DS3DALG_DEFAULT;
	desc.dwReserved		= 0;
	IDirectSoundBuffer* buffer;
	if ( FAILED(hr = device->CreateSoundBuffer(&desc, &buffer, nullptr)) )
		throw AudioException( String::Format(Str::SoundEmitterCreateFail, format.ToString()), String::Format(Str::CallFail, L"IDirectSound8::CreateSoundBuffer()"), Ds8::ToString(hr) );

	if ( FAILED(hr = buffer->QueryInterface( IID_IDirectSoundBuffer8, (void**)&_buffer )) )
		throw AudioException( String::Format(Str::SoundEmitterCreateFail, format.ToString()), String::Format(Str::CallFail, L"IDirectSoundBuffer::QueryInterface()"), Ds8::ToString(hr) );

	if ( FAILED(hr = buffer->QueryInterface( IID_IDirectSound3DBuffer8, (void**)&_buffer3D )) )
		throw AudioException( String::Format(Str::SoundEmitterCreateFail, format.ToString()), String::Format(Str::CallFail, L"IDirectSoundBuffer::QueryInterface()"), Ds8::ToString(hr) );
	buffer->Release();

	// Create chunk.
	_chunks.Add( new Ds8AudioChunk(this, 0, _size) );
}

Ds8SoundEmitter::~Ds8SoundEmitter()
{
	SafeRelease( _buffer3D );
	SafeRelease( _buffer );
}

void Ds8SoundEmitter::Update()
{
	// Do nothing.
}

void Ds8SoundEmitter::Process( Bool start, Bool loop )
{
	HRESULT hr = S_OK;

	if ( start )
	{
		const DWORD flags = loop ? DSBPLAY_LOOPING : 0;
		hr = _buffer->Play( 0, 0, flags );
	}
	else
	{
		hr = _buffer->Stop();
		_buffer->SetCurrentPosition( 0 );
	}
}

void Ds8SoundEmitter::SetPan( Int pan )
{
	// Call base implementation.
	SoundEmitterImpl<ISoundEmitter, Ds8AudioChunk>::SetPan( pan );

	HRESULT hr = _buffer->SetPan( pan );
}

void Ds8SoundEmitter::SetAttenuation( Int attenuation )
{
	// Call base implementation.
	SoundEmitterImpl<ISoundEmitter, Ds8AudioChunk>::SetAttenuation( attenuation );

	HRESULT hr = _buffer->SetVolume( attenuation );
}

void Ds8SoundEmitter::SetFrequency( UInt frequency )
{
	// Call base implementation.
	SoundEmitterImpl<ISoundEmitter, Ds8AudioChunk>::SetFrequency( frequency );

	HRESULT hr = _buffer->SetFrequency( frequency );
}

void Ds8SoundEmitter::Bind()
{
	if ( _dirty )
	{
		DS3DBUFFER desc;
		desc.dwSize = sizeof(desc);
		Ds8::Convert( _position, desc.vPosition );
		Ds8::Convert( _direction, desc.vConeOrientation );
		Ds8::Convert( _velocity, desc.vVelocity );
		desc.dwInsideConeAngle	= (DWORD)_innerAngle;
		desc.dwOutsideConeAngle	= (DWORD)_outerAngle;
		desc.flMinDistance		= _minDistance;
		desc.flMaxDistance		= _maxDistance;
		desc.lConeOutsideVolume	= _outerAttenuation;
		desc.dwMode				= DS3DMODE_NORMAL;
		_buffer3D->SetAllParameters( &desc, DS3D_IMMEDIATE );
		_dirty = false;
	}
}

Bool Ds8SoundEmitter::Map( UInt offset, UInt size, Byte** data )
{
	assert( _ptr1 == nullptr );

	HRESULT hr = DS_OK;
	if ( SUCCEEDED(_buffer->Lock(offset, size, &_ptr1, &_bytes1, &_ptr2, &_bytes2, 0)) )
	{
		assert( _ptr2 == nullptr );
		assert( _bytes1 == size );

		*data = (Byte*)_ptr1;
		return true;
	}

	return false;
}

Bool Ds8SoundEmitter::Unmap( Byte* data, UInt size )
{
	assert( _ptr1 != nullptr );
	assert( _ptr1 == data );
	assert( _bytes1 == size );

	const Bool ok = SUCCEEDED( _buffer->Unlock(_ptr1, _bytes1, _ptr2, _bytes2) );
	_ptr1 = _ptr2 = nullptr;
	return ok;
}

void Ds8SoundEmitter::GetPosition( UInt* read, UInt* write ) const
{
	UInt readPosition; UInt writePosition;
	HRESULT hr = _buffer->GetCurrentPosition( (DWORD*)&readPosition, (DWORD*)&writePosition );
	*read = readPosition;
	*write = writePosition;
}


} // audio


} // synkro
