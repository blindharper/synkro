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
// Purpose: Base log.
//==============================================================================
#ifndef _SYNKRO_DIAG_BASELOG_
#define _SYNKRO_DIAG_BASELOG_


#include "config.h"
#include <diag/LogMode.h>
#include <diag/LogLevel.h>


namespace synkro
{


namespace diag
{


// Base log.
class BaseLog
{
public:
	virtual void											Initialize( const LogLevel& level, const LogMode& mode ) = 0;
	virtual void											Pause( Bool pause ) = 0;
};


// Casts object to BaseLog.
#define AsBaseLog( OBJ ) dynamic_cast<BaseLog*>( OBJ )


} // diag


} // synkro


#endif // _SYNKRO_DIAG_BASELOG_

