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
// Purpose: Generic scripting system implementation.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_SCRIPTSYSTEMIMPL_
#define _SYNKRO_SCRIPT_SCRIPTSYSTEMIMPL_


#include "config.h"
#include <core/ObjectImpl.h>


namespace synkro
{


namespace script
{


// Generic scripting system implementation.
template <class T>
class ScriptSystemImpl :
	public core::ObjectImpl<T>,
	public Logger
{
public:
	// Constructor & destructor.
	ScriptSystemImpl( diag::ILog* log );
	virtual ~ScriptSystemImpl();

	// ISystem methods.
	virtual Bool											Update( Double delta );
};


#include "ScriptSystemImpl.inl"


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_SCRIPTSYSTEMIMPL_
