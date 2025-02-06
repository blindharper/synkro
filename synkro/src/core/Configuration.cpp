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
// Purpose: Implements configuration parameter storage.
//==============================================================================
#include "config.h"
#include "Configuration.h"
#include <core/ConfigurationException.h>
#include <lang/Convert.h>
#include <io/TextReader.h>
#include <io/TextWriter.h>
#include <io/IStream.h>
#include "ParamTypeConst.h"


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


ParamValue::ParamValue( String value, const String& name, const ParamType type, const ParamConstraint constraints,
						const String& defaultValue, const String& data, const String& description ) :
	Param( name, type, constraints, defaultValue, data, description ),
	Value( value )
{
}

ParamValue::ParamValue() :
	Param( L"", ParamType::String, ParamConstraint::None, L"", L"", L"" ),
	Value( L"" )
{
}

void ParamValue::operator=( const ParamValue& other )
{
	this->Value			= other.Value;
	this->Name			= other.Name;
	this->Type			= other.Type;
	this->Data			= other.Data;
	this->Constraints	= other.Constraints;
	this->Description	= other.Description;
	this->DefaultValue	= other.DefaultValue;
}

//------------------------------------------------------------------------------

Configuration::Configuration() :
	Dict( A(DictEntry) ),
	_readonly( false ),
	_keys( A(String) ),
	_currentKey( 0 )
{
}

Configuration::Configuration( const Configuration& other ) :
	Dict( other ),
	_readonly( false ),
	_keys( other._keys ),
	_currentKey( 0 )
{
}

void Configuration::Load( IStream* stream )
{
	Int lineno = 0;
	String line;

	TextReader reader( stream );
	while ( (line = reader.ReadLine()) != String::Null )
	{
		++lineno;

		// Skip comments.
		if ( line.StartsWith(L'#') )
			continue;

		// Parse line and extract parameter name and value.
		const UInt idxDelim = line.IndexOf( L'=' );
		if ( idxDelim == none )
			throw ConfigurationException( String::Format(L"Configuration formatting error: missing assignment operator at line {0}.", lineno) );

		if ( idxDelim == 0 )
			throw ConfigurationException( String::Format(L"Configuration formatting error: missing parameter name at line {0}.", lineno) );
		
		// Make sure the parameter exists.
		String key = line.Substring( 0, idxDelim ).Trim();
		if ( !Dict::ContainsKey(key) )
			throw ConfigurationException( String::Format(L"Configuration parameter {0,q} is not registered.", key), key );

		// Insert parameter.
		String value = line.Substring( idxDelim+1 ).Trim();
		ParamValue p = Dict::Get( key );
		switch ( p.Type )
		{
			case PARAM_TYPE_STRING:
			case PARAM_TYPE_LIST:
				Set( key, value );
				break;

			case PARAM_TYPE_INTEGER:
			case PARAM_TYPE_ENUMERATION:
			case PARAM_TYPE_FLAG:
				Set( key, Convert::ToUInt(value) );
				break;

			case PARAM_TYPE_BOOLEAN:
				Set( key, Convert::ToBool(value) );
				break;

			default:
				break;
		}
	}
}

void Configuration::Save( IStream* stream )
{
	// Sort parameter names alphabetically.
	SortKeys();

	// Write configuration to stream.
	Formatter fmt( L"{0} = {1}" );
	TextWriter writer( stream );
	for ( UInt i = 0; i < _keys.Size(); ++i )
	{
		ParamValue p = Dict::Get( _keys[i] );
		if ( p.Type == ParamType::List )
		{
			const UInt entriesCount = p.Value.EntryCount( L'|' );
			for ( UInt j = 0; j < entriesCount; ++j )
			{
				fmt.Map( _keys[i], p.Value.Entry(j, L'|') );
				writer.WriteLine( fmt.ToString() );
			}
		}
		else
		{
			fmt.Map( _keys[i], p.Value );
			writer.WriteLine( fmt.ToString() );
		}
	}
}

