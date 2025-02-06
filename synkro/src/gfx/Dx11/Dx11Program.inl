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
// Purpose: DX11 based program.
//==============================================================================
SYNKRO_INLINE void Dx11Program::Bind()
{
	Dx11Lock( _context );
	_context->VSSetShader( _vertexShader, nullptr, 0 );
	_context->HSSetShader( _hullShader, nullptr, 0 );
	_context->DSSetShader( _domainShader, nullptr, 0 );
	_context->GSSetShader( _geometryShader, nullptr, 0 );
	_context->PSSetShader( _fragmentShader, nullptr, 0 );
}
