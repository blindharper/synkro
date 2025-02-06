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
// Purpose: Implements sound codec context.
//==============================================================================
#include "config.h"
#include <sound/SoundCodecContext.h>
#include <io/IStream.h>
#include <internal/SafeDelete.h>
#include <internal/SafeClose.h>

//------------------------------------------------------------------------------

using namespace synkro::io;

//------------------------------------------------------------------------------


namespace synkro
{


namespace sound
{


SoundCodecContext::SoundCodecContext( IStream* stream, Bool write ) :
	Stream( stream ),
	Data( nullptr )
{
	assert( stream != nullptr );

	Stream->Open( write ? OpenMode::Write : OpenMode::Read );
}

SoundCodecContext::SoundCodecContext() :
	Stream( nullptr ),
	Data( nullptr )
{
}

SoundCodecContext::~SoundCodecContext()
{
	SafeDelete( Data );
	SafeClose( Stream );
}


} // sound


} // synkro
