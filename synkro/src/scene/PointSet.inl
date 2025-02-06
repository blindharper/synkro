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
// Purpose: Implements point set.
//==============================================================================
SYNKRO_INLINE void PointSet::Show( Bool show )
{
	_object->Enable( show );
}

SYNKRO_INLINE void PointSet::SetElementRange( const lang::Range& range )
{
	_object->SetElementRange( range.Start, range.Length );
}

SYNKRO_INLINE void PointSet::SetInstanceRange( const lang::Range& range )
{
	_object->SetInstanceRange( range.Start, range.Length );
}

SYNKRO_INLINE void PointSet::SetTransform( const math::Matrix4x4& transform )
{
	_transform = transform;
}

SYNKRO_INLINE void PointSet::SetOwnerTransform( const math::Matrix4x4& transform )
{
	if ( _paramTransform != nullptr )
	{
		math::Matrix4x4 worldTransform = transform * _transform;
		_object->GetVertexParameters()->Set( _paramTransform, worldTransform );
	}
}

SYNKRO_INLINE void PointSet::Resize( UInt vertexCount, UInt indexCount )
{
	_object->GetData()->Resize( vertexCount, indexCount, _object->GetData()->GetInstanceCount() );
}

SYNKRO_INLINE Bool PointSet::IsVisible() const
{
	return _object->IsEnabled();
}

SYNKRO_INLINE void PointSet::GetElementRange( lang::Range& range ) const
{
	range.Start = _object->GetStartElement();
	range.Length = _object->GetElementCount();
}

SYNKRO_INLINE void PointSet::GetInstanceRange( lang::Range& range ) const
{
	range.Start = _object->GetStartInstance();
	range.Length = _object->GetInstanceCount();
}

SYNKRO_INLINE UInt PointSet::GetVertexCount() const
{
	return _object->GetData()->GetVertexCount();
}

SYNKRO_INLINE UInt PointSet::GetIndexCount() const
{
	return _object->GetData()->GetIndexCount();
}

SYNKRO_INLINE UInt PointSet::GetElementCount() const
{
	gfx::IPrimitive* data = _object->GetData();
	return (data->GetIndexCount() > 0) ? data->GetIndexCount() : data->GetVertexCount();
}

SYNKRO_INLINE void PointSet::GetTransform( math::Matrix4x4& transform ) const
{
	transform = _transform;
}

SYNKRO_INLINE void PointSet::GetCenter( math::Vector3& center ) const
{
	center = _center;
}

SYNKRO_INLINE Float PointSet::GetBoundSphere() const
{
	return _boundSphere;
}

SYNKRO_INLINE IPointSet* PointSet::AsPointSet() const
{
	return (IPointSet*)this;
}

SYNKRO_INLINE ILineSet* PointSet::AsLineSet() const
{
	return nullptr;
}

SYNKRO_INLINE ITriangleSet* PointSet::AsTriangleSet() const
{
	return nullptr;
}

SYNKRO_INLINE void PointSet::SetColor( const img::Color& color )
{
	if ( _paramColor != nullptr )
	{
		_object->GetVertexParameters()->Set( _paramColor, ToVector(color) );
	}
}

SYNKRO_INLINE Float PointSet::GetPointSize() const
{
	return _size;
}
