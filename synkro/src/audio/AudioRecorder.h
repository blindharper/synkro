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
// Purpose: Logical recorder.
//==============================================================================
#ifndef _SYNKRO_AUDIO_AUDIORECORDER_
#define _SYNKRO_AUDIO_AUDIORECORDER_


#include "config.h"
#include <core/ObjectImpl.h>
#include <audio/IAudioRecorder.h>
#include <lang/Vector.h>
#include "BaseAudioRecorder.h"


namespace synkro
{


namespace audio
{


// Logical recorder.
class AudioRecorder :
	public core::ObjectImpl<IAudioRecorder>,
	public BaseAudioRecorder
{
public:
	// Constructor.
	AudioRecorder( IAudioRecorder* recorder, UInt index );

	// IAudioRecorder methods.
	IVoiceBuffer*											CreateVoiceBuffer( const sound::SoundFormat& format, Double length, UInt chunkCount );
	void													GetDesc( RecorderDesc& desc ) const;

	// BaseAudioRecorder methods.
	void													RemoveBuffer( IVoiceBuffer* buffer );

	// Other methods.
	void													Update();
	UInt													GetIndex() const;

private:
	lang::Vector<IVoiceBuffer*>								_buffers;
	P(IAudioRecorder)										_recorder;
	UInt													_index;
};


#include "AudioRecorder.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_AUDIORECORDER_
