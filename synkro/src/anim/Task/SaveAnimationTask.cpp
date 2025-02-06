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
// Purpose: "Save animation" task.
//==============================================================================
#include "config.h"
#include "SaveAnimationTask.h"
#include <anim/IAnimationSet.h>
#include <anim/IAnimationCodec.h>
#include <io/IStream.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


SaveAnimationTask::SaveAnimationTask( const IAnimationSet* animation, IAnimationCodec* codec, IStream* stream, ILog* log ) :
	Logger( log, LogFacility::AnimationSystem ),
	_animation( animation ),
	_codec( codec ),
	_stream( stream )
{
}

void SaveAnimationTask::Execute()
{
	if ( _stream != nullptr )
	{
		LogInfo( MessagePriority::Lowest, Formatter::Format(L"Saving animation {0,q} to stream [{1}]. Name = {2,q}.", _animation->GetName(), _stream->ID(), _stream->GetName()) );

		_stream->Open( OpenMode::Write );
		_codec->Save( _animation, _stream );
		_stream->Close();

		LogInfo( MessagePriority::Lowest, Formatter::Format(L"Animation {0,q} saved to stream.", _animation->GetName()) );
	}
}

void SaveAnimationTask::Cancel()
{
	// Do nothing.
}


} // anim


} // synkro
