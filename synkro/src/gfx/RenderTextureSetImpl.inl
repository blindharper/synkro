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
// Purpose: Generic rendering texture set implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE RenderTextureSetImpl<T>::RenderTextureSetImpl() :
	_textures( A(P(IRenderTexture)) ),
	_defaultColor( math::Vector4(0.0f, 0.0f, 0.0f, 1.0f) )
{
}

template <class T>
SYNKRO_INLINE RenderTextureSetImpl<T>::~RenderTextureSetImpl()
{
}

template <class T>
SYNKRO_INLINE Bool RenderTextureSetImpl<T>::Present()
{
	// Do nothing.
	return true;
}

template <class T>
SYNKRO_INLINE void RenderTextureSetImpl<T>::Set( UInt index, IRenderTexture* texture )
{
	assert( index < _textures.Size() );

	if ( index >= _textures.Size() )
		throw lang::OutOfRangeException( index, _textures.Size() );

	_textures[index] = texture;
}

template <class T>
SYNKRO_INLINE void RenderTextureSetImpl<T>::SetDefaultColor( const math::Vector4& color )
{
	_defaultColor = color;
}

template <class T>
SYNKRO_INLINE void RenderTextureSetImpl<T>::GetDefaultColor( math::Vector4& color ) const
{
	color = _defaultColor;
}

template <class T>
SYNKRO_INLINE UInt RenderTextureSetImpl<T>::GetSize() const
{
	return _textures.Size();
}

template <class T>
SYNKRO_INLINE IRenderTexture* RenderTextureSetImpl<T>::Get( UInt index ) const
{
	assert( index < _textures.Size() );

	if ( index >= _textures.Size() )
		throw lang::OutOfRangeException( index, _textures.Size() );

	return _textures[index];
}
