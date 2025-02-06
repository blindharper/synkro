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
#include "config.h"
#include "MaterialTriangleSet.h"


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace mat
{


MaterialTriangleSet::MaterialTriangleSet( ISceneRenderObject* object, UInt start, UInt count ) :
	TriangleSetImpl<ITriangleSet>( object, start, count )
{
}


} // mat


} // synkro
