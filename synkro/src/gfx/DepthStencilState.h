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
// Purpose: Logical depth-stencil state.
//==============================================================================
#ifndef _SYNKRO_GFX_DEPTHSTENCILSTATE_
#define _SYNKRO_GFX_DEPTHSTENCILSTATE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/IDepthStencilState.h>


namespace synkro
{


namespace gfx
{


// Logical depth-stencil state.
class DepthStencilState :
	public core::ObjectImpl<IDepthStencilState>
{
public:
	// Constructors.
	DepthStencilState( IDepthStencilState* state );
	DepthStencilState( const DepthStencilState& other );

	// IRenderState methods.
	void													Bind();

	// IDepthStencilState methods.
	void													EnableDepth( Bool enable );
	void													EnableDepthWrite( Bool enable );
	void													SetDepthFunction( const CompareFunction& function );
	void													EnableStencil( Bool enable );
	void													SetReadMask( Byte mask );
	void													SetWriteMask( Byte mask );
	void													SetReference( Byte reference );
	void													SetFailOperation( const StencilOperation& operation );
	void													SetFrontFailOperation( const StencilOperation& operation );
	void													SetBackFailOperation( const StencilOperation& operation );
	void													SetDepthFailOperation( const StencilOperation& operation );
	void													SetFrontDepthFailOperation( const StencilOperation& operation );
	void													SetBackDepthFailOperation( const StencilOperation& operation );
	void													SetPassOperation( const StencilOperation& operation );
	void													SetFrontPassOperation( const StencilOperation& operation );
	void													SetBackPassOperation( const StencilOperation& operation );
	void													SetStencilFunction( const CompareFunction& function );
	void													SetFrontStencilFunction( const CompareFunction& function );
	void													SetBackStencilFunction( const CompareFunction& function );
	Bool													IsDepthEnabled() const;
	Bool													IsDepthWriteEnabled() const;
	CompareFunction											GetDepthFunction() const;
	Bool													IsStencilEnabled() const;
	Byte 													GetReadMask() const;
	Byte 													GetWriteMask() const;
	Byte													GetReference() const;
	StencilOperation										GetFrontFailOperation() const;
	StencilOperation										GetBackFailOperation() const;
	StencilOperation										GetFrontDepthFailOperation() const;
	StencilOperation										GetBackDepthFailOperation() const;
	StencilOperation										GetFrontPassOperation() const;
	StencilOperation										GetBackPassOperation() const;
	CompareFunction											GetFrontStencilFunction() const;
	CompareFunction											GetBackStencilFunction() const;
	IDepthStencilState*										Clone() const;

private:
	P(IDepthStencilState)									_state;
	Bool													_readonly;

	void													PreventModify();
};


#include "DepthStencilState.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DEPTHSTENCILSTATE_
