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
// Purpose: Defines stream directory factory.
//==============================================================================
#ifndef _SYNKRO_IO_ISTREAMDIRECTORYFACTORY_
#define _SYNKRO_IO_ISTREAMDIRECTORYFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace io
{


/**
 * Stream directory factory.
 */
iface IStreamDirectoryFactory :
	public core::IFactory
{
public:
	/**
	 * Creates stream directory from the given stream.
	 * @param stream Stream used to create the stream directory.
	 * @param write Specifies whether to allow writing to the directory.
	 * @return Created stream directory if succeeded, nullptr otherwise.
	 */
	virtual IStreamDirectory*								Create( IStream* stream, Bool write ) = 0;
};


} // io


} // synkro


#endif // _SYNKRO_IO_ISTREAMDIRECTORYFACTORY_
