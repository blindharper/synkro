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
// Purpose: Plane mesh builder.
//==============================================================================
#include "config.h"
#include "PlaneMeshBuilder.h"
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


PlaneMeshBuilder::PlaneMeshBuilder()
{
}

void PlaneMeshBuilder::Build( IPointMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float width = param1.x;
	const Float depth = param1.y;
	const UInt segmentCount = param2.Width;

	// Create mesh.
	const UInt vertexCount = (segmentCount+1)*(segmentCount+1);
	IPointSet* grid = mesh->CreatePointList( String::Format(L"Grid {0}", mesh->GetSubsetCount()), vertexCount, 1.0f, ColorMode::Monochrome, transform );

	// Set positions.
	Vector<Vector3> positions( A(Vector3), vertexCount );
	Float x = -width/2.0f;
	const Float dx = width/segmentCount;
	for ( UInt i = 0; i <= segmentCount; ++i )
	{
		Float z = -depth/2.0f;
		const Float dz = depth/segmentCount;
		for ( UInt j = 0; j <= segmentCount; ++j )
		{
			positions.Add( Vector3(x, 0.0f, z) );
			z += dz;
		}
		x += dx;
	}
	grid->SetPositions( positions.Begin(), 0, positions.Size() );
}

void PlaneMeshBuilder::Build( ILineMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float width = param1.x;
	const Float depth = param1.y;
	const UInt segmentCount = param2.Width;

	// Create mesh.
	const UInt vertexCount = 4*(segmentCount+1);
	ILineSet* grid = mesh->CreateLineList( String::Format(L"Grid {0}", mesh->GetSubsetCount()), vertexCount, 0, false, ColorMode::Monochrome, transform );

	// Set positions.
	Vector<Vector3> positions( A(Vector3), vertexCount );
	Float x = -width/2.0f;
	const Float dx = width/segmentCount;
	for ( UInt i = 0; i <= segmentCount; ++i )
	{
		positions.Add( Vector3(x, 0.0f, depth/2.0f) );
		positions.Add( Vector3(x, 0.0f, -depth/2.0f) );
		x += dx;
	}

	Float z = -depth/2.0f;
	const Float dz = depth/segmentCount;
	for ( UInt i = 0; i <= segmentCount; ++i )
	{
		positions.Add( Vector3(width/2.0f, 0.0f, z) );
		positions.Add( Vector3(-width/2.0f, 0.0f, z) );
		z += dz;
	}
	grid->SetPositions( positions.Begin(), 0, positions.Size() );
}

void PlaneMeshBuilder::Build( ITriangleMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float width = param1.x;
	const Float depth = param1.y;
	const UInt segmentCount = param2.Width;

	// Create mesh.
	const UInt vertexCount = (segmentCount+1)*(segmentCount+1);
	const UInt indexCount = 6*segmentCount*segmentCount;
	ITriangleSet* plane = mesh->CreateTriangleList( String::Format(L"Plane {0}", mesh->GetSubsetCount()), vertexCount, indexCount, false, transform );

	// Set positions, texture coordinates and indices.
	const Float x = -width/2.0f;
	const Float dx = width/segmentCount;
	const Float z = -depth/2.0f;
	const Float dz = depth/segmentCount;
	const Float ds = 1.0f/CastFloat(segmentCount);
	const Float dt = 1.0f/CastFloat(segmentCount);
	Float s = 0.0f;
	Float t = 0.0f;
	Vector<Vector3> positions( A(Vector3), vertexCount );
	Vector<Vector2> coords( A(Vector2), vertexCount );
	Vector<UInt> indices( A(UInt), indexCount );
	UInt quad[6] = {};
	for ( UInt j = 0; j <= segmentCount; ++j )
	{
		t = 0.0f;
		for ( UInt i = 0; i <= segmentCount; ++i )
		{
			positions.Add( Vector3(x+i*dx, 0.0f, z+j*dz) );
			coords.Add( Vector2(s, t) );

			if ( (i < segmentCount) && (j < segmentCount) )
			{
				const UInt idx1 = j*(segmentCount+1)+i;
				const UInt idx2 = idx1+segmentCount+1;

				quad[0] = idx1;
				quad[1] = idx2;
				quad[2] = idx2+1;

				quad[3] = idx1;
				quad[4] = idx2+1;
				quad[5] = idx1+1;

				indices.Add( quad, 6 );
			}
			t += dt;
		}
		s += ds;
	}
	plane->SetPositions( positions.Begin(), 0, positions.Size() );
	plane->SetTextureCoordinates( coords.Begin(), 0, coords.Size() );
	plane->SetIndices( indices.Begin(), 0, indices.Size() );

	// Set normals.
	if ( mesh->GetScene()->IsLit() )
	{
		Vector<Vector3> normals( A(Vector3) );
		normals.SetSize( positions.Size() );
		for ( UInt i = 0; i < normals.Size(); ++i )
		{
			normals[i] = Vector3( 0.0f, 1.0f, 0.0f );
		}
		plane->SetNormals( normals.Begin(), 0, normals.Size() );
	}
}


} // scene


} // synkro
