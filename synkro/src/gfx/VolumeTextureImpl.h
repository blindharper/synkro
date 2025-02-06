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
// Purpose: Generic volume texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_VOLUMETEXTUREIMPL_
#define _SYNKRO_GFX_VOLUMETEXTUREIMPL_


#include "config.h"
#include "TextureImpl.h"


namespace synkro
{


namespace gfx
{


// Generic texture implementation.
template <class T>
class VolumeTextureImpl :
	public TextureImpl<T>
{
public:
	// Constructor & destructor.
	VolumeTextureImpl( UInt width, UInt height, UInt depth, const img::PixelFormat& format, UInt levelCount );
	virtual ~VolumeTextureImpl();

	// ITexture methods.
	virtual IVolumeTexture*									AsVolume() const;

	// IVolumeTexture methods.
	virtual UInt											GetWidth() const;
	virtual UInt											GetHeight() const;
	virtual UInt											GetDepth() const;

protected:
	UInt													_width;
	UInt													_height;
	UInt													_depth;
};


#include "VolumeTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_VOLUMETEXTUREIMPL_
