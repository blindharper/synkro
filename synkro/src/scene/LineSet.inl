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
// Purpose: Implements line set.
//==============================================================================
SYNKRO_INLINE void LineSet::Show( Bool show )
{
	_object->Enable( show );
}

SYNKRO_INLINE void LineSet::SetElementRange( const lang::Range& range )
{
	_object->SetElementRange( range.Start, range.Length );
}

SYNKRO_INLINE void LineSet::SetInstanceRange( const lang::Range& range )
{
	_object->SetInstanceRange( range.Start, range.Length );
}

SYNKRO_INLINE void LineSet::SetTransform( const math::Matrix4x4& transform )
{
	_transform = transform;
}

SYNKRO_INLINE void LineSet::SetOwnerTransform( const math::Matrix4x4& transform )
{
	if ( _paramTransform != nullptr )
	{
		math::Matrix4x4 worldTransform = transform * _transform;
		_object->GetVertexParameters()->Set( _paramTransform, worldTransform );
	}
}

SYNKRO_INLINE void LineSet::Resize( UInt vertexCount, UInt indexCount )
{
	_object->GetData()->Resize( vertexCount, indexCount, _object->GetData()->GetInstanceCount() );
}

SYNKRO_INLINE Bool LineSet::IsVisible() const
{
	return _object->IsEnabled();
}

SYNKRO_INLINE void LineSet::GetElementRange( lang::Range& range ) const
{
	range.Start = _object->GetStartElement();
	range.Length = _object->GetElementCount();
}

SYNKRO_INLINE void LineSet::GetInstanceRange( lang::Range& range ) const
{
	range.Start = _object->GetStartInstance();
	range.Length = _object->GetInstanceCount();
}

SYNKRO_INLINE UInt LineSet::GetVertexCount() const
{
	return _object->GetData()->GetVertexCount();
}

SYNKRO_INLINE UInt LineSet::GetIndexCount() const
{
	return _object->GetData()->GetIndexCount();
}

SYNKRO_INLINE UInt LineSet::GetElementCount() const
{
	gfx::IPrimitive* data = _object->GetData();
	return (data->GetIndexCount() > 0) ? data->GetIndexCount() : data->GetVertexCount();
}

SYNKRO_INLINE void LineSet::GetTransform( math::Matrix4x4& transform ) const
{
	transform = _transform;
}

SYNKRO_INLINE void LineSet::GetCenter( math::Vector3& center ) const
{
	center = _center;
}

SYNKRO_INLINE Float LineSet::GetBoundSphere() const
{
	return _boundSphere;
}

SYNKRO_INLINE IPointSet* LineSet::AsPointSet() const
{
	return nullptr;
}

SYNKRO_INLINE ILineSet* LineSet::AsLineSet() const
{
	return (ILineSet*)this;
}

SYNKRO_INLINE ITriangleSet* LineSet::AsTriangleSet() const
{
	return nullptr;
}
