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
#ifndef _SYNKRO_DB_DATAFILTER_
#define _SYNKRO_DB_DATAFILTER_


#include "config.h"
#include <core/ObjectImpl.h>
#include <db/IDataFilter.h>
#include <db/CombinationType.h>
#include <db/ComparisonType.h>


namespace synkro
{


namespace db
{


// Database records filter implementation.
class DataFilter :
	public core::ObjectImpl<IDataFilter>
{
public:
	// Constructors.
	DataFilter( const lang::String& column, const ComparisonType& comparison, const lang::Variant& reference );
	DataFilter( IDataFilter* first, const CombinationType& combination, IDataFilter* second );

	// IDataFilter methods.
	lang::String											GetColumn() const;
	lang::Variant											GetReference() const;
	ComparisonType											GetComparisonType() const;
	CombinationType											GetCombinationType() const;
	IDataFilter*											GetFirstFilter() const;
	IDataFilter*											GetSecondFilter() const;

protected:
	lang::String											_column;
	lang::Variant											_reference;
	ComparisonType											_comparison;
	CombinationType											_combination;
	P(IDataFilter)											_first;
	P(IDataFilter)											_second;
};


#include "DataFilter.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_DATAFILTER_
