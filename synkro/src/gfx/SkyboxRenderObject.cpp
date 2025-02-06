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
// Purpose: Skybox rendering object implementation.
//==============================================================================
#include "config.h"
#include "SkyboxRenderObject.h"
#include "Primitive.h"
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IVector4Stream.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::io;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


SkyboxRenderObject::SkyboxRenderObject( IGraphicsSystemEx* graphicsSystem ) :
	SkyRenderObjectImpl<ISkyRenderObject>( graphicsSystem, graphicsSystem->GetProgram(L"skybox") )
{
	IRenderWindow* window = (IRenderWindow*)(IFrameRenderWindow*)graphicsSystem->GetFrameWindow( 0 );
	const UInt width = window->GetWidth();
	const UInt height = window->GetHeight();
	Ndc ndc( window, width, height );

	IPrimitive* data = graphicsSystem->GetDevice()->CreatePrimitive( _program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleStrip, IndexType::None, 4, 0, 0, 0, true, false );
	((Primitive*)data)->Prepare( &ndc );
	_data = (IPrimitiveEx*)data;
	P(IVector4Stream) streamPos = (IVector4Stream*)_data->GetVertexStream( DataStream::Position2D, 0 );
	if ( (streamPos != nullptr) && streamPos->Open(OpenMode::Write) )
	{
		Vector4 pos[] =
		{
			Vector4( 0.0f,	0.0f,	1.0f, 1.0f ),
			Vector4( width,	0.0f,	1.0f, 1.0f ),
			Vector4( 0.0f,	height,	1.0f, 1.0f ),
			Vector4( width,	height,	1.0f, 1.0f ),
		};
		streamPos->Write( pos, 4 );
		streamPos->Close();
	}

	_elementCount = 4;
	_depthStencilState = graphicsSystem->GetDevice()->GetDepthStencilState()->Clone();
	_depthStencilState->EnableDepth( false );
	_depthStencilState->EnableStencil( false );
	_rasterizerState = graphicsSystem->GetDevice()->GetRasterizerState()->Clone();
	_rasterizerState->SetFillMode( FillMode::Solid );
	_rasterizerState->SetCullMode( CullMode::Back );
}


} // gfx


} // synkro
