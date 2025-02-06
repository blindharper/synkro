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
// Purpose: Generic cube texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_CUBETEXTUREIMPL_
#define _SYNKRO_GFX_CUBETEXTUREIMPL_


#include "config.h"
#include "TextureImpl.h"


namespace synkro
{


namespace gfx
{


// Generic texture implementation.
template <class T>
class CubeTextureImpl :
	public TextureImpl<T>
{
public:
	// Constructor & destructor.
	CubeTextureImpl( UInt length, const img::PixelFormat& format, UInt levelCount );
	virtual ~CubeTextureImpl();

	// ITexture methods.
	virtual ICubeTexture*									AsCube() const;

	// ICubeTexture methods.
	virtual UInt											GetLength() const;

protected:
	UInt													_length;
};


#include "CubeTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_CUBETEXTUREIMPL_
