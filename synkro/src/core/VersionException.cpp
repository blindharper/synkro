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
// Purpose: Implements version exception.
//==============================================================================
#include "config.h"
#include <core/VersionException.h>
#include <core/Str.h>
#include <cfg/SynkroVersion.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


VersionException::VersionException( const core::Version& version ) :
	Exception( String::Format(Str::IncompatibleVersion, CastDouble(version.Major), CastDouble(version.Minor), CastDouble(version.Patch), CastDouble(SYNKRO_VERSION_MAJOR)) ),
	_version( version )
{
}

core::Version VersionException::Version() const
{
	return _version;
}

String VersionException::ToString() const
{
	return _message;
}

VersionException::VersionException( const VersionException& )
{
}

VersionException& VersionException::operator=( const VersionException& )
{
	return *this;
}


} // core


} // synkro
