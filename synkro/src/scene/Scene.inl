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
// Purpose: Scene implementation.
//==============================================================================
SYNKRO_INLINE gfx::ISceneRenderQueue* Scene::GetRenderQueue() const
{
	return _scene->GetRenderQueue();
}

SYNKRO_INLINE Bool Scene::IsLit() const
{
	return _scene->IsLit();
}

SYNKRO_INLINE void Scene::SetAmbientLightColor( const img::Color& color )
{
	_ambientLightColor = ToVector( color );
}

SYNKRO_INLINE void Scene::SetAmbientLightIntensity( Float intensity )
{
	_ambientLightIntensity = Clamp( intensity, 0.0f, 1.0f );
}

SYNKRO_INLINE INode* Scene::GetRoot() const
{
	return _root;
}

SYNKRO_INLINE void Scene::GetAmbientLightColor( img::Color& color ) const
{
	color = ToColor( _ambientLightColor );
}

SYNKRO_INLINE Float Scene::GetAmbientLightIntensity() const
{
	return _ambientLightIntensity;
}

SYNKRO_INLINE audio::IAudioEnvironment* Scene::GetAudioEnvironment() const
{
	return _audioEnvironment;
}

SYNKRO_INLINE lang::String Scene::GetName() const
{
	return _name;
}

SYNKRO_INLINE DebugMode Scene::GetDebugMode() const
{
	return _debugMode;
}

SYNKRO_INLINE lang::String Scene::GetDummyName( const lang::String& name )
{
	return GetNodeName( name, L"Dummy {0}", _indexDummy );
}

SYNKRO_INLINE lang::String Scene::GetCameraName( const lang::String& name )
{
	return GetNodeName( name, L"Camera {0}", _indexCamera );
}

SYNKRO_INLINE lang::String Scene::GetCurveName( const lang::String& name )
{
	return GetNodeName( name, L"Curve {0}", _indexCurve );
}

SYNKRO_INLINE lang::String Scene::GetLightName( const lang::String& name )
{
	return GetNodeName( name, L"Light {0}", _indexLight );
}

SYNKRO_INLINE lang::String Scene::GetSoundName( const lang::String& name )
{
	return GetNodeName( name, L"Sound {0}", _indexSound );
}

SYNKRO_INLINE lang::String Scene::GetLineMeshName( const lang::String& name )
{
	return GetNodeName( name, L"Line Mesh {0}", _indexLineMesh );
}

SYNKRO_INLINE lang::String Scene::GetPointMeshName( const lang::String& name )
{
	return GetNodeName( name, L"Point Mesh {0}", _indexPointMesh );
}

SYNKRO_INLINE lang::String Scene::GetTriangleMeshName( const lang::String& name )
{
	return GetNodeName( name, L"Triangle Mesh {0}", _indexTriangleMesh );
}

SYNKRO_INLINE gfx::IParameterSet* Scene::GetVertexParams() const
{
	return _vertexParams;
}

SYNKRO_INLINE gfx::IResourceSet* Scene::GetVertexResources() const
{
	return _vertexResources;
}

SYNKRO_INLINE gfx::IParameterSet* Scene::GetFragmentParams() const
{
	return _fragmentParams;
}
