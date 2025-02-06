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
// Purpose: Logical program.
//==============================================================================
#ifndef _SYNKRO_GFX_PROGRAM_
#define _SYNKRO_GFX_PROGRAM_


#include "config.h"
#include "ProgramImpl.h"


namespace synkro
{


namespace gfx
{


// Logical program.
class Program :
	public ProgramImpl<IProgram>
{
public:
	// Constructor.
	Program( IProgram* program, IProgram* parent );

	// IProgram methods.
	void													Bind();
	void													Save( io::IStream* vertexProgram, io::IStream* hullProgram, io::IStream* domainProgram, io::IStream* geometryProgram, io::IStream* pixelProgram );

private:
	friend class GraphicsSystemEx;
	friend class GraphicsDevice;

	P(IProgram)												_program;
};


#include "Program.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PROGRAM_
