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
// Purpose: Defines memory allocator for objects of type T.
//==============================================================================
template <class T>
SYNKRO_INLINE Allocator<T>::Allocator( const char* name, UInt index ) :
	_name( name ),
	_index( index )
{
	assert( _name != 0 );
}

template <class T>
SYNKRO_INLINE Allocator<T>::Allocator( const char* name ) :
	_name( name ),
	_index( 0 )
{
	assert( _name != 0 );
}

template <class T>
SYNKRO_INLINE Allocator<T>::Allocator( const Allocator<T>& other ) :
	_name( other._name ),
	_index( other._index )
{
}

template <class T>
SYNKRO_INLINE Allocator<T>& Allocator<T>::operator=( const Allocator<T>& other )
{
	_name = other._name;
	_index = other._index;
	return *this;
}

template <class T>
SYNKRO_INLINE T* Allocator<T>::Allocate( UInt count )
{
	void* memory = mem::MemoryManager::Allocate( sizeof(T)*count, _name, _index );
	T* item0 = reinterpret_cast<T*>( memory );
	Int i = 0;
	Int c = count;

	try
	{
		T* item = item0; 
		for ( ; i < c ; ++i ) 
		{
			void* itemmem = item;

#	undef new
#	define new new

			::new( itemmem ) T;

#	undef new
#	define new SYNKRO_NEW

			++item;
		} 
		return item0;
	}
	catch ( ... )
	{
		--i;
		T* item = item0 + i;
		for ( ; i >= 0; --i ) 
		{
			item->~T();
			--item;
		}
		mem::MemoryManager::Free( memory, sizeof(T)*count );
		throw;
	}
}

template <class T>
SYNKRO_INLINE T* Allocator<T>::Allocate()
{
	return Allocate( 1 );
}

template <class T>
SYNKRO_INLINE void Allocator<T>::Deallocate( T* ptr, UInt count )
{
	void* m = ptr;
	ptr += count-1;
	for ( UInt i = 0; i < count; ++i ) 
	{
		ptr->~T(); 
		--ptr;
	}
	mem::MemoryManager::Free( m, sizeof(T)*count );
}

template <class T>
SYNKRO_INLINE void Allocator<T>::Deallocate( T* ptr )
{
	Deallocate( ptr, 1 );
}

template <class T>
SYNKRO_INLINE T* Allocator<T>::Construct( void* ptr, const T& value )
{
#	undef new
#	define new new

	return ::new( ptr ) T( value );

#	undef new
#	define new SYNKRO_NEW
}
    
template <class T>
SYNKRO_INLINE void Allocator<T>::Destroy( T* ptr )
{
	ptr->~T(); 
	ptr = 0;
}

template <class T>
SYNKRO_INLINE const char* Allocator<T>::Name() const
{
	return _name;
}

template <class T>
SYNKRO_INLINE UInt Allocator<T>::Index() const
{
	return _index;
}
