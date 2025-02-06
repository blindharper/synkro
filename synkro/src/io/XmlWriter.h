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
#ifndef _SYNKRO_IO_XMLWRITER_
#define _SYNKRO_IO_XMLWRITER_


#include "config.h"
#include "XmlDocument.h"
#include "TextWriter.h"


namespace synkro
{


namespace io
{


// Xml text writer.
class SYNKRO_API XmlWriter :
	public TextWriter
{
public:
	// Constructors & destructor.
	XmlWriter( IStream* stream, const char* encoding );
	XmlWriter( IStream* stream );
	~XmlWriter();

	// Methods.
	void													WriteDeclaration( const lang::String& version, Bool standalone );
	void													WriteComment( const lang::String& comment );
	void													WriteString( const lang::String& elem, const lang::String& text );
	void													WriteStartElement( const lang::String& elem );
	void													WriteAttribute( const lang::String& name, const lang::String& value );
	void													WriteEndElement();

private:
	XmlDocument*											_doc;
	XmlElement*												_node;
	lang::String											_encoding;

	void													Init();
	void													WriteNode( XmlNode* node, UInt level );
};


} // io


} // synkro


#endif // _SYNKRO_IO_XMLWRITER_
