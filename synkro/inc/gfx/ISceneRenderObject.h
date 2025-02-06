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
// Purpose: Defines scene rendering object.
//==============================================================================
#ifndef _SYNKRO_GFX_ISCENERENDEROBJECT_
#define _SYNKRO_GFX_ISCENERENDEROBJECT_


#include "config.h"
#include <gfx/IRenderObject.h>
#include <gfx/CompareFunction.h>


namespace synkro
{


namespace gfx
{


/**
 * Scene rendering object.
 */
iface ISceneRenderObject :
	public IRenderObject
{
public:
	/**
	 * Controls whether the render the object should be rendered in the given render view.
	 * @param view Render view.
	 * @param render True to render the object in the render view.
	 */
	virtual void											SetRenderable( IRenderView* view, Bool render ) = 0;

	/**
	 * Sets blend states used to render the object.
	 */
	virtual void											SetBlendStates( IBlendStateSet* states ) = 0;

	/**
	 * Sets depth-stencil state used to render the object.
	 */
	virtual void											SetDepthStencilState( IDepthStencilState* state ) = 0;

	/**
	 * Sets rasterizer state used to render the object.
	 */
	virtual void											SetRasterizerState( IRasterizerState* state ) = 0;

	/**
	 * Sets parameters for program's vertex stage.
	 */
	virtual void											SetVertexParameters( IParameterSet* params ) = 0;

	/**
	 * Sets resources for program's vertex stage.
	 */
	virtual void											SetVertexResources( IResourceSet* resources ) = 0;

	/**
	 * Sets sampler states for program's vertex stage.
	 */
	virtual void											SetVertexSamplers( ISamplerStateSet* samplers ) = 0;

	/**
	 * Sets parameters for program's hull stage.
	 */
	virtual void											SetHullParameters( IParameterSet* params ) = 0;

	/**
	 * Sets resources for program's hull stage.
	 */
	virtual void											SetHullResources( IResourceSet* resources ) = 0;

	/**
	 * Sets sampler states for program's hull stage.
	 */
	virtual void											SetHullSamplers( ISamplerStateSet* samplers ) = 0;

	/**
	 * Sets parameters for program's domain stage.
	 */
	virtual void											SetDomainParameters( IParameterSet* params ) = 0;

	/**
	 * Sets resources for program's domain stage.
	 */
	virtual void											SetDomainResources( IResourceSet* resources ) = 0;

	/**
	 * Sets sampler states for program's domain stage.
	 */
	virtual void											SetDomainSamplers( ISamplerStateSet* samplers ) = 0;

	/**
	 * Sets parameters for program's geometry stage.
	 */
	virtual void											SetGeometryParameters( IParameterSet* params ) = 0;

	/**
	 * Sets resources for program's geometry stage.
	 */
	virtual void											SetGeometryResources( IResourceSet* resources ) = 0;

	/**
	 * Sets sampler states for program's geometry stage.
	 */
	virtual void											SetGeometrySamplers( ISamplerStateSet* samplers ) = 0;

	/**
	 * Sets parameters for program's fragment stage.
	 */
	virtual void											SetFragmentParameters( IParameterSet* params ) = 0;

	/**
	 * Sets resources for program's fragment stage.
	 */
	virtual void											SetFragmentResources( IResourceSet* resources ) = 0;

	/**
	 * Sets sampler states for program's fragment stage.
	 */
	virtual void											SetFragmentSamplers( ISamplerStateSet* samplers ) = 0;

	/**
	 * Sets bounding volume for occlusion query.
	 * @param volume Bounding volume geometry.
	 */
	virtual void											SetBoundingVolume( IPrimitive* volume ) = 0;

	/**
	 * Sets comparison function for the occlusion query.
	 * @param function Comparison function.
	 */
	virtual void											SetOcclusionFunction( const CompareFunction& function ) = 0;

	/**
	 * Sets value to compare occlusion query result with.
	 * @param value Pass value.
	 */
	virtual void											SetOcclusionPassValue( UInt value ) = 0;

	/**
	 * Sets index of the first element and the number of elements to render.
	 */
	virtual void											SetElementRange( UInt start, UInt count ) = 0;

	/**
	 * Sets index of the first instance and the number of instances to render.
	 */
	virtual void											SetInstanceRange( UInt start, UInt count ) = 0;

	/**
	 * Indicates whether the render the object should be rendered in the given render view.
	 * @param view Render view.
	 * @return True if the render object should be rendered, false otherwise.
	 */
	virtual Bool											IsRenderable( IRenderView* view ) const = 0;

	/**
	 * Retrieves blend states used to render the object.
	 */
	virtual IBlendStateSet*									GetBlendStates() const = 0;

	/**
	 * Retrieves depth-stencil state used to render the object.
	 */
	virtual IDepthStencilState*								GetDepthStencilState() const = 0;

	/**
	 * Retrieves rasterizer state used to render the object.
	 */
	virtual IRasterizerState*								GetRasterizerState() const = 0;

	/**
	 * Retrieves parameters for program's vertex stage.
	 */
	virtual IParameterSet*									GetVertexParameters() const = 0;

	/**
	 * Retrieves resources for program's vertex stage.
	 */
	virtual IResourceSet*									GetVertexResources() const = 0;

	/**
	 * Retrieves sampler states for program's vertex stage.
	 */
	virtual ISamplerStateSet*								GetVertexSamplers() const = 0;

	/**
	 * Retrieves parameters for program's hull stage.
	 */
	virtual IParameterSet*									GetHullParameters() const = 0;

	/**
	 * Retrieves resources for program's hull stage.
	 */
	virtual IResourceSet*									GetHullResources() const = 0;

	/**
	 * Retrieves sampler states for program's hull stage.
	 */
	virtual ISamplerStateSet*								GetHullSamplers() const = 0;

	/**
	 * Retrieves parameters for program's domain stage.
	 */
	virtual IParameterSet*									GetDomainParameters() const = 0;

	/**
	 * Retrieves resources for program's domain stage.
	 */
	virtual IResourceSet*									GetDomainResources() const = 0;

	/**
	 * Retrieves sampler states for program's domain stage.
	 */
	virtual ISamplerStateSet*								GetDomainSamplers() const = 0;

	/**
	 * Retrieves parameters for program's geometry stage.
	 */
	virtual IParameterSet*									GetGeometryParameters() const = 0;

	/**
	 * Retrieves resources for program's geometry stage.
	 */
	virtual IResourceSet*									GetGeometryResources() const = 0;

	/**
	 * Retrieves sampler states for program's geometry stage.
	 */
	virtual ISamplerStateSet*								GetGeometrySamplers() const = 0;

	/**
	 * Retrieves parameters for program's fragment stage.
	 */
	virtual IParameterSet*									GetFragmentParameters() const = 0;

	/**
	 * Retrieves resources for program's fragment stage.
	 */
	virtual IResourceSet*									GetFragmentResources() const = 0;

	/**
	 * Retrieves sampler states for program's fragment stage.
	 */
	virtual ISamplerStateSet*								GetFragmentSamplers() const = 0;

	/**
	 * Retrieves bounding volume for occlusion query.
	 */
	virtual IPrimitive*										GetBoundingVolume() const = 0;

	/**
	 * Retrieves comparison function for occlusion query.
	 */
	virtual CompareFunction									GetOcclusionFunction() const = 0;

	/**
	 * Retrieves value to compare occlusion query result with.
	 */
	virtual UInt											GetOcclusionPassValue() const = 0;

	/**
	 * Retrieves index of the first element to render.
	 */
	virtual UInt											GetStartElement() const = 0;

	/**
	 * Retrieves the number of elements to render.
	 */
	virtual UInt											GetElementCount() const = 0;

	/**
	 * Retrieves index of the first instance to render.
	 */
	virtual UInt											GetStartInstance() const = 0;

	/**
	 * Retrieves the number of instances to render.
	 */
	virtual UInt											GetInstanceCount() const = 0;

	/**
	 * Retrieves the owner queue.
	 */
	virtual ISceneRenderQueue*								GetQueue() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ISCENERENDEROBJECT_
