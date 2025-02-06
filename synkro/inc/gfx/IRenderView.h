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
// Purpose: Defines rendering view.
//==============================================================================
#ifndef _SYNKRO_GFX_IRENDERVIEW_
#define _SYNKRO_GFX_IRENDERVIEW_


#include "config.h"
#include <core/IObject.h>
#include <math/Vector4.h>
#include <gfx/FillMode.h>
#include <gfx/RenderViewStats.h>
#include <img/PixelChannel.h>


namespace synkro
{


namespace gfx
{


/**
 * Rendering view.
 */
iface IRenderView :
	public core::IObject
{
public:
	/**
	 * Sets view visibility.
	 * @param show Set to true to make view visible, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/**
	 * Sets view origin and dimensions.
	 * @param left Left view coordinate relative to the owner window.
	 * @param top Top view coordinate relative to the owner window.
	 * @param right Right view coordinate relative to the owner window.
	 * @param bottom Bottom view coordinate relative to the owner window.
	 */
	virtual void											SetBounds( Int left, Int top, Int right, Int bottom ) = 0;

	/**
	 * Sets view's back color.
	 * @param color New back color.
	 */
	virtual void											SetBackColor( const math::Vector4& color ) = 0;

	/**
	 * Sets view's overlay color.
	 * @param color New overlay color.
	 */
	virtual void											SetOverlayColor( const math::Vector4& color ) = 0;

	/** 
	 * Sets view fill mode.
	 * @param fill View fill mode.
	 */
	virtual void											SetFillMode( const FillMode& fill ) = 0;

	/** 
	 * Sets write mask for the entire rendering target.
	 * @param mask Write mask.
	 */
	virtual void											SetChannelMask( const img::PixelChannel& mask ) = 0;

	/** 
	 * Sets write mask for the left channel of the rendering target.
	 * @param mask Write mask.
	 */
	virtual void											SetLeftChannelMask( const img::PixelChannel& mask ) = 0;

	/** 
	 * Sets write mask for the right channel of the rendering target.
	 * @param mask Write mask.
	 */
	virtual void											SetRightChannelMask( const img::PixelChannel& mask ) = 0;

	/**
	 * Sets scissor rectangle used to render the view. The rectangle is specified in the owner window's coordinates.
	 */
	virtual void											SetScissorRect( IRect* rect ) = 0;

	/** 
	 * Sets vertex program parameters for the entire rendering target.
	 * @param params Program parameters.
	 */
	virtual void											SetVertexParams( IParameterSet* params ) = 0;

	/** 
	 * Sets vertex program resources for the view.
	 * @param resources Program resources.
	 */
	virtual void											SetVertexResources( IResourceSet* resources ) = 0;

	/** 
	 * Sets fragment program parameters for the entire rendering target.
	 * @param params Program parameters.
	 */
	virtual void											SetFragmentParams( IParameterSet* params ) = 0;

	/** 
	 * Sets vertex program parameters for the left channel of the rendering target.
	 * @param params Program parameters.
	 */
	virtual void											SetLeftChannelVertexParams( IParameterSet* params ) = 0;

	/** 
	 * Sets vertex program parameters for the right channel of the rendering target.
	 * @param params Program parameters.
	 */
	virtual void											SetRightChannelVertexParams( IParameterSet* params ) = 0;

	/**
	 * Sets optional color rendering target to render scene queue to it.
	 * @param target Color rendering target.
	 */
	virtual void											SetColorTarget( IPlainRenderTexture* target ) = 0;

	/**
	 * Sets optional depth rendering target to render scene queue to it.
	 * @param target Depth rendering target.
	 */
	virtual void											SetDepthTarget( IPlainDepthTexture* target ) = 0;

	/**
	 * Sets scene rendering queue.
	 * @param queue Rendering queue used to draw the scene.
	 */
	virtual void											SetQueue( ISceneRenderQueue* queue ) = 0;

	/**
	 * Makes the object render before or after the post-processing phase.
	 * @param object Object which rendering in this view to change.
	 * @param overlay False to make the object render before the post-processing phase, true otherwise.
	 */
	virtual void											MakeOverlay( ISceneRenderObject* object, Bool overlay ) = 0;

	/** 
	 * Enables or disables stencil display mode.
	 * @param show Indicates whether to visualize stencil buffer contents.
	 */
	virtual void											ShowStencil( Bool show ) = 0;

	/** 
	 * Enables post-processing for this view.
	 */
	virtual void											EnablePostProcess() = 0;

	/**
	 * Indicates whether the view is currently visible.
	 */
	virtual Bool											IsVisible() const = 0;

	/**
	 * Retrieves view origin and dimensions.
	 * @param [out] left Left view coordinate relative to the owner window.
	 * @param [out] top Top view coordinate relative to the owner window.
	 * @param [out] right Right view coordinate relative to the owner window.
	 * @param [out] bottom Bottom view coordinate relative to the owner window.
	 */
	virtual void											GetBounds( Int& left, Int& top, Int& right, Int& bottom ) const = 0;

	/**
	 * Retrieves view's back color.
	 * @param [out] color Back color.
	 */
	virtual void											GetBackColor( math::Vector4& color ) const = 0;

	/**
	 * Retrieves view's overlay color.
	 * @param [out] color Overlay color.
	 */
	virtual void											GetOverlayColor( math::Vector4& color ) const = 0;

	/** 
	 * Retrieves view fill mode.
	 */
	virtual FillMode										GetFillMode() const = 0;

	/** 
	 * Retrieves write mask for the left channel of the rendering target.
	 */
	virtual img::PixelChannel								GetLeftChannelMask() const = 0;

	/** 
	 * Retrieves write mask for the right channel of the rendering target.
	 */
	virtual img::PixelChannel								GetRightChannelMask() const = 0;

	/**
	 * Retrieves scissor rectangle used to render the view.
	 */
	virtual IRect*											GetScissorRect() const = 0;

	/** 
	 * Retrieves vertex program parameters for the entire rendering target.
	 */
	virtual IParameterSet*									GetVertexParams() const = 0;

	/** 
	 * Retrieves vertex program resources for the view.
	 */
	virtual IResourceSet*									GetVertexResources() const = 0;

	/** 
	 * Retrieves fragment program parameters for the entire rendering target.
	 */
	virtual IParameterSet*									GetFragmentParams() const = 0;

	/** 
	 * Retrieves vertex program parameters for the left channel of the rendering target.
	 */
	virtual IParameterSet*									GetLeftChannelVertexParams() const = 0;

	/** 
	 * Retrieves vertex program parameters for the right channel of the rendering target.
	 */
	virtual IParameterSet*									GetRightChannelVertexParams() const = 0;

	/**
	 * Retrieves color rendering target.
	 */
	virtual IPlainRenderTexture*							GetColorTarget() const = 0;

	/**
	 * Retrieves depth rendering target.
	 */
	virtual IPlainDepthTexture*								GetDepthTarget() const = 0;

	/**
	 * Retrieves scene rendering queue.
	 */
	virtual ISceneRenderQueue*								GetQueue() const = 0;

	/**
	 * Indicates whether the given object is rendered after the post-processing phase.
	 * @param object Object to test.
	 */
	virtual Bool											IsOverlay( ISceneRenderObject* object ) const = 0;

	/**
	 * Retrieves post-processing rendering queue.
	 */
	virtual IPostProcessRenderQueue*						GetPostProcessQueue() const = 0;

	/**
	 * Retrieves owner window.
	 */
	virtual IRenderWindow*									GetWindow() const = 0;

	/**
	 * Retrieves rendering statistics.
	 */
	virtual void											GetStats( RenderViewStats& stats ) const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IRENDERVIEW_
