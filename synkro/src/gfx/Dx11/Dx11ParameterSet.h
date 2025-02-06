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
// Purpose: DX11 program parameters.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11PARAMETERSET_
#define _SYNKRO_GFX_DX11PARAMETERSET_


#include "config.h"
#include <gfx/ParameterSetImpl.h>
#include <gfx/IParameterSet.h>
#include <gfx/GraphicsException.h>
#include <lang/Vector.h>
#undef new
#include "Dx11.h"
#include "Dx11ProgramParam.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 program parameters.
class Dx11ParameterSet :
	public ParameterSetImpl<IParameterSet, Dx11ProgramParam>
{
public:
	// Constructors and destructor.
	Dx11ParameterSet( Dx11Context* context, ID3D11ShaderReflection* reflect, const ProgramStageType& type, IParameterSet* parent, IParameterSet* grandParent, UINT startSlot );
	Dx11ParameterSet( const Dx11ParameterSet& other, Bool cloneShared );
	~Dx11ParameterSet();

	// IParameterSet methods.
	void													Bind();
	void													Set( ProgramParam* param, Bool value );
	void													Set( ProgramParam* param, const Bool* value, UInt count );
	void													Set( ProgramParam* param, Int value );
	void													Set( ProgramParam* param, const Int* value, UInt count );
	void													Set( ProgramParam* param, Float value );
	void													Set( ProgramParam* param, const Float* value, UInt count );
	void													Set( ProgramParam* param, const math::Vector2& value );
	void													Set( ProgramParam* param, const math::Vector2* value, UInt count );
	void													Set( ProgramParam* param, const math::Vector3& value );
	void													Set( ProgramParam* param, const math::Vector3* value, UInt count );
	void													Set( ProgramParam* param, const math::Vector4& value );
	void													Set( ProgramParam* param, const math::Vector4* value, UInt count );
	void													Set( ProgramParam* param, const math::Matrix4x4& value );
	void													Set( ProgramParam* param, const math::Matrix4x4* value, UInt count );
	void													Set( ProgramParam* param, const Byte* value, UInt size );
	void													Set( ProgramParam* param, const Byte* value, UInt size, UInt count );
	IParameterSet*											Clone( UInt ownerID, Bool cloneShared ) const;

private:
	typedef lang::MapPair<Pointer, ID3D11Buffer*>			BufferEntry;

	lang::Vector<ID3D11Buffer*>								_buffers;
	lang::Map<Pointer, ID3D11Buffer*>						_dirtyBuffers;
	UINT													_startSlot;
	Dx11Context												_context;
};


#include "Dx11ParameterSet.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11PARAMETERSET_
