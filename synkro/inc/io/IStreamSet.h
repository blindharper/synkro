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
// Purpose: Defines stream set.
//==============================================================================
#ifndef _SYNKRO_IO_ISTREAMSET_
#define _SYNKRO_IO_ISTREAMSET_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace io
{


/**
 * Stream set.
 */
iface IStreamSet :
	public core::IObject
{
public:
	/**
	 * Removes all streams from the set.
	 */
	virtual void											Clear() = 0;

	/**
	 * Adds the specified stream to the set.
	 * @param stream Stream to add.
	 * @exception BadArgumentException Stream is null.
	 */
	virtual void											Add( IStream* stream ) = 0;

	/**
	 * Returns the total number of streams in the set.
	 */
	virtual UInt											GetSize() const = 0;

	/**
	 * Retrieves a stream by index.
	 * @param index Index of the stream to retrieve.
	 * @return Requested stream.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IStream*										Get( UInt index ) const = 0;

	/**
	 * Retrieves the index of the specified stream.
	 * @param stream Stream to look for.
	 * @return Non-negative index of the specified stream if one is found, or none otherwise.
	 */
	virtual UInt											IndexOf( IStream* stream ) const = 0;
};


} // io


} // synkro


#endif // _SYNKRO_IO_ISTREAMSET_
