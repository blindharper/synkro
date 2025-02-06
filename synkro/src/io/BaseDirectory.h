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
// Purpose: Defines abstract file directory.
//==============================================================================
#ifndef _SYNKRO_IO_BASEDIRECTORY_
#define _SYNKRO_IO_BASEDIRECTORY_


#include "config.h"
#include <io/OpenMode.h>


namespace synkro
{


namespace io
{


// Abstract file directory.
class BaseDirectory
{
public:
	virtual Bool											FileOpen( const lang::String& name, const OpenMode& mode ) = 0;
	virtual void											FileClose() = 0;
	virtual UInt											FileRead( void* data, UInt size ) = 0;
	virtual UInt											FileWrite( const void* data, UInt size ) = 0;
	virtual Int												FileSeek( const lang::String& name, UInt size, UInt position, Int bytes, const SeekOrigin& origin ) = 0;
	virtual Bool											FileReset( const lang::String& name ) = 0;
};


} // io


} // synkro


#endif // _SYNKRO_IO_BASEDIRECTORY_
