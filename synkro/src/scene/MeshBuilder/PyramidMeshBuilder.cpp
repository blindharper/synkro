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
// Purpose: Pyramid mesh builder.
//==============================================================================
#include "config.h"
#include "PyramidMeshBuilder.h"
#include <scene/ILineMesh.h>
#include <scene/IPointMesh.h>
#include <scene/ITriangleMesh.h>
#include <scene/IPointSet.h>
#include <scene/ILineSet.h>
#include <scene/ITriangleSet.h>
#include <scene/IScene.h>
#include <lang/Vector.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


PyramidMeshBuilder::PyramidMeshBuilder()
{
}

void PyramidMeshBuilder::Build( IPointMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float width = param1.x;
	const Float depth = param1.y;
	const Float height = param1.z;

	// Create mesh.
	constexpr UInt vertexCount = 5;
	IPointSet* pyramid = mesh->CreatePointList( String::Format(L"Pyramid {0}", mesh->GetSubsetCount()), vertexCount, 1.0f, ColorMode::Monochrome, transform );

	// Set positions.
	Vector3 positions[] =
	{
		Vector3( -width/2.0f,	 0.0f,	 depth/2.0f ),
		Vector3(  width/2.0f,	 0.0f,	 depth/2.0f ),
		Vector3( -width/2.0f,	 0.0f,	-depth/2.0f ),
		Vector3(  width/2.0f,	 0.0f,	-depth/2.0f ),
		Vector3(		0.0f,	height,		   0.0f ),
	};
	pyramid->SetPositions( positions, 0, vertexCount );
}

void PyramidMeshBuilder::Build( ILineMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float width = param1.x;
	const Float depth = param1.y;
	const Float height = param1.z;

	// Create mesh.
	constexpr UInt vertexCount = 5;
	constexpr UInt indexCount = 16;
	ILineSet* pyramid = mesh->CreateLineList( String::Format(L"Pyramid {0}", mesh->GetSubsetCount()), vertexCount, indexCount, false, ColorMode::Monochrome, transform );

	// Set positions.
	Vector3 positions[] =
	{
		Vector3( -width/2.0f,	 0.0f,	 depth/2.0f ),
		Vector3(  width/2.0f,	 0.0f,	 depth/2.0f ),
		Vector3( -width/2.0f,	 0.0f,	-depth/2.0f ),
		Vector3(  width/2.0f,	 0.0f,	-depth/2.0f ),
		Vector3(		0.0f,	height,		   0.0f ),
	};
	pyramid->SetPositions( positions, 0, vertexCount );

	// Set indices.
	UInt indices[] =
	{
		0, 1, 1, 3, 3, 2, 2, 0,
		0, 4, 1, 4, 3, 4, 2, 4
	};
	pyramid->SetIndices( indices, 0, indexCount );
}

void PyramidMeshBuilder::Build( ITriangleMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float width = param1.x;
	const Float depth = param1.y;
	const Float height = param1.z;

	// Create mesh.
	constexpr UInt vertexCount = 5;
	constexpr UInt indexCount = 18;
	ITriangleSet* pyramid = mesh->CreateTriangleList( String::Format(L"Pyramid {0}", mesh->GetSubsetCount()), vertexCount, indexCount, false, transform );

	// Set positions.
	Vector3 positions[] =
	{
		Vector3( -width/2.0f,	  0.0f,	 depth/2.0f ),
		Vector3(  width/2.0f,	  0.0f,	 depth/2.0f ),
		Vector3( -width/2.0f,	  0.0f,	-depth/2.0f ),
		Vector3(  width/2.0f,	  0.0f,	-depth/2.0f ),
		Vector3(		0.0f,	height,		   0.0f ),
	};
	pyramid->SetPositions( positions, 0, vertexCount );

	// Set texture coordinates.
	Vector2 coords[] =
	{
		Vector2( 0.0f, 0.0f ),
		Vector2( 0.0f, 1.0f ),
		Vector2( 1.0f, 0.0f ),
		Vector2( 1.0f, 1.0f ),
		Vector2( 0.5f, 0.5f ),
	};
	pyramid->SetTextureCoordinates( coords, 0, vertexCount );

	// Set indices.
	UInt indices[] =
	{
		0, 2, 1, 1, 2, 3,
		0, 1, 4, 1, 3, 4,
		3, 2, 4, 2, 0, 4
	};
	pyramid->SetIndices( indices, 0, indexCount );

	// Set normals.
	if ( mesh->GetScene()->IsLit() )
	{
		Vector<Vector3> normals( A(Vector3) );
		normals.SetSize( vertexCount );
		GenerateNormals( indices, indexCount, positions, normals.Begin(), false );
		pyramid->SetNormals( normals.Begin(), 0, normals.Size() );
	}
}


} // scene


} // synkro
