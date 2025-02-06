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
// Purpose: Expression list.
//==============================================================================
#ifndef _SYNKRO_ANIM_EXPRESSIONLIST_
#define _SYNKRO_ANIM_EXPRESSIONLIST_


#include "config.h"
#include <lang/Vector.h>
#include "Expression.h"


namespace synkro
{


namespace anim
{


// Expression list.
class ExpressionList
{
public:
	ExpressionList( const ExpressionList& other, BaseExpressionScript* script );
	ExpressionList();
	~ExpressionList();

	ExpressionList*											Clone( BaseExpressionScript* script ) const;
	void													Prepend( Expression* expr );
	void													Append( Expression* expr );
	UInt													GetSize() const;
	Expression*												Get( UInt index ) const;
	Bool													ReferencesVariable( const lang::String& name ) const;

private:
	lang::Vector<Expression*>								_list;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_EXPRESSIONLIST_
