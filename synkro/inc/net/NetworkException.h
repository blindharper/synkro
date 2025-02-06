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
// Purpose: Defines network system exception.
//==============================================================================
#ifndef _SYNKRO_NET_NETWORKEXCEPTION_
#define _SYNKRO_NET_NETWORKEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace net
{


/**
 * Thrown when an network system error occurs.
 */
class SYNKRO_API NetworkException :
	public lang::Exception
{
public:
	/**
	 * Creates network exception.
	 * @param message Error message.
	 * @param details Detailed error description.
	 * @param code Error code.
	 */
	NetworkException( const lang::String& message, const lang::String& details, const lang::String& code );

	/**
	 * Creates network exception.
	 * @param message Error message.
	 * @param code Error code.
	 */
	NetworkException( const lang::String& message, const lang::String& code );

	/**
	 * Creates network exception.
	 * @param message Error message.
	 */
	NetworkException( const lang::String& message );

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

	NetworkException( const NetworkException& );

private:
	lang::String											_details;
	lang::String											_code;

	NetworkException& operator=( const NetworkException& );
};


} // net


} // synkro


#endif // _SYNKRO_NET_NETWORKEXCEPTION_
