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
#ifndef _SYNKRO_IO_XMLREADER_
#define _SYNKRO_IO_XMLREADER_


#include "config.h"
#include "XmlDocument.h"
#include "TextReader.h"
#include <lang/Map.h>
#include <lang/Formatter.h>


namespace synkro
{


namespace io
{


// Xml text reader.
class SYNKRO_API XmlReader :
	public TextReader
{
public:
	// Constructors & destructor.
	XmlReader( IStream* stream, const char* encoding, Bool separate );
	XmlReader( IStream* stream, const char* encoding );
	XmlReader( IStream* stream, Bool separate );
	XmlReader( IStream* stream );
	~XmlReader();

	// Methods.
	Bool													Read();
	lang::String											GetName() const;
	lang::String											GetText() const;
	lang::String											GetValue() const;
	Bool													IsStart() const;
	Bool													IsEnd() const;
	Bool													HasAttributes() const;
	UInt													GetAttributeCount() const;
	lang::String											GetAttributeName( UInt index ) const;
	lang::String											GetAttributeValue( UInt index ) const;
	lang::String											GetAttributeValue( const lang::String& name ) const;

private:
	typedef lang::MapPair<lang::String, lang::String>		AttributeEntry;

	Bool													_separate;
	XmlDocument*											_doc;
	XmlElement*												_node;
	lang::Vector<lang::String>								_attrNames;
	lang::MapCI<lang::String, lang::String>					_attrValues;
	lang::String											_name;
	lang::String											_text;
	lang::String											_value;
	Bool													_isStart;

	void													Init();
	Bool													Update( XmlElement* node, Bool isStart );
	Bool													Update( XmlElement* node );

	void													Verify( Bool valid, UInt line, UInt pos );
};


} // io


} // synkro


#endif // _SYNKRO_IO_XMLREADER_
