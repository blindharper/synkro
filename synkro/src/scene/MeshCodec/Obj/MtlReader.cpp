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
// Purpose: Obj mesh material reader.
//==============================================================================
#include "config.h"
#include "MtlReader.h"


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


MtlReader::MtlReader( IStream* stream ) :
	ObjStreamReader( stream ),
	_materials( A(ObjMaterial) )
{
	Init();
}

UInt MtlReader::GetMaterialCount() const
{
	return _materials.Size();
}

void MtlReader::GetMaterial( UInt index, ObjMaterial& desc ) const
{
	if ( index < _materials.Size() )
	{
		desc = _materials[index];
	}
}

void MtlReader::ReadColor( Color& color )
{
	const Float r = GetFloat();
	const Float g = GetFloat();
	const Float b = GetFloat();
	color = Color(r, g, b);
}

void MtlReader::Init()
{
	while ( GetLexem() )
	{
		if ( !_strcmpi(_lexem.Begin(), "newmtl") )
		{
			ObjMaterial desc;
			desc.Name = GetString();
			_materials.Add( desc );
		}
		if ( !_strcmpi(_lexem.Begin(), "Ka") )
		{
			ReadColor( _materials.Last()->Ambient );
		}
		else if ( !_strcmpi(_lexem.Begin(), "Kd") )
		{
			ReadColor( _materials.Last()->Diffuse );
		}
		else if ( !_strcmpi(_lexem.Begin(), "Ke") )
		{
			ReadColor( _materials.Last()->Emissive );
		}
		else if ( !_strcmpi(_lexem.Begin(), "Ks") )
		{
			ReadColor( _materials.Last()->Specular );
		}
		else if ( !_strcmpi(_lexem.Begin(), "Ns") )
		{
			_materials.Last()->SpecularPower = GetFloat();
		}
		else if ( !_strcmpi(_lexem.Begin(), "map_Kd") )
		{
			String mapDiffuse = GetString();
			if ( mapDiffuse.Contains(L'.') )
			{
				_materials.Last()->DiffuseTexture = mapDiffuse;
			}
		}
	}
}


} // scene


} // synkro
