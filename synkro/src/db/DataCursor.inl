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
// Purpose: Implements logical data cursor.
//==============================================================================
SYNKRO_INLINE Bool DataCursor::Read()
{
	return _cursor->Read();
}

SYNKRO_INLINE lang::Variant DataCursor::GetValue( const lang::String& column ) const
{
	return _cursor->GetValue( column );
}
