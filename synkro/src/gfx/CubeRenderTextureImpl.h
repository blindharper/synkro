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
// Purpose: Generic cube rendering texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_CUBERENDERTEXTUREIMPL_
#define _SYNKRO_GFX_CUBERENDERTEXTUREIMPL_


#include "config.h"
#include "RenderTextureImpl.h"
#include <gfx/CubeFace.h>


namespace synkro
{


namespace gfx
{


// Generic cube rendering texture implementation.
template <class T>
class CubeRenderTextureImpl :
	public RenderTextureImpl<T>
{
public:
	// Constructor & destructor.
	CubeRenderTextureImpl( UInt length, const img::PixelFormat& format );
	virtual ~CubeRenderTextureImpl();

	// ICubeRenderTexture methods.
	virtual Bool											BindFace( const CubeFace& face );
	virtual UInt											GetLength() const;

protected:
	UInt													_length;
};


#include "CubeRenderTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_CUBERENDERTEXTUREIMPL_
