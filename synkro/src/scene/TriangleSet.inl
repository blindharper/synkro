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
// Purpose: Implements triangle set.
//==============================================================================
SYNKRO_INLINE void TriangleSet::Show( Bool show )
{
	_set->Show( show );
	if ( _objectNormals != nullptr )
	{
		_objectNormals->Enable( show );
	}
}

SYNKRO_INLINE void TriangleSet::SetElementRange( const lang::Range& range )
{
	if ( !_base )
		return;

	_set->SetElementRange( range );
	if ( _objectNormals != nullptr )
	{
		_objectNormals->SetElementRange( range.Start, range.Length );
	}
}

SYNKRO_INLINE void TriangleSet::SetInstanceRange( const lang::Range& range )
{
	_set->SetInstanceRange( range );
	if ( _objectNormals != nullptr )
	{
		_objectNormals->SetInstanceRange( range.Start, range.Length );
	}
}

SYNKRO_INLINE void TriangleSet::SetTransform( const math::Matrix4x4& transform )
{
	_set->SetTransform( transform );
}

SYNKRO_INLINE void TriangleSet::SetOwnerTransform( const math::Matrix4x4& transform )
{
	_set->SetOwnerTransform( transform );
	if ( _objectNormals != nullptr )
	{
		math::Matrix4x4 trans; _set->GetTransform( trans );
		const math::Matrix4x4 worldTransform = transform * trans;
		_objectNormals->GetVertexParameters()->Set( _paramNormalsTransform, worldTransform );
	}
}

SYNKRO_INLINE void TriangleSet::SetInstanceTransform( UInt index, const math::Matrix4x4& transform )
{
	_set->SetInstanceTransform( index, transform );
}

SYNKRO_INLINE void TriangleSet::SetInstanceColor( UInt index, const img::Color& color )
{
	_set->SetInstanceColor( index, color );
}

SYNKRO_INLINE void TriangleSet::Resize( UInt vertexCount, UInt indexCount )
{
	_set->Resize( vertexCount, indexCount );
	if ( _objectNormals != nullptr )
	{
		_normals.SetSize( 2*vertexCount );
		_objectNormals->GetData()->Resize( _normals.Size(), 0, 0 );
	}
}

SYNKRO_INLINE Bool TriangleSet::IsVisible() const
{
	return _set->IsVisible();
}

SYNKRO_INLINE void TriangleSet::GetElementRange( lang::Range& range ) const
{
	_set->GetElementRange( range );
}

SYNKRO_INLINE void TriangleSet::GetInstanceRange( lang::Range& range ) const
{
	_set->GetInstanceRange( range );
}

SYNKRO_INLINE UInt TriangleSet::GetVertexCount() const
{
	return _set->GetVertexCount();
}

SYNKRO_INLINE UInt TriangleSet::GetIndexCount() const
{
	return _set->GetIndexCount();
}

SYNKRO_INLINE UInt TriangleSet::GetElementCount() const
{
	return _set->GetElementCount();
}

SYNKRO_INLINE void TriangleSet::GetTransform( math::Matrix4x4& transform ) const
{
	_set->GetTransform( transform );
}

SYNKRO_INLINE void TriangleSet::GetCenter( math::Vector3& center ) const
{
	_set->GetCenter( center );
}

SYNKRO_INLINE Float TriangleSet::GetBoundSphere() const
{
	return _set->GetBoundSphere();
}

SYNKRO_INLINE IPointSet* TriangleSet::AsPointSet() const
{
	return nullptr;
}

SYNKRO_INLINE ILineSet* TriangleSet::AsLineSet() const
{
	return nullptr;
}

SYNKRO_INLINE ITriangleSet* TriangleSet::AsTriangleSet() const
{
	return (ITriangleSet*)this;
}

SYNKRO_INLINE Bool TriangleSet::BeginSetBoneWeights()
{
	return _set->BeginSetBoneWeights();
}

SYNKRO_INLINE void TriangleSet::EndSetBoneWeights()
{
	_set->EndSetBoneWeights();
}

SYNKRO_INLINE void TriangleSet::SetColors( const img::Color* colors, UInt start, UInt count )
{
	_set->SetColors( colors, start, count );
}

SYNKRO_INLINE void TriangleSet::SetTextureCoordinates( const math::Vector2* coords, UInt start, UInt count )
{
	_set->SetTextureCoordinates( coords, start, count );
}

SYNKRO_INLINE void TriangleSet::SetIndices( const UInt* indices, UInt start, UInt count )
{
	_set->SetIndices( indices, start, count );
}

SYNKRO_INLINE void TriangleSet::SetBoneWeights( UInt index, const Byte* bones, const Float* weights, UInt count )
{
	SynkroProfile( "TriangleSet.SetBoneWeights" );

	_set->SetBoneWeights( index, bones, weights, count );
}

SYNKRO_INLINE void TriangleSet::SetBoneTransforms( const math::Matrix4x4* transforms, UInt count )
{
	SynkroProfile( "TriangleSet.SetBoneTransforms" );

	_set->SetBoneTransforms( transforms, count );
}

SYNKRO_INLINE Bool TriangleSet::GetPositions( math::Vector3* positions, UInt start, UInt count ) const
{
	throw lang::InvalidOperationException( L"Cannot get positions." );
}

SYNKRO_INLINE Bool TriangleSet::GetNormals( math::Vector3* normals, UInt start, UInt count ) const
{
	throw lang::InvalidOperationException( L"Cannot get normals." );
}

SYNKRO_INLINE Bool TriangleSet::GetColors( img::Color* colors, UInt start, UInt count ) const
{
	throw lang::InvalidOperationException( L"Cannot get colors." );
}

SYNKRO_INLINE Bool TriangleSet::GetTextureCoordinates( math::Vector2* coords, UInt start, UInt count ) const
{
	throw lang::InvalidOperationException( L"Cannot get texture coordinates." );
}

SYNKRO_INLINE Bool TriangleSet::GetIndices( UInt* indices, UInt start, UInt count ) const
{
	throw lang::InvalidOperationException( L"Cannot get indices." );
}

SYNKRO_INLINE gfx::ISceneRenderObject* TriangleSet::GetRenderObject() const
{
	return _set->GetRenderObject();
}
