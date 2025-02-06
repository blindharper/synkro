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
#include "config.h"
#include "UiReader.h"


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


UiReader::UiReader( IStream* stream, UInt width, UInt height ) :
	_types( A(TypeEntry) ),
	_parserPoint( L"{0},{1}" ),
	_parserSize( L"{0},{1}" ),
	_parserNumber( L"{0}" ),
	_parserPointer( L"{0}({1})" ),
	_rd( stream, true ),
	_widthName( L"WIDTH" ),
	_heightName( L"HEIGHT" ),
	_widthValue( CastInt(width) ),
	_heightValue( CastInt(height) )
{
	_types[L"frame"]		= WIDGET_FRAME;
	_types[L"accordion"]	= WIDGET_ACCORDION;
	_types[L"angle"]		= WIDGET_ANGLE;
	_types[L"button"]		= WIDGET_BUTTON;
	_types[L"droplist"]		= WIDGET_DROPLIST;
	_types[L"edit"]			= WIDGET_EDIT;
	_types[L"label"]		= WIDGET_LABEL;
	_types[L"list"]			= WIDGET_LIST;
	_types[L"option"]		= WIDGET_OPTION;
	_types[L"picture"]		= WIDGET_PICTURE;
	_types[L"progress"]		= WIDGET_PROGRESS;
	_types[L"slider"]		= WIDGET_SLIDER;
	_types[L"switch"]		= WIDGET_SWITCH;

	// Read <ui> tag.
	if ( !_rd.Read() || (!_rd.GetName().EqualsTo(L"ui", true)) )
		throw Exception( L"Bad ui resource. Missing <ui> tag." );
}

Bool UiReader::Read()
{
	return _rd.Read();
}

Bool UiReader::IsStart()
{
	return _rd.IsStart();
}

WidgetType UiReader::GetType() const
{
	return _types.ContainsKey(_rd.GetName()) ? _types[_rd.GetName()] : WIDGET_NONE;
}

UInt UiReader::GetID() const
{
	String id = _rd.GetAttributeValue( L"id" );
	return id.IsInteger() ? CastUInt(id.ToInteger()) : none;
}

Point UiReader::GetLocation() const
{
	String location = _rd.GetAttributeValue( L"location" );
	if ( location.IsNull() )
		return Point();

	Int left; Int top;
	_parserPoint.Map( left, top );
	if ( !_parserPoint.ParseText(Evaluate(location)) )
		return Point();

	return Point( left, top );
}

Size UiReader::GetSize() const
{
	String size = _rd.GetAttributeValue( L"size" );
	if ( size.IsNull() )
		return Size();

	Int width; Int height;
	_parserSize.Map( width, height );
	if ( !_parserSize.ParseText(Evaluate(size)) )
		return Size();

	return Size( CastUInt(width), CastUInt(height) );
}

String UiReader::GetText() const
{
	String text = _rd.GetAttributeValue( L"text" );
	return text.IsNull() ? String::Empty : text;
}

Color UiReader::GetColor() const
{
	String color = _rd.GetAttributeValue( L"color" );
	return Color( color );
}

Pointer UiReader::GetData() const
{
	Pointer data = null;
	String value = _rd.GetAttributeValue( L"data" );
	if ( !value.IsNull() )
	{
		Int number = 0;
		_parserNumber.Map( number );
		if ( _parserNumber.ParseText(value) )
			data = (Pointer)number;

		String type; String val;
		_parserPointer.Map( type, val );
		if ( _parserPointer.ParseText(value) )
			data = (Pointer)Enum::GetValue( type, val );
	}
	return data;
}

String UiReader::GetString( const String& name ) const
{
	return _rd.GetAttributeValue( name );
}

Bool UiReader::GetBool( const String& name ) const
{
	String value = _rd.GetAttributeValue( name );
	return !value.IsNull() && value.EqualsTo(L"true", true);
}

UInt UiReader::GetUInt( const String& name ) const
{
	String value = _rd.GetAttributeValue( name );
	return value.IsInteger() ? CastUInt(value.ToInteger()) : 0;
}

Anchor UiReader::GetAnchor() const
{
	String anchor = _rd.GetAttributeValue( L"anchor" );
	return !anchor.IsNull() ? Anchor( anchor ) : Anchor::None;
}

HotKey UiReader::GetHotKey() const
{
	String hotkey = _rd.GetAttributeValue( L"hotkey" );
	if ( !hotkey.IsNull() )
	{
		Key key; Bool control = false; Bool shift = false; Bool alt = false;
		const UInt count = hotkey.EntryCount( L'+' );
		for ( UInt i = 0; i < count; ++i )
		{
			String item = hotkey.Entry( i, L'+' );
			if ( item.EqualsTo(L"CTRL", true) )
				control = true;
			else if ( item.EqualsTo(L"SHIFT", true) )
				shift = true;
			else if ( item.EqualsTo(L"ALT", true) )
				alt = true;
			else
				key = Key( item );
		}
		return HotKey( key, control, shift, alt );
	}
	return HotKey::None;
}

EditStyle UiReader::GetEditStyle() const
{
	String style = _rd.GetAttributeValue( L"style" );
	return !style.IsNull() ? EditStyle( style ) : EditStyle::Normal;
}

Orientation UiReader::GetOrientation() const
{
	String orientation = _rd.GetAttributeValue( L"orientation" );
	return !orientation.IsNull() ? Orientation( orientation ) : Orientation::Horizontal;
}

ProgressType UiReader::GetProgressType() const
{
	String type = _rd.GetAttributeValue( L"type" );
	return !type.IsNull() ? ProgressType( type ) : ProgressType::Bar;
}

String UiReader::Evaluate( const String& text ) const
{
	String value = text.Replace( _widthName, _widthValue ).Replace( _heightName, _heightValue );
	if ( value.EntryCount(L',') == 2 )
	{
		String entry1 = Calcuate( value.Entry(0, L',') );
		String entry2 = Calcuate( value.Entry(1, L',') );
		return entry1.Append(L',').Append(entry2);
	}
	return text;
}

String UiReader::Calcuate( const String& text ) const
{
	if ( text.EntryCount(L'-') == 2 )
	{
		String arg1 = text.Entry( 0, L'-' );
		String arg2 = text.Entry( 1, L'-' );
		if ( arg1.IsInteger() && arg2.IsInteger() )
		{
			const Int res = arg1.ToInteger() - arg2.ToInteger();
			return String( res );
		}
	}
	return text;
}


} // ui


} // synkro
