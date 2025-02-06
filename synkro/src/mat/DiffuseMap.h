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
// Purpose: Diffuse map implementation.
//==============================================================================
#ifndef _SYNKRO_MAT_DIFFUSEMAP_
#define _SYNKRO_MAT_DIFFUSEMAP_


#include "config.h"
#include "MaterialMapImpl.h"
#include <mat/IMaterialMap.h>
#include "BaseMaterial.h"


namespace synkro
{


namespace mat
{


// Diffuse map implementation.
class DiffuseMap :
	public MaterialMapImpl<IMaterialMap>
{
public:
	// Constructor.
	DiffuseMap( BaseMaterial* material, img::IImage* image );

	// IMaterialMap methods.
	void													SetImage( img::IImage* image );

private:
	BaseMaterial*											_material;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_DIFFUSEMAP_
