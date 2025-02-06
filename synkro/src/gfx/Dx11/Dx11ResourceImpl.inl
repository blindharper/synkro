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
template <class T>
SYNKRO_INLINE Dx11ResourceImpl<T>::Dx11ResourceImpl( Dx11Context* context ) :
	_context( context ),
	_srv( nullptr )
{
}

template <class T>
SYNKRO_INLINE Dx11ResourceImpl<T>::~Dx11ResourceImpl()
{
	SafeRelease( _srv );
}

template <class T>
SYNKRO_INLINE void Dx11ResourceImpl<T>::GenerateMipmaps()
{
	Dx11Lock( _context );
	_context->GenerateMips( _srv );
}

template <class T>
SYNKRO_INLINE ID3D11ShaderResourceView* Dx11ResourceImpl<T>::AsDx11ShaderResourceView() const
{
	return _srv;
}
