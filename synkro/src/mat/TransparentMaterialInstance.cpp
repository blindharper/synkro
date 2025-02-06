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
// Purpose: Transparent material instance implementation.
//==============================================================================
#include "config.h"
#include "TransparentMaterialInstance.h"
#include "TransparentMaterial.h"
#include "TransparentMaterialAnimationController.h"


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


TransparentMaterialInstance::TransparentMaterialInstance( IContext* context, ITriangleMeshBatch* batch, ITransparentMaterial* material, UInt index ) :
	_context( context ),
	_batch( batch ),
	_material( material ),
	_index( index ),
	_colorDiffuse( Color::Transparent )
{
}

IVisualMaterialAnimationController* TransparentMaterialInstance::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new TransparentMaterialAnimationController( this, _context->GetAnimationSystem(), animation, listener) : _ctrlAnimation;
}

void TransparentMaterialInstance::SetLightingModel( const LightingModel& model )
{
	_material->SetLightingModel( model );
}

void TransparentMaterialInstance::SetDiffuseColor( const Color& color )
{
	if ( color != _colorDiffuse )
	{
		_batch->SetInstanceColor( _index, color );
		_colorDiffuse = color;
	}
}

void TransparentMaterialInstance::SetAmbientColor( const Color& color )
{
	_material->SetAmbientColor( color );
}

void TransparentMaterialInstance::SetEmissiveColor( const Color& color )
{
	_material->SetEmissiveColor( color );
}

void TransparentMaterialInstance::SetSpecularColor( const Color& color )
{
	_material->SetSpecularColor( color );
}

void TransparentMaterialInstance::SetSpecularPower( Float power )
{
	_material->SetSpecularPower( power );
}

void TransparentMaterialInstance::SetTilingHorizontal( UInt tiling )
{
	_material->SetTilingHorizontal( tiling );
}

void TransparentMaterialInstance::SetTilingVertical( UInt tiling )
{
	_material->SetTilingVertical( tiling );
}

LightingModel TransparentMaterialInstance::GetLightingModel() const
{
	return _material->GetLightingModel();
}

void TransparentMaterialInstance::GetDiffuseColor( Color& color ) const
{
	color = _colorDiffuse;
}

void TransparentMaterialInstance::GetAmbientColor( Color& color ) const
{
	_material->GetAmbientColor( color );
}

void TransparentMaterialInstance::GetEmissiveColor( Color& color ) const
{
	_material->GetEmissiveColor( color );
}

void TransparentMaterialInstance::GetSpecularColor( Color& color ) const
{
	_material->GetSpecularColor( color );
}

Float TransparentMaterialInstance::GetSpecularPower() const
{
	return _material->GetSpecularPower();
}

UInt TransparentMaterialInstance::GetTilingHorizontal() const
{
	return _material->GetTilingHorizontal();
}

UInt TransparentMaterialInstance::GetTilingVertical() const
{
	return _material->GetTilingVertical();
}

IVisualMaterial* TransparentMaterialInstance::CreateInstance( ITriangleMeshBatch* batch, UInt index )
{
	return dynamic_cast<TransparentMaterial*>( _material )->CreateInstance( batch, index );
}

void TransparentMaterialInstance::Assign( scene::ITriangleMesh* mesh, gfx::ISceneRenderObject* object, UInt index )
{
	return dynamic_cast<TransparentMaterial*>( _material )->Assign( mesh, object, index );
}

void TransparentMaterialInstance::SetIndex( UInt index )
{
	_index = index;
}

void TransparentMaterialInstance::SetParam( const String& name, const String& value )
{
	dynamic_cast<TransparentMaterial*>( _material )->SetParam( name, value );
}

void TransparentMaterialInstance::OnDiffuseMapSet()
{
	dynamic_cast<TransparentMaterial*>( _material )->OnDiffuseMapSet();
}

void TransparentMaterialInstance::OnOpacityMapSet()
{
	dynamic_cast<TransparentMaterial*>( _material )->OnOpacityMapSet();
}


} // mat


} // synkro
