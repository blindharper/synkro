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
// Purpose: Logical sound emitter.
//==============================================================================
#ifndef _SYNKRO_AUDIO_SOUNDEMITTER_
#define _SYNKRO_AUDIO_SOUNDEMITTER_


#include "config.h"
#include "AudioBufferImpl.h"
#include <audio/ISoundEmitter.h>
#include "AudioChunk.h"


namespace synkro
{


namespace audio
{


// Logical sound emitter.
class SoundEmitter :
	public AudioBufferImpl<ISoundEmitter, AudioChunk>
{
public:
	// Constructor.
	SoundEmitter( ISoundEmitter* emitter );

	// IAudioBuffer methods.
	void													Update();
	void													Process( Bool start, Bool loop );
	void													GetFormat( sound::SoundFormat& format ) const;

	// ISoundBuffer methods.
	void													SetPan( Int pan );
	void													SetAttenuation( Int attenuation );
	void													SetFrequency( UInt frequency );
	Int														GetPan() const;
	Int														GetAttenuation() const;
	UInt													GetFrequency() const;

	// ISoundEmitter methods.
	void													Bind();
	void													SetPosition( const math::Vector3& position );
	void													SetDirection( const math::Vector3& direction );
	void													SetVelocity( const math::Vector3& velocity );
	void													SetInnerAngle( Float angle );
	void													SetOuterAngle( Float angle );
	void													SetInnerAttenuation( Int volume );
	void													SetOuterAttenuation( Int volume );
	void													SetInnerReverb( Float reverb );
	void													SetOuterReverb( Float reverb );
	void													SetMinDistance( Float distance );
	void													SetMaxDistance( Float distance );
	void													GetPosition( math::Vector3& position ) const;
	void													GetDirection( math::Vector3& direction ) const;
	void													GetVelocity( math::Vector3& velocity ) const;
	Float													GetInnerAngle() const;
	Float													GetOuterAngle() const;
	Int														GetInnerAttenuation() const;
	Int														GetOuterAttenuation() const;
	Float													GetInnerReverb() const;
	Float 													GetOuterReverb() const;
	Float													GetMinDistance() const;
	Float													GetMaxDistance() const;

private:
	P(ISoundEmitter)										_emitter;
};


#include "SoundEmitter.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_SOUNDEMITTER_
