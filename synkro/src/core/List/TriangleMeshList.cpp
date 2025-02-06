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
// Purpose: Triangle mesh list implementation.
//==============================================================================
#include "config.h"
#include "TriangleMeshList.h"


//------------------------------------------------------------------------------

using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


TriangleMeshList::TriangleMeshList() :
	_meshes( A(P(ITriangleMesh)) )
{
}


} // core


} // synkro
