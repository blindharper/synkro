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
// Purpose: Implements named variant data type.
//==============================================================================
#include "config.h"
#include <lang/VariantEx.h>


//------------------------------------------------------------------------------

using namespace synkro::io;

//------------------------------------------------------------------------------


namespace synkro
{


namespace lang
{


VariantEx::VariantEx( const String& name, Int value ) :
	Name( name ),
	Value( Variant(value) )
{
}

VariantEx::VariantEx( const String& name, UInt value ) :
	Name( name ),
	Value( Variant((Int)value) )
{
}

VariantEx::VariantEx( const String& name, Float value ) :
	Name( name ),
	Value( Variant(value) )
{
}

VariantEx::VariantEx( const String& name, const String& value ) :
	Name( name ),
	Value( Variant(value) )
{
}

VariantEx::VariantEx( const String& name, const Char* value ) :
	Name( name ),
	Value( Variant(value) )
{
}

VariantEx::VariantEx( const String& name, const DateTime& value ) :
	Name( name ),
	Value( Variant(value) )
{
}

VariantEx::VariantEx( const String& name, IStream* value ) :
	Name( name ),
	Value( Variant(value) )
{
}

VariantEx::VariantEx( const String& name, const Byte* value, UInt size ) :
	Name( name ),
	Value( Variant(value, size) )
{
}

VariantEx::VariantEx( const String& name ) :
	Name( name ),
	Value( Variant::Null )
{
}

VariantEx::VariantEx() :
	Value( Variant::Null )
{
}


} // lang


} // synkro
