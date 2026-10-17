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
// Purpose: Obj mesh material description.
//==============================================================================
#ifndef _SYNKRO_SCENE_OBJMATERIAL_
#define _SYNKRO_SCENE_OBJMATERIAL_


#include "config.h"
#include <img/Color.h>
#include <lang/Ptr.h>
#include <lang/String.h>
#include <mat/IOpaqueMaterial.h>
#include <mat/IMaterialMap.h>


namespace synkro
{


namespace scene
{


struct ObjMaterial
{
	ObjMaterial( mat::IOpaqueMaterial* material )
	{
		Name = material->GetName();
		material->GetAmbientColor( Ambient );
		material->GetDiffuseColor( Diffuse );
		material->GetEmissiveColor( Emissive );
		material->GetSpecularColor( Specular );
		SpecularPower = material->GetSpecularPower();
		DiffuseTexture = material->GetDiffuseMap()->GetName();
	}

	ObjMaterial()
	{
	}

	lang::String			Name;
	img::Color				Ambient;
	img::Color				Diffuse;
	img::Color				Emissive;
	img::Color				Specular;
	Float					SpecularPower;
	lang::String			DiffuseTexture;
	P(mat::IOpaqueMaterial)	Material;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_OBJMATERIAL_
