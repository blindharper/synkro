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
// Purpose: Triangle mesh list implementation.
//==============================================================================
SYNKRO_INLINE void TriangleMeshList::SetSize( UInt size )
{
	_meshes.SetSize( size );
}

SYNKRO_INLINE void TriangleMeshList::Add( scene::ITriangleMesh* mesh )
{
	_meshes.Add( mesh );
}

SYNKRO_INLINE void TriangleMeshList::Set( UInt index, scene::ITriangleMesh* mesh )
{
	assert( index < _meshes.Size() );

	if ( index >= _meshes.Size() )
		throw lang::OutOfRangeException( index, _meshes.Size() );

	_meshes[index] = mesh;
}

SYNKRO_INLINE UInt TriangleMeshList::GetSize() const
{
	return _meshes.Size();
}

SYNKRO_INLINE scene::ITriangleMesh* TriangleMeshList::Get( UInt index ) const
{
	assert( index < _meshes.Size() );

	if ( index >= _meshes.Size() )
		throw lang::OutOfRangeException( index, _meshes.Size() );

	return _meshes[index];
}
