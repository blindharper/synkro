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
// Purpose: Defines configuration parameter.
//==============================================================================
#ifndef _SYNKRO_CORE_PARAM_
#define _SYNKRO_CORE_PARAM_


#include "config.h"
#include <core/ParamType.h>
#include <core/ParamConstraint.h>


namespace synkro
{


namespace core
{


/**
 * Configuration parameter.
 */
class SYNKRO_API Param
{
public:
	//--------------------------------------------------------------------------
	// Anim
	//--------------------------------------------------------------------------

	/** Indicates whether to enable animation functionality. */
	static const Char* AnimationEnable;

	//--------------------------------------------------------------------------
	// Audio
	//--------------------------------------------------------------------------

	/** Indicates whether to enable sound playback and recording. */
	static const Char* AudioEnable;

	/** Name of the audio system. */
	static const Char* AudioSystem;

	/** Sound format to use in application. */
	static const Char* AudioFormat;

	//--------------------------------------------------------------------------
	// Console
	//--------------------------------------------------------------------------

	/** Indicates whether to enable console. */
	static const Char* ConsoleEnable;

	//--------------------------------------------------------------------------
	// Core
	//--------------------------------------------------------------------------

	/** Maximum number of working threads. */
	static const Char* CoreThreadPoolCapacity;

	//--------------------------------------------------------------------------
	// Database
	//--------------------------------------------------------------------------

	/** Indicates whether to enable database functionality. */
	static const Char* DatabaseEnable;

	/** Name of the database system. */
	static const Char* DatabaseSystem;

	//--------------------------------------------------------------------------
	// Graphics
	//--------------------------------------------------------------------------

	/** Name of the graphics system. */
	static const Char* GraphicsSystem;

	/** Type of the graphics device. */
	static const Char* GraphicsDevice;

	/** Depth buffer format. */
	static const Char* GraphicsDepthFormat;

	/** Screen dimensions and color depth. */
	static const Char* GraphicsDisplayMode;

	/** Indicates whether to run application in full screen. */
	static const Char* GraphicsFullscreen;

	/** Indicates whether to synchronize presentation of a frame with the vertical blank. */
	static const Char* GraphicsVsync;

	/** Sample count. */
	static const Char* GraphicsSampleCount;

	/** Sample quality [0-100]. */
	static const Char* GraphicsSampleQuality;

	/** Path to compiled GPU programs cache. */
	static const Char* GraphicsProgramCache;

	/** GPU program library. */
	static const Char* GraphicsProgramLibrary;

	/** GPU program to preload. */
	static const Char* GraphicsProgramPreload;

	//--------------------------------------------------------------------------
	// Imaging
	//--------------------------------------------------------------------------

	/** Indicates whether to enable imaging. */
	static const Char* ImagingEnable;

	/** Image codec quality [1-100]. */
	static const Char* ImagingCodecQuality;

	//--------------------------------------------------------------------------
	// Input
	//--------------------------------------------------------------------------

	/** Indicates whether to enable user input processing. */
	static const Char* InputEnable;

	/** Name of the input system object. */
	static const Char* InputSystem;

	//--------------------------------------------------------------------------
	// Log
	//--------------------------------------------------------------------------

	/** Logging level. */
	static const Char* LogLevel;

	/** Logging mode. */
	static const Char* LogMode;

	/** Log file name. If not empty, logging is enabled. */
	static const Char* LogFileName;

	/** Indicates whether the log file is plain text or rich text. */
	static const Char* LogFilePlain;

	/** Indicates whether to append messages to log file. */
	static const Char* LogFileAppend;

	/** Maximum size of the log file, in kilobytes. */
	static const Char* LogFileMaxSize;

	//--------------------------------------------------------------------------
	// Net
	//--------------------------------------------------------------------------

	/** Indicates whether to enable network activity. */
	static const Char* NetworkEnable;

	/** Name of the network system. */
	static const Char* NetworkSystem;

	//--------------------------------------------------------------------------
	// Script
	//--------------------------------------------------------------------------

	/** Indicates whether to enable scripting. */
	static const Char* ScriptEnable;

	/** Name of the scripting system. */
	static const Char* ScriptSystem;

	//--------------------------------------------------------------------------
	// Stream
	//--------------------------------------------------------------------------

	/** Name of the stream system. */
	static const Char* StreamSystem;

	/** Stream system search path. */
	static const Char* StreamPath;

	//--------------------------------------------------------------------------
	// Ui
	//--------------------------------------------------------------------------

	/** Indicates whether to enable user interface. */
	static const Char* UiEnable;

	/** User interface type. */
	static const Char* UiType;

	/** User interface theme name. */
	static const Char* UiTheme;

	/** Current theme name. */
	static const Char* UiThemeName;

	/** User interface font size. */
	static const Char* UiFontSize;

	/** Normal widget color. */
	static const Char* UiColorWidgetNormal;

	/** Normal widget text color. */
	static const Char* UiColorTextNormal;

	/** Active widget color. */
	static const Char* UiColorWidgetActive;

	/** Active widget text color. */
	static const Char* UiColorTextActive;

	/** Hovered widget color. */
	static const Char* UiColorWidgetHovered;

	/** Hovered widget text color. */
	static const Char* UiColorTextHovered;

	/** Disabled widget color. */
	static const Char* UiColorWidgetDisabled;

	/** Disabled widget text color. */
	static const Char* UiColorTextDisabled;

	//--------------------------------------------------------------------------
	// View
	//--------------------------------------------------------------------------

	/** Viewport stereo mode. */
	static const Char* ViewStereoMode;

	//--------------------------------------------------------------------------
	// Win
	//--------------------------------------------------------------------------

	/** Name of the window system. */
	static const Char* WindowSystem;

	//--------------------------------------------------------------------------

	/** Creates configuration parameter with the specified properties. */
	Param( const lang::String& name, const ParamType type, const ParamConstraint constraints, const lang::String& defaultValue, const lang::String& data, const lang::String& description );
	Param();
	
	/** Parameter name. */
	lang::String											Name;

	/** Parameter type. */
	ParamType												Type;

	/** Parameter constraints. */
	ParamConstraint											Constraints;

	/** Default parameter value. */
	lang::String											DefaultValue;

	/** Internal parameter data. */
	lang::String											Data;

	/** Parameter description. */
	lang::String											Description;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_PARAM_
