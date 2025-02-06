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
// Purpose: 4x4 matrix constructor.
//==============================================================================
#include "config.h"
#include "Matrix4x4Function.h"


//------------------------------------------------------------------------------

using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


Matrix4x4Function::Matrix4x4Function() :
	Function( L"matrix4x4" )
{
	for ( UInt i = 0; i < 16; ++i )
	{
		_arguments.Add( AnimationDataType::Float );
	}
}

AnimationDataType Matrix4x4Function::DeduceType( ExpressionList* arguments )
{
	if ( arguments->GetSize() == 16 )
	{
		for ( UInt i = 0; i < 16; ++i )
		{
			if ( arguments->Get(i)->ValueType != AnimationDataType::Float )
				return AnimationDataType::Unknown;
		}
		return AnimationDataType::Matrix4x4;
	}
	return AnimationDataType::Unknown;
}

Expression* Matrix4x4Function::Call( ExpressionList* arguments )
{
	Float a[16] = {};
	for ( UInt i = 0; i < 16; ++i )
	{
		arguments->Get( i )->GetValue( &a[i]);
	}
	_value.Value = Matrix4x4( a );
	return &_value;
}


} // anim


} // synkro
