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
#ifndef _SYNKRO_CORE_ISYNKROCONTEXT_
#define _SYNKRO_CORE_ISYNKROCONTEXT_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace core
{


/**
 * Framework context.
 */
iface ISynkroContext :
	public IObject
{
public:
	/**
	 * Retrieves animation system.
	 * @param silent Indicates whether to suppress exception if subsystem is disabled.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual anim::IAnimationSystem*							GetAnimationSystem( Bool silent ) const = 0;

	/**
	 * Retrieves animation system.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual anim::IAnimationSystem*							GetAnimationSystem() const = 0;

	/**
	 * Retrieves audio system.
	 * @param silent Indicates whether to suppress exception if subsystem is disabled.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual audio::IAudioSystemEx*							GetAudioSystem( Bool silent ) const = 0;

	/**
	 * Retrieves audio system.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual audio::IAudioSystemEx*							GetAudioSystem() const = 0;

	/**
	 * Retrieves console.
	 * @param silent Indicates whether to suppress exception if console is disabled.
	 * @exception InvalidOperationException Console is disabled.
	 */
	virtual cons::IConsole*									GetConsole( Bool silent ) const = 0;

	/**
	 * Retrieves console.
	 * @exception InvalidOperationException Console is disabled.
	 */
	virtual cons::IConsole*									GetConsole() const = 0;

	/**
	 * Retrieves database system.
	 * @param silent Indicates whether to suppress exception if subsystem is disabled.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual db::IDatabaseSystemEx*							GetDatabaseSystem( Bool silent ) const = 0;

	/**
	 * Retrieves database system.
	 * @exception InvalidOperationException Subsystem is disabled.
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
	 * @param silent Indicates whether to suppress exception if subsystem is disabled.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual img::IImageManager*								GetImageManager( Bool silent ) const = 0;

	/**
	 * Retrieves image manager.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual img::IImageManager*								GetImageManager() const = 0;

	/**
	 * Retrieves input system.
	 * @param silent Indicates whether to suppress exception if subsystem is disabled.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual input::IInputSystemEx*							GetInputSystem( Bool silent ) const = 0;

	/**
	 * Retrieves input system.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual input::IInputSystemEx*							GetInputSystem() const = 0;

	/**
	 * Retrieves material manager.
	 */
	virtual mat::IMaterialManager*							GetMaterialManager() const = 0;

	/**
	 * Retrieves network system.
	 * @param silent Indicates whether to suppress exception if subsystem is disabled.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual net::INetworkSystemEx*							GetNetworkSystem( Bool silent ) const = 0;

	/**
	 * Retrieves network system.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual net::INetworkSystemEx*							GetNetworkSystem() const = 0;

	/**
	 * Retrieves overlay manager.
	 */
	virtual over::IOverlayManager*							GetOverlayManager() const = 0;

	/**
	 * Retrieves physics system.
	 * @param silent Indicates whether to suppress exception if subsystem is disabled.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual phys::IPhysicsSystemEx*							GetPhysicsSystem( Bool silent ) const = 0;

	/**
	 * Retrieves physics system.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual phys::IPhysicsSystemEx*							GetPhysicsSystem() const = 0;

	/**
	 * Retrieves scene manager.
	 */
	virtual scene::ISceneManager*							GetSceneManager() const = 0;

	/**
	 * Retrieves scripting system.
	 * @param silent Indicates whether to suppress exception if subsystem is disabled.
	 * @exception InvalidOperationException Subsystem is disabled.
	 */
	virtual script::IScriptSystemEx*						GetScriptSystem( Bool silent ) const = 0;

	/**
	 * Retrieves scripting system.
	 * @exception InvalidOperationException Subsystem is disabled.
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
	 * @param silent Indicates whether to suppress exception if user interface is disabled.
	 * @exception InvalidOperationException User interface is disabled.
	 */
	virtual ui::IUiEx*										GetUi( Bool silent ) const = 0;

	/**
	 * Retrieves user interface.
	 * @exception InvalidOperationException User interface is disabled.
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


#endif // _SYNKRO_CORE_ISYNKROCONTEXT_
