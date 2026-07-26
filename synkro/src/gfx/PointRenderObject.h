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
// Purpose: Point rendering object implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_POINTRENDEROBJECT_
#define _SYNKRO_GFX_POINTRENDEROBJECT_


#include "config.h"
#include "RenderObjectImpl.h"
#include <gfx/IPointRenderObject.h>
#include <gfx/IParameterSet.h>
#include "PointRenderQueue.h"


namespace synkro
{


namespace gfx
{


// Point rendering object implementation.
class PointRenderObject :
	public RenderObjectImpl<IPointRenderObject>
{
public:
	// Constructor & destructor.
	PointRenderObject( PointRenderQueue* queue, IPrimitive* data );
	~PointRenderObject();

	// IPointRenderObject methods.
	void													SetVertexParameters( IParameterSet* params );
	void													SetElementRange( UInt start, UInt count );
	void													SetInstanceRange( UInt start, UInt count );
	IParameterSet*											GetVertexParameters() const;
	UInt													GetStartElement() const;
	UInt													GetElementCount() const;
	UInt													GetStartInstance() const;
	UInt													GetInstanceCount() const;
	IPointRenderQueue*										GetQueue() const;

private:
	PointRenderQueue*										_queue;
	P(IParameterSet)										_vertexParams;
	UInt													_startElement;
	UInt													_elementCount;
	UInt													_startInstance;
	UInt													_instanceCount;
};


#include "PointRenderObject.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_POINTRENDEROBJECT_
