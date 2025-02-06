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
// Purpose: 3D sound implementation.
//==============================================================================
#ifndef _SYNKRO_SOUND_SOUND3D_
#define _SYNKRO_SOUND_SOUND3D_


#include "config.h"
#include <core/ObjectImpl.h>
#include <sound/ISound3D.h>
#include <audio/IAudioSystemEx.h>
#include <audio/ISoundEmitter.h>
#include <audio/IAudioChunk.h>
#include "BaseSound3D.h"


namespace synkro
{


namespace sound
{


// 3D sound implementation.
class Sound3D :
	public core::ObjectImpl<ISound3D>,
	public BaseSound3D
{
public:
	// Constructor.
	Sound3D( audio::IAudioSystemEx* audioSystem, ISoundCodec* codec, io::IStream* stream );

	// ISound methods.
	void													Play( Bool play );
	void													SetVolume( Int volume );
	Bool													IsPlaying() const;
	Int														GetVolume() const;
	Double													GetLength() const;

	// ISound3D methods.
	void													SetPosition( const math::Vector3& position );
	void													SetDirection( const math::Vector3& direction );
	void													SetVelocity( const math::Vector3& velocity );
	void													SetInnerAngle( Float angle );
	void													SetOuterAngle( Float angle );
	void													SetInnerVolume( Float volume );
	void													SetOuterVolume( Float volume );
	void													SetInnerReverb( Float reverb );
	void													SetOuterReverb( Float reverb );
	void													SetMinDistance( Float distance );
	void													SetMaxDistance( Float distance );
	void													GetPosition( math::Vector3& position ) const;
	void													GetDirection( math::Vector3& direction ) const;
	void													GetVelocity( math::Vector3& velocity ) const;
	Float													GetInnerAngle() const;
	Float													GetOuterAngle() const;
	Float													GetInnerVolume() const;
	Float													GetOuterVolume() const;
	Float													GetInnerReverb() const;
	Float 													GetOuterReverb() const;
	Float													GetMinDistance() const;
	Float													GetMaxDistance() const;

	// BaseSound3D methods.
	audio::ISoundEmitter*									GetEmitter() const;

private:
	audio::IAudioPlayer*									_player;
	P(audio::ISoundEmitter)									_emitter;
	Double													_length;
};


#include "Sound3D.inl"


} // sound


} // synkro


#endif // _SYNKRO_SOUND_SOUND3D_
