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
// Purpose: Defines scene viewport.
//==============================================================================
#ifndef _SYNKRO_VIEW_IVIEWPORT_
#define _SYNKRO_VIEW_IVIEWPORT_


#include "config.h"
#include <core/IObject.h>
#include <img/Color.h>
#include <lang/Size.h>
#include <lang/Rect.h>
#include <lang/Point.h>
#include <view/ViewMode.h>
#include <view/StereoMode.h>
#include <view/ViewportFilter.h>


namespace synkro
{


namespace view
{


/**
 * Scene viewport.
 */
iface IViewport :
	public core::IObject
{
public:
	/**
	 * Creates viewport controller.
	 * @param animation Optional viewport animation.
	 * @param listener Controller listener.
	 * @return Created controller.
	 */
	virtual IViewportAnimationController*					CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener ) = 0;

	/**
	 * Creates post-processing filter of the given type.
	 * @param type Filter type.
	 * @return Created filter.
	 */
	virtual IViewportFilter*								CreateFilter( const ViewportFilter& type ) = 0;

	/**
	 * Creates custom depth target, if needed, and activates it.
	 * @return Created depth target.
	 */
	virtual IDepthMap*										CreateDepthTarget() = 0;

	/**
	 * Activates viewport.
	 */
	virtual void											Activate() = 0;

	/** 
	 * Enables or disables clipping rectangle.
	 * @param enable Set to true to enable clipping rectangle, set to false to disable it.
	 */
	virtual void											EnableRect( Bool enable ) = 0;

	/**
	 * Sets camera to be used with the viewport.
	 * @param camera Camera used to draw scene to the viewport.
	 */
	virtual void											SetCamera( scene::ICamera* camera ) = 0;

	/**
	 * Sets viewport visualization mode.
	 * @param viewMode New visualization mode.
	 */
	virtual void											SetViewMode( const ViewMode& viewMode ) = 0;

	/**
	 * Sets viewport stereo mode.
	 * @param stereoMode New stereo mode.
	 */
	virtual void											SetStereoMode( const StereoMode& stereoMode ) = 0;

	/**
	 * Sets viewport location.
	 * @param location New viewport location.
	 */
	virtual void											SetLocation( const lang::Point& location ) = 0;

	/**
	 * Sets viewport size.
	 * @param size New viewport size.
	 */
	virtual void											SetSize( const lang::Size& size ) = 0;

	/**
	 * Sets clipping rectangle, in window coordinates.
	 * @param rect Clipping rectangle.
	 */
	virtual void											SetRect( const lang::Rect& rect ) = 0;

	/**
	 * Sets viewport background color.
	 * @param color Color used to clear viewport.
	 */
	virtual void											SetColor( const img::Color& color ) = 0;

	/**
	 * Sets viewport border color.
	 * @param color Viewport border color.
	 */
	virtual void											SetBorderColor( const img::Color& color ) = 0;

	/**
	 * Sets viewport label color.
	 * @param color Viewport label color.
	 */
	virtual void											SetLabelColor( const img::Color& color ) = 0;

	/**
	 * Sets viewport label text.
	 * @param text Viewport label text.
	 */
	virtual void											SetLabelText( const lang::String& text ) = 0;

	/** 
	 * Sets degree of viewport opacity. Valid range is [0.0-1.0]. Default is 1.0.
	 * @param opacity Viewport opacity.
	 */
	virtual void											SetOpacity( Float opacity ) = 0;

	/** 
	 * Controls whether the objects in the viewport are rendered as wireframe.
	 * @param wireframe True to enable wireframe mode, or false to disable it.
	 */
	virtual void											SetWireframe( Bool wireframe ) = 0;

	/** 
	 * Shows or hides viewport border.
	 * @param show True to show viewport border, or false to hide it.
	 */
	virtual void											ShowBorder( Bool show ) = 0;

