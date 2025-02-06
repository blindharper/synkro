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
// Purpose: Defines smart pointer to an object.
//==============================================================================
template <class T>
SYNKRO_INLINE Ptr<T>::Ptr( T* other )
{
	if ( other != nullptr )
	{
		other->AddRef();
	}
	_object = other;
}

template <class T>
SYNKRO_INLINE Ptr<T>::Ptr( const Ptr<T>& other )
{
	T* obj = other._object;
	if ( obj != nullptr )
	{
		obj->AddRef();
	}
	_object = obj;
}

template <class T>
SYNKRO_INLINE Ptr<T>::Ptr() :
	_object( nullptr )
{
}

template <class T>
SYNKRO_INLINE Ptr<T>::~Ptr()
{
	if ( _object != nullptr )
	{ 
		if ( _object->Release() == 0 )
		{
			_object = nullptr;
		}
	}
}

template <class T>
SYNKRO_INLINE Ptr<T>& Ptr<T>::operator=( T* other )
{
	if ( other != _object )
	{
		if ( other != nullptr )
		{
			other->AddRef();
		}

		if ( _object != nullptr )
		{
			if ( _object->Release() == 0 )
			{
				_object = nullptr;
			}
		}

		_object = other;
	}
	return *this;
}

template <class T>
SYNKRO_INLINE Ptr<T>& Ptr<T>::operator=( const Ptr<T>& other )
{
	if ( other != *this )
	{
		T* obj = other._object;

		if ( obj != nullptr )
		{
			obj->AddRef();
		}

		if ( _object != nullptr )
		{
			if ( _object->Release() == 0 )
			{
				_object = nullptr;
			}
		}

		_object = obj;
	}
	return *this;
}

template <class T>
SYNKRO_INLINE Bool Ptr<T>::operator==( T* other ) const
{
	return _object == other;
}

template <class T>
SYNKRO_INLINE Bool Ptr<T>::operator==( const Ptr<T>& other ) const
{
	return _object == other._object;
}

template <class T>
SYNKRO_INLINE Bool Ptr<T>::operator!=( T* other ) const
{
	return _object != other;
}

template <class T>
SYNKRO_INLINE Bool Ptr<T>::operator!=( const Ptr<T>& other ) const
{
	return _object != other._object;
}

template <class T>
SYNKRO_INLINE T& Ptr<T>::operator*() const
{
	if ( _object == nullptr )
		throw NullReferenceException( __FILE__, __LINE__ );

	return *_object;
}

template <class T>
SYNKRO_INLINE T* Ptr<T>::operator->() const
{
	if ( _object == nullptr )
		throw NullReferenceException( __FILE__, __LINE__ );

	return _object;
}

template <class T>
SYNKRO_INLINE Ptr<T>::operator T*() const
{
	return _object;
}

template <class T>
SYNKRO_INLINE T* Ptr<T>::AsPtr() const
{
	return _object;
}
