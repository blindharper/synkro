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
// Purpose: Gizmo helper.
//==============================================================================
#include "config.h"
#include "Gizmo.h"
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/ISceneRenderQueue.h>
#include <gfx/ILineRenderQueue.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <gfx/IParameterSet.h>
#include <gfx/IVector3Stream.h>
#include <gfx/IVector4Stream.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/DataStream.h>
#include <scene/IScene.h>
#include <img/Color.h>
#include <internal/SizeOf.h>


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::math;

//------------------------------------------------------------------------------

namespace synkro
{


namespace scene
{


Gizmo::Gizmo()
{
}

void Gizmo::Create( IGraphicsSystemEx* graphicsSystem, IScene* scene )
{
	if ( _gizmo != nullptr )
		return;

	IProgram* program = graphicsSystem->GetProgram( L"line.colored" );
	gfx::IPrimitive* data = graphicsSystem->GetDevice()->CreatePrimitive( program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::LineList, IndexType::None, 6+4+6+6, 0, 0, 0, true, false );
	_gizmo = scene->GetRenderQueue()->GetLineQueue()->CreateObject( data );
	_gizmo->SetVertexParameters( program->GetVertexStage()->GetParameters()->Clone(_gizmo->ID(), true) );
	_paramTransform = _gizmo->GetVertexParameters()->GetParam( L"p_transform" );

	SetSize( 5.0f );
}

void Gizmo::SetSize( Float size )
{
	// Set positions.
	Vector3 positions[] =
	{
		// Axes.
		Vector3( 0.0f, 0.0f, 0.0f ), Vector3( size, 0.0f, 0.0f ),
		Vector3( 0.0f, 0.0f, 0.0f ), Vector3( 0.0f, size, 0.0f ),
		Vector3( 0.0f, 0.0f, 0.0f ), Vector3( 0.0f, 0.0f, size ),

		// X label.
		Vector3( size, 1.0f, 0.0f ), Vector3( size-0.5f, 2.0f, 0.0f ),
		Vector3( size-0.5f, 1.0f, 0.0f ), Vector3( size, 2.0f, 0.0f ),

		// Y label.
		Vector3( 1.0f, size, 0.0f ), Vector3( 1.25f, size-0.5f, 0.0f ),
		Vector3( 1.5f, size, 0.0f ), Vector3( 1.25f, size-0.5f, 0.0f ),
		Vector3( 1.25f, size-1.0f, 0.0f ), Vector3( 1.25f, size-0.5f, 0.0f ),

		// Z label.
		Vector3( 0.0f, 1.0f, size ), Vector3( 0.0f, 1.0f, size-0.5f ),
		Vector3( 0.0f, 1.0f, size-0.5f ), Vector3( 0.0f, 2.0f, size ),
		Vector3( 0.0f, 2.0f, size ), Vector3( 0.0f, 2.0f, size-0.5f ),
	};
	SetVertices( positions, SizeOf(positions) );

	// Set colors.
	Color x = Color::Red; Color y = Color::LimeGreen; Color z = Color::Blue;
	Vector4 colors[] = 
	{
		Vector4( x.R, x.G, x.B, 1.0f ), Vector4( x.R, x.G, x.B, 1.0f ),
		Vector4( y.R, y.G, y.B, 1.0f ), Vector4( y.R, y.G, y.B, 1.0f ),
		Vector4( z.R, z.G, z.B, 1.0f ), Vector4( z.R, z.G, z.B, 1.0f ),

		Vector4( x.R, x.G, x.B, 1.0f ), Vector4( x.R, x.G, x.B, 1.0f ),
		Vector4( x.R, x.G, x.B, 1.0f ), Vector4( x.R, x.G, x.B, 1.0f ),

		Vector4( y.R, y.G, y.B, 1.0f ), Vector4( y.R, y.G, y.B, 1.0f ),
		Vector4( y.R, y.G, y.B, 1.0f ), Vector4( y.R, y.G, y.B, 1.0f ),
		Vector4( y.R, y.G, y.B, 1.0f ), Vector4( y.R, y.G, y.B, 1.0f ),

		Vector4( z.R, z.G, z.B, 1.0f ), Vector4( z.R, z.G, z.B, 1.0f ),
		Vector4( z.R, z.G, z.B, 1.0f ), Vector4( z.R, z.G, z.B, 1.0f ),
		Vector4( z.R, z.G, z.B, 1.0f ), Vector4( z.R, z.G, z.B, 1.0f ),
	};
	SetColors( colors, SizeOf(colors) );
}

void Gizmo::SetTransform( const Matrix4x4& transform )
{
	if ( _gizmo != nullptr )
	{
		Matrix4x4 mirror = Matrix4x4::Identity.MirrorZ();
		_gizmo->GetVertexParameters()->Set( _paramTransform, transform*mirror );
	}
}

void Gizmo::SetVertices( const Vector3* data, UInt count )
{
	IVector3Stream* stream = (IVector3Stream*)_gizmo->GetData()->GetVertexStream( DataStream::Position3D, 0 );
	if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
	{
		stream->Write( data, count );
		stream->Close();
	}
}

void Gizmo::SetColors( const Vector4* data, UInt count )
{
	IVector4Stream* stream = (IVector4Stream*)_gizmo->GetData()->GetVertexStream( DataStream::Color, 0 );
	if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
	{
		stream->Write( data, count );
		stream->Close();
	}
}


} // scene


} // synkro
