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
// Purpose: Implements string resources.
//==============================================================================
#include "config.h"
#include <core/Str.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


// Defines resource string.
#define SYNKRO_STR( NAME ) \
		else if ( (_wcsicmp(name, L## #NAME) == 0) && Str::##NAME == nullptr ) Str::##NAME = value


namespace synkro
{


namespace core
{


// General
const Char* Str::UnknownError = nullptr;
const Char* Str::IncompatibleVersion = nullptr;
const Char* Str::DivisionByZero = nullptr;
const Char* Str::NullReference = nullptr;
const Char* Str::OutOfRange = nullptr;
const Char* Str::Done = nullptr;
const Char* Str::CallFail = nullptr;
const Char* Str::ErrorCode = nullptr;
const Char* Str::NotFound = nullptr;
const Char* Str::Initializing = nullptr;
const Char* Str::InitializeFail = nullptr;
const Char* Str::SubsystemDisabled = nullptr;
const Char* Str::InvalidSdkVersion = nullptr;
const Char* Str::InvalidArgument = nullptr;
const Char* Str::InvalidPointer = nullptr;
const Char* Str::InvalidOperation = nullptr;

// I/O
const Char* Str::DirectoryFail = nullptr;
const Char* Str::StreamFail = nullptr;

// Input
const Char* Str::InputDeviceDetected = nullptr;
const Char* Str::JoystickDetected = nullptr;
const Char* Str::JoystickInitFail = nullptr;
const Char* Str::KeyboardDetected = nullptr;
const Char* Str::KeyboardInitFail = nullptr;
const Char* Str::MouseDetected = nullptr;
const Char* Str::MouseInitFail = nullptr;

// Audio
const Char* Str::PlayerDetected = nullptr;
const Char* Str::PlayerCreateFail = nullptr;
const Char* Str::RecorderDetected = nullptr;
const Char* Str::RecorderCreateFail = nullptr;
const Char* Str::SoundEmitterCreateFail = nullptr;
const Char* Str::SoundBufferCreateFail = nullptr;
const Char* Str::VoiceBufferCreateFail = nullptr;
const Char* Str::AudioEffectBindFail = nullptr;

// Graphics
const Char* Str::GraphicsDeviceFail = nullptr;
const Char* Str::RenderWindowFail = nullptr;
const Char* Str::SettingDisplayMode = nullptr;
const Char* Str::DisplayModeFail = nullptr;
const Char* Str::ProgramCompileFail = nullptr;
const Char* Str::ProgramBuildFail = nullptr;
const Char* Str::ProgramBindFail = nullptr;
const Char* Str::WrongProgramParameter = nullptr;
const Char* Str::ProgramParameterFail = nullptr;
const Char* Str::BlendStateCreateFail = nullptr;
const Char* Str::BlendStateBindFail = nullptr;
const Char* Str::DepthStencilStateCreateFail = nullptr;
const Char* Str::DepthStencilStateBindFail = nullptr;
const Char* Str::RasterizerStateCreateFail = nullptr;
const Char* Str::RasterizerStateBindFail = nullptr;
const Char* Str::SamplerStateCreateFail = nullptr;
const Char* Str::SamplerStateBindFail = nullptr;

const Char* Str::NetworkDeviceDetected = nullptr;

void Str::RegisterString( const Char* name, const Char* value )
{
	if ( false ) ;
	SYNKRO_STR( UnknownError );
	SYNKRO_STR( IncompatibleVersion );
	SYNKRO_STR( DivisionByZero );
	SYNKRO_STR( NullReference );
	SYNKRO_STR( OutOfRange );
	SYNKRO_STR( Done );
	SYNKRO_STR( CallFail );
	SYNKRO_STR( ErrorCode );
	SYNKRO_STR( NotFound );
	SYNKRO_STR( Initializing );
	SYNKRO_STR( InitializeFail );
	SYNKRO_STR( SubsystemDisabled );
	SYNKRO_STR( InvalidSdkVersion );
	SYNKRO_STR( InvalidArgument );
	SYNKRO_STR( InvalidPointer );
	SYNKRO_STR( InvalidOperation );

	SYNKRO_STR( DirectoryFail );
	SYNKRO_STR( StreamFail );

	SYNKRO_STR( InputDeviceDetected );
	SYNKRO_STR( JoystickDetected );
	SYNKRO_STR( JoystickInitFail );
	SYNKRO_STR( KeyboardDetected );
	SYNKRO_STR( KeyboardInitFail );
	SYNKRO_STR( MouseDetected );
	SYNKRO_STR( MouseInitFail );

	SYNKRO_STR( PlayerDetected );
	SYNKRO_STR( PlayerCreateFail );
	SYNKRO_STR( RecorderDetected );
	SYNKRO_STR( RecorderCreateFail );
	SYNKRO_STR( SoundEmitterCreateFail );
	SYNKRO_STR( SoundBufferCreateFail );
	SYNKRO_STR( VoiceBufferCreateFail );
	SYNKRO_STR( AudioEffectBindFail );

	SYNKRO_STR( GraphicsDeviceFail );
	SYNKRO_STR( RenderWindowFail );
	SYNKRO_STR( SettingDisplayMode );
	SYNKRO_STR( DisplayModeFail );
	SYNKRO_STR( ProgramCompileFail );
	SYNKRO_STR( ProgramBuildFail );
	SYNKRO_STR( ProgramBindFail );
	SYNKRO_STR( WrongProgramParameter );
	SYNKRO_STR( ProgramParameterFail );
	SYNKRO_STR( BlendStateCreateFail );
	SYNKRO_STR( BlendStateBindFail );
	SYNKRO_STR( DepthStencilStateCreateFail );
	SYNKRO_STR( DepthStencilStateBindFail );
	SYNKRO_STR( RasterizerStateCreateFail );
	SYNKRO_STR( RasterizerStateBindFail );
	SYNKRO_STR( SamplerStateCreateFail );
	SYNKRO_STR( SamplerStateBindFail );
	
	SYNKRO_STR( NetworkDeviceDetected );
}


} // core


} // synkro
