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
// Purpose: Defines XML document.
//==============================================================================
#include "config.h"
#include "XmlDocument.h"
#include <internal/SafeDelete.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


XmlAttribute::XmlAttribute( const String& name, const String& value ) :
	_next( nullptr ),
	_name( name ),
	_value( value )
{
}

XmlAttribute* XmlAttribute::Next() const
{
	return _next;
}

String XmlAttribute::Name() const
{
	return _name;
}

String XmlAttribute::Value() const
{
	return _value;
}

//------------------------------------------------------------------------------

XmlNode::XmlNode( const String& name, int type ) :
	_type( type ),
	_parent( nullptr ),
	_firstChild( nullptr ),
	_lastChild( nullptr ),
	_next( nullptr ),
	_name( name )
{
}

XmlNode::XmlNode( int type ) :
	_type( type ),
	_parent( nullptr ),
	_firstChild( nullptr ),
	_lastChild( nullptr ),
	_next( nullptr )
{
}

XmlNode::~XmlNode()
{
	XmlNode* child = _firstChild;
	while ( _firstChild != nullptr )
	{
		child = _firstChild;
		_firstChild = _firstChild->_next;
		delete child;
	}
}

void XmlNode::AddChild( XmlNode* child )
{
	if ( _firstChild == nullptr )
	{
		_firstChild = child;
		_lastChild = child;
	}
	else
	{
		_lastChild->_next = child;
		_lastChild = child;
	}
	child->_parent = this;
}

XmlNode* XmlNode::Parent() const
{
	return _parent;
}

XmlNode* XmlNode::FirstChild() const
{
	return _firstChild;
}

XmlNode* XmlNode::Next() const
{
	return _next;
}

String XmlNode::Name() const
{
	return _name;
}

int XmlNode::Type() const
{
	return _type;
}

//------------------------------------------------------------------------------

XmlComment::XmlComment( const String& value ) :
	XmlNode( XMLNODE_COMMENT ),
	_value( value )
{
}

String XmlComment::Value() const
{
	return _value;
}

//------------------------------------------------------------------------------

XmlElement::XmlElement( const String& name ) :
	XmlNode( name, XMLNODE_ELEMENT ),
	_firstAttr( nullptr ),
	_lastAttr( nullptr )
{
}

XmlElement::~XmlElement()
{
	XmlAttribute* attr = _firstAttr;
	while ( _firstAttr != nullptr )
	{
		attr = _firstAttr;
		_firstAttr = _firstAttr->_next;
		delete attr;
	}
}

void XmlElement::SetText( const String& text )
{
	_text = text;
}

void XmlElement::AddAttribute( XmlAttribute* attr )
{
	if ( _firstAttr == nullptr )
	{
		_firstAttr = attr;
		_lastAttr = attr;
	}
	else
	{
		_lastAttr->_next = attr;
		_lastAttr = attr;
	}
}

String XmlElement::Text() const
{
	return _text;
}

XmlAttribute* XmlElement::FirstAttribute() const
{
	return _firstAttr;
}

//------------------------------------------------------------------------------

XmlDeclaration::XmlDeclaration( const String& version, const String& encoding, Bool standalone ) :
	XmlNode( XMLNODE_DECLARATION ),
	_version( version ),
	_encoding( encoding ),
	_standalone( standalone )
{
}

String XmlDeclaration::Version() const
{
	return _version;
}

String XmlDeclaration::Encoding() const
{
	return _encoding;
}

Bool XmlDeclaration::Standalone() const
{
	return _standalone;
}

//------------------------------------------------------------------------------

XmlDocument::XmlDocument() :
	_root( nullptr ),
	_decl( nullptr )
{
}

XmlDocument::~XmlDocument()
{
	SafeDelete( _root );
	SafeDelete( _decl );
}

void XmlDocument::AddChild( XmlNode* child )
{
	if ( _root != nullptr )
		_root->AddChild( child );
	else
		_root = (XmlElement*)child;
}

void XmlDocument::SetDeclaration( XmlDeclaration* decl )
{
	if ( _decl == nullptr )
	{
		_decl = decl;
	}
}

XmlElement* XmlDocument::Root() const
{
	return _root;
}

XmlDeclaration*	XmlDocument::Declaration() const
{
	return _decl;
}


} // io


} // synkro
