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
// Purpose: Line rendering object implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_LINERENDEROBJECT_
#define _SYNKRO_GFX_LINERENDEROBJECT_


#include "config.h"
#include "RenderObjectImpl.h"
#include <gfx/ILineRenderObject.h>
#include <gfx/IParameterSet.h>
#include "LineRenderQueue.h"


namespace synkro
{


namespace gfx
{


// Line rendering object implementation.
class LineRenderObject :
	public RenderObjectImpl<ILineRenderObject>
{
public:
	// Constructor & destructor.
	LineRenderObject( LineRenderQueue* queue, IPrimitive* data );
	~LineRenderObject();

	// ILineRenderObject methods.
	void													SetVertexParameters( IParameterSet* params );
	void													SetElementRange( UInt start, UInt count );
	void													SetInstanceRange( UInt start, UInt count );
	IParameterSet*											GetVertexParameters() const;
	UInt													GetStartElement() const;
	UInt													GetElementCount() const;
	UInt													GetStartInstance() const;
	UInt													GetInstanceCount() const;
	ILineRenderQueue*										GetQueue() const;

private:
	LineRenderQueue*										_queue;
	P(IParameterSet)										_vertexParams;
	UInt													_startElement;
	UInt													_elementCount;
	UInt													_startInstance;
	UInt													_instanceCount;
};


#include "LineRenderObject.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_LINERENDEROBJECT_
