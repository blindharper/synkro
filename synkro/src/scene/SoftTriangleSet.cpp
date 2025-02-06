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
// Purpose: Implements software triangle set.
//==============================================================================
#include "config.h"
#include "SoftTriangleSet.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


SoftTriangleSet::SoftTriangleSet( SoftTriangleSet* base, UInt vertexCount, UInt indexCount, const Range& range ) :
	_positions( A(Vector3) ),
	_normals( A(Vector3) ),
	_textureCoords( A(Vector2) ),
	_colors( A(Color) ),
	_indices( A(UInt) ),
	_base( base ),
	_range( range )
{
	Resize( vertexCount, indexCount );
}

IPrimitiveAnimationController* SoftTriangleSet::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return nullptr;
}

void SoftTriangleSet::Show( Bool show )
{
	// Do nothing.
}

void SoftTriangleSet::SetElementRange( const Range& range )
{
	if ( _base == nullptr )
	{
		_range = range;
	}
}

void SoftTriangleSet::SetInstanceRange( const Range& range )
{
	// Do nothing.
}

void SoftTriangleSet::SetTransform( const Matrix4x4& transform )
{
	// Do nothing.
}

void SoftTriangleSet::SetOwnerTransform( const Matrix4x4& transform )
{
	// Do nothing.
}

void SoftTriangleSet::SetInstanceTransform( UInt index, const Matrix4x4& transform )
{
	// Do nothing.
}

void SoftTriangleSet::SetInstanceColor( UInt index, const Color& color )
{
	// Do nothing.
}

void SoftTriangleSet::Resize( UInt vertexCount, UInt indexCount )
{
	_positions.SetSize( vertexCount );
	if ( _normals.Size() != 0 )
	{
		_normals.SetSize( vertexCount );
	}
	if ( _colors.Size() != 0 )
	{
		_colors.SetSize( vertexCount );
	}
	if ( _textureCoords.Size() != 0 )
	{
		_textureCoords.SetSize( vertexCount );
	}	
	_indices.SetSize( indexCount );
}

Bool SoftTriangleSet::IsVisible() const
{
	return false;
}

void SoftTriangleSet::GetElementRange( Range& range ) const
{
	range = _range;
}

void SoftTriangleSet::GetInstanceRange( Range& range ) const
{
	// Do nothing.
}

UInt SoftTriangleSet::GetVertexCount() const
{
	return (_base != nullptr) ? _base->GetVertexCount() : _positions.Size();
}

UInt SoftTriangleSet::GetIndexCount() const
{
	return (_base != nullptr) ? _base->GetIndexCount() : _indices.Size();
}

UInt SoftTriangleSet::GetElementCount() const
{
	return 0;
}

void SoftTriangleSet::GetTransform( Matrix4x4& transform ) const
{
}

void SoftTriangleSet::GetInstanceTransform( UInt index, Matrix4x4& transform ) const
{
	// Do nothing.
}

void SoftTriangleSet::GetCenter( Vector3& center ) const
{
	// Do nothing.
}

Float SoftTriangleSet::GetBoundSphere() const
{
	return 0.0f;
}

ILineSet* SoftTriangleSet::AsLineSet() const
{
	return nullptr;
}

IPointSet* SoftTriangleSet::AsPointSet() const
{
	return nullptr;
}

ITriangleSet* SoftTriangleSet::AsTriangleSet() const
{
	return (ITriangleSet*)this;
}

Bool SoftTriangleSet::BeginSetBoneWeights()
{
	return true;
}

void SoftTriangleSet::EndSetBoneWeights()
{
}

void SoftTriangleSet::SetPositions( const Vector3* positions, UInt start, UInt count )
{
	if ( _base != nullptr )
		_base->SetData( _positions, positions, start, count );
	else
		SetData( _positions, positions, start, count );
}

void SoftTriangleSet::SetNormals( const Vector3* normals, UInt start, UInt count )
{
	if ( _base != nullptr )
		_base->SetData( _normals, normals, start, count );
	else
	{
		_normals.SetSize( _positions.Size() );
		SetData( _normals, normals, start, count );
	}
}

void SoftTriangleSet::SetColors( const Color* colors, UInt start, UInt count )
{
	if ( _base != nullptr )
		_base->SetData( _colors, colors, start, count );
	else
	{
		_colors.SetSize( _positions.Size() );
		SetData( _colors, colors, start, count );
	}
}

void SoftTriangleSet::SetTextureCoordinates( const Vector2* coords, UInt start, UInt count )
{
	if ( _base != nullptr )
		_base->SetData( _textureCoords, coords, start, count );
	else
	{
		_textureCoords.SetSize( _positions.Size() );
		SetData( _textureCoords, coords, start, count );
	}
}

void SoftTriangleSet::SetIndices( const UInt* indices, UInt start, UInt count )
{
	if ( _base != nullptr )
		_base->SetData( _indices, indices, start, count );
	else
		SetData( _indices, indices, start, count );
}

void SoftTriangleSet::SetBoneWeights( UInt index, const Byte* bones, const Float* weights, UInt count )
{
}

void SoftTriangleSet::SetBoneTransforms( const Matrix4x4* transforms, UInt count )
{
}

Bool SoftTriangleSet::GetPositions( Vector3* positions, UInt start, UInt count ) const
{
	if ( _base != nullptr )
		return _base->GetData( positions, _base->_positions, start, count );
	else
		return GetData( positions, _positions, start, count );
}

Bool SoftTriangleSet::GetNormals( Vector3* normals, UInt start, UInt count ) const
{
	if ( _base != nullptr )
		return _base->GetData( normals, _base->_normals, start, count );
	else
		return GetData( normals, _normals, start, count );
}

Bool SoftTriangleSet::GetColors( Color* colors, UInt start, UInt count ) const
{
	if ( _base != nullptr )
		return _base->GetData( colors, _base->_colors, start, count );
	else
		return GetData( colors, _colors, start, count );
}

Bool SoftTriangleSet::GetTextureCoordinates( Vector2* coords, UInt start, UInt count ) const
{
	if ( _base != nullptr )
		return _base->GetData( coords, _base->_textureCoords, start, count );
	else
		return GetData( coords, _textureCoords, start, count );
}

Bool SoftTriangleSet::GetIndices( UInt* indices, UInt start, UInt count ) const
{
	if ( _base != nullptr )
		return _base->GetData( indices, _base->_indices, start, count );
	else
		return GetData( indices, _indices, start, count );
}

ISceneRenderObject* SoftTriangleSet::GetRenderObject() const
{
	return nullptr;
}

template <class T>
void SoftTriangleSet::SetData( Vector<T>& stream, const T* data, UInt start, UInt count )
{
	assert( start+count <= stream.Size() );

	if ( (start == 0) && (count == stream.Size()) )
	{
		Copy( stream.Begin(), data, count );
	}
	else
	{
		for ( UInt i = 0; i < count; ++i )
		{
			stream[i+start] = data[i];
		}
	}
}

template <class T>
Bool SoftTriangleSet::GetData( T* data, const Vector<T>& stream, UInt start, UInt count ) const
{
	if ( stream.Size() == 0 )
		return false;

	if ( (start == 0) && (count == stream.Size()) )
	{
		Copy( data, stream.Begin(), count );
	}
	else
	{
		for ( UInt i = 0; i < count; ++i )
		{
			data[i] = stream[i+start];
		}
	}
	return true;
}


} // scene


} // synkro
