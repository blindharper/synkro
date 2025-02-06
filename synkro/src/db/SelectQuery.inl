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
// Purpose: Implements logical SELECT query.
//==============================================================================
SYNKRO_INLINE void SelectQuery::Execute()
{
	_cursor = nullptr;
	_query->Execute();
}

SYNKRO_INLINE void SelectQuery::Reset()
{
	_query->Reset();
}

SYNKRO_INLINE void SelectQuery::SelectAll()
{
	_query->SelectAll();
}

SYNKRO_INLINE void SelectQuery::SelectCount()
{
	_query->SelectCount();
}

SYNKRO_INLINE void SelectQuery::SelectUnique( Bool unique )
{
	_query->SelectUnique( unique );
}

SYNKRO_INLINE void SelectQuery::Select( const lang::String& column )
{
	ValidateColumn( column );
	_query->Select( column );
}

SYNKRO_INLINE void SelectQuery::Sort( const lang::String& column, const SortOrder& order )
{
	ValidateColumn( column );
	_query->Sort( column, order );
}

SYNKRO_INLINE void SelectQuery::SetFilter( IDataFilter* filter )
{
	ValidateFilter( filter );
	_query->SetFilter( filter );
}

SYNKRO_INLINE IDataFilter* SelectQuery::GetFilter() const
{
	return _query->GetFilter();
}
