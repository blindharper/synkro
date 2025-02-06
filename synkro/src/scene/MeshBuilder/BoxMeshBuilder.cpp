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
// Purpose: Box mesh builder.
//==============================================================================
#include "config.h"
#include "BoxMeshBuilder.h"
#include <scene/ILineMesh.h>
#include <scene/IPointMesh.h>
#include <scene/ITriangleMesh.h>
#include <scene/IPointSet.h>
#include <scene/ILineSet.h>
#include <scene/ITriangleSet.h>
#include <scene/IScene.h>
#include <mat/IVisualMaterial.h>
#include <internal/SizeOf.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


BoxMeshBuilder::BoxMeshBuilder() :
	_positions( A(Vector3) ),
	_normals( A(Vector3) ),
	_coordinates( A(Vector2) ),
	_indices( A(UInt) )
{
}

void BoxMeshBuilder::Build( IPointMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float width = param1.x;
	const Float depth = param1.y;
	const Float height = param1.z;

	// Create mesh.
	const UInt vertexCount = 8;
	IPointSet* box = mesh->CreatePointList( String::Format(L"Box {0}", mesh->GetSubsetCount()), vertexCount, 1.0f, ColorMode::Monochrome, transform );

	// Set positions.
	Vector3 positions[] =
	{
		// Top.
		Vector3( -width/2.0f,	 height/2.0f,	 depth/2.0f ),
		Vector3(  width/2.0f,	 height/2.0f,	 depth/2.0f ),
		Vector3( -width/2.0f,	 height/2.0f,	-depth/2.0f ),
		Vector3(  width/2.0f,	 height/2.0f,	-depth/2.0f ),
		// Bottom.
		Vector3( -width/2.0f,	-height/2.0f,	 depth/2.0f ),
		Vector3(  width/2.0f,	-height/2.0f,	 depth/2.0f ),
		Vector3( -width/2.0f,	-height/2.0f,	-depth/2.0f ),
		Vector3(  width/2.0f,	-height/2.0f,	-depth/2.0f ),
	};
	box->SetPositions( positions, 0, vertexCount );
}

void BoxMeshBuilder::Build( ILineMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float width = param1.x;
	const Float depth = param1.y;
	const Float height = param1.z;

	// Create/resize mesh.
	const UInt vertexCount = 8;
	const UInt indexCount = 24;
	ILineSet* box = mesh->CreateLineList( String::Format(L"Box {0}", mesh->GetSubsetCount()), vertexCount, indexCount, false, ColorMode::Monochrome, transform );

	// Set positions.
	Vector3 positions[] =
	{
		// Top.
		Vector3( -width/2.0f,	 height/2.0f,	 depth/2.0f ),
		Vector3(  width/2.0f,	 height/2.0f,	 depth/2.0f ),
		Vector3( -width/2.0f,	 height/2.0f,	-depth/2.0f ),
		Vector3(  width/2.0f,	 height/2.0f,	-depth/2.0f ),
		// Bottom.
		Vector3( -width/2.0f,	-height/2.0f,	 depth/2.0f ),
		Vector3(  width/2.0f,	-height/2.0f,	 depth/2.0f ),
		Vector3( -width/2.0f,	-height/2.0f,	-depth/2.0f ),
		Vector3(  width/2.0f,	-height/2.0f,	-depth/2.0f ),
	};
	box->SetPositions( positions, 0, vertexCount );

	// Set indices.
	UInt indices[] =
	{
		0, 1, 1, 3, 3, 2, 2, 0,
		4, 5, 5, 7, 7, 6, 6, 4,
		0, 4, 1, 5, 2, 6, 3, 7
	};
	box->SetIndices( indices, 0, indexCount );
}

