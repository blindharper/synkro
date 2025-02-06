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
// Purpose: Defines xml text reader.
//==============================================================================
#include "config.h"
#include "XmlReader.h"
#include <lang/BadArgumentException.h>
#include <internal/SafeDelete.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


XmlReader::XmlReader( IStream* stream, const char* encoding, Bool separate ) :
	TextReader( stream, encoding ),
	_separate( separate ),
	_attrNames( A(String) ),
	_attrValues( A(AttributeEntry) ),
	_doc( nullptr ),
	_node( nullptr )
{
	Init();
}

XmlReader::XmlReader( IStream* stream, const char* encoding ) :
	TextReader( stream, encoding ),
	_separate( false ),
	_attrNames( A(String) ),
	_attrValues( A(AttributeEntry) ),
	_doc( nullptr ),
	_node( nullptr )
{
	Init();
}

XmlReader::XmlReader( IStream* stream, Bool separate ) :
	TextReader( stream ),
	_separate( separate ),
	_attrNames( A(String) ),
	_attrValues( A(AttributeEntry) ),
	_doc( nullptr ),
	_node( nullptr )
{
	Init();
}

XmlReader::XmlReader( IStream* stream ) :
	TextReader( stream ),
	_separate( false ),
	_attrNames( A(String) ),
	_attrValues( A(AttributeEntry) ),
	_doc( nullptr ),
	_node( nullptr )
{
	Init();
}

XmlReader::~XmlReader()
{
	SafeDelete( _doc );
}

Bool XmlReader::Read()
{
	if ( _node == nullptr )
		return Update( _doc->Root() );

	if ( !_separate || _isStart )
	{
		XmlElement* child = (XmlElement*)_node->FirstChild();
		if ( child != nullptr )
			return Update( child );
	}

	XmlElement* sibling = (XmlElement*)_node->Next();
	if ( sibling != nullptr )
		return Update( sibling );

	_node = (XmlElement*)_node->Parent();

	if ( !_separate )
	{
		for ( ; _node != nullptr ; _node = (XmlElement*)_node->Parent() )
		{
			if ( _node->Next() != nullptr )
				return Update( (XmlElement*)_node->Next() );
		}
		return Update( nullptr );
	}

	return Update( _node, false );
}

String XmlReader::GetName() const
{
	return _name;
}

String XmlReader::GetText() const
{
	return _text;
}

String XmlReader::GetValue() const
{
	return _value;
}

Bool XmlReader::IsStart() const
{
	return _isStart;
}

Bool XmlReader::IsEnd() const
{
	return !IsStart();
}

Bool XmlReader::HasAttributes() const
{
	return GetAttributeCount() > 0;
}

UInt XmlReader::GetAttributeCount() const
{
	return _attrNames.Size();
}

String XmlReader::GetAttributeName( UInt index ) const
{
	assert( index < _attrNames.Size() );

	if ( index >= _attrNames.Size() )
		throw BadArgumentException( L"Invalid XML node attribute index.", L"index" );

	return _attrNames[index];
}

String XmlReader::GetAttributeValue( UInt index ) const
{
	return GetAttributeValue( GetAttributeName(index) );
}

String XmlReader::GetAttributeValue( const String& name ) const
{
	assert( !name.IsNull() );

	if ( name.IsNull() )
		throw BadArgumentException( L"Null XML node attribute names are not allowed.", L"name", name );

	if ( !_attrValues.ContainsKey(name) )
		return String::Null;
	else
		return _attrValues[name];
}

