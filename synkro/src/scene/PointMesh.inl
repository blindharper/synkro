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
// Purpose: Point mesh implementation.
//==============================================================================
SYNKRO_INLINE IPointMesh* PointMesh::AsPoint() const
{
	return (IPointMesh*)this;
}

SYNKRO_INLINE IPointMeshBatch* PointMesh::AsBatch() const
{
	return nullptr;
}
