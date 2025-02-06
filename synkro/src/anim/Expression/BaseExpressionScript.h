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
// Purpose: Defines base expression script.
//==============================================================================
#ifndef _SYNKRO_ANIM_BASEEXPRESSIONSCRIPT_
#define _SYNKRO_ANIM_BASEEXPRESSIONSCRIPT_


#include "config.h"
#include "Variable.h"
#include "Expression.h"


namespace synkro
{


namespace anim
{


class ExpressionStatement;


// Base expression script.
class BaseExpressionScript
{
public:
	virtual void											Validate() = 0;
	virtual void											DeclareVariable( Variable* var ) = 0;
	virtual void											SetReturnValue( Expression* value ) = 0;
	virtual void											AddStatement( ExpressionStatement* statement ) = 0;
	virtual ExpressionParam*								GetParameter( const lang::String& name ) const = 0;
	virtual Variable*										CloneVariable( const lang::String& name ) const = 0;
};


// Casts object to BaseExpressionScript.
#define AsBaseExpressionScript( OBJ ) dynamic_cast<BaseExpressionScript*>( OBJ )


} // anim


} // synkro


#endif // _SYNKRO_ANIM_BASEEXPRESSIONSCRIPT_
