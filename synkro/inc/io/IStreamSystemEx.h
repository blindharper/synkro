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
// Purpose: Defines extended stream system.
//==============================================================================
#ifndef _SYNKRO_IO_ISTREAMSYSTEMEX_
#define _SYNKRO_IO_ISTREAMSYSTEMEX_


#include "config.h"
#include <io/IStreamSystem.h>
#include <io/StreamDirectory.h>


#undef IStream
#define IStream IStream


namespace synkro
{


namespace io
{


/**
 * Extended stream system.
 */
iface IStreamSystemEx :
	public IStreamSystem
{
public:
	/**
	 * Creates stream directory from the given stream.
	 * @param stream Stream used to create the stream directory.
	 * @param type Directory type.
	 * @param write Specifies whether to allow writing to the directory.
	 * @return Created stream directory if succeeded, nullptr otherwise.
	 */
	virtual IStreamDirectory*								CreateDirectory( IStream* stream, const StreamDirectory& type, Bool write ) = 0;

	/**
	 * Creates stream directory of the given type.
	 * @param path Full path to the directory.
	 * @param type Directory type.
	 * @return Created directory.
	 */
	virtual IStreamDirectory*								CreateDirectory( const lang::String& path, const StreamDirectory& type ) = 0;

	/**
	 * Creates binary stream and opens it for reading.
	 * @param data Stream data.
	 * @param size Stream data size, in bytes.
	 * @return Created stream.
	 */
	virtual IStream*										CreateBinaryStream( const Byte* data, UInt size ) = 0;

	/**
	 * Creates empty binary stream and opens it for writing.
	 * @return Created stream.
	 */
	virtual IStream*										CreateBinaryStream() = 0;

	/**
	 * Creates text stream and opens it for reading.
	 * @param data Stream data.
	 * @param encoding Text encoding name.
	 * @return Created stream.
	 */
	virtual IStream*										CreateTextStream( const lang::String& data, const char* encoding ) = 0;

	/**
	 * Creates empty text stream and opens it for writing.
	 * @param encoding Text encoding name.
	 * @return Created stream.
	 */
	virtual IStream*										CreateTextStream( const char* encoding ) = 0;

	/**
	 * Creates empty text stream and opens it for writing.
	 * @return Created stream.
	 */
	virtual IStream*										CreateTextStream() = 0;
};


} // io


} // synkro


#endif // _SYNKRO_IO_ISTREAMSYSTEMEX_
