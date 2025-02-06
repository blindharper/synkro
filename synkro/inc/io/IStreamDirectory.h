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
// Purpose: Defines stream directory.
//==============================================================================
#ifndef _SYNKRO_IO_ISTREAMDIRECTORY_
#define _SYNKRO_IO_ISTREAMDIRECTORY_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>


#undef CreateDirectory
#define CreateDirectory CreateDirectory


namespace synkro
{


namespace io
{


/**
 * Stream directory.
 */
iface IStreamDirectory :
	public core::IObject
{
public:
	/**
	 * Creates new directory.
	 * @param name Directory name.
	 * @return Created directory.
	 * @exception IoException Directory cannot be created.
	 */
	virtual IStreamDirectory*								CreateDirectory( const lang::String& name ) = 0;

	/**
	 * Creates new stream and opens it for writing.
	 * @param name Stream name.
	 * @return Created stream.
	 * @exception IoException Stream cannot be created.
	 */
	virtual IStream*										CreateStream( const lang::String& name ) = 0;

	/**
	 * Retrieves the total number of streams in the directory.
	 * @return Number of streams.
	 */
	virtual UInt											GetStreamCount() const = 0;

	/**
	 * Retrieves stream by index.
	 * @param index stream index.
	 * @return Requested stream.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IStream*										GetStream( UInt index ) const = 0;

	/**
	 * Retrieves stream by name.
	 * @param name Full path to the stream in the stream directory.
	 * @return Requested stream, if one is found, nullptr otherwise.
	 */
	virtual IStream*										GetStream( const lang::String& name ) const = 0;

	/**
	 * Retrieves a set of streams matching the specified pattern.
	 * @param pattern Search pattern.
	 * @return Stream set.
	 */
	virtual IStreamSet*										GetStreams( const lang::String& pattern ) const = 0;

	/**
	 * Retrieves all streams in the directory.
	 * @return Stream set.
	 */
	virtual IStreamSet*										GetStreams() const = 0;

	/**
	 * Retrieves the total number of stream directories in the directory.
	 * @return Number of directories.
	 */
	virtual UInt											GetDirectoryCount() const = 0;

	/**
	 * Retrieves stream directory by index.
	 * @param index stream directory index.
	 * @return Requested stream directory.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IStreamDirectory*								GetDirectory( UInt index ) const = 0;

	/**
	 * Retrieves stream directory by name.
	 * @param name Full path to the directory.
	 * @return Requested stream directory, if one is found, nullptr otherwise.
	 */
	virtual IStreamDirectory*								GetDirectory( const lang::String& name ) const = 0;

	/**
	 * Retrieves parent directory.
	 */
	virtual IStreamDirectory*								GetParent() const = 0;

	/**
	 * Retrieves directory name.
	 */
	virtual lang::String									GetName() const = 0;
};


} // io


} // synkro


#endif // _SYNKRO_IO_ISTREAMDIRECTORY_
