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
// Purpose: Generic controller implementation.
//==============================================================================
#ifndef _SYNKRO_CORE_CONTROLLERIMPL_
#define _SYNKRO_CORE_CONTROLLERIMPL_


#include "config.h"
#include "ObjectImpl.h"
#include <core/ControllerState.h>
#include "ControllerStateConst.h"


namespace synkro
{


namespace core
{


// Generic controller implementation.
template <class T>
class ControllerImpl :
	public ObjectImpl<T>
{
public:
	// Constructors & destructor.
	ControllerImpl();
	virtual ~ControllerImpl();

	// IController methods.
	virtual void											Start( Bool start );
	virtual void											Pause( Bool pause );
	virtual void											Update( Double delta );
	virtual void											SetTime( Double time );
	virtual void											Restart();
	virtual void											Reset();
	virtual Double											GetTime() const;
	virtual ControllerState									GetState() const;

protected:
	ControllerState											_state;
	Double													_time;
};


#include "ControllerImpl.inl"


} // core


} // synkro


#endif // _SYNKRO_CORE_CONTROLLERIMPL_
