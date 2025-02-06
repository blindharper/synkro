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
// Purpose: Defines program resource reader.
//==============================================================================
#ifndef _SYNKRO_GFX_PROGRAMREADER_
#define _SYNKRO_GFX_PROGRAMREADER_


#include "config.h"
#include <io/XmlReader.h>
#include <lang/Vector.h>


namespace synkro
{


namespace gfx
{


// Device capability description.
struct CapDesc
{
	lang::String	Name;
	UInt			Value;
};

// Stream description.
struct StreamDesc
{
	lang::String	Name;
	lang::String	Type;
};

// Format description.
struct FormatDesc
{
	FormatDesc();

	lang::String				Name;
	lang::Vector<StreamDesc>	VertexStreams;
	lang::Vector<StreamDesc>	InstanceStreams;
};

// Program resource reader.
class ProgramReader
{
public:
	// Constructor.
	ProgramReader( io::IStreamDirectory* directory, const lang::String& system );

	// Reads the next program resource from the stream.
	Bool													Read();
	lang::String											GetName() const;
	lang::String											GetParent() const;
	UInt													GetCapabilityCount() const;
	lang::String											GetCapabilityName( UInt index ) const;
	UInt													GetCapabilityValue( UInt index ) const;
	lang::String											GetVertexCodePath() const;
	lang::String											GetHullCodePath() const;
	lang::String											GetDomainCodePath() const;
	lang::String											GetGeometryCodePath() const;
	lang::String											GetFragmentCodePath() const;
	FormatDesc*												GetInputFormat() const;
	FormatDesc*												GetOutputFormat() const;

private:
	io::XmlReader											_rd;
	Bool													_skip;
	lang::String											_path;
	lang::Vector<FormatDesc>								_formats;
	lang::Vector<CapDesc>									_caps;
	lang::String											_name;
	lang::String											_parent;
	lang::String											_pathVertex;
	lang::String											_pathHull;
	lang::String											_pathDomain;
	lang::String											_pathGeometry;
	lang::String											_pathFragment;
	UInt													_inputFormat;
	UInt													_outputFormat;

	static io::IStream*										GetManifest( io::IStreamDirectory* directory );
	UInt													GetFormat( const lang::String& name ) const;
	lang::String											GetPath( const lang::String& type ) const;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PROGRAMREADER_
