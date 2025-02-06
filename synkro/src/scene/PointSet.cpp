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
#include "config.h"
#include "PointSet.h"
#include "PointSetAnimationController.h"
#include <gfx/ILineRenderQueue.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
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


PointSet::PointSet( IContext* context, ILineRenderObject* object, UInt start, UInt count, Float size ) :
	_context( context ),
	_object( object ),
	_paramColor( nullptr ),
	_paramTransform( nullptr ),
	_center( Vector3::Origin ),
	_boundSphere( 0.0f ),
	_size( size )
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

IPrimitiveAnimationController* PointSet::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new PointSetAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

void PointSet::SetInstanceTransform( UInt index, const Matrix4x4& transform )
{
	IMatrix4x4Stream* stream = (IMatrix4x4Stream*)_object->GetData()->GetInstanceStream( DataStream::Transform, 0 );
	if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
	{
		stream->SetPosition( index );
		stream->Write( &transform, 1 );
		stream->Close();
	}
}

void PointSet::SetInstanceColor( UInt index, const Color& color )
{
	IVector4Stream* stream = (IVector4Stream*)_object->GetData()->GetInstanceStream( DataStream::Color, 0 );
	if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
	{
		stream->SetPosition( index );
		stream->Set( ToVector(color), 1 );
		stream->Close();
	}
}

void PointSet::SetPositions( const Vector3* positions, UInt start, UInt count )
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

void PointSet::SetColors( const Color* colors, UInt start, UInt count )
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

IPointSet* PointSet::CreateSubset( UInt start, UInt count )
{
	ILineRenderObject* object = _object->GetQueue()->CreateObject( _object->GetData() );
	object->SetVertexParameters( _object->GetData()->GetProgram()->GetVertexStage()->GetParameters()->Clone( object->ID(), true) );
	return new PointSet( _context, object, start, count, _size );
}


} // scene


} // synkro
