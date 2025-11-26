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
// Purpose: 'synkro.audio.winmm' library.
//==============================================================================
#include "config.h"

#define SYNKROLIB_NAME			L"synkro.audio.winmm"
#define SYNKROLIB_DESC			L"Synkro Audio Library"
#define SYNKROLIB_COMMENT		L"Winmm audio system"
#define SYNKROLIB_FACTORIES		_factories
#define SYNKROLIB_INIT			SynkroAudioWinmmInit
#define SYNKROLIB_VERSION_MAJOR	1
#define SYNKROLIB_VERSION_MINOR	0
#define SYNKROLIB_VERSION_PATCH	0
#include "../synkrolib.inl"
