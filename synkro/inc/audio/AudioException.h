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
// Purpose: Defines audio exception.
//==============================================================================
#ifndef _SYNKRO_AUDIO_AUDIOEXCEPTION_
#define _SYNKRO_AUDIO_AUDIOEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace audio
{


/**
 * Thrown if an audio system error occurs.
 */
class SYNKRO_API AudioException :
	public lang::Exception
{
public:
	/**
	 * Creates audio exception.
	 * @param message Error message.
	 * @param details Detailed error description.
	 * @param code Error code.
	 */
	AudioException( const lang::String& message, const lang::String& details, const lang::String& code );

	/**
	 * Creates audio exception.
	 * @param message Error message.
	 * @param code Error code.
	 */
	AudioException( const lang::String& message, const lang::String& code );

	/**
	 * Creates an exception.
	 * @param message Error message.
	 */
	AudioException( const lang::String& message );

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

	AudioException( const AudioException& );

private:
	lang::String											_details;
	lang::String											_code;

	AudioException& operator=( const AudioException& );
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_AUDIOEXCEPTION_
