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
SYNKRO_INLINE void Program::Bind()
{
	SynkroProfile( "Program.Bind" );

	_program->Bind();
}

SYNKRO_INLINE void Program::Save( io::IStream* vertexProgram, io::IStream* hullProgram, io::IStream* domainProgram, io::IStream* geometryProgram, io::IStream* pixelProgram )
{
	_program->Save( vertexProgram, hullProgram, domainProgram, geometryProgram, pixelProgram );
}
