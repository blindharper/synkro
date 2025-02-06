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
// Purpose: Defines main Synkro framework object.
//==============================================================================
#ifndef _SYNKRO_CORE_ISYNKRO_
#define _SYNKRO_CORE_ISYNKRO_


#include "config.h"
#include <core/IContextEx.h>
#include <core/Iface.h>
#include <core/Language.h>
#include <core/ResourceType.h>


namespace synkro
{


namespace core
{


/**
 * Synkro object. Provides platform-specific functionality.
 * Used to configure application and create virtual environments.
 */
iface ISynkro :
	public IContextEx
{
public:
	/**
	 * Starts updating host application.
	 * @param running Reference to a 'running' flag. Set to false to exit main loop.
	 */
	virtual void											Run( const Bool& running ) = 0;

	/**
	 * Adds a task to the system task queue.
	 * @param task Task to execute.
	 */
	virtual void											Execute( Task* task ) = 0;

	/**
	 * Invokes visual configuration editor and loads the configuration into it.
	 * @param config Configuration storage.
	 * @return True if the user hit 'Run' button in the configuration editor.
	 */
	virtual Bool											Configure( IConfiguration* config ) = 0;

	/**
	 * Creates resource from given memory.
	 * @param data Data.
	 * @param size Data size, in bytes.
	 * @return Created resource.
	 * @exception Exception Supplied data do not represent a directory.
	 */
	virtual IResource*										CreateResource( const Byte* data, UInt size ) = 0;

	/**
	 * Creates a timer with the given interval.
	 * @param interval Interval at which timer events are sent to the listener, in milliseconds.
	 * @param listener Timer listener.
	 * @return Unique timer identifier.
	 */
	virtual UInt											CreateTimer( UInt interval, TimerListener* listener ) = 0;

	/**
	 * Initializes all systems according to the given configuration.
	 * @param config Configuration storage.
	 */
	virtual void											Initialize( IConfiguration* config ) = 0;

	/**
	 * Retrieves default configuration.
	 */
	virtual IConfiguration*									GetConfiguration() const = 0;

	/**
	 * Retrieves the number of the currently loaded libraries.
	 */
	virtual UInt											GetLibraryCount() const = 0;

	/**
	 * Retrieves library by index.
	 * @param index Index of the library to retrieve.
	 * @exception OutOfRangeException.
	 */
	virtual ILibrary*										GetLibrary( UInt index ) const = 0;

	/**
	 * Retrieves the total number of resources of the given type.
	 * @param type Resource type.
	 */
	virtual UInt											GetResourceCount( const ResourceType& type ) const = 0;

	/**
	 * Retrieves resource by resource type and index.
	 * @param type Resource type.
	 * @param index Index of the resource to retrieve.
	 * @exception OutOfRangeException.
	 */
	virtual IResource*										GetResource( const ResourceType& type, UInt index ) const = 0;

	/**
	 * Retrieves resource by resource identifier.
	 * @param id Unique resource identifier.
	 * @return Requested resource, if found, or nullptr otherwise.
	 */
	virtual IResource*										GetResource( UInt id ) const = 0;

	/**
	 * Retrieves the total number of factories for the given interface.
	 * @param ifaceID Interface identifier.
	 */
	virtual UInt											GetFactoryCount( const Iface& ifaceID ) const = 0;

	/**
	 * Retrieves factory by interface name and index.
	 * @param ifaceID Interface identifier.
	 * @param index Index of the factory to retrieve.
	 * @exception OutOfRangeException.
	 */
	virtual IFactory*										GetFactory( const Iface& ifaceID, UInt index ) const = 0;

	/**
	 * Retrieves factory by object type.
	 * @param ifaceID Interface identifier.
	 * @param classID Class identifier.
	 * @exception Exception.
	 */
	virtual IFactory*										GetFactory( const Iface& ifaceID, const lang::Enum& classID ) const = 0;

	/**
	 * Retrieves Synkro module handle.
	 */
	virtual Pointer											GetModule() const = 0;

	/**
	 * Retrieves current frame number.
	 */
	virtual UInt											GetFrame() const = 0;

	/**
	 * Retrieves Synkro internal time.
	 */
	virtual Double											GetTime() const = 0;

	/**
	 * Retrieves system language.
	 */
	virtual Language										GetLanguage() const = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_ISYNKRO_
