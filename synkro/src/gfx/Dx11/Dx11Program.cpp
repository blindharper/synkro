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
#include "config.h"
#include "Dx11Program.h"
#include "Dx11ProgramStage.h"
#include "Dx11Include.h"
#include <io/BinaryReader.h>
#include <internal/SafeRelease.h>
#undef new
#include <dx/d3dx11async.h>
#define new SYNKRO_NEW


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11Program::Dx11Program( Dx11GraphicsDevice* device, IProgram* parent, IDataFormat* inputFormat, IDataFormat* outputFormat, io::IStream* vertexProgram, io::IStream* hullProgram, io::IStream* domainProgram, io::IStream* geometryProgram, io::IStream* fragmentProgram ) :
	ProgramImpl<IProgram>( parent, inputFormat, outputFormat ),
	_context( device ),
	_layout( nullptr ),
	_layoutInterleaved( nullptr ),
	_vertexCode( nullptr ),
	_vertexShader( nullptr ),
	_hullCode( nullptr ),
	_hullShader( nullptr ),
	_domainCode( nullptr ),
	_domainShader( nullptr ),
	_geometryCode( nullptr ),
	_geometryShader( nullptr ),
	_fragmentCode( nullptr ),
	_fragmentShader( nullptr )
{
	// Prepare vertex shader.
	if ( vertexProgram != nullptr )
	{
		ID3D11ShaderReflection* reflect = nullptr;
		_vertexShader = PrepareShader<ID3D11VertexShader>( device, ProgramStageType::Vertex, vertexProgram, &_vertexCode, &reflect );
		_vertexStage = new Dx11ProgramStage( parent, device, reflect, ProgramStageType::Vertex );
	}

	// Prepare hull shader.
	if ( hullProgram != nullptr )
	{
		ID3D11ShaderReflection* reflect = nullptr;
		_hullShader = PrepareShader<ID3D11HullShader>( device, ProgramStageType::Hull, hullProgram, &_hullCode, &reflect );
		_hullStage = new Dx11ProgramStage( parent, device, reflect, ProgramStageType::Hull );
	}

	// Prepare domain shader.
	if ( domainProgram != nullptr )
	{
		ID3D11ShaderReflection* reflect = nullptr;
		_domainShader = PrepareShader<ID3D11DomainShader>( device, ProgramStageType::Domain, domainProgram, &_domainCode, &reflect );
		_domainStage = new Dx11ProgramStage( parent, device, reflect, ProgramStageType::Domain );
	}

	// Prepare geometry shader.
	if ( geometryProgram != nullptr )
	{
		ID3D11ShaderReflection* reflect = nullptr;
		_geometryShader = PrepareShader<ID3D11GeometryShader>( device, ProgramStageType::Geometry, geometryProgram, &_geometryCode, &reflect );
		_geometryStage = new Dx11ProgramStage( parent, device, reflect, ProgramStageType::Geometry );
	}

	// Prepare fragment shader.
	if ( fragmentProgram != nullptr )
	{
		ID3D11ShaderReflection* reflect = nullptr;
		_fragmentShader = PrepareShader<ID3D11PixelShader>( device, ProgramStageType::Fragment, fragmentProgram, &_fragmentCode, &reflect );
		_fragmentStage = new Dx11ProgramStage( parent, device, reflect, ProgramStageType::Fragment );
	}

	// Create vertex declaration.
	HRESULT hr = S_OK;
	D3D11_INPUT_ELEMENT_DESC decl[24];
	UINT count = 0;
	count = Dx11::Convert( inputFormat, decl, false );
	if ( (_vertexCode != nullptr) && FAILED(hr = device->_device->CreateInputLayout(decl, count, _vertexCode->GetBufferPointer(), _vertexCode->GetBufferSize(), &_layout)) )
		throw GraphicsException( L"Failed to create input layout. #1", String::Format(Str::CallFail, L"ID3D11Device::CreateInputLayout()"), Dx11::ToString(hr) );

	count = Dx11::Convert( inputFormat, decl, true );
	if ( (_vertexCode != nullptr) && FAILED(hr = device->_device->CreateInputLayout(decl, count, _vertexCode->GetBufferPointer(), _vertexCode->GetBufferSize(), &_layoutInterleaved)) )
		throw GraphicsException( L"Failed to create input layout. #2", String::Format(Str::CallFail, L"ID3D11Device::CreateInputLayout()"), Dx11::ToString(hr) );
}

