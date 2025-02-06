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
#ifndef _SYNKRO_CORE_CONFIGURATIONEDITOR_
#define _SYNKRO_CORE_CONFIGURATIONEDITOR_


#include "config.h"
#include <lang/Ptr.h>
#include <view/IViewport.h>


namespace synkro
{


namespace core
{


// Configuration editor.
class ConfigurationEditor
{
public:
	static void												Initialize( Pointer module, ISynkro* synkro );
	static void												Show( IConfiguration* config );
	static void												Finalize();
	static Bool												GetResult();

private:
	static ISynkro*											_synkro;
	static P(view::IViewport)								_banner;
	static P(view::IViewport)								_preview;

	static void												Run0();
	static void												Run1();
	static void												Run2();
	static void												Run3();
};


} // core


} // synkro


#endif // _SYNKRO_CORE_CONFIGURATIONEDITOR_
