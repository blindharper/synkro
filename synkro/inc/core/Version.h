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
// Purpose: Defines Synkro version.
//==============================================================================
#ifndef _SYNKRO_CORE_VERSION_
#define _SYNKRO_CORE_VERSION_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace core
{


/**
 * Synkro version.
 */
class SYNKRO_API Version
{
public:
	/**
	 * Current version.
	 */
	static const Version									Current;

	/**
	 * Creates version from a 32-bit number.
	 */
	Version( UInt version );

	/**
	 * Creates default version.
	 */
	Version();

	/**
	 * Major version.
	 */
	Byte													Major;

	/**
	 * Minor version.
	 */
	Byte													Minor;

	/**
	 * Patch number.
	 */
	Byte													Patch;

	/**
	 * Retrieves formatted version.
	 */
	lang::String											ToString() const;

	/**
	* Tests two versions for compatibility.
	* @param other Version to compare to.
	* @return True for versions with same major version, false otherwise.
	*/
	Bool													IsCompatible( const Version& other ) const;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_VERSION_
