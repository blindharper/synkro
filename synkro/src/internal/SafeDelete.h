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
// Purpose: Safe memory releaser.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_SAFEDELETE_
#define _SYNKRO_INTERNAL_SAFEDELETE_


#include "config.h"


// Helper function for safe object deletion.
template <class T> SYNKRO_INLINE static void SafeDelete( T* obj )
{
	if ( obj != nullptr )
	{
		delete obj;
		obj = nullptr;
	}
}


#endif // _SYNKRO_INTERNAL_SAFEDELETE_
