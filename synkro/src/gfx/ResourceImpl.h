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
// Purpose: Generic resource implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_RESOURCEIMPL_
#define _SYNKRO_GFX_RESOURCEIMPL_


#include "config.h"
#include <core/ObjectImpl.h>


namespace synkro
{


namespace gfx
{


// Generic resource implementation.
template <class T>
class ResourceImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	ResourceImpl();
	virtual ~ResourceImpl();

	// IResource methods.
	virtual IBuffer*										AsBuffer() const;
	virtual ITexture*										AsTexture() const;
	virtual IRenderTexture*									AsRenderTexture() const;
	virtual IDepthTexture*									AsDepthTexture() const;	
};


#include "ResourceImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RESOURCEIMPL_
