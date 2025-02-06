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
// Purpose: Defines file-not-found exception.
//==============================================================================
#ifndef _SYNKRO_IO_FILENOTFOUNDEXCEPTION_
#define _SYNKRO_IO_FILENOTFOUNDEXCEPTION_


#include "config.h"
#include <io/IoException.h>


namespace synkro
{


namespace io
{


/**
 * Thrown when trying to access file that does not exists
 * or cannot be opened for some reason.
 */
class SYNKRO_API FileNotFoundException :
	public IoException
{
public:
	/**
	 * Creates an exception.
	 * @param message Error message.
	 * @param filename Name of the file that cannot be found.
	 */
	FileNotFoundException( const lang::String& message, const lang::String& filename );

	/**
	 * Creates an exception.
	 * @param filename Name of the file that cannot be found.
	 */
	FileNotFoundException( const lang::String& filename );

	/**
	 * Retrieves the name of the file that caused the error.
	 */
	lang::String											Filename() const;

	/**
	 * Retrieves formatted error message.
	 */
	lang::String											ToString() const;

	FileNotFoundException( const FileNotFoundException& );

private:
	lang::String											_filename;

	FileNotFoundException& operator=( const FileNotFoundException& );
};


} // io


} // synkro


#endif // _SYNKRO_IO_FILENOTFOUNDEXCEPTION_
