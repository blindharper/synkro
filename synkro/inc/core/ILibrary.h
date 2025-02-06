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
// Purpose: Defines Synkro library.
//==============================================================================
#ifndef _SYNKRO_CORE_ILIBRARY_
#define _SYNKRO_CORE_ILIBRARY_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace core
{


/**
 * Synkro library.
 */
iface ILibrary :
	public IObject
{
public:
	/**
	 * Returns true for profiling libraries.
	 */
	virtual Bool											IsPerf() const = 0;

	/**
	 * Returns true for debug libraries.
	 */
	virtual Bool											IsDebug() const = 0;

	/**
	 * Returns true for object libraries.
	 */
	virtual Bool											IsObject() const = 0;

	/**
	 * Returns true for string libraries.
	 */
	virtual Bool											IsString() const = 0;

	/**
	 * Returns true for resource libraries.
	 */
	virtual Bool											IsResource() const = 0;

	/**
	 * Retrieves library name.
	 */
	virtual const Char*										GetName() const = 0;

	/**
	 * Retrieves library description.
	 */
	virtual const Char*										GetDescription() const = 0;

	/**
	 * Retrieves library author.
	 */
	virtual const Char*										GetAuthor() const = 0;

	/**
	 * Retrieves library copyright notice.
	 */
	virtual const Char*										GetCopyright() const = 0;

	/**
	 * Retrieves library comment.
	 */
	virtual const Char*										GetComment() const = 0;

	/**
	 * Retrieves library language.
	 */
	virtual const Char*										GetLanguage() const = 0;

	/**
	 * Retrieves Synkro core version at the time library was built.
	 */
	virtual UInt											GetCoreVersion() const = 0;

	/**
	 * Retrieves library version.
	 */
	virtual UInt											GetVersion() const = 0;

	/**
	 * Retrieves the total number of resources the library contains.
	 */
	virtual UInt											GetResourceCount() const = 0;

	/**
	 * Retrieves resource by index.
	 */
	virtual IResource*										GetResource( UInt index ) const = 0;

	/**
	 * Retrieves the total number of factories the library contains.
	 */
	virtual UInt											GetFactoryCount() const = 0;

	/**
	 * Retrieves factory by index.
	 */
	virtual IFactory*										GetFactory( UInt index ) const = 0;

	/**
	 * Retrieves the total number of string resources in the library.
	 */
	virtual UInt											GetStringCount() const = 0;

	/**
	 * Retrieves string resource name by index.
	 */
	virtual const Char*										GetStringName( UInt index ) const = 0;

	/**
	 * Retrieves string resource value by index.
	 */
	virtual const Char*										GetStringValue( UInt index ) const = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_ILIBRARY_
