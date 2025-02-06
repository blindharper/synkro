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
// Purpose: Defines depth-stencil state.
//==============================================================================
#ifndef _SYNKRO_GFX_IDEPTHSTENCILSTATE_
#define _SYNKRO_GFX_IDEPTHSTENCILSTATE_


#include "config.h"
#include <gfx/IRenderState.h>
#include <gfx/CompareFunction.h>
#include <gfx/StencilOperation.h>


namespace synkro
{


namespace gfx
{


/**
 * Depth-stencil state.
 */
iface IDepthStencilState :
	public IRenderState
{
public:
	/**
	 * Turns depth buffer test on or off. Default is true.
	 * @param enable True to enable depth buffer test, false to disable it.
	 */
	virtual void											EnableDepth( Bool enable ) = 0;

	/**
	 * Turns writing to the depth buffer on or off. Default is true.
	 * @param enable True to enable writing to depth buffer, false to disable it.
	 */
	virtual void											EnableDepthWrite( Bool enable ) = 0;

	/**
	 * Sets depth buffer comparison function. Default is LessOrEqual.
	 * @param function Comparison function.
	 */
	virtual void											SetDepthFunction( const CompareFunction& function ) = 0;

	/**
	 * Turns stencil buffer test on or off. Default is false.
	 * @param enable True to enable stencil buffer test, false to disable it.
	 */
	virtual void											EnableStencil( Bool enable ) = 0;

	/**
	 * Sets a mask applied to the reference value and each stencil buffer 
	 * entry to determine the significant bits for the stencil test. Default is 0xff.
	 * @param mask Read mask.
	 */
	virtual void											SetReadMask( Byte mask ) = 0;

	/**
	 * Sets write mask applied to values written into the stencil buffer. Default is 0xff.
	 * @param mask Write mask.
	 */
	virtual void											SetWriteMask( Byte mask ) = 0;

	/**
	 * Sets reference value for the stencil test. Default is 0x00.
	 * @param reference Reference value.
	 */
	virtual void											SetReference( Byte reference ) = 0;

	/**
	 * Sets stencil operation to perform if stencil test fails. Default is None.
	 * @param operation Stencil operation.
	 */
	virtual void											SetFailOperation( const StencilOperation& operation ) = 0;

	/**
	 * Sets stencil operation to perform if stencil test fails (for front faces). Default is None.
	 * @param operation Stencil operation.
	 */
	virtual void											SetFrontFailOperation( const StencilOperation& operation ) = 0;

	/**
	 * Sets stencil operation to perform if stencil test fails (for back faces). Default is None.
	 * @param operation Stencil operation.
	 */
	virtual void											SetBackFailOperation( const StencilOperation& operation ) = 0;

	/**
	 * Sets stencil operation to perform if stencil test passes but depth test fails. Default is None.
	 * @param operation Stencil operation.
	 */
	virtual void											SetDepthFailOperation( const StencilOperation& operation ) = 0;

	/**
	 * Sets stencil operation to perform if stencil test passes but depth test fails (for front faces). Default is None.
	 * @param operation Stencil operation.
	 */
	virtual void											SetFrontDepthFailOperation( const StencilOperation& operation ) = 0;

	/**
	 * Sets stencil operation to perform if stencil test passes but depth test fails (for back faces). Default is None.
	 * @param operation Stencil operation.
	 */
	virtual void											SetBackDepthFailOperation( const StencilOperation& operation ) = 0;
	
	/**
	 * Sets stencil operation to perform if both stencil test and depth test passes. Default is None.
	 * @param operation Stencil operation.
	 */
	virtual void											SetPassOperation( const StencilOperation& operation ) = 0;

	/**
	 * Sets stencil operation to perform if both stencil test and depth test passes (for front faces). Default is None.
	 * @param operation Stencil operation.
	 */
	virtual void											SetFrontPassOperation( const StencilOperation& operation ) = 0;

	/**
	 * Sets stencil operation to perform if both stencil test and depth test passes (for back faces). Default is None.
	 * @param operation Stencil operation.
	 */
	virtual void											SetBackPassOperation( const StencilOperation& operation ) = 0;

	/**
	 * Sets stencil buffer comparison function. Default is Always.
	 * @param function Comparison function.
	 */
	virtual void											SetStencilFunction( const CompareFunction& function ) = 0;

	/**
	 * Sets stencil buffer comparison function (for front faces). Default is Always.
	 * @param function Comparison function.
	 */
	virtual void											SetFrontStencilFunction( const CompareFunction& function ) = 0;

	/**
	 * Sets stencil buffer comparison function (for back faces). Default is Always.
	 * @param function Comparison function.
	 */
	virtual void											SetBackStencilFunction( const CompareFunction& function ) = 0;

	/**
	 * Indicates whether the depth buffer test is enabled.
	 * @return True if depth buffer test is enabled, or false otherwise.
	 */
	virtual Bool											IsDepthEnabled() const = 0;

	/**
	 * Indicates whether the writing to depth buffer test is enabled.
	 * @return True if writing to the depth buffer is enabled, or false otherwise.
	 */
	virtual Bool											IsDepthWriteEnabled() const = 0;

	/**
	 * Retrieves depth buffer comparison function.
	 */
	virtual CompareFunction									GetDepthFunction() const = 0;

	/**
	 * Indicates whether the stencil buffer test is enabled.
	 * @return True if stencil buffer test is enabled, or false otherwise.
	 */
	virtual Bool											IsStencilEnabled() const = 0;

	/**
	 * Retrieves mask applied to the reference value and each stencil buffer 
	 * entry to determine the significant bits for the stencil test.
	 */
	virtual Byte											GetReadMask() const = 0;

	/**
	 * Retrieves write mask applied to values written into the stencil buffer.
	 */
	virtual Byte											GetWriteMask() const = 0;

	/**
	 * Retrieves reference value for the stencil test.
	 */
	virtual Byte											GetReference() const = 0;

	/**
	 * Retrieves stencil operation to perform if stencil test fails (for front faces).
	 */
	virtual StencilOperation								GetFrontFailOperation() const = 0;

	/**
	 * Retrieves stencil operation to perform if stencil test fails (for back faces).
	 */
	virtual StencilOperation								GetBackFailOperation() const = 0;

	/**
	 * Retrieves stencil operation to perform if stencil test passes but depth test fails (for front faces).
	 */
	virtual StencilOperation								GetFrontDepthFailOperation() const = 0;

	/**
	 * Retrieves stencil operation to perform if stencil test passes but depth test fails (for back faces).
	 */
	virtual StencilOperation								GetBackDepthFailOperation() const = 0;

	/**
	 * Retrieves stencil operation to perform if both stencil test and depth test passes (for front faces).
	 */
	virtual StencilOperation								GetFrontPassOperation() const = 0;

	/**
	 * Retrieves stencil operation to perform if both stencil test and depth test passes (for back faces).
	 */
	virtual StencilOperation								GetBackPassOperation() const = 0;

	/**
	 * Retrieves stencil buffer comparison function (for front faces).
	 */
	virtual CompareFunction									GetFrontStencilFunction() const = 0;

	/**
	 * Retrieves stencil buffer comparison function (for back faces).
	 */
	virtual CompareFunction									GetBackStencilFunction() const = 0;

	/**
	 * Produces an exact copy of depth-stencil state.
	 * @return Newly created depth-stencil state.
	 */
	virtual IDepthStencilState*								Clone() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IDEPTHSTENCILSTATE_
