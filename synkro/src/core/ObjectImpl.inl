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
// Purpose: Generic IObject interface implementation.
//==============================================================================
template <class T> 
SYNKRO_INLINE ObjectImpl<T>::ObjectImpl() :
	_id( Platform::NextID() ),
	_refCount( 0 )
{
}

template <class T>
SYNKRO_INLINE ObjectImpl<T>::~ObjectImpl()
{
}

template <class T>
SYNKRO_INLINE Int ObjectImpl<T>::AddRef()
{
	return _refCount = Platform::Increment( _refCount );
}

template <class T>
SYNKRO_INLINE Int ObjectImpl<T>::Release()
{
	if ( (_refCount = Platform::Decrement(_refCount)) == 0 )
	{
		delete this;
		return 0;
	}
	return _refCount;
}

template <class T>
SYNKRO_INLINE UInt ObjectImpl<T>::ID() const
{
	return _id;
}
