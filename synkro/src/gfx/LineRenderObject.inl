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
SYNKRO_INLINE void LineRenderObject::SetVertexParameters( IParameterSet* params )
{
	if ( params != _vertexParams )
	{
		_vertexParams = params;
		_dirty = true;
	}
}

SYNKRO_INLINE IParameterSet* LineRenderObject::GetVertexParameters() const
{
	return _vertexParams;
}

SYNKRO_INLINE UInt LineRenderObject::GetStartElement() const
{
	return _startElement;
}

SYNKRO_INLINE UInt LineRenderObject::GetElementCount() const
{
	return _elementCount;
}

SYNKRO_INLINE UInt LineRenderObject::GetStartInstance() const
{
	return _startInstance;
}

SYNKRO_INLINE UInt LineRenderObject::GetInstanceCount() const
{
	return _instanceCount;
}

SYNKRO_INLINE ILineRenderQueue* LineRenderObject::GetQueue() const
{
	return _queue;
}
