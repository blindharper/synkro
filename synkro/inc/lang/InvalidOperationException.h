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
// Purpose: Defines 'Invalid operation' exception.
//==============================================================================
#ifndef _SYNKRO_LANG_INVALIDOPERATIONEXCEPTION_
#define _SYNKRO_LANG_INVALIDOPERATIONEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace lang
{


/**
 * Thrown if a method call is invalid for the object's current state.
 */
class SYNKRO_API InvalidOperationException :
	public Exception
{
public:
	/**
	 * Creates exception with the specified error message.
	 * @param message Error message.
	 */
	InvalidOperationException( const String& message );

	/**
	 * Creates an exception with the default error message.
	 */
	InvalidOperationException();

	/**
	 * Retrieves formatted error message.
	 */
	String													ToString() const;

	InvalidOperationException( const InvalidOperationException& );

private:	
	InvalidOperationException& operator=( const InvalidOperationException& );
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_INVALIDOPERATIONEXCEPTION_
