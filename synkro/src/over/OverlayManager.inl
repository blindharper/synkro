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
// Purpose: Overlay manager implementation.
//==============================================================================
SYNKRO_INLINE IOverlay* OverlayManager::GetOverlay( gfx::IRenderWindow* window ) const
{
	UInt key = window->ID();
	return _overlays.ContainsKey(key) ? _overlays[key] : nullptr;
}

SYNKRO_INLINE gfx::IProgram* OverlayManager::GetFontProgram() const
{
	return _fontProgram;
}

SYNKRO_INLINE gfx::IBlendStateSet* OverlayManager::GetBlendStates() const
{
	return _blendStates;
}
