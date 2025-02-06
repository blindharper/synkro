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
// Purpose: Defines enumeration value.
//==============================================================================
#ifndef _SYNKRO_LANG_ENUM_
#define _SYNKRO_LANG_ENUM_


#include "config.h"
#include <lang/String.h>


// Begins enumeration value declaration.
#define SYNKRO_ENUM_BEGIN( NAME )					\
	class SYNKRO_API NAME : public synkro::lang::Enum		\
	{ public: NAME( UInt value = 0) : Enum( value ) {} 

// Declares enumeration constant.
#define SYNKRO_ENUM_CONST( NAME, CONST ) \
	static const NAME CONST;

// Ends enumeration value declaration.
#define SYNKRO_ENUM_END()	\
	};


namespace synkro
{


namespace lang
{


/**
 * Enumeration value.
 */
class SYNKRO_API Enum
{
public:
	/**
	 * Creates a constant with the specified value.
	 * @param value Constant value.
	 */
	Enum( UInt value );

	/**
	 * Creates a constant with default value.
	 */
	Enum();

	/**
	 * Tests two enumeration constants for equality.
	 * @param other Constant to compare to.
	 * @return True if the constants are equal, false otherwise.
	 */
	Bool													operator==( const Enum& other ) const;

	/**
	 * Tests two enumeration constants for inequality.
	 * @param other Constant to compare to.
	 * @return True if the constants are unequal, false otherwise.
	 */
	Bool													operator!=( const Enum& other ) const;

	/**
	 * Calculates enumeration value hash code.
	 */
	Int														HashCode() const;

	/**
	 * Gets enumeration constant value.
	 */
	UInt													Value() const;

	/**
	 * Casts enum to numeric value.
	 */
															operator UInt() const;

	/**
	 * Calculates numeric value for the given enumeration constant.
	 * @param type Enumeration type name.
	 * @param value String representation of an enumeration constant.
	 * @return Enumeration constant value.
	 */
	static UInt												GetValue( const String& type, const String& value );

protected:
	UInt													_value;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_ENUM_