	/**
	 * Shows or hides viewport label.
	 * @param show True to show viewport label, or false to hide it.
	 */
	virtual void											ShowLabel( Bool show ) = 0;

	/**
	 * Sets viewport visibility.
	 * @param show Set to true to make viewport visible, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/**
	 * Sets mesh drawing pass.
	 * @param mesh Mesh to control.
	 * @param overlay Set to true to draw mesh as viewport overlay, or false to draw it inside the scene.
	 */
	virtual void											MakeOverlay( scene::ITriangleMesh* mesh, Bool overlay ) = 0;

	/**
	 * Picks a mesh node at the given point of the viewport.
	 * @param location Location to test.
	 * @param [out] distance Distance at which picked mesh is located from viewport's camera.
	 * @return Picked node, if one is found, or null otherwise.
	 */
	virtual scene::ITriangleMesh*							PickMesh( const lang::Point& location, Float* distance ) const = 0;

	/** 
	 * Indicates whether the clipping rectangle is enabled.
	 */
	virtual Bool											IsRectEnabled() const = 0;

	/**
	 * Retrieves viewport camera.
	 */
	virtual scene::ICamera*									GetCamera() const = 0;

	/**
	 * Retrieves viewport visualization mode.
	 */
	virtual ViewMode										GetViewMode() const = 0;

	/**
	 * Retrieves viewport stereo mode.
	 */
	virtual StereoMode										GetStereoMode() const = 0;

	/**
	 * Retrieves viewport location.
	 * @param [out] location Viewport location.
	 */
	virtual void											GetLocation( lang::Point& location ) const = 0;

	/**
	 * Retrieves viewport size.
	 * @param [out] size viewport size.
	 */
	virtual void											GetSize( lang::Size& size ) const = 0;

	/**
	 * Retrieves clipping rectangle, in window coordinates.
	 * @param [out] rect Clipping rectangle.
	 */
	virtual void											GetRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves viewport background color.
	 * @param [out] color Viewport background color.
	 */
	virtual void											GetColor( img::Color& color ) const = 0;

	/**
	 * Retrieves viewport border color.
	 * @param [out] color Viewport border color.
	 */
	virtual void											GetBorderColor( img::Color& color ) const = 0;

	/**
	 * Retrieves viewport label color.
	 * @param [out] color Viewport label color.
	 */
	virtual void											GetLabelColor( img::Color& color ) const = 0;

	/**
	 * Retrieves viewport label text.
	 */
	virtual lang::String									GetLabelText() const = 0;

	/** 
	 * Retrieves degree of viewport opacity.
	 */
	virtual Float											GetOpacity() const = 0;

	/** 
	 * Indicates whether the viewport is rendered in wireframe mode.
	 */
	virtual Bool											IsWireframe() const = 0;

	/** 
	 * Indicates whether the viewport border is visible.
	 */
	virtual Bool											IsBorderVisible() const = 0;

	/**
	 * Indicates whether the viewport label is visible.
	 */
	virtual Bool											IsLabelVisible() const = 0;

	/**
	 * Indicates whether the viewport is currently visible.
	 */
	virtual Bool											IsVisible() const = 0;

	/**
	 * Retrieves mesh drawing pass.
	 * @param mesh Mesh to test.
	 */
	virtual Bool											IsOverlay( scene::ITriangleMesh* mesh ) const = 0;

	/**
	 * Retrieves viewport's depth target.
	 */
	virtual IDepthMap*										GetDepthTarget() const = 0;

	/**
	 * Retrieves the number of viewport filters.
	 */
	virtual UInt											GetFilterCount() const = 0;

	/**
	 * Retrieves filter by index.
	 * @param index Index of the filter to retrieve.
	 * @exception OutOfRangeException Index is out of range.
	 * @return Requested filter.
	 */
	virtual IViewportFilter*								GetFilter( UInt index ) const = 0;

	/**
	 * Retrieves underlying rendering view.
	 */
	virtual gfx::IRenderView*								GetView() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IVIEWPORT_
