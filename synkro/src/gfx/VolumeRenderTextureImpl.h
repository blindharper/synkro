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
// Purpose: Generic volume rendering texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_VOLUMERENDERTEXTUREIMPL_
#define _SYNKRO_GFX_VOLUMERENDERTEXTUREIMPL_


#include "config.h"
#include "RenderTextureImpl.h"


namespace synkro
{


namespace gfx
{


// Generic volume rendering texture implementation.
template <class T>
class VolumeRenderTextureImpl :
	public RenderTextureImpl<T>
{
public:
	// Constructors & destructor.
	VolumeRenderTextureImpl( UInt width, UInt height, UInt depth, const img::PixelFormat& format );
	virtual ~VolumeRenderTextureImpl();

	// IVolumeRenderTexture methods.
	virtual UInt											GetWidth() const;
	virtual UInt											GetHeight() const;
	virtual UInt											GetDepth() const;

protected:
	UInt													_width;
	UInt													_height;
	UInt													_depth;
};


#include "VolumeRenderTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_VOLUMERENDERTEXTUREIMPL_
