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
// Purpose: Generic plain texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_PLAINTEXTUREIMPL_
#define _SYNKRO_GFX_PLAINTEXTUREIMPL_


#include "config.h"
#include "TextureImpl.h"


namespace synkro
{


namespace gfx
{


// Generic plain texture implementation.
template <class T>
class PlainTextureImpl :
	public TextureImpl<T>
{
public:
	// Constructor & destructor.
	PlainTextureImpl( UInt width, UInt height, const img::PixelFormat& format, UInt levelCount, UInt elementCount );
	virtual ~PlainTextureImpl();

	// ITexture methods.
	virtual IPlainTexture*									AsPlain() const;

	// IPlainTexture methods.
	virtual UInt											GetWidth() const;
	virtual UInt											GetHeight() const;

protected:
	UInt													_width;
	UInt													_height;
};


#include "PlainTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PLAINTEXTUREIMPL_
