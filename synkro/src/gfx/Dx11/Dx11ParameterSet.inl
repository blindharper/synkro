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
SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, Bool value )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, const Bool* value, UInt count )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value, count );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, Int value )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, const Int* value, UInt count )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value, count );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, Float value )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, const Float* value, UInt count )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value, count );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, const math::Vector2& value )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, const math::Vector2* value, UInt count )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value, count );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, const math::Vector3& value )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, const math::Vector3* value, UInt count )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value, count );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, const math::Vector4& value )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, const math::Vector4* value, UInt count )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value, count );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, const math::Matrix4x4& value )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, const math::Matrix4x4* value, UInt count )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value, count );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, const Byte* value, UInt size )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value, size );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}

SYNKRO_INLINE void Dx11ParameterSet::Set( ProgramParam* param, const Byte* value, UInt size, UInt count )
{
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>::Set( param, value, size, count );
	ID3D11Buffer* buf = ((Dx11ProgramParam*)param)->Buffer;
	Pointer key = reinterpret_cast<Pointer>( buf );
	_dirtyBuffers[key] = buf;
}
