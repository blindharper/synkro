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
#ifndef _SYNKRO_LANG_MAPEX_
#define _SYNKRO_LANG_MAPEX_


#include "config.h"
#include "Map.h"
#include <internal/Mutex.h>


namespace synkro
{


namespace lang
{


// Thread-safe map.
template < class K, class T, class F = Hash<K>, class E = Equal<K>, class A = Allocator<MapPair<K,T> > >
class MapEx
{
public:
	// Creates thread-safe copy of another map.
	MapEx( const Map<K,T,F,E,A>& map );

	// Destroys the map.
	~MapEx();

	// Returns the value of specified key. Puts the key to the map if not exist.
	T&														operator[]( const K& key );

	// Returns the value of specified key. 
	T&														Get( const K& key );

	// Puts the value at specified key to the container. 
	// If there is already old value with the same key it is overwritten.
	void													Put( const K& key, const T& value );

	// Removes value at specified key. Does nothing if the key is not in the map.
	void													Remove( const K& key );

	// Removes all keys from the container.
	void													Clear();

	// Returns the value of specified key. Puts the key to the map if not exist.
	const T&												operator[]( const K& key ) const;

	// Returns the value of specified key. Returns default value if the key is not in the map.
	const T&												Get( const K& key ) const;

	// Returns map load factor.
	Float													LoadFactor() const;

	// Returns map capacity.
	Int														Capacity() const;

	// Returns number of distinct keys.
	Int														Size() const;

	// Returns true if there are no elements in the map.
	Bool													IsEmpty() const;

	// Returns true if the hash map contains specific key.
	Bool													ContainsKey( const K& key ) const;

	// Returns number of collisions occured in the hash map. Can be used for debugging hash functions.
	Int														Collisions() const;

	// Returns iterator to the first element. Behaviour is undefined if the map is changed during the traversal.
	MapIterator<K,T>										Begin() const;

	// Returns iterator to one beyond the last element. Behaviour is undefined if the map is changed during the traversal.
	MapIterator<K,T>										End() const;

protected:
	Map<K,T,F,E,A>											_map;
	Mutex													_mutex;
};


#include "MapEx.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_MAPEX_
