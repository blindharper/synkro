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
#include "config.h"
#include "ParamTypeConst.h"
#include <core/Param.h>
#include <math/Math.h>
#include <ui/UiType.h>
#include <win/WindowSystem.h>
#include <audio/AudioSystem.h>
#include <db/DatabaseSystem.h>
#include <gfx/DisplayMode.h>
#include <gfx/GraphicsSystem.h>
#include <input/InputSystem.h>
#include <net/NetworkSystem.h>
#include <script/ScriptSystem.h>
#include <sound/SoundFormat.h>
#include <io/StreamSystem.h>
#include <win/WindowSystem.h>
#include <internal/Enum.h>
#include <internal/Zero.h>
#include <internal/SizeOf.h>


// Defines configuration parameter name.
#define SYNKRO_PARAM( PARAM, VALUE ) \
		const Char* Param::PARAM = L##VALUE;

// Defines configuration parameter with the specified name, type, label and description.
#define P1( PARAM, TYPE, DESCRIPTION ) \
		  { Param::##PARAM, ParamType::##TYPE, ParamConstraint::None, L"", L"", L##DESCRIPTION },

// Defines configuration parameter with a default value.
#define P2( PARAM, TYPE, DEFAULT, DESCRIPTION ) \
		  { Param::##PARAM, ParamType::##TYPE, ParamConstraint::None, L##DEFAULT, L"", L##DESCRIPTION },

// Defines configuration parameter with a constraint.
#define P3( PARAM, TYPE, CONSTRAINT, DEFAULT, DESCRIPTION ) \
		  { Param::##PARAM, ParamType::##TYPE, ParamConstraint::##CONSTRAINT, L##DEFAULT, L"", L##DESCRIPTION },

// Defines configuration parameter with internal data and no constraints.
#define P4( PARAM, TYPE, DEFAULT, DATA, DESCRIPTION ) \
		  { Param::##PARAM, ParamType::##TYPE, ParamConstraint::None, L##DEFAULT, L##DATA, L##DESCRIPTION },


namespace synkro
{


namespace core
{


Param::Param( const lang::String& name, const ParamType type, const ParamConstraint constraints, const lang::String& defaultValue, const lang::String& data, const lang::String& description ) :
	Name( name ), Type( type ), Constraints( constraints ), DefaultValue( defaultValue ), Data( data ), Description( description )
{
}

Param::Param() :
	Name( L"" ), Type( ParamType::String ), Constraints( ParamConstraint::None ), DefaultValue( L"" ), Data( L"" ), Description( L"" )
{
}


// Configuration parameter definition.
struct ParamDef
{
	const Char*		name;
	ParamType		type;
	ParamConstraint	constraints;
	const Char*		defaultValue;
	const Char*		data;
	const Char*		description;
};


// Anim
SYNKRO_PARAM( AnimationEnable,			"Animation.Enable" )

// Audio
SYNKRO_PARAM( AudioEnable,				"Audio.Enable" )
SYNKRO_PARAM( AudioSystem,				"Audio.System" )
SYNKRO_PARAM( AudioFormat,				"Audio.Format" )

// Console
SYNKRO_PARAM( ConsoleEnable,			"Console.Enable" )

// Core
SYNKRO_PARAM( CoreThreadPoolCapacity,	"Core.Thread.PoolCapacity" )

// Db
SYNKRO_PARAM( DatabaseEnable,			"Database.Enable" )
SYNKRO_PARAM( DatabaseSystem,			"Database.System" )

// Graphics
SYNKRO_PARAM( GraphicsSystem,			"Graphics.System" )
SYNKRO_PARAM( GraphicsDevice,			"Graphics.Device" )
SYNKRO_PARAM( GraphicsDepthFormat,		"Graphics.DepthFormat" )
SYNKRO_PARAM( GraphicsDisplayMode,		"Graphics.DisplayMode" )
SYNKRO_PARAM( GraphicsFullscreen,		"Graphics.Fullscreen" )
SYNKRO_PARAM( GraphicsVsync,			"Graphics.Vsync" )
SYNKRO_PARAM( GraphicsSampleCount,		"Graphics.Sample.Count" )
SYNKRO_PARAM( GraphicsSampleQuality,	"Graphics.Sample.Quality" )
SYNKRO_PARAM( GraphicsProgramCache,		"Graphics.ProgramCache" )
SYNKRO_PARAM( GraphicsProgramLibrary,	"Graphics.ProgramLibrary" )
SYNKRO_PARAM( GraphicsProgramPreload,	"Graphics.ProgramPreload" )

// Imaging
SYNKRO_PARAM( ImagingEnable,			"Imaging.Enable" )
SYNKRO_PARAM( ImagingCodecQuality,		"Imaging.Codec.Quality" )

// Input
SYNKRO_PARAM( InputEnable,				"Input.Enable" )
SYNKRO_PARAM( InputSystem,				"Input.System" )

// Log
SYNKRO_PARAM( LogLevel,					"Log.Level" )
SYNKRO_PARAM( LogMode,					"Log.Mode" )
SYNKRO_PARAM( LogFileName,				"Log.File.Name" )
SYNKRO_PARAM( LogFilePlain,				"Log.File.Plain" )
SYNKRO_PARAM( LogFileAppend,			"Log.File.Append" )
SYNKRO_PARAM( LogFileMaxSize,			"Log.File.MaxSize" )

// Net
SYNKRO_PARAM( NetworkEnable,			"Network.Enable" )
SYNKRO_PARAM( NetworkSystem,			"Network.System" )

// Script
SYNKRO_PARAM( ScriptEnable,				"Script.Enable" )
SYNKRO_PARAM( ScriptSystem,				"Script.System" )

// Stream
SYNKRO_PARAM( StreamSystem,				"Stream.System" )
SYNKRO_PARAM( StreamPath,				"Stream.Path" )

// Ui
SYNKRO_PARAM( UiEnable,					"Ui.Enable" )
SYNKRO_PARAM( UiType,					"Ui.Type" )
SYNKRO_PARAM( UiTheme,					"Ui.Theme" )
SYNKRO_PARAM( UiThemeName,				"Ui.Theme.Name" )
SYNKRO_PARAM( UiFontSize,				"Ui.Font.Size" )
SYNKRO_PARAM( UiColorWidgetNormal,		"Ui.Color.Widget.Normal" )
SYNKRO_PARAM( UiColorTextNormal,		"Ui.Color.Text.Normal" )
SYNKRO_PARAM( UiColorWidgetActive,		"Ui.Color.Widget.Active" )
SYNKRO_PARAM( UiColorTextActive,		"Ui.Color.Text.Active" )
SYNKRO_PARAM( UiColorWidgetHovered,		"Ui.Color.Widget.Hovered" )
SYNKRO_PARAM( UiColorTextHovered,		"Ui.Color.Text.Hovered" )
SYNKRO_PARAM( UiColorWidgetDisabled,	"Ui.Color.Widget.Disabled" )
SYNKRO_PARAM( UiColorTextDisabled,		"Ui.Color.Text.Disabled" )

// View
SYNKRO_PARAM( ViewStereoMode,			"View.StereoMode" )

// Win
SYNKRO_PARAM( WindowSystem,				"Window.System" )


// We have to define ParamType and ParamConstraint constants here
// to guarantee that ParamType is initialized before ParamConstraint.
SYNKRO_DEFINE_CONST( ParamType, String,			PARAM_TYPE_STRING )
SYNKRO_DEFINE_CONST( ParamType, List,			PARAM_TYPE_LIST )
SYNKRO_DEFINE_CONST( ParamType, Integer,		PARAM_TYPE_INTEGER )
SYNKRO_DEFINE_CONST( ParamType, Boolean,		PARAM_TYPE_BOOLEAN )
SYNKRO_DEFINE_CONST( ParamType, Flag,			PARAM_TYPE_FLAG )
SYNKRO_DEFINE_CONST( ParamType, Enumeration,	PARAM_TYPE_ENUMERATION )
SYNKRO_DEFINE_CONST( ParamType, Color,			PARAM_TYPE_COLOR )


SYNKRO_DEFINE_CONST( ParamConstraint, None,		0x00 )
SYNKRO_DEFINE_CONST( ParamConstraint, NonEmpty,	0x01 )
SYNKRO_DEFINE_CONST( ParamConstraint, Positive,	0x02 )


// Parameter initializer.
class Init
{
public:
	enum
	{
		BUFFER_SIZE = 4096
	};

	Char DisplayModes[BUFFER_SIZE];
	Char SoundFormats[BUFFER_SIZE];
	const Char* DefaultAudioSystem;
	const Char* DefaultDatabaseSystem;
	const Char* DefaultGraphicsSystem;
	const Char* DefaultStreamSystem;
	const Char* DefaultInputSystem;
	const Char* DefaultNetworkSystem;
	const Char* DefaultScriptSystem;
	const Char* DefaulWindowSystem;

	Float GetAspect( UInt width, UInt height )
	{
		const Float aspect = CastFloat(width)/CastFloat(height);
		return 0.01f*math::Math::Round( 100.0f*aspect );
	}

	Float GetAspect( const gfx::DisplayMode& mode )
	{
		return GetAspect( mode.Width, mode.Height );
	}

	Init()
	{
		Char buf[64] = {};
		Char aspect[64] = {};

		gfx::DisplayMode mode;
		Zero( DisplayModes, BUFFER_SIZE );
		static Float aspects[] =
		{
			GetAspect(2, 1),
			GetAspect(3, 2),
			GetAspect(4, 3),
			GetAspect(5, 4),
			GetAspect(8, 5),
			GetAspect(16, 9),
		};
		static const Char* strAspects[] =
		{
			L"2:1",
			L"3:2",
			L"4:3",
			L"5:4",
			L"8:5",
			L"16:9",
		};
		for ( UInt i = 0; i < gfx::DisplayMode::GetModeCount(); ++i )
		{
			gfx::DisplayMode::GetMode( i, mode );

			Zero( aspect, 64 );
			Float modeAspect = GetAspect( mode );

			Float diffMin = math::Math::MaxFloat;
			constexpr UInt cnt = SizeOf( aspects );
			for ( UInt a = 0; a < cnt; ++a )
			{
				const Float diff = math::Math::Abs( aspects[a] - modeAspect );
				if ( diff < diffMin )
				{
					diffMin = diff;
					wcscpy( aspect, strAspects[a] );
				}
			}

			if ( i > 0 )
			{
				wcscat( DisplayModes, L"|" );
			}
			swprintf_s( buf, 64, L"%dx%dx%d (%s)", mode.Width, mode.Height, mode.Depth, aspect );
			wcscat( DisplayModes, buf );
		}

		sound::SoundFormat fmt;
		Zero( SoundFormats, BUFFER_SIZE );
		for ( UInt i = 0; i < sound::SoundFormat::GetFormatCount(); ++i )
		{
			UInt sampleRate = 0;
			sound::SoundFormat::GetFormat( i, fmt );
			switch ( fmt.SamplesPerSecond )
			{
				case 11025:	sampleRate = 11; break;
				case 22050:	sampleRate = 22; break;
				case 44100:	sampleRate = 44; break;
			}
			swprintf_s( buf, 64, (i == 0) ? L"%dkHz%dbit%dCh" : L"|%dkHz%dbit%dCh", sampleRate, fmt.BitsPerSample, fmt.ChannelCount );
			wcscat( SoundFormats, buf );
		}

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
		DefaultGraphicsSystem	= L"DirectX11";
		DefaultAudioSystem		= L"DirectSound8";
		DefaultStreamSystem		= L"Win32";
		DefaultInputSystem		= L"Win32";
		DefaultNetworkSystem	= L"WinSock2";
		DefaulWindowSystem		= L"Win32";
#else
		DefaultAudioSystem		= L"OpenAL";
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
		DefaultDatabaseSystem	= L"Sqlite";
		DefaultScriptSystem		= L"Lua";
	}
} L_init;

// Standard configuration parameter map.
ParamDef _stdParams[] =
{
#include "Param.inl"
};


// Returns the total number of standard parameters.
UInt GetStdParamCount()
{
	return SizeOf( _stdParams );
}

// Returns a standard parameter by index.
Bool GetStdParam( UInt i, Param* param )
{
	if ( i < GetStdParamCount() )
	{
		const ParamDef& p = _stdParams[i];

		param->Name				= p.name;
		param->Type				= p.type;
		param->Constraints		= p.constraints;
		param->DefaultValue		= p.defaultValue;
		param->Data				= p.data;
		param->Description		= p.description;

		return true;
	}
	return false;
}


} // core


} // synkro
