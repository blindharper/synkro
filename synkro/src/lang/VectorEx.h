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
// Purpose: Defines thread-safe dynamic array.
//==============================================================================
#ifndef _SYNKRO_LANG_VECTOREX_
#define _SYNKRO_LANG_VECTOREX_


#include "config.h"
#include "Vector.h"
#include <internal/Mutex.h>


namespace synkro
{


namespace lang
{


// Thread-safe dynamic array of elements of type T.
template <class T, class A = Allocator<T> >
class VectorEx
{
public:
	// Creates thread-safe version of another vector.
	VectorEx( const Vector<T,A>& vector );

	// Frees all allocated resources.
	~VectorEx();

	// Sets new vector size.
	void													SetSize( UInt size, const T& value );

	// Sets new vector size. Sets all new elements to default value of type T.
	void													SetSize( UInt size );

	// Appends new element to the end of the vector.
	void													Add( const T& elem );

	// Appends a set of new element to the end of the vector.
	void													Add( const T* elems, UInt size );

	// Inserts element at the given position.
	void													Insert( UInt index, const T& elem );

	// Sets a set of elements from the specified buffer.
	void													Set( UInt start, const T* elems, UInt size );

	// Swaps elements at the specified indices.
	void													Swap( UInt first, UInt second );

	// Removes an element at the specified index.
	void													Remove( UInt index );

	// Removes an element with the specified value.
	void													Remove( const T& elem );

	// Sets vector capacity to match its actual size.
	void													TrimToSize();

	// Removes all elements from the vector.
	void													Clear();

	// Sorts elements in the vector.
	void													Sort();

	// Executes given function for each element of the vector.
	template<class F, class P>
	void													Each( F& function, const P& param );

	// Executes given function for each element of the vector.
	template<class F>
	void													Each( F& function );

	// Provides access to the element at the index.
	T&														operator[]( UInt index );

	// Provides access to the last element.
	T&														LastValue();

	// Executes given function for each element of the vector.
	template<class F, class P>
	void													Each( F& function, const P& param ) const;

	// Executes given function for each element of the vector.
	template<class F>
	void													Each( F& function ) const;

	// Provides read-only access to the element at the index.
	const T&												operator[]( UInt index ) const;

	// Provides read-only access to the last element.
	const T&												LastValue() const;

	// Searches the element in the vector in direct order.
	UInt													IndexOf( const T& elem, UInt start ) const;

	// Searches the element in the vector in direct order starting with the first one.
	UInt													IndexOf( const T& elem ) const;

	// Searches the element in the vector in reverse order.
	UInt													LastIndexOf( const T& elem, UInt start ) const;

	// Searches the element in the vector in reverse order starting with the last one.
	UInt													LastIndexOf( const T& elem ) const;

	// Returns true if the vector contains the specified element.
	Bool													Contains( const T& elem ) const;

	// Retrieves a set of elements to the specified buffer.
	void													Get( UInt start, T* elems, UInt size ) const;

	// Retrieves vector capacity.
	UInt													Capacity() const;

	// Retrieves vector size.
	UInt													Size() const;

	// Returns true if the vector has no elements.
	Bool													IsEmpty() const;

	// Returns pointer to the first element of the vector.
	T*														Begin() const;

	// Returns pointer to the last element of the vector.
	T*														Last() const;

	// Returns pointer to one beyond the last element of the vector.
	T*														End() const;

	// Returns pointer to the given element of the vector.
	T*														Get( UInt index ) const;

private:
	Vector<T,A>												_vector;
	Mutex													_mutex;
};


#include "VectorEx.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_VECTOREX_
