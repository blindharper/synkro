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
// Purpose: Defines xml text writer.
//==============================================================================
#include "config.h"
#include "XmlWriter.h"
#include <lang/Exception.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


XmlWriter::XmlWriter( IStream* stream, const char* encoding ) :
	TextWriter( stream, encoding, false, false ),
	_doc( nullptr ),
	_node( nullptr ),
	_encoding( encoding )
{
	Init();
}

XmlWriter::XmlWriter( IStream* stream ) :
	TextWriter( stream, false, false ),
	_doc( nullptr ),
	_node( nullptr ),
	_encoding( L"UTF-7" )
{
	Init();
}

XmlWriter::~XmlWriter()
{
	if ( _doc != nullptr )
	{
		// Traverse XML document and write its nodes to underlying stream.
		XmlDeclaration* decl = _doc->Declaration();
		if ( decl != nullptr )
		{
			WriteNode( decl, 0 );
		}

		if ( _doc->Root() != nullptr )
		{
			WriteNode( _doc->Root(), 0 );
		}

		delete _doc;
		_doc = nullptr;
	}
}

void XmlWriter::WriteDeclaration( const String& version, Bool standalone )
{
	_doc->SetDeclaration( new XmlDeclaration(version, _encoding, standalone) );
}

void XmlWriter::WriteComment( const String& comment )
{
	_doc->AddChild( new XmlComment(comment) );
}

void XmlWriter::WriteString( const String& elem, const String& text )
{
	XmlElement* element = new XmlElement( elem );
	element->SetText( text );

	if ( _node != nullptr )
		_node->AddChild( element );
	else
		_doc->AddChild( element );
}

void XmlWriter::WriteStartElement( const String& elem )
{
	// Create start tag.
	XmlElement* node = new XmlElement( elem );

	// Link to the tree.
	if ( _node != nullptr )
		_node->AddChild( node );
	else
		_doc->AddChild( node );

	_node = node;
}

void XmlWriter::WriteAttribute( const String& name, const String& value )
{
	if ( _node == nullptr )
		throw Exception( L"Failed to write tag attribute. No open start tag found." );

	_node->AddAttribute( new XmlAttribute(name, value) );
}

void XmlWriter::WriteEndElement()
{
	if ( _node == nullptr )
		throw Exception( L"Failed to write end xml tag. No matching start tag." );

	_node = (XmlElement*)_node->Parent();
}

void XmlWriter::Init()
{
	_doc = new XmlDocument();
}

void XmlWriter::WriteNode( XmlNode* node, UInt level )
{
	XmlDeclaration* decl = nullptr;
	XmlComment* comment = nullptr;
	XmlElement* elem = nullptr;
	XmlAttribute* attr = nullptr;
	XmlNode* child = nullptr;

	switch ( node->Type() )
	{
		case XMLNODE_DECLARATION:
			decl = (XmlDeclaration*)node;
			TextWriter::Write( L"<?xml version=\"" );
			TextWriter::Write( decl->Version() );
			TextWriter::WriteLine( L"\"?>" );
			break;

		case XMLNODE_COMMENT:
			for ( UInt i = 0; i < level; ++i )
			{
				TextWriter::Write( L"\t" );
			}
			comment = (XmlComment*)node;
			TextWriter::Write( L"<!-- " );
			TextWriter::Write( comment->Value() );
			TextWriter::WriteLine( L" -->" );
			break;

		case XMLNODE_ELEMENT:
			for ( UInt i = 0; i < level; ++i )
			{
				TextWriter::Write( L"\t" );
			}
			TextWriter::Write( L"<" );
			elem = (XmlElement*)node;
			TextWriter::Write( elem->Name() );

			attr = elem->FirstAttribute();
			for ( ; attr != nullptr; attr = attr->Next() )
			{
				TextWriter::Write( L" " );
				TextWriter::Write( attr->Name() );
				TextWriter::Write( L"=\"" );
				TextWriter::Write( attr->Value() );
				TextWriter::Write( L"\"" );
			}
			
			child = (XmlNode*)elem->FirstChild();
			if ( child != nullptr )
			{
				if ( !elem->Text().IsEmpty() )
					TextWriter::Write( L">" );
				else
					TextWriter::WriteLine( L">" );

				for ( ; child != nullptr; child = child->Next() )
				{
					WriteNode( child, level+1 );
				}
				if ( elem->Text().IsEmpty() )
				{
					for ( UInt i = 0; i < level; ++i )
					{
						TextWriter::Write( L"\t" );
					}
				}
				TextWriter::Write( L"</" );
				TextWriter::Write( elem->Name() );
				TextWriter::WriteLine( L">" );
			}
			else
			{
				if ( elem->Text().IsEmpty() )
				{
					TextWriter::WriteLine( L"/>" );
				}
				else
				{
					TextWriter::Write( L">" );
					TextWriter::Write( elem->Text() );
					TextWriter::Write( L"</" );
					TextWriter::Write( elem->Name() );
					TextWriter::WriteLine( L">" );
				}
				
			}

			break;

		default:
			break;
	}
}


} // io


} // synkro
