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
#ifndef _SYNKRO_IO_XMLDOCUMENT_
#define _SYNKRO_IO_XMLDOCUMENT_


#include "config.h"
#include <lang/String.h>
#include <mem/OperatorNew.h>


namespace synkro
{


namespace io
{


// XML node type.
enum XmlNodeType
{
	XMLNODE_UNKNOWN,
	XMLNODE_DOCUMENT,
	XMLNODE_DECLARATION,
	XMLNODE_COMMENT,
	XMLNODE_ELEMENT,
};


// XML attribute.
class XmlAttribute
{
public:
	XmlAttribute( const lang::String& name, const lang::String& value );

	XmlAttribute*											Next() const;
	lang::String											Name() const;
	lang::String											Value() const;

private:
	friend class XmlElement;

	lang::String											_name;
	lang::String											_value;
	XmlAttribute*											_next;
};

// Abstract XML node.
class XmlNode
{
public:
	XmlNode( const lang::String& name, int type );
	XmlNode( int type );
	virtual ~XmlNode();

	void													AddChild( XmlNode* child );
	XmlNode*												Parent() const;
	XmlNode*												FirstChild() const;
	XmlNode*												Next() const;
	lang::String											Name() const;
	int														Type() const;

protected:
	lang::String											_name;
	int														_type;
	XmlNode*												_parent;
	XmlNode*												_firstChild;
	XmlNode*												_lastChild;
	XmlNode*												_next;
};

// XML comment.
class XmlComment :
	public XmlNode
{
public:
	XmlComment( const lang::String& value );

	lang::String											Value() const;

private:
	lang::String											_value;
};

// XML element.
class XmlElement :
	public XmlNode
{
public:
	XmlElement( const lang::String& name );
	~XmlElement();

	void													SetText( const lang::String& text );
	void													AddAttribute( XmlAttribute* attr );
	XmlAttribute*											FirstAttribute() const;
	lang::String											Text() const;

private:
	lang::String											_text;
	XmlAttribute*											_firstAttr;
	XmlAttribute*											_lastAttr;
};

// XML declaration.
class XmlDeclaration :
	public XmlNode
{
public:
	XmlDeclaration( const lang::String& version, const lang::String& encoding, Bool standalone );

	lang::String											Version() const;
	lang::String											Encoding() const;
	Bool													Standalone() const;

private:
	lang::String											_version;
	lang::String											_encoding;
	Bool													_standalone;
};

// XML document.
class XmlDocument
{
public:
	XmlDocument();
	~XmlDocument();

	void													AddChild( XmlNode* child );
	void													SetDeclaration( XmlDeclaration* decl );
	XmlElement*												Root() const;
	XmlDeclaration*											Declaration() const;

private:
	XmlElement*												_root;
	XmlDeclaration*											_decl;
};


} // io


} // synkro


#endif // _SYNKRO_IO_XMLDOCUMENT_
