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
#ifndef _SYNKRO_CORE_CONFIGURATION_
#define _SYNKRO_CORE_CONFIGURATION_


#include "config.h"
#include "ObjectImpl.h"
#include <core/IConfiguration.h>
#include <core/Param.h>
#include <lang/Vector.h>
#include <lang/Map.h>


namespace synkro
{


namespace core
{


// Parameter value.
class ParamValue :
	public Param
{
public:
	ParamValue( lang::String Value, const lang::String& name, const ParamType type, const ParamConstraint constraints, const lang::String& defaultValue, const lang::String& data, const lang::String& description );
	ParamValue();

	void operator=( const ParamValue& other );

	lang::String Value;
};


// Configuration parameter storage implementation.
class Configuration :
	public ObjectImpl<IConfiguration>,
	public lang::MapCI<lang::String, ParamValue>
{
public:
	// Constructors.
	Configuration();
	Configuration( const Configuration& other );

	// IConfiguration methods.
	void													Load( io::IStream* stream );
	void													Save( io::IStream* stream );
	void													RegisterParam( const Param* param );
	lang::String											GetFirstParam();
	lang::String											GetNextParam();
	void													Validate();
	void													Set( const lang::String& param, Bool value );
	void													Set( const lang::String& param, UInt value );
	void													Set( const lang::String& param, const lang::Enum& value );
	void													Set( const lang::String& param, const lang::String& value );
	void													Set( const lang::String& param, const char* value );
	void													Set( const lang::String& param, const img::Color& value );
	void													Get( const lang::String& param, Bool* value ) const;
	void													Get( const lang::String& param, Int* value ) const;
	void													Get( const lang::String& param, lang::Enum* value ) const;
	void													Get( const lang::String& param, lang::String* value ) const;
	void													Get( const lang::String& param, img::Color* value ) const;
	const Param*											GetParam( const lang::String& name ) const;
	IConfiguration*											Clone() const;

	// Other methods.
	void													Lock();

private:
	typedef lang::MapCI<lang::String, ParamValue>			Dict;
	typedef lang::MapPair<lang::String, ParamValue>			DictEntry;
	typedef lang::MapIterator<lang::String, ParamValue>		DictIterator;

	Bool													_readonly;
	lang::Vector<lang::String>								_keys;
	UInt													_currentKey;

	void													SortKeys();
	void													ValidateParam( const ParamValue& param );
	void													VerifyWriteable();
};


} // core


} // synkro


#endif // _SYNKRO_CORE_CONFIGURATION_
