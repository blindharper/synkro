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
// Purpose: Generic resource implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE ResourceImpl<T>::ResourceImpl()
{
}

template <class T>
SYNKRO_INLINE ResourceImpl<T>::~ResourceImpl()
{
}

template <class T>
SYNKRO_INLINE IBuffer* ResourceImpl<T>::AsBuffer() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ITexture* ResourceImpl<T>::AsTexture() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IRenderTexture* ResourceImpl<T>::AsRenderTexture() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IDepthTexture* ResourceImpl<T>::AsDepthTexture() const
{
	return nullptr;
}
