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
// Purpose: Opaque material implementation.
//==============================================================================
#include "config.h"
#include "OpaqueMaterial.h"
#include "OpaqueMaterialInstance.h"
#include "SimpleMaterialAnimationController.h"
#include "DiffuseMap.h"
#include "OpacityMap.h"
#include "MaterialTriangleSet.h"
#include <scene/ITriangleMeshBatch.h>
#include <scene/ISkeleton.h>
#include <img/IImage.h>
#include <gfx/IFrameRenderWindowEx.h>
#include <gfx/IViewRenderWindowEx.h>
#include <gfx/ISceneRenderQueue.h>
#include <gfx/ITypedBuffer.h>


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


OpaqueMaterial::OpaqueMaterial( IContext* context, const LightingModel& model ) :
	SimpleMaterialImpl<IOpaqueMaterial>( context ),
	_twoSided( false ),
	_wireframe( false ),
	_paramAmountDiffuse( nullptr )
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

OpaqueMaterial::OpaqueMaterial( const OpaqueMaterial& other ) :
	SimpleMaterialImpl<IOpaqueMaterial>( other._context ),
	_twoSided( other._twoSided ),
	_wireframe( other._wireframe ),
	_paramAmountDiffuse( nullptr )
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

IVisualMaterialAnimationController* OpaqueMaterial::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new SimpleMaterialAnimationController( this, _context->GetAnimationSystem(), animation, listener) : _ctrlAnimation;
}

void OpaqueMaterial::SetDiffuseColor( const Color& color )
{
	// Call base implementation.
	SimpleMaterialImpl<IOpaqueMaterial>::SetDiffuseColor( color );

	UpdateVertexParameters();
}

void OpaqueMaterial::SetAmbientColor( const Color& color )
{
	// Call base implementation.
	SimpleMaterialImpl<IOpaqueMaterial>::SetAmbientColor( color );

	UpdateVertexParameters();
}

void OpaqueMaterial::SetEmissiveColor( const Color& color )
{
	// Call base implementation.
	SimpleMaterialImpl<IOpaqueMaterial>::SetEmissiveColor( color );

	UpdateVertexParameters();
}

void OpaqueMaterial::SetSpecularColor( const Color& color )
{
	// Call base implementation.
	SimpleMaterialImpl<IOpaqueMaterial>::SetSpecularColor( color );

	UpdateVertexParameters();
}

void OpaqueMaterial::SetSpecularPower( Float power )
{
	// Call base implementation.
	SimpleMaterialImpl<IOpaqueMaterial>::SetSpecularPower( power );

	UpdateVertexParameters();
}

void OpaqueMaterial::SetTilingHorizontal( UInt tiling )
{
	// Call base implementation.
	SimpleMaterialImpl<IOpaqueMaterial>::SetTilingHorizontal( tiling );

	if ( _paramTilingHorizontal != nullptr )
	{
		_fragmentParams->Set( _paramTilingHorizontal, CastFloat(_tilingHorizontal) );
		UpdateVertexParameters();
	}
}

void OpaqueMaterial::SetTilingVertical( UInt tiling )
{
	// Call base implementation.
	SimpleMaterialImpl<IOpaqueMaterial>::SetTilingVertical( tiling );

	if ( _paramTilingVertical != nullptr )
	{
		_fragmentParams->Set( _paramTilingVertical, CastFloat(_tilingVertical) );
		UpdateVertexParameters();
	}
}

IVisualMaterial* OpaqueMaterial::CreateInstance( ITriangleMeshBatch* batch, UInt index )
{
	return new OpaqueMaterialInstance( _context, batch, this, index );
}

void OpaqueMaterial::Assign( ITriangleMesh* mesh, ISceneRenderObject* object, UInt index )
{
	MaterialDesc* mat = FindMaterial( GetKey(mesh) );
	Assign( object, mat );
}

void OpaqueMaterial::SetIndex( UInt index )
{
	// Do nothing.
}

void OpaqueMaterial::SetParam( const String& name, const String& value )
{
		 if ( name.EqualsTo(L"twosided", true) )	SetTwoSided( Convert::ToBool(value) );
	else if ( name.EqualsTo(L"wireframe", true) )	SetWireframe( Convert::ToBool(value) );
	else if ( name.EqualsTo(L"ambient", true) )		SetAmbientColor( Color(value) );
	else if ( name.EqualsTo(L"diffuse", true) )		SetDiffuseColor( Color(value) );
	else if ( name.EqualsTo(L"emissive", true) )	SetEmissiveColor( Color(value) );
	else if ( name.EqualsTo(L"specular", true) )	SetSpecularColor( Color(value) );
	else if ( name.EqualsTo(L"power", true) )		SetSpecularPower( Convert::ToFloat(value) );
}

void OpaqueMaterial::OnDiffuseMapSet()
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

void OpaqueMaterial::OnOpacityMapSet()
{
	// Do nothing.
}

