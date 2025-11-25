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
	ControllerImpl() SYNKRO_NOEXCEPT;
	virtual ~ControllerImpl();

	// IController methods.
	virtual void											Start( Bool start );
	virtual void											Pause( Bool pause );
	virtual void											Update( Double delta );
	virtual void											SetTime( Double time ) SYNKRO_NOEXCEPT;
	virtual void											Restart() SYNKRO_NOEXCEPT;
	virtual void											Reset() SYNKRO_NOEXCEPT;
	virtual Double											GetTime() const SYNKRO_NOEXCEPT;
	virtual ControllerState									GetState() const SYNKRO_NOEXCEPT;

protected:
	ControllerState											_state;
	Double													_time;
};


#include "ControllerImpl.inl"


} // core


} // synkro


#endif // _SYNKRO_CORE_CONTROLLERIMPL_