void XmlReader::Init()
{
	Vector<Char> chars( A(Char) );
	Vector<Char> symbol( A(Char) );

	// Read and build XML document tree.
	_doc = new XmlDocument();
	UInt lineNum = 0; String line; String attr; String tmp;
	Bool insideTag = false; Bool insideComment = false; Bool insideAttr = false;
	Bool insideQuote = false; Bool insideApos = false;
	Bool insideSymbol = false; Bool isEnd = false;
	for ( ; (line = ReadLine()) != String::Null; ++lineNum )
	{
		insideTag = false;
		const UInt len = line.Length();
		for ( UInt i = 0; i < len; )
		{
			Bool ok = false;
			const Char ch = line[i++];
			const Char next = (i+1 < len) ? line[i+1] : (Char)0;
			switch ( ch )
			{
				case L'<':
					Verify( !insideTag, lineNum, i );
					insideTag = true;
					ok = true;
					break;

				case L'>':
					Verify( insideTag, lineNum, i );

					if ( isEnd )
					{
						if ( chars.Size() > 0 )
						{
							chars.Add( L'\0' );
							tmp = String( chars.Begin() );
							Verify( (_node != nullptr), lineNum, i );
						}
						if ( _node != nullptr )
						{
							_node = (XmlElement*)_node->Parent();
						}
						isEnd = false;
						chars.Clear();
					}
					else if ( chars.Size() > 0 )
					{
						chars.Add( L'\0' );
						tmp = String( chars.Begin() );
						XmlElement* elem = new XmlElement( tmp );
						if ( _node != nullptr )
							_node->AddChild( elem );
						else if ( _doc != nullptr )
							_doc->AddChild( elem );

						_node = elem;
						chars.Clear();
					}

					insideTag = false;
					ok = true;
					break;

				case L'/':
					if ( insideTag && !insideQuote )
					{
						if ( next != '>' )
						{
							if ( chars.Size() > 0 )
							{
								chars.Add( L'\0' );
								tmp = String( chars.Begin() );
								if ( _node != nullptr )
								{
									_node->SetText( tmp );
								}
								chars.Clear();
							}
							isEnd = true;
						}
						else
						{
							++i;
							isEnd = false;
							insideTag = false;
						}
						ok = true;
					}
					break;

				case L'!':
					if ( !insideQuote )
					{
						Verify( (i+1 < len) && (line[i] == L'-') && (next == L'-'), lineNum, i );
						++i;
						insideComment = true;
						ok = true;
					}
					break;

				case L'-':
					if ( insideComment && !chars.IsEmpty() )
					{
						Verify( (i+1 < len) && (line[i] == L'-') && (next == L'>'), lineNum, i );
						chars.Add( L'\0' );
						tmp = String( chars.Begin()+1 );
						XmlComment* comment = new XmlComment( tmp );
						if ( _node != nullptr )
							_node->AddChild( comment );
						else if ( _doc != nullptr )
							_doc->AddChild( comment );

						i += 2;
						chars.Clear();
						insideTag = false;
						insideComment = false;
						ok = true;
					}
					break;

				case L' ':
					if ( insideTag && !insideComment && !insideQuote )
					{
						if ( chars.Size() > 0 )
						{
							chars.Add( L'\0' );
							tmp = String( chars.Begin() );
							XmlElement* elem = new XmlElement( tmp );
							if ( _node != nullptr )
								_node->AddChild( elem );
							else if ( _doc != nullptr )
								_doc->AddChild( elem );

							_node = elem;
							chars.Clear();
						}
						insideAttr = true;
						ok = true;
					}
					break;

				case L'=':
					if ( insideAttr && !insideQuote )
					{
						chars.Add( L'\0' );
						attr = String( chars.Begin() );
						chars.Clear();
						insideAttr = false;
						ok = true;
					}
					break;

				case L'\'':
					if ( !insideQuote )
					{
						if ( insideApos && !attr.IsNull() && !attr.IsEmpty() )
						{
							chars.Add( L'\0' );
							tmp = String( chars.Begin() );
							XmlAttribute* attribute = new XmlAttribute( attr, tmp );
							if ( _node != nullptr )
							{
								_node->AddAttribute( attribute );
							}
							chars.Clear();
							insideApos = false;
							insideAttr = false;
						}
						else
						{
							chars.Add( ch );
							insideApos = true;
						}
						ok = true;
					}
					break;

				case L'\"':
					if ( !insideApos )
					{
						if ( insideQuote && !attr.IsNull() && !attr.IsEmpty() )
						{
							chars.Add( L'\0' );
							tmp = String( chars.Begin() );
							XmlAttribute* attribute = new XmlAttribute( attr, tmp );
							if ( _node != nullptr )
							{
								_node->AddAttribute( attribute );
							}

							chars.Clear();
							insideQuote = false;
							insideAttr = false;
						}
						else
						{
							insideQuote = true;
						}
						ok = true;
					}
					break;

				case L'&':
					Verify( !insideSymbol, lineNum, i );
					insideSymbol = true;
					ok = true;
					break;

				case L';':
					if ( insideSymbol )
					{
						symbol.Add( L'\0' );
						String sym( symbol.Begin() );
						if ( sym.EqualsTo(L"amp", true) ) chars.Add( L'&' );
						else if ( sym.EqualsTo(L"lt", true) ) chars.Add( L'<' );
						else if ( sym.EqualsTo(L"gt", true) ) chars.Add( L'>' );
						else if ( sym.EqualsTo(L"quot", true) ) chars.Add( L'\"' );
						else if ( sym.EqualsTo(L"apos", true) ) chars.Add( L'\'' );
						symbol.Clear();
						insideSymbol = false;
						ok = true;
					}
					break;
			}

			if ( !ok )
			{
				if ( insideSymbol )
				{
					symbol.Add( ch );
				}
				else if ( (ch == L' ') && (insideQuote || !insideTag) )
				{
					chars.Add( ch );
				}
				else if ( (ch != L' ') && (ch != L'\t') && (ch != L'\r') && (ch != L'\n') )
				{
					chars.Add( ch );
				}
			}
		}
	}

	_node = nullptr;
}

Bool XmlReader::Update( XmlElement* node, Bool isStart )
{
	_node		= node;
	_isStart	= isStart;

	if ( _node == nullptr )
	{
		_name = String::Empty;
		_text = String::Empty;
		_attrNames.Clear();
		_attrValues.Clear();
		return false;
	}

	_name = _node->Name();
	_text = _node->Text();
	if ( (_node->Type() == XMLNODE_DOCUMENT) && !_isStart )
		return false;

	// Get attributes.
	_attrNames.Clear();
	_attrValues.Clear();
	XmlAttribute* a = _node->FirstAttribute();
	for ( ; a ; a = a->Next() )
	{
		String attrName = a->Name();
		String attrValue = a->Value();

		_attrNames.Add( attrName );
		_attrValues[attrName] = attrValue;
	}

	return true;
}

Bool XmlReader::Update( XmlElement* node )
{
	return Update( node, true );
}

void XmlReader::Verify( Bool valid, UInt line, UInt pos )
{
	if ( !valid )
		throw Exception( String::Format(L"Malformatted XML document. Line={0}. Position={1}.", line, pos) );
}


} // io


} // synkro
