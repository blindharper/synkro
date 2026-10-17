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
// Purpose: Obj mesh description.
//==============================================================================
#ifndef _SYNKRO_SCENE_OBJMESH_
#define _SYNKRO_SCENE_OBJMESH_


#include "config.h"
#include <lang/String.h>
#include <lang/Vector.h>
#include <math/Vector2.h>
#include <math/Vector3.h>
#include <scene/ITriangleSet.h>


namespace synkro
{


namespace scene
{


struct ObjModelDesc
{
	ObjModelDesc( ITriangleSet* subset, const lang::String& name ) :
		Positions( A(math::Vector3) ),
		Normals( A(math::Vector3) ),
		TexCoords( A(math::Vector2) ),
		Indices( A(UInt) ),
		Name( name ),
		Material( none )
	{
		lang::Vector<UInt> indices( A(UInt) );
		indices.SetSize( subset->GetIndexCount() );
		subset->GetIndices( indices.Begin(), 0, indices.Size() );
		const UInt faceCount = indices.Size()/3;
		// TODO: Complete faces!!!

		Positions.SetSize( subset->GetVertexCount() );
		subset->GetPositions( Positions.Begin(), 0, Positions.Size() );

		Normals.SetSize( subset->GetVertexCount() );
		if ( !subset->GetNormals(Normals.Begin(), 0, Normals.Size()) )
		{
			Normals.Clear();
		}

		TexCoords.SetSize( subset->GetVertexCount() );
		if ( !subset->GetTextureCoordinates(TexCoords.Begin(), 0, TexCoords.Size()) )
		{
			TexCoords.Clear();
		}
	}

	ObjModelDesc( const lang::String& name ) :
		Positions( A(math::Vector3) ),
		Normals( A(math::Vector3) ),
		TexCoords( A(math::Vector2) ),
		Indices( A(UInt) ),
		Name( name ),
		Material( none )
	{
	}

	ObjModelDesc() :
		Positions( A(math::Vector3) ),
		Normals( A(math::Vector3) ),
		TexCoords( A(math::Vector2) ),
		Indices( A(UInt) ),
		Material( none )
	{
	}

	lang::Vector<math::Vector3>	Positions;
	lang::Vector<math::Vector3>	Normals;
	lang::Vector<math::Vector2>	TexCoords;
	lang::Vector<UInt>			Indices;
	lang::String				Name;
	lang::String				MaterialName;
	UInt						Material;
};

struct Face
{
	Face() :
		IdxPos( none ),
		IdxTex( none ),
		IdxNorm( none )
	{
	}

	UInt IdxPos;
	UInt IdxTex;
	UInt IdxNorm;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_OBJMESH_
