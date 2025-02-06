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
#ifndef _SYNKRO_ANIM_SAVEANIMATIONTASK_
#define _SYNKRO_ANIM_SAVEANIMATIONTASK_


#include "config.h"
#include <core/Task.h>
#include <lang/Formatter.h>
#include <internal/Logger.h>


namespace synkro
{


namespace anim
{


// Animation loader.
class SaveAnimationTask :
	public core::Task,
	public Logger
{
public:
	// Constructor.
	SaveAnimationTask( const IAnimationSet* animation, IAnimationCodec* codec, io::IStream* stream, diag::ILog* log );

	// Task methods.
	void													Execute();
	void													Cancel();

private:
	const IAnimationSet*									_animation;
	IAnimationCodec*										_codec;
	io::IStream*											_stream;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_SAVEANIMATIONTASK_
