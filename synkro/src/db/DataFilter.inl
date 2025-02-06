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
// Purpose: Implements database records filter.
//==============================================================================
SYNKRO_INLINE lang::String DataFilter::GetColumn() const
{
	return _column;
}

SYNKRO_INLINE lang::Variant DataFilter::GetReference() const
{
	return _reference;
}

SYNKRO_INLINE ComparisonType DataFilter::GetComparisonType() const
{
	return _comparison;
}

SYNKRO_INLINE CombinationType DataFilter::GetCombinationType() const
{
	return _combination;
}

SYNKRO_INLINE IDataFilter* DataFilter::GetFirstFilter() const
{
	return _first;
}

SYNKRO_INLINE IDataFilter* DataFilter::GetSecondFilter() const
{
	return _second;
}
