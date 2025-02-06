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
// Purpose: Zip directory factory.
//==============================================================================
#ifndef _SYNKRO_IO_ZIPDIRECTORYFACTORY_
#define _SYNKRO_IO_ZIPDIRECTORYFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <io/IStreamDirectoryFactory.h>
#include <io/StreamDirectory.h>
#include "ZipDirectory.h"


namespace synkro
{


namespace io
{


// Zip directory factory.
SYNKRO_FACTORY_BEGIN( ZipDirectoryFactory, IStreamDirectoryFactory, StreamDirectory, StreamDirectory::Zip )
	IStreamDirectory*	Create( IStream* stream, Bool write ) { return (write || ZipDirectory::IsDirectory(stream)) ? new ZipDirectory(stream, write) : nullptr; }
SYNKRO_FACTORY_END()


} // io


} // synkro


#endif // _SYNKRO_IO_ZIPDIRECTORYFACTORY_
