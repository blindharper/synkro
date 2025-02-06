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
// Purpose: Implements logical UPDATE query.
//==============================================================================
SYNKRO_INLINE void UpdateQuery::Execute()
{
	_query->Execute();
}

SYNKRO_INLINE void UpdateQuery::Reset()
{
	_query->Reset();
}

SYNKRO_INLINE void UpdateQuery::SetValue( const lang::String& column, const lang::Variant& value )
{
	ValidateColumn( column );
	_query->SetValue( column, value );
}

SYNKRO_INLINE void UpdateQuery::SetFilter( IDataFilter* filter )
{
	ValidateFilter( filter );
	_query->SetFilter( filter );
}

SYNKRO_INLINE IDataFilter* UpdateQuery::GetFilter() const
{
	return _query->GetFilter();
}
