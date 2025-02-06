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
#ifndef _SYNKRO_LANG_SETEX_
#define _SYNKRO_LANG_SETEX_


#include "config.h"
#include "Set.h"
#include <internal/Mutex.h>


namespace synkro
{


namespace lang
{


// Thread-safe set.
template < class K, class F = Hash<K>, class E = Equal<K>, class A = Allocator<SetPair<K> > >
class SetEx
{
public:
	// Creates thread-safe copy of another set.
	SetEx( const Set<K,F,E,A>& set );

	// Destroys the set.
	~SetEx();

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
	Set<K,F,E,A>											_set;
	Mutex													_mutex;
};


#include "SetEx.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_SETEX_
