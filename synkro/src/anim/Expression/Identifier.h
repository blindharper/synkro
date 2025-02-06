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
#ifndef _SYNKRO_ANIM_IDENTIFIER_
#define _SYNKRO_ANIM_IDENTIFIER_


#include "config.h"
#include "MetaExpression.h"
#include "IdentifierType.h"
#include <anim/AnimationDataType.h>


namespace synkro
{


namespace anim
{


// Identifier description.
class Identifier : 
	public MetaExpression
{
public:
	Identifier( IdentifierType type, const lang::String& name, const AnimationDataType& dataType );

	IdentifierType											Type;
	lang::String											Name;
	AnimationDataType										DataType;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IDENTIFIER_
