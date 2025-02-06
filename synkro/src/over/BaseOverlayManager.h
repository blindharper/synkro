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
// Purpose: Base overlay manager.
//==============================================================================
#ifndef _SYNKRO_OVER_BASEOVERLAYMANAGER_
#define _SYNKRO_OVER_BASEOVERLAYMANAGER_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace over
{


// Base overlay manager.
class BaseOverlayManager
{
public:
	virtual IFont*											CreateFont( const lang::String& name, IOverlay* overlay ) = 0;
	virtual gfx::IProgram*									GetFontProgram() const = 0;
	virtual gfx::IBlendStateSet*							GetBlendStates() const = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_BASEOVERLAYMANAGER_
