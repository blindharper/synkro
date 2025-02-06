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
// Purpose: Base resource.
//==============================================================================
#ifndef _SYNKRO_GFX_BASERESOURCE_
#define _SYNKRO_GFX_BASERESOURCE_


#include "config.h"
#include "Classes.h"


namespace synkro
{


namespace gfx
{


// Base resource.
class BaseResource
{
public:
	// Sets the specified collection as a resource's parent.
	virtual void											AddParent( ResourceSet* parent ) = 0;

	// Removes previously set parent.
	virtual void											RemoveParent( ResourceSet* parent ) = 0;

	// Notifies parents that the resource has been updated.
	virtual void											Invalidate() = 0;

	// Returns underlying physical resource.
	virtual IResource*										AsResource() const = 0;
};


// Casts object to BaseResource.
#define AsBaseResource( OBJ ) dynamic_cast<BaseResource*>( OBJ )


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BASERESOURCE_
