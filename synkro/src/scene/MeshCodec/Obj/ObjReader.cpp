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
// Purpose: Obj mesh reader.
//==============================================================================
#include "config.h"
#include "ObjReader.h"


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


ObjReader::ObjReader( IStream* stream ) :
	ObjStreamReader( stream ),
	_models( A(ObjModelDesc) )
{
	Init();
}

String ObjReader::GetMaterialLibrary() const
{
	return _materialLibrary;
}

UInt ObjReader::GetModelCount() const
{
	return _models.Size();
}

void ObjReader::GetModel( UInt index, ObjModelDesc& desc ) const
{
	if ( index < _models.Size() )
	{
		desc = _models[index];
	}
}

void ObjReader::Init()
{
	Vector<Vector3> positions( A(Vector3) );
	Vector<Vector2> texCoords( A(Vector2) );
	Vector<Vector3> normals( A(Vector3) );
	Vector<Face> faces( A(Face) );
	String materialName = String::Empty;

	while ( GetLexem() )
	{
		if ( !_strcmpi(_lexem.Begin(), "mtllib") )
		{
			_materialLibrary = GetString();
		}
		else if ( !_strcmpi(_lexem.Begin(), "usemtl") )
		{
			materialName = GetString();
		}
		else if ( !_strcmpi(_lexem.Begin(), "g") || !_strcmpi(_lexem.Begin(), "o") )
		{
			String name = GetString();
			ObjModelDesc desc( name );
			_models.Add( desc );
		}
		else if ( !_strcmpi(_lexem.Begin(), "v") )
		{
			const Float x = GetFloat();
			const Float y = GetFloat();
			const Float z = GetFloat();
			positions.Add( Vector3(x, y, z) );
		}
		else if ( !_strcmpi(_lexem.Begin(), "vt") )
		{
			const Float x = GetFloat();
			const Float y = GetFloat();
			texCoords.Add( Vector2(x, 1.0f-y) );
		}
		else if ( !_strcmpi(_lexem.Begin(), "vn") )
		{
			const Float x = GetFloat();
			const Float y = GetFloat();
			const Float z = GetFloat();
			normals.Add( Vector3(x, y, -z) );
		}
		else if ( !_strcmpi(_lexem.Begin(), "f") )
		{
			if ( _models.Size() == 0 )
			{
				_models.Add( ObjModelDesc(L"Default") );
			}

			ObjModelDesc& desc = _models.LastValue();
			desc.MaterialName = materialName;
			faces.Clear();

			Face f;
			while ( GetFace(f) )
			{
				faces.Add( f );
			}

			// Split faces to triangles, if needed.
			UInt face[3] = {};
			const UInt idx = desc.Positions.Size();
			for ( UInt i = 0; i < faces.Size()-2; ++i )
			{
				face[0] = idx;
				face[1] = idx+i+1;
				face[2] = idx+i+2;
				desc.Indices.Add( face, 3 );
			}

			for ( UInt i = 0; i < faces.Size(); ++i )
			{
				desc.Positions.Add( positions[faces[i].IdxPos-1] );
				if ( faces[i].IdxNorm != none )
				{
					desc.Normals.Add( normals[faces[i].IdxNorm-1] );
				}
				if ( faces[i].IdxTex != none )
				{
					desc.TexCoords.Add( texCoords[faces[i].IdxTex-1] );
				}
			}
		}
	}
}

Bool ObjReader::GetFace( Face& face )
{
	int ret = 0;
	
	if ( PeekLexem() )
	{
		ret = sscanf( _lexemCache.Begin(), "%d/%d/%d", &face.IdxPos, &face.IdxTex, &face.IdxNorm );
		if ( ret == 3 )
		{
			GetLexem();
			return true;
		}

		ret = sscanf( _lexemCache.Begin(), "%d//%d", &face.IdxPos, &face.IdxNorm );
		if ( ret == 2 )
		{
			face.IdxTex = none;
			GetLexem();
			return true;
		}

		ret = sscanf( _lexemCache.Begin(), "%d/%d", &face.IdxPos, &face.IdxTex );
		if ( ret == 2 )
		{
			face.IdxNorm = none;
			GetLexem();
			return true;
		}

		ret = sscanf( _lexemCache.Begin(), "%d", &face.IdxPos );
		if ( ret == 1 )
		{
			face.IdxTex = none;
			face.IdxNorm = none;
			GetLexem();
			return true;
		}
	}

	return false;
}


} // scene


} // synkro
