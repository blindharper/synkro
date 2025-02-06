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
#include "config.h"
#include "ProgramReader.h"
#include <lang/Convert.h>
#include <lang/Exception.h>
#include <io/Path.h>
#include <io/IStreamDirectory.h>


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


FormatDesc::FormatDesc() :
	VertexStreams( A(StreamDesc) ),
	InstanceStreams( A(StreamDesc) )
{
}


//------------------------------------------------------------------------------


ProgramReader::ProgramReader( IStreamDirectory* directory, const String& system ) :
	_rd( XmlReader(GetManifest(directory), true) ),
	_skip( false ),
	_path( system.Append(L"\\") ),
	_caps( A(CapDesc) ),
	_formats( A(FormatDesc) ),
	_inputFormat( none ),
	_outputFormat( none )
{
	// Read <resource> tag.
	if ( !_rd.Read() || (!_rd.GetName().EqualsTo(L"resource", true)) )
		throw Exception( L"Bad program resource. Missing <resource> tag." );

	// Read <formats> tag.
	if ( !_rd.Read() || (!_rd.GetName().EqualsTo(L"formats", true)) )
		throw Exception( L"Bad program resource. Missing <formats> tag." );

	// Read formats.
	while ( _rd.Read() && _rd.GetName().EqualsTo(L"format", true) && _rd.IsStart() )
	{
		FormatDesc format;
		format.Name = _rd.GetAttributeValue( L"name" );
		while ( _rd.Read() && !(_rd.GetName().EqualsTo(L"format", true) && _rd.IsEnd()) )
		{
			if ( _rd.GetName().EqualsTo(L"vertex", true) )
			{
				StreamDesc stream;
				stream.Name = _rd.GetAttributeValue( L"name" );
				stream.Type = _rd.GetAttributeValue( L"type" );
				format.VertexStreams.Add( stream );
			}
			else if ( _rd.GetName().EqualsTo(L"instance", true) )
			{
				StreamDesc stream;
				stream.Name = _rd.GetAttributeValue( L"name" );
				stream.Type = _rd.GetAttributeValue( L"type" );
				format.InstanceStreams.Add( stream );
			}
			else
			{
				break;
			}
		}
		_formats.Add( format );
	}

	// Read <programs> tag.
	if ( !_rd.Read() || (!_rd.GetName().EqualsTo(L"programs", true)) )
		throw Exception( L"Bad program resource. Missing <programs> tag." );
}

Bool ProgramReader::Read()
{
	while ( (_skip || _rd.Read()) && _rd.GetName().EqualsTo(L"program", true) && _rd.IsStart() )
	{
		_skip = false;
		_caps.Clear();
		_name = _rd.GetAttributeValue( L"name" );
		_parent = _rd.GetAttributeValue( L"parent" );
		_pathVertex = GetPath( L"vertex" );
		_pathHull = GetPath( L"hull" );
		_pathDomain = GetPath( L"domain" );
		_pathGeometry = GetPath( L"geometry" );
		_pathFragment = GetPath( L"fragment" );
		_inputFormat = GetFormat( _rd.GetAttributeValue(L"input") );
		_outputFormat = GetFormat( _rd.GetAttributeValue(L"output") );

		while ( _rd.Read() && !(_rd.GetName().EqualsTo(L"program", true) && _rd.IsEnd()) )
		{
			if ( _rd.GetName().EqualsTo(L"capabilities", true) )
			{
				while ( _rd.Read() && !(_rd.GetName().EqualsTo(L"capabilities", true) && _rd.IsEnd()) )
				{
					if ( _rd.GetName().EqualsTo(L"capability", true) )
					{
						CapDesc cap;
						cap.Name = _rd.GetAttributeValue( L"name" );
						String value = _rd.GetAttributeValue( L"value" );
						cap.Value = !value.IsNull() ? Convert::ToUInt(value) : 0;
						_caps.Add( cap );
					}
				}
				_rd.Read();
				break;
			}
			else
			{
				_skip = true;
				break;
			}
		}
		return true;
	}
	return false;
}

String ProgramReader::GetName() const
{
	return _name;
}

String ProgramReader::GetParent() const
{
	return _parent;
}

UInt ProgramReader::GetCapabilityCount() const
{
	return _caps.Size();
}

String ProgramReader::GetCapabilityName( UInt index ) const
{
	assert( index < _caps.Size() );

	return _caps[index].Name;
}

UInt ProgramReader::GetCapabilityValue( UInt index ) const
{
	assert( index < _caps.Size() );

	return _caps[index].Value;
}

String ProgramReader::GetVertexCodePath() const
{
	return _pathVertex;
}

String ProgramReader::GetHullCodePath() const
{
	return _pathHull;
}

String ProgramReader::GetDomainCodePath() const
{
	return _pathDomain;
}

String ProgramReader::GetGeometryCodePath() const
{
	return _pathGeometry;
}

String ProgramReader::GetFragmentCodePath() const
{
	return _pathFragment;
}

FormatDesc* ProgramReader::GetInputFormat() const
{
	assert( _inputFormat != none );

	return (FormatDesc*)&_formats[_inputFormat];
}

FormatDesc* ProgramReader::GetOutputFormat() const
{
	if ( _outputFormat != none )
	{
		return (FormatDesc*)&_formats[_outputFormat];
	}
	return nullptr;
}

IStream* ProgramReader::GetManifest( IStreamDirectory* directory )
{
	assert( directory != nullptr );

	// Get 'manifest.xml' file.
	IStream* stream = directory->GetStream( L"manifest.xml" );
	if ( stream == nullptr )
		throw Exception( L"Bad program resource. Missing 'manifest.xml' file." );

	return stream;
}

UInt ProgramReader::GetFormat( const String& name ) const
{
	if ( !name.IsNull() && !name.IsEmpty() )
	{
		for ( UInt i = 0; i < _formats.Size(); ++i )
		{
			if ( _formats[i].Name.EqualsTo(name, true) )
				return i;
		}
	}
	return none;
}

String ProgramReader::GetPath( const String& type ) const
{
	String name = _rd.GetAttributeValue( type );
	return !name.IsNull() ? _path.Append(name) : String::Empty;
}


} // gfx


} // synkro