void BoxMeshBuilder::Build( ITriangleMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	Float width = param1.x;
	Float depth = param1.y;
	Float height = param1.z;
	Bool cacheMiss = (param1 != _param1);
	_param1 = param1;

	// Create/resize mesh.
	Bool simple = (mesh->GetMaterial()->GetSubsetCount() == 1);

	if ( mesh->GetSubsetCount() == 0 )
	{
		if ( simple )
		{
			mesh->CreateTriangleList( L"Box", 24, 36, false, transform );
		}
		else
		{
			for ( UInt i = 0; i < 6; ++i )
			{
				mesh->CreateTriangleList( L"BoxSide", 4, 6, false, transform );
			}
		}
	}
	else
	{
		if ( simple )
		{
			mesh->GetSubset( 0 )->Resize( 24, 36 );
		}
		else
		{
			for ( UInt i = 0; i < 6; ++i )
			{
				mesh->GetSubset( i )->Resize( 4, 6 );
			}
		}
	}

	// Set positions.
	if ( cacheMiss )
	{
		Vector3 positions[] =
		{
			// Right.
			Vector3(  width/2.0f,	 height/2.0f,	-depth/2.0f ),
			Vector3(  width/2.0f,	 height/2.0f,	 depth/2.0f ),
			Vector3(  width/2.0f,	-height/2.0f,	-depth/2.0f ),
			Vector3(  width/2.0f,	-height/2.0f,	 depth/2.0f ),
			// Left.
			Vector3( -width/2.0f,	 height/2.0f,	 depth/2.0f ),
			Vector3( -width/2.0f,	 height/2.0f,	-depth/2.0f ),
			Vector3( -width/2.0f,	-height/2.0f,	 depth/2.0f ),
			Vector3( -width/2.0f,	-height/2.0f,	-depth/2.0f ),
			// Top.
			Vector3( -width/2.0f,	 height/2.0f,	 depth/2.0f ),
			Vector3(  width/2.0f,	 height/2.0f,	 depth/2.0f ),
			Vector3( -width/2.0f,	 height/2.0f,	-depth/2.0f ),
			Vector3(  width/2.0f,	 height/2.0f,	-depth/2.0f ),
			// Bottom.
			Vector3( -width/2.0f,	-height/2.0f,	 depth/2.0f ),
			Vector3( -width/2.0f,	-height/2.0f,	-depth/2.0f ),
			Vector3(  width/2.0f,	-height/2.0f,	 depth/2.0f ),
			Vector3(  width/2.0f,	-height/2.0f,	-depth/2.0f ),
			// Front.
			Vector3( -width/2.0f,	 height/2.0f,	 depth/2.0f ),
			Vector3( -width/2.0f,	-height/2.0f,	 depth/2.0f ),
			Vector3(  width/2.0f,	 height/2.0f,	 depth/2.0f ),
			Vector3(  width/2.0f,	-height/2.0f,	 depth/2.0f ),
			// Back.
			Vector3( -width/2.0f,	 height/2.0f,	-depth/2.0f ),
			Vector3(  width/2.0f,	 height/2.0f,	-depth/2.0f ),
			Vector3( -width/2.0f,	-height/2.0f,	-depth/2.0f ),
			Vector3(  width/2.0f,	-height/2.0f,	-depth/2.0f ),
		};
		_positions.SetSize( SizeOf(positions) );
		_positions.Set( 0, positions, _positions.Size() );
	}
	UInt cnt = simple ? 1 : 6;
	for ( UInt i = 0; i < cnt; ++i )
	{
		Vector3* pos = simple ? _positions.Begin() : _positions.Begin()+i*4;
		UInt count = simple ? 24 : 4;
		ITriangleSet* face = mesh->GetSubset( i )->AsTriangleSet();
		face->SetPositions( pos, 0, count );
	}

	// Set normals.
	if ( cacheMiss )
	{
		Vector3 normals[] =
		{
			// Right (POSITIVE_X).
			Vector3::X, Vector3::X, Vector3::X, Vector3::X,
			// Left (NEGATIVE_X).
			-Vector3::X, -Vector3::X, -Vector3::X, -Vector3::X,
			// Top (POSITIVE_Y).
			Vector3::Y, Vector3::Y, Vector3::Y, Vector3::Y,
			// Bottom (NEGATIVE_Y	).
			-Vector3::Y, -Vector3::Y, -Vector3::Y, -Vector3::Y,
			// Front (POSITIVE_Z).
			Vector3::Z, Vector3::Z, Vector3::Z, Vector3::Z,
			// Back (NEGATIVE_Z).
			-Vector3::Z, -Vector3::Z, -Vector3::Z, -Vector3::Z,
		};
		_normals.SetSize( SizeOf(normals) );
		_normals.Set( 0, normals, _normals.Size() );
	}
	if ( mesh->GetScene()->IsLit() )
	{
		for ( UInt i = 0; i < cnt; ++i )
		{
			Vector3* norm = simple ? _normals.Begin() : _normals.Begin()+i*4;
			UInt count = simple ? 24 : 4;
			ITriangleSet* face = mesh->GetSubset( i )->AsTriangleSet();
			face->SetNormals( norm, 0, count );
		}
	}

	// Set texture coordinates.
	if ( cacheMiss )
	{
		Vector2 coordinates[] = 
		{
			// Right.
			Vector2( 0.0f, 0.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 1.0f ),
			// Left.
			Vector2( 0.0f, 0.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 1.0f ),
			// Top.
			Vector2( 1.0f, 1.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 0.0f, 0.0f ),
			// Bottom.
			Vector2( 1.0f, 1.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 0.0f, 0.0f ),
			// Front.
			Vector2( 0.0f, 0.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 1.0f ),
			// Back.
			Vector2( 0.0f, 0.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 1.0f ),
		};
		_coordinates.SetSize( SizeOf(coordinates) );
		_coordinates.Set( 0, coordinates, _coordinates.Size() );
	}
	for ( UInt i = 0; i < cnt; ++i )
	{
		Vector2* coords = simple ? _coordinates.Begin() : _coordinates.Begin()+i*4;
		UInt count = simple ? 24 : 4;
		ITriangleSet* face = mesh->GetSubset( i )->AsTriangleSet();
		face->SetTextureCoordinates( coords, 0, count );
	}

	// Set indices.
	if ( cacheMiss )
	{
		UInt indices[] =
		{
			// Right.
			0,   1,  2,  1,  3,  2,
			// Left.
			4,   5,  6,  5,  7,  6,
			// Top.
			8,   9, 10,  9, 11, 10,
			// Bottom.
			12, 13, 14, 13, 15, 14,
			// Front.
			16, 17, 18, 17, 19, 18,
			// Back.
			20, 21, 22, 21, 23, 22,
		};
		_indices.SetSize( SizeOf(indices) );
		_indices.Set( 0, indices, _indices.Size() );
	}
	UInt tmp[6];
	for ( UInt i = 0; i < cnt; ++i )
	{
		for ( UInt k = 0; k < 6; ++k )
		{
			tmp[k] = _indices[i*6 + k] - i*4;
		}
		UInt* idx = simple ? _indices.Begin() : tmp;
		UInt count = simple ? 36 : 6;
		ITriangleSet* face = mesh->GetSubset( i )->AsTriangleSet();
		face->SetIndices( idx, 0, count );
	}
}


} // scene


} // synkro
