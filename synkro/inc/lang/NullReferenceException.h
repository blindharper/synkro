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
// Purpose: Defines 'Null reference' exception.
//==============================================================================
#ifndef _SYNKRO_LANG_NULLREFERENCEEXCEPTION_
#define _SYNKRO_LANG_NULLREFERENCEEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace lang
{


/**
 * Thrown on an attempt to access null object.
 */
class SYNKRO_API NullReferenceException :
	public Exception
{
public:
	/**
	 * Creates exception with the specified arguments.
	 * @param file File where null pointer is defined.
	 * @param line Line number where null pointer is defined.
	 */
	NullReferenceException( const String& file, UInt line );

	/**
	 * Retrieves formatted error message.
	 */
	String													ToString() const;

	NullReferenceException( const NullReferenceException& );

private:	
	NullReferenceException& operator=( const NullReferenceException& );
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_NULLREFERENCEEXCEPTION_
