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
// Purpose: Scene manager implementation.
//==============================================================================
SYNKRO_INLINE UInt SceneManager::GetSceneCount() const
{
	return _scenes.Size();
}

SYNKRO_INLINE ISceneEx* SceneManager::GetScene( UInt index ) const
{
	assert( index < _scenes.Size() );

	if ( index >= _scenes.Size() )
		throw lang::OutOfRangeException( index, _scenes.Size() );

	return _scenes[index];
}

SYNKRO_INLINE ISceneEx* SceneManager::GetScene( const lang::String& name ) const
{
	for ( UInt i = 0; i < _scenes.Size(); ++i )
	{
		if ( name.EqualsTo(_scenes[i]->GetName(), true) )
			return _scenes[i];
	}
	return nullptr;
}

SYNKRO_INLINE Bool SceneManager::Call( Scene* scene )
{
	scene->Update();
	return true;
}
