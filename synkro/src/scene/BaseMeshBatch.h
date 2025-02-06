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
// Purpose: Defines base mesh batch.
//==============================================================================
#ifndef _SYNKRO_SCENE_BASEMESHBATCH_
#define _SYNKRO_SCENE_BASEMESHBATCH_


#include "config.h"


namespace synkro
{


namespace scene
{


// Base mesh batch.
class BaseMeshBatch
{
public:
	virtual void											Update() = 0;
};


// Casts object to BaseMeshBatch.
#define AsBaseMeshBatch( OBJ ) dynamic_cast<BaseMeshBatch*>( OBJ )


} // scene


} // synkro


#endif // _SYNKRO_SCENE_BASEMESHBATCH_
