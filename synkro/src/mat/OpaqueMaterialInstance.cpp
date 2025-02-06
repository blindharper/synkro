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
// Purpose: Opaque material instance implementation.
//==============================================================================
#include "config.h"
#include "OpaqueMaterialInstance.h"
#include "OpaqueMaterial.h"
#include "SimpleMaterialAnimationController.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace mat
{


OpaqueMaterialInstance::OpaqueMaterialInstance( IContext* context, ITriangleMeshBatch* batch, IOpaqueMaterial* material, UInt index ) :
	_context( context ),
	_batch( batch ),
	_material( material ),
	_index( index ),
	_colorDiffuse( Color::Transparent )
{
}

IVisualMaterialAnimationController* OpaqueMaterialInstance::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new SimpleMaterialAnimationController( this, _context->GetAnimationSystem(), animation, listener) : _ctrlAnimation;
}

void OpaqueMaterialInstance::SetLightingModel( const LightingModel& model )
{
	_material->SetLightingModel( model );
}

void OpaqueMaterialInstance::SetDiffuseColor( const Color& color )
{
	if ( color != _colorDiffuse )
	{
		_batch->SetInstanceColor( _index, color );
		_colorDiffuse = color;
	}
}

void OpaqueMaterialInstance::SetAmbientColor( const Color& color )
{
	_material->SetAmbientColor( color );
}

void OpaqueMaterialInstance::SetEmissiveColor( const Color& color )
{
	_material->SetEmissiveColor( color );
}

void OpaqueMaterialInstance::SetSpecularColor( const Color& color )
{
	_material->SetSpecularColor( color );
}

void OpaqueMaterialInstance::SetSpecularPower( Float power )
{
	_material->SetSpecularPower( power );
}

void OpaqueMaterialInstance::SetTilingHorizontal( UInt tiling )
{
	_material->SetTilingHorizontal( tiling );
}

void OpaqueMaterialInstance::SetTilingVertical( UInt tiling )
{
	_material->SetTilingVertical( tiling );
}

LightingModel OpaqueMaterialInstance::GetLightingModel() const
{
	return _material->GetLightingModel();
}

void OpaqueMaterialInstance::GetDiffuseColor( Color& color ) const
{
	color = _colorDiffuse;
}

void OpaqueMaterialInstance::GetAmbientColor( Color& color ) const
{
	_material->GetAmbientColor( color );
}

void OpaqueMaterialInstance::GetEmissiveColor( Color& color ) const
{
	_material->GetEmissiveColor( color );
}

void OpaqueMaterialInstance::GetSpecularColor( Color& color ) const
{
	_material->GetSpecularColor( color );
}

Float OpaqueMaterialInstance::GetSpecularPower() const
{
	return _material->GetSpecularPower();
}

UInt OpaqueMaterialInstance::GetTilingHorizontal() const
{
	return _material->GetTilingHorizontal();
}

UInt OpaqueMaterialInstance::GetTilingVertical() const
{
	return _material->GetTilingVertical();
}

IMaterialMap* OpaqueMaterialInstance::GetDiffuseMap() const
{
	return _material->GetDiffuseMap();
}

IVisualMaterial* OpaqueMaterialInstance::CreateInstance( ITriangleMeshBatch* batch, UInt index )
{
	return dynamic_cast<OpaqueMaterial*>( _material )->CreateInstance( batch, index );
}

void OpaqueMaterialInstance::Assign( scene::ITriangleMesh* mesh, gfx::ISceneRenderObject* object, UInt index )
{
	return dynamic_cast<OpaqueMaterial*>( _material )->Assign( mesh, object, index );
}

void OpaqueMaterialInstance::SetIndex( UInt index )
{
	_index = index;
}

void OpaqueMaterialInstance::SetParam( const String& name, const String& value )
{
	dynamic_cast<OpaqueMaterial*>( _material )->SetParam( name, value );
}

void OpaqueMaterialInstance::OnDiffuseMapSet()
{
	dynamic_cast<OpaqueMaterial*>( _material )->OnDiffuseMapSet();
}

void OpaqueMaterialInstance::OnOpacityMapSet()
{
	// Do nothing.
}


} // mat


} // synkro
