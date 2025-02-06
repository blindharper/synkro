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
// Purpose: Generic plain rendering texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_PLAINRENDERTEXTUREIMPL_
#define _SYNKRO_GFX_PLAINRENDERTEXTUREIMPL_


#include "config.h"
#include "RenderTextureImpl.h"


namespace synkro
{


namespace gfx
{


// Generic plain rendering texture implementation.
template <class T>
class PlainRenderTextureImpl :
	public RenderTextureImpl<T>
{
public:
	// Constructors & destructor.
	PlainRenderTextureImpl( UInt width, UInt height, const img::PixelFormat& format );
	virtual ~PlainRenderTextureImpl();

	// IPlainRenderTexture methods.
	virtual UInt											GetWidth() const;
	virtual UInt											GetHeight() const;

protected:
	UInt													_width;
	UInt													_height;
};


#include "PlainRenderTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PLAINRENDERTEXTUREIMPL_
