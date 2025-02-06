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
// Purpose: Generic texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_TEXTUREIMPL_
#define _SYNKRO_GFX_TEXTUREIMPL_


#include "config.h"
#include <gfx/ResourceImpl.h>
#include <gfx/GraphicsException.h>
#include <img/PixelFormat.h>


namespace synkro
{


namespace gfx
{


// Generic texture implementation.
template <class T>
class TextureImpl :
	public ResourceImpl<T>
{
public:
	// Constructor & destructor.
	TextureImpl( const img::PixelFormat& format, UInt levelCount, UInt elementCount );
	virtual ~TextureImpl();

	// IResource methods.
	virtual ITexture*										AsTexture() const;

	// ITexture methods.
	virtual void											GenerateLevels();
	virtual UInt											GetElementCount() const;
	virtual UInt											GetLevelCount() const;
	virtual img::PixelFormat								GetFormat() const;
	virtual ILinearTexture*									AsLinear() const;
	virtual IPlainTexture*									AsPlain() const;
	virtual ICubeTexture*									AsCube() const;
	virtual IVolumeTexture*									AsVolume() const;

protected:
	img::PixelFormat										_format;
	UInt													_levelCount;
	UInt													_elementCount;
};


#include "TextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_TEXTUREIMPL_
