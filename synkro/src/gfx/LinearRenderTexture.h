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
// Purpose: Logical linear rendering texture.
//==============================================================================
#ifndef _SYNKRO_GFX_LINEARRENDERTEXTURE_
#define _SYNKRO_GFX_LINEARRENDERTEXTURE_


#include "config.h"
#include <gfx/ResourceImpl.h>
#include <gfx/ILinearRenderTexture.h>
#include "BaseResourceImpl.h"
#include "BaseResource.h"


namespace synkro
{


namespace gfx
{


// Logical linear rendering texture.
class LinearRenderTexture :
	public ResourceImpl<ILinearRenderTexture>,
	public BaseResourceImpl<BaseResource>
{
public:
	// Constructor.
	LinearRenderTexture( ILinearRenderTexture* texture );

	// IResource methods.
	IRenderTexture*											AsRenderTexture() const;

	// IRenderTexture methods.
	Bool													Bind();
	void													Clear();
	Bool													Present();
	void													SetDefaultColor( const math::Vector4& color );
	void													GetDefaultColor( math::Vector4& color ) const;
	img::PixelFormat										GetFormat() const;

	// ILinearRenderTexture methods.
	Bool													GetData( UInt* length, img::PixelFormat* format, Byte** data, UInt* size );
	UInt													GetLength() const;

private:
	P(ILinearRenderTexture)									_texture;
};


#include "LinearRenderTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_LINEARRENDERTEXTURE_
