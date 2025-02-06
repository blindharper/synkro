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
// Purpose: Opacity map implementation.
//==============================================================================
#include "config.h"
#include "OpacityMap.h"


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace mat
{


OpacityMap::OpacityMap( BaseMaterial* material ) :
	_material( material )
{
}

void OpacityMap::SetImage( IImage* image )
{
	// Call base implementation.
	MaterialMapImpl<IMaterialMap>::SetImage( image );

	// Notify owner material.
	_material->OnOpacityMapSet();
}


} // mat


} // synkro
