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
// Purpose: Defines input system exception.
//==============================================================================
#ifndef _SYNKRO_INPUT_INPUTEXCEPTION_
#define _SYNKRO_INPUT_INPUTEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace input
{


/**
 * Thrown when an input system error occurs.
 */
class SYNKRO_API InputException :
	public lang::Exception
{
public:
	/**
	 * Creates input exception.
	 * @param message Error message.
	 * @param details Detailed error description.
	 * @param code Error code.
	 */
	InputException( const lang::String& message, const lang::String& details, const lang::String& code );

	/**
	 * Creates input exception.
	 * @param message Error message.
	 * @param code Error code.
	 */
	InputException( const lang::String& message, const lang::String& code );

	/**
	 * Creates input exception.
	 * @param message Error message.
	 */
	InputException( const lang::String& message );

	/**
	 * Retrieves detailed error description.
	 */
	lang::String											Details() const;

	/**
	 * Retrieves error code.
	 */
	lang::String											Code() const;

	/**
	 * Retrieves formatted error message.
	 */
	lang::String											ToString() const;

	InputException( const InputException& );

private:
	lang::String											_details;
	lang::String											_code;

	InputException& operator=( const InputException& );
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_INPUTEXCEPTION_
