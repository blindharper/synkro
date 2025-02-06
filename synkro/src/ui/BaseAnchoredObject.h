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
// Purpose: Base anchor-aware object.
//==============================================================================
#ifndef _SYNKRO_UI_BASEANCHOREDOBJECT_
#define _SYNKRO_UI_BASEANCHOREDOBJECT_


#include "config.h"


namespace synkro
{


namespace ui
{


// Base anchor-aware object.
class BaseAnchoredObject
{
public:
	virtual void											SaveAnchors() = 0;
	virtual void											RestoreAnchors() = 0;
};


// Casts object to BaseAnchoredObject.
#define AsBaseAnchoredObject( OBJ ) dynamic_cast<BaseAnchoredObject*>( OBJ )


} // ui


} // synkro


#endif // _SYNKRO_UI_BASEANCHOREDOBJECT_
