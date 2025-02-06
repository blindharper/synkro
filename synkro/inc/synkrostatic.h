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
// Purpose: Synkro static include file.
//==============================================================================
#ifndef _SYNKROSTATIC_
#define _SYNKROSTATIC_


#include <synkro.h>


namespace synkro
{


#ifdef SYNKRO_STATIC


/**
 * Performs animation library initialization.
 */
SYNKRO_API void												SynkroAnimInit();

/**
 * Performs OpenAL audio library initialization.
 */
SYNKRO_API void												SynkroAudioAlInit();

/**
 * Performs DirectSound8 audio library initialization.
 */
SYNKRO_API void												SynkroAudioDs8Init();

/**
 * Performs WinMM audio library initialization.
 */
SYNKRO_API void												SynkroAudioWinmmInit();

/**
 * Performs console library initialization.
 */
SYNKRO_API void												SynkroConsInit();

/**
 * Performs Sqlite database library initialization.
 */
SYNKRO_API void												SynkroDbSqliteInit();

/**
 * Performs DirectX 11 graphics library initialization.
 */
SYNKRO_API void												SynkroGfxDx11Init();

/**
 * Performs imaging library initialization.
 */
SYNKRO_API void												SynkroImgInit();

/**
 * Performs DirectInput8 input library initialization.
 */
SYNKRO_API void												SynkroInputDi8Init();

/**
 * Performs Win32 input library initialization.
 */
SYNKRO_API void												SynkroInputWin32Init();

/**
 * Performs I/O library initialization.
 */
SYNKRO_API void												SynkroIoInit();

/**
 * Performs material library initialization.
 */
SYNKRO_API void												SynkroMatInit();

/**
 * Performs WinSock2 networking library initialization.
 */
SYNKRO_API void												SynkroNetWs2Init();

/**
 * Performs scene library initialization.
 */
SYNKRO_API void												SynkroSceneInit();

/**
 * Performs LUA scripting library initialization.
 */
SYNKRO_API void												SynkroScriptLuaInit();

/**
 * Performs sound library initialization.
 */
SYNKRO_API void												SynkroSoundInit();

/**
 * Performs user interface library initialization.
 */
SYNKRO_API void												SynkroUiInit();

/**
 * Performs viewport library initialization.
 */
SYNKRO_API void												SynkroViewInit();

/**
 * Performs Win32 windowing library initialization.
 */
SYNKRO_API void												SynkroWinWin32Init();


#endif // SYNKRO_STATIC


} // synkro


#endif // _SYNKROSTATIC_
