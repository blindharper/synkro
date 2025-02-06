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
#ifndef _SYNKRO_GFX_RENDERVIEW_
#define _SYNKRO_GFX_RENDERVIEW_


#include "config.h"
#include "Classes.h"
#include <lang/Set.h>
#include <gfx/IRenderView.h>
#include <gfx/ISceneRenderObject.h>
#include <gfx/ILineRenderQueue.h>
#include <gfx/IPlainRenderTexture.h>
#include <gfx/IPlainDepthTexture.h>
#include <gfx/IResourceSet.h>
#include <gfx/IParameterSet.h>
#include <gfx/GraphicsStats.h>
#include "SceneRenderQueue.h"
#include "PostProcessRenderQueue.h"
#include "Primitive.h"
#include "RenderChain.h"
#include "RenderChainImpl.h"


namespace synkro
{


namespace gfx
{


// Display viewport.
class RenderView :
	public core::ObjectImpl<IRenderView>,
	public RenderChainImpl<RenderChain>
{
public:
	// Constructors.
	RenderView( GraphicsDevice* device, IRenderWindow* window, IProgram* programPass, IProgram* program, IBlendStateSet* blendStateEnabled, IBlendStateSet* blendStateDisabled, const img::PixelFormat& format, const DepthFormat& depthFormat, Int left, Int top, UInt width, UInt height, UInt sampleCount, const math::Vector4& color );
	RenderView();

	// IRenderView methods.
	void													Show( Bool show );
	void													SetBounds( Int left, Int top, Int right, Int bottom );
	void													SetBackColor( const math::Vector4& color );
	void													SetOverlayColor( const math::Vector4& color );
	void													SetFillMode( const FillMode& fill );
	void													SetChannelMask( const img::PixelChannel& mask );
	void													SetLeftChannelMask( const img::PixelChannel& mask );
	void													SetRightChannelMask( const img::PixelChannel& mask );
	void													SetScissorRect( IRect* rect );
	void													SetVertexParams( IParameterSet* params );
	void													SetVertexResources( IResourceSet* resources );
	void													SetFragmentParams( IParameterSet* params );
	void													SetLeftChannelVertexParams( IParameterSet* params );
	void													SetRightChannelVertexParams( IParameterSet* params );
	void													SetColorTarget( IPlainRenderTexture* target );
	void													SetDepthTarget( IPlainDepthTexture* target );
	void													SetQueue( ISceneRenderQueue* queue );
	void													MakeOverlay( ISceneRenderObject* object, Bool overlay );
	void													ShowStencil( Bool show );
	void													EnablePostProcess();
	Bool													IsVisible() const;
	void													GetBounds( Int& left, Int& top, Int& right, Int& bottom ) const;
	void													GetBackColor( math::Vector4& color ) const;
	void													GetOverlayColor( math::Vector4& color ) const;
	FillMode												GetFillMode() const;
	img::PixelChannel										GetLeftChannelMask() const;
	img::PixelChannel										GetRightChannelMask() const;
	IRect*													GetScissorRect() const;
	IParameterSet*											GetVertexParams() const;
	IResourceSet*											GetVertexResources() const;
	IParameterSet*											GetFragmentParams() const;
	IParameterSet*											GetLeftChannelVertexParams() const;
	IParameterSet*											GetRightChannelVertexParams() const;
	IPlainRenderTexture*									GetColorTarget() const;
	IPlainDepthTexture*										GetDepthTarget() const;
	ISceneRenderQueue*										GetQueue() const;
	Bool													IsOverlay( ISceneRenderObject* object ) const;
	IPostProcessRenderQueue*								GetPostProcessQueue() const;
	IRenderWindow*											GetWindow() const;
	void													GetStats( RenderViewStats& stats ) const;

	// Other methods.
	void													Resize();
	void													Draw( Double delta, GraphicsStats& stats );
	Bool													IsRenderable() const;
	IPrimitiveEx*											GetData() const;
	IPrimitiveEx*											GetQuadData() const;
	IPrimitiveEx*											GetScreenData() const;
	IParameterSet*											GetScreenParams() const;
	IBlendStateSet*											GetBlendStates() const;

private:
	IRenderWindow*											_window;
	IProgram*												_programPass;
	IProgram*												_program;
	SceneRenderQueue*										_scene;
	P(PostProcessRenderQueue)								_postProcess;
	IPlainRenderTexture*									_colorTarget;
	IPlainDepthTexture*										_depthTarget;
	P(IBlendStateSet)										_blendStateDisabled;
	P(IBlendStateSet)										_blendStateEnabled;
	P(IRect)												_scissorRect;
	IParameterSet*											_vertexParams;
	IResourceSet*											_vertexResources;
	IParameterSet*											_fragmentParams;
	IParameterSet*											_leftVertexParams;
	IParameterSet*											_rightVertexParams;

	P(IPlainRenderTexture)									_colorTexture;
	P(IPlainDepthTexture)									_depthTexture;
	GraphicsDevice*											_device;
	P(Primitive)											_data;
	Ndc														_dataNdc;
	P(Primitive)											_screen;
	Ndc														_screenNdc;
	P(Primitive)											_quad;

	Bool													_visible;
	Bool													_showStencil;
	Int														_left;
	Int														_top;
	UInt													_width;
	UInt													_height;
	UInt													_windowWidth;
	UInt													_windowHeight;
	UInt													_sampleCount;
	FillMode												_fill;
	img::PixelChannel										_leftMask;
	img::PixelChannel										_rightMask;
	img::PixelFormat										_format;
	DepthFormat												_depthFormat;
	math::Vector4											_backColor;
	math::Vector4											_overlayColor;
	P(IParameterSet)										_params;
	ProgramParam*											_paramColor;
	UInt													_frameCount;
	mutable Bool											_gatherStats;
	RenderViewStats											_stats;
	Double													_delta;

	typedef lang::SetItem<UInt>								OverlayEntry;
	lang::Set<UInt>											_overlays;

	void													CreateTextures();
	void													FillData( IPrimitiveEx* data, Int left, Int top, UInt width, UInt height );
};


#include "RenderView.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RENDERVIEW_
