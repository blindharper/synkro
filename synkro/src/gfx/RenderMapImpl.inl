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
// Purpose: Generic rendering map implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE RenderMapImpl<T>::RenderMapImpl( IRenderQueue* queue ) :
	_queue( queue ),
	_vertexParams( nullptr )
{
}

template <class T>
SYNKRO_INLINE RenderMapImpl<T>::~RenderMapImpl()
{
}

template <class T>
SYNKRO_INLINE void RenderMapImpl<T>::SetVertexParams( IParameterSet* params )
{
	_vertexParams = params;
}

template <class T>
SYNKRO_INLINE IParameterSet* RenderMapImpl<T>::GetVertexParams() const
{
	return _vertexParams;
}

template <class T>
SYNKRO_INLINE IRenderQueue* RenderMapImpl<T>::GetQueue() const
{
	return _queue;
}
