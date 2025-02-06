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
// Purpose: DX11 based program stage implementation.
//==============================================================================
#include "config.h"
#include "Dx11ProgramStage.h"
#include "Dx11ParameterSet.h"
#include "Dx11ResourceSet.h"
#include "Dx11SamplerStateSet.h"
#include <gfx/ProgramStageTypeConst.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11ProgramStage::Dx11ProgramStage( IProgram* parentProgram, Dx11Context* context, ID3D11ShaderReflection* reflect, const ProgramStageType& type ) :
	_reflect( reflect )
{
	IProgram* grandParentProgram = (parentProgram != nullptr) ? parentProgram->GetParent() : nullptr;
	IParameterSet* parentParams = nullptr; IParameterSet* grandParentParams = nullptr;
	IResourceSet* parentResources = nullptr; IResourceSet* grandParentResources = nullptr;
	ISamplerStateSet* parentSamplers = nullptr; ISamplerStateSet* grandParentSamplers = nullptr;

	switch ( type )
	{
		case PROGRAM_STAGE_TYPE_VERTEX:
			parentParams = (parentProgram != nullptr) ? GetParameters(parentProgram->GetVertexStage()) : nullptr;
			grandParentParams = (grandParentProgram != nullptr) ? GetParameters(grandParentProgram->GetVertexStage()) : nullptr;
			parentResources = (parentProgram != nullptr) ? GetResources(parentProgram->GetVertexStage()) : nullptr;
			grandParentResources = (grandParentProgram != nullptr) ? GetResources(grandParentProgram->GetVertexStage()) : nullptr;
			parentSamplers = (parentProgram != nullptr) ? GetSamplers(parentProgram->GetVertexStage()) : nullptr;
			grandParentSamplers = (grandParentProgram != nullptr) ? GetSamplers(grandParentProgram->GetVertexStage()) : nullptr;
			break;

		case PROGRAM_STAGE_TYPE_HULL:
			parentParams = (parentProgram != nullptr) ? GetParameters(parentProgram->GetHullStage()) : nullptr;
			grandParentParams = (grandParentProgram != nullptr) ? GetParameters(grandParentProgram->GetHullStage()) : nullptr;
			parentResources = (parentProgram != nullptr) ? GetResources(parentProgram->GetHullStage()) : nullptr;
			grandParentResources = (grandParentProgram != nullptr) ? GetResources(grandParentProgram->GetHullStage()) : nullptr;
			parentSamplers = (parentProgram != nullptr) ? GetSamplers(parentProgram->GetHullStage()) : nullptr;
			grandParentSamplers = (grandParentProgram != nullptr) ? GetSamplers(grandParentProgram->GetHullStage()) : nullptr;
			break;

		case PROGRAM_STAGE_TYPE_DOMAIN:
			parentParams = (parentProgram != nullptr) ? GetParameters(parentProgram->GetDomainStage()) : nullptr;
			grandParentParams = (grandParentProgram != nullptr) ? GetParameters(grandParentProgram->GetDomainStage()) : nullptr;
			parentResources = (parentProgram != nullptr) ? GetResources(parentProgram->GetDomainStage()) : nullptr;
			grandParentResources = (grandParentProgram != nullptr) ? GetResources(grandParentProgram->GetDomainStage()) : nullptr;
			parentSamplers = (parentProgram != nullptr) ? GetSamplers(parentProgram->GetDomainStage()) : nullptr;
			grandParentSamplers = (grandParentProgram != nullptr) ? GetSamplers(grandParentProgram->GetDomainStage()) : nullptr;
			break;

		case PROGRAM_STAGE_TYPE_GEOMETRY:
			parentParams = (parentProgram != nullptr) ? GetParameters(parentProgram->GetGeometryStage()) : nullptr;
			grandParentParams = (grandParentProgram != nullptr) ? GetParameters(grandParentProgram->GetGeometryStage()) : nullptr;
			parentResources = (parentProgram != nullptr) ? GetResources(parentProgram->GetGeometryStage()) : nullptr;
			grandParentResources = (grandParentProgram != nullptr) ? GetResources(grandParentProgram->GetGeometryStage()) : nullptr;
			parentSamplers = (parentProgram != nullptr) ? GetSamplers(parentProgram->GetGeometryStage()) : nullptr;
			grandParentSamplers = (grandParentProgram != nullptr) ? GetSamplers(grandParentProgram->GetGeometryStage()) : nullptr;
			break;

		case PROGRAM_STAGE_TYPE_FRAGMENT:
			parentParams = (parentProgram != nullptr) ? GetParameters(parentProgram->GetFragmentStage()) : nullptr;
			grandParentParams = (grandParentProgram != nullptr) ? GetParameters(grandParentProgram->GetFragmentStage()) : nullptr;
			parentResources = (parentProgram != nullptr) ? GetResources(parentProgram->GetFragmentStage()) : nullptr;
			grandParentResources = (grandParentProgram != nullptr) ? GetResources(grandParentProgram->GetFragmentStage()) : nullptr;
			parentSamplers = (parentProgram != nullptr) ? GetSamplers(parentProgram->GetFragmentStage()) : nullptr;
			grandParentSamplers = (grandParentProgram != nullptr) ? GetSamplers(grandParentProgram->GetFragmentStage()) : nullptr;
			break;
	}
	const UINT paramsStartSlot = GetParamsStartSlot( parentParams, grandParentParams );
	const UINT resStartSlot = GetResourcesStartSlot( parentResources, grandParentResources );
	const UINT samplersStartSlot = GetSamplersStartSlot( parentSamplers, grandParentSamplers );

	_params		= new Dx11ParameterSet( context, reflect, type, parentParams, grandParentParams, paramsStartSlot );
	_resources	= new Dx11ResourceSet( context, reflect, type, resStartSlot );
	_samplers	= new Dx11SamplerStateSet( context, reflect, type, samplersStartSlot );
}

