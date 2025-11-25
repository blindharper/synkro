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
// Purpose: Defines smart pointer to an object.
//==============================================================================
#ifndef _SYNKRO_LANG_PTR_
#define _SYNKRO_LANG_PTR_


#include "config.h"
#include <lang/NullReferenceException.h>


/**
 * Abbreviated smart pointer.
 */
#define P( X ) synkro::lang::Ptr< X >


namespace synkro
{


namespace lang
{


/**
 * Smart pointer to an object of class T.
 * Type T should implement at least AddRef() and Release() methods.
 */
template <class T>
class Ptr
{
public:
	/**
	 * Increments object reference count and stores the reference.
	 * @param other Object to create pointer on.
	 */
	Ptr( T* other ) SYNKRO_NOEXCEPT;

	/**
	 * Increments object reference count and stores the reference.
	 * @param other Object to create pointer on.
	 */
	Ptr( const Ptr<T>& other ) SYNKRO_NOEXCEPT;

	/**
	 * Creates null pointer.
	 */
	Ptr() SYNKRO_NOEXCEPT;

	/**
	 * Releases the object.
	 */
	~Ptr();

	/**
	 * Releases reference to the old object and stores the reference to the new object.
	 * @param other Object to create pointer on.
	 */
	Ptr&													operator=( T* other ) SYNKRO_NOEXCEPT;

	/**
	 * Releases reference to the old object and stores the reference to the new object.
	 * @param other Object to create pointer on.
	 */
	Ptr&													operator=( const Ptr<T>& other ) SYNKRO_NOEXCEPT;

	/**
	 * Tests two pointers for equality.
	 * @param other Pointer to compare to.
	 * @return True if the references point to the same unique object, false otherwise.
	 */
	Bool													operator==( T* other ) const SYNKRO_NOEXCEPT;

	/**
	 * Tests two pointers for equality.
	 * @param other Pointer to compare to.
	 * @return True if the references point to the same unique object, false otherwise.
	 */
	Bool													operator==( const Ptr<T>& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Tests two pointers for inequality.
	 * @param other Pointer to compare to.
	 * @return True if the references point to different unique objects, false otherwise.
	 */
	Bool													operator!=( T* other ) const SYNKRO_NOEXCEPT;

	/**
	 * Tests two pointers for inequality.
	 * @param other Pointer to compare to.
	 * @return True if the references point to different unique objects, false otherwise.
	 */
	Bool													operator!=( const Ptr<T>& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Provides access to the object.
	 */
	T&														operator*() const;

	/**
	 * Provides access to the object.
	 */
	T*														operator->() const;

	/**
	 * Provides access to the object.
	 */
															operator T*() const SYNKRO_NOEXCEPT;

	/**
	 * Provides access to the object.
	 */
	T*														AsPtr() const SYNKRO_NOEXCEPT;

private:
	T*														_object;
};


#include "Ptr.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_PTR_
