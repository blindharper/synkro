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
// Purpose: Defines extended database system.
//==============================================================================
#ifndef _SYNKRO_DB_IDATABASESYSTEMEX_
#define _SYNKRO_DB_IDATABASESYSTEMEX_


#include "config.h"
#include <db/IDatabaseSystem.h>
#include <db/ComparisonType.h>
#include <db/CombinationType.h>
#include <lang/Variant.h>


namespace synkro
{


namespace db
{


/**
 * Extended database system.
 */
iface IDatabaseSystemEx :
	public IDatabaseSystem
{
public:
	/**
	 * Creates data filter.
	 * @param column Database table column name.
	 * @param comparison cell-to-value comparison function.
	 * @param reference Value with which to compare database table cell value.
	 * @return Created data filter.
	 */
	virtual IDataFilter*									CreateFilter( const lang::String& column, const ComparisonType& comparison, const lang::Variant& reference ) = 0;

	/**
	 * Creates a combination of two data filter.
	 * @param first First data filter.
	 * @param combination Filter combination operator.
	 * @param second Second data filter.
	 * @return Created data filter.
	 */
	virtual IDataFilter*									CreateFilter( IDataFilter* first, const CombinationType& combination, IDataFilter* second ) = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_IDATABASESYSTEMEX_
