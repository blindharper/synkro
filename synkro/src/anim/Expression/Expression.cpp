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
// Purpose: Abstract expression.
//==============================================================================
#include "config.h"
#include "Expression.h"


namespace synkro
{


namespace anim
{


Expression::Expression( ExpressionType type, const AnimationDataType& valueType ) :
	Type( type ),
	ValueType( valueType )
{
}

Expression::Expression( ExpressionType type ) :
	Type( type ),
	ValueType( AnimationDataType::Unknown )
{
}

Expression::~Expression()
{
}

void Expression::GetValue( Float* value )
{
}

Bool Expression::ReferencesVariable( const lang::String& name ) const
{
	return false;
}


} // anim


} // synkro
