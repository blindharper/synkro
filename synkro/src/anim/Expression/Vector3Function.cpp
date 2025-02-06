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
// Purpose: 3-component vector constructor.
//==============================================================================
#include "config.h"
#include "Vector3Function.h"


//------------------------------------------------------------------------------

using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


Vector3Function::Vector3Function() :
	Function( L"vector3" )
{
	for ( UInt i = 0; i < 3; ++i )
	{
		_arguments.Add( AnimationDataType::Float );
	}
}

AnimationDataType Vector3Function::DeduceType( ExpressionList* arguments )
{
	if ( arguments->GetSize() == 3 )
	{
		for ( UInt i = 0; i < 3; ++i )
		{
			if ( arguments->Get(i)->ValueType != AnimationDataType::Float )
				return AnimationDataType::Unknown;
		}
		return AnimationDataType::Vector3;
	}
	return AnimationDataType::Unknown;
}

Expression* Vector3Function::Call( ExpressionList* arguments )
{
	Float x = 0.0f; Float y = 0.0f; Float z = 0.0f;
	arguments->Get( 0 )->GetValue( &x );
	arguments->Get( 1 )->GetValue( &y );
	arguments->Get( 2 )->GetValue( &z );
	_value.Value = Vector3( x, y, z );
	return &_value;
}


} // anim


} // synkro
