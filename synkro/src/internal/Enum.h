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
// Purpose: Enumeration constant macro.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_ENUM_
#define _SYNKRO_INTERNAL_ENUM_


#include <internal/SizeOf.h>


// Defines enumeration constant.
#define SYNKRO_DEFINE_CONST( NAME, CONST, VALUE )	\
	const NAME NAME::CONST( VALUE );

// Converts string to enumeration value.
#define SET_ENUM_VALUE( TYPE )						\
	for ( UInt i = 0; i < _count; ++i )			\
	{												\
		const TypeDesc& desc = _desc[i];			\
		if ( TYPE.EqualsTo(desc.name, true) )		\
		{											\
			_value = desc.type;						\
			break;									\
		}											\
	}

// Tests if the given string represents a valid enumeration value.
#define IS_VALID_ENUM( NAME )						\
	for ( UInt i = 0; i < _count; ++i )			\
	{												\
		const TypeDesc& desc = _desc[i];			\
		UInt len = CastUInt(wcslen(desc.name));		\
		if ( (name.Length() > len) && (name[name.Length()-len-1] == L'.') && name.EndsWith(desc.name, true) )	\
			return true;							\
	}												\
	return false;

// Converts enumeration value to string.
#define ENUM_TO_STRING()							\
		UInt i = Value();							\
		return (i < _count) ? _desc[i].name : lang::String::Empty;

// Converts string to flag value.
#define SET_FLAG_VALUE( TYPE )						\
	UInt count = TYPE.EntryCount( L'|' );			\
	for ( UInt f = 0; f < count; ++f )				\
	{												\
		lang::String s = TYPE.Entry( f, L'|' );		\
		for ( UInt i = 0; i < _count; ++i )		\
		{											\
			const TypeDesc& desc = _desc[i];		\
			if ( s.EqualsTo(desc.name, true) )		\
			{										\
				_value |= desc.type;				\
				break;								\
			}										\
		}											\
	}

// Converts flag value to string.
#define FLAG_TO_STRING( TYPE )						\
	static UInt cnt = SizeOf( flags );				\
	lang::String str;								\
	lang::String d( L"|" );							\
	for ( UInt i = 0; i < cnt; ++i )				\
	{												\
		const TYPE& flag = flags[i];				\
		if ( this->IsSet(flag) )					\
		{											\
			lang::String s = _desc[flag].name;		\
			str = str.IsEmpty() ? s : str+d+s;		\
		}											\
	}												\
	return str;


#endif // _SYNKRO_INTERNAL_ENUM_
