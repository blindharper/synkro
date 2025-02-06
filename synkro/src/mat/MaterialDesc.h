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
#ifndef _SYNKRO_MAT_MATERIALDESC_
#define _SYNKRO_MAT_MATERIALDESC_


#include "config.h"
#include <lang/Ptr.h>
#include <lang/Formatter.h>
#include <mat/LightingModel.h>
#include <gfx/IParameterSet.h>


namespace synkro
{


namespace mat
{


// Material key.
class SYNKRO_API MaterialKey
{
public:
	// Constructors.
	MaterialKey( const LightingModel& model, Bool diffuseMap, Bool opacityMap, Bool skinned, Bool instanced, UInt instanceCount );
	MaterialKey();

	LightingModel											Model;
	Bool													DiffuseMap;
	Bool													OpacityMap;
	Bool													Skinned;
	Bool													Instanced;
	UInt													InstanceCount;

	Bool													operator==( const MaterialKey& other ) const;
	Int														HashCode() const;

private:
	Int														_hash;
};


// Material description.
class SYNKRO_API MaterialDesc
{
public:
	MaterialDesc();

	Bool													Textured;
	Bool													Skinned;
	Bool													Instanced;
	UInt													InstanceCount;
	gfx::IProgram*											Program;
	gfx::ProgramParam*										ParamDiffuse;
	gfx::ProgramParam*										ParamAmbient;
	gfx::ProgramParam*										ParamEmissive;
	gfx::ProgramParam*										ParamSpecular;
	gfx::ProgramParam*										ParamSpecularPower;
	P(gfx::IParameterSet)									VertexParams;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_MATERIALDESC_
