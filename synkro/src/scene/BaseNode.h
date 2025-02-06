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
// Purpose: Defines base node.
//==============================================================================
#ifndef _SYNKRO_SCENE_BASENODE_
#define _SYNKRO_SCENE_BASENODE_


#include "config.h"


namespace synkro
{


namespace scene
{


// Base node.
class BaseNode
{
public:
	virtual void											Update() = 0;
};


// Casts object to BaseNode.
#define AsBaseNode( OBJ ) dynamic_cast<BaseNode*>( OBJ )


} // scene


} // synkro


#endif // _SYNKRO_SCENE_BASENODE_
