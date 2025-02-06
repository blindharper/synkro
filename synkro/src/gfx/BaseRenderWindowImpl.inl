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
// Purpose: Generic base render window implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE BaseRenderWindowImpl<T>::BaseRenderWindowImpl( GraphicsDevice* device, IRenderWindow* renderWindow, UInt width, UInt height, IProgram* programScreen, IProgram* programView, UInt sampleCount ) :
	_views( A(P(RenderView)) ),
	_device( device ),
	_programScreen( programScreen ),
	_programView( programView ),
	_renderWindow( renderWindow ),
	_sampleCount( sampleCount ),
	_ndc( _renderWindow, (_renderWindow != nullptr) ? _renderWindow->GetWidth() : 1, (_renderWindow != nullptr) ? _renderWindow->GetHeight() : 1 ),
	_width( width ),
	_height( height )
{
	// Initialize shared stuff.
	_blendStateDisabled = _device->GetBlendStates()->Clone();
	_blendStateDisabled->Get(0)->Enable( false );
	_blendStateEnabled = _device->GetBlendStates()->Clone();
	_blendStateEnabled->Get(0)->Enable( true );
	_blendStateEnabled->Get(0)->SetSrcMode( BlendMode::SrcAlpha );
	_blendStateEnabled->Get(0)->SetDstMode( BlendMode::InvSrcAlpha );
	
	_depthStencilState = _device->GetDepthStencilState()->Clone();
	_depthStencilState->EnableDepth( false );
	_depthStencilState->EnableStencil( false );
	
	_rasterizerState = _device->GetRasterizerState()->Clone();
	_rasterizerState->SetFillMode( FillMode::Solid );
	_rasterizerState->SetCullMode( CullMode::Back );
	_rasterizerState->EnableScissor( false );

	_rasterizerStateScissor = _device->GetRasterizerState()->Clone();
	_rasterizerStateScissor->SetFillMode( FillMode::Solid );
	_rasterizerStateScissor->SetCullMode( CullMode::Back );
	_rasterizerStateScissor->EnableScissor( true );
	
	_resources = _programScreen->GetFragmentStage()->GetResources()->Clone( (_renderWindow != nullptr) ? _renderWindow->ID() : 0 );
	_samplers = _programScreen->GetFragmentStage()->GetSamplers()->Clone( (_renderWindow != nullptr) ? _renderWindow->ID() : 0 );
	_samplers->Get(0)->SetFilter( TextureFilter::Linear );

	GraphicsDeviceDesc desc;
	_device->GetDesc( desc );
	if ( desc.TopDown )
	{
		_screenTexture = _device->CreateRenderTexture( (_renderWindow != nullptr) ? _renderWindow->GetWidth() : 1, (_renderWindow != nullptr) ? _renderWindow->GetHeight() : 1, (_renderWindow != nullptr) ? _renderWindow->GetPixelFormat() : PixelFormat::R8G8B8A8, 4, 0 );
	}
}

template <class T>
SYNKRO_INLINE BaseRenderWindowImpl<T>::~BaseRenderWindowImpl()
{
}

template <class T>
SYNKRO_INLINE void BaseRenderWindowImpl<T>::Resize()
{
	for ( UInt i = 0; i < _views.Size(); ++i )
	{
		_views[i]->Resize();
	}
	if ( _screen != nullptr )
	{
		_ndc.Update();
		_screen->Update();
		FillScreen();
	}
	if ( _overlays != nullptr )
	{
		_overlays->Update();
	}
	GraphicsDeviceDesc desc;
	_device->GetDesc( desc );
	if ( desc.TopDown )
	{
		_screenTexture = _device->CreateRenderTexture( _renderWindow->GetWidth(), _renderWindow->GetHeight(), _renderWindow->GetPixelFormat(), 4, 0 );
	}
}

template <class T>
SYNKRO_INLINE void BaseRenderWindowImpl<T>::Draw( Double delta, GraphicsStats& stats )
{
	SynkroProfile( "BaseRenderWindowImpl.Draw" );
	
	for ( UInt i = 0; i < _views.Size(); ++i )
	{
		// Skip non-renderable viewports.
		if ( !_views[i]->IsRenderable() )
			continue;

		_views[i]->Draw( delta, stats );
	}
}

