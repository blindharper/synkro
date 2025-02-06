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
#include "config.h"
#include "DiffuseMap.h"


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace mat
{


DiffuseMap::DiffuseMap( BaseMaterial* material, IImage* image ) :
	_material( material )
{
	if ( image != nullptr )
	{
		MaterialMapImpl<IMaterialMap>::SetImage( image );
	}
}

void DiffuseMap::SetImage( IImage* image )
{
	if ( image != nullptr )
	{
		if ( (image->GetFormat().ChannelCount() < 3) )
			throw BadArgumentException( L"Diffuse map should have at least 3 channels.", L"image" );
	}

	// Call base implementation.
	MaterialMapImpl<IMaterialMap>::SetImage( image );

	// Notify owner material.
	_material->OnDiffuseMapSet();
}


} // mat


} // synkro
