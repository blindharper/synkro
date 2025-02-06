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
// Purpose: Implements logical INSERT query.
//==============================================================================
SYNKRO_INLINE void InsertQuery::Execute()
{
	_query->Execute();
}

SYNKRO_INLINE void InsertQuery::Reset()
{
	_query->Reset();
}

SYNKRO_INLINE void InsertQuery::SetValue( const lang::String& column, const lang::Variant& value )
{
	ValidateColumn( column );
	_query->SetValue( column, value );
}

SYNKRO_INLINE UInt InsertQuery::GetRowID() const
{
	return _query->GetRowID();
}
