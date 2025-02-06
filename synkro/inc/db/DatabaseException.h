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
// Purpose: Defines database exception.
//==============================================================================
#ifndef _SYNKRO_DB_DATABASEEXCEPTION_
#define _SYNKRO_DB_DATABASEEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace db
{


/**
 * Thrown when database system encounters a syntax error or another problem.
 */
class SYNKRO_API DatabaseException :
	public lang::Exception
{
public:
	/**
	 * Creates an exception.
	 * @param message Error message.
	 * @param query Database system query.
	 * @param code Error code.
	 */
	DatabaseException( const lang::String& message, const lang::String& query, const lang::String& code );

	/**
	 * Creates an exception.
	 * @param message Error message.
	 * @param code Error code.
	 */
	DatabaseException( const lang::String& message, const lang::String& code );

	/**
	 * Creates an exception.
	 * @param query Database system query.
	 */
	DatabaseException( const lang::String& query );

	/**
	 * Retrieves database query that caused the exception.
	 */
	lang::String											Query() const;

	/**
	 * Retrieves error code.
	 */
	lang::String											Code() const;

	/**
	 * Retrieves formatted error message.
	 */
	lang::String											ToString() const;

	DatabaseException( const DatabaseException& );

private:
	lang::String											_query;
	lang::String											_code;
	
	DatabaseException& operator=( const DatabaseException& );
};


} // db


} // synkro


#endif // _SYNKRO_DB_DATABASEEXCEPTION_
