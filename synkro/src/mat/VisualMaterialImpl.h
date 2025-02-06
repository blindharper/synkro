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
// Purpose: Generic visual material implementation.
//==============================================================================
#ifndef _SYNKRO_MAT_VISUALMATERIALIMPL_
#define _SYNKRO_MAT_VISUALMATERIALIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/IDataFormatEx.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <gfx/IParameterSet.h>
#include <gfx/IResourceSet.h>
#include <gfx/ISamplerStateSet.h>
#include <gfx/IBlendStateSet.h>
#include <gfx/IBlendState.h>
#include <gfx/IDepthStencilState.h>
#include <gfx/ISamplerState.h>
#include <gfx/IRasterizerState.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <core/IContext.h>
#include <scene/ISceneEx.h>
#include <scene/ITriangleMesh.h>
#include <lang/Convert.h>
#include <lang/Map.h>


namespace synkro
{


namespace mat
{


// Generic material implementation.
template <class T>
class VisualMaterialImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	VisualMaterialImpl( core::IContext* context );
	virtual ~VisualMaterialImpl();

	// IVisualMaterial methods.
	virtual IVisualMaterialAnimationController*				CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	virtual scene::ITriangleSet*							CreateTriangleList( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency );
	virtual scene::ITriangleSet*							CreateTriangleStrip( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency );
	virtual void											SetColored( Bool colored );
	virtual Bool											IsColored() const;
	virtual UInt											GetSubsetCount() const;
	virtual ISimpleMaterial*								AsSimple() const;
	virtual IMultiMaterial*									AsMulti() const;

	// Other methods.
	virtual scene::ITriangleSet*							CreateTriangleSet( const gfx::PrimitiveType& type, scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency ) = 0;

protected:
	core::IContext*											_context;
	P(gfx::IBlendStateSet)									_blendStates;
	P(gfx::IDepthStencilState)								_depthStencilState;
	P(gfx::IRasterizerState)								_rasterizerState;
	Bool													_colored;
};


#include "VisualMaterialImpl.inl"


} // mat


} // synkro


#endif // _SYNKRO_MAT_VISUALMATERIALIMPL_
