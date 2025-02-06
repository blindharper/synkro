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
// Purpose: Defines base resource.
//==============================================================================
#ifndef _SYNKRO_CORE_BASERESOURCE_
#define _SYNKRO_CORE_BASERESOURCE_


#include "config.h"


namespace synkro
{


namespace core
{


// Base resource.
struct BaseResource;
struct BaseResource
{
	BaseResource*											Next;
	IResource*												Res;
};
extern BaseResource*										_Resources;


} // core


} // synkro


#endif // _SYNKRO_CORE_BASERESOURCE_
