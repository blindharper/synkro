//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of _image source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: "Prepare image" task.
//==============================================================================
#include "config.h"
#include "PrepareImageTask.h"
#include <img/ImageTypeConst.h>
#include <img/IImage.h>
#include <gfx/ILinearTexture.h>
#include <gfx/IPlainTexture.h>
#include <gfx/ICubeTexture.h>
#include <gfx/IVolumeTexture.h>


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::diag;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


PrepareImageTask::PrepareImageTask( IImage* image, ITexture* texture, ILog* log ) :
	Logger( log, LogFacility::ImageManager ),
	_image( image ),
	_texture( texture )
{
	assert( _texture != nullptr );
}

void PrepareImageTask::Execute()
{
	// Fill texture with image data.
	const UInt elementCount = _image->GetElementCount();
	const UInt imageLevelCount = _image->GetLevelCount();
	switch ( _image->GetType() )
	{
		case IMAGE_TYPE_LINEAR:
			PrepareLinear( elementCount, imageLevelCount );
			break;

		case IMAGE_TYPE_PLAIN:
			PreparePlain( elementCount, imageLevelCount );
			break;

		case IMAGE_TYPE_CUBE:
			PrepareCube( elementCount, imageLevelCount );
			break;

		case IMAGE_TYPE_VOLUME:
			PrepareVolume( elementCount, imageLevelCount );
			break;
	}

	// Generate missing texture levels, if needed.
	if ( (imageLevelCount > 0) && (imageLevelCount < _texture->GetLevelCount()) )
	{
		_texture->GenerateLevels();
	}

	LogInfo( MessagePriority::Low, Formatter::Format(L"Texture from image [{0}] prepared.", _image->ID()) );
}

void PrepareImageTask::Cancel()
{
	// Do nothing.
}

void PrepareImageTask::PrepareLinear( UInt elementCount, UInt imageLevelCount )
{
	LogInfo( MessagePriority::Low, Formatter::Format(L"Preparing linear texture from image [{0}]...", _image->ID()) );

	ILinearTexture* tex = _texture->AsLinear();
	for ( UInt e = 0; e < elementCount; ++e )
	{
		for ( UInt level = 0; level < imageLevelCount; ++level )
		{
			tex->SetData( e, level, _image->GetWidth(level), _image->GetFormat(), _image->GetLevel(e, level) );
		}
	}
}

void PrepareImageTask::PreparePlain( UInt elementCount, UInt imageLevelCount )
{
	LogInfo( MessagePriority::Low, Formatter::Format(L"Preparing plain texture from image [{0}]...", _image->ID()) );

	IPlainTexture* tex = _texture->AsPlain();
	for ( UInt e = 0; e < elementCount; ++e )
	{
		for ( UInt level = 0; level < imageLevelCount; ++level )
		{
			tex->SetData( e, level, _image->GetWidth(level), _image->GetHeight(level), _image->GetStride(level), _image->GetFormat(), _image->GetLevel(e, level) );
		}
	}
}

void PrepareImageTask::PrepareCube( UInt elementCount, UInt imageLevelCount )
{
	LogInfo( MessagePriority::Low, Formatter::Format(L"Preparing cube texture from image [{0}]...", _image->ID()) );

	ICubeTexture* tex = _texture->AsCube();
	for ( UInt f = 0; f < 6; ++f )
	{
		const CubeFace face = CubeFace( f );
		for ( UInt level = 0; level < imageLevelCount; ++level )
		{
			tex->SetData( face, level, _image->GetWidth(level), _image->GetStride(level), _image->GetFormat(), _image->GetLevel(f, level) );
		}
	}
}

void PrepareImageTask::PrepareVolume( UInt elementCount, UInt imageLevelCount )
{
	LogInfo( MessagePriority::Low, Formatter::Format(L"Preparing volume texture from image [{0}]...", _image->ID()) );

	IVolumeTexture* tex = _texture->AsVolume();
	for ( UInt e = 0; e < elementCount; ++e )
	{
		for ( UInt level = 0; level < imageLevelCount; ++level )
		{
			tex->SetData( level, _image->GetWidth(level), _image->GetHeight(level), _image->GetElementCount(), _image->GetStride(level), _image->GetSliceStride(level), _image->GetFormat(), _image->GetLevel(e, level) );
		}
	}
}


} // img


} // synkro
