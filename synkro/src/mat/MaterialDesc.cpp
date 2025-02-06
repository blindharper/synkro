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
// Purpose: Material description.
//==============================================================================
#include "config.h"
#include "MaterialDesc.h"


namespace synkro
{


namespace mat
{


MaterialKey::MaterialKey( const LightingModel& model, Bool diffuseMap, Bool opacityMap, Bool skinned, Bool instanced, UInt instanceCount ) :
	Model( model ),
	DiffuseMap( diffuseMap ),
	OpacityMap( opacityMap ),
	Skinned( skinned ),
	Instanced( instanced ),
	InstanceCount( instanceCount )
{
	lang::String key = lang::String::Format( L"{0}|{1}|{2}|{3}|{4}", CastUInt(model), diffuseMap, opacityMap, skinned, instanced );
	_hash = key.HashCode( true );
}

MaterialKey::MaterialKey() :
	_hash( 0 )
{
}

Bool MaterialKey::operator==( const MaterialKey& other ) const
{
	return _hash == other._hash;
}

Int MaterialKey::HashCode() const
{
	return _hash;
}


MaterialDesc::MaterialDesc() :
	Textured( false ),
	Skinned( false ),
	Instanced( false ),
	InstanceCount( 0 ),
	Program( nullptr ),
	ParamDiffuse( nullptr ),
	ParamAmbient( nullptr ),
	ParamEmissive( nullptr ),
	ParamSpecular( nullptr ),
	ParamSpecularPower( nullptr ),
	VertexParams( nullptr )
{
}


} // mat


} // synkro
