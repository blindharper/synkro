//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is encouraged without any permission from the Synkro Project.
// Website: https://synkro.org Email: mailto:blindharper70@gmail.com
//
// Purpose: Defines memory allocator for objects of type T.
//==============================================================================
template <class T>
SYNKRO_INLINE Allocator<T>::Allocator( const char* name )
{
	assert( name != nullptr );

	_name = name;
}

template <class T>
SYNKRO_INLINE Allocator<T>::Allocator( const Allocator<T>& other )
{
	_name = other._name;
}

template <class T>
SYNKRO_INLINE Allocator<T>& Allocator<T>::operator=( const Allocator<T>& other )
{
	_name = other._name;
	return *this;
}

template <class T>
SYNKRO_INLINE T* Allocator<T>::Allocate( UInt n )
{
	void* memory = malloc( sizeof(T)*n );
	T* item0 = reinterpret_cast<T*>( memory );
	Long i = 0;
	Long c = n;

	try
	{
		T* item = item0; 
		for ( ; i < c ; ++i ) 
		{
			void* itemmem = item;

#	undef new
#	define new new

			::new( itemmem ) T;
			++item;
		} 
		return item0;
	}
	catch ( ... )
	{
		--i;
		T* item = item0 + i;
		for ( ; i >= 0 ; --i ) 
		{
			item->~T();
			--item;
		}
		free( memory );
		throw;
	}
}

template <class T>
SYNKRO_INLINE T* Allocator<T>::Allocate()
{
	return Allocate( 1 );
}

template <class T>
SYNKRO_INLINE void Allocator<T>::Deallocate( T* p, UInt n )
{
	void* m = p;
	p += n-1;
	for ( UInt i = 0 ; i < n ; ++i ) 
	{
		p->~T(); 
		--p;
	}
	free( m );
}

template <class T>
SYNKRO_INLINE void Allocator<T>::Deallocate( T* p )
{
	Deallocate( p, 1 );
}

template <class T>
SYNKRO_INLINE T* Allocator<T>::Construct( void* p, const T& v )
{
#	undef new
#	define new new

	return ::new( p ) T( v );
}
    
template <class T>
SYNKRO_INLINE void Allocator<T>::Destroy( T* p )
{
	p->~T(); 
	p = p;
}

template <class T>
SYNKRO_INLINE const char* Allocator<T>::Name() const
{
	return _name;
}
