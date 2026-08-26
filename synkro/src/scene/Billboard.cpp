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
// Purpose: Billboard node implementation.
//==============================================================================
#include "config.h"
#include "Billboard.h"
#include "NodeAnimationController.h"
#include <gfx/IFrameRenderWindowEx.h>
#include <gfx/IViewRenderWindowEx.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/ISceneRenderQueue.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <gfx/IParameterSet.h>
#include <gfx/IResourceSet.h>
#include <gfx/ISamplerStateSet.h>
#include <gfx/ISamplerState.h>
#include <gfx/IVector2Stream.h>
#include <gfx/IVector3Stream.h>
#include <gfx/IBlendState.h>
#include <img/IImage.h>
#include <view/IViewport.h>
#include <scene/ICamera.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::view;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


Billboard::Billboard( ISceneEx* scene, IContext* context, const String& name, IImage* image, Float width, Float height ) :
	NodeImpl<IBillboard>( scene, context, AsBaseScene(scene)->GetBillboardName(name), false ),
	_paramName( L"p_transform" )
{
	_paramName.MakePermanent();

	assert( image != nullptr );

	// Create object.
	IProgram* program = _context->GetGraphicsSystem()->GetProgram( L"billboard" );
	gfx::IPrimitive* data = _context->GetGraphicsSystem()->GetDevice()->CreatePrimitive( program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleStrip, IndexType::None, 4, 0, 0, 0, true, false );
	_billboard = scene->GetRenderQueue()->CreateObject( data, false );

	// Set vertex positions.
	IVector3Stream* streamPos = (IVector3Stream*)_billboard->GetData()->GetVertexStream( DataStream::Position3D, 0 );
	if ( (streamPos != nullptr) && streamPos->Open(OpenMode::Write) )
	{
		const Vector3 positions[] =
		{
			Vector3( -width/2.0f,	 height/2.0f,	0.0f ),
			Vector3( -width/2.0f,	-height/2.0f,	0.0f ),
			Vector3(  width/2.0f,	 height/2.0f,	0.0f ),			
			Vector3(  width/2.0f,	-height/2.0f,	0.0f ),
		};
		streamPos->Write( positions, SizeOf(positions) );
		streamPos->Close();
	}

	// Set texture coordinates.
	IVector2Stream* streamCoord = (IVector2Stream*)_billboard->GetData()->GetVertexStream( DataStream::TexCoord2D, 0 );
	if ( (streamCoord != nullptr) && streamCoord->Open(OpenMode::Write) )
	{
		const Vector2 coordinates[] =
		{
			Vector2( 0.0f, 0.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 1.0f, 1.0f ),
		};
		streamCoord->Write( coordinates, SizeOf(coordinates) );
		streamCoord->Close();
	}

	// Set texture and sampler.
	PixelFormat format = (_context->GetGraphicsSystem()->GetFrameWindow() != nullptr) ? _context->GetGraphicsSystem()->GetFrameWindow()->GetPixelFormat() : _context->GetGraphicsSystem()->GetViewWindow(0)->GetPixelFormat();
	image->Prepare( format, 1 );
	IResourceSet* resources = program->GetFragmentStage()->GetResources()->Clone( _billboard->ID() );
	resources->Set( 0, image->AsResource() );
	_billboard->SetFragmentResources( resources );

	ISamplerStateSet* samplers = program->GetFragmentStage()->GetSamplers()->Clone( _billboard->ID() );
	samplers->Get( 0 )->SetFilter( TextureFilter::Linear );
	samplers->Get( 0 )->SetAddress( TextureAddress::Clamp );
	_billboard->SetFragmentSamplers( samplers );

	// Set render states.
	IGraphicsDeviceEx* graphicsDevice = _context->GetGraphicsSystem()->GetDevice();

	_blendStates = graphicsDevice->GetBlendStates()->Clone();
	IBlendState* state = _blendStates->Get( 0 );
	state->Enable( true );
	state->SetOperation( BlendOperation::Add );
	state->SetSrcMode( BlendMode::SrcAlpha );
	state->SetDstMode( BlendMode::InvSrcAlpha );
	_billboard->SetBlendStates( _blendStates );

	_depthStencilState = graphicsDevice->GetDepthStencilState()->Clone();
	_depthStencilState->EnableDepth( true );
	_depthStencilState->EnableDepthWrite( true );
	_depthStencilState->SetDepthFunction( CompareFunction::LessOrEqual );
	_billboard->SetDepthStencilState( _depthStencilState );

	_rasterizerState = graphicsDevice->GetRasterizerState()->Clone();
	_rasterizerState->SetFillMode( FillMode::Solid );
	_rasterizerState->SetCullMode( CullMode::Front );
	_rasterizerState->EnableMultisample( true );
	_billboard->SetRasterizerState( _rasterizerState );
}

Billboard::Billboard( const Billboard& other ) :
	NodeImpl<IBillboard>( other._scene, other._context, AsBaseScene(other._scene)->GetBillboardName(other._name) )
{
}

INodeAnimationController* Billboard::CreateAnimationController(IAnimationSet* animations, AnimationListener* listener)
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new NodeAnimationController( this, _context->GetAnimationSystem(), animations, listener ) : _ctrlAnimation;
}

void Billboard::SetTransform( const Matrix4x4& transform )
{
	ThrowError();
}

void Billboard::SetOrientation( const Quaternion& orientation )
{
	ThrowError();
}

void Billboard::SetOrientationYaw( Float yaw )
{
	ThrowError();
}

void Billboard::SetOrientationPitch( Float pitch )
{
	ThrowError();
}

void Billboard::SetOrientationRoll( Float roll )
{
	ThrowError();
}

IBillboard* Billboard::AsBillboard() const
{
	return (IBillboard*)this;
}

void Billboard::Show( Bool show )
{
	_billboard->Enable( show );
}

Bool Billboard::IsVisible() const
{
	return _billboard->IsEnabled();
}

void Billboard::Update( IViewport* viewport )
{
	// Get viewport camera's position.
	ICamera* camera = viewport->GetCamera();
	assert( camera != nullptr );
	Matrix4x4 transCamera;
	camera->GetWorldTransform( transCamera );
	Vector3 posCamera = transCamera.Translation();

	// Make billboard look at camera.
	Matrix4x4 parentTransform;
	GetParent()->GetWorldTransform( parentTransform, true );
	LookAt( posCamera );
	Matrix4x4 nodeTransform;
	GetTransform( nodeTransform, false );
	const Matrix4x4 worldTransform = parentTransform * nodeTransform;

	// Update vertex parameters.
	IRenderView* view = viewport->GetView();
	IParameterSet* vertexParams = _billboard->GetVertexParameters( view );
	if ( vertexParams == nullptr )
	{
		vertexParams = _billboard->GetProgram()->GetVertexStage()->GetParameters()->Clone( _billboard->ID(), true );
		_billboard->SetVertexParameters( view, vertexParams );
	}
	ProgramParam* paramTransform = vertexParams->GetParam( _paramName );
	vertexParams->Set( paramTransform, worldTransform );
}

void Billboard::ThrowError()
{
	throw InvalidOperationException( L"Cannot explicitly modify billboard orientation." );
}


} // scene


} // synkro
