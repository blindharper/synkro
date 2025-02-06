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
// Purpose: Generic DX11 base rendering texture implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE Dx11BaseRenderTextureImpl<T>::Dx11BaseRenderTextureImpl() :
	_rtv( nullptr )
{
}

template <class T>
SYNKRO_INLINE Dx11BaseRenderTextureImpl<T>::~Dx11BaseRenderTextureImpl()
{
	SafeRelease( _rtv );
}

template <class T>
SYNKRO_INLINE ID3D11RenderTargetView* Dx11BaseRenderTextureImpl<T>::AsDx11RenderTargetView() const
{
	return _rtv;
}
