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
// Purpose: "Return" statement.
//==============================================================================
#include "config.h"
#include "ReturnStatement.h"
#include "Expression.h"
#include <internal/SafeDelete.h>


namespace synkro
{


namespace anim
{


ReturnStatement::ReturnStatement( ReturnExpression* value ) :
	Value( value )
{
}

ReturnStatement::ReturnStatement( const ReturnStatement& other, BaseExpressionScript* script ) :
	Value( (ReturnExpression*)other.Value->Clone(script) )
{
}

ReturnStatement::~ReturnStatement()
{
	SafeDelete( Value );
}

void ReturnStatement::Execute( BaseExpressionScript* script )
{
	script->SetReturnValue( Value->Value );
}

Bool ReturnStatement::IsReturn() const
{
	return true;
}

ExpressionStatement* ReturnStatement::Clone( BaseExpressionScript* script ) const
{
	return new ReturnStatement( *this, script );
}

Bool ReturnStatement::ReferencesVariable( const lang::String& name ) const
{
	return Value->ReferencesVariable( name );
}


} // anim


} // synkro
