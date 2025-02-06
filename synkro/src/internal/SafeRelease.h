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
// Purpose: Safe releaser.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_SAFERELEASE_
#define _SYNKRO_INTERNAL_SAFERELEASE_


#include "config.h"


// Helper function for safe object release.
template <class T> SYNKRO_INLINE static void SafeRelease( T* obj )
{
	if ( obj != nullptr )
	{
		obj->Release();
		obj = nullptr;
	}
}


#endif // _SYNKRO_INTERNAL_SAFERELEASE_
