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
// Purpose: Abstract function description.
//==============================================================================
#include "config.h"
#include "Function.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


Function::Function( const String& name ) :
	Name( name ),
	_arguments( A(AnimationDataType) )
{
}

UInt Function::GetArgumentCount() const
{
	return _arguments.Size();
}

AnimationDataType Function::GetArgumentType( UInt index ) const
{
	assert( index < _arguments.Size() );

	return _arguments[index];
}


} // anim


} // synkro
