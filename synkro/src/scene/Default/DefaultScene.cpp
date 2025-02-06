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
// Purpose: Default scene implementation.
//==============================================================================
#include "config.h"
#include "DefaultScene.h"
#include "DefaultTriangleMesh.h"
#include "DefaultTriangleMeshBatch.h"
#include <math/Intersection.h>


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


DefaultScene::DefaultScene( ISceneRenderQueue* queue, Bool lit ) :
	_queue( queue ),
	_meshes( A(ITriangleMesh*) ),
	_lit( lit )
{
}

ITriangleMesh* DefaultScene::CreateTriangleMesh( INode* parent, const String& name, IVisualMaterial* material, ISkeleton* skeleton )
{
	ITriangleMesh* mesh = new DefaultTriangleMesh( this, material, skeleton );
	_meshes.Add( mesh );
	return mesh;
}

ITriangleMeshBatch* DefaultScene::CreateTriangleMeshBatch( IVisualMaterial* material, ISkeleton* skeleton, UInt capacity )
{
	DefaultTriangleMeshBatch* batch = new DefaultTriangleMeshBatch( this, material, skeleton, capacity );
	// NB: _batches.Add( batch );
	return batch;
}

ITriangleMesh* DefaultScene::PickMesh( const Vector3& origin, const Vector3& direction, Float* distance ) const
{
	ITriangleMesh* res = nullptr;
	Float minDistance = Math::MaxFloat;

	for ( UInt m = 0; m < _meshes.Size(); ++m )
	{
		ITriangleMesh* mesh = _meshes[m];
		if ( mesh->IsVisible() )
		{
			Matrix4x4 trans; mesh->GetWorldTransform( trans );
			trans = trans.Inverse();
			const Vector3 org = trans * origin;
			const Vector3 dir = trans.Rotate( direction );
			const Float dp = org*dir;
			const Float dist = (org - dir*dp).Length();

			// Explore mesh subsets.
			for ( UInt i = 0; i < mesh->GetSubsetCount(); ++i )
			{
				ITriangleSet* subset = mesh->GetSubset( i )->AsTriangleSet();
				if ( dist < subset->GetBoundSphere() )
				{
					UInt face[3]; Vector3 v[3];
					for ( UInt j = 0; j < subset->GetIndexCount(); j+=3 )
					{
						// Get face vertices.
						subset->GetIndices( face, j, 3 );
						for ( UInt k = 0; k < 3; ++k )
						{
							subset->GetPositions( &v[k], face[k], 1 );
						}

						// See if the face is valid.
						Bool facing = false;
						Bool valid = true;
						const Vector3 edge1 = v[2] - v[0];
						const Vector3 edge2 = v[1] - v[0];
						const Vector3 normal = edge1 ^ edge2;
						const Float n2 = normal.LengthSquared();
						if ( n2 > 1e-8f )
						{
							facing = ((normal*dir) < 0.0f);
						}
						else
						{
							valid = false;
						}

						// Test face.
						if ( facing && valid )
						{
							Float d = 0.0f;
							if ( Intersection::TestRayAndTriangle(org, dir, v[0], v[1], v[2], &d) )
							{
								if ( d < minDistance )
								{
									minDistance = d;
									res = mesh;
								}
							}
						}
					}
				}
			}
		}
	}

	if ( distance != nullptr )
	{
		*distance = minDistance;
	}

	return res;
}

ISceneRenderQueue* DefaultScene::GetRenderQueue() const
{
	return _queue;
}

Bool DefaultScene::IsLit() const
{
	return _lit;
}

void DefaultScene::RemoveMesh( ITriangleMesh* mesh )
{
	assert( mesh != nullptr );

	_meshes.Remove( mesh );
}


} // scene


} // synkro
