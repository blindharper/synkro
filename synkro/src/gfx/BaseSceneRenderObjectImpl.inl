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
// Purpose: Generic base scene render object implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE BaseSceneRenderObjectImpl<T>::BaseSceneRenderObjectImpl()
{
}

template <class T>
SYNKRO_INLINE BaseSceneRenderObjectImpl<T>::~BaseSceneRenderObjectImpl()
{
}

template <class T>
SYNKRO_INLINE void BaseSceneRenderObjectImpl<T>::SetKeys( const lang::String& resourceKey, const lang::String& dataKey, const lang::String& instanceKey )
{
	_resourceKey	= resourceKey;
	_dataKey		= dataKey;
	_instanceKey	= instanceKey;
}

template <class T>
SYNKRO_INLINE lang::String BaseSceneRenderObjectImpl<T>::GetResourceKey() const
{
	return _resourceKey;
}

template <class T>
SYNKRO_INLINE lang::String BaseSceneRenderObjectImpl<T>::GetDataKey() const
{
	return _dataKey;
}

template <class T>
SYNKRO_INLINE lang::String BaseSceneRenderObjectImpl<T>::GetInstanceKey() const
{
	return _instanceKey;
}
