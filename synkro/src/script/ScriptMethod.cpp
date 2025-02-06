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
// Purpose: Defines script method.
//==============================================================================
#include "config.h"
#include <script/ScriptMethod.h>


namespace synkro
{


namespace script
{


ScriptMethod::ScriptMethod() :
	Name( 0 ),
	InputSignature( 0 ),
	OutputSignature( 0 )
{
}

ScriptMethod::ScriptMethod( const char* name, const char* inputSignature, const char* outputSignature ) :
	Name( name ),
	InputSignature( inputSignature ),
	OutputSignature( outputSignature )
{
}


} // script


} // synkro
