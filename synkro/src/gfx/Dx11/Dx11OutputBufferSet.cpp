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
// Purpose: DX11 based output buffer set implementation.
//==============================================================================
#include "config.h"
#include "Dx11OutputBufferSet.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11OutputBufferSet::Dx11OutputBufferSet( Dx11Context* context ) :
	_items( A(ID3D11Buffer*) ),
	_offsets( A(UINT) ),
	_context( context )
{
}

void Dx11OutputBufferSet::AddBuffer( Dx11OutputBuffer* buffer )
{
	assert( buffer != nullptr );

	_buffers.Add( buffer );
	_items.Add( buffer->_buffer );
	_offsets.Add( 0 );
}


} // gfx


} // synkro
