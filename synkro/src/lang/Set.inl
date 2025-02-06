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
static UInt Set_NextInt( UInt n )
{
	static const UInt primes[] = 
	{
		37, 67, 131, 257, 521, 1031, 2053, 4099, 
		8209, 16411, 32771, 65543, 129403 
	};
	
	for ( UInt i = 0 ; i < sizeof(primes)/sizeof(primes[0]) ; ++i )
	{
		if ( primes[i] > n )
			return primes[i];
	}

	n += primes[ sizeof(primes)/sizeof(primes[0]) - 1 ];
	n |= 1;
	return n;
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE Set<K,F,E,A>::Set( const A& alloc ) :
	_alloc( alloc )
{
	Defaults();
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE Set<K,F,E,A>::Set( Float loadFactor, const A& alloc ) :
	_alloc( alloc )
{
	assert( loadFactor >= 0.01f && loadFactor <= 0.99f );

	Defaults();
	_loadFactor = loadFactor;
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE Set<K,F,E,A>::Set( UInt initialCapacity, Float loadFactor, const A& alloc ) :
	_alloc( alloc )
{
	assert( loadFactor >= 0.01f && loadFactor <= 0.99f );
	assert( initialCapacity > 0 );

	Defaults();
	_loadFactor = loadFactor;
	_capacity = Set_NextInt( initialCapacity );
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE Set<K,F,E,A>::Set( UInt initialCapacity, Float loadFactor, const F& hashFunc, const E& equalFunc, const A& alloc ) :
	_alloc( alloc )
{
	assert( loadFactor >= 0.01f && loadFactor <= 0.99f );
	assert( initialCapacity > 0 );

	Defaults();
	_capacity = Set_NextInt( initialCapacity );
	_data = AllocateSet( _capacity );
	_loadFactor = loadFactor;
	_size = 0;
	_entryLimit = CastUInt(_capacity * _loadFactor);
	_hashFunc = hashFunc;
	_equalFunc = equalFunc;
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE Set<K,F,E,A>::Set( const Set<K,F,E,A>& other ) :
	_alloc( other._alloc )
{
	Defaults();
	*this = other;
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE Set<K,F,E,A>::~Set()
{
	Destroy();
}

template <class K, class F, class E, class A> 
Set<K,F,E,A>& Set<K,F,E,A>::operator=( const Set<K,F,E,A>& other )
{
	if ( this != &other )
	{
		Destroy();
		_alloc = other._alloc;
		if ( other._size > 0 )
		{
			UInt capacity = other._capacity;
			SetItem<K>* data = AllocateSet( capacity );
			other.RehashTo( data, capacity );
			_capacity = capacity;
			_data = data;
			_loadFactor = other._loadFactor;
			_size = other._size;
			_entryLimit = other._entryLimit;
		}
	}
	return *this;
}

template <class K, class F, class E, class A>
SYNKRO_INLINE void Set<K,F,E,A>::Put( const K& key )
{
	if ( _size+1 >= _entryLimit )
		Grow();
	SetItem<K>* item = GetItem( _data, _capacity, key );
	if ( !item->used )
	{
		item->used = true;
		++_size;
	}
}

template <class K, class F, class E, class A>
void Set<K,F,E,A>::Remove( const K& key )
{
	UInt slot = (_hashFunc(key) & 0x7FFFFFFF) % _capacity;
	SetItem<K>* first = &_data[slot];

	SetItem<K>* prevItem = 0;
	SetItem<K>* nextItem = 0;
	for ( SetItem<K>* item = first ; item ; item = nextItem )
	{
		nextItem = item->next;

		if ( item->used && _equalFunc(item->key,key) )
		{
			item->used = false;
			--_size;

			if ( item != first )
			{
				assert( prevItem );
				prevItem->next = item->next;
				_alloc.Deallocate( item, 1 );
			}
		}

		prevItem = item;
	}
}

template <class K, class F, class E, class A> 
void Set<K,F,E,A>::Clear()
{
	for ( UInt i = 0 ; i < _capacity ; ++i )
	{
		SetItem<K>* nextItem = 0;
		for ( SetItem<K>* item = &_data[i] ; item ; item = nextItem )
		{
			nextItem = item->next;
			if ( item->used )
			{
				item->used = false;
				--_size;
			}
		}
	}

	assert( _size == 0 );
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE Float Set<K,F,E,A>::LoadFactor() const
{
	return _loadFactor;
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE UInt Set<K,F,E,A>::Capacity() const
{
	return _capacity;
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE UInt Set<K,F,E,A>::Size() const
{
	return _size;
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE Bool Set<K,F,E,A>::IsEmpty() const
{
	return _size == 0;
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE Bool Set<K,F,E,A>::Contains( const K& key ) const
{
	if ( _size > 0 )
	{
		UInt slot = (_hashFunc(key) & 0x7FFFFFFF) % _capacity;
		SetItem<K>* item = &_data[slot];
		for ( ; item ; item = item->next )
		{
			if ( item->used && _equalFunc(item->key,key) )
				return true;
		}
	}
	return false;
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE UInt Set<K,F,E,A>::Collisions() const
{
	return _collisions;
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE SetIterator<K> Set<K,F,E,A>::Begin() const
{
	return SetIterator<K>( _data, _capacity, 0 );
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE SetIterator<K> Set<K,F,E,A>::End() const
{
	return SetIterator<K>();
}

template <class K, class F, class E, class A> 
void Set<K,F,E,A>::Grow()
{
	UInt capacity = Set_NextInt( _capacity );
	SetItem<K>* data = AllocateSet( capacity );
	_collisions = 0;
	
	for ( UInt i = 0 ; i < _capacity ; ++i )
	{
		SetItem<K>* nextItem = nullptr;
		for ( SetItem<K>* item = &_data[i] ; item ; item = nextItem )
		{
			nextItem = item->next;
			if ( item->used )
			{
				SetItem<K>* newItem = GetItem( data, capacity, item->key );
				newItem->used = true;
			}
			item->next = nullptr;
			if ( _data+i != item )
				_alloc.Deallocate( item, 1 );
		}
	}

	DeallocateSet( _data, _capacity );
	_capacity = capacity;
	_data = data;
	_entryLimit = CastUInt( _capacity * _loadFactor );
}

template <class K, class F, class E, class A> 
void Set<K,F,E,A>::RehashTo( SetItem<K>* data, UInt capacity ) const
{
	for ( UInt i = 0 ; i < _capacity ; ++i )
	{
		SetItem<K>* nextItem = 0;
		for ( SetItem<K>* item = &_data[i] ; item ; item = nextItem )
		{
			nextItem = item->next;
			if ( item->used )
			{
				SetItem<K>* newItem = GetItem( data, capacity, item->key );
				newItem->used = true;
			}
		}
	}
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE void Set<K,F,E,A>::Destroy()
{
	if ( _data )
	{
		DeallocateSet( _data, _capacity );
		Defaults();
	}
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE void Set<K,F,E,A>::Defaults()
{
	_capacity		= 0;
	_data			= nullptr;
	_loadFactor		= 0.75f;
	_size			= 0;
	_entryLimit		= 0;
	_collisions		= 0;
	_hashFunc		= F();
}

template <class K, class F, class E, class A> 
SetItem<K>* Set<K,F,E,A>::GetItem( SetItem<K>* data, UInt capacity, const K& key ) const
{
	UInt slot = (_hashFunc(key) & 0x7FFFFFFF) % capacity;
	SetItem<K>* first = &data[slot];
	SetItem<K>* unused = nullptr;
	
	for ( SetItem<K>* item = first ; item ; item = item->next )
	{
		if ( !item->used )
			unused = item;
		else if ( _equalFunc(item->key,key) )
			return item;
	}

	if ( !unused )
	{
		++_collisions;
		unused = _alloc.Allocate(1);
		unused->used = false;
		unused->next = first->next;
		first->next = unused;
	}
	unused->key = key;
	return unused;
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE SetItem<K>* Set<K,F,E,A>::AllocateSet( UInt capacity ) const
{
	return _alloc.Allocate( capacity );
}

template <class K, class F, class E, class A> 
SYNKRO_INLINE void Set<K,F,E,A>::DeallocateSet( SetItem<K>* data, UInt capacity ) const
{
	for ( UInt i = 0 ; i < capacity ; ++i )
	{
		SetItem<K>* nextItem = nullptr;
		for ( SetItem<K>* item = data[i].next ; item ; item = nextItem )
		{
			nextItem = item->next;
			_alloc.Deallocate( item, 1 );
		}
	}
	_alloc.Deallocate( data, capacity );
}

template <class K, class A> 
SYNKRO_INLINE SetCI<K,A>::SetCI( const A& alloc ) :
	Set<K,HashCI<K>,EqualCI<K>,A>( alloc )
{
}
