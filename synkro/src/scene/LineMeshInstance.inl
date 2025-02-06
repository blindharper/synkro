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
// Purpose: Line mesh node instance implementation.
//==============================================================================
SYNKRO_INLINE void LineMeshInstance::Show( Bool show )
{
	_visible = show;
}

SYNKRO_INLINE UInt LineMeshInstance::GetSubsetCount() const
{
	return _batch->GetSubsetCount();
}

SYNKRO_INLINE lang::String LineMeshInstance::GetSubsetName( UInt index ) const
{
	return _batch->GetSubsetName( index );
}

SYNKRO_INLINE IPrimitive* LineMeshInstance::GetSubset( UInt index ) const
{
	return _batch->GetSubset( index );
}

SYNKRO_INLINE IPrimitive* LineMeshInstance::GetSubset( const lang::String& name ) const
{
	return _batch->GetSubset( name );
}

SYNKRO_INLINE void LineMeshInstance::GetCenter( math::Vector3& center ) const
{
	_batch->GetCenter( center );
}

SYNKRO_INLINE Float LineMeshInstance::GetBoundSphere() const
{
	return _batch->GetBoundSphere();
}

SYNKRO_INLINE Bool LineMeshInstance::IsVisible() const
{
	return _visible;
}

SYNKRO_INLINE ILineMesh* LineMeshInstance::AsLine() const
{
	return (ILineMesh*)this;
}

SYNKRO_INLINE IPointMesh* LineMeshInstance::AsPoint() const
{
	return nullptr;
}

SYNKRO_INLINE ITriangleMesh* LineMeshInstance::AsTriangle() const
{
	return nullptr;
}

SYNKRO_INLINE ILineMeshBatch* LineMeshInstance::AsBatch() const
{
	return nullptr;
}

SYNKRO_INLINE ILineSet* LineMeshInstance::CreateLineList( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform )
{
	return _batch->CreateLineList( name, vertexCount, indexCount, adjacency, colorMode, transform );
}

SYNKRO_INLINE ILineSet* LineMeshInstance::CreateLineList4D( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform )
{
	throw lang::NotSupportedException();
}

SYNKRO_INLINE ILineSet* LineMeshInstance::CreateLineStrip( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform )
{
	return _batch->CreateLineStrip( name, vertexCount, indexCount, adjacency, colorMode, transform );
}

SYNKRO_INLINE ILineSet* LineMeshInstance::CreateLineSet( const lang::String& name, const lang::Range& range )
{
	return _batch->CreateLineSet( name, range );
}

SYNKRO_INLINE void LineMeshInstance::SetColor( const img::Color& color )
{
	_batch->SetColor( color );
}
