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
// Purpose: Defines graphics system exception.
//==============================================================================
#ifndef _SYNKRO_GFX_GRAPHICSEXCEPTION_
#define _SYNKRO_GFX_GRAPHICSEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace gfx
{


/**
 * Thrown when a graphics system error occurs.
 */
class SYNKRO_API GraphicsException :
	public lang::Exception
{
public:
	/**
	 * Creates graphics exception.
	 * @param message Error message.
	 * @param details Detailed error description.
	 * @param code Error code.
	 */
	GraphicsException( const lang::String& message, const lang::String& details, const lang::String& code );

	/**
	 * Creates graphics exception.
	 * @param message Error message.
	 * @param code Error code.
	 */
	GraphicsException( const lang::String& message, const lang::String& code );

	/**
	 * Creates graphics exception.
	 * @param message Error message.
	 */
	GraphicsException( const lang::String& message );

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

	GraphicsException( const GraphicsException& );

private:
	lang::String											_details;
	lang::String											_code;

	GraphicsException& operator=( const GraphicsException& );
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_GRAPHICSEXCEPTION_
