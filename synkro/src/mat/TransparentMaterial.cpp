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
// Purpose: Transparent material implementation.
//==============================================================================
#include "config.h"
#include "TransparentMaterial.h"
#include "TransparentMaterialInstance.h"
#include "TransparentMaterialAnimationController.h"
#include "DiffuseMap.h"
#include "OpacityMap.h"
#include "MaterialTriangleSet.h"
#include <scene/ITriangleMeshBatch.h>
#include <scene/ISkeleton.h>
#include <img/IImage.h>
#include <gfx/IFrameRenderWindowEx.h>
#include <gfx/IViewRenderWindowEx.h>
#include <gfx/ISceneRenderQueue.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace mat
{


TransparentMaterial::TransparentMaterial( IContext* context, const LightingModel& model ) :
	SimpleMaterialImpl<ITransparentMaterial>( context ),
	_opacityMap( new OpacityMap(this) ),
	_paramAmountDiffuse( nullptr ),
	_paramAmountOpacity( nullptr ),
	_opacity( 0.5f ),
	_colorSourceMode( BlendMode::One ),
	_alphaSourceMode( BlendMode::One ),
	_colorDestinationMode( BlendMode::Zero ),
	_alphaDestinationMode( BlendMode::Zero ),
	_colorOperation( BlendOperation::Add ),
	_alphaOperation( BlendOperation::Add )
{
	_diffuseMap = new DiffuseMap( this, nullptr );

	// Set lighting properties.
	SetLightingModel( model );
	SetDiffuseColor( Color::White );
	SetAmbientColor( Color::DarkGray );
	SetEmissiveColor( Color::Black );
	SetSpecularColor( Color::White );
	SetSpecularPower( 1.0f );
	SetTilingHorizontal( 1 );
	SetTilingVertical( 1 );
}

TransparentMaterial::TransparentMaterial( const TransparentMaterial& other ) :
	SimpleMaterialImpl<ITransparentMaterial>( other._context ),
	_opacityMap( new OpacityMap(this) ),
	_paramAmountDiffuse( nullptr ),
	_paramAmountOpacity( nullptr )
{
	_diffuseMap = new DiffuseMap( this, other.GetDiffuseMap()->GetImage() );

	// Set lighting properties.
	Color diffuse; other.GetDiffuseColor( diffuse );
	Color ambient; other.GetAmbientColor( ambient );
	Color emissive; other.GetEmissiveColor( emissive );
	Color specular; other.GetSpecularColor( specular );

	SetLightingModel( other.GetLightingModel() );
	SetDiffuseColor( diffuse );
	SetAmbientColor( ambient );
	SetEmissiveColor( emissive );
	SetSpecularColor( specular );
	SetSpecularPower( other.GetSpecularPower() );
	SetTilingHorizontal( other.GetTilingHorizontal() );
	SetTilingVertical( other.GetTilingVertical() );
}

IVisualMaterialAnimationController* TransparentMaterial::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new TransparentMaterialAnimationController( this, _context->GetAnimationSystem(), animation, listener) : _ctrlAnimation;
}

void TransparentMaterial::SetDiffuseColor( const Color& color )
{
	// Call base implementation.
	SimpleMaterialImpl<ITransparentMaterial>::SetDiffuseColor( color );

	UpdateVertexParameters();
}

void TransparentMaterial::SetAmbientColor( const img::Color& color )
{
	// Call base implementation.
	SimpleMaterialImpl<ITransparentMaterial>::SetAmbientColor( color );

	UpdateVertexParameters();
}

void TransparentMaterial::SetEmissiveColor( const img::Color& color )
{
	// Call base implementation.
	SimpleMaterialImpl<ITransparentMaterial>::SetEmissiveColor( color );

	UpdateVertexParameters();
}

void TransparentMaterial::SetSpecularColor( const img::Color& color )
{
	// Call base implementation.
	SimpleMaterialImpl<ITransparentMaterial>::SetSpecularColor( color );

	UpdateVertexParameters();
}

void TransparentMaterial::SetSpecularPower( Float power )
{
	// Call base implementation.
	SimpleMaterialImpl<ITransparentMaterial>::SetSpecularPower( power );

	UpdateVertexParameters();
}

