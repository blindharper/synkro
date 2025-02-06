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
// Purpose: Overlay font implementation.
//==============================================================================
SYNKRO_INLINE lang::String FontEx::GetFamily() const
{
	return _family;
}

SYNKRO_INLINE UInt FontEx::GetSize() const
{
	return _size;
}

SYNKRO_INLINE FontStyle FontEx::GetStyle() const
{
	return _style;
}

SYNKRO_INLINE core::Language FontEx::GetLanguage() const
{
	return _language;
}

SYNKRO_INLINE Bool FontEx::Call( BaseText* text )
{
	text->Update();
	return true;
}
