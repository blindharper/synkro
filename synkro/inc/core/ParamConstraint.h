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
// Purpose: Defines configuration parameter constraints.
//==============================================================================
#ifndef _SYNKRO_CORE_PARAMCONSTRAINT_
#define _SYNKRO_CORE_PARAMCONSTRAINT_


#include "config.h"
#include <lang/Flag.h>


namespace synkro
{


namespace core
{


/**
 * Configuration parameter constraints.
 */
SYNKRO_FLAG_BEGIN( ParamConstraint )
	/** No constraints. */
	SYNKRO_FLAG_CONST( ParamConstraint, None )
	
	/** String value should be non-empty. */
	SYNKRO_FLAG_CONST( ParamConstraint, NonEmpty )
		
	/** Number should be greater than zero. */
	SYNKRO_FLAG_CONST( ParamConstraint, Positive )
SYNKRO_FLAG_END()


} // core


} // synkro


#endif // _SYNKRO_CORE_PARAMCONSTRAINT_