Dx11Program::~Dx11Program()
{
	SafeRelease( _layout );
	SafeRelease( _layoutInterleaved );

	SafeRelease( _vertexCode );
	SafeRelease( _vertexShader );

	SafeRelease( _hullCode );
	SafeRelease( _hullShader );

	SafeRelease( _domainCode );
	SafeRelease( _domainShader );

	SafeRelease( _geometryCode );
	SafeRelease( _geometryShader );

	SafeRelease( _fragmentCode );
	SafeRelease( _fragmentShader );
}

void Dx11Program::Save( io::IStream* vertexProgram, io::IStream* hullProgram, io::IStream* domainProgram, io::IStream* geometryProgram, io::IStream* fragmentProgram )
{
	Save( _vertexCode, vertexProgram );
	Save( _hullCode, hullProgram );
	Save( _domainCode, domainProgram );
	Save( _geometryCode, geometryProgram );
	Save( _fragmentCode, fragmentProgram );
}

void Dx11Program::Save( ID3D10Blob* blob, io::IStream* stream )
{
	if ( stream != nullptr )
	{
		stream->Write( blob->GetBufferPointer(), blob->GetBufferSize() );
	}
}

template<class T>
T* Dx11Program::PrepareShader( Dx11GraphicsDevice* device, const ProgramStageType& type, io::IStream* program, ID3D10Blob** code, ID3D11ShaderReflection** reflect )
{	
	HRESULT hr = S_OK;
	ID3D10Blob* shaderCode = nullptr;
	ID3D11ShaderReflection* shaderReflect = nullptr;

	T* shader = (T*)device->GetShader( program );
	if ( shader == nullptr )
	{
		// Read code.
		BinaryReader rd( program );
		Vector<Byte> data( A(Byte), program->GetLength() );
		rd.ReadBytes( data );

		// See if we have a binary or a source code.
		if ( IsAscii(data.Begin(), data.Size()) )
		{
			// Compile program.
			UINT dwFlags =  0;
#ifdef SYNKRO_DEBUG
			dwFlags |= D3DCOMPILE_DEBUG;
#endif // SYNKRO_DEBUG

			ID3D10Blob* pErrors;
			Dx11Include dx11Inc( program->GetDirectory() );
			if (FAILED(hr = Dx11::Compile(data.Begin(), data.Size(), nullptr, nullptr, &dx11Inc, "main", Dx11::Convert(type, device->_level), dwFlags, 0, &shaderCode, &pErrors)))
			{
				const char* error = (const char*)pErrors->GetBufferPointer();
				throw GraphicsException( String::Format(Str::ProgramCompileFail, program->GetName()), String(error), Dx11::ToString(hr) );
			}
		}
		else
		{
			// Copy shader bytecode to a BLOB.
			if ( FAILED(hr = Dx11::CreateBlob((SIZE_T)data.Size(), &shaderCode)) )
				throw GraphicsException( L"Failed to create BLOB for shader bytecode.", Dx11::ToString(hr) );

			Copy<Byte>( (Byte*)shaderCode->GetBufferPointer(), data.Begin(), data.Size() );
		}

		// Build program.
		shader = CreateShader<T>( device, program, shaderCode );

		// Retrieve reflection interface.
		if ( FAILED(hr = Dx11::Reflect( shaderCode->GetBufferPointer(), shaderCode->GetBufferSize(), IID_ID3D11ShaderReflection, (void**)&shaderReflect )) )
			throw GraphicsException( String::Format(Str::ProgramBuildFail, program->GetName()), Dx11::ToString(hr) );

		// Add shader to cache.
		device->AddShader( program, shader, shaderReflect );
	}
	else
	{
		shader->AddRef();
		shaderReflect = (ID3D11ShaderReflection*)device->GetShaderData( program );
		shaderReflect->AddRef();
	}

	*code = shaderCode;
	*reflect = shaderReflect;
	return shader;
}

