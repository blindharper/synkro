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
// Purpose: Defines stream seek origin constant values.
//==============================================================================
#ifndef _SYNKRO_IO_SEEKORIGINCONST_
#define _SYNKRO_IO_SEEKORIGINCONST_


#include "config.h"


namespace synkro
{


namespace io
{


// Stream seek origin constant values.
enum SeekOriginConst
{
	SEEK_ORIGIN_START	= 0,
	SEEK_ORIGIN_CURRENT	= 1,
	SEEK_ORIGIN_END		= 2,
};


} // io


} // synkro


#endif // _SYNKRO_IO_SEEKORIGINCONST_
