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
// Purpose: Generic DX11 resource implementation.
//=============================================================================
#ifndef _SYNKRO_GFX_DX11RESOURCEIMPL_
#define _SYNKRO_GFX_DX11RESOURCEIMPL_


#include "config.h"
#include <d3d11.h>
#include "Dx11Context.h"
#include <internal/SafeRelease.h>


namespace synkro
{


namespace gfx
{


// Generic DX11 base resource implementation.
template <class T>
class Dx11ResourceImpl :
	public T
{
public:
	// Constructor and destructor.
	Dx11ResourceImpl( Dx11Context* context );
	virtual ~Dx11ResourceImpl();

	// Dx11Resource methods.
	virtual void											GenerateMipmaps();
	virtual ID3D11ShaderResourceView*						AsDx11ShaderResourceView() const;

protected:
	Dx11Context												_context;
	ID3D11ShaderResourceView*								_srv;
};


#include "Dx11ResourceImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11RESOURCEIMPL_
