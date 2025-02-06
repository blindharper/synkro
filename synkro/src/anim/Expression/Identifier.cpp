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
// Purpose: Identifier description.
//==============================================================================
#include "config.h"
#include "Identifier.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


Identifier::Identifier( IdentifierType type, const String& name, const AnimationDataType& dataType ) :
	MetaExpression( EXPRESSION_IDENTIFIER ),
	Type( type ),
	Name( name ),
	DataType( dataType )
{
}


} // anim


} // synkro
