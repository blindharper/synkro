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
// Purpose: Cone mesh builder.
//==============================================================================
#include "config.h"
#include "ConeMeshBuilder.h"
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


ConeMeshBuilder::ConeMeshBuilder()
{
}

void ConeMeshBuilder::Build( IPointMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float radius = param1.x;
	const Float height = param1.y;
	const UInt stackCount = param2.Width;
	const UInt sliceCount = param2.Height;

	// Create mesh.
	const UInt vertexCount = (stackCount+1)*(sliceCount+1);
	IPointSet* cone = mesh->CreatePointList( String::Format(L"Cone {0}", mesh->GetSubsetCount()), vertexCount, 1.0f, ColorMode::Monochrome, transform );

	// Set positions.
	const Float dtheta = Math::TwoPi/CastFloat(sliceCount);
	const Float dy = height/CastFloat(stackCount);
	const Float y = -0.5f*height;
	Float r = 0.0f;
	Vector<Vector3> positions( A(Vector3), vertexCount );
	for ( UInt i = 0; i <= stackCount; ++i )
	{
		r = Lerp( radius, 0.0f, CastDouble(i)/CastDouble(stackCount) );
		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = -Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(r*sinTheta, y+i*dy, r*cosTheta) );
		}
	}
	cone->SetPositions( positions.Begin(), 0, positions.Size() );
}

void ConeMeshBuilder::Build( ILineMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float radius = param1.x;
	const Float height = param1.y;
	const UInt stackCount = param2.Width;
	const UInt sliceCount = param2.Height;

	// Create mesh.
	const UInt vertexCount = (stackCount+1)*(sliceCount+1);
	const UInt indexCount = 2*sliceCount + 2*sliceCount*sliceCount;
	ILineSet* cone = mesh->CreateLineList( String::Format(L"Cone {0}", mesh->GetSubsetCount()), vertexCount, indexCount, false, ColorMode::Monochrome, transform );

	// Set positions.
	const Float dtheta = Math::TwoPi/CastFloat(sliceCount);
	const Float dy = height/CastFloat(stackCount);
	const Float y = -0.5f*height;
	Float r = 0.0f;
	Vector<Vector3> positions( A(Vector3), vertexCount );
	Vector<UInt> indices( A(UInt), indexCount );
	UInt line[2] = {};
	for ( UInt i = 0; i <= stackCount; ++i )
	{
		r = Lerp( radius, 0.0f, CastDouble(i)/CastDouble(stackCount) );
		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = -Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(r*sinTheta, y+i*dy, r*cosTheta) );

			if ( (i < stackCount) && (j < sliceCount) )
			{
				UInt idx1 = i*(sliceCount+1)+j;
				line[0] = idx1;
				line[1] = idx1+1;
				indices.Add( line, 2 );
			}
		}
	}
	cone->SetPositions( positions.Begin(), 0, positions.Size() );

	for ( UInt j = 0; j <= sliceCount; ++j )
	{
		const UInt idx1 = vertexCount-1;
		const UInt idx2 = j;
		line[0] = idx1;
		line[1] = idx2;
		indices.Add( line, 2 );
	}
	cone->SetIndices( indices.Begin(), 0, indices.Size() );
}

void ConeMeshBuilder::Build( ITriangleMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float radius = param1.x;
	const Float height = param1.y;
	const UInt stackCount = param2.Width;
	const UInt sliceCount = param2.Height;

	// Create mesh.
	const UInt vertexCount = (stackCount+1)*(sliceCount+1)+1;
	const UInt indexCount = 6*stackCount*sliceCount+1*(3*sliceCount);
	ITriangleSet* cone = mesh->CreateTriangleList( String::Format(L"Cone {0}", mesh->GetSubsetCount()), vertexCount, indexCount, false, transform );

	// Set positions, texture coordinates and indices.
	const Float dtheta = Math::TwoPi/CastFloat(sliceCount);
	const Float dy = height/CastFloat(stackCount);
	const Float ds = 1.0f/CastFloat(sliceCount);
	const Float dt = 1.0f/CastFloat(stackCount);
	const Float y = -0.5f*height;
	Float s = 0.0f;
	Float t = 0.0f;
	Float r = 0.0f;
	Vector<Vector3> positions( A(Vector3), vertexCount );
	Vector<Vector2> coords( A(Vector2), vertexCount );
	Vector<UInt> indices( A(UInt), indexCount );
	UInt quad[6] = {};
	for ( UInt i = 0; i <= stackCount; ++i )
	{
		s = 0.0f;
		r = Lerp( radius, 0.0f, CastDouble(i)/CastDouble(stackCount) );
		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = -Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(r*sinTheta, y+i*dy, r*cosTheta) );
			coords.Add( Vector2(s, t) );
			s += ds;

			if ( (i < stackCount) && (j < sliceCount) )
			{
				const UInt idx2 = i*(sliceCount+1)+j;
				const UInt idx1 = idx2+sliceCount+2;

				quad[0] = idx1-1;
				quad[1] = idx1;
				quad[2] = idx2;

				quad[3] = idx2+1;
				quad[4] = idx2;
				quad[5] = idx1;

				indices.Add( quad, 6 );
			}
		}
		t += dt;
	}

	positions.Add( Vector3(0.0f, y, 0.0f) );
	coords.Add( Vector2(0.5f, 0.5f) );
	const UInt idxBottom = positions.Size()-1;

	UInt face[3] = {};
	for ( UInt j = 0; j < sliceCount; ++j )
	{
		const UInt idx2 = j;
		face[0] = idxBottom;
		face[1] = idx2;
		face[2] = idx2+1;
		indices.Add( face, 3 );
	}

	cone->SetPositions( positions.Begin(), 0, positions.Size() );
	cone->SetTextureCoordinates( coords.Begin(), 0, coords.Size() );
	cone->SetIndices( indices.Begin(), 0, indices.Size() );

	// Set normals.
	if ( mesh->GetScene()->IsLit() )
	{
		Vector<Vector3> normals( A(Vector3) );
		normals.SetSize( positions.Size() );
		GenerateNormals( indices.Begin(), indices.Size(), positions.Begin(), normals.Begin(), false );
		cone->SetNormals( normals.Begin(), 0, normals.Size() );
	}
}


} // scene


} // synkro
