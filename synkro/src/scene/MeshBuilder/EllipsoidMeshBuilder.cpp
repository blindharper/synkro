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
// Purpose: Ellipsoid mesh builder.
//==============================================================================
#include "config.h"
#include "EllipsoidMeshBuilder.h"
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


EllipsoidMeshBuilder::EllipsoidMeshBuilder()
{
}

void EllipsoidMeshBuilder::Build( IPointMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float radiusX = param1.x;
	const Float radiusY = param1.y;
	const Float radiusZ = param1.z;
	const UInt stackCount = param2.Width;
	const UInt sliceCount = param2.Height;

	// Create mesh.
	const UInt vertexCount = (stackCount+1)*(sliceCount+1);
	IPointSet* ellipsoid = mesh->CreatePointList( String::Format(L"Ellipsoid {0}", mesh->GetSubsetCount()), vertexCount, 1.0f, ColorMode::Monochrome, transform );

	// Set positions.
	const Float drho = Math::Pi/CastFloat(stackCount);
	const Float dtheta = Math::TwoPi/CastFloat(sliceCount);
	Vector<Vector3> positions( A(Vector3), vertexCount );
	for ( UInt i = 0; i <= stackCount; ++i )
	{
		const Float rho = CastFloat(i)*drho;
		const Float sinRho = Math::Sin( rho );
		const Float cosRho = Math::Cos( rho );

		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(radiusX*sinTheta*sinRho, radiusY*cosRho, radiusZ*cosTheta*sinRho) );
		}
	}
	ellipsoid->SetPositions( positions.Begin(), 0, positions.Size() );
}

void EllipsoidMeshBuilder::Build( ILineMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float radiusX = param1.x;
	const Float radiusY = param1.y;
	const Float radiusZ = param1.z;
	const UInt stackCount = param2.Width;
	const UInt sliceCount = param2.Height;

	// Create mesh.
	const UInt vertexCount = (stackCount+1)*(sliceCount+1);
	const UInt indexCount = 4*sliceCount*sliceCount;
	ILineSet* ellipsoid = mesh->CreateLineList( String::Format(L"Ellipsoid {0}", mesh->GetSubsetCount()), vertexCount, indexCount, false, ColorMode::Monochrome, transform );

	// Set positions.
	const Float drho = Math::Pi/CastFloat(stackCount);
	const Float dtheta = Math::TwoPi/CastFloat(sliceCount);
	Vector<Vector3> positions( A(Vector3), vertexCount );
	Vector<UInt> indices( A(UInt), indexCount );
	UInt line[2] = {};
	for ( UInt i = 0; i <= stackCount; ++i )
	{
		const Float rho = CastFloat(i)*drho;
		const Float sinRho = Math::Sin( rho );
		const Float cosRho = Math::Cos( rho );

		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(radiusX*sinTheta*sinRho, radiusY*cosRho, radiusZ*cosTheta*sinRho) );

			if ( (i < stackCount) && (j < sliceCount) )
			{
				const UInt idx1 = i*(sliceCount+1)+j;
				line[0] = idx1;
				line[1] = idx1+1;
				indices.Add( line, 2 );

				const UInt idx2 = (i+1)*(sliceCount+1)+j;
				line[0] = idx1;
				line[1] = idx2;
				indices.Add( line, 2 );
			}
		}
	}
	ellipsoid->SetPositions( positions.Begin(), 0, positions.Size() );
	ellipsoid->SetIndices( indices.Begin(), 0, indices.Size() );
}

void EllipsoidMeshBuilder::Build( ITriangleMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float radiusX = param1.x;
	const Float radiusY = param1.y;
	const Float radiusZ = param1.z;
	const UInt stackCount = param2.Width;
	const UInt sliceCount = param2.Height;

	// Create/resize mesh.
	const UInt vertexCount = (stackCount+1)*(sliceCount+1);
	const UInt indexCount = 6*stackCount*sliceCount;
	ITriangleSet* ellipsoid = mesh->CreateTriangleList( String::Format(L"Ellipsoid {0}", mesh->GetSubsetCount()), vertexCount, indexCount, false, transform );

	// Set positions, texture coordinates and indices.
	const Float drho = Math::Pi/CastFloat(stackCount);
	const Float dtheta = Math::TwoPi/CastFloat(sliceCount);
	const Float ds = 1.0f/CastFloat(sliceCount);
	const Float dt = 1.0f/CastFloat(stackCount);
	Float s = 0.0f;
	Float t = 0.0f;
	Vector<Vector3> positions( A(Vector3), vertexCount );
	Vector<Vector2> coords( A(Vector2), vertexCount );
	Vector<UInt> indices( A(UInt), indexCount );
	UInt quad[6] = {};
	for ( UInt i = 0; i <= stackCount; ++i )
	{
		const Float rho = CastFloat(i)*drho;
		const Float sinRho = Math::Sin( rho );
		const Float cosRho = Math::Cos( rho );

		s = 0.0f;
		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(radiusX*sinTheta*sinRho, radiusY*cosRho, radiusZ*cosTheta*sinRho) );
			coords.Add( Vector2(1.0f-s, t) );
			s += ds;

			if ( (i < stackCount) && (j < sliceCount) )
			{
				const UInt idx2 = i*(sliceCount+1)+j;
				const UInt idx1 = idx2+sliceCount+2;

				quad[0] = idx1-1;
				quad[1] = idx1;
				quad[2] = idx2;

				quad[3] = idx2;
				quad[4] = idx1;
				quad[5] = idx2+1;

				indices.Add( quad, 6 );
			}
		}
		t += dt;
	}
	ellipsoid->SetPositions( positions.Begin(), 0, positions.Size() );
	ellipsoid->SetTextureCoordinates( coords.Begin(), 0, coords.Size() );
	ellipsoid->SetIndices( indices.Begin(), 0, indices.Size() );

	// Set normals.
	if ( mesh->GetScene()->IsLit() )
	{
		Vector<Vector3> normals( A(Vector3) );
		normals.SetSize( positions.Size() );
		GenerateNormals( indices.Begin(), indices.Size(), positions.Begin(), normals.Begin(), false );

		// Fix normals for coinciding positions.
		for ( UInt i = 0; i <= stackCount; ++i )
		{
			const UInt idx1 = i*(sliceCount+1);
			const UInt idx2 = idx1+sliceCount;
			const Vector3 norm1 = normals[idx1];
			const Vector3 norm2 = normals[idx2];
			const Vector3 norm = (norm1+norm2)/2.0f;
			normals[idx1] = normals[idx2] = norm;
		}

		ellipsoid->SetNormals( normals.Begin(), 0, normals.Size() );
	}
}


} // scene


} // synkro
