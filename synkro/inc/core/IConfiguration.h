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
// Purpose: Defines configuration parameter storage.
//==============================================================================
#ifndef _SYNKRO_CORE_ICONFIGURATION_
#define _SYNKRO_CORE_ICONFIGURATION_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>
#include <lang/Enum.h>
#include <img/Color.h>


namespace synkro
{


namespace core
{


/**
 * Configuration parameter storage.
 */
iface IConfiguration :
	public IObject
{
public:
	/**
	 * Reads configuration from stream.
	 * @param stream Stream from which to read configuration.
	 * @exception IoException Bad stream.
	 */
	virtual void											Load( io::IStream* stream ) = 0;

	/**
	 * Writes configuration to stream.
	 * @param stream Stream to write configuration to.
	 * @exception IoException Bad stream.
	 */
	virtual void											Save( io::IStream* stream ) = 0;

	/**
	 * Registers configuration parameter.
	 * @param param Parameter definition.
	 * @exception Exception.
	 */
	virtual void											RegisterParam( const Param* param ) = 0;

	/**
	 * Retrieves first parameter name.
	 */
	virtual lang::String									GetFirstParam() = 0;

	/**
	 * Retrieves next parameter name.
	 * @return Non-empty string if not last parameter, empty string otherwise.
	 */
	virtual lang::String									GetNextParam() = 0;

	/**
	 * Verifies registered parameters against their constraints.
	 * @exception ConfigurationException.
	 */
	virtual void											Validate() = 0;

	/**
	 * Sets logical parameter value.
	 * @param param Name of the parameter to set.
	 * @param value New value of the parameter.
	 */
	virtual void											Set( const lang::String& param, Bool value ) = 0;

	/**
	 * Sets integer parameter value.
	 * @param param Name of the parameter to set.
	 * @param value New value of the parameter.
	 */
	virtual void											Set( const lang::String& param, UInt value ) = 0;

	/**
	 * Sets enumeration parameter value.
	 * @param param Name of the parameter to set.
	 * @param value New value of the parameter.
	 */
	virtual void											Set( const lang::String& param, const lang::Enum& value ) = 0;

	/**
	 * Sets string parameter value.
	 * @param param Name of the parameter to set.
	 * @param value New value of the parameter.
	 */
	virtual void											Set( const lang::String& param, const lang::String& value ) = 0;

	/**
	 * Sets string parameter value.
	 * @param param Name of the parameter to set.
	 * @param value New value of the parameter.
	 */
	virtual void											Set( const lang::String& param, const char* value ) = 0;

	/**
	 * Sets color parameter value.
	 * @param param Name of the parameter to set.
	 * @param value New value of the parameter.
	 */
	virtual void											Set( const lang::String& param, const img::Color& value ) = 0;

	/**
	 * Retrieves logical parameter value.
	 * @param param Name of the parameter to retrieve.
	 * @param [out] value Variable to hold parameter value.
	 */
	virtual void											Get( const lang::String& param, Bool* value ) const = 0;

	/**
	 * Retrieves integer parameter value.
	 * @param param Name of the parameter to retrieve.
	 * @param [out] value Variable to hold parameter value.
	 */
	virtual void											Get( const lang::String& param, Int* value ) const = 0;

	/**
	 * Retrieves enumeration parameter value.
	 * @param param Name of the parameter to retrieve.
	 * @param [out] value Variable to hold parameter value.
	 */
	virtual void											Get( const lang::String& param, lang::Enum* value ) const = 0;

	/**
	 * Retrieves string parameter value.
	 * @param param Name of the parameter to retrieve.
	 * @param [out] value Variable to hold parameter value.
	 */
	virtual void											Get( const lang::String& param, lang::String* value ) const = 0;

	/**
	 * Retrieves color parameter value.
	 * @param param Name of the parameter to retrieve.
	 * @param [out] value Variable to hold parameter value.
	 */
	virtual void											Get( const lang::String& param, img::Color* value ) const = 0;

	/**
	 * Retrieves registered configuration parameter definition by name.
	 * @param name Parameter name.
	 * @return Configuration parameter definition, if one exists, or nullptr otherwise.
	 */
	virtual const Param*									GetParam( const lang::String& name ) const = 0;

	/**
	 * Produces an exact copy of the configuration.
	 */
	virtual IConfiguration*									Clone() const = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_ICONFIGURATION_
