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
// Purpose: Viewport implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_VIEWPORT_
#define _SYNKRO_VIEW_VIEWPORT_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/IContext.h>
#include <view/IViewport.h>
#include <view/IViewportAnimationController.h>
#include <view/IViewportFilter.h>
#include <lang/Vector.h>
#include <gfx/IRect.h>
#include <gfx/IRenderView.h>
#include <gfx/IRenderWindow.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <gfx/IParameterSet.h>
#include <gfx/IPlainDepthTexture.h>
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IGraphicsSystemEx.h>
#include <scene/IScene.h>
#include <scene/ICamera.h>
#include <over/IText.h>
#include <over/IPolyLine.h>
#include <scene/BaseScene.h>
#include <view/Filter/Depth/DepthMap.h>
#include "BaseViewportManager.h"


namespace synkro
{


namespace view
{


// Viewport implementation.
class Viewport :
	public core::ObjectImpl<IViewport>,
	public BaseViewport
{
public:
	// Constructor & destructor.
	Viewport( BaseViewportManager* viewportManager, core::IContext* context, gfx::IRenderView* view, scene::ICamera* camera );
	~Viewport();

	// IViewport methods.
	IViewportAnimationController*							CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	IViewportFilter*										CreateFilter( const ViewportFilter& type );
	IDepthMap*												CreateDepthTarget();
	void													Activate();
	void													EnableRect( Bool enable );
	void													SetCamera( scene::ICamera* camera );
	void													SetViewMode( const ViewMode& viewMode );
	void													SetStereoMode( const StereoMode& stereoMode );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetRect( const lang::Rect& rect );
	void													SetColor( const img::Color& color );
	void													SetBorderColor( const img::Color& color );
	void													SetLabelColor( const img::Color& color );
	void													SetLabelText( const lang::String& text );
	void													SetOpacity( Float opacity );
	void													SetWireframe( Bool wireframe );
	void													ShowBorder( Bool show );
	void													ShowLabel( Bool show );
	void													Show( Bool show );
	void													MakeOverlay( scene::ITriangleMesh* mesh, Bool overlay );
	scene::ITriangleMesh*									PickMesh( const lang::Point& location, Float* distance ) const;
	Bool													IsRectEnabled() const;
	scene::ICamera*											GetCamera() const;
	ViewMode												GetViewMode() const;
	StereoMode												GetStereoMode() const;
	void													GetLocation( lang::Point& location ) const;
	void													GetSize( lang::Size& size ) const;
	void													GetRect( lang::Rect& rect ) const;
	void													GetColor( img::Color& color ) const;
	void													GetBorderColor( img::Color& color ) const;
	void													GetLabelColor( img::Color& color ) const;
	lang::String											GetLabelText() const;
	Float													GetOpacity() const;
	Bool													IsWireframe() const;
	Bool													IsBorderVisible() const;
	Bool													IsLabelVisible() const;
	Bool													IsVisible() const;
	Bool													IsOverlay( scene::ITriangleMesh* mesh ) const;
	IDepthMap*												GetDepthTarget() const;
	UInt													GetFilterCount() const;
	IViewportFilter*										GetFilter( UInt index ) const;
	gfx::IRenderView*										GetView() const;

	// BaseViewport methods.
	void													AddFilter( IViewportFilter* filter );
	void													RemoveFilter( IViewportFilter* filter );
	void													SetActive( Bool active );
	void													Update();
	IViewport*												AsViewport() const;

	// Other methods.
	Bool													Call( IViewportFilter* filter );

private:
	struct ViewParams
	{
		ViewParams() :
			ParamView( nullptr ),
			ParamProj( nullptr ),
			ParamWorldView( nullptr ),
			ParamWorldViewProj( nullptr ),
			ParamInvWorldViewProj( nullptr )
		{
		}

		void Init( gfx::IParameterSet* params )
		{
			Params = params;
			if ( Params != nullptr )
			{
				ParamView				= Params->GetParam( L"sp_view" );
				ParamProj				= Params->GetParam( L"sp_proj" );
				ParamWorldView			= Params->GetParam( L"sp_worldView" );
				ParamWorldViewProj		= Params->GetParam( L"sp_worldViewProj" );
				ParamInvWorldViewProj	= Params->GetParam( L"sp_invWorldViewProj" );
			}
		}

		void Set( const math::Matrix4x4& transView, const math::Matrix4x4& transProj )
		{
			const math::Matrix4x4 transWorldView = transView;
			const math::Matrix4x4 transWorldViewProj = transProj * transWorldView;
			const math::Matrix4x4 transInvWorldViewProj = transWorldViewProj.Inverse();
			Params->Set( ParamView, transView );
			Params->Set( ParamProj, transProj );
			Params->Set( ParamWorldView, transWorldView );
			Params->Set( ParamWorldViewProj, transWorldViewProj );
			Params->Set( ParamInvWorldViewProj, transInvWorldViewProj );
		}

		P(gfx::IParameterSet)	Params;
		gfx::ProgramParam*		ParamView;
		gfx::ProgramParam*		ParamProj;
		gfx::ProgramParam*		ParamWorldView;
		gfx::ProgramParam*		ParamWorldViewProj;
		gfx::ProgramParam*		ParamInvWorldViewProj;
	};

	BaseViewportManager*									_viewportManager;
	core::IContext*											_context;
	P(IViewportAnimationController)							_ctrlAnimation;
	lang::Vector<IViewportFilter*>							_filters;
	P(gfx::IProgram)										_program;
	P(gfx::IRenderView)										_view;
	IViewportFilter*										_alphaFilter;
	IDepthFilter*											_depthFilter;	
	P(DepthMap)												_depthTarget;
	P(scene::ICamera)										_camera;
	P(over::IText)											_label;
	img::Color												_labelColor;
	lang::String											_labelText;
	Bool													_labelVisible;
	P(over::IPolyLine)										_border;
	img::Color												_borderColor;
	Bool													_borderVisible;
	ViewMode												_viewMode;
	StereoMode												_stereoMode;
	lang::Point												_location;
	mutable lang::Size										_size;
	lang::Rect												_rect;
	P(gfx::IRect)											_scissor;
	Bool													_boundsDirty;
	ViewParams												_paramsLeft;
	ViewParams												_paramsRight;
};


#include "Viewport.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_VIEWPORT_
