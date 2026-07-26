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
// Purpose: Point rendering queue implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_POINTRENDERQUEUE_
#define _SYNKRO_GFX_POINTRENDERQUEUE_


#include "config.h"
#include "Classes.h"
#include "RenderQueueImpl.h"
#include <gfx/IPointRenderQueue.h>
#include <gfx/GraphicsStats.h>
#include "BlendStateSet.h"
#include "DepthStencilState.h"
#include "RasterizerState.h"
#include <lang/Vector.h>


namespace synkro
{


namespace gfx
{


// Point render item.
class PointRenderItem
{
public:
	// Constructors.
	PointRenderItem( PointRenderObject* object );
	PointRenderItem();

	PointRenderObject*	Object;
	Primitive*			Data;
	ParameterSet*		VertexParams;
	UInt				StartElement;
	UInt				ElementCount;
	UInt				StartInstance;
	UInt				InstanceCount;
};


// Point rendering queue implementation.
class PointRenderQueue :
	public RenderQueueImpl<IPointRenderQueue>
{
public:
	// Constructor.
	PointRenderQueue( IGraphicsSystemEx* graphicsSystem );

	// IPointRenderQueue methods.
	IPointRenderObject*										CreateObject( IPrimitive* data );

	// Other methods.
	void													RemoveObject( PointRenderObject* object );
	void													Process( GraphicsStats& stats );

private:
	lang::Vector<PointRenderItem>							_items;
	Program*												_program;
	Program*												_programColored;
	Program*												_programInstanced;
	P(BlendStateSet)										_blendStates;
	P(DepthStencilState)									_depthStencilState;
	P(RasterizerState)										_rasterizerState;

	void													ProcessItems( IProgram* program, lang::Vector<PointRenderItem>& items, GraphicsStats& stats );
	Bool													RemoveObject( lang::Vector<PointRenderItem>& items, PointRenderObject* object );
	void													ValidateItem( PointRenderItem& item );
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_POINTRENDERQUEUE_
