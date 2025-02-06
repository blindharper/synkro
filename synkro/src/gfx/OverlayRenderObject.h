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
// Purpose: Overlay rendering object implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_OVERLAYRENDEROBJECT_
#define _SYNKRO_GFX_OVERLAYRENDEROBJECT_


#include "config.h"
#include "Classes.h"
#include "RenderObjectImpl.h"
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IParameterSet.h>
#include <gfx/IResourceSet.h>
#include <gfx/IBlendStateSet.h>
#include "Ndc.h"


namespace synkro
{


namespace gfx
{


// Overlay rendering object implementation.
class OverlayRenderObject :
	public RenderObjectImpl<IOverlayRenderObject>
{
public:
	// Constructor & destructor.
	OverlayRenderObject( OverlayRenderQueue* queue, IPrimitive* data, Ndc* ndc );
	~OverlayRenderObject();

	// IOverlayRenderObject methods.
	void													EnableSmoothing( Bool enable );
	void													SetScissorRect( IRect* rect );
	void													SetBlendStates( IBlendStateSet* states );
	void													SetVertexParameters( IParameterSet* params );
	void													SetFragmentParameters( IParameterSet* params );
	void													SetFragmentResources( IResourceSet* resources );
	void													SetElementCount( UInt count );
	void													SetOrder( UInt order );
	Bool													IsSmoothingEnabled() const;
	IRect*													GetScissorRect() const;
	IBlendStateSet*											GetBlendStates() const;
	IParameterSet*											GetVertexParameters() const;
	IParameterSet*											GetFragmentParameters() const;
	IResourceSet*											GetFragmentResources() const;
	UInt													GetElementCount() const;
	UInt													GetOrder() const;

private:
	OverlayRenderQueue*										_queue;
	Bool													_smoothingEnabled;
	P(IRect)												_scissorRect;
	P(IBlendStateSet)										_blendStates;
	P(IParameterSet)										_vertexParams;
	P(IParameterSet)										_fragmentParams;
	P(IResourceSet)											_fragmentResources;
	UInt													_elementCount;
	UInt													_order;
};


#include "OverlayRenderObject.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_OVERLAYRENDEROBJECT_
