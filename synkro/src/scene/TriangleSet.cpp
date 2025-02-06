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
#include "config.h"
#include "TriangleSet.h"
#include "PrimitiveAnimationController.h"
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/ISceneRenderQueue.h>
#include <gfx/ISceneRenderObject.h>
#include <gfx/ILineRenderQueue.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <gfx/IParameterSet.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/IVector3Stream.h>
#include <gfx/IVector4Stream.h>
#include <gfx/DataStream.h>


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


TriangleSet::TriangleSet( ITriangleSet* set, IContext* context, const DebugMode& debugMode, UInt start, UInt count ) :
	_context( context ),
	_set( set ),
	_normals( A(Vector3) ),
	_paramNormalsTransform( nullptr ),
	_base( count == 0 )
{
	// Create debug geometry.
	if ( debugMode.IsSet(DebugMode::Normals) )
	{
		_normals.SetSize( 2*set->GetVertexCount() );
		IProgram* program = _context->GetGraphicsSystem()->GetProgram( L"line.colored" );
		gfx::IPrimitive* data = _context->GetGraphicsSystem()->GetDevice()->CreatePrimitive( program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::LineList, IndexType::None, _normals.Size(), 0, 0, 0, true, false );
		_objectNormals = _set->GetRenderObject()->GetQueue()->GetLineQueue()->CreateObject(data);
		_objectNormals->SetVertexParameters( program->GetVertexStage()->GetParameters()->Clone(_objectNormals->ID(), true) );
		_paramNormalsTransform = _objectNormals->GetVertexParameters()->GetParam( L"p_transform" );
	}
}

IPrimitiveAnimationController* TriangleSet::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new PrimitiveAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

void TriangleSet::SetPositions( const Vector3* positions, UInt start, UInt count )
{
	_set->SetPositions( positions, start, count );

	if ( _objectNormals != nullptr )
	{
		const Vector3* vec = positions+start;
		for ( UInt i = 0; i < count; ++i, ++vec )
		{
			const UInt idx = 2*(start+i);
			_normals[idx] = _normals[idx+1] = *vec;
		}
	}
}

void TriangleSet::SetNormals( const Vector3* normals, UInt start, UInt count )
{
	_set->SetNormals( normals, start, count );

	if ( _objectNormals != nullptr )
	{
		Vector<Vector4> colors( A(Vector4), _normals.Size() );
		colors.SetSize( _normals.Size() );
		const Vector3* vec = normals+start;
		for ( UInt i = 0; i < count; ++i, ++vec )
		{
			Vector3 v = *vec;
			v.Normalize();
			const UInt idx = 2*(start+i);
			_normals[idx+1] += v;
			colors[idx] = colors[idx+1] = Vector4( v, 1.0f );
		}

		IVector3Stream* streamNormals = (IVector3Stream*)_objectNormals->GetData()->GetVertexStream( DataStream::Position3D, 0 );
		if ( (streamNormals != nullptr) && streamNormals->Open(OpenMode::Write) )
		{
			streamNormals->SetPosition( 0 );
			streamNormals->Write( _normals.Begin(), _normals.Size() );
			streamNormals->Close();
			_normals.Clear();
		}

		IVector4Stream* streamColors = (IVector4Stream*)_objectNormals->GetData()->GetVertexStream( DataStream::Color, 0 );
		if ( (streamColors != nullptr) && streamColors->Open(OpenMode::Write) )
		{
			streamColors->SetPosition( 0 );
			streamColors->Write( colors.Begin(), colors.Size() );
			streamColors->Close();
		}
	}
}


} // scene


} // synkro
