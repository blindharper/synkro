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
// Purpose: Defines configuration exception.
//==============================================================================
#ifndef _SYNKRO_CORE_CONFIGURATIONEXCEPTION_
#define _SYNKRO_CORE_CONFIGURATIONEXCEPTION_


#include "config.h"
#include <lang/Exception.h>
#include <core/Param.h>


namespace synkro
{


namespace core
{


/**
 * Thrown in case of an invalid configuration parameter.
 */
class SYNKRO_API ConfigurationException :
	public lang::Exception
{
public:
	/**
	 * Constructor.
	 * @param param Parameter name.
	 * @param constraint Violated constraint.
	 */
	ConfigurationException( const lang::String& param, const ParamConstraint constraint );

	/**
	 * Creates an exception with the specified error message.
	 * @param message Error message.
	 * @param param Parameter name.
	 */
	ConfigurationException( const lang::String& message, const lang::String& param );

	/**
	 * Creates an exception with the specified error message.
	 * @param message Error message.
	 */
	ConfigurationException( const lang::String& message );

	/**
	 * Retrieves the parameter that failed to meet validation constraints.
	 */
	lang::String											Param() const;

	/**
	 * Retrieves formatted error message.
	 */
	lang::String											ToString() const;

	ConfigurationException( const ConfigurationException& );

private:
	lang::String											_param;
	ParamConstraint											_constraint;

	ConfigurationException& operator=( const ConfigurationException& );
};


} // core


} // synkro


#endif // _SYNKRO_CORE_CONFIGURATIONEXCEPTION_
