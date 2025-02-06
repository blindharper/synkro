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
// Purpose: Logical configuration editor.
//==============================================================================
#include "config.h"
#include "ConfigurationEditor.h"
#include "ConfigurationBanner.h"
#include "ConfigurationScene/PointMeshConfigurationScene.h"
#include "ConfigurationScene/RubikCubeConfigurationScene.h"
#include "ConfigurationScene/ProjectorsConfigurationScene.h"
#include "ConfigurationScene/TesseractConfigurationScene.h"
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	#include "Win32/Win32ConfigurationEditor.h"
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
#include <view/IViewportManager.h>
#include <win/IWindowSystemEx.h>
#include <win/IFrameWindowEx.h>
#include <core/ISynkro.h>
#include <lang/Random.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


ISynkro* ConfigurationEditor::_synkro = nullptr;
P(view::IViewport) ConfigurationEditor::_banner;
P(view::IViewport) ConfigurationEditor::_preview;


void ConfigurationEditor::Initialize( Pointer module, ISynkro* synkro )
{
	_synkro = synkro;

	Pointer handle = 0;
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	handle = Win32ConfigurationEditor::Initialize( module, synkro );
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

	// Create preview pane.
	win::IFrameWindow* dlg = _synkro->GetWindowSystem()->CreateWindow( handle );
	Float scale = CastFloat(dlg->GetDpi()) / 96.0f; // Config dialog is designed on a screen with 96 DPI.
	_synkro->GetWindowSystem()->CreateWindow( _synkro->GetWindowSystem()->GetFrameWindow(0), scale*12, scale*12, scale*690, scale*48 );
	_synkro->GetWindowSystem()->CreateWindow( _synkro->GetWindowSystem()->GetFrameWindow(0), scale*12, scale*72, scale*267, scale*267 );
}

void ConfigurationEditor::Show( IConfiguration* config )
{
	_banner = _synkro->GetViewportManager()->GetViewport( CastUInt(0) );
	_preview = _synkro->GetViewportManager()->GetViewport( CastUInt(1) );

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	Win32ConfigurationEditor::Show( config );
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

	ConfigurationBanner banner( _synkro );
	Random rnd;
	switch ( rnd.GetInt(4) )
	{
		case 0: Run0(); break;
		case 1: Run1(); break;
		case 2: Run2(); break;
		case 3: Run3(); break;
		default:
			Bool run = true;
			_synkro->Run( run );
			break;
	}
}

void ConfigurationEditor::Finalize()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	Win32ConfigurationEditor::Finalize();
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

	_banner = nullptr;
	_preview = nullptr;
}

Bool ConfigurationEditor::GetResult()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	return Win32ConfigurationEditor::GetResult();
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

void ConfigurationEditor::Run0()
{
	PointMeshConfigurationScene scene( _synkro );
	Bool run = true; _synkro->Run( run );
}

void ConfigurationEditor::Run1()
{
	RubikCubeConfigurationScene scene( _synkro );
	Bool run = true; _synkro->Run( run );
}

void ConfigurationEditor::Run2()
{
	ProjectorsConfigurationScene scene( _synkro );
	Bool run = true; _synkro->Run( run );
}

void ConfigurationEditor::Run3()
{
	TesseractConfigurationScene scene( _synkro );
	Bool run = true; _synkro->Run( run );
}


} // core


} // synkro
