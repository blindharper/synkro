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
#include "config.h"
#include "LineSet.h"
#include "LineSetAnimationController.h"
#include <gfx/ILineRenderQueue.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <gfx/IShortStream.h>
#include <gfx/ILongStream.h>
#include <gfx/IVector3Stream.h>
#include <gfx/IVector4Stream.h>
#include <gfx/IMatrix4x4Stream.h>
#include <gfx/DataStreamWriter.h>
#include <lang/Vector.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
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


LineSet::LineSet( IContext* context, ILineRenderObject* object, UInt start, UInt count ) :
	_context( context ),
	_object( object ),
	_paramColor( nullptr ),
	_paramTransform( nullptr ),
	_center( Vector3::Origin ),
	_boundSphere( 0.0f )
{
	assert( _object != nullptr );

	if ( _object->GetVertexParameters() != nullptr )
	{
		_paramColor = _object->GetVertexParameters()->GetParam( L"sp_color" );
		_paramTransform = _object->GetVertexParameters()->GetParam( L"p_transform" );
	}

	if ( count > 0 )
	{
		_object->SetElementRange( start, count );
	}
}

IPrimitiveAnimationController* LineSet::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new LineSetAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

void LineSet::SetInstanceTransform( UInt index, const Matrix4x4& transform )
{
	IMatrix4x4Stream* stream = (IMatrix4x4Stream*)_object->GetData()->GetInstanceStream( DataStream::Transform, 0 );
	if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
	{
		stream->SetPosition( index );
		stream->Write( &transform, 1 );
		stream->Close();
	}
}

void LineSet::SetInstanceColor( UInt index, const Color& color )
{
	IVector4Stream* stream = (IVector4Stream*)_object->GetData()->GetInstanceStream( DataStream::Color, 0 );
	if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
	{
		stream->SetPosition( index );
		stream->Set( ToVector(color), 1 );
		stream->Close();
	}
}

void LineSet::SetPositions( const Vector3* positions, UInt start, UInt count )
{
	IVector3Stream* stream = (IVector3Stream*)_object->GetData()->GetVertexStream( DataStream::Position3D, 0 );
	if ( stream == nullptr )
		throw InvalidOperationException( L"Cannot set 3D positions for non-3D primitive." );

	DataStreamWriter sw( stream );
	if ( !sw.Open() )
		return;

	stream->SetPosition( start );
	stream->Write( positions, count );

	// Update center and bounding sphere.
	Vector3 total;
	Float boundSphere2 = 0.0f;
	if ( start == 0 )
	{
		_boundSphere = 0.0f;
	}
	const Vector3* vec = positions+start;
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
	_boundSphere = Math::Sqrt( boundSphere2 );
}

void LineSet::SetPositions( const Vector4* positions, UInt start, UInt count )
{
	IVector4Stream* stream = (IVector4Stream*)_object->GetData()->GetVertexStream( DataStream::Position4D, 0 );
	if ( stream == nullptr )
		throw InvalidOperationException( L"Cannot set 4D positions for non-4D primitive." );

	DataStreamWriter sw( stream );
	if ( !sw.Open() )
		return;

	stream->SetPosition( start );
	stream->Write( positions, count );
}

void LineSet::SetColors( const Color* colors, UInt start, UInt count )
{
	IVector4Stream* stream = (IVector4Stream*)_object->GetData()->GetVertexStream( DataStream::Color, 0 );
	if ( stream == nullptr )
		throw InvalidOperationException( L"Cannot set vertices colors for monochrome primitive." );

	DataStreamWriter sw( stream );
	if ( !sw.Open() )
		return;

	Vector<Vector4> cols( A(Vector4), count );
	for ( UInt i = 0; i < count; ++i )
	{
		cols.Add( ToVector(colors[i]) );
	}
	stream->SetPosition( start );
	stream->Write( cols.Begin(), cols.Size() );
}

void LineSet::SetIndices( const UInt* indices, UInt start, UInt count )
{
	IDataStream* stream = _object->GetData()->GetIndexStream();
	if ( stream == nullptr )
		throw InvalidOperationException( L"Cannot set indices for unindexed primitive." );

	DataStreamWriter sw( stream );
	if ( !sw.Open() )
		return;

	stream->SetPosition( start );

	const IndexType indexType = _object->GetData()->GetIndexType();
	if ( indexType == IndexType::Long )
	{
		ILongStream* streamLong = (ILongStream*)stream;
		streamLong->Write( indices, count );
	}
	else if ( indexType == IndexType::Short )
	{
		IShortStream* streamShort = (IShortStream*)stream;
		UShort idx = 0;
		for ( UInt i = 0; i < count; ++i )
		{
			idx = CastUShort( indices[i] );
			streamShort->Write( &idx, 1 );
		}
	}
}

void LineSet::SetColor( const Color& color )
{
	if ( _paramColor == nullptr )
		throw InvalidOperationException( L"Cannot set single color for colored primitive." );

	_object->GetVertexParameters()->Set( _paramColor, ToVector(color) );
}

ILineSet* LineSet::CreateSubset( UInt start, UInt count )
{
	ILineRenderObject* object = _object->GetQueue()->CreateObject( _object->GetData() );
	object->SetVertexParameters( _object->GetData()->GetProgram()->GetVertexStage()->GetParameters()->Clone(object->ID(), true) );
	return new LineSet( _context, object, start, count );
}


} // scene


} // synkro
