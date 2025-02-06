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
// Purpose: "Prepare image" task.
//==============================================================================
#ifndef _SYNKRO_IMG_PREPAREIMAGETASK_
#define _SYNKRO_IMG_PREPAREIMAGETASK_


#include "config.h"
#include <core/Task.h>
#include <lang/Formatter.h>
#include <internal/Logger.h>


namespace synkro
{


namespace img
{


// Image preparer.
class PrepareImageTask :
	public core::Task,
	public Logger
{
public:
	// Constructor.
	PrepareImageTask( IImage* image, gfx::ITexture* texture, diag::ILog* log );

	// Task methods.
	void													Execute();
	void													Cancel();

private:
	IImage*													_image;
	gfx::ITexture*											_texture;

	void													PrepareLinear( UInt elementCount, UInt imageLevelCount );
	void													PreparePlain( UInt elementCount, UInt imageLevelCount );
	void													PrepareCube( UInt elementCount, UInt imageLevelCount );
	void													PrepareVolume( UInt elementCount, UInt imageLevelCount );
};


} // img


} // synkro


#endif // _SYNKRO_IMG_PREPAREIMAGETASK_
