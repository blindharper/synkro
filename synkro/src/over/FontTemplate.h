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
// Purpose: Overlay font template.
//==============================================================================
#ifndef _SYNKRO_OVER_FONTTEMPLATE_
#define _SYNKRO_OVER_FONTTEMPLATE_


#include "config.h"
#include <lang/Ptr.h>
#include <lang/Map.h>
#include <lang/RectF.h>
#include <lang/Size.h>
#include <lang/Vector.h>
#include <core/Language.h>
#include <over/FontStyle.h>
#include <io/IStreamDirectory.h>
#include <img/IImageManager.h>
#include <img/IImage.h>


namespace synkro
{


namespace over
{


// Overlay font template.
class FontTemplate
{
public:
	// Constructors.
	FontTemplate( const core::Language& language, img::IImageManager* imageManager, const lang::String& family, const FontStyle& style, UInt size );
	FontTemplate( const core::Language& language, img::IImageManager* imageManager, io::IStreamDirectory* resource, const lang::String& image, const lang::String& alpha );
	FontTemplate();

	// Methods.
	void													GetTextSize( const lang::String& text, lang::Size& size ) const;
	void													Prepare();

private:
	friend class FontEx;

	typedef lang::MapPair<Char, lang::RectF>				GlyphEntry;

	lang::Map<Char, lang::RectF>							_glyphs;
	lang::Vector<P(img::IImage)>							_images;
	io::IStreamDirectory*									_resource;
	img::IImageManager*										_imageManager;
	core::Language											_language;
	lang::String											_imageName;
	lang::String											_alphaName;
	lang::String											_family;
	FontStyle												_style;
	UInt													_size;
	UInt													_imageWidth;
	UInt													_imageHeight;
	Float													_dy;

	void													Prepare( img::IImageManager* imageManager, const lang::String& family, const FontStyle& style, UInt size );
	void													Prepare( img::IImage* image );
	img::IImage*											LoadFontImage( io::IStream* streamImage, io::IStream* streamAlpha ) const;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_FONTTEMPLATE_
