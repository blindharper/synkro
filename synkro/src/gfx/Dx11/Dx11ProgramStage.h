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
#ifndef _SYNKRO_GFX_DX11PROGRAMSTAGE_
#define _SYNKRO_GFX_DX11PROGRAMSTAGE_


#include "config.h"
#include <gfx/ProgramStageImpl.h>
#include <gfx/IProgramStage.h>
#undef new
#include "Dx11.h"
#include <d3d11shader.h>
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 based program stage.
class Dx11ProgramStage :
	public ProgramStageImpl<IProgramStage>
{
public:
	// Constructor & destructor.
	Dx11ProgramStage( IProgram* parentProgram, Dx11Context* context, ID3D11ShaderReflection* reflect, const ProgramStageType& type );
	~Dx11ProgramStage();

private:
	ID3D11ShaderReflection*									_reflect;

	IParameterSet*											GetParameters( IProgramStage* stage ) const;
	IResourceSet*											GetResources( IProgramStage* stage ) const;
	ISamplerStateSet*										GetSamplers( IProgramStage* stage ) const;
	UInt													GetParamsStartSlot( IParameterSet* parentParams, IParameterSet* grandParentParams ) const;
	UInt													GetResourcesStartSlot( IResourceSet* parentResources, IResourceSet* grandParentResources ) const;
	UInt													GetSamplersStartSlot( ISamplerStateSet* parentSamplers, ISamplerStateSet* grandParentSamplers ) const;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11PROGRAMSTAGE_
