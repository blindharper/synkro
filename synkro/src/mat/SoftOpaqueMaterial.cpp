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
// Purpose: Opaque software material implementation.
//==============================================================================
#include "config.h"
#include "SoftOpaqueMaterial.h"
#include "DiffuseMap.h"
#include "OpacityMap.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace mat
{


SoftOpaqueMaterial::SoftOpaqueMaterial() :
	SimpleMaterialImpl<IOpaqueMaterial>( nullptr ),
	_twoSided( false ),
	_wireframe( false )
{
	_diffuseMap = new DiffuseMap( this, nullptr );

	SetDiffuseColor( Color::White );
	SetAmbientColor( Color::DarkGray );
	SetEmissiveColor( Color::Black );
	SetSpecularColor( Color::White );
	SetSpecularPower( 1.0f );
}

SoftOpaqueMaterial::SoftOpaqueMaterial( const SoftOpaqueMaterial& other ) :
	SimpleMaterialImpl<IOpaqueMaterial>( nullptr ),
	_twoSided( other._twoSided ),
	_wireframe( other._wireframe )
{
	_diffuseMap = new DiffuseMap( this, other.GetDiffuseMap()->GetImage() );

	// Set lighting properties.
	Color diffuse; other.GetDiffuseColor( diffuse );
	Color ambient; other.GetAmbientColor( ambient );
	Color emissive; other.GetEmissiveColor( emissive );
	Color specular; other.GetSpecularColor( specular );

	SetDiffuseColor( diffuse );
	SetAmbientColor( ambient );
	SetEmissiveColor( emissive );
	SetSpecularColor( specular );
	SetSpecularPower( other.GetSpecularPower() );
}

IVisualMaterialAnimationController* SoftOpaqueMaterial::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return nullptr;
}

IOpaqueMaterial* SoftOpaqueMaterial::AsOpaque() const
{
	return (IOpaqueMaterial*)this;
}

void SoftOpaqueMaterial::SetTwoSided( Bool twoSided )
{
	_twoSided = twoSided;
}

void SoftOpaqueMaterial::SetWireframe( Bool wireframe )
{
	_wireframe = wireframe;
}

Bool SoftOpaqueMaterial::IsTwoSided() const
{
	return _twoSided;
}

Bool SoftOpaqueMaterial::IsWireframe() const
{
	return _wireframe;
}

IOpaqueMaterial* SoftOpaqueMaterial::Clone() const
{
	return new SoftOpaqueMaterial( *this );
}

IVisualMaterial* SoftOpaqueMaterial::CreateInstance( ITriangleMeshBatch* batch, UInt index )
{
	return nullptr;
}

void SoftOpaqueMaterial::Assign( ITriangleMesh* mesh, ISceneRenderObject* object, UInt index )
{
}

void SoftOpaqueMaterial::SetIndex( UInt index )
{
}

void SoftOpaqueMaterial::SetParam( const String& name, const String& value )
{
}

void SoftOpaqueMaterial::OnDiffuseMapSet()
{
}

void SoftOpaqueMaterial::OnOpacityMapSet()
{
}

ITriangleSet* SoftOpaqueMaterial::CreateTriangleSet( const PrimitiveType& type, ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency )
{
	return nullptr;
}


} // mat


} // synkro
