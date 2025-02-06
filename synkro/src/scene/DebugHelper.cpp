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
// Purpose: Debug geometry visualizer.
//==============================================================================
#include "config.h"
#include "DebugHelper.h"
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/ISceneRenderQueue.h>
#include <gfx/ILineRenderQueue.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <gfx/IParameterSet.h>
#include <gfx/IVector3Stream.h>
#include <gfx/IShortStream.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/DataStream.h>
#include <scene/IScene.h>
#include <internal/ToVector.h>


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


DebugHelper::DebugHelper()
{
}

void DebugHelper::Create( IGraphicsSystemEx* graphicsSystem, IScene* scene, UInt vertexCount, UInt indexCount, const Color& color )
{
	Create( PrimitiveType::LineList, graphicsSystem, scene, vertexCount, indexCount, color );
}

void DebugHelper::CreateStrip( IGraphicsSystemEx* graphicsSystem, IScene* scene, UInt vertexCount, const Color& color )
{
	Create( PrimitiveType::LineStrip, graphicsSystem, scene, vertexCount, 0, color );
}

void DebugHelper::Resize( UInt vertexCount, UInt indexCount )
{
	_helper->GetData()->Resize( vertexCount, indexCount, 0 );
}

void DebugHelper::SetVisibleVertexCount( UInt count )
{
	_helper->SetElementRange( 0, count );
}

void DebugHelper::SetVertices( const Vector3* data, UInt count )
{
	IVector3Stream* stream = (IVector3Stream*)_helper->GetData()->GetVertexStream( DataStream::Position3D, 0 );
	if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
	{
		stream->Write( data, count );
		stream->Close();
	}
}

void DebugHelper::SetIndices( const UShort* data, UInt count )
{
	IShortStream* stream = (IShortStream*)_helper->GetData()->GetIndexStream();
	if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
	{
		stream->Write( data, count );
		stream->Close();
	}
}

void DebugHelper::SetTransform( const Matrix4x4& transform )
{
	if ( _helper != nullptr )
	{
		_helper->GetVertexParameters()->Set( _paramTransform, transform );
	}
}

void DebugHelper::SetColor( const Color& color )
{
	if ( _helper != nullptr )
	{
		_helper->GetVertexParameters()->Set( _paramColor, ToVector(color) );
	}
}

UInt DebugHelper::GetVertexCount() const
{
	return _helper->GetData()->GetVertexCount();
}

void DebugHelper::Create( const PrimitiveType& type, IGraphicsSystemEx* graphicsSystem, IScene* scene, UInt vertexCount, UInt indexCount, const Color& color )
{
	if ( _helper != nullptr )
		return;

	IProgram* program = graphicsSystem->GetProgram( L"line.monochrome" );
	IndexType indexType = (indexCount > 0) ? IndexType::Short : IndexType::None;
	gfx::IPrimitive* data = graphicsSystem->GetDevice()->CreatePrimitive( program, DataUsage::Dynamic, DataAccess::WriteOnly, type, indexType, vertexCount, indexCount, 0, 0, true, false );
	_helper = scene->GetRenderQueue()->GetLineQueue()->CreateObject( data );
	_helper->SetVertexParameters( program->GetVertexStage()->GetParameters()->Clone(_helper->ID(), true) );
	_paramTransform = _helper->GetVertexParameters()->GetParam( L"p_transform" );
	_paramColor = _helper->GetVertexParameters()->GetParam( L"sp_color" );
	_helper->GetVertexParameters()->Set( _paramColor, ToVector(color) );
}


} // scene


} // synkro