ITriangleSet* OpaqueMaterial::CreateTriangleSet( const PrimitiveType& type, ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency )
{
	SynkroProfile( "OpaqueMaterial.CreateTriangleSet" );

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

void OpaqueMaterial::Assign( ISceneRenderObject* object, MaterialDesc* mat )
{
	object->SetDepthStencilState( _depthStencilState );
	object->SetBlendStates( _blendStates );
	object->SetRasterizerState( _rasterizerState );
	object->SetVertexResources( _vertexResources );
	object->SetVertexParameters( mat->VertexParams->Clone(object->ID(), false) );
	object->SetFragmentResources( mat->Textured ? _fragmentResources : nullptr );
	object->SetFragmentSamplers( mat->Textured ? _fragmentSamplers : nullptr );
	object->SetFragmentParameters( _fragmentParams );
}

void OpaqueMaterial::CreateStates()
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
		_rasterizerState->SetCullMode( _twoSided ? CullMode::None : CullMode::Back );
		_rasterizerState->SetFillMode( _wireframe ? FillMode::Wireframe : FillMode::Solid );
		_rasterizerState->EnableMultisample( true );
	}

	if ( _blendStates == nullptr )
	{
		_blendStates = _context->GetGraphicsSystem()->GetDevice()->GetBlendStates()->Clone();
		_blendStates->Get( 0 )->Enable( false );
	}
}

void OpaqueMaterial::UpdateVertexParameters()
{
	MapIterator<MaterialKey, MaterialDesc> it = _materials.Begin();
	MapIterator<MaterialKey, MaterialDesc> itEnd = _materials.End();
	for ( ; it != itEnd ; ++it )
	{
		MaterialDesc& mat = it.Value();
		if ( mat.ParamDiffuse != nullptr )
		{
			mat.VertexParams->Set( mat.ParamDiffuse, ToVector(_colorDiffuse) );
			if ( mat.ParamAmbient != nullptr )
			{
				mat.VertexParams->Set( mat.ParamAmbient, ToVector(_colorAmbient) );
				mat.VertexParams->Set( mat.ParamEmissive, ToVector(_colorEmissive) );
				mat.VertexParams->Set( mat.ParamSpecular, ToVector(_colorSpecular) );
				mat.VertexParams->Set( mat.ParamSpecularPower, _specularPower );
			}
			mat.VertexParams->Bind();
		}
	}

	// Blending only works when depth test is off.
	CreateStates();
}

void OpaqueMaterial::SetVertexParameters( MaterialDesc* mat )
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
		mat->VertexParams->Set( mat->ParamDiffuse, ToVector(_colorDiffuse) );
		mat->VertexParams->Bind();
	}
}

void OpaqueMaterial::SetVertexResources( MaterialDesc* mat )
{
	if ( (_vertexResources == nullptr) && mat->Skinned && mat->Instanced )
	{
		constexpr UInt MAX_BONE_COUNT = 50;
		ITypedBuffer* bufferBoneTransforms = _context->GetGraphicsSystem()->GetDevice()->CreateTypedBuffer( DataUsage::Dynamic, ProgramDataType::Matrix4x4, mat->InstanceCount*MAX_BONE_COUNT );
		_vertexResources = mat->Program->GetVertexStage()->GetResources()->Clone( this->ID() );
		_vertexResources->Set( 0, bufferBoneTransforms );
	}
}

void OpaqueMaterial::SetFragmentParameters( MaterialDesc* mat )
{
	if ( (_fragmentParams == nullptr) && mat->Textured )
	{
		_fragmentParams = mat->Program->GetFragmentStage()->GetParameters()->Clone( this->ID(), true );
		_paramAmountDiffuse = _fragmentParams->GetParam( L"sp_amountDiffuse" );
		_paramTilingHorizontal = _fragmentParams->GetParam( L"sp_tilingHorizontal" );
		_paramTilingVertical = _fragmentParams->GetParam( L"sp_tilingVertical" );
	}
	if ( _paramAmountDiffuse != nullptr ) { _fragmentParams->Set( _paramAmountDiffuse, this->GetDiffuseMap()->GetAmount() ); }
	if ( _paramTilingHorizontal != nullptr ) { _fragmentParams->Set( _paramTilingHorizontal, CastFloat(_tilingHorizontal) ); }
	if ( _paramTilingVertical != nullptr ) { _fragmentParams->Set( _paramTilingVertical, CastFloat(_tilingVertical) ); }
}

void OpaqueMaterial::SetFragmentResources( MaterialDesc* mat )
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
}

MaterialKey OpaqueMaterial::GetKey( ITriangleMesh* mesh )
{
	const Bool diffuse = (_diffuseMap->GetImage() != nullptr);
	const Bool opacity = false;
	const Bool instanced = (mesh->AsBatch() != nullptr);
	const UInt instanceCount = instanced ? mesh->AsBatch()->GetCapacity() : 0;
	const Bool skinned = (mesh->GetSkeleton() != nullptr) && (mesh->GetSkeleton()->GetBoneCount() > 0);
	return MaterialKey( mesh->GetScene()->IsLit() ? _lightingModel : LightingModel::Unknown, diffuse, opacity, skinned, instanced, instanceCount );
}

MaterialDesc* OpaqueMaterial::FindMaterial( const MaterialKey& key )
{
	SynkroProfile( "OpaqueMaterial.FindMaterial" );

	MaterialDesc* mat = nullptr;

	const Bool lit = (key.Model != LightingModel::Unknown);
	const Bool textured = key.DiffuseMap;
	const Bool colored = false;
	const Bool skinned = key.Skinned;
	const Bool instanced = key.Instanced;

	// Generate program name.
	String name( L"material.opaque" );
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
	mat->Skinned = key.Skinned;
	mat->Instanced = key.Instanced;
	mat->InstanceCount = key.InstanceCount;

	// Setup states, parameters and resources.
	CreateStates();
	SetFragmentParameters( mat );
	SetFragmentResources( mat );
	SetVertexParameters( mat );
	SetVertexResources( mat );

	return mat;
}


} // mat


} // synkro
