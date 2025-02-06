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
// Purpose: Defines 'Out of range' exception.
//==============================================================================
#ifndef _SYNKRO_LANG_OUTOFRANGEEXCEPTION_
#define _SYNKRO_LANG_OUTOFRANGEEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace lang
{


/**
 * Thrown if an index is out of range.
 */
class SYNKRO_API OutOfRangeException :
	public Exception
{
public:
	/**
	 * Creates exception with the specified attributes.
	 * @param index Actual index value.
	 * @param maximum Maximum allowed index value.
	 */
	OutOfRangeException( UInt index, UInt maximum );

	/**
	 * Retrieves actual index value.
	 */
	UInt													Index() const;

	/**
	 * Retrieves maximum allowed value.
	 */
	UInt													Maximum() const;

	/**
	 * Retrieves formatted error message.
	 */
	String													ToString() const;

	OutOfRangeException( const OutOfRangeException& );

private:
	UInt													_index;
	UInt													_maximum;
	
	OutOfRangeException& operator=( const OutOfRangeException& );
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_OUTOFRANGEEXCEPTION_
