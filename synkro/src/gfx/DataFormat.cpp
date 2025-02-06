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
// Purpose: Defines data buffer format.
//==============================================================================
#include "config.h"
#include "DataFormat.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


DataFormat::DataFormat() :
	_vertices( A(Stream) ),
	_instances( A(Stream) )
{
}

void DataFormat::AddVertexStream( const DataStream& type, const ProgramDataType& dataType )
{
	assert( type != DataStream::Unknown );
	assert( dataType != ProgramDataType::Unknown );

	_vertices.Add( Stream(type, dataType) );
}

void DataFormat::AddInstanceStream( const DataStream& type, const ProgramDataType& dataType )
{
	assert( type != DataStream::Unknown );
	assert( dataType != ProgramDataType::Unknown );

	_instances.Add( Stream(type, dataType) );
}


} // gfx


} // synkro
