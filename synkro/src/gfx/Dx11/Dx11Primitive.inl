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
// Purpose: DX11 primitive implementation.
//==============================================================================
SYNKRO_INLINE UInt Dx11Primitive::Draw()
{
	Dx11Lock( _context );
	_context->IASetInputLayout( _layout );
	_context->IASetPrimitiveTopology( _primitiveType );

	if ( _first )
	{
		_context->Draw( _vertexCount, 0 );
		_first = false;
	}
	else
	{
		_context->DrawAuto();
	}

	return 0;
}
