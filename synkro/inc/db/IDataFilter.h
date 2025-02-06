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
// Purpose: Defines data filter.
//==============================================================================
#ifndef _SYNKRO_DB_IDATAFILTER_
#define _SYNKRO_DB_IDATAFILTER_


#include "config.h"
#include <core/IObject.h>
#include <lang/Variant.h>
#include <db/ComparisonType.h>
#include <db/CombinationType.h>


namespace synkro
{


namespace db
{


/**
 * Database records filter.
 */
iface IDataFilter :
	public core::IObject
{
public:
	/**
	 * Retrieves table column name.
	 */
	virtual lang::String									GetColumn() const = 0;

	/**
	 * Retrieves reference value.
	 */
	virtual lang::Variant									GetReference() const = 0;

	/**
	 * Retrieves cell value comparison type.
	 */
	virtual ComparisonType									GetComparisonType() const = 0;

	/**
	 * Retrieves combination type for complex filters.
	 */
	virtual CombinationType									GetCombinationType() const = 0;

	/**
	 * Retrieves first sub-filter of a complex filter.
	 */
	virtual IDataFilter*									GetFirstFilter() const = 0;

	/**
	 * Retrieves second sub-filter of a complex filter.
	 */
	virtual IDataFilter*									GetSecondFilter() const = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_IDATAFILTER_
