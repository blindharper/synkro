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
// Purpose: Abstract task.
//==============================================================================
#ifndef _SYNKRO_CORE_TASK_
#define _SYNKRO_CORE_TASK_


#include "config.h"


namespace synkro
{


namespace core
{


/**
 * Abstract task. Executed asynchronously.
 */
class Task
{
public:
	/**
	 * Task entry point.
	 */
	virtual void											Execute() = 0;

	/**
	 * Cancels the task.
	 */
	virtual void											Cancel() = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_TASK_
