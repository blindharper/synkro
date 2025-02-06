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
// Purpose: Dx11 based vertex buffer set implementation.
//==============================================================================
#include "config.h"
#include "Dx11VertexBufferSet.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11VertexBufferSet::Dx11VertexBufferSet( Dx11Context* context ) :
	_items( A(ID3D11Buffer*) ),
	_strides( A(UINT) ),
	_offsets( A(UINT) ),
	_context( context )
{
}

void Dx11VertexBufferSet::AddBuffer( Dx11VertexBuffer* buffer )
{
	assert( buffer != nullptr );

	_buffers.Add( buffer );
	_items.Add( buffer->_buffer );
	_strides.Add( buffer->_stride );
	_offsets.Add( 0 );
}

void Dx11VertexBufferSet::UpdateBuffer( Dx11VertexBuffer* buffer )
{
	assert( buffer != nullptr );

	UInt idx = _buffers.IndexOf( buffer );
	if ( idx != none )
	{
		_items[idx] = buffer->_buffer;
	}
}


} // gfx


} // synkro
