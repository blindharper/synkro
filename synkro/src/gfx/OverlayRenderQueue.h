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
// Purpose: Overlay rendering queue implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_OVERLAYRENDERQUEUE_
#define _SYNKRO_GFX_OVERLAYRENDERQUEUE_


#include "config.h"
#include "Classes.h"
#include "RenderQueueImpl.h"
#include <gfx/IOverlayRenderQueue.h>
#include "RectEx.h"
#include "BlendStateSet.h"
#include "DepthStencilState.h"
#include "RasterizerState.h"
#include "Ndc.h"
#include <lang/Vector.h>


namespace synkro
{


namespace gfx
{


// Overlay render item.
class OverlayRenderItem
{
public:
	// Constructors.
	OverlayRenderItem( OverlayRenderObject* object );
	OverlayRenderItem();

	Bool					operator<( const OverlayRenderItem& other ) const;

	OverlayRenderObject*	Object;
	Program*				Program;
	Primitive*				Data;
	RectEx*					ScissorRect;
	BlendStateSet*			BlendStates;
	RasterizerState*		RasterizerState;
	ParameterSet*			VertexParams;
	ParameterSet*			FragmentParams;
	ResourceSet*			FragmentResources;
	P(SamplerStateSet)		FragmentSamplers;
	UInt					ElementCount;
};


// Overlay rendering object implementation.
class OverlayRenderQueue :
	public RenderQueueImpl<IOverlayRenderQueue>
{
public:
	// Constructors.
	OverlayRenderQueue( IGraphicsDevice* device, UInt width, UInt height );
	OverlayRenderQueue( IGraphicsDevice* device, IRenderWindow* window );

	// IOverlayRenderQueue methods.
	IOverlayRenderObject*									CreateObject( IPrimitive* data );
	IRenderWindow*											GetWindow() const;

	// Other methods.
	void													RemoveObject( OverlayRenderObject* object );
	void													Update();
	UInt													Process();
	void													SetDirty();

private:
	lang::Vector<OverlayRenderItem>							_items;
	IRenderWindow*											_window;
	Ndc														_ndc;
	Bool													_dirty;
	P(BlendStateSet)										_blendStates;
	P(DepthStencilState)									_depthStencilState;
	P(RasterizerState)										_rasterizerState;
	P(RasterizerState)										_rasterizerStateScissor;

	void													Init( IGraphicsDevice* device );
	void													ValidateItem( OverlayRenderItem& item );
};


#include "OverlayRenderQueue.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_OVERLAYRENDERQUEUE_
