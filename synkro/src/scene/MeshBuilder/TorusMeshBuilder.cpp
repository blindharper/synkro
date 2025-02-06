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
// Purpose: Torus mesh builder.
//==============================================================================
#include "config.h"
#include "TorusMeshBuilder.h"
#include <scene/ILineMesh.h>
#include <scene/IPointMesh.h>
#include <scene/ITriangleMesh.h>
#include <scene/IPointSet.h>
#include <scene/ILineSet.h>
#include <scene/ITriangleSet.h>
#include <scene/IScene.h>
#include <math/Math.h>
#include <lang/Vector.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


TorusMeshBuilder::TorusMeshBuilder()
{
}

void TorusMeshBuilder::Build( IPointMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float radiusMinor = param1.x;
	const Float radiusMajor = param1.y;
	const UInt ringCount = param2.Width;
	const UInt sideCount = param2.Height;

	// Create mesh.
	const UInt vertexCount = (ringCount+1)*(sideCount+1);
	IPointSet* torus = mesh->CreatePointList( String::Format(L"Torus {0}", mesh->GetSubsetCount()), vertexCount, 1.0f, ColorMode::Monochrome, transform );

	// Set positions.
	const Float ringDelta = Math::TwoPi/CastFloat(ringCount);
	const Float sideDelta = Math::TwoPi/CastFloat(sideCount);
	Vector<Vector3> positions( A(Vector3), vertexCount );
	for ( UInt i = 0; i <= ringCount; ++i )
	{
		const Float theta = i*ringDelta;
		const Float cosTheta = Math::Cos( theta );
		const Float sinTheta = Math::Sin( theta );

		for ( UInt j = 0; j <= sideCount; ++j )
		{
			const Float phi = j*sideDelta;
			const Float cosPhi = Math::Cos( phi );
			const Float sinPhi = Math::Sin( phi );
			const Float dist = cosPhi*radiusMinor + radiusMajor;
			positions.Add( Vector3(dist*cosTheta, radiusMinor*sinPhi, -dist*sinTheta) );
		}
	}
	torus->SetPositions( positions.Begin(), 0, positions.Size() );
}

void TorusMeshBuilder::Build( ILineMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float radiusMinor = param1.x;
	const Float radiusMajor = param1.y;
	const UInt ringCount = param2.Width;
	const UInt sideCount = param2.Height;

	// Create mesh.
	const UInt vertexCount = (ringCount+1)*(sideCount+1);
	const UInt indexCount = 4*ringCount*sideCount;
	ILineSet* torus = mesh->CreateLineList( String::Format(L"Torus {0}", mesh->GetSubsetCount()), vertexCount, indexCount, false, ColorMode::Monochrome, transform );

	// Set positions.
	const Float ringDelta = Math::TwoPi/CastFloat(ringCount);
	const Float sideDelta = Math::TwoPi/CastFloat(sideCount);
	Vector<Vector3> positions( A(Vector3), vertexCount );
	Vector<UInt> indices( A(UInt), indexCount );
	UInt line[2] = { 0, 0 };
	for ( UInt i = 0; i <= ringCount; ++i )
	{
		const Float theta = i*ringDelta;
		const Float cosTheta = Math::Cos( theta );
		const Float sinTheta = Math::Sin( theta );

		for ( UInt j = 0; j <= sideCount; ++j )
		{
			const Float phi = j*sideDelta;
			const Float cosPhi = Math::Cos( phi );
			const Float sinPhi = Math::Sin( phi );
			const Float dist = cosPhi*radiusMinor + radiusMajor;
			positions.Add( Vector3(dist*cosTheta, radiusMinor*sinPhi, -dist*sinTheta) );

			if ( (i < ringCount) && (j < sideCount) )
			{
				UInt idx1 = i*(sideCount+1)+j;
				line[0] = idx1;
				line[1] = idx1+1;
				indices.Add( line, 2 );

				UInt idx2 = (i+1)*(sideCount+1)+j;
				line[0] = idx1;
				line[1] = idx2;
				indices.Add( line, 2 );
			}
		}
	}
	torus->SetPositions( positions.Begin(), 0, positions.Size() );
	torus->SetIndices( indices.Begin(), 0, indices.Size() );
}

void TorusMeshBuilder::Build( ITriangleMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float radiusMinor = param1.x;
	const Float radiusMajor = param1.y;
	const UInt ringCount = param2.Width;
	const UInt sideCount = param2.Height;

	// Create mesh.
	const UInt vertexCount = (ringCount+1)*(sideCount+1);
	const UInt indexCount = 6*ringCount*sideCount;
	ITriangleSet* torus = mesh->CreateTriangleList( String::Format(L"Torus {0}", mesh->GetSubsetCount()), vertexCount, indexCount, false, transform );

	// Set positions, texture coordinates and indices.
	const Float ringDelta = Math::TwoPi/CastFloat(ringCount);
	const Float sideDelta = Math::TwoPi/CastFloat(sideCount);
	const Float ds = 1.0f/CastFloat(sideCount);
	const Float dt = 1.0f/CastFloat(ringCount);
	Vector<Vector3> positions( A(Vector3), vertexCount );
	Vector<Vector2> coords( A(Vector2), vertexCount );
	Vector<UInt> indices( A(UInt), indexCount );
	UInt quad[6] = {};
	for ( UInt i = 0; i <= ringCount; ++i )
	{
		const Float theta = i*ringDelta;
		const Float cosTheta = Math::Cos( theta );
		const Float sinTheta = Math::Sin( theta );

		for ( UInt j = 0; j <= sideCount; ++j )
		{
			const Float phi = j*sideDelta;
			const Float cosPhi = Math::Cos( phi );
			const Float sinPhi = Math::Sin( phi );
			const Float dist = cosPhi*radiusMinor + radiusMajor;
			positions.Add( Vector3(dist*cosTheta, radiusMinor*sinPhi, -dist*sinTheta) );
			coords.Add( Vector2(j*ds, i*dt) );

			if ( (i < ringCount) && (j < sideCount) )
			{
				const UInt idx1 = (i+1)*(sideCount+1) + j;
				const UInt idx2 = i*(sideCount+1) + j;

				quad[0] = idx1+1;
				quad[1] = idx2;
				quad[2] = idx1;

				quad[3] = idx2+1;
				quad[4] = idx2;
				quad[5] = idx1+1;

				indices.Add( quad, 6 );
			}
		}
	}
	torus->SetPositions( positions.Begin(), 0, positions.Size() );
	torus->SetTextureCoordinates( coords.Begin(), 0, coords.Size() );
	torus->SetIndices( indices.Begin(), 0, indices.Size() );

	// Set normals.
	if ( mesh->GetScene()->IsLit() )
	{
		Vector<Vector3> normals( A(Vector3) );
		normals.SetSize( positions.Size() );
		GenerateNormals( indices.Begin(), indices.Size(), positions.Begin(), normals.Begin(), false );
		torus->SetNormals( normals.Begin(), 0, normals.Size() );
	}
}


} // scene


} // synkro
