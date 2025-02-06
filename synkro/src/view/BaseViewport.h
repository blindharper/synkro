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
// Purpose: Defines base viewport.
//==============================================================================
#ifndef _SYNKRO_VIEW_BASEVIEWPORT_
#define _SYNKRO_VIEW_BASEVIEWPORT_


#include "config.h"


namespace synkro
{


namespace view
{


// Base viewport.
class BaseViewport
{
public:
	virtual void											AddFilter( IViewportFilter* filter ) = 0;
	virtual void											RemoveFilter( IViewportFilter* filter ) = 0;
	virtual void											SetActive( Bool active ) = 0;
	virtual void											Update() = 0;
	virtual IViewport*										AsViewport() const = 0;
};


// Casts object to BaseViewport.
#define AsBaseViewport( OBJ ) dynamic_cast<BaseViewport*>( OBJ )


} // view


} // synkro


#endif // _SYNKRO_VIEW_BASEVIEWPORT_
