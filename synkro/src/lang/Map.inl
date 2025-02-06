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
static UInt Map_NextInt( UInt n )
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

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Map<K,T,F,E,A>::Map( const A& alloc ) :
	_alloc( alloc )
{
	Defaults();
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Map<K,T,F,E,A>::Map( Float loadFactor, const A& alloc ) :
	_alloc( alloc )
{
	assert( loadFactor >= 0.01f && loadFactor <= 0.99f );

	Defaults();
	_loadFactor = loadFactor;
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Map<K,T,F,E,A>::Map( UInt initialCapacity, Float loadFactor, const A& alloc ) :
	_alloc( alloc )
{
	assert( loadFactor >= 0.01f && loadFactor <= 0.99f );
	assert( initialCapacity > 0 );

	Defaults();
	_loadFactor = loadFactor;
	_capacity = Map_NextInt( initialCapacity );
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Map<K,T,F,E,A>::Map( UInt initialCapacity, Float loadFactor, const T& defaultValue, const F& hashFunc, const E& equalFunc, const A& alloc ) :
	_alloc( alloc )
{
	assert( loadFactor >= 0.01f && loadFactor <= 0.99f );
	assert( initialCapacity > 0 );

	Defaults();
	_capacity = Map_NextInt( initialCapacity );
	_data = AllocateMap( _capacity );
	_loadFactor = loadFactor;
	_size = 0;
	_entryLimit = CastUInt(_capacity * _loadFactor);
	_defaultValue = defaultValue;
	_hashFunc = hashFunc;
	_equalFunc = equalFunc;
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Map<K,T,F,E,A>::Map( const Map<K,T,F,E,A>& other ) :
	_alloc( other._alloc )
{
	Defaults();
	*this = other;
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Map<K,T,F,E,A>::~Map()
{
	Destroy();
}

template <class K, class T, class F, class E, class A> 
Map<K,T,F,E,A>& Map<K,T,F,E,A>::operator=( const Map<K,T,F,E,A>& other )
{
	if ( this != &other )
	{
		Destroy();
		_alloc = other._alloc;
		if ( other._size > 0 )
		{
			UInt capacity = other._capacity;
			MapPair<K,T>* data = AllocateMap( capacity );
			other.RehashTo( data, capacity );
			_capacity = capacity;
			_data = data;
			_loadFactor = other._loadFactor;
			_size = other._size;
			_entryLimit = other._entryLimit;
			_defaultValue = other._defaultValue;
		}
	}
	return *this;
}

template <class K, class T, class F, class E, class A>
SYNKRO_INLINE T& Map<K,T,F,E,A>::Get( const K& key )
{
	MapPair<K,T>* pair = GetPair( _data, _capacity, key );
	if ( !pair->used )
	{
		pair->used = true;
		++_size;
	}
	return pair->value;
}	

template <class K, class T, class F, class E, class A>
SYNKRO_INLINE void Map<K,T,F,E,A>::Put( const K& key, const T& value )
{
	if ( _size+1 >= _entryLimit )
		Grow();
	MapPair<K,T>* pair = GetPair( _data, _capacity, key );
	pair->value = value;
	if ( !pair->used )
	{
		pair->used = true;
		++_size;
	}
}

template <class K, class T, class F, class E, class A>
void Map<K,T,F,E,A>::Remove( const K& key )
{
	UInt slot = (_hashFunc(key) & 0x7FFFFFFF) % _capacity;
	MapPair<K,T>* first = &_data[slot];

	MapPair<K,T>* prevPair = nullptr;
	MapPair<K,T>* nextPair = nullptr;
	for ( MapPair<K,T>* pair = first ; pair ; pair = nextPair )
	{
		nextPair = pair->next;

		if ( pair->used && _equalFunc(pair->key,key) )
		{
			pair->used = false;
			pair->value = _defaultValue;
			--_size;

			if ( pair != first )
			{
				assert( prevPair != nullptr );
				prevPair->next = pair->next;
				_alloc.Deallocate( pair, 1 );
			}
		}

		prevPair = pair;
	}
}

template <class K, class T, class F, class E, class A> 
void Map<K,T,F,E,A>::Clear()
{
	for ( UInt i = 0 ; i < _capacity ; ++i )
	{
		MapPair<K,T>* nextPair = nullptr;
		for ( MapPair<K,T>* pair = &_data[i] ; pair ; pair = nextPair )
		{
			nextPair = pair->next;
			if ( pair->used )
			{
				pair->used = false;
				pair->value = _defaultValue;
				--_size;
			}
		}
	}

	assert( _size == 0 );
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE T& Map<K,T,F,E,A>::operator[]( const K& key )
{
	if ( _size+1 >= _entryLimit )
		Grow();
	MapPair<K,T>* pair = GetPair( _data, _capacity, key );
	if ( !pair->used )
	{
		pair->used = true;
		++_size;
	}
	return pair->value;
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE const T& Map<K,T,F,E,A>::Get( const K& key ) const
{
	MapPair<K,T>* pair = GetPair( _data, _capacity, key );
	if ( !pair->used )
	{
		pair->used = true;
		++_size;
	}
	return pair->value;
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Float Map<K,T,F,E,A>::LoadFactor() const
{
	return _loadFactor;
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE UInt Map<K,T,F,E,A>::Capacity() const
{
	return _capacity;
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE UInt Map<K,T,F,E,A>::Size() const
{
	return _size;
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Bool Map<K,T,F,E,A>::IsEmpty() const
{
	return _size == 0;
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE Bool Map<K,T,F,E,A>::ContainsKey( const K& key ) const
{
	if ( _size > 0 )
	{
		UInt slot = (_hashFunc(key) & 0x7FFFFFFF) % _capacity;
		MapPair<K,T>* pair = &_data[slot];
		for ( ; pair ; pair = pair->next )
		{
			if ( pair->used && _equalFunc(pair->key,key) )
				return true;
		}
	}
	return false;
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE UInt Map<K,T,F,E,A>::Collisions() const
{
	return _collisions;
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE MapIterator<K,T> Map<K,T,F,E,A>::Begin() const
{
	return MapIterator<K,T>( _data, _capacity, 0 );
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE MapIterator<K,T> Map<K,T,F,E,A>::End() const
{
	return MapIterator<K,T>();
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE const T& Map<K,T,F,E,A>::operator[]( const K& key ) const
{
	if ( _size+1 >= _entryLimit )
		const_cast< Map<K,T,F,E,A>* >(this)->Grow();
	MapPair<K,T>* pair = GetPair( _data, _capacity, key );
	if ( !pair->used )
	{
		pair->used = true;
		++_size;
	}
	return pair->value;
}

template <class K, class T, class F, class E, class A> 
void Map<K,T,F,E,A>::Grow()
{
	UInt capacity = Map_NextInt( _capacity );
	MapPair<K,T>* data = AllocateMap( capacity );
	_collisions = 0;
	
	for ( UInt i = 0 ; i < _capacity ; ++i )
	{
		MapPair<K,T>* nextPair = nullptr;
		for ( MapPair<K,T>* pair = &_data[i] ; pair ; pair = nextPair )
		{
			nextPair = pair->next;
			if ( pair->used )
			{
				MapPair<K,T>* newPair = GetPair( data, capacity, pair->key );
				newPair->value = pair->value;
				newPair->used = true;
			}
			pair->next = nullptr;
			if ( _data+i != pair )
				_alloc.Deallocate( pair, 1 );
		}
	}

	DeallocateMap( _data, _capacity );
	_capacity = capacity;
	_data = data;
	_entryLimit = CastUInt( _capacity * _loadFactor );
}

template <class K, class T, class F, class E, class A> 
void Map<K,T,F,E,A>::RehashTo( MapPair<K,T>* data, UInt capacity ) const
{
	for ( UInt i = 0 ; i < _capacity ; ++i )
	{
		MapPair<K,T>* nextPair = nullptr;
		for ( MapPair<K,T>* pair = &_data[i] ; pair ; pair = nextPair )
		{
			nextPair = pair->next;
			if ( pair->used )
			{
				MapPair<K,T>* newPair = GetPair( data, capacity, pair->key );
				newPair->value = pair->value;
				newPair->used = true;
			}
		}
	}
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE void Map<K,T,F,E,A>::Destroy()
{
	if ( _data )
	{
		DeallocateMap( _data, _capacity );
		Defaults();
	}
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE void Map<K,T,F,E,A>::Defaults()
{
	_capacity		= 0;
	_data			= nullptr;
	_loadFactor		= 0.75f;
	_size			= 0;
	_entryLimit		= 0;
	_defaultValue	= T();
	_collisions		= 0;
	_hashFunc		= F();
}

template <class K, class T, class F, class E, class A> 
MapPair<K,T>* Map<K,T,F,E,A>::GetPair( MapPair<K,T>* data, UInt capacity, const K& key ) const
{
	UInt slot = (_hashFunc(key) & 0x7FFFFFFF) % capacity;
	MapPair<K,T>* first = &data[slot];
	MapPair<K,T>* unused = nullptr;
	
	for ( MapPair<K,T>* pair = first ; pair ; pair = pair->next )
	{
		if ( !pair->used )
			unused = pair;
		else if ( _equalFunc(pair->key,key) )
			return pair;
	}

	if ( !unused )
	{
		++_collisions;
		unused = _alloc.Allocate( 1 );
		unused->used = false;
		unused->next = first->next;
		first->next = unused;
	}
	unused->key = key;
	unused->value = _defaultValue;
	return unused;
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE MapPair<K,T>* Map<K,T,F,E,A>::AllocateMap( UInt capacity ) const
{
	return _alloc.Allocate( capacity );
}

template <class K, class T, class F, class E, class A> 
SYNKRO_INLINE void Map<K,T,F,E,A>::DeallocateMap( MapPair<K,T>* data, UInt capacity ) const
{
	for ( UInt i = 0 ; i < capacity ; ++i )
	{
		MapPair<K,T>* nextPair = nullptr;
		for ( MapPair<K,T>* pair = data[i].next ; pair ; pair = nextPair )
		{
			nextPair = pair->next;
			_alloc.Deallocate( pair, 1 );
		}
	}
	_alloc.Deallocate( data, capacity );
}

template <class K, class T, class A> 
SYNKRO_INLINE MapCI<K,T,A>::MapCI( const A& alloc ) :
	Map<K,T,HashCI<K>,EqualCI<K>,A>( alloc )
{
}
