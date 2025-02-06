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
// Purpose: Defines linked list.
//==============================================================================
#ifndef _SYNKRO_LANG_LIST_
#define _SYNKRO_LANG_LIST_


#include "config.h"
#include "Allocator.h"
#include "ListIterator.h"


namespace synkro
{


namespace lang
{


// Double-linked list of elements of type T.
template <class T, class A = Allocator<ListItem<T> > >
class List
{
public:
	// Constructs an empty list.
	explicit List( const A& alloc );

	// Creates a copy of another list.
	List( const List<T,A>& other );

	// Frees all allocated resources.
	~List();

	// Creates a copy of another list.
	List<T,A>&												operator=( const List<T,A>& other );

	// Searches list for the given element starting at the specified position.
	ListIterator<T>											Find( const T& elem, const ListIterator<T>& it );

	// Searches list for the given element starting at the beginning.
	ListIterator<T>											Find( const T& elem );

	// Searches list for the last occurence of given element starting at the specified position.
	ListIterator<T>											FindLast( const T& elem, const ListIterator<T>& it );

	// Searches list for the last occurence of given element starting at the end.
	ListIterator<T>											FindLast( const T& elem );

	// Inserts element into the list at the specified position.
	ListIterator<T>											Insert( const T& elem, const ListIterator<T>& it );

	// Inserts element into the list at the beginning.
	ListIterator<T>											Insert( const T& elem );

	// Appends element to the end of the list.
	ListIterator<T>											Add( const T& elem );

	// Removes element from the list.
	Bool													Remove( const ListIterator<T>& it );

	// Removes element from the list.
	Bool													Remove( const T& elem );
	
	// Removes all elements from the list.
	void													Clear();

	// Sorts elements in the list.
	void													Sort();

	// Retrieves iterator to the start of the list.
	ListIterator<T>											Begin();

	// Retrieves constant iterator to the start of the list.
	const ListIterator<T>									Begin() const;

	// Retrieves iterator to the end of the list.
	ListIterator<T>											End();

	// Retrieves constant iterator to the end of the list.
	const ListIterator<T>									End() const;

	// Returns the number of elements in the list.
	UInt													Size() const;

	// Returns true if the list has no elements.
	Bool													IsEmpty() const;

private:
	ListItem<T>*											_begin;
	ListItem<T>*											_end;
	A														_alloc;
	UInt													_size;
	
	void													Copy( const List<T,A>& other );
};


#include "List.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_LIST_
