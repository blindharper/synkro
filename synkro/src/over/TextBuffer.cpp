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
// Purpose: Text buffer.
//==============================================================================
#include "config.h"
#include "TextBuffer.h"
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/IVector2Stream.h>
#include <gfx/IVector4Stream.h>


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::io;

//------------------------------------------------------------------------------


namespace synkro
{


namespace over
{


TextBuffer::TextBuffer( IOverlayRenderObject* object ) :
	StreamPosition( nullptr ),
	StreamTexCoord( nullptr ),
	StreamColor( nullptr )
{
	StreamPosition = (IVector4Stream*)object->GetData()->GetVertexStream( DataStream::Position2D, 0 );
	if ( !StreamPosition->Open(OpenMode::Write) )
	{
		StreamPosition = nullptr;
	}

	StreamTexCoord = (IVector2Stream*)object->GetData()->GetVertexStream( DataStream::TexCoord2D, 0 );
	if ( !StreamTexCoord->Open(OpenMode::Write) )
	{
		StreamPosition->Close();
		StreamPosition = nullptr;
		StreamTexCoord = nullptr;
	}

	StreamColor = (IVector4Stream*)object->GetData()->GetVertexStream( DataStream::Color, 0 );
	if ( !StreamColor->Open(OpenMode::Write) )
	{
		StreamPosition->Close();
		StreamTexCoord->Close();
		StreamPosition = nullptr;
		StreamTexCoord = nullptr;
		StreamColor = nullptr;
	}
}

TextBuffer::~TextBuffer()
{
	if ( StreamPosition != nullptr )
		StreamPosition->Close();

	if ( StreamTexCoord != nullptr )
		StreamTexCoord->Close();

	if ( StreamColor != nullptr )
		StreamColor->Close();
}

Bool TextBuffer::IsValid() const
{
	return (StreamPosition != nullptr) && (StreamTexCoord != nullptr) && (StreamColor != nullptr);
}


} // over


} // synkro
