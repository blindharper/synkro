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
// Purpose: Defines range object.
//==============================================================================
#ifndef _SYNKRO_LANG_RANGE_
#define _SYNKRO_LANG_RANGE_


#include "config.h"


namespace synkro
{


namespace lang
{


/**
 * Range object.
 */
class SYNKRO_API Range
{
public:
	// Range value.
	UInt Start, Length;

	/**
	 * Constructs a range with the given properties.
	 * @param start Starting index of the range.
	 * @param length Range length.
	 */
	Range( UInt start, UInt length );

	/**
	 * Constructs a range with starting index of zero.
	 * @param length Range length.
	 */
	Range( UInt length );

	/**
	 * Copy constructor.
	 */
	Range( const Range& other );

	/**
	 * Constructs an empty range.
	 */
	Range();

	/**
	 * Sets range properties.
	 * @param start Starting index of the range.
	 * @param length Range length.
	 */
	Range&													Set( UInt start, UInt length );

	/**
	 * Copy by reference.
	 */
	Range&													operator=( const Range& other );

	/**
	 * Tests two ranges for equality.
	 * @param other Range to compare to.
	 * @return True for equal ranges, false otherwise.
	 */
	Bool													operator==( const Range& other ) const;

	/**
	 * Tests two ranges for inequality.
	 * @param other Range to compare to.
	 * @return True for unequal ranges, false otherwise.
	 */
	Bool													operator!=( const Range& other ) const;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_RANGE_
