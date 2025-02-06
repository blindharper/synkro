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
// Purpose: Defines 'Division by zero' exception.
//==============================================================================
#ifndef _SYNKRO_LANG_DIVISIONBYZEROEXCEPTION_
#define _SYNKRO_LANG_DIVISIONBYZEROEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace lang
{


/**
 * Thrown on an attempt to divide by zero.
 */
class SYNKRO_API DivisionByZeroException :
	public Exception
{
public:
	/**
	 * Creates an exception.
	 */
	DivisionByZeroException();

	/**
	 * Retrieves formatted error message.
	 */
	String													ToString() const;

	DivisionByZeroException( const DivisionByZeroException& );

private:	
	DivisionByZeroException& operator=( const DivisionByZeroException& );
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_DIVISIONBYZEROEXCEPTION_
