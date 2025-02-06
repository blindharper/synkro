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
// Purpose: Defines input/output stream.
//==============================================================================
#ifndef _SYNKRO_IO_ISTREAM_
#define _SYNKRO_IO_ISTREAM_


#include "config.h"
#include <core/IObject.h>
#include <io/AccessMode.h>
#include <io/OpenMode.h>
#include <io/SeekOrigin.h>


namespace synkro
{


namespace io
{


/**
 * Input/output stream.
 */
iface IStream :
	public core::IObject
{
public:
	/**
	 * Opens stream with the specified access type.
	 * @param mode Stream open mode.
	 */
	virtual void											Open( const OpenMode& mode ) = 0;

	/**
	 * Closes stream and frees all associated resources.
	 */
	virtual void											Close() = 0;

	/**
	 * Forces any buffered output to be written out.
	 * @exception IoException Stream is not open for writing.
	 */
	virtual void											Flush() = 0;

	/**
	 * Reads given number of bytes from the stream.
	 * @param data Buffer to which to read stream data.
	 * @param size Number of bytes to read.
	 * @return Number of bytes actually read.
	 * @exception IoException Stream is not open for reading.
	 */
	virtual UInt											Read( void* data, UInt size ) = 0;

	/**
	 * Writes given number of bytes to the stream.
	 * @param data Buffer to write to the stream.
	 * @param size Number of bytes to write.
	 * @return Number of bytes actually written.
	 * @exception IoException Stream is not open for writing.
	 */
	virtual UInt											Write( const void* data, UInt size ) = 0;

	/**
	 * Moves stream pointer to the given position.
	 * @param bytes Number of bytes from the origin.
	 * @param origin Position from which to perform seek.
	 * @return Number of bytes actually skipped.
	 * @exception IoException Stream is not open for reading.
	 */
	virtual Int												Seek( Int bytes, const SeekOrigin& origin ) = 0;

	/**
	 * Positions stream pointer to the beginning.
	 * @return True if reset succeeded, false otherwise.
	 */
	virtual Bool											Reset() = 0;

	/**
	 * Physically removes stream from storage.
	 */
	virtual void											Delete() = 0;

	/**
	 * Sets stream access mode.
	 * @param mode New access mode.
	 */
	virtual void											SetAccessMode( const AccessMode& mode ) = 0;

	/**
	 * Sets new stream length.
	 * @param length New stream length, in bytes.
	 */
	virtual void											SetLength( UInt length ) = 0;

	/**
	 * Indicates if the stream exists on storage without opening it.
	 * @return True if stream exists, false otherwise.
	 */
	virtual Bool											Exists() const = 0;

	/**
	 * Retrieves stream access mode.
	 */
	virtual AccessMode										GetAccessMode() const = 0;

	/**
	 * Retrieves stream length, in bytes.
	 */
	virtual UInt											GetLength() const = 0;

	/**
	 * Retrieves current stream position, in bytes.
	 */
	virtual UInt											GetPosition() const = 0;

	/**
	 * Retrieves stream open mode.
	 */
	virtual OpenMode										GetMode() const = 0;

	/**
	 * Retrieves optional stream name.
	 */
	virtual lang::String									GetName() const = 0;

	/**
	 * Retrieves stream's parent directory.
	 */
	virtual IStreamDirectory*								GetDirectory() const = 0;
};


} // io


} // synkro


#endif // _SYNKRO_IO_ISTREAM_
