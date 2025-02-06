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
// Purpose: 'over' namespace includes.
//==============================================================================
#ifndef _SYNKRO_OVER_
#define _SYNKRO_OVER_


#include <over/IOverlayManager.h>
#include <over/IOverlay.h>
#include <over/IFont.h>
#include <over/IPolyLine.h>
#include <over/IQuad.h>
#include <over/ISpritePool.h>
#include <over/ISprite.h>
#include <over/ISpriteAnimationController.h>
#include <over/ITextPool.h>
#include <over/IText.h>
#include <over/ITextAnimationController.h>
#include <over/ITextPoolAnimationController.h>


#define PtrOverlay P(synkro::over::IOverlay)
#define PtrFont P(synkro::over::IFont)
#define PtrSprite P(synkro::over::ISprite)
#define PtrText P(synkro::over::IText)
#define PtrTextAnimationController P(synkro::over::ITextAnimationController)
#define PtrTextPool P(synkro::over::ITextPool)
#define PtrTextPoolAnimationController P(synkro::over::ITextPoolAnimationController)


namespace synkro
{


/**
 * The 'over' namespace contains interfaces
 * for creating on-screen objects like texts and sprites.
 */
namespace over
{
} // over


} // synkro


#endif // _SYNKRO_OVER_
