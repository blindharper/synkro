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
// Purpose: Post-processing rendering object implementation.
//==============================================================================
SYNKRO_INLINE void PostProcessRenderObject::SetInput( IResource* input )
{
	if ( input != _input )
	{
		_input = input;
		_dirty = true;
	}
}

SYNKRO_INLINE void PostProcessRenderObject::SetStencil( IPlainDepthTexture* stencil )
{
	if ( stencil != _stencil )
	{
		_stencil = stencil;
		_dirty = true;
	}
}

SYNKRO_INLINE void PostProcessRenderObject::SetScissorRect( IRect* rect )
{
	if ( rect != _scissorRect )
	{
		_scissorRect = rect;
		_dirty = true;
	}
}

SYNKRO_INLINE void PostProcessRenderObject::SetStencilState( IDepthStencilState* state )
{
	if ( state != _stencilState )
	{
		_stencilState = state;
		_dirty = true;
	}
}

SYNKRO_INLINE void PostProcessRenderObject::SetFragmentParameters( IParameterSet* params )
{
	if ( params != _fragmentParams )
	{
		_fragmentParams = params;
		_dirty = true;
	}
}

SYNKRO_INLINE void PostProcessRenderObject::SetFragmentResources( IResourceSet* resources )
{
	if ( resources != _fragmentResources )
	{
		_fragmentResources = resources;
		_dirty = true;
	}
}

SYNKRO_INLINE void PostProcessRenderObject::SetFragmentSamplers( ISamplerStateSet* samplers )
{
	if ( samplers != _fragmentSamplers )
	{
		_fragmentSamplers = samplers;
		_dirty = true;
	}
}

SYNKRO_INLINE void PostProcessRenderObject::SetPassCount( UInt count )
{
	if ( count != _passCount )
	{
		_passCount = count;
		_dirty = true;
	}
}

SYNKRO_INLINE IResource* PostProcessRenderObject::GetInput() const
{
	return _input;
}

SYNKRO_INLINE IPlainRenderTexture* PostProcessRenderObject::GetTarget() const
{
	return _target;
}

SYNKRO_INLINE IPlainDepthTexture* PostProcessRenderObject::GetStencil() const
{
	return _stencil;
}

SYNKRO_INLINE IRect* PostProcessRenderObject::GetScissorRect() const
{
	return _scissorRect;
}

SYNKRO_INLINE IDepthStencilState* PostProcessRenderObject::GetStencilState() const
{
	return _stencilState;
}

SYNKRO_INLINE IParameterSet* PostProcessRenderObject::GetFragmentParameters() const
{
	return _fragmentParams;
}

SYNKRO_INLINE IResourceSet* PostProcessRenderObject::GetFragmentResources() const
{
	return _fragmentResources;
}

SYNKRO_INLINE ISamplerStateSet* PostProcessRenderObject::GetFragmentSamplers() const
{
	return _fragmentSamplers;
}

SYNKRO_INLINE UInt PostProcessRenderObject::GetPassCount() const
{
	return _passCount;
}

SYNKRO_INLINE UInt PostProcessRenderObject::GetOrder() const
{
	return _order;
}
