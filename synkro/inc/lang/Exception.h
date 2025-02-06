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
// Purpose: Defines base exception.
//==============================================================================
#ifndef _SYNKRO_LANG_EXCEPTION_
#define _SYNKRO_LANG_EXCEPTION_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace lang
{


/**
 * Base class for all errors application may want to handle.
 */
class SYNKRO_API Exception
{
public:
	/**
	 * Creates exception with the given error message.
	 * @param message Error message.
	 */
	Exception( const String& message );

	/**
	 * Creates an exception with default error message.
	 */
	Exception();

	/**
	 * Destroys exception object.
	 */
	virtual ~Exception();

	/**
	 * Displays error dialog.
	 */
	virtual void											Show() const;

	/**
	 * Retrieves stack trace.
	 */
	String													Stack() const;

	/**
	 * Retrieves error message.
	 */
	virtual String											Message() const;

	/**
	 * Retrieves formatted error message.
	 */
	virtual String											ToString() const;

	Exception( const Exception& );

protected:
	String													_message;

private:	
	Exception& operator=( const Exception& );
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_EXCEPTION_
