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
// Purpose: Overlay font implementation.
//==============================================================================
#ifndef _SYNKRO_OVER_FONTEX_
#define _SYNKRO_OVER_FONTEX_


#include "config.h"
#include <lang/Map.h>
#include <lang/Vector.h>
#include <over/IFont.h>
#include "Overlay.h"
#include "FontTemplate.h"
#include "TextBuffer.h"
#include "TextDesc.h"
#include <gfx/IPrimitiveEx.h>
#include <gfx/ITexture.h>
#include <gfx/IResource.h>
#include <gfx/IBlendState.h>
#include <gfx/IBlendStateSet.h>
#include <gfx/IRasterizerState.h>
#include "BaseTextPool.h"
#include "BaseFont.h"


namespace synkro
{


namespace over
{


// Overlay font implementation.
class FontEx :
	public core::ObjectImpl<IFont>,
	public BaseTextPool,
	public BaseFont
{
public:
	// Constructor.
	FontEx( FontTemplate* temp, Overlay* overlay );

	// IFont methods.
	IText*													CreateText( const img::ColorGradient& gradient, const lang::Point& location, const lang::String& text, const Order& groupOrder, const Order& order );
	IText*													CreateText( const img::ColorGradient& gradient, const lang::Point& location, const lang::String& text );
	IText*													CreateText( const img::Color& color, const lang::Point& location, const lang::String& text, const Order& groupOrder, const Order& order );
	IText*													CreateText( const img::Color& color, const lang::Point& location, const lang::String& text );
	void													GetTextSize( const lang::String& text, lang::Size& size ) const;
	lang::String											GetFamily() const;
	UInt													GetSize() const;
	FontStyle												GetStyle() const;
	core::Language											GetLanguage() const;

	// BaseTextPool methods.
	void													AddText( BaseText* text );
	void													RemoveText( BaseText* text );
	void													InvalidateTexts();
	void													Update();

	// BaseFont methods.
	void													SetFrame( UInt frame );
	UInt													GetTextCapacity( const lang::String& text );
	gfx::IOverlayRenderObject*								CreateText( gfx::IOverlayRenderQueue* queue, UInt capacity, UInt order );
	UInt													DrawText( const TextBuffer& buffer, const TextDesc& desc, UInt start );
	void													UpdateColor( gfx::IOverlayRenderObject* obj, const img::Color& color, Float opacity );

	// Other methods.
	Bool													Call( BaseText* text );

private:
	friend class Text;

	FontTemplate*											_template;
	Overlay*												_overlay;
	core::Language											_language;
	lang::Vector<P(img::IImage)>							_frames;
	lang::Vector<BaseText*>									_texts;
	P(gfx::IResourceSet)									_resources;
	lang::String											_family;
	UInt													_size;
	FontStyle												_style;
	Float													_dh;
};


#include "FontEx.inl"


} // over


} // synkro


#endif // _SYNKRO_OVER_FONTEX_
