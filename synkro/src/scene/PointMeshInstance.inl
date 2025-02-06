//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: http://synkro.org Email: mailto:blindharper70@gmail.com
//
// Purpose: Point mesh node instance implementation.
//==============================================================================
SYNKRO_INLINE void PointMeshInstance::Show( Bool show )
{
	_visible = show;
}

SYNKRO_INLINE UInt PointMeshInstance::GetSubsetCount() const
{
	return _batch->GetSubsetCount();
}

SYNKRO_INLINE lang::String PointMeshInstance::GetSubsetName( UInt index ) const
{
	return _batch->GetSubsetName( index );
}

SYNKRO_INLINE IPrimitive* PointMeshInstance::GetSubset( UInt index ) const
{
	return _batch->GetSubset( index );
}

SYNKRO_INLINE IPrimitive* PointMeshInstance::GetSubset( const lang::String& name ) const
{
	return _batch->GetSubset( name );
}

SYNKRO_INLINE void PointMeshInstance::GetCenter( math::Vector3& center ) const
{
	_batch->GetCenter( center );
}

SYNKRO_INLINE Float PointMeshInstance::GetBoundSphere() const
{
	return _batch->GetBoundSphere();
}

SYNKRO_INLINE Bool PointMeshInstance::IsVisible() const
{
	return _visible;
}

SYNKRO_INLINE ILineMesh* PointMeshInstance::AsLine() const
{
	return nullptr;
}

SYNKRO_INLINE IPointMesh* PointMeshInstance::AsPoint() const
{
	return (IPointMesh*)this;
}

SYNKRO_INLINE ITriangleMesh* PointMeshInstance::AsTriangle() const
{
	return nullptr;
}

SYNKRO_INLINE IPointMeshBatch* PointMeshInstance::AsBatch() const
{
	return nullptr;
}

SYNKRO_INLINE IPointMesh* PointMeshInstance::CreateInstance( INode* parent, const math::Matrix4x4& transform, const img::Color& color )
{
	return _batch->CreateInstance( parent, transform, color );
}

SYNKRO_INLINE IPointSet* PointMeshInstance::CreatePointList( const lang::String& name, UInt count, Float size, const ColorMode& colorMode, const math::Matrix4x4& transform )
{
	return _batch->CreatePointList( name, count, size, colorMode, transform );
}

SYNKRO_INLINE IPointSet* PointMeshInstance::CreatePointSet( const lang::String& name, const lang::Range& range )
{
	return _batch->CreatePointSet( name, range );
}

SYNKRO_INLINE void PointMeshInstance::SetColor( const img::Color& color )
{
	_batch->SetColor( color );
}
