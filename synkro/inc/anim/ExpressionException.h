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
// Purpose: Defines expression exception.
//==============================================================================
#ifndef _SYNKRO_ANIM_EXPRESSIONEXCEPTION_
#define _SYNKRO_ANIM_EXPRESSIONEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace anim
{


/**
 * Thrown when there is a syntax error in an expression.
 */
class SYNKRO_API ExpressionException :
	public lang::Exception
{
public:
	/**
	 * Creates an exception.
	 * @param message Error message.
	 */
	ExpressionException( const lang::String& message, UInt line, UInt symbol );

	/**
	 * Retrieves line number in which the error occured.
	 */
	UInt													Line() const;

	/**
	 * Retrieves position within the erroneous line at which the error occured.
	 */
	UInt													Symbol() const;

	/**
	 * Retrieves formatted error message.
	 */
	lang::String											ToString() const;

	ExpressionException( const ExpressionException& );

private:
	UInt													_line;
	UInt													_symbol;

	ExpressionException& operator=( const ExpressionException& );
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_EXPRESSIONEXCEPTION_