void Configuration::RegisterParam( const Param* param )
{
	assert( param != nullptr );

	VerifyWriteable();

	// Make sure the parameter name is unique.
	if ( Dict::ContainsKey(param->Name) )
		throw ConfigurationException( String::Format(L"Configuration parameter {0,q} is already registered.", param->Name), param->Name );

	// Parameter name should be non-empty.
	if ( param->Name.IsEmpty() )
		throw ConfigurationException( L"Configuration parameter name should be non-empty." );

	// Create parameter.
	ParamValue value( param->DefaultValue, param->Name, param->Type, param->Constraints, param->DefaultValue, param->Data, param->Description );

	// Perform validation.
	ValidateParam( value );

	// Register parameter.
	Dict::Put( param->Name, value );
}

String Configuration::GetFirstParam()
{
	SortKeys();
	return _keys[(_currentKey = 0)];
}

String Configuration::GetNextParam()
{
	++_currentKey;
	return (_currentKey < _keys.Size()) ? _keys[_currentKey] : String::Empty;
}

void Configuration::Validate()
{
	for ( DictIterator it = Begin(); it != End(); ++it )
	{
		ValidateParam( it.Value() );
	}
}

void Configuration::Set( const String& param, Bool value )
{
	VerifyWriteable();

	// Make sure the parameter exists.
	if ( !Dict::ContainsKey(param) )
		throw ConfigurationException( String::Format(L"Configuration parameter {0,q} is not registered.", param), param );

	// Verify parameter type.
	ParamValue& p = Dict::Get( param );
	if ( p.Type != ParamType::Boolean )
		throw ConfigurationException( String::Format(L"Configuration parameter {0,q} is not of type Boolean.", param), param );

	// Update parameter value.
	p.Value = Convert::ToString( value );
}

void Configuration::Set( const String& param, UInt value )
{
	VerifyWriteable();

	// Make sure the parameter exists.
	if ( !Dict::ContainsKey(param) )
		throw ConfigurationException( String::Format(L"Configuration parameter {0,q} is not registered.", param), param );

	// Update parameter value.
	ParamValue& p = Dict::Get( param );
	switch ( p.Type )
	{
		case PARAM_TYPE_INTEGER:
		case PARAM_TYPE_ENUMERATION:
		case PARAM_TYPE_FLAG:
			p.Value = Convert::ToString( value );
			break;

		default:
			throw ConfigurationException( String::Format(L"Configuration parameter {0,q} is not of type Integer, Enum or Flag.", param), param );
	}
}

void Configuration::Set( const String& param, const Enum& value )
{
	Set( param, CastUInt(value.Value()) );
}

void Configuration::Set( const String& param, const String& value )
{
	VerifyWriteable();

	// Make sure the parameter exists.
	if ( !Dict::ContainsKey(param) )
		throw ConfigurationException( String::Format(L"Configuration parameter {0,q} is not registered.", param), param );

	// Update parameter type.
	String list; UInt val = 0;
	ParamValue& p = Dict::Get( param );
	switch ( p.Type )
	{
		case PARAM_TYPE_STRING:
			p.Value = value;
			break;

		case PARAM_TYPE_LIST:
			// List parameter should not contain '|' characters in it.
			if ( value.Contains(L'|') )
				throw ConfigurationException( String::Format(L"List parameter {0,q} should not contain '|' characters.", param), param );

			// Extract string list.
			list = p.Value;

			// Clear string list.
			if ( value.IsEmpty() )
			{
				list = String::Empty;
			}
			// Add element to the string list, if it is not added yet.
			else if ( list.EntryIndex(value, L'|') == none )
			{
				list = list.IsEmpty() ? (list + value) : (list + L"|" + value);
			}

			// Update string list.
			p.Value = list;
			break;

		case PARAM_TYPE_ENUMERATION:
			val = p.Data.EntryIndex( value, L'|' );
			p.Value = (val != none) ? Convert::ToString(val) : value;
			break;

		default:
			throw ConfigurationException( String::Format(L"Configuration parameter {0,q} is not of type String, List or Enum.", param), param );
	}
}

void Configuration::Set( const String& param, const char* value )
{
	Set( param, String(value) );
}

void Configuration::Set( const String& param, const Color& value )
{
	VerifyWriteable();

	// Make sure the parameter exists.
	if ( !Dict::ContainsKey(param) )
		throw ConfigurationException( String::Format(L"Configuration parameter {0,q} is not registered.", param), param );

	// Verify parameter type.
	ParamValue& p = Dict::Get( param );
	if ( p.Type != ParamType::Color )
		throw ConfigurationException( String::Format(L"Configuration parameter {0,q} is not of type color.", param), param );

	// Update parameter value.
	p.Value = value.ToString();
}

