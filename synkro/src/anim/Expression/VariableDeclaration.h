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
// Purpose: Variable declaration statement.
//==============================================================================
#ifndef _SYNKRO_ANIM_VARIABLEDECLARATION_
#define _SYNKRO_ANIM_VARIABLEDECLARATION_


#include "config.h"
#include "ExpressionStatement.h"
#include "Variable.h"


namespace synkro
{


namespace anim
{


// Variable declaration statement.
class VariableDeclaration : 
	public ExpressionStatement
{
public:
	VariableDeclaration( Variable* var );
	VariableDeclaration( const VariableDeclaration& other, BaseExpressionScript* script );
	~VariableDeclaration();

	void													Execute( BaseExpressionScript* script );
	Bool													IsDeclaration() const;
	ExpressionStatement*									Clone( BaseExpressionScript* script ) const;

	Variable*												Var;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_VARIABLEDECLARATION_
