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
// Purpose: Capsule mesh builder.
//==============================================================================
#include "config.h"
#include "CapsuleMeshBuilder.h"
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


CapsuleMeshBuilder::CapsuleMeshBuilder()
{
}

void CapsuleMeshBuilder::Build( IPointMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float radius = param1.x;
	const Float height = param1.y;
	const UInt stackCount = (param2.Width > 1) ? (param2.Width/2)*2 : 2;
	const UInt sliceCount = param2.Height;

	// Set positions.
	const UInt stackCount2 = stackCount/2;
	const Float drho = Math::Pi/CastFloat(stackCount);
	const Float dtheta = Math::TwoPi/CastFloat(sliceCount);
	Vector<Vector3> positions( A(Vector3), 2*(stackCount+1)*(sliceCount+1) );

	// Top cap.
	for ( UInt i = 0; i <= stackCount2; ++i )
	{
		const Float rho = CastFloat(i)*drho;
		const Float sinRho = Math::Sin( rho );
		const Float cosRho = Math::Cos( rho );

		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(radius*sinTheta*sinRho, radius*cosRho+0.5f*height, radius*cosTheta*sinRho) );
		}
	}

	// Lateral side.
	const Float dy = height/CastFloat(stackCount);
	const Float y = 0.5f*height;
	for ( UInt i = 0; i <= stackCount; ++i )
	{
		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(radius*sinTheta, y-i*dy, radius*cosTheta) );
		}
	}

	// Bottom cap.
	for ( UInt i = 0; i <= stackCount2; ++i )
	{
		const Float rho = Math::HalfPi+CastFloat(i)*drho;
		const Float sinRho = Math::Sin( rho );
		const Float cosRho = Math::Cos( rho );

		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(radius*sinTheta*sinRho, radius*cosRho-0.5f*height, radius*cosTheta*sinRho) );
		}
	}

	// Create mesh.
	IPointSet* capsule = mesh->CreatePointList( String::Format(L"Capsule {0}", mesh->GetSubsetCount()), positions.Size(), 1.0f, ColorMode::Monochrome, transform );
	capsule->SetPositions( positions.Begin(), 0, positions.Size() );
}

void CapsuleMeshBuilder::Build( ILineMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float radius = param1.x;
	const Float height = param1.y;
	const UInt stackCount = (param2.Width > 1) ? (param2.Width/2)*2 : 2;
	const UInt sliceCount = param2.Height;

	// Set positions.
	const UInt stackCount2 = stackCount/2;
	const Float drho = Math::Pi/CastFloat(stackCount);
	const Float dtheta = Math::TwoPi/CastFloat(sliceCount);
	Vector<Vector3> positions( A(Vector3), 2*(stackCount+1)*(sliceCount+1) );
	Vector<UInt> indices( A(UInt), 8*stackCount*sliceCount );
	UInt line[2] = {};

	// Top cap.
	for ( UInt i = 0; i <= stackCount2; ++i )
	{
		const Float rho = CastFloat(i)*drho;
		const Float sinRho = Math::Sin( rho );
		const Float cosRho = Math::Cos( rho );

		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(radius*sinTheta*sinRho, radius*cosRho+0.5f*height, radius*cosTheta*sinRho) );

			if ( (i < stackCount2) && (j < sliceCount) )
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

	// Lateral surface.
	const Float dy = height/CastFloat(stackCount);
	const Float y = 0.5f*height;
	UInt idx0 = positions.Size();
	for ( UInt i = 0; i <= stackCount; ++i )
	{
		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(radius*sinTheta, y-i*dy, radius*cosTheta) );

			if ( (i < stackCount+1) && (j < sliceCount) )
			{
				const UInt idx1 = idx0+i*(sliceCount+1)+j;
				line[0] = idx1;
				line[1] = idx1+1;
				indices.Add( line, 2 );

				if ( (i < stackCount) && (j<sliceCount) )
				{
					const UInt idx2 = idx0+(i+1)*(sliceCount+1)+j;
					line[0] = idx1;
					line[1] = idx2;
					indices.Add( line, 2 );
				}
			}
		}
	}

	// Bottom cap.
	idx0 = positions.Size();
	for ( UInt i = 0; i <= stackCount2; ++i )
	{
		const Float rho = Math::HalfPi+CastFloat(i)*drho;
		const Float sinRho = Math::Sin( rho );
		const Float cosRho = Math::Cos( rho );

		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(radius*sinTheta*sinRho, radius*cosRho-0.5f*height, radius*cosTheta*sinRho) );

			if ( (i < stackCount2) && (j < sliceCount) )
			{
				const UInt idx1 = idx0+i*(sliceCount+1)+j;
				line[0] = idx1;
				line[1] = idx1+1;
				indices.Add( line, 2 );

				if ( (i < stackCount2) && (j < sliceCount) )
				{
					const UInt idx2 = idx0+(i+1)*(sliceCount+1)+j;
					line[0] = idx1;
					line[1] = idx2;
					indices.Add( line, 2 );
				}
			}
		}
	}

	// Create mesh.
	ILineSet* capsule = mesh->CreateLineList( String::Format(L"Capsule {0}", mesh->GetSubsetCount()), positions.Size(), indices.Size(), false, ColorMode::Monochrome, transform );
	capsule->SetPositions( positions.Begin(), 0, positions.Size() );
	capsule->SetIndices( indices.Begin(), 0, indices.Size() );
}

