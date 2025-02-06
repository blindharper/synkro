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
// Purpose: Base stream system.
//=============================================================================
#ifndef _SYNKRO_IO_BASESTREAMSYSTEM_
#define _SYNKRO_IO_BASESTREAMSYSTEM_


#include "config.h"


namespace synkro
{


namespace io
{


// Base stream system.
class BaseStreamSystem
{
public:
	virtual IStreamDirectory*								CreateDirectory( IStream* stream ) = 0;
};


} // io


} // synkro


#endif // _SYNKRO_IO_BASESTREAMSYSTEM_
