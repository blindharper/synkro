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
// Purpose: Defines stack.
//==============================================================================
#ifndef _SYNKRO_LANG_STACK_
#define _SYNKRO_LANG_STACK_


#include "config.h"
#include "Allocator.h"
#include "StackOverflowException.h"
#include "StackUnderflowException.h"


namespace synkro
{


namespace lang
{


// Stack of elements of type T.
template <class T, class A = Allocator<T> >
class Stack
{
public:
	enum
	{
		// Default stack capacity.
		DEFAULT_CAPACITY = 64,
	};

	// Constructs an empty stack of the given capacity.
	explicit Stack( const A& alloc, UInt capacity );

	// Constructs an empty stack of default capacity.
	explicit Stack( const A& alloc );

	// Creates a copy of another stack.
	Stack( const Stack<T,A>& other );

	// Frees all allocated resources.
	~Stack();

	// Creates a copy of another stack.
	Stack<T,A>&												operator=( const Stack<T,A>& other );

	// Places the element to the top of the stack.
	void													Push( const T& elem );

	// Removes all elements from the stack.
	void													Clear();

	// Removes top element off the stack.
	void													Pop();

	// Retrieves reference to the top of the stack.
	T&														Top();

	// Retrieves constant reference to the top of the stack.
	const T&												Top() const;

	// Returns the number of elements in the stack.
	UInt													Size() const;

	// Returns stack capacity.
	UInt													Capacity() const;

private:
	T*														_data;
	A														_alloc;
	Int														_index;
	Int														_capacity;
	
	void													Init();
	void													Uninit();
	void													Copy( const Stack<T,A>& other );
};


#include "Stack.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_STACK_