Dx11ProgramStage::~Dx11ProgramStage()
{
	SafeRelease( _reflect );
}

IParameterSet* Dx11ProgramStage::GetParameters( IProgramStage* stage ) const
{
	return (stage != nullptr) ? stage->GetParameters() : nullptr;
}

IResourceSet* Dx11ProgramStage::GetResources( IProgramStage* stage ) const
{
	return (stage != nullptr) ? stage->GetResources() : nullptr;
}

ISamplerStateSet* Dx11ProgramStage::GetSamplers( IProgramStage* stage ) const
{
	return (stage != nullptr) ? stage->GetSamplers() : nullptr;
}

UInt Dx11ProgramStage::GetParamsStartSlot( IParameterSet* parentParams, IParameterSet* grandParentParams ) const
{
	UInt slot = 0;
	if ( parentParams != nullptr )
	{
		++slot;
	}
	if ( grandParentParams != nullptr )
	{
		++slot;
	}
	return slot;
}

UInt Dx11ProgramStage::GetResourcesStartSlot( IResourceSet* parentResources, IResourceSet* grandParentResources ) const
{
	UInt slot = 0;
	if ( parentResources != nullptr )
	{
		slot += parentResources->GetSize();
	}
	if ( grandParentResources != nullptr )
	{
		slot += grandParentResources->GetSize();
	}
	return slot;
}

UInt Dx11ProgramStage::GetSamplersStartSlot( ISamplerStateSet* parentSamplers, ISamplerStateSet* grandParentSamplers ) const
{
	UInt slot = 0;
	if ( parentSamplers != nullptr )
	{
		slot += parentSamplers->GetSize();
	}
	if ( grandParentSamplers != nullptr )
	{
		slot += grandParentSamplers->GetSize();
	}
	return slot;
}


} // gfx


} // synkro
