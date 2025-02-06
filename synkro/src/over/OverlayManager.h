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
#ifndef _SYNKRO_OVER_OVERLAYMANAGER_
#define _SYNKRO_OVER_OVERLAYMANAGER_


#include "config.h"
#include <over/IOverlayManager.h>
#include <over/IFont.h>
#include "FontTemplate.h"
#include "Overlay.h"
#include "BaseOverlayManager.h"


namespace synkro
{


namespace over
{


// Overlay manager implementation.
class OverlayManager :
	public core::ObjectImpl<IOverlayManager>,
	public BaseOverlayManager,
	public Logger
{
public:
	// Constructor & destructor.
	OverlayManager( core::IContext* context, diag::ILog* log );
	~OverlayManager();

	// ISystem methods.
	Bool													Update( Double delta );

	// IOverlayManager methods.
	IOverlay*												CreateOverlay( gfx::IVirtualRenderWindow* window );
	IOverlay*												CreateOverlay( img::IImage* image );
	void													CreateFont( const lang::String& name, const core::Language& language, const lang::String& family, const FontStyle& style, UInt size );
	IOverlay*												GetOverlay( gfx::IRenderWindow* window ) const;

	// BaseOverlayManager methods.
	IFont*													CreateFont( const lang::String& name, IOverlay* overlay );
	gfx::IProgram*											GetFontProgram() const;
	gfx::IBlendStateSet*									GetBlendStates() const;

	// Other methods.
	void													Init();

private:
	friend class Overlay;

	typedef lang::MapPair<UInt, P(Overlay)> OverlayEntry;
	typedef lang::MapPair<lang::String, FontTemplate>		TemplateEntry;

	lang::Map<UInt, P(Overlay)>								_overlays;
	lang::MapCI<lang::String, FontTemplate>					_fonts;
	core::IContext*											_context;
	gfx::IProgram*											_fontProgram;
	P(gfx::IBlendStateSet)									_blendStates;
};


#include "OverlayManager.inl"


} // over


} // synkro


#endif // _SYNKRO_OVER_OVERLAYMANAGER_
