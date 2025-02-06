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
// Purpose: Defines generic hash function.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_HASH_
#define _SYNKRO_INTERNAL_HASH_


#include "config.h"


// Hash function object.
// Uses 'Int T::HashCode()' for hashing
// if the key is not basic arithmetic type.
template <class T> class Hash
{
public:
	SYNKRO_INLINE synkro::UInt operator()( const T& x ) const
	{
		return x.HashCode();
	}
};

// Case-insensitive hash function object.
template <class T> class HashCI
{
public:
	SYNKRO_INLINE synkro::UInt operator()( const T& x ) const
	{
		return x.HashCode( true );
	}
};

// Hash specializations for basic types.
template <> class Hash<char> 
	{ public: synkro::UInt operator()( const char& x ) const {return x;} };

template <> class Hash<synkro::Char> 
	{ public: synkro::UInt operator()( const synkro::Char& x ) const {return x;} };

template <> class Hash<synkro::Byte> 
	{ public: synkro::UInt operator()( const synkro::Byte& x ) const {return x;} };

template <> class Hash<synkro::UShort> 
	{ public: synkro::UInt operator()( const synkro::UShort& x ) const {return x;} };

template <> class Hash<synkro::Int> 
	{ public: synkro::UInt operator()( const synkro::Int& x ) const {return x;} };

template <> class Hash<synkro::UInt> 
	{ public: synkro::UInt operator()( const synkro::UInt& x ) const {return x;} };

template <> class Hash<synkro::ULong> 
	{ public: synkro::UInt operator()( const synkro::ULong& x ) const {return x;} };

template <> class Hash<synkro::Float>
	{ public: synkro::UInt operator()( const synkro::Float& x ) const {return *(synkro::UInt*)&x;} };


#endif // _SYNKRO_INTERNAL_HASH_
