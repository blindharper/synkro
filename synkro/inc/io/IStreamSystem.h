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
// Purpose: Defines stream system.
//==============================================================================
#ifndef _SYNKRO_IO_ISTREAMSYSTEM_
#define _SYNKRO_IO_ISTREAMSYSTEM_


#include "config.h"
#include <core/ISystem.h>


#undef CreateDirectory
#define CreateDirectory CreateDirectory


namespace synkro
{


namespace io
{


/**
 * Stream system. Provides access to I/O streams.
 */
iface IStreamSystem :
	public core::ISystem
{
public:
	/**
	 * Creates directory from the specified path and adds all its subdirectories to stream system.
	 * @param path Path to map as a trunk directory.
	 * @param recursive Indicates whether to map all indirect subdirectories.
	 * @return Created directory, if path exists, or null otherwise.
	 */
	virtual IStreamDirectory*								MapDirectory( const lang::String& path, Bool recursive ) = 0;

	/**
	 * Creates new directory from the given path.
	 * @param path Path to the directory.
	 * @return Created directory.
	 * @exception IoException Directory cannot be created.
	 */
	virtual IStreamDirectory*								BuildDirectory( const lang::String& path ) = 0;

	/**
	* Creates file stream from existing file.
	* @param path Full path to the file.
	* @return Mapped stream.
	*/
	virtual IStream*										MapStream( const lang::String& path ) = 0;

	/**
	 * Creates file stream from the given path.
	 * @param path Full path to the stream.
	 * @return Created stream.
	 * @exception IoException Stream cannot be created.
	 */
	virtual IStream*										CreateStream( const lang::String& path ) = 0;

	/**
	 * Retrieves file stream by name.
	 * @param name Full path to the stream in the stream directory.
	 * @return Requested stream, if one is found, nullptr otherwise.
	 */
	virtual IStream*										GetStream( const lang::String& name ) const = 0;

	/**
	 * Retrieves stream directory by name.
	 * @param name Full path to the directory.
	 * @return Requested stream directory, if one is found, nullptr otherwise.
	 */
	virtual IStreamDirectory*								GetDirectory( const lang::String& name ) const = 0;
};


} // io


} // synkro


#endif // _SYNKRO_IO_ISTREAMSYSTEM_
