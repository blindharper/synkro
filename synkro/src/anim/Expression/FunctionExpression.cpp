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
// Purpose: Function expression.
//==============================================================================
#include "config.h"
#include "FunctionExpression.h"
#include <mem/OperatorNew.h>
#include <internal/SafeDelete.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


FunctionExpression::FunctionExpression( Function* prototype ) :
	ComplexExpression( EXPRESSION_FUNCTION, AnimationDataType::Unknown ),
	Prototype( prototype ),
	_arguments( nullptr )
{
}

FunctionExpression::FunctionExpression( const FunctionExpression& other, BaseExpressionScript* script ) :
	ComplexExpression( EXPRESSION_FUNCTION, AnimationDataType::Unknown ),
	Prototype( other.Prototype ),
	_arguments( other._arguments->Clone(script) )
{
}

FunctionExpression::~FunctionExpression()
{
	SafeDelete( _arguments );
}

void FunctionExpression::GetValue( Float* value )
{
	assert( _arguments != nullptr );

	Expression* ret = Prototype->Call( _arguments );
	ret->GetValue( value );
}

Expression* FunctionExpression::Clone( BaseExpressionScript* script ) const
{
	return new FunctionExpression( *this, script );
}

Bool FunctionExpression::ReferencesVariable( const String& name ) const
{
	return _arguments->ReferencesVariable( name );
}

void FunctionExpression::SetArguments( ExpressionList* arguments )
{
	ValueType = Prototype->DeduceType( _arguments = arguments );
}


} // anim


} // synkro
