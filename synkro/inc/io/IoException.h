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
// Purpose: Defines input/output exception.
//==============================================================================
#ifndef _SYNKRO_IO_IOEXCEPTION_
#define _SYNKRO_IO_IOEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace io
{


/**
 * Thrown if an input/output operation fails.
 */
class SYNKRO_API IoException :
	public lang::Exception
{
public:
	/**
	* Creates exception with the specified error message.
	* @param message Error message.
	*/
	IoException( const lang::String& message );

	/**
	 * Creates an exception with the default error message.
	 */
	IoException();

	/**
	 * Retrieves formatted error message.
	 */
	lang::String											ToString() const;

	IoException( const IoException& );

private:	
	IoException& operator=( const IoException& );
};


} // io


} // synkro


#endif // _SYNKRO_IO_IOEXCEPTION_
