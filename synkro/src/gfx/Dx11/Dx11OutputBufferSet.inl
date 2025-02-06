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
SYNKRO_INLINE void Dx11OutputBufferSet::Bind()
{
	if ( _items.Size() > 0 )
	{
		Dx11Lock( _context );
		_context->SOSetTargets( _items.Size(), _items.Begin(), _offsets.Begin() );
	}
}
