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
// Purpose: Defines hash map.
//==============================================================================
#ifndef _SYNKRO_LANG_MAP_
#define _SYNKRO_LANG_MAP_


#include "config.h"
#include "Allocator.h"
#include "MapIterator.h"
#include <internal/Hash.h>
#include <internal/Equal.h>


namespace synkro
{


namespace lang
{


// Map maps keys to values. 
// Default hash function uses key hashCode() for hashing.
// Default compare function uses key operator==.
// @param K Key type.
// @param T Element type.
// @param F Key hash function type.
// @param E Key equality compare function type.
// @param A Allocator of MapPair<K,T>.
template < class K, class T, class F = Hash<K>, class E = Equal<K>, class A = Allocator<MapPair<K,T> > >
class Map
{
public:
	// Constructs an empty hash map with load factor of 0.75.
	explicit Map( const A& alloc );

	// Constructs an empty hash map with the given load factor.
	explicit Map( Float loadFactor, const A& alloc );

	// Constructs an empty hash map with the given capacity and load factor.
	explicit Map( UInt initialCapacity, Float loadFactor, const A& alloc );

	// Constructs an empty hash map with specified initial capacity, load factor, default value and hash function.
	explicit Map( UInt initialCapacity, Float loadFactor, const T& defaultValue, const F& hashFunc, const E& equalFunc, const A& alloc );

	// Creates a copy of another map.
	Map( const Map<K,T,F,E,A>& other );

	// Destroys the map.
	~Map();

	// Creates a copy of another map.
	Map<K,T,F,E,A>&											operator=( const Map<K,T,F,E,A>& other );

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
	UInt													Capacity() const;

	// Returns number of distinct keys.
	UInt													Size() const;

	// Returns true if there are no elements in the map.
	Bool													IsEmpty() const;

	// Returns true if the hash map contains specific key.
	Bool													ContainsKey( const K& key ) const;

	// Returns number of collisions occured in the hash map. Can be used for debugging hash functions.
	UInt													Collisions() const;

	// Returns iterator to the first element. Behaviour is undefined if the map is changed during the traversal.
	MapIterator<K,T>										Begin() const;

	// Returns iterator to one beyond the last element. Behaviour is undefined if the map is changed during the traversal.
	MapIterator<K,T>										End() const;

protected:
	UInt													_capacity;
	MapPair<K,T>*											_data;
	Float													_loadFactor;
	mutable UInt											_size;
	UInt													_entryLimit;
	T														_defaultValue;
	mutable UInt											_collisions;
	F														_hashFunc;
	E														_equalFunc;
	mutable A												_alloc;

	void													Defaults();
	void													Destroy();
	void													Grow();
	void													RehashTo( MapPair<K,T>* data, UInt capacity ) const;
	MapPair<K,T>*											GetPair( MapPair<K,T>* data, UInt capacity, const K& key ) const;
	MapPair<K,T>*											AllocateMap( UInt capacity ) const;
	void													DeallocateMap( MapPair<K,T>* data, UInt capacity ) const;
};


// Case-insensitive map.
template < class K, class T, class A = Allocator< MapPair<K,T> > >
class MapCI :
	public Map<K, T, HashCI<K>, EqualCI<K>, A>
{
public:
	// Constructs an empty hash map with load factor of 0.75.
	explicit MapCI( const A& alloc );
};


#include "Map.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_MAP_
