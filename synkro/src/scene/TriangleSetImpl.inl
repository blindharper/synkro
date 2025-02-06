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
// Purpose: Generic triangle set implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE TriangleSetImpl<T>::TriangleSetImpl( gfx::ISceneRenderObject* object, UInt start, UInt count ) :
	_object( object ),
	_paramTransform( nullptr ),
	_center( math::Vector3::Origin ),
	_boundSphere( 0.0f ),
	_positions( A(math::Vector3) ),
	_indices( A(UInt) ),
	_paramBoneTransforms( nullptr ),
	_base( count == 0 )
{
	assert( _object != nullptr );

	if ( _object->GetVertexParameters() != nullptr )
	{
		_paramTransform = _object->GetVertexParameters()->GetParam( L"p_transform" );
		_paramBoneTransforms = _object->GetVertexParameters()->GetParam( L"p_bones" );
	}

	if ( count > 0 )
	{
		_object->SetElementRange( start, count );
	}
}

template <class T>
SYNKRO_INLINE TriangleSetImpl<T>::~TriangleSetImpl()
{
}

template <class T>
SYNKRO_INLINE IPrimitiveAnimationController* TriangleSetImpl<T>::CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener )
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::Show( Bool show )
{
	_object->Enable( show );
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::SetElementRange( const lang::Range& range )
{
	if ( _base )
	{
		_object->SetElementRange( range.Start, range.Length );
		_object->Enable( true );
	}
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::SetInstanceRange( const lang::Range& range )
{
	_object->SetInstanceRange( range.Start, range.Length );
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::SetTransform( const math::Matrix4x4& transform )
{
	_transform = transform;
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::SetOwnerTransform( const math::Matrix4x4& transform )
{
	if ( _paramTransform != nullptr )
	{
		const math::Matrix4x4 worldTransform = transform * _transform;
		_object->GetVertexParameters()->Set( _paramTransform, worldTransform );
	}
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::SetInstanceTransform( UInt index, const math::Matrix4x4& transform )
{
	gfx::IMatrix4x4Stream* stream = (gfx::IMatrix4x4Stream*)_object->GetData()->GetInstanceStream( gfx::DataStream::Transform, 0 );
	if ( (stream != nullptr) && stream->Open(io::OpenMode::Write) )
	{
		stream->SetPosition( index );
		stream->Write( &transform, 1 );
		stream->Close();
	}
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::SetInstanceColor( UInt index, const img::Color& color )
{
	gfx::IVector4Stream* stream = (gfx::IVector4Stream*)_object->GetData()->GetInstanceStream( gfx::DataStream::Color, 0 );
	if ( (stream != nullptr) && stream->Open(io::OpenMode::Write) )
	{
		stream->SetPosition( index );
		stream->Set( ToVector(color), 1 );
		stream->Close();
	}
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::Resize( UInt vertexCount, UInt indexCount )
{
	_object->GetData()->Resize( vertexCount, indexCount, _object->GetData()->GetInstanceCount() );
}

template <class T>
SYNKRO_INLINE Bool TriangleSetImpl<T>::IsVisible() const
{
	return _object->IsEnabled();
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::GetElementRange( lang::Range& range ) const
{
	range.Start = _object->GetStartElement();
	range.Length = _object->GetElementCount();
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::GetInstanceRange( lang::Range& range ) const
{
	range.Start = _object->GetStartInstance();
	range.Length = _object->GetInstanceCount();
}

template <class T>
SYNKRO_INLINE UInt TriangleSetImpl<T>::GetVertexCount() const
{
	return _object->GetData()->GetVertexCount();
}

template <class T>
SYNKRO_INLINE UInt TriangleSetImpl<T>::GetIndexCount() const
{
	return _object->GetData()->GetIndexCount();
}

template <class T>
SYNKRO_INLINE UInt TriangleSetImpl<T>::GetElementCount() const
{
	gfx::IPrimitive* data = _object->GetData();
	return (data->GetIndexCount() > 0) ? data->GetIndexCount() : data->GetVertexCount();
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::GetTransform( math::Matrix4x4& transform ) const
{
	transform = _transform;
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::GetCenter( math::Vector3& center ) const
{
	center = _center;
}

template <class T>
SYNKRO_INLINE Float TriangleSetImpl<T>::GetBoundSphere() const
{
	return _boundSphere;
}

template <class T>
SYNKRO_INLINE IPointSet* TriangleSetImpl<T>::AsPointSet() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ILineSet* TriangleSetImpl<T>::AsLineSet() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ITriangleSet* TriangleSetImpl<T>::AsTriangleSet() const
{
	return (ITriangleSet*)this;
}

template <class T>
SYNKRO_INLINE Bool TriangleSetImpl<T>::BeginSetBoneWeights()
{
	_boneIndices = (gfx::ILongStream*)_object->GetData()->GetVertexStream( gfx::DataStream::Bones, 0 );
	if ( !_boneIndices->Open(io::OpenMode::Write) )
	{
		_boneIndices = nullptr;
		return false;
	}
	_boneWeights = (gfx::IVector4Stream*)_object->GetData()->GetVertexStream( gfx::DataStream::Weights, 0 );
	if ( !_boneWeights->Open(io::OpenMode::Write) )
	{
		_boneIndices->Close();
		_boneIndices = nullptr;
		_boneWeights = nullptr;
		return false;
	}
	return true;
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::EndSetBoneWeights()
{
	if ( _boneIndices != nullptr )
	{
		_boneIndices->Close();
		_boneIndices = nullptr;
	}

	if ( _boneWeights != nullptr )
	{
		_boneWeights->Close();
		_boneWeights = nullptr;
	}
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::SetPositions( const math::Vector3* positions, UInt start, UInt count )
{
	gfx::IVector3Stream* stream = (gfx::IVector3Stream*)_object->GetData()->GetVertexStream( gfx::DataStream::Position3D, 0 );
	if ( stream == nullptr )
		throw lang::InvalidOperationException( L"Cannot set 3D positions for non-3D primitive." );

	gfx::DataStreamWriter sw( stream );
	if ( !sw.Open() )
		return;

	// Update positions.
	stream->SetPosition( start );
	stream->Write( positions, count );
	_positions.Clear();
	_positions.Add( positions, count );

	// Update center and bounding sphere.
	math::Vector3 total;
	Float boundSphere2 = 0.0f;
	if ( start == 0 )
	{
		_boundSphere = 0.0f;
	}
	const math::Vector3* vec = positions+start;
	for ( UInt i = 0; i < count; ++i, ++vec )
	{
		total += *vec;
		const Float len2 = vec->LengthSquared();
		if ( boundSphere2 < len2 )
		{
			boundSphere2 = len2;
		}
	}
	_center = total/CastFloat(count);
	_boundSphere = math::Math::Sqrt( boundSphere2 );
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::SetNormals( const math::Vector3* normals, UInt start, UInt count )
{
	gfx::IVector3Stream* stream = (gfx::IVector3Stream*)_object->GetData()->GetVertexStream( gfx::DataStream::Normal, 0 );
	if ( stream == nullptr )
		throw lang::InvalidOperationException( L"Cannot set normals for unlit primitive." );

	gfx::DataStreamWriter sw( stream );
	if ( !sw.Open() )
		return;

	stream->SetPosition( start );
	stream->Write( normals, count );
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::SetColors( const img::Color* colors, UInt start, UInt count )
{
	gfx::IVector4Stream* stream = (gfx::IVector4Stream*)_object->GetData()->GetVertexStream( gfx::DataStream::Color, 0 );
	if ( stream == nullptr )
		throw lang::InvalidOperationException( L"Cannot set vertices colors for monochrome primitive." );

	gfx::DataStreamWriter sw( stream );
	if ( !sw.Open() )
		return;

	lang::Vector<math::Vector4> cols( A(math::Vector4), count );
	for ( UInt i = 0; i < count; ++i )
	{
		cols.Add( ToVector(colors[i]) );
	}
	stream->SetPosition( start );
	stream->Write( cols.Begin(), cols.Size() );
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::SetTextureCoordinates( const math::Vector2* coords, UInt start, UInt count )
{
	gfx::IVector2Stream* stream = (gfx::IVector2Stream*)_object->GetData()->GetVertexStream( gfx::DataStream::TexCoord2D, 0 );
	if ( stream == nullptr )
		return;
		// NB: throw lang::InvalidOperationException( L"Cannot set texture coordinates for untextured primitive." );

	gfx::DataStreamWriter sw( stream );
	if ( !sw.Open() )
		return;

	stream->SetPosition( start );
	stream->Write( coords, count );
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::SetIndices( const UInt* indices, UInt start, UInt count )
{
	gfx::IDataStream* stream = _object->GetData()->GetIndexStream();
	if ( stream == nullptr )
		throw lang::InvalidOperationException( L"Cannot set indices for unindexed primitive." );

	gfx::DataStreamWriter sw( stream );
	if ( !sw.Open() )
		return;

	stream->SetPosition( start );

	const gfx::IndexType indexType = _object->GetData()->GetIndexType();
	if ( indexType == gfx::IndexType::Long )
	{
		gfx::ILongStream* streamLong = (gfx::ILongStream*)stream;
		streamLong->Write( indices, count );
	}
	else if ( indexType == gfx::IndexType::Short )
	{
		gfx::IShortStream* streamShort = (gfx::IShortStream*)stream;
		UShort idx = 0;
		for ( UInt i = 0; i < count; ++i )
		{
			idx = CastUShort(indices[i]);
			streamShort->Write( &idx, 1 );
		}
	}
	_indices.Clear();
	_indices.Add( indices, count );
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::SetBoneWeights( UInt index, const Byte* bones, const Float* weights, UInt count )
{
	if ( _boneIndices == nullptr )
		return;

	UInt indices = 0;
	math::Vector4 wgts;

	switch ( count )
	{
		case 4:
			indices |= bones[3] << 24;
			wgts.w = weights[3];

		case 3:
			indices |= bones[2] << 16;
			wgts.z = weights[2];

		case 2:
			indices |= bones[1] << 8;
			wgts.y = weights[1];

		case 1:
			indices |= bones[0];
			wgts.x = weights[0];
	}

	_boneIndices->SetPosition( index );
	_boneIndices->Write( &indices, count );

	_boneWeights->SetPosition( index );
	_boneWeights->Write( &wgts, count );
}

template <class T>
SYNKRO_INLINE void TriangleSetImpl<T>::SetBoneTransforms( const math::Matrix4x4* transforms, UInt count )
{
	if ( _paramBoneTransforms != nullptr )
	{
		_object->GetVertexParameters()->Set( _paramBoneTransforms, transforms, count );
	}
	else
	{
		gfx::IResource* res = _object->GetVertexResources()->Get( 0 );
		ITypedBuffer* buffer = res->AsBuffer()->AsTyped();
		buffer->Set( transforms, count );
	}
}

template <class T>
SYNKRO_INLINE Bool TriangleSetImpl<T>::GetPositions( math::Vector3* positions, UInt start, UInt count ) const
{
	if ( start+count <= _positions.Size() )
	{
		Copy( positions, &_positions[start], count );
		return true;
	}
	return false;
}

template <class T>
SYNKRO_INLINE Bool TriangleSetImpl<T>::GetNormals( math::Vector3* normals, UInt start, UInt count ) const
{
	throw lang::InvalidOperationException( L"Cannot get normals." );
}

template <class T>
SYNKRO_INLINE Bool TriangleSetImpl<T>::GetColors( img::Color* colors, UInt start, UInt count ) const
{
	throw lang::InvalidOperationException( L"Cannot get colors." );
}

template <class T>
SYNKRO_INLINE Bool TriangleSetImpl<T>::GetTextureCoordinates( math::Vector2* coords, UInt start, UInt count ) const
{
	throw lang::InvalidOperationException( L"Cannot get texture coordinates." );
}

template <class T>
SYNKRO_INLINE Bool TriangleSetImpl<T>::GetIndices( UInt* indices, UInt start, UInt count ) const
{
	if ( start+count <= _indices.Size() )
	{
		Copy( indices, &_indices[start], count );
		return true;
	}
	return false;
}

template <class T>
SYNKRO_INLINE gfx::ISceneRenderObject* TriangleSetImpl<T>::GetRenderObject() const
{
	return _object;
}
