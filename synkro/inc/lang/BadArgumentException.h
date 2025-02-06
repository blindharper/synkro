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
// Purpose: Defines 'Bad argument' exception.
//==============================================================================
#ifndef _SYNKRO_LANG_BADARGUMENTEXCEPTION_
#define _SYNKRO_LANG_BADARGUMENTEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace lang
{


/**
 * Thrown if an invalid method argument is supplied.
 */
class SYNKRO_API BadArgumentException :
	public Exception
{
public:
	/**
	 * Creates exception with the specified attributes.
	 * @param message Error message.
	 * @param argument Argument name.
	 * @param value Argument value.
	 */
	BadArgumentException( const String& message, const String& argument, const String& value );

	/**
	 * Creates exception with the specified attributes.
	 * @param message Error message.
	 * @param argument Argument name.
	 */
	BadArgumentException( const String& message, const String& argument );

	/**
	 * Creates an exception with the default error message.
	 */
	BadArgumentException();

	/**
	 * Retrieves argument name.
	 */
	String													Argument() const;

	/**
	 * Retrieves argument value.
	 */
	String													Value() const;

	/**
	 * Retrieves formatted error message.
	 */
	String													ToString() const;

	BadArgumentException( const BadArgumentException& );

private:
	String													_argument;
	String													_value;
	
	BadArgumentException& operator=( const BadArgumentException& );
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_BADARGUMENTEXCEPTION_