template<>
ID3D11VertexShader* Dx11Program::CreateShader<ID3D11VertexShader>( Dx11GraphicsDevice* device, io::IStream* program, ID3D10Blob* code )
{
	HRESULT hr = S_OK;
	ID3D11VertexShader* shader = nullptr;

	if ( FAILED(hr = device->_device->CreateVertexShader( code->GetBufferPointer(), code->GetBufferSize(), nullptr, &shader )) )
		throw GraphicsException( String::Format(Str::ProgramBuildFail, program->GetName()), Dx11::ToString(hr) );

	return shader;
}

template<>
ID3D11HullShader* Dx11Program::CreateShader<ID3D11HullShader>( Dx11GraphicsDevice* device, io::IStream* program, ID3D10Blob* code )
{
	HRESULT hr = S_OK;
	ID3D11HullShader* shader = nullptr;

	if ( FAILED(hr = device->_device->CreateHullShader( code->GetBufferPointer(), code->GetBufferSize(), nullptr, &shader )) )
		throw GraphicsException( String::Format(Str::ProgramBuildFail, program->GetName()), Dx11::ToString(hr) );

	return shader;
}

template<>
ID3D11DomainShader* Dx11Program::CreateShader<ID3D11DomainShader>( Dx11GraphicsDevice* device, io::IStream* program, ID3D10Blob* code )
{
	HRESULT hr = S_OK;
	ID3D11DomainShader* shader = nullptr;

	if ( FAILED(hr = device->_device->CreateDomainShader( code->GetBufferPointer(), code->GetBufferSize(), nullptr, &shader )) )
		throw GraphicsException( String::Format(Str::ProgramBuildFail, program->GetName()), Dx11::ToString(hr) );

	return shader;
}

template<>
ID3D11GeometryShader* Dx11Program::CreateShader<ID3D11GeometryShader>( Dx11GraphicsDevice* device, io::IStream* program, ID3D10Blob* code )
{
	HRESULT hr = S_OK;
	ID3D11GeometryShader* shader = nullptr;

	if ( _outputFormat != nullptr )
	{
		D3D11_SO_DECLARATION_ENTRY decl[64];
		UINT stride; UINT count = Dx11::Convert( _outputFormat, decl, stride );
		hr = device->_device->CreateGeometryShaderWithStreamOutput( code->GetBufferPointer(), code->GetBufferSize(), decl, count, &stride, 1, 0, nullptr, &shader );
	}
	else
	{
		hr = device->_device->CreateGeometryShader( code->GetBufferPointer(), code->GetBufferSize(), nullptr, &shader );
	}
	if ( FAILED(hr) )
		throw GraphicsException( String::Format(Str::ProgramBuildFail, program->GetName()), Dx11::ToString(hr) );

	return shader;
}

template<>
ID3D11PixelShader* Dx11Program::CreateShader<ID3D11PixelShader>( Dx11GraphicsDevice* device, io::IStream* program, ID3D10Blob* code )
{
	HRESULT hr = S_OK;
	ID3D11PixelShader* shader = nullptr;

	if ( FAILED(hr = device->_device->CreatePixelShader( code->GetBufferPointer(), code->GetBufferSize(), nullptr, &shader )) )
		throw GraphicsException( String::Format(Str::ProgramBuildFail, program->GetName()), Dx11::ToString(hr) );

	return shader;
}


} // gfx


} // synkro
