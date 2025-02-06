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
#include "config.h"
#include "VariableDeclaration.h"
#include "Expression.h"
#include <internal/SafeDelete.h>


namespace synkro
{


namespace anim
{


VariableDeclaration::VariableDeclaration( Variable* var ) :
	Var( var )
{
}

VariableDeclaration::VariableDeclaration( const VariableDeclaration& other, BaseExpressionScript* script ) :
	Var( new Variable(other.Var->Name, other.Var->Type, other.Var->Value->Clone(script)) )
{
}

VariableDeclaration::~VariableDeclaration()
{
	SafeDelete( Var );
}

void VariableDeclaration::Execute( BaseExpressionScript* script )
{
	script->DeclareVariable( Var );
}

Bool VariableDeclaration::IsDeclaration() const
{
	return true;
}

ExpressionStatement* VariableDeclaration::Clone( BaseExpressionScript* script ) const
{
	return new VariableDeclaration( *this, script );
}


} // anim


} // synkro
