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
// Purpose: Generic DirectX mesh writer implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE XMeshWriterImpl<T>::XMeshWriterImpl() :
	_stream( nullptr ),
	_templates( A(IndexEntry2) ),
	_buffer( A(Byte) )
{
	RegisterTemplates();
}

template <class T>
SYNKRO_INLINE XMeshWriterImpl<T>::~XMeshWriterImpl()
{
}

template <class T>
SYNKRO_INLINE void XMeshWriterImpl<T>::WriteName( const lang::String& name )
{
	_buffer.SetSize( name.Length()+1 );
	name.GetBytes( _buffer.Begin(), _buffer.Size() );
	_stream->Write( _buffer.Begin(), name.Length() );
}

template <class T>
SYNKRO_INLINE void XMeshWriterImpl<T>::RegisterTemplates()
{
	RegisterTemplate( TEMPLATE_ANIMATION, L"Animation" );
	RegisterTemplate( TEMPLATE_ANIMATION_KEY, L"AnimationKey" );
	RegisterTemplate( TEMPLATE_ANIMATION_SET, L"AnimationSet" );
	RegisterTemplate( TEMPLATE_COLOR_RGB, L"ColorRGB" );
	RegisterTemplate( TEMPLATE_COLOR_RGBA, L"ColorRGBA" );
	RegisterTemplate( TEMPLATE_FRAME, L"Frame" );
	RegisterTemplate( TEMPLATE_FRAME_TRANSFORM_MATRIX, L"FrameTransformMatrix" );
	RegisterTemplate( TEMPLATE_MATERIAL, L"Material" );
	RegisterTemplate( TEMPLATE_MATRIX4X4, L"Matrix4x4" );
	RegisterTemplate( TEMPLATE_MESH, L"Mesh" );
	RegisterTemplate( TEMPLATE_MESH_FACE, L"MeshFace" );
	RegisterTemplate( TEMPLATE_MESH_MATERIAL_LIST, L"MeshMaterialList" );
	RegisterTemplate( TEMPLATE_MESH_NORMALS, L"MeshNormals" );
	RegisterTemplate( TEMPLATE_MESH_TEXTURE_COORDS, L"MeshTextureCoords" );
	RegisterTemplate( TEMPLATE_SKIN_WEIGHTS, L"SkinWeights" );
	RegisterTemplate( TEMPLATE_TEXTURE_FILENAME, L"TextureFilename" );
	RegisterTemplate( TEMPLATE_TIMED_FLOAT_KEYS, L"TimedFloatKeys" );
	RegisterTemplate( TEMPLATE_VECTOR, L"Vector" );
	RegisterTemplate( TEMPLATE_XSKIN_MESH_HEADER, L"XSkinMeshHeader" );
}

template <class T>
SYNKRO_INLINE void XMeshWriterImpl<T>::RegisterTemplate( Byte type, const lang::String& name )
{
	_templates[type] = name;
}
