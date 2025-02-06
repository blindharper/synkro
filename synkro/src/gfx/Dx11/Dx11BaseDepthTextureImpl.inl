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
// Purpose: Generic DX11 base depth texture implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE Dx11BaseDepthTextureImpl<T>::Dx11BaseDepthTextureImpl() :
	_dsv( nullptr )
{
}

template <class T>
SYNKRO_INLINE Dx11BaseDepthTextureImpl<T>::~Dx11BaseDepthTextureImpl()
{
	SafeRelease( _dsv );
}

template <class T>
SYNKRO_INLINE ID3D11DepthStencilView* Dx11BaseDepthTextureImpl<T>::AsDx11DepthStencilView() const
{
	return _dsv;
}
