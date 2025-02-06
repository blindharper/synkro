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
// Purpose: 'view' namespace includes.
//==============================================================================
#ifndef _SYNKRO_VIEW_
#define _SYNKRO_VIEW_


#include <view/IColorFilter.h>
#include <view/IColorFilterAnimationController.h>
#include <view/IKernel3x3Filter.h>
#include <view/IKernel3x3FilterAnimationController.h>
#include <view/IEmbossFilter.h>
#include <view/IEmbossFilterAnimationController.h>
#include <view/IFogFilter.h>
#include <view/IFogFilterAnimationController.h>
#include <view/IDepthMap.h>
#include <view/IMotionBlurFilter.h>
#include <view/ISimpleFilter.h>
#include <view/ISimpleFilterAnimationController.h>
#include <view/IViewport.h>
#include <view/IViewportManager.h>
#include <view/IViewportAnimationController.h>
#include <view/IViewportFilter.h>
#include <view/IViewportFilterFactory.h>
#include <view/IViewportTransitionController.h>
#include <view/ViewportFilter.h>
#include <view/ViewportListener.h>


#define PtrEmbossFilter P(synkro::view::IEmbossFilter)
#define PtrFogFilter P(synkro::view::IFogFilter)
#define PtrFogFilterAnimationController P(synkro::view::IFogFilterAnimationController)
#define PtrKernel3x3Filter P(synkro::view::IKernel3x3Filter)
#define PtrSimpleFilter P(synkro::view::ISimpleFilter)
#define PtrViewport P(synkro::view::IViewport)
#define PtrViewportAnimationController P(synkro::view::IViewportAnimationController)
#define PtrViewportFilter P(synkro::view::IViewportFilter)
#define PtrViewportTransitionController P(synkro::view::IViewportTransitionController)


namespace synkro
{


/**
 * The 'view' namespace contains interfaces
 * used to create viewports through which
 * the 3D scenes are shown to the viewer.
 */
namespace view
{
} // view


} // synkro


#endif // _SYNKRO_VIEW_
