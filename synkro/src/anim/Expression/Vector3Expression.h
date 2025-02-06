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
// Purpose: 3-component vector expression.
//==============================================================================
#ifndef _SYNKRO_ANIM_VECTOR3EXPRESSION_
#define _SYNKRO_ANIM_VECTOR3EXPRESSION_


#include "config.h"
#include "SimpleExpression.h"
#include <math/Vector3.h>


namespace synkro
{


namespace anim
{


// 3-component vector expression.
class Vector3Expression : 
	public SimpleExpression
{
public:
	// Constructor.
	Vector3Expression( const Vector3Expression& other );
	Vector3Expression();

	void													GetValue( Float* value );
	Expression*												Clone( BaseExpressionScript* script ) const;

	math::Vector3											Value;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_VECTOR3EXPRESSION_
