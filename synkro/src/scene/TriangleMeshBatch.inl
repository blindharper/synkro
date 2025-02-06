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
// Purpose: Triangle mesh batch implementation.
//==============================================================================
SYNKRO_INLINE ITriangleMesh* TriangleMeshBatch::AsTriangle() const
{
	return (ITriangleMesh*)this;
}

SYNKRO_INLINE ISkeleton* TriangleMeshBatch::GetSkeleton() const
{
	return _skeleton;
}

SYNKRO_INLINE mat::IVisualMaterial* TriangleMeshBatch::GetMaterial() const
{
	return _batch->GetMaterial();
}

SYNKRO_INLINE IScene* TriangleMeshBatch::GetScene() const
{
	return _scene;
}

SYNKRO_INLINE ITriangleMeshBatch* TriangleMeshBatch::AsBatch() const
{
	return (ITriangleMeshBatch*)this;
}
