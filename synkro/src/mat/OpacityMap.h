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
#ifndef _SYNKRO_MAT_OPACITYMAP_
#define _SYNKRO_MAT_OPACITYMAP_


#include "config.h"
#include "MaterialMapImpl.h"
#include <mat/IMaterialMap.h>
#include "BaseMaterial.h"


namespace synkro
{


namespace mat
{


// Opacity map implementation.
class OpacityMap :
	public MaterialMapImpl<IMaterialMap>
{
public:
	// Constructor.
	OpacityMap( BaseMaterial* material );

	// IMaterialMap methods.
	void													SetImage( img::IImage* image );

private:
	BaseMaterial*											_material;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_OPACITYMAP_