void TransparentMaterial::SetTilingHorizontal( UInt tiling )
{
	// Call base implementation.
	SimpleMaterialImpl<ITransparentMaterial>::SetTilingHorizontal( tiling );

	if ( _paramTilingHorizontal != nullptr )
	{
		_fragmentParams->Set( _paramTilingHorizontal, CastFloat(_tilingHorizontal) );
		UpdateVertexParameters();
	}
}

void TransparentMaterial::SetTilingVertical( UInt tiling )
{
	// Call base implementation.
	SimpleMaterialImpl<ITransparentMaterial>::SetTilingVertical( tiling );

	if ( _paramTilingVertical != nullptr )
	{
		_fragmentParams->Set( _paramTilingVertical, CastFloat(_tilingVertical) );
		UpdateVertexParameters();
	}
}

void TransparentMaterial::SetOpacity( Float opacity )
{
	_opacity = Clamp( opacity, 0.0f, 1.0f );
	UpdateVertexParameters();
}

void TransparentMaterial::SetColorSourceMode( const BlendMode& mode )
{
	if ( mode != _colorSourceMode )
	{
		_blendStates->Get( 0 )->SetColorSrcMode( mode );
		_colorSourceMode = mode;
	}
}

void TransparentMaterial::SetAlphaSourceMode( const BlendMode& mode )
{
	if ( mode != _alphaSourceMode )
	{
		_blendStates->Get( 0 )->SetAlphaSrcMode( mode );
		_alphaSourceMode = mode;
	}
}

void TransparentMaterial::SetColorDestinationMode( const BlendMode& mode )
{
	if ( mode != _colorDestinationMode )
	{
		_blendStates->Get( 0 )->SetColorDstMode( mode );
		_colorDestinationMode = mode;
	}
}

void TransparentMaterial::SetAlphaDestinationMode( const BlendMode& mode )
{
	if ( mode != _alphaDestinationMode )
	{
		_blendStates->Get( 0 )->SetAlphaDstMode( mode );
		_alphaDestinationMode = mode;
	}
}

void TransparentMaterial::SetColorOperation( const BlendOperation& operation )
{
	if ( operation != _colorOperation )
	{
		_blendStates->Get( 0 )->SetColorOperation( operation );
		_colorOperation = operation;
	}
}

void TransparentMaterial::SetAlphaOperation( const BlendOperation& operation )
{
	if ( operation != _alphaOperation )
	{
		_blendStates->Get( 0 )->SetAlphaOperation( operation );
		_alphaOperation = operation;
	}
}

IVisualMaterial* TransparentMaterial::CreateInstance( ITriangleMeshBatch* batch, UInt index )
{
	return new TransparentMaterialInstance( _context, batch, this, index );
}

void TransparentMaterial::Assign( ITriangleMesh* mesh, ISceneRenderObject* object, UInt index )
{
	MaterialDesc* mat = FindMaterial( GetKey(mesh) );
	Assign( object, mat );
}

void TransparentMaterial::SetIndex( UInt index )
{
	// Do nothing.
}

void TransparentMaterial::SetParam( const String& name, const String& value )
{
		 if ( name.EqualsTo(L"ambient", true) )		SetAmbientColor( Color(value) );
	else if ( name.EqualsTo(L"diffuse", true) )		SetDiffuseColor( Color(value) );
	else if ( name.EqualsTo(L"emissive", true) )	SetEmissiveColor( Color(value) );
	else if ( name.EqualsTo(L"specular", true) )	SetSpecularColor( Color(value) );
	else if ( name.EqualsTo(L"power", true) )		SetSpecularPower( Convert::ToFloat(value) );
}

void TransparentMaterial::OnDiffuseMapSet()
{
	UInt idxRes = 0;
	if ( (this->GetDiffuseMap()->GetImage() != nullptr) && (_fragmentResources != nullptr) )
	{
		PixelFormat format = (_context->GetGraphicsSystem()->GetFrameWindowCount() > 0) ? _context->GetGraphicsSystem()->GetFrameWindow(0)->GetPixelFormat() : _context->GetGraphicsSystem()->GetViewWindow(0)->GetPixelFormat();
		IImage* map = this->GetDiffuseMap()->GetImage();
		map->Prepare( format, 0 );
		_fragmentResources->Set( idxRes, map->AsResource() );
	}
}

