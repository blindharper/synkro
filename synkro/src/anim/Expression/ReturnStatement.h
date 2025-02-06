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
#ifndef _SYNKRO_ANIM_RETURNSTATEMENT_
#define _SYNKRO_ANIM_RETURNSTATEMENT_


#include "config.h"
#include "ExpressionStatement.h"
#include "ReturnExpression.h"


namespace synkro
{


namespace anim
{


// Return statement.
class ReturnStatement : 
	public ExpressionStatement
{
public:
	ReturnStatement( ReturnExpression* value );
	ReturnStatement( const ReturnStatement& other, BaseExpressionScript* script );
	~ReturnStatement();

	void													Execute( BaseExpressionScript* script );
	Bool													IsReturn() const;
	ExpressionStatement*									Clone( BaseExpressionScript* script ) const;
	Bool													ReferencesVariable( const lang::String& name ) const;

	ReturnExpression*										Value;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_RETURNSTATEMENT_
