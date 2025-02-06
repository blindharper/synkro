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
// Purpose: Defines string resources.
//==============================================================================
#ifndef _SYNKRO_CORE_STR_
#define _SYNKRO_CORE_STR_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace core
{


/**
 * String resources.
 */
class SYNKRO_API Str
{
public:
	//--------------------------------------------------------------------------
	// General
	//--------------------------------------------------------------------------

	/** Unknown error occured. */
	static const Char* UnknownError;

	/** Incompatible Synkro version requested. */
	static const Char* IncompatibleVersion;

	/** Division by zero. */
	static const Char* DivisionByZero;

	/** Null reference. */
	static const Char* NullReference;

	/** Index is out of range. */
	static const Char* OutOfRange;

	/** Done. */
	static const Char* Done;

	/** Call to {0} has failed. */
	static const Char* CallFail;

	/** Error code: {0}. */
	static const Char* ErrorCode;

	/** {0} not found. */
	static const Char* NotFound;

	/** Initializing {0}... */
	static const Char* Initializing;

	/** Failed to initialize {0}. */
	static const Char* InitializeFail;

	/** Subsystem {0,q} is disabled. Use {1,q} parameter to enable it. */
	static const Char* SubsystemDisabled;

	/** Invalid Synkro version: {0}. Should be {1}. */
	static const Char* InvalidSdkVersion;

	/** Invalid argument. */
	static const Char* InvalidArgument;

	/** Invalid pointer. */
	static const Char* InvalidPointer;

	/** Invalid operation. */
	static const Char* InvalidOperation;

	//--------------------------------------------------------------------------
	// I/O
	//--------------------------------------------------------------------------

	/** Failed to open directory {0,q}. */
	static const Char* DirectoryFail;

	/** Failed to open stream {0,q}. */
	static const Char* StreamFail;

	//--------------------------------------------------------------------------
	// Input
	//--------------------------------------------------------------------------

	/** Unknown input device detected: {0,q}. */
	static const Char* InputDeviceDetected;

	/** Joystick detected: {0,q}. */
	static const Char* JoystickDetected;

	/** Failed to initialize joystick: {0,q}. */
	static const Char* JoystickInitFail;

	/** Keyboard detected: {0,q}. */
	static const Char* KeyboardDetected;

	/** Failed to initialize keyboard: {0,q}. */
	static const Char* KeyboardInitFail;

	/** Mouse detected: {0,q}. */
	static const Char* MouseDetected;

	/** Failed to initialize mouse: {0,q}. */
	static const Char* MouseInitFail;

	//--------------------------------------------------------------------------
	// Audio
	//--------------------------------------------------------------------------

	/** Audio playback device detected: {0,q}. */
	static const Char* PlayerDetected;

	/** Failed to create audio playback device: {0,q}. */
	static const Char* PlayerCreateFail;

	/** Audio recording device detected: {0,q}. */
	static const Char* RecorderDetected;

	/** Failed to create audio recording device: {0,q}. */
	static const Char* RecorderCreateFail;

	/** Failed to create 3D sound emitter of format {0}. */
	static const Char* SoundEmitterCreateFail;

	/** Failed to create sound buffer of format {0}. */
	static const Char* SoundBufferCreateFail;

	/** Failed to create voice buffer of format {0}. */
	static const Char* VoiceBufferCreateFail;

	/** Failed to apply audio effect. */
	static const Char* AudioEffectBindFail;

	//--------------------------------------------------------------------------
	// Graphics
	//--------------------------------------------------------------------------

	/** Failed to create graphics device. */
	static const Char* GraphicsDeviceFail;

	/** Failed to create rendering window. */
	static const Char* RenderWindowFail;

	/** Setting display mode {0}... */
	static const Char* SettingDisplayMode;

	/** Failed to set display mode. */
	static const Char* DisplayModeFail;

	/** Failed to compile program {0,q}. */
	static const Char* ProgramCompileFail;

	/** Failed to build program {0,q}. */
	static const Char* ProgramBuildFail;

	/** Failed to bind program {0,q}. */
	static const Char* ProgramBindFail;

	/** Wrong program parameter. */
	static const Char* WrongProgramParameter;

	/** Failed to set program parameter. */
	static const Char* ProgramParameterFail;

	/** Failed to create blend state. */
	static const Char* BlendStateCreateFail;

	/** Failed to bind blend state. */
	static const Char* BlendStateBindFail;

	/** Failed to create depth-stencil state. */
	static const Char* DepthStencilStateCreateFail;

	/** Failed to bind depth-stencil state. */
	static const Char* DepthStencilStateBindFail;

	/** Failed to create rasterizer state. */
	static const Char* RasterizerStateCreateFail;

	/** Failed to bind rasterizer state. */
	static const Char* RasterizerStateBindFail;

	/** Failed to create sampler state. */
	static const Char* SamplerStateCreateFail;

	/** Failed to bind sampler state. */
	static const Char* SamplerStateBindFail;

	//--------------------------------------------------------------------------
	// Network
	//--------------------------------------------------------------------------

	/** Network device detected: {0}. */
	static const Char* NetworkDeviceDetected;

	/** Registers resource string. */
	static void RegisterString( const Char* name, const Char* value );
};


} // core


} // synkro


#endif // _SYNKRO_CORE_STR_
