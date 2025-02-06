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
// Purpose: Post-processing rendering queue implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_POSTPROCESSRENDERQUEUE_
#define _SYNKRO_GFX_POSTPROCESSRENDERQUEUE_


#include "config.h"
#include "Classes.h"
#include "RenderQueueImpl.h"
#include <gfx/IPostProcessRenderQueue.h>
#include "RenderChain.h"
#include "BlendStateSet.h"
#include "DepthStencilState.h"
#include "RasterizerState.h"
#include <lang/Vector.h>


namespace synkro
{


namespace gfx
{


// Post-processing render item.
class PostProcessRenderItem
{
public:
	// Constructors.
	PostProcessRenderItem( PostProcessRenderObject* object );
	PostProcessRenderItem();

	Bool						operator<( const PostProcessRenderItem& other ) const;

	Program*					Program;
	PostProcessRenderObject*	Object;
	RasterizerState*			RasterizerState;
	DepthStencilState*			StencilState;
	ParameterSet*				FragmentParams;
	P(ResourceSet)				FragmentResources;
	SamplerStateSet*			FragmentSamplers;
	UInt						PassCount;
};


// Post-processing rendering queue implementation.
class PostProcessRenderQueue :
	public RenderQueueImpl<IPostProcessRenderQueue>
{
public:
	// Constructor.
	PostProcessRenderQueue( IGraphicsDevice* device, RenderView* view, IProgram* programPass );

	// IPostProcessRenderQueue methods.
	IPostProcessRenderObject*								CreateObject( IProgram* program );
	void													SetInput( IResource* input );
	IResource*												GetInput() const;

	// Other methods.
	UInt													Process( RenderChain* chain, IPlainRenderTexture* colorTarget );
	void													SetDirty();
	void													Resize();
	Bool													TargetExists( IPlainRenderTexture* target ) const;

private:
	lang::Vector<PostProcessRenderItem>						_items;
	RenderView*												_view;
	IProgram*												_programPass;
	IResource*												_input;
	Bool													_dirty;
	P(BlendStateSet)										_blendStates;
	P(DepthStencilState)									_stencilState;
	P(RasterizerState)										_rasterizerState;
	P(RasterizerState)										_rasterizerStateScissor;

	void													ValidateItem( PostProcessRenderItem& item );
};


#include "PostProcessRenderQueue.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_POSTPROCESSRENDERQUEUE_