void TransparentMaterial::OnOpacityMapSet()
{
	UInt idxRes = 1;
	if ( (this->GetOpacityMap()->GetImage() != nullptr) && (_fragmentResources != nullptr) )
	{
		PixelFormat format = PixelFormat::R8G8B8A8;
		IImage* map = this->GetOpacityMap()->GetImage();
		map->Prepare( format, 0 );
		_fragmentResources->Set( idxRes, map->AsResource() );
		_fragmentSamplers->Get(idxRes)->SetFilter( TextureFilter::Anisotropic );
		_fragmentSamplers->Get(idxRes)->SetAddress( TextureAddress::Wrap );
	}

	EnableBlend( this->GetOpacityMap()->GetImage() != nullptr );
}

ITriangleSet* TransparentMaterial::CreateTriangleSet( const PrimitiveType& type, ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency )
{
	SynkroProfile( "TransparentMaterial.CreateTriangleSet" );

	const DataUsage usage = DataUsage::Dynamic;
	const DataAccess access = DataAccess::WriteOnly;
	MaterialDesc* mat = FindMaterial( GetKey(mesh) );
	ITriangleMeshBatch* batch = mesh->AsBatch();
	const UInt instanceCount = (batch != nullptr) ? batch->GetCapacity() : 0;
	gfx::IPrimitive* data = _context->GetGraphicsSystem()->GetDevice()->CreatePrimitive( mat->Program, usage, access, type, IndexType::Get(vertexCount), vertexCount, indexCount, instanceCount, 0, true, adjacency );
	ISceneRenderQueue* queue = mesh->GetScene()->GetRenderQueue();
	ISceneRenderObject* object = queue->CreateObject( data, false );
	Assign( object, mat );
	return new MaterialTriangleSet( object, 0, 0 );
}

void TransparentMaterial::Assign( ISceneRenderObject* object, MaterialDesc* mat )
{
	object->SetDepthStencilState( _depthStencilState );
	object->SetBlendStates( _blendStates );
	object->SetRasterizerState( _rasterizerState );
	object->SetVertexParameters( mat->VertexParams->Clone(object->ID(), false) );
	object->SetFragmentResources( mat->Textured ? _fragmentResources : nullptr );
	object->SetFragmentSamplers( mat->Textured ? _fragmentSamplers : nullptr );
	object->SetFragmentParameters( _fragmentParams );
}

void TransparentMaterial::CreateStates()
{
	if ( _depthStencilState == nullptr )
	{
		_depthStencilState = _context->GetGraphicsSystem()->GetDevice()->GetDepthStencilState()->Clone();
		_depthStencilState->EnableDepth( true );
		_depthStencilState->EnableDepthWrite( true );
		_depthStencilState->SetDepthFunction( CompareFunction::LessOrEqual );
	}

	if ( _rasterizerState == nullptr )
	{
		_rasterizerState = _context->GetGraphicsSystem()->GetDevice()->GetRasterizerState()->Clone();
		_rasterizerState->SetCullMode( CullMode::None );
		_rasterizerState->SetFillMode( FillMode::Solid );
		_rasterizerState->EnableMultisample( true );
	}

	if ( _blendStates == nullptr )
	{
		_blendStates = _context->GetGraphicsSystem()->GetDevice()->GetBlendStates()->Clone();
		_blendStates->Get( 0 )->Enable( false );
	}
}

