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
// Purpose: Defines version exception.
//==============================================================================
#ifndef _SYNKRO_CORE_VERSIONEXCEPTION_
#define _SYNKRO_CORE_VERSIONEXCEPTION_


#include "config.h"
#include <lang/Exception.h>
#include <core/Version.h>


namespace synkro
{


namespace core
{


/**
 * Thrown if any version incompatibility is detected.
 */
class SYNKRO_API VersionException :
	public lang::Exception
{
public:
	/**
	 * Creates version exception.
	 * @param version Synkro version supplied by host application.
	 */
	VersionException( const Version& version );

	/**
	 * Retrieves supplied Synkro version.
	 */
	core::Version											Version() const;

	/**
	 * Retrieves formatted error message.
	 */
	lang::String											ToString() const;

	VersionException( const VersionException& );

private:
	core::Version											_version;
	
	VersionException& operator=( const VersionException& );
};


} // core


} // synkro


#endif // _SYNKRO_CORE_VERSIONEXCEPTION_
