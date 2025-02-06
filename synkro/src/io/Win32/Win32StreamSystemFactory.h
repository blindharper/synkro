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
// Purpose: Win32 stream system factory.
//==============================================================================
#ifndef _SYNKRO_IO_WIN32STREAMSYSTEMFACTORY_
#define _SYNKRO_IO_WIN32STREAMSYSTEMFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <io/IStreamSystemFactory.h>
#include <io/StreamSystem.h>
#include "Win32StreamSystem.h"


namespace synkro
{


namespace io
{


// Win32 stream system factory.
SYNKRO_FACTORY_BEGIN( Win32StreamSystemFactory, IStreamSystemFactory, StreamSystem, StreamSystem::Win32 )
	IStreamSystem*	Create( diag::ILog* log ) { return new Win32StreamSystem(log); }
SYNKRO_FACTORY_END()


} // io


} // synkro


#endif // _SYNKRO_IO_WIN32STREAMSYSTEMFACTORY_