void CapsuleMeshBuilder::Build( ITriangleMesh* mesh, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	// Get parameters.
	const Float radius = param1.x;
	const Float height = param1.y;
	const UInt stackCount = (param2.Width > 1) ? (param2.Width/2)*2 : 2;
	const UInt sliceCount = param2.Height;

	// Set positions.
	const UInt stackCount2 = stackCount/2;
	const Float drho = Math::Pi/CastFloat(stackCount);
	const Float dtheta = Math::TwoPi/CastFloat(sliceCount);
	const Float ds = 1.0f/CastFloat(sliceCount);
	const Float dt = 1.0f/CastFloat(2*stackCount);
	Float s = 0.0f;
	Float t = 0.0f;
	Vector<Vector3> positions( A(Vector3), 2*(stackCount+1)*(sliceCount+1) );
	Vector<Vector2> coords( A(Vector2), 2*(stackCount+1)*(sliceCount+1) );
	Vector<UInt> indices( A(UInt), 8*stackCount*sliceCount );
	UInt quad[6] = {};

	// Top cap.
	t = 0.0f;
	for ( UInt i = 0; i <= stackCount2; ++i )
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
			positions.Add( Vector3(radius*sinTheta*sinRho, radius*cosRho+0.5f*height, radius*cosTheta*sinRho) );
			coords.Add( Vector2(1.0f-s, t) );
			s += ds;

			if ( (i < stackCount2) && (j < sliceCount) )
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

	// Lateral surface.
	const Float dy = height/CastFloat(stackCount);
	const Float y = 0.5f*height;
	UInt idx0 = positions.Size();
	for ( UInt i = 0; i <= stackCount; ++i )
	{
		s = 0.0f;
		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(radius*sinTheta, y-i*dy, radius*cosTheta) );
			coords.Add( Vector2(1.0f-s, t) );
			s += ds;

			if ( (i < stackCount) && (j < sliceCount) )
			{
				const UInt idx2 = idx0+i*(sliceCount+1)+j;
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

	// Bottom cap.
	idx0 = positions.Size();
	for ( UInt i = 0; i <= stackCount2; ++i )
	{
		const Float rho = Math::HalfPi+CastFloat(i)*drho;
		const Float sinRho = Math::Sin( rho );
		const Float cosRho = Math::Cos( rho );

		s = 0.0f;
		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(radius*sinTheta*sinRho, radius*cosRho-0.5f*height, radius*cosTheta*sinRho) );
			coords.Add( Vector2(1.0f-s, t) );
			s += ds;

			if ( (i < stackCount2) && (j < sliceCount) )
			{
				const UInt idx2 = idx0+i*(sliceCount+1)+j;
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

	// Create mesh.
	ITriangleSet* capsule = mesh->CreateTriangleList( String::Format(L"Capsule {0}", mesh->GetSubsetCount()), positions.Size(), indices.Size(), false, transform );
	capsule->SetPositions( positions.Begin(), 0, positions.Size() );
	capsule->SetTextureCoordinates( coords.Begin(), 0, coords.Size() );
	capsule->SetIndices( indices.Begin(), 0, indices.Size() );

	// Set normals.
	if ( mesh->GetScene()->IsLit() )
	{
		Vector<Vector3> normals( A(Vector3) );
		normals.SetSize( positions.Size() );
		GenerateNormals( indices.Begin(), indices.Size(), positions.Begin(), normals.Begin(), false );
		capsule->SetNormals( normals.Begin(), 0, normals.Size() );
	}
}


} // scene


} // synkro
