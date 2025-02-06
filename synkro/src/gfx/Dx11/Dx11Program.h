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
// Purpose: DX11 based program.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11PROGRAM_
#define _SYNKRO_GFX_DX11PROGRAM_


#include "config.h"
#include <gfx/ProgramImpl.h>
#include <gfx/IProgram.h>
#include <gfx/GraphicsException.h>
#undef new
#include "Dx11.h"
#include "Dx11Classes.h"
#include "Dx11GraphicsDevice.h"
#include <d3d11shader.h>
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 based program.
class Dx11Program :
	public ProgramImpl<IProgram>
{
public:
	// Constructor & destructor.
	Dx11Program( Dx11GraphicsDevice* device, IProgram* parent, IDataFormat* inputFormat, IDataFormat* outputFormat, io::IStream* vertexProgram, io::IStream* hullProgram, io::IStream* domainProgram, io::IStream* geometryProgram, io::IStream* fragmentProgram );
	~Dx11Program();

	// IProgram methods.
	void													Bind();
	void													Save( io::IStream* vertexProgram, io::IStream* hullProgram, io::IStream* domainProgram, io::IStream* geometryProgram, io::IStream* fragmentProgram );

private:
	friend class Dx11Primitive;

	void													Save( ID3D10Blob* blob, io::IStream* stream );
	template<class T>
	T*														PrepareShader( Dx11GraphicsDevice* device, const ProgramStageType& type, io::IStream* program, ID3D10Blob** code, ID3D11ShaderReflection** reflect );
	template<class T>
	T*														CreateShader( Dx11GraphicsDevice* device, io::IStream* program, ID3D10Blob* code );	

	Dx11Context												_context;
	ID3D11InputLayout*										_layout;
	ID3D11InputLayout*										_layoutInterleaved;
	ID3D10Blob*												_vertexCode;
	ID3D11VertexShader*										_vertexShader;
	ID3D10Blob*												_hullCode;
	ID3D11HullShader*										_hullShader;
	ID3D10Blob*												_domainCode;
	ID3D11DomainShader*										_domainShader;
	ID3D10Blob*												_geometryCode;
	ID3D11GeometryShader*									_geometryShader;
	ID3D10Blob*												_fragmentCode;
	ID3D11PixelShader*										_fragmentShader;
};


#include "Dx11Program.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11PROGRAM_
