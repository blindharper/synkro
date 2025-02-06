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
// Purpose: Implements material triangle set.
//==============================================================================
#ifndef _SYNKRO_MAT_MATERIALTRIANGLESET_
#define _SYNKRO_MAT_MATERIALTRIANGLESET_


#include "config.h"
#include <scene/TriangleSetImpl.h>
#include <scene/ITriangleSet.h>


namespace synkro
{


namespace mat
{


// Triangle set implementation for materials.
class SYNKRO_API MaterialTriangleSet :
	public scene::TriangleSetImpl<scene::ITriangleSet>
{
public:
	// Constructor.
	MaterialTriangleSet( gfx::ISceneRenderObject* object, UInt start, UInt count );
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_MATERIALTRIANGLESET_
