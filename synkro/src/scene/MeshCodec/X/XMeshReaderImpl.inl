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
// Purpose: Generic DirectX mesh reader implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE XMeshReaderImpl<T>::XMeshReaderImpl() :
	_stream( nullptr ),
	_templates( A(IndexEntry) ),
	_materials( A(MaterialEntry) ),
	_subMaterials( A(SubMaterialDesc) ),
	_models( A(ModelDesc) ),
	_animationSets( A(AnimationSetDesc) ),
	_frames( A(FrameDesc) ),
	_frameStack( A(UInt) ),
	_frameIndices( A(IndexEntry) )
{
	RegisterTemplates();
}

template <class T>
SYNKRO_INLINE XMeshReaderImpl<T>::~XMeshReaderImpl()
{
}

template <class T>
SYNKRO_INLINE char XMeshReaderImpl<T>::ReadChar()
{
	return (char)0;
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::ReadAnimationSet( const lang::String& name, Bool load )
{
	if ( load )
	{
		_animationSets.Add( AnimationSetDesc(name) );
	}
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::ReadAnimation( Bool load )
{
	if ( load )
	{
		_animationSets.Last()->Animations.Add( AnimationDesc() );
	}
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::ReadAnimationKey( Bool load )
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::ReadFrame( const lang::String& name )
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::PopFrame()
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::ReadFrameTransformMatrix()
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::ReadMeshSkinHeader( Bool load )
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::ReadSkinWeights( Bool load )
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::GetModels( lang::Vector<ModelDesc>** models )
{
	*models = &_models;
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::GetMaterials( lang::MapCI<lang::String, MaterialDesc>** materials )
{
	*materials = &_materials;
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::GetSubMaterials( lang::Vector<SubMaterialDesc>** subMaterials )
{
	*subMaterials = &_subMaterials;
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::GetAnimations( lang::Vector<AnimationSetDesc>** animationSets )
{
	*animationSets = &_animationSets;
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::GetFrames( lang::Vector<FrameDesc>** frames )
{
	*frames = &_frames;
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::GetFrameIndices( lang::Map<lang::String, Byte>** frameIndices )
{
	*frameIndices = &_frameIndices;
}

template <class T>
SYNKRO_INLINE void XMeshReaderImpl<T>::RegisterTemplates()
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
SYNKRO_INLINE void XMeshReaderImpl<T>::RegisterTemplate( Byte type, const lang::String& name )
{
	_templates[name] = type;
}
