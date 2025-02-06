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
// Purpose: 'io' namespace includes.
//==============================================================================
#ifndef _SYNKRO_IO_
#define _SYNKRO_IO_


#include <io/IStream.h>
#include <io/IStreamSystemEx.h>
#include <io/IStreamSet.h>
#include <io/IStreamDirectory.h>
#include <io/IStreamDirectoryFactory.h>
#include <io/IoException.h>
#include <io/FileNotFoundException.h>
#include <io/StreamSystem.h>
#include <io/StreamDirectory.h>


#define PtrStream P(synkro::io::IStream)
#define PtrStreamSet P(synkro::io::IStreamSet)
#define PtrStreamDirectory P(synkro::io::IStreamDirectory)


namespace synkro
{


/**
 * The 'io' namespace contains interfaces
 * for manipulation host file system
 * and working with compressed folders.
 */
namespace io
{
} // io


} // synkro


#endif // _SYNKRO_IO_
