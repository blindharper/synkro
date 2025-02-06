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
// Purpose: Defines thread-safe hash set.
//==============================================================================
template <class K, class F, class E, class A> 
SYNKRO_INLINE SetEx<K,F,E,A>::SetEx( const Set<K,F,E,A>& set ) :
	_set( set )
{
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE SetEx<K,F,E,A>::~SetEx()
{
}

template <class K, class F, class E, class A>
SYNKRO_INLINE void SetEx<K,F,E,A>::Put( const K& key )
{
	LOCK( _mutex );

	_set.Put( key );
}

template <class K, class F, class E, class A>
void SetEx<K,F,E,A>::Remove( const K& key )
{
	LOCK( _mutex );

	_set.Remove( key );
}

template <class K, class F, class E, class A> 
void SetEx<K,F,E,A>::Clear()
{
	LOCK( _mutex );

	_set.Clear();
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE Bool SetEx<K,F,E,A>::Contains( const K& key ) const
{
	return _set.Contains( key );
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE Float SetEx<K,F,E,A>::LoadFactor() const
{
	return _set.LoadFactor();
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE UInt SetEx<K,F,E,A>::Capacity() const
{
	return _set.Capacity();
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE Int SetEx<K,F,E,A>::Size() const
{
	return _set.Size();
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE Bool SetEx<K,F,E,A>::IsEmpty() const
{
	return _set.IsEmpty();
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE UInt SetEx<K,F,E,A>::Collisions() const
{
	return _set.Collisions();
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE SetIterator<K> SetEx<K,F,E,A>::Begin() const
{
	return _set.Begin();
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE SetIterator<K> SetEx<K,F,E,A>::End() const
{
	return _set.End();
}
