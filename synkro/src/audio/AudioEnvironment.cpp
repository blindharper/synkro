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
// Purpose: Audio environment implementation.
//==============================================================================
#include "config.h"
#include "AudioEnvironment.h"
#include "AudioSystemEx.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


AudioEnvironment::AudioEnvironment( IAudioSystemEx* audioSystem ) :
	_emitters( A(P(ISoundEmitter)) ),
	_audioSystem( audioSystem )
{
}

void AudioEnvironment::Activate()
{
	((AudioSystemEx*)_audioSystem)->SetActiveEnvironment( this );
}

void AudioEnvironment::AddEmitter( ISoundEmitter* emitter )
{
	assert( emitter != nullptr );

	_emitters.Add( emitter );
}


} // audio


} // synkro