void TransparentMaterial::UpdateVertexParameters()
{
	MapIterator<MaterialKey, MaterialDesc> it = _materials.Begin();
	MapIterator<MaterialKey, MaterialDesc> itEnd = _materials.End();
	for ( ; it != itEnd ; ++it )
	{
		MaterialDesc& mat = it.Value();
		if ( mat.ParamDiffuse != nullptr )
		{
			mat.VertexParams->Set( mat.ParamDiffuse, ToVector(_colorDiffuse, _opacity) );
			if ( mat.ParamAmbient != nullptr )
			{
				mat.VertexParams->Set( mat.ParamAmbient, ToVector(_colorAmbient, _opacity) );
				mat.VertexParams->Set( mat.ParamEmissive, ToVector(_colorEmissive, _opacity) );
				mat.VertexParams->Set( mat.ParamSpecular, ToVector(_colorSpecular, _opacity) );
				mat.VertexParams->Set( mat.ParamSpecularPower, _specularPower );
			}
			mat.VertexParams->Bind();
		}
	}

	// Blending only works when depth test is off.
	EnableBlend( _opacity != 1.0f );
}

void TransparentMaterial::EnableBlend( Bool enable )
{
	// Blending only works when depth test is off.
	CreateStates();
	_depthStencilState->EnableDepth( !enable );
	IBlendState* blendState = _blendStates->Get( 0 );
	blendState->SetColorSrcMode( _colorSourceMode );
	blendState->SetAlphaSrcMode( _alphaSourceMode );
	blendState->SetColorDstMode( _colorDestinationMode );
	blendState->SetAlphaDstMode( _alphaDestinationMode );
	blendState->SetColorOperation( _colorOperation );
	blendState->SetAlphaOperation( _alphaOperation );
	blendState->Enable( enable );
}

void TransparentMaterial::SetFragmentParameters( MaterialDesc* mat )
{
	if ( (_fragmentParams == nullptr) && mat->Textured )
	{
		_fragmentParams = mat->Program->GetFragmentStage()->GetParameters()->Clone( this->ID(), true );
		_paramAmountDiffuse = _fragmentParams->GetParam( L"sp_amountDiffuse" );
		_paramAmountOpacity = _fragmentParams->GetParam( L"sp_amountOpacity" );
		_paramTilingHorizontal = _fragmentParams->GetParam( L"sp_tilingHorizontal" );
		_paramTilingVertical = _fragmentParams->GetParam( L"sp_tilingVertical" );
	}
	if ( _paramAmountDiffuse != nullptr ) { _fragmentParams->Set( _paramAmountDiffuse, this->GetDiffuseMap()->GetAmount() ); }
	if ( _paramAmountOpacity != nullptr ) { _fragmentParams->Set( _paramAmountOpacity, this->GetOpacityMap()->GetAmount() ); }
	if ( _paramTilingHorizontal != nullptr ) { _fragmentParams->Set( _paramTilingHorizontal, CastFloat(_tilingHorizontal) ); }
	if ( _paramTilingVertical != nullptr ) { _fragmentParams->Set( _paramTilingVertical, CastFloat(_tilingVertical) ); }
}

void TransparentMaterial::SetFragmentResources( MaterialDesc* mat )
{
	if ( (_fragmentResources == nullptr) && (_fragmentSamplers == nullptr ) && mat->Textured )
	{
		_fragmentResources = mat->Program->GetFragmentStage()->GetResources()->Clone( this->ID() );
		_fragmentSamplers = mat->Program->GetFragmentStage()->GetSamplers()->Clone( this->ID() );
	}
	UInt idxRes = 0;
	if ( (this->GetDiffuseMap()->GetImage() != nullptr) && mat->Textured )
	{
		PixelFormat format = (_context->GetGraphicsSystem()->GetFrameWindowCount() > 0) ? _context->GetGraphicsSystem()->GetFrameWindow(0)->GetPixelFormat() : _context->GetGraphicsSystem()->GetViewWindow(0)->GetPixelFormat();
		IImage* map = this->GetDiffuseMap()->GetImage();
		map->Prepare( format, 0 );
		_fragmentResources->Set( idxRes, map->AsResource() );
		_fragmentSamplers->Get(idxRes)->SetFilter( TextureFilter::Anisotropic );
		_fragmentSamplers->Get(idxRes)->SetAddress( TextureAddress::Wrap );
		++idxRes;
	}
	if ( (this->GetOpacityMap()->GetImage() != nullptr) && mat->Textured )
	{
		PixelFormat format = PixelFormat::R8G8B8A8;
		IImage* map = this->GetOpacityMap()->GetImage();
		map->Prepare( format, 0 );
		_fragmentResources->Set( idxRes, map->AsResource() );
		_fragmentSamplers->Get(idxRes)->SetFilter( TextureFilter::Anisotropic );
		_fragmentSamplers->Get(idxRes)->SetAddress( TextureAddress::Wrap );
		++idxRes;
	}
}

