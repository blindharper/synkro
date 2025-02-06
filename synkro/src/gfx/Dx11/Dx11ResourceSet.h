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
// Purpose: DX11 based resource set implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11RESOURCESET_
#define _SYNKRO_GFX_DX11RESOURCESET_


#include "config.h"
#include <gfx/ResourceSetImpl.h>
#include <gfx/IResourceSet.h>
#undef new
#include "Dx11.h"
#include "Dx11Resource.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 based resource set.
class Dx11ResourceSet :
	public ResourceSetImpl<IResourceSet, Dx11Resource>
{
public:
	// Constructors.
	Dx11ResourceSet( Dx11Context* context, ID3D11ShaderReflection* reflect, const ProgramStageType& type, UINT startSlot );
	Dx11ResourceSet( const Dx11ResourceSet& other );

	// IResourceSet methods.
	void													Bind();
	void													Unbind();
	void													Set( UInt index, IResource* resource );
	IResourceSet*											Clone( UInt ownerID ) const;

private:
	lang::Vector<ID3D11ShaderResourceView*>					_views;
	lang::Vector<ID3D11ShaderResourceView*>					_nulls;
	UINT													_startSlot;
	Dx11Context												_context;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11RESOURCESET_
