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
// Purpose: Defines thread-safe hash map.
//==============================================================================
template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE MapEx<K,T,F,E,A>::MapEx( const Map<K,T,F,E,A>& map ) :
	_map( map )
{
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE MapEx<K,T,F,E,A>::~MapEx()
{
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE T& MapEx<K,T,F,E,A>::operator[]( const K& key )
{
	LOCK( _mutex );

	return _map.operator[]( key );
}

template <class K, class T, class F, class E, class A>
SYNKRO_INLINE T& MapEx<K,T,F,E,A>::Get( const K& key )
{
	LOCK( _mutex );

	return _map.Get( key );
}	

template <class K, class T, class F, class E, class A>
SYNKRO_INLINE void MapEx<K,T,F,E,A>::Put( const K& key, const T& value )
{
	LOCK( _mutex );

	_map.Put( key, value );
}

template <class K, class T, class F, class E, class A>
void MapEx<K,T,F,E,A>::Remove( const K& key )
{
	LOCK( _mutex );

	_map.Remove( key );
}

template <class K, class T, class F, class E, class A> 
void MapEx<K,T,F,E,A>::Clear()
{
	LOCK( _mutex );

	_map.Clear();
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE const T& MapEx<K,T,F,E,A>::operator[]( const K& key ) const
{
	return _map.operator[]( key );
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE const T& MapEx<K,T,F,E,A>::Get( const K& key ) const
{
	return _map.Get( key );
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Bool MapEx<K,T,F,E,A>::ContainsKey( const K& key ) const
{
	return _map.ContainsKey( key );
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Float MapEx<K,T,F,E,A>::LoadFactor() const
{
	return _map.LoadFactor();
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Int MapEx<K,T,F,E,A>::Capacity() const
{
	return _map.Capacity();
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Int MapEx<K,T,F,E,A>::Size() const
{
	return _map.Size();
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Bool MapEx<K,T,F,E,A>::IsEmpty() const
{
	return _map.IsEmpty();
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Int MapEx<K,T,F,E,A>::Collisions() const
{
	return _map.Collisions();
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE MapIterator<K,T> MapEx<K,T,F,E,A>::Begin() const
{
	return _map.Begin();
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE MapIterator<K,T> MapEx<K,T,F,E,A>::End() const
{
	return _map.End();
}
