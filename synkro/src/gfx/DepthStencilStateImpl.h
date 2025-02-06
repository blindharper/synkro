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
// Purpose: Generic depth-stencil state implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DEPTHSTENCILSTATEIMPL_
#define _SYNKRO_GFX_DEPTHSTENCILSTATEIMPL_


#include "config.h"
#include "RenderStateImpl.h"
#include <gfx/StencilOperation.h>
#include <gfx/CompareFunction.h>


namespace synkro
{


namespace gfx
{


// Generic depth-stencil state implementation.
template <class T>
class DepthStencilStateImpl :
	public RenderStateImpl<T>
{
public:
	// Constructor & destructor.
	DepthStencilStateImpl();
	virtual ~DepthStencilStateImpl();

	// IDepthStencilState methods.
	virtual void											EnableDepth( Bool enable );
	virtual void											EnableDepthWrite( Bool enable );
	virtual void											SetDepthFunction( const CompareFunction& function );
	virtual void											EnableStencil( Bool enable );
	virtual void											SetReadMask( Byte mask );
	virtual void											SetWriteMask( Byte mask );
	virtual void											SetReference( Byte reference );
	virtual void											SetFailOperation( const StencilOperation& operation );
	virtual void											SetFrontFailOperation( const StencilOperation& operation );
	virtual void											SetBackFailOperation( const StencilOperation& operation );
	virtual void											SetDepthFailOperation( const StencilOperation& operation );
	virtual void											SetFrontDepthFailOperation( const StencilOperation& operation );
	virtual void											SetBackDepthFailOperation( const StencilOperation& operation );
	virtual void											SetPassOperation( const StencilOperation& operation );
	virtual void											SetFrontPassOperation( const StencilOperation& operation );
	virtual void											SetBackPassOperation( const StencilOperation& operation );
	virtual void											SetStencilFunction( const CompareFunction& function );
	virtual void											SetFrontStencilFunction( const CompareFunction& function );
	virtual void											SetBackStencilFunction( const CompareFunction& function );
	virtual Bool											IsDepthEnabled() const;
	virtual Bool											IsDepthWriteEnabled() const;
	virtual CompareFunction									GetDepthFunction() const;
	virtual Bool											IsStencilEnabled() const;
	virtual Byte 											GetReadMask() const;
	virtual Byte 											GetWriteMask() const;
	virtual Byte											GetReference() const;
	virtual StencilOperation								GetFrontFailOperation() const;
	virtual StencilOperation								GetBackFailOperation() const;
	virtual StencilOperation								GetFrontDepthFailOperation() const;
	virtual StencilOperation								GetBackDepthFailOperation() const;
	virtual StencilOperation								GetFrontPassOperation() const;
	virtual StencilOperation								GetBackPassOperation() const;
	virtual CompareFunction									GetFrontStencilFunction() const;
	virtual CompareFunction									GetBackStencilFunction() const;

protected:
	Bool													_depthEnabled;
	Bool													_depthWriteEnabled;
	CompareFunction											_depthFunction;

	Bool													_stencilEnabled;
	Byte													_maskRead;
	Byte													_maskWrite;
	Byte													_reference;
	
	StencilOperation										_frontFailOp;
	StencilOperation										_frontDepthFailOp;
	StencilOperation										_frontPassOp;
	CompareFunction											_frontStencilFunction;

	StencilOperation										_backFailOp;
	StencilOperation										_backDepthFailOp;
	StencilOperation										_backPassOp;
	CompareFunction											_backStencilFunction;
};


#include "DepthStencilStateImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DEPTHSTENCILSTATEIMPL_
