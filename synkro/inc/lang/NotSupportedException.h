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
// Purpose: Defines 'Not supported' exception.
//==============================================================================
#ifndef _SYNKRO_LANG_NOTSUPPORTEDEXCEPTION_
#define _SYNKRO_LANG_NOTSUPPORTEDEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace lang
{


/**
 * Thrown if an invoked method is not supported.
 */
class SYNKRO_API NotSupportedException :
	public Exception
{
public:
	/**
	 * Creates exception with the specified error message.
	 * @param message Error message.
	 */
	NotSupportedException( const String& message );

	/**
	 * Creates an exception with the default error message.
	 */
	NotSupportedException();

	/**
	 * Retrieves formatted error message.
	 */
	String													ToString() const;

	NotSupportedException( const NotSupportedException& );

private:	
	NotSupportedException& operator=( const NotSupportedException& );
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_NOTSUPPORTEDEXCEPTION_
