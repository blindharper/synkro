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
// Purpose: 'synkro.input.win32' library.
//==============================================================================
#include "config.h"

#define SYNKROLIB_NAME			L"synkro.input.win32"
#define SYNKROLIB_DESC			L"Synkro Input Library"
#define SYNKROLIB_COMMENT		L"Win32 input system"
#define SYNKROLIB_FACTORIES		_factories
#define SYNKROLIB_INIT			SynkroInputWin32Init
#define SYNKROLIB_VERSION_MAJOR	1
#define SYNKROLIB_VERSION_MINOR	0
#define SYNKROLIB_VERSION_PATCH	0
#include "../synkrolib.inl"
