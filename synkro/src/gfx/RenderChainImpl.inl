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
// Purpose: Generic render chain implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE RenderChainImpl<T>::RenderChainImpl() :
	_targets( A(P(IPlainRenderTexture)) ),
	_target( nullptr ),
	_backBuffer( nullptr ),
	_targetIndex( 0 ),
	_began( false )
{
}

template <class T>
SYNKRO_INLINE RenderChainImpl<T>::~RenderChainImpl()
{
}

template <class T>
SYNKRO_INLINE Bool RenderChainImpl<T>::Begin( IPlainRenderTexture* target )
{
	if ( !_began )
	{
		// Swap targets, if needed.
		if ( target == nullptr )
		{
			_target = _targets[_targetIndex];
			_targetIndex = (_targetIndex == 0) ? 1 : 0;
			_backBuffer = _targets[_targetIndex];
		}
		else
		{
			_target = target;
		}

		// Bind targets.
		_began = _target->Bind();
	}

	return _began;
}

template <class T>
SYNKRO_INLINE void RenderChainImpl<T>::Present()
{
	_target->Present();
}

template <class T>
SYNKRO_INLINE Bool RenderChainImpl<T>::End()
{
	if ( _began )
	{
		_began = false;
		return _target->Present();
	}

	return false;
}

template <class T>
SYNKRO_INLINE IResource* RenderChainImpl<T>::GetBackBuffer() const
{
	return _backBuffer;
}