void TransparentMaterial::SetVertexParameters( MaterialDesc* mat )
{
	if ( mat->VertexParams == nullptr )
	{
		mat->VertexParams = mat->Program->GetVertexStage()->GetParameters()->Clone( this->ID(), true );
		mat->ParamDiffuse = mat->VertexParams->GetParam( L"sp_diffuse" );
		mat->ParamAmbient = mat->VertexParams->GetParam( L"sp_ambient" );
		mat->ParamSpecular = mat->VertexParams->GetParam( L"sp_specular" );
		mat->ParamEmissive = mat->VertexParams->GetParam( L"sp_emissive" );
		mat->ParamSpecularPower = mat->VertexParams->GetParam( L"sp_power" );
	}
	if ( mat->ParamAmbient != nullptr )
	{
		mat->VertexParams->Set( mat->ParamDiffuse, ToVector(_colorDiffuse) );
		mat->VertexParams->Set( mat->ParamAmbient, ToVector(_colorAmbient) );
		mat->VertexParams->Set( mat->ParamSpecular, ToVector(_colorSpecular) );
		mat->VertexParams->Set( mat->ParamEmissive, ToVector(_colorEmissive) );
		mat->VertexParams->Set( mat->ParamSpecularPower, _specularPower );
		mat->VertexParams->Bind();
	}
	else if ( !mat->Instanced )
	{
		mat->ParamDiffuse = mat->VertexParams->GetParam( L"sp_color" );
		mat->VertexParams->Set( mat->ParamDiffuse, ToVector(_colorDiffuse, _opacity) );
		mat->VertexParams->Bind();
	}
}

MaterialKey TransparentMaterial::GetKey( ITriangleMesh* mesh )
{
	const Bool diffuse = (_diffuseMap->GetImage() != nullptr);
	const Bool opacity = (_opacityMap->GetImage() != nullptr);
	const Bool instanced = (mesh->AsBatch() != nullptr);
	const Bool skinned = (mesh->GetSkeleton() != nullptr) && (mesh->GetSkeleton()->GetBoneCount() > 0);
	return MaterialKey( mesh->GetScene()->IsLit() ? _lightingModel : LightingModel::Unknown, diffuse, opacity, skinned, instanced, 0 );
}

MaterialDesc* TransparentMaterial::FindMaterial( const MaterialKey& key )
{
	SynkroProfile( "TransparentMaterial.FindMaterial" );

	MaterialDesc* mat = nullptr;

	const Bool lit = (key.Model != LightingModel::Unknown);
	const Bool textured = key.DiffuseMap;
	const Bool colored = false;
	const Bool skinned = key.Skinned;
	const Bool instanced = key.Instanced;

	// Generate program name.
	String name( L"material.transparent" );
	if ( lit )								name = name.Append( String::Format(L".lit[{0}]", _lightingModel.ToString().ToLower()) );
	if ( textured )							name = name.Append( L".textured" );
	if ( colored && !lit && !instanced )	name = name.Append( L".colored" );
	if ( skinned )							name = name.Append( L".skinned" );
	if ( instanced )						name = name.Append( L".instanced" );

	// Find matching material implementation.
	if ( !_materials.ContainsKey(key) )
	{
		_materials[key] = MaterialDesc();
		_materials[key].Program = _context->GetGraphicsSystem()->GetProgram( name );
		assert( _materials[key].Program != nullptr );
	}
	mat = &_materials[key];
	mat->Textured = (key.DiffuseMap || key.OpacityMap);
	mat->Instanced = key.Instanced;

	// Setup states, parameters and resources.
	CreateStates();
	SetFragmentParameters( mat );
	SetFragmentResources( mat );
	SetVertexParameters( mat );

	return mat;
}


} // mat


} // synkro
