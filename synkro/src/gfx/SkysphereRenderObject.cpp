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
// Purpose: Skysphere rendering object implementation.
//==============================================================================
#include "config.h"
#include "SkysphereRenderObject.h"
#include "Primitive.h"
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IVector3Stream.h>
#include <gfx/IVector2Stream.h>
#include <gfx/ILongStream.h>


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


SkysphereRenderObject::SkysphereRenderObject( IGraphicsSystemEx* graphicsSystem, Float radius ) :
	SkyRenderObjectImpl<ISkyRenderObject>( graphicsSystem, graphicsSystem->GetProgram(L"skysphere") )
{
	constexpr UInt stackCount = 100;
	constexpr UInt sliceCount = 100;
	constexpr UInt vertexCount = (stackCount+1)*(sliceCount+1);
	constexpr UInt indexCount = 6*stackCount*sliceCount;
	_elementCount = indexCount;

	gfx::IPrimitive* data = graphicsSystem->GetDevice()->CreatePrimitive( _program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleList, IndexType::Long, vertexCount, indexCount, 0, 0, true, false );
	((Primitive*)data)->Prepare( nullptr );
	_data = (IPrimitiveEx*)data;

	Vector<Vector3> positions( A(Vector3), vertexCount );
	Vector<Vector2> coords( A(Vector2), vertexCount );
	Vector<UInt> indices( A(UInt), indexCount );

	const Float drho = Math::Pi/CastFloat(stackCount);
	const Float dtheta = Math::TwoPi/CastFloat(sliceCount);
	constexpr Float ds = 1.0f/CastFloat(sliceCount);
	constexpr Float dt = 1.0f/CastFloat(stackCount);
	Float s = 0.0f; Float t = 0.0f;
	UInt quad[6] = { 0, 0, 0, 0, 0, 0 };

	for ( UInt i = 0; i <= stackCount; ++i )
	{
		const Float rho = CastFloat(i)*drho;
		const Float sinRho = Math::Sin( rho );
		const Float cosRho = Math::Cos( rho );

		s = 0.0f;
		for ( UInt j = 0; j <= sliceCount; ++j )
		{
			const Float theta = (j == sliceCount) ? 0.0f : j*dtheta;
			const Float sinTheta = -Math::Sin( theta );
			const Float cosTheta = Math::Cos( theta );
			positions.Add( Vector3(radius*sinTheta*sinRho, radius*cosRho, radius*cosTheta*sinRho) );
			coords.Add( Vector2(1.0f-s, t) );
			s += ds;

			if ( (i < stackCount) && (j < sliceCount) )
			{
				const UInt idx2 = i*(sliceCount+1)+j;
				const UInt idx1 = idx2+sliceCount+2;

				quad[0] = idx1-1;
				quad[1] = idx2;
				quad[2] = idx1;

				quad[3] = idx2;
				quad[4] = idx2+1;
				quad[5] = idx1;

				indices.Add( quad, 6 );
			}
		}
		t += dt;
	}

	P(IVector3Stream) streamPos = (IVector3Stream*)_data->GetVertexStream( DataStream::Position3D, 0 );
	if ( (streamPos != nullptr) && streamPos->Open(OpenMode::Write) )
	{
		streamPos->Write( positions.Begin(), positions.Size() );
		streamPos->Close();
	}

	P(IVector2Stream) streamCoord = (IVector2Stream*)_data->GetVertexStream( DataStream::TexCoord2D, 0 );
	if ( (streamCoord != nullptr) && streamCoord->Open(OpenMode::Write) )
	{
		streamCoord->Write( coords.Begin(), coords.Size() );
		streamCoord->Close();
	}

	P(ILongStream) streamIndices = (ILongStream*)_data->GetIndexStream();
	if ( (streamIndices != nullptr) && streamIndices->Open(OpenMode::Write) )
	{
		streamIndices->Write( indices.Begin(), indices.Size() );
		streamIndices->Close();
	}

	_depthStencilState = graphicsSystem->GetDevice()->GetDepthStencilState()->Clone();
	_depthStencilState->EnableDepth( false );
	_depthStencilState->EnableStencil( false );
	_rasterizerState = graphicsSystem->GetDevice()->GetRasterizerState()->Clone();
	_rasterizerState->SetFillMode( FillMode::Solid );
	_rasterizerState->SetCullMode( CullMode::Front );
}


} // gfx


} // synkro
