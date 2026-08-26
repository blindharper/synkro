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
// Purpose: Defines base billboard.
//==============================================================================
#ifndef _SYNKRO_SCENE_BASEBILLBOARD_
#define _SYNKRO_SCENE_BASEBILLBOARD_


#include "config.h"


namespace synkro
{


namespace scene
{


// Base billboard.
class BaseBillboard
{
public:
	virtual void											Update( view::IViewport* viewport ) = 0;
};


// Casts object to BaseBillboard.
#define AsBaseBillboard( OBJ ) dynamic_cast<BaseBillboard*>( OBJ )


} // scene


} // synkro


#endif // _SYNKRO_SCENE_BASEBILLBOARD_
