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
#include "config.h"
#include "Program.h"
#include "ProgramStage.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Program::Program( IProgram* program, IProgram* parent ) :
	ProgramImpl<IProgram>( parent, program->GetInputFormat(), program->GetOutputFormat() ),
	_program( program )
{
	assert( _program != nullptr );

	if ( _program->GetVertexStage() != nullptr )
	{
		_vertexStage = new ProgramStage( ProgramStageType::Vertex, _program->GetVertexStage() );
	}

	if ( _program->GetHullStage() != nullptr )
	{
		_hullStage = new ProgramStage( ProgramStageType::Hull, _program->GetHullStage() );
	}

	if ( _program->GetDomainStage() != nullptr )
	{
		_domainStage = new ProgramStage( ProgramStageType::Domain, _program->GetDomainStage() );
	}

	if ( _program->GetGeometryStage() != nullptr )
	{
		_geometryStage = new ProgramStage( ProgramStageType::Geometry, _program->GetGeometryStage() );
	}

	if ( _program->GetFragmentStage() != nullptr )
	{
		_fragmentStage = new ProgramStage( ProgramStageType::Fragment, _program->GetFragmentStage() );
	}
}


} // gfx


} // synkro
