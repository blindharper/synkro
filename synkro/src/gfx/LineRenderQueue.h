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
// Purpose: Line rendering queue implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_LINERENDERQUEUE_
#define _SYNKRO_GFX_LINERENDERQUEUE_


#include "config.h"
#include "Classes.h"
#include "RenderQueueImpl.h"
#include <gfx/ILineRenderQueue.h>
#include <gfx/GraphicsStats.h>
#include "BlendStateSet.h"
#include "DepthStencilState.h"
#include "RasterizerState.h"
#include <lang/Vector.h>


namespace synkro
{


namespace gfx
{


// Line render item.
class LineRenderItem
{
public:
	// Constructors.
	LineRenderItem( LineRenderObject* object );
	LineRenderItem();

	LineRenderObject*	Object;
	Primitive*			Data;
	ParameterSet*		VertexParams;
	UInt				StartElement;
	UInt				ElementCount;
	UInt				StartInstance;
	UInt				InstanceCount;
};


// Line rendering queue implementation.
class LineRenderQueue :
	public RenderQueueImpl<ILineRenderQueue>
{
public:
	// Constructor.
	LineRenderQueue( IGraphicsSystemEx* graphicsSystem );

	// ILineRenderQueue methods.
	ILineRenderObject*										CreateObject( IPrimitive* data );

	// Other methods.
	void													RemoveObject( LineRenderObject* object );
	void													Process( GraphicsStats& stats );

private:
	lang::Vector<LineRenderItem>							_items;
	lang::Vector<LineRenderItem>							_items4D;
	lang::Vector<LineRenderItem>							_itemsColored;
	lang::Vector<LineRenderItem>							_items4DColored;
	lang::Vector<LineRenderItem>							_itemsInstanced;
	lang::Vector<LineRenderItem>							_itemsColoredInstanced;
	Program*												_program;
	Program*												_program4D;
	Program*												_programColored;
	Program*												_program4DColored;
	Program*												_programInstanced;
	P(BlendStateSet)										_blendStates;
	P(DepthStencilState)									_depthStencilState;
	P(RasterizerState)										_rasterizerState;

	void													ProcessItems( IProgram* program, lang::Vector<LineRenderItem>& items, GraphicsStats& stats );
	Bool													RemoveObject( lang::Vector<LineRenderItem>& items, LineRenderObject* object );
	void													ValidateItem( LineRenderItem& item );
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_LINERENDERQUEUE_
