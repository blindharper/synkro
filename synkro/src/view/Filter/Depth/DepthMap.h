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
// Purpose: Depth map implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_DEPTHMAP_
#define _SYNKRO_VIEW_DEPTHMAP_


#include "config.h"
#include <core/ObjectImpl.h>
#include <view/IDepthMap.h>
#include <gfx/IPlainDepthTexture.h>


namespace synkro
{


namespace view
{


// Depth map implementation.
class DepthMap :
	public core::ObjectImpl<IDepthMap>
{
public:
	// Constructor.
	DepthMap( gfx::IPlainDepthTexture* texture );

	// IDepthMap methods.
	UInt													GetWidth() const;
	UInt													GetHeight() const;
	gfx::IResource*											GetResource() const;

	// Other methods.
	gfx::IPlainDepthTexture*								GetTexture() const;

private:
	P(gfx::IPlainDepthTexture)								_texture;
};


#include "DepthMap.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_DEPTHMAP_
