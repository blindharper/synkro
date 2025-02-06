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
// Purpose: Defines scene rendering queue.
//==============================================================================
#ifndef _SYNKRO_GFX_SCENERENDERQUEUE_
#define _SYNKRO_GFX_SCENERENDERQUEUE_


#include "config.h"
#include "Classes.h"
#include <lang/Map.h>
#include <lang/Vector.h>
#include "RenderQueueImpl.h"
#include "LineRenderQueue.h"
#include <gfx/GraphicsStats.h>
#include <gfx/ISceneRenderQueue.h>
#include <gfx/IPrimitive.h>


namespace synkro
{


namespace gfx
{


// Instance item.
class InstanceItem
{
public:
	// Constructors.
	InstanceItem( SceneRenderObject* object );
	InstanceItem();

	lang::String						Key() const;

	SceneRenderObject*					Object;
	UInt								StartElement;
	UInt								ElementCount;
	UInt								StartInstance;
	UInt								InstanceCount;

	ParameterSet*						VertexParams;
	ParameterSet*						GeometryParams;
	ParameterSet*						FragmentParams;

	SamplerStateSet*					VertexSamplers;
	SamplerStateSet*					GeometrySamplers;
	SamplerStateSet*					FragmentSamplers;
};

// Data item.
class DataItem
{
public:
	// Constructors.
	DataItem( IPrimitive* data );
	DataItem();

	lang::String						Key() const;

	typedef lang::MapPair<lang::String, InstanceItem> InstanceEntry;

	lang::Map<lang::String, InstanceItem> Instances;
	IPrimitive*							Data;
	Program*							Program;

	BlendStateSet*						BlendStates;
	DepthStencilState*					DepthStencilState;
	RasterizerState*					RasterizerState;
	FillMode							OrgFillMode;
};

// Resource item.
class ResourceItem
{
public:
	// Constructor.
	ResourceItem();

	lang::String						Key() const;

	typedef lang::MapPair<lang::String, DataItem> BufferEntry;

	lang::Map<lang::String, DataItem>	Buffers;
	ResourceSet*						VertexResources;
	ResourceSet*						GeometryResources;
	ResourceSet*						FragmentResources;
};


// Scene rendering queue.
class SceneRenderQueue :
	public RenderQueueImpl<ISceneRenderQueue>
{
public:
	// Constructor & destructor.
	SceneRenderQueue( IGraphicsSystemEx* graphicsSystem );
	~SceneRenderQueue();

	// ISceneRenderQueue methods.
	ISceneRenderObject*										CreateObject( IPrimitive* data, Bool occluder );
	ISkyRenderObject*										CreateSkysphereObject( Float radius );
	ISkyRenderObject*										CreateSkyboxObject();
	ILineRenderQueue*										GetLineQueue() const;

	// Other methods.
	void													RemoveObject( SceneRenderObject* object );
	void													Process( IRenderView* view, Bool overlay, const FillMode& fill, const img::PixelChannel& mask, IParameterSet* vertexParams, GraphicsStats& stats );
	void													ProcessLines( GraphicsStats& stats );

private:
	typedef lang::MapPair<lang::String, ResourceItem>		ResourceEntry;

	lang::Map<lang::String, ResourceItem>					_resources;
	lang::Vector<SceneRenderObject*>						_dirty;
	P(LineRenderQueue)										_lineQueue;
	IGraphicsSystemEx*										_graphicsSystem;
	ISkyRenderObject*										_sky;

	IPrimitive*												_data;
	Program*												_program;
	P(BlendStateSet)										_blendStates;
	P(DepthStencilState)									_depthStencilState;
	P(RasterizerState)										_rasterizerState;

	ParameterSet*											_vertexParams;
	ResourceSet*											_vertexResources;
	SamplerStateSet*										_vertexSamplers;

	ParameterSet*											_geometryParams;
	ResourceSet*											_geometryResources;
	SamplerStateSet*										_geometrySamplers;

	ParameterSet*											_fragmentParams;
	ResourceSet*											_fragmentResources;
	SamplerStateSet*										_fragmentSamplers;
};


#include "SceneRenderQueue.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_SCENERENDERQUEUE_
