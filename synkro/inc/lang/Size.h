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
// Purpose: Defines whole number size.
//==============================================================================
#ifndef _SYNKRO_LANG_SIZE_
#define _SYNKRO_LANG_SIZE_


#include "config.h"


namespace synkro
{


namespace lang
{


/**
 * Whole number size.
 */
class SYNKRO_API Size
{
public:
	// Size dimensions.
	UInt Width, Height;

	/**
	 * Constructs a size with the given dimensions.
	 * @param width Width.
	 * @param height Height.
	 */
	Size( UInt width, UInt height ) SYNKRO_NOEXCEPT;

	/**
	 * Copy constructor.
	 */
	Size( const Size& other ) SYNKRO_NOEXCEPT;

	/**
	 * Constructs an empty size.
	 */
	Size() SYNKRO_NOEXCEPT;

	/**
	 * Sets size dimensions.
	 * @param width Horizontal dimension.
	 * @param height Vertical dimension.
	 */
	Size&													Set( UInt width, UInt height ) SYNKRO_NOEXCEPT;

	/**
	 * Copy by reference.
	 */
	Size&													operator=( const Size& other ) SYNKRO_NOEXCEPT;

	/**
	 * Tests two sizes for equality.
	 * @param other Size to compare to.
	 * @return True for equal sizes, false otherwise.
	 */
	Bool													operator==( const Size& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Tests two sizes for inequality.
	 * @param other Size to compare to.
	 * @return True for unequal sizes, false otherwise.
	 */
	Bool													operator!=( const Size& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Indicates if either width or height is zero.
	 */
	Bool													IsEmpty() const SYNKRO_NOEXCEPT;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_SIZE_
