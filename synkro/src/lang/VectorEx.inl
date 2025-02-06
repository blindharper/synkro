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
// Purpose: Defines thread-safe dynamic array.
//==============================================================================
template <class T, class A>
SYNKRO_INLINE VectorEx<T,A>::VectorEx( const Vector<T,A>& vector ) :
	_vector( vector )
{
}

template <class T, class A>
SYNKRO_INLINE VectorEx<T,A>::~VectorEx()
{
}

template <class T, class A>
SYNKRO_INLINE void VectorEx<T,A>::SetSize( UInt size, const T& value )
{
	LOCK( _mutex );

	_vector.SetSize( size, value );
}

template <class T, class A>
SYNKRO_INLINE void VectorEx<T,A>::SetSize( UInt size )
{
	LOCK( _mutex );

	_vector.SetSize( size );
}

template <class T, class A>
SYNKRO_INLINE void VectorEx<T,A>::Add( const T& elem )
{
	LOCK( _mutex );

	_vector.Add( elem );
}

template <class T, class A>
SYNKRO_INLINE void VectorEx<T,A>::Add( const T* elems, UInt size )
{
	LOCK( _mutex );

	_vector.Add( elems, size );
}

template <class T, class A>
SYNKRO_INLINE void VectorEx<T,A>::Insert( UInt index, const T& elem )
{
	LOCK( _mutex );

	_vector.Insert( index, elem );
}

template <class T, class A>
SYNKRO_INLINE void VectorEx<T,A>::Set( UInt start, const T* elems, UInt size )
{
	LOCK( _mutex );

	_vector.Set( start, elems, size );
}

template <class T, class A>
SYNKRO_INLINE void VectorEx<T,A>::Swap( UInt first, UInt second )
{
	LOCK( _mutex );

	_vector.Swap( first, second );
}

template <class T, class A>
SYNKRO_INLINE void VectorEx<T,A>::Remove( UInt index )
{
	LOCK( _mutex );

	_vector.Remove( index );
}

template <class T, class A>
SYNKRO_INLINE void VectorEx<T,A>::Remove( const T& elem )
{
	LOCK( _mutex );

	_vector.Remove( elem );
}

template <class T, class A>
SYNKRO_INLINE void VectorEx<T,A>::TrimToSize()
{
	LOCK( _mutex );

	_vector.TrimToSize();
}

template <class T, class A>
SYNKRO_INLINE void VectorEx<T,A>::Clear()
{
	LOCK( _mutex );

	_vector.Clear();
}

template <class T, class A>
SYNKRO_INLINE void VectorEx<T,A>::Sort()
{
	LOCK( _mutex );

	_vector.Sort();
}

template<class T, class A> template<class F, class P>
SYNKRO_INLINE void VectorEx<T,A>::Each( F& function, const P& param )
{
	LOCK( _mutex );

	_vector.Each( function, param );
}

template<class T, class A> template<class F>
SYNKRO_INLINE void VectorEx<T,A>::Each( F& function )
{
	LOCK( _mutex );

	_vector.Each( function );
}

template <class T, class A>
SYNKRO_INLINE T& VectorEx<T,A>::operator[]( UInt index )
{
	LOCK( _mutex );

	return _vector.operator[]( index );
}

template <class T, class A>
SYNKRO_INLINE T& VectorEx<T,A>::LastValue()
{
	LOCK( _mutex );

	return _vector.LastValue();
}

template<class T, class A> template<class F, class P>
SYNKRO_INLINE void VectorEx<T,A>::Each( F& function, const P& param ) const
{
	LOCK( _mutex );

	_vector.Each( function, param );
}

template<class T, class A> template<class F>
SYNKRO_INLINE void VectorEx<T,A>::Each( F& function ) const
{
	LOCK( _mutex );

	_vector.Each( function );
}

template <class T, class A>
SYNKRO_INLINE const T& VectorEx<T,A>::operator[]( UInt index ) const
{
	return _vector.operator[]( index );
}

template <class T, class A>
SYNKRO_INLINE const T& VectorEx<T,A>::LastValue() const
{
	LOCK( _mutex );

	return _vector.LastValue();
}

template <class T, class A>
SYNKRO_INLINE UInt VectorEx<T,A>::IndexOf( const T& elem, UInt start ) const
{
	return _vector.IndexOf( elem, start );
}

template <class T, class A>
SYNKRO_INLINE UInt VectorEx<T,A>::IndexOf( const T& elem ) const
{
	return _vector.IndexOf( elem );
}

template <class T, class A>
SYNKRO_INLINE UInt VectorEx<T,A>::LastIndexOf( const T& elem, UInt start ) const
{
	return _vector.LastIndexOf( elem, start );
}

template <class T, class A>
SYNKRO_INLINE UInt VectorEx<T,A>::LastIndexOf( const T& elem ) const
{
	return _vector.LastIndexOf( elem );
}

template <class T, class A>
SYNKRO_INLINE Bool VectorEx<T,A>::Contains( const T& elem ) const
{
	return _vector.Contains( elem );
}

template <class T, class A>
SYNKRO_INLINE void VectorEx<T,A>::Get( UInt start, T* elems, UInt size ) const
{
	_vector.Get( start, elems, size );
}

template <class T, class A>
SYNKRO_INLINE UInt VectorEx<T,A>::Capacity() const
{
	return _vector.Capacity();
}

template <class T, class A>
SYNKRO_INLINE UInt VectorEx<T,A>::Size() const
{
	return _vector.Size();
}

template <class T, class A>
SYNKRO_INLINE Bool VectorEx<T,A>::IsEmpty() const
{
	return _vector.IsEmpty();
}

template <class T, class A>
SYNKRO_INLINE T* VectorEx<T,A>::Begin() const
{
	return _vector.Begin();
}

template <class T, class A>
SYNKRO_INLINE T* VectorEx<T,A>::Last() const
{
	return _vector.Last();
}

template <class T, class A>
SYNKRO_INLINE T* VectorEx<T,A>::End() const
{
	return _vector.End();
}

template <class T, class A>
SYNKRO_INLINE T* VectorEx<T,A>::Get( UInt index ) const
{
	return _vector.Get( index );
}
