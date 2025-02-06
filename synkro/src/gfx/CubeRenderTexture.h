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
// Purpose: Logical cube rendering texture.
//==============================================================================
#ifndef _SYNKRO_GFX_CUBERENDERTEXTURE_
#define _SYNKRO_GFX_CUBERENDERTEXTURE_


#include "config.h"
#include <gfx/ResourceImpl.h>
#include <gfx/ICubeRenderTexture.h>
#include "BaseResourceImpl.h"
#include "BaseResource.h"


namespace synkro
{


namespace gfx
{


// Logical cube rendering texture.
class CubeRenderTexture :
	public ResourceImpl<ICubeRenderTexture>,
	public BaseResourceImpl<BaseResource>
{
public:
	// Constructor.
	CubeRenderTexture( ICubeRenderTexture* texture );

	// IResource methods.
	IRenderTexture*											AsRenderTexture() const;

	// IRenderTexture methods.
	Bool													Bind();
	void													Clear();
	Bool													Present();
	void													SetDefaultColor( const math::Vector4& color );
	void													GetDefaultColor( math::Vector4& color ) const;
	img::PixelFormat										GetFormat() const;

	// ICubeRenderTexture methods.
	Bool													BindFace( const CubeFace& face );
	Bool													GetData( const CubeFace& face, UInt* length, UInt* stride, img::PixelFormat* format, Byte** data, UInt* size );
	UInt													GetLength() const;

private:
	P(ICubeRenderTexture)									_texture;
};


#include "CubeRenderTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_CUBERENDERTEXTURE_
