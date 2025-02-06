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
// Purpose: Simple viewport filter implementation.
//==============================================================================
SYNKRO_INLINE void SimpleFilter::SetValue( Float value )
{
	_params->Set( _paramValue, value );
}

SYNKRO_INLINE Float SimpleFilter::GetValue() const
{
	Float value;
	_params->Get( _paramValue, &value );
	return value;
}

SYNKRO_INLINE ISimpleFilter* SimpleFilter::AsSimple() const
{
	return (ISimpleFilter*)this;
}
