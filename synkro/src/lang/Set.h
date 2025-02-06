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
// Purpose: Defines hash set.
//==============================================================================
#ifndef _SYNKRO_LANG_SET_
#define _SYNKRO_LANG_SET_


#include "config.h"
#include "Allocator.h"
#include "SetIterator.h"
#include <internal/Hash.h>
#include <internal/Equal.h>


namespace synkro
{


namespace lang
{


// Hash set stores keys which are at the same time represent values.
// Default hash function uses key hashCode() for hashing.
// Default compare function uses key operator==.
// @param K Key type.
// @param F Key hash function type.
// @param E Key equality compare function type.
// @param A Allocator of SetItem<K>.
template < class K, class F = Hash<K>, class E = Equal<K>, class A = Allocator<SetItem<K> > >
class Set
{
public:
	// Constructs an empty hash set with load factor of 0.75.
	explicit Set( const A& alloc );

	// Constructs an empty hash set with the given load factor.
	explicit Set( Float loadFactor, const A& alloc );

	// Constructs an empty hash set with the given capacity and load factor.
	explicit Set( UInt initialCapacity, Float loadFactor, const A& alloc );

	// Constructs an empty hash set with specified initial capacity, load factor and hash function.
	explicit Set( UInt initialCapacity, Float loadFactor, const F& hashFunc, const E& equalFunc, const A& alloc );

	// Creates a copy of another set.
	Set( const Set<K,F,E,A>& other );

	// Destroys the set.
	~Set();

	// Creates a copy of another set.
	Set<K,F,E,A>&											operator=( const Set<K,F,E,A>& other );

	// Puts the specified key to the container.
	void													Put( const K& key );

	// Removes specified key. Does nothing if the key is not in the set.
	void													Remove( const K& key );

	// Removes all keys from the container.
	void													Clear();

	// Returns set load factor.
	Float													LoadFactor() const;

	// Returns set capacity.
	UInt													Capacity() const;

	// Returns number of distinct keys.
	UInt													Size() const;

	// Returns true if there are no elements in the set.
	Bool													IsEmpty() const;

	// Returns true if the hash set contains specific key.
	Bool													Contains( const K& key ) const;

	// Returns number of collisions occured in the hash set. Can be used for debugging hash functions.
	UInt													Collisions() const;

	// Returns iterator to the first element. Behaviour is undefined if the set is changed during the traversal.
	SetIterator<K>											Begin() const;

	// Returns iterator to one beyond the last element. Behaviour is undefined if the set is changed during the traversal.
	SetIterator<K>											End() const;

protected:
	UInt													_capacity;
	SetItem<K>*												_data;
	Float													_loadFactor;
	mutable UInt											_size;
	UInt													_entryLimit;
	mutable UInt											_collisions;
	F														_hashFunc;
	E														_equalFunc;
	mutable A												_alloc;

	void													Defaults();
	void													Destroy();
	void													Grow();
	void													RehashTo( SetItem<K>* data, UInt capacity ) const;
	SetItem<K>*												GetItem( SetItem<K>* data, UInt capacity, const K& key ) const;
	SetItem<K>*												AllocateSet( UInt capacity ) const;
	void													DeallocateSet( SetItem<K>* data, UInt capacity ) const;
};


// Case-insensitive set.
template < class K, class A = Allocator< SetItem<K> > >
class SetCI :
	public Set<K, HashCI<K>, EqualCI<K>, A>
{
public:
	// Constructs an empty hash set with load factor of 0.75.
	explicit SetCI( const A& alloc );
};


#include "Set.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_SET_
