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
// Purpose: Defines graphics device program.
//==============================================================================
#ifndef _SYNKRO_GFX_IPROGRAM_
#define _SYNKRO_GFX_IPROGRAM_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Graphics device program.
 */
iface IProgram :
	public core::IObject
{
public:
	/**
	 * Binds program to the pipeline.
	 */
	virtual void											Bind() = 0;

	/**
	 * Saves compiled programs to a set of streams.
	 * @param vertexProgram Vertex program stream.
	 * @param hullProgram Hull program stream.
	 * @param domainProgram Domain program stream.
	 * @param geometryProgram Geometry program stream.
	 * @param fragmentProgram Fragment program stream.
	 */
	virtual void											Save( io::IStream* vertexProgram, io::IStream* hullProgram, io::IStream* domainProgram, io::IStream* geometryProgram, io::IStream* fragmentProgram ) = 0;

	/**
	 * Retrieves program's input data format.
	 */
	virtual IDataFormat*									GetInputFormat() const = 0;

	/**
	 * Retrieves program's output data format.
	 */
	virtual IDataFormat*									GetOutputFormat() const = 0;

	/**
	 * Retrieves program's vertex stage.
	 */
	virtual IProgramStage*									GetVertexStage() const = 0;

	/**
	 * Retrieves program's hull stage.
	 */
	virtual IProgramStage*									GetHullStage() const = 0;

	/**
	 * Retrieves program's domain stage.
	 */
	virtual IProgramStage*									GetDomainStage() const = 0;

	/**
	 * Retrieves program's geometry stage.
	 */
	virtual IProgramStage*									GetGeometryStage() const = 0;

	/**
	 * Retrieves program's fragment stage.
	 */
	virtual IProgramStage*									GetFragmentStage() const = 0;

	/**
	 * Retrieves parent program.
	 */
	virtual IProgram*										GetParent() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IPROGRAM_
