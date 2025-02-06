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
// Purpose: Main Synkro include file.
//==============================================================================
#ifndef _SYNKRO_
#define _SYNKRO_


#include <cfg/SynkroVersion.h>
#include <anim/anim.h>
#include <audio/audio.h>
#include <cons/cons.h>
#include <core/core.h>
#include <db/db.h>
#include <diag/diag.h>
#include <gfx/gfx.h>
#include <img/img.h>
#include <input/input.h>
#include <io/io.h>
#include <lang/lang.h>
#include <mat/mat.h>
#include <math/math.h>
#include <mem/mem.h>
#include <net/net.h>
#include <over/over.h>
#include <prf/prf.h>
#include <scene/scene.h>
#include <script/script.h>
#include <sound/sound.h>
#include <ui/ui.h>
#include <view/view.h>
#include <win/win.h>


namespace synkro
{


/**
 * Creates Synkro object.
 * Host application should call this function to get access to Synkro framework functionality.
 * To release access, application needs to release object returned by this function.
 * @param version Synkro version, against which the host application is compiled. Should be SYNKRO_VERSION.
 * @param listener Synkro events listener.
 * @return created Synkro object.
 * @exception VersionException Incompatible Synkro version requested.
 */
SYNKRO_API core::ISynkro*									SynkroCreate( UInt version, core::SynkroListener* listener );


} // synkro


#endif // _SYNKRO_
