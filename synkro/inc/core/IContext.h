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
// Purpose: Defines framework context.
//==============================================================================
#ifndef _SYNKRO_CORE_ICONTEXT_
#define _SYNKRO_CORE_ICONTEXT_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace core
{


/**
 * Framework context.
 */
iface IContext :
	public IObject
{
public:
	/**
	 * Retrieves animation system.
	 */
	virtual anim::IAnimationSystem*							GetAnimationSystem() const = 0;

	/**
	 * Retrieves audio system.
	 */
	virtual audio::IAudioSystemEx*							GetAudioSystem() const = 0;

	/**
	 * Retrieves console.
	 */
	virtual cons::IConsole*									GetConsole() const = 0;

	/**
	 * Retrieves database system.
	 */
	virtual db::IDatabaseSystemEx*							GetDatabaseSystem() const = 0;

	/**
	 * Retrieves diagnostics object.
	 */
	virtual diag::IDiag*									GetDiag() const = 0;

	/**
	 * Retrieves graphics system.
	 */
	virtual gfx::IGraphicsSystemEx*							GetGraphicsSystem() const = 0;

	/**
	 * Retrieves image manager.
	 */
	virtual img::IImageManager*								GetImageManager() const = 0;

	/**
	 * Retrieves input system.
	 */
	virtual input::IInputSystemEx*							GetInputSystem() const = 0;

	/**
	 * Retrieves material manager.
	 */
	virtual mat::IMaterialManager*							GetMaterialManager() const = 0;

	/**
	 * Retrieves network system.
	 */
	virtual net::INetworkSystemEx*							GetNetworkSystem() const = 0;

	/**
	 * Retrieves overlay manager.
	 */
	virtual over::IOverlayManager*							GetOverlayManager() const = 0;

	/**
	 * Retrieves scene manager.
	 */
	virtual scene::ISceneManager*							GetSceneManager() const = 0;

	/**
	 * Retrieves scripting system.
	 */
	virtual script::IScriptSystemEx*						GetScriptSystem() const = 0;

	/**
	 * Retrieves sound manager.
	 */
	virtual sound::ISoundManager*							GetSoundManager() const = 0;

	/**
	 * Retrieves stream system.
	 */
	virtual io::IStreamSystemEx*							GetStreamSystem() const = 0;

	/**
	 * Retrieves user interface.
	 */
	virtual ui::IUiEx*										GetUi() const = 0;

	/**
	 * Retrieves viewport manager.
	 */
	virtual view::IViewportManager*							GetViewportManager() const = 0;

	/**
	 * Retrieves window system.
	 */
	virtual win::IWindowSystemEx*							GetWindowSystem() const = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_ICONTEXT_
