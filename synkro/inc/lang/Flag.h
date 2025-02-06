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
// Purpose: Defines bit flag set.
//==============================================================================
#ifndef _SYNKRO_LANG_FLAG_
#define _SYNKRO_LANG_FLAG_


#include "config.h"
#include <lang/Enum.h>


// Begins enumeration value declaration.
#define SYNKRO_FLAG_BEGIN( NAME )					\
	class SYNKRO_API NAME : public synkro::lang::Flag		\
	{ public: NAME( UInt value = 0) : Flag( value ) {} \
	SYNKRO_INLINE NAME& operator|=( const NAME& flag ) { _value |= flag._value; return *this; } \
	SYNKRO_INLINE const NAME operator|( const NAME& flag ) const { return NAME( _value | flag._value ); }

// Declares enumeration constant.
#define SYNKRO_FLAG_CONST( NAME, CONST ) \
	static const NAME CONST;

// Ends enumeration value declaration.
#define SYNKRO_FLAG_END()	\
	};


namespace synkro
{


namespace lang
{


/**
 * Bit flag set.
 */
class SYNKRO_API Flag :
	public Enum
{
public:
	/**
	 * Creates a constant with the specified value.
	 * @param value Constant value.
	 */
	Flag( UInt value );

	/**
	 * Sets the specified bit flag.
	 * @param flag Flag to set.
	 */
	void													Set( const Flag& flag );

	/**
	 * Resets the specified bit flag.
	 * @param flag Flag to reset.
	 */
	void													Reset( const Flag& flag );

	/**
	 * Tests if the specified bit flag is set.
	 * @param flag Flag to test.
	 * @return True if the flag is set, false otherwise.
	 */
	Bool													IsSet( const Flag& flag ) const;

	/**
	 * Tests if the specified bit flag is not set.
	 * @param flag Flag to test.
	 * @return True if the flag is not set, false otherwise.
	 */
	Bool													IsNotSet( const Flag& flag ) const;

	/**
	 * Returns the number of set bits.
	 * @return The number of set bits.
	 */
	UInt													Bits() const;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_FLAG_