template <class T>
SYNKRO_INLINE UInt BaseRenderWindowImpl<T>::DrawLast()
{
	SynkroProfile( "BaseRenderWindowImpl.DrawLast" );

	UInt primitiveCount = 0;

	// Bind shared stuff.
	_programView->Bind();

	_depthStencilState->Bind();
	_samplers->Bind();

	// Process views.
	for ( UInt i = 0; i < _views.Size(); ++i )
	{
		// Skip non-renderable viewports.
		if ( !_views[i]->IsRenderable() )
			continue;

		// Bind states.
		IRect* scissorRect = _views[i]->GetScissorRect();
		if ( scissorRect != nullptr )
		{
			_rasterizerStateScissor->Bind();
			scissorRect->Bind();
		}
		else
		{
			_rasterizerState->Bind();
		}
		_views[i]->GetBlendStates()->Bind();
		_views[i]->GetScreenParams()->Bind();

		// Perform drawing.
		_resources->Set( 0, _views[i]->GetBackBuffer() );
		_resources->Bind();
		_views[i]->GetScreenData()->GetInputBuffers()->Bind();
		primitiveCount += _views[i]->GetScreenData()->Draw( 0, 4, 0, 0 );
	}

	// Draw overlay stuff.
	if ( _overlays != nullptr )
	{
		_overlays->Process();
	}

	return primitiveCount;
}

template <class T>
SYNKRO_INLINE UInt BaseRenderWindowImpl<T>::DrawScreen( IPlainRenderTexture* texture )
{
	SynkroProfile( "BaseRenderWindowImpl.DrawScreen" );

	if ( _screen == nullptr )
	{
		_screen = (Primitive*)_device->CreatePrimitive( _programScreen, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleStrip, IndexType::None, 4, 0, 0, 0, true, false );
		_screen->Prepare( &_ndc );
		FillScreen();
	}

	_programScreen->Bind();
	_blendStateDisabled->Bind();
	_depthStencilState->Bind();
	_rasterizerState->Bind();
	_resources->Set( 0, texture );
	_resources->Bind();
	_samplers->Bind();
	_screen->GetInputBuffers()->Bind();
	return _screen->Draw( 0, 4, 0, 0 );
}

template <class T>
SYNKRO_INLINE IPlainRenderTexture* BaseRenderWindowImpl<T>::GetIntermediateTarget() const
{
	return _screenTexture;
}

template <class T>
SYNKRO_INLINE void BaseRenderWindowImpl<T>::CreateOverlay()
{
	if ( _overlays == nullptr )
	{
		_overlays = (_renderWindow != nullptr) ? new OverlayRenderQueue( (IGraphicsDevice*)_device, _renderWindow ) : new OverlayRenderQueue( (IGraphicsDevice*)_device, _width, _height );
	}
}

template <class T>
SYNKRO_INLINE void BaseRenderWindowImpl<T>::FillScreen()
{
	const Float width = CastFloat( _renderWindow->GetWidth() );
	const Float height = CastFloat( _renderWindow->GetHeight() );
	
	P(IVector4Stream) streamPos = (IVector4Stream*)_screen->GetVertexStream( DataStream::Position2D, 0 );
	if ( (streamPos != nullptr) && streamPos->Open(io::OpenMode::Write) )
	{
		math::Vector4 pos[] =
		{
			math::Vector4( 0.0f,	0.0f,	0.0f, 1.0f ),
			math::Vector4( 0.0f,	height,	0.0f, 1.0f ),
			math::Vector4( width,	0.0f,	0.0f, 1.0f ),
			math::Vector4( width,	height,	0.0f, 1.0f ),
		};
		streamPos->Write( pos, 4 );
		streamPos->Close();
	}

	P(IVector2Stream) streamTexCoord = (IVector2Stream*)_screen->GetVertexStream( DataStream::TexCoord2D, 0 );
	if ( (streamTexCoord != nullptr) && streamTexCoord->Open(io::OpenMode::Write) )
	{
		math::Vector2 coords[] = 
		{
			math::Vector2( 0.0f, 0.0f ),
			math::Vector2( 0.0f, 1.0f ),
			math::Vector2( 1.0f, 0.0f ),
			math::Vector2( 1.0f, 1.0f ),
		};
		streamTexCoord->Write( coords, 4 );
		streamTexCoord->Close();
	}
}
