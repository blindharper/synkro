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
// Purpose: Defines pseudo-random number generator.
//==============================================================================
#ifndef _SYNKRO_LANG_RANDOM_
#define _SYNKRO_LANG_RANDOM_


#include "config.h"


namespace synkro
{


namespace lang
{


/**
 * Pseudo-random number generator.
 */
class SYNKRO_API Random
{
public:
	/**
	 * Creates a new generator.
	 * @param seed Random starting point.
	 */
	Random( UInt seed );

	/**
	 * Creates a new generator.
	 */
	Random();

	/**
	 * Generates a whole number in the given range.
	 * @param minValue Lower limit of the number to generate.
	 * @param maxValue Upper limit of the number to generate.
	 * @return Generated number.
	 */
	Int														GetInt( Int minValue, Int maxValue );

	/**
	 * Generates a whole number in the given range.
	 * @param maxValue Upper limit of the number to generate.
	 * @return Generated number.
	 */
	Int														GetInt( Int maxValue );

	/**
	 * Generates a whole number.
	 * @return Generated number.
	 */
	Int														GetInt();

	/**
	 * Generates a boolean value.
	 * @return Generated value.
	 */
	Bool													GetBool();

	/**
	 * Generates a floating-point number in the range [0.0, 1.0].
	 * @return Generated number.
	 */
	Float													GetFloat();

	/**
	 * Generates a double precision floating-point number in the range [0.0, 1.0].
	 * @return Generated number.
	 */
	Double													GetDouble();

	/**
	 * Generates an array of bytes.
	 * @param count Total number of bytes to generate.
	 * @param [out] value Array to fill with random numbers.
	 */
	void													GetBytes( UInt count, Byte* value );

private:
	UInt													_seed;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_RANDOM_