void Configuration::Get( const String& param, Bool* value ) const
{
	String val;
	Get( param, &val );
	*value = Convert::ToBool( val );
}

void Configuration::Get( const String& param, Int* value ) const
{
	// Make sure the parameter exists.
	if ( !Dict::ContainsKey(param) )
		throw ConfigurationException( String::Format(L"Configuration parameter {0,q} is not registered.", param), param );

	String val;
	const ParamValue& p = Dict::Get( param );
	switch ( p.Type )
	{
		case PARAM_TYPE_ENUMERATION:
		case PARAM_TYPE_FLAG:
			if ( p.Value.IsInteger() )
			{
				*value = Convert::ToInt( p.Value );
			}
			else
			{
				*value = p.Data.EntryIndex( p.Value, L'|' );
			}
			break;

		default:
			Get( param, &val );
			*value = Convert::ToInt( val );
			break;
	}
}

void Configuration::Get( const String& param, Enum* value ) const
{
	Int num = 0;
	Get( param, &num );
	*value = Enum( num );
}

void Configuration::Get( const String& param, String* value ) const
{
	// Make sure the parameter exists.
	if ( !Dict::ContainsKey(param) )
		throw ConfigurationException( String::Format(L"Configuration parameter {0,q} is not registered.", param), param );

	String str;
	Int val = 0;
	UInt flags = 0;
	const ParamValue& p = Dict::Get( param );
	switch ( p.Type )
	{
		case PARAM_TYPE_ENUMERATION:
			if ( p.Value.IsInteger() )
			{
				val = Convert::ToInt( p.Value );
				*value = p.Data.Entry( val, L'|' );
			}
			else
			{
				*value = p.Value;
			}
			break;

		case PARAM_TYPE_FLAG:
			val = Convert::ToInt( p.Value );
			flags = CastUInt( val );
			for ( Int i = 1; flags > 0; ++i )
			{
				if ( (flags & 0x00000001) != 0 )
				{
					if ( !str.IsEmpty() )
						str = str + "|";

					str = str + p.Data.Entry( i-1, L'|' );
				}
				flags >>= 1;
			}
			*value = str;
			break;

		default:
			*value = p.Value;
			break;
	}
}

void Configuration::Get( const String& param, Color* value ) const
{
	String str;
	Get( param, &str );
	*value = Color( str );
}

const Param* Configuration::GetParam( const String& name ) const
{
	return Dict::ContainsKey(name) ? static_cast<const Param*>( &(Dict::Get(name)) ) : 0;
}

IConfiguration* Configuration::Clone() const
{
	return new Configuration( *this );
}

void Configuration::Lock()
{
	_readonly = true;
}

void Configuration::SortKeys()
{
	_keys.Clear();
	for ( DictIterator it = Begin(); it != End(); ++it )
	{
		_keys.Add( it.Key() );
	}
	_keys.Sort();
}

void Configuration::ValidateParam( const ParamValue& param )
{
	switch ( param.Type )
	{
		case PARAM_TYPE_STRING:
			if ( param.Constraints.IsSet(ParamConstraint::NonEmpty) && param.Value.IsEmpty() )
				throw ConfigurationException( String::Format(L"String parameter {0,q} cannot be empty.", param.Name), ParamConstraint::NonEmpty );

			if ( param.Value.Contains(L'|') )
				throw ConfigurationException( String::Format(L"String parameter {0,q} should not contain '|' characters.", param.Name), param.Name );
			break;

		case PARAM_TYPE_LIST:
			if ( param.Constraints.IsSet(ParamConstraint::NonEmpty) && param.Value.IsEmpty() )
				throw ConfigurationException( String::Format(L"List parameter {0,q} cannot be empty.", param.Name), ParamConstraint::NonEmpty );
			break;

		case PARAM_TYPE_INTEGER:
			if ( param.Constraints.IsSet(ParamConstraint::Positive) && (Convert::ToUInt(param.Value) == 0) )
				throw ConfigurationException( String::Format(L"Parameter {0,q} should be positive.", param.Name), ParamConstraint::Positive );
			break;

		default:
			break;
	}
}

void Configuration::VerifyWriteable()
{
	if ( _readonly )
		throw ConfigurationException( L"Cannot modify default configuration." );
}


} // core


} // synkro
