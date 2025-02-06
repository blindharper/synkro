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
// Purpose: Overlay implementation.
//==============================================================================
SYNKRO_INLINE gfx::IRenderWindow* Overlay::GetRenderWindow() const
{
	return _window;
}

SYNKRO_INLINE Bool Overlay::Call( BaseSpritePool* pool )
{
	pool->Update();
	return true;
}
