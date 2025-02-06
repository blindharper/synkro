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
SYNKRO_INLINE void OverlayRenderObject::EnableSmoothing( Bool enable )
{
	if ( enable != _smoothingEnabled )
	{
		_smoothingEnabled = enable;
		_dirty = true;
	}
}

SYNKRO_INLINE void OverlayRenderObject::SetScissorRect( IRect* rect )
{
	if ( rect != _scissorRect )
	{
		_scissorRect = rect;
		_dirty = true;
	}
}

SYNKRO_INLINE void OverlayRenderObject::SetBlendStates( IBlendStateSet* states )
{
	if ( states != _blendStates )
	{
		_blendStates = states;
		_dirty = true;
	}
}

SYNKRO_INLINE void OverlayRenderObject::SetVertexParameters( IParameterSet* params )
{
	if ( params != _vertexParams )
	{
		_vertexParams = params;
		_dirty = true;
	}
}

SYNKRO_INLINE void OverlayRenderObject::SetFragmentParameters( IParameterSet* params )
{
	if ( params != _fragmentParams )
	{
		_fragmentParams = params;
		_dirty = true;
	}
}

SYNKRO_INLINE void OverlayRenderObject::SetFragmentResources( IResourceSet* resources )
{
	if ( resources != _fragmentResources )
	{
		_fragmentResources = resources;
		_dirty = true;
	}
}

SYNKRO_INLINE Bool OverlayRenderObject::IsSmoothingEnabled() const
{
	return _smoothingEnabled;
}

SYNKRO_INLINE IRect* OverlayRenderObject::GetScissorRect() const
{
	return _scissorRect;
}

SYNKRO_INLINE IBlendStateSet* OverlayRenderObject::GetBlendStates() const
{
	return _blendStates;
}

SYNKRO_INLINE IParameterSet* OverlayRenderObject::GetVertexParameters() const
{
	return _vertexParams;
}

SYNKRO_INLINE IParameterSet* OverlayRenderObject::GetFragmentParameters() const
{
	return _fragmentParams;
}

SYNKRO_INLINE IResourceSet* OverlayRenderObject::GetFragmentResources() const
{
	return _fragmentResources;
}

SYNKRO_INLINE UInt OverlayRenderObject::GetElementCount() const
{
	return _elementCount;
}

SYNKRO_INLINE UInt OverlayRenderObject::GetOrder() const
{
	return _order;
}
