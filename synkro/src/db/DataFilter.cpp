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
#include "config.h"
#include "DataFilter.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


DataFilter::DataFilter( const String& column, const ComparisonType& comparison, const Variant& reference ) :
	_column( column ),
	_comparison( comparison ),
	_reference( reference )
{
}

DataFilter::DataFilter( IDataFilter* first, const CombinationType& combination, IDataFilter* second ) :
	_reference( Variant::Null ),
	_combination( combination ),
	_first( first ),
	_second( second )
{
}


} // db


} // synkro
