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
// Purpose: Generic rendering queue implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE RenderQueueImpl<T>::RenderQueueImpl() :
	_enabled( true )
{
}

template <class T>
SYNKRO_INLINE RenderQueueImpl<T>::~RenderQueueImpl()
{
}

template <class T>
SYNKRO_INLINE void RenderQueueImpl<T>::Enable( Bool enable )
{
	_enabled = enable;
}

template <class T>
SYNKRO_INLINE Bool RenderQueueImpl<T>::IsEnabled() const
{
	return _enabled;
}
