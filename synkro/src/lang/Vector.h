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
// Purpose: Defines dynamic array.
//==============================================================================
#ifndef _SYNKRO_LANG_VECTOR_
#define _SYNKRO_LANG_VECTOR_


#include "config.h"
#include "Allocator.h"
#include <internal/Sort.h>


namespace synkro
{


namespace lang
{


// Dynamic array of elements of type T.
template <class T, class A = Allocator<T> >
class Vector
{
public:
	// Constructs a vector from an array of elements.
	explicit Vector( const T* elems, UInt size, const A& alloc );

	// Constructs an empty vector with the given capacity.
	explicit Vector( const A& alloc, UInt capacity );

	// Constructs an empty vector.
	explicit Vector( const A& alloc );

	// Creates a copy of another vector.
	Vector( const Vector<T,A>& other );

	// Frees all allocated resources.
	~Vector();

	// Creates a copy of another vector.
	Vector<T,A>&											operator=( const Vector<T,A>& other );

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
	T*														_data;
	A														_alloc;
	UInt													_capacity;
	UInt													_size;

	void													Destroy();
	static void												Copy( T* dst, const T* src, UInt count );
	static UInt												GetCapacity( UInt size );
};


#include "Vector.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_VECTOR_
