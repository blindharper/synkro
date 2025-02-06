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
// Purpose: Rendering view implementation.
//==============================================================================
SYNKRO_INLINE void RenderView::Show( Bool show )
{
	_visible = show;
}

SYNKRO_INLINE void RenderView::SetBounds( Int left, Int top, Int right, Int bottom )
{
	_left = left; _top = top; _width = (right-left); _height = (bottom-top);
	FillData( _screen, _left, _top, _width, _height );
}

SYNKRO_INLINE void RenderView::SetBackColor( const math::Vector4& color )
{
	if ( color != _backColor )
	{
		_backColor = color;
		this->GetColorTarget()->SetDefaultColor( _backColor );
	}
}

SYNKRO_INLINE void RenderView::SetOverlayColor( const math::Vector4& color )
{
	if ( color != _overlayColor )
	{
		_overlayColor = color;
		_params->Set( _paramColor, _overlayColor );
	}
}

SYNKRO_INLINE void RenderView::SetFillMode( const FillMode& fill )
{
	_fill = fill;
}

SYNKRO_INLINE void RenderView::SetChannelMask( const img::PixelChannel& mask )
{
	SetLeftChannelMask( mask );
	SetRightChannelMask( mask );
}

SYNKRO_INLINE void RenderView::SetLeftChannelMask( const img::PixelChannel& mask )
{
	_leftMask = mask;
}

SYNKRO_INLINE void RenderView::SetRightChannelMask( const img::PixelChannel& mask )
{
	_rightMask = mask;
}

SYNKRO_INLINE void RenderView::SetScissorRect( IRect* rect )
{
	_scissorRect = rect;
}

SYNKRO_INLINE void RenderView::SetVertexParams( IParameterSet* params )
{
	_vertexParams = params;
}

SYNKRO_INLINE void RenderView::SetVertexResources( IResourceSet* resources )
{
	_vertexResources = resources;
}

SYNKRO_INLINE void RenderView::SetFragmentParams( IParameterSet* params )
{
	_fragmentParams = params;
}

SYNKRO_INLINE void RenderView::SetLeftChannelVertexParams( IParameterSet* params )
{
	_leftVertexParams = params;
}

SYNKRO_INLINE void RenderView::SetRightChannelVertexParams( IParameterSet* params )
{
	_rightVertexParams = params;
}

SYNKRO_INLINE void RenderView::SetColorTarget( IPlainRenderTexture* target )
{
	_colorTarget = (target != nullptr) ? target : _colorTexture;
}

SYNKRO_INLINE void RenderView::SetDepthTarget( IPlainDepthTexture* target )
{
	_depthTarget = (target != nullptr) ? target : _depthTexture;
}

SYNKRO_INLINE void RenderView::SetQueue( ISceneRenderQueue* queue )
{
	_scene = (SceneRenderQueue*)queue;
}

SYNKRO_INLINE void RenderView::MakeOverlay( ISceneRenderObject* object, Bool overlay )
{
	assert( object != nullptr );

	if ( overlay )
	{
		if ( !_overlays.Contains(object->ID()) )
			_overlays.Put( object->ID() );
	}
	else
	{
		if ( _overlays.Contains(object->ID()) )
			_overlays.Remove( object->ID() );
	}
}

SYNKRO_INLINE void RenderView::ShowStencil( Bool show )
{
	_showStencil = show;
}

SYNKRO_INLINE Bool RenderView::IsVisible() const
{
	return _visible;
}

SYNKRO_INLINE void RenderView::GetBounds( Int& left, Int& top, Int& right, Int& bottom ) const
{
	left	= _left;
	top		= _top;
	right	= _left+_width;
	bottom	= _top+_height;
}

SYNKRO_INLINE void RenderView::GetBackColor( math::Vector4& color ) const
{
	color = _backColor;
}

SYNKRO_INLINE void RenderView::GetOverlayColor( math::Vector4& color ) const
{
	color = _overlayColor;
}

SYNKRO_INLINE FillMode RenderView::GetFillMode() const
{
	return _fill;
}

SYNKRO_INLINE img::PixelChannel RenderView::GetLeftChannelMask() const
{
	return _leftMask;
}

SYNKRO_INLINE img::PixelChannel RenderView::GetRightChannelMask() const
{
	return _rightMask;
}

SYNKRO_INLINE IRect* RenderView::GetScissorRect() const
{
	return _scissorRect;
}

SYNKRO_INLINE IParameterSet* RenderView::GetVertexParams() const
{
	return _vertexParams;
}

SYNKRO_INLINE IResourceSet* RenderView::GetVertexResources() const
{
	return _vertexResources;
}

SYNKRO_INLINE IParameterSet* RenderView::GetFragmentParams() const
{
	return _fragmentParams;
}

SYNKRO_INLINE IParameterSet* RenderView::GetLeftChannelVertexParams() const
{
	return _leftVertexParams;
}

SYNKRO_INLINE IParameterSet* RenderView::GetRightChannelVertexParams() const
{
	return _rightVertexParams;
}

SYNKRO_INLINE IPlainRenderTexture* RenderView::GetColorTarget() const
{
	return _colorTarget;
}

SYNKRO_INLINE IPlainDepthTexture* RenderView::GetDepthTarget() const
{
	return _depthTarget;
}

SYNKRO_INLINE ISceneRenderQueue* RenderView::GetQueue() const
{
	return (ISceneRenderQueue*)_scene;
}

SYNKRO_INLINE Bool RenderView::IsOverlay( ISceneRenderObject* object ) const
{
	return (object != nullptr) && _overlays.Contains( object->ID() );
}

SYNKRO_INLINE IPostProcessRenderQueue* RenderView::GetPostProcessQueue() const
{
	return _postProcess;
}

SYNKRO_INLINE IRenderWindow* RenderView::GetWindow() const
{
	return _window;
}

SYNKRO_INLINE void RenderView::GetStats( RenderViewStats& stats ) const
{
	_gatherStats = true;
	stats = _stats;
}

SYNKRO_INLINE Bool RenderView::IsRenderable() const
{
	return _visible && (_overlayColor.w > 0.01f);
}

SYNKRO_INLINE IPrimitiveEx* RenderView::GetData() const
{
	return _data;
}

SYNKRO_INLINE IPrimitiveEx* RenderView::GetQuadData() const
{
	return _quad;
}

SYNKRO_INLINE IPrimitiveEx* RenderView::GetScreenData() const
{
	return _screen;
}

SYNKRO_INLINE IParameterSet* RenderView::GetScreenParams() const
{
	return _params;
}

SYNKRO_INLINE IBlendStateSet* RenderView::GetBlendStates() const
{
	return (_overlayColor.w == 1.0f) ? _blendStateDisabled : _blendStateEnabled;
}
