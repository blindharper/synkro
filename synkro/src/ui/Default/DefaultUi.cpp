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
// Purpose: Default user interface.
//==============================================================================
#include "config.h"
#include "DefaultUi.h"
#include "DefaultAccordion.h"
#include "DefaultAngle.h"
#include "DefaultButton.h"
#include "DefaultDropList.h"
#include "DefaultEdit.h"
#include "DefaultList.h"
#include "DefaultOption.h"
#include "DefaultProgress.h"
#include "DefaultSlider.h"
#include "DefaultSwitch.h"
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IFrameRenderWindowEx.h>
#include <gfx/IOverlayRenderQueue.h>
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IProgramStage.h>
#include <gfx/IParameterSet.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::diag;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::over;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


DefaultUi::DefaultUi( IGraphicsSystemEx* graphicsSystem, IAnimationSystem* animationSystem, IOverlayManager* overlayManager, ITheme* theme, ILog* log ) :
	_graphicsSystem( graphicsSystem ),
	_animationSystem( animationSystem ),
	_overlayManager( overlayManager ),
	_overlay( nullptr ),
	_theme( theme ),
	_font( nullptr ),
	_backColor( Color::Black ),
	Logger( log, LogFacility::UserInterface )
{
	IFrameRenderWindow* window = (IFrameRenderWindow*)graphicsSystem->GetFrameWindow( 0 );
	_overlay = overlayManager->GetOverlay( (IRenderWindow*)window );

	_blendStates = _graphicsSystem->GetDevice()->GetBlendStates()->Clone();
	IBlendState* blenState = _blendStates->Get( 0 );
	blenState->SetSrcMode( BlendMode::SrcAlpha );
	blenState->SetDstMode( BlendMode::InvSrcAlpha );
	blenState->Enable( true );

	_font = _overlay->GetFont( L"ui" );
}

IFrame* DefaultUi::CreateFrame( IFrame* parent, UInt id, const Point& location, const Size& size, Bool showBorder )
{
	DefaultFrame* frame = new DefaultFrame( this, parent, location, size, showBorder );
	if ( parent == nullptr )
	{
		_root = frame;
	}
	return frame;
}

IAccordion* DefaultUi::CreateAccordion( IFrame* parent, UInt id, const Point& location, const Size& size )
{
	return new DefaultAccordion( this, parent, location, size );
}

IAngle* DefaultUi::CreateAngle( IFrame* parent, UInt id, const Point& location, const Color& color )
{
	Rect rect;
	GetTheme()->GetAngleRect( rect );
	return new DefaultAngle( this, parent, location, Size(rect.Width(), rect.Height()), color );
}

IButton* DefaultUi::CreateButton( IFrame* parent, UInt id, const Point& location, const Size& size, const String& text, const Color& color )
{
	return new DefaultButton( this, parent, location, size, text, color );
}

IDropList* DefaultUi::CreateDropList( IFrame* parent, UInt id, const Point& location, const Size& size, UInt capacity )
{
	return new DefaultDropList( this, parent, location, size, capacity );
}

IEdit* DefaultUi::CreateEdit( IFrame* parent, UInt id, const Point& location, const Size& size, const String& text, const EditStyle& style )
{
	return new DefaultEdit( this, parent, location, size, text );
}

IList* DefaultUi::CreateList( IFrame* parent, UInt id, const Point& location, const Size& size, UInt capacity )
{
	return new DefaultList( this, parent, location, size, capacity );
}

IOption* DefaultUi::CreateOption( IFrame* parent, UInt id, const Point& location, const Size& size, const String& text, Bool selected, const Color& color )
{
	return new DefaultOption( this, parent, location, size, text, color );
}

IProgress* DefaultUi::CreateProgress( IFrame* parent, UInt id, const Point& location, const Size& size, const ProgressType& type, const Color& color )
{
	return new DefaultProgress( this, parent, location, size, type, color );
}

ISlider* DefaultUi::CreateSlider( IFrame* parent, UInt id, const Point& location, const Size& size, const Orientation& orientation, UInt minPosition, UInt maxPosition, const Color& color )
{
	return new DefaultSlider( this, parent, location, size, orientation, minPosition, maxPosition, color );
}

ISwitch* DefaultUi::CreateSwitch( IFrame* parent, UInt id, const Point& location, UInt width, const String& text, Bool on, const Color& color )
{
	Size sz; _font->GetTextSize( text, sz );
	return new DefaultSwitch( this, parent, location, Size(width, sz.Height), text, color );
}

void DefaultUi::SetTheme( ITheme* theme )
{
	_theme = theme;
	if ( _root != nullptr )
	{
		_root->SetTheme( _theme );
	}
}

IOverlayRenderObject* DefaultUi::CreateObject( const PrimitiveType& type, const IndexType& indexType, UInt vertexCount, UInt indexCount, UInt order )
{
	IPrimitive* data = _graphicsSystem->GetDevice()->CreatePrimitive( _theme->GetProgram(), DataUsage::Dynamic, DataAccess::WriteOnly, type, indexType, vertexCount, indexCount, 0, 0, true, false );
	IOverlayRenderObject* obj = _graphicsSystem->GetFrameWindow(0)->GetOverlayQueue()->CreateObject( data );
	obj->SetOrder( order );
	obj->SetBlendStates( _blendStates );
	obj->SetFragmentResources( _theme->GetResources() );
	IParameterSet* params = _theme->GetProgram()->GetFragmentStage()->GetParameters()->Clone( obj->ID(), true );
	obj->SetFragmentParameters( params );
	return obj;
}

IOverlayRenderObject* DefaultUi::CreateLineObject( const PrimitiveType& type, UInt vertexCount, UInt order )
{
	IPrimitive* data = _graphicsSystem->GetDevice()->CreatePrimitive( _graphicsSystem->GetProgram(L"overlay.monochrome"), DataUsage::Dynamic, DataAccess::WriteOnly, type, IndexType::None, vertexCount, 0, 0, 0, true, false );
	IOverlayRenderObject* obj = _graphicsSystem->GetFrameWindow(0)->GetOverlayQueue()->CreateObject( data );
	obj->SetOrder( order );
	obj->SetBlendStates( _blendStates );
	obj->SetFragmentResources( _theme->GetResources() );
	IParameterSet* params = _theme->GetProgram()->GetFragmentStage()->GetParameters()->Clone( obj->ID(), true );
	obj->SetFragmentParameters( params );
	return obj;
}

IRect* DefaultUi::CreateScissorRect( Int left, Int top, Int right, Int bottom )
{
	return _graphicsSystem->GetDevice()->CreateScissorRect( left, top, right, bottom );
}


} // ui


} // synkro
