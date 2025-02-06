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
// Purpose: Defines user interface resource reader.
//==============================================================================
#ifndef _SYNKRO_UI_UIREADER_
#define _SYNKRO_UI_UIREADER_


#include "config.h"
#include <io/XmlReader.h>
#include <lang/Parser.h>
#include <lang/Map.h>
#include <lang/Point.h>
#include <lang/Size.h>
#include <img/Color.h>
#include <ui/Anchor.h>
#include <ui/HotKey.h>
#include <ui/EditStyle.h>
#include <ui/ProgressType.h>
#include <ui/Orientation.h>


namespace synkro
{


namespace ui
{


// Available widget types.
enum WidgetType
{
	WIDGET_NONE,
	WIDGET_FRAME,
	WIDGET_ACCORDION,
	WIDGET_ANGLE,
	WIDGET_BUTTON,
	WIDGET_DROPLIST,
	WIDGET_EDIT,
	WIDGET_LABEL,
	WIDGET_LIST,
	WIDGET_OPTION,
	WIDGET_PICTURE,
	WIDGET_PROGRESS,
	WIDGET_SLIDER,
	WIDGET_SWITCH,
};


// UI resource reader.
class UiReader
{
public:
	// Constructor.
	UiReader( io::IStream* stream, UInt width, UInt height );

	Bool													Read();
	Bool													IsStart();
	WidgetType												GetType() const;
	UInt													GetID() const;
	lang::Point												GetLocation() const;
	lang::Size												GetSize() const;
	lang::String											GetText() const;
	img::Color												GetColor() const;
	Pointer													GetData() const;
	lang::String											GetString( const lang::String& name ) const;
	Bool													GetBool( const lang::String& name ) const;
	UInt													GetUInt( const lang::String& name ) const;
	Anchor													GetAnchor() const;
	HotKey													GetHotKey() const;
	EditStyle												GetEditStyle() const;
	Orientation												GetOrientation() const;
	ProgressType											GetProgressType() const;

private:
	typedef lang::MapPair<lang::String, WidgetType>			TypeEntry;

	lang::MapCI<lang::String, WidgetType>					_types;
	mutable lang::Parser									_parserPoint;
	mutable lang::Parser									_parserSize;
	mutable lang::Parser									_parserNumber;
	mutable lang::Parser									_parserPointer;
	io::XmlReader											_rd;
	lang::String											_widthName;
	lang::String											_heightName;
	lang::String											_widthValue;
	lang::String											_heightValue;

	lang::String											Evaluate( const lang::String& text ) const;
	lang::String											Calcuate( const lang::String& text ) const;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_UIREADER_
