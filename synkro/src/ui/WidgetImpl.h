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
// Purpose: Generic user interface widget implementation.
//==============================================================================
#ifndef _SYNKRO_UI_WIDGETIMPL_
#define _SYNKRO_UI_WIDGETIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <lang/Vector.h>
#include <img/IImage.h>
#include <over/IFont.h>
#include <over/IQuad.h>
#include <over/IText.h>
#include <over/ITextPool.h>
#include <over/ITextAnimationController.h>
#include <over/IOverlay.h>
#include <ui/IFrame.h>
#include <ui/IWidget.h>
#include <ui/ICursor.h>
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IProgram.h>
#include <gfx/IParameterSet.h>
#include <gfx/IGraphicsDevice.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IVector2Stream.h>
#include <gfx/IVector4Stream.h>
#include <gfx/IShortStream.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/DataStream.h>
#include "BaseUi.h"
#include "BaseFrame.h"
#include "WidgetEffect.h"


namespace synkro
{


namespace ui
{


// Generic user interface widget implementation.
template <class T>
class WidgetImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor and destructor.
	WidgetImpl( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size );
	virtual ~WidgetImpl();

	// IWidget methods.
	virtual	void											Activate( Bool activate );
	virtual	void											Enable( Bool enable );
	virtual	void											Show( Bool show );
	virtual void											SetOpacity( Float opacity );
	virtual void											SetLocation( const lang::Point& location );
	virtual void											SetSize( const lang::Size& size );
	virtual void											SetHotKey( const HotKey& key );
	virtual void											SetAnchor( const Anchor& anchor );
	virtual void											SetZOrder( UInt order );
	virtual void											SetTabOrder( UInt order );
	virtual void											SetData( Pointer data );
	virtual Bool											IsActive() const;
	virtual Bool											IsEnabled() const;
	virtual Bool											IsVisible() const;
	virtual Float											GetOpacity() const;
	virtual void											GetLocation( lang::Point& location ) const;
	virtual void											GetSize( lang::Size& size ) const;
	virtual void											GetRect( lang::Rect& rect ) const;
	virtual void											GetVisibleRect( lang::Rect& rect ) const;
	virtual void											GetHotKey( HotKey& key ) const;
	virtual Anchor											GetAnchor() const;
	virtual UInt											GetZOrder() const;
	virtual UInt											GetTabOrder() const;
	virtual Pointer											GetData() const;
	virtual CursorType										GetCursor() const;
	virtual IFrame*											GetParent() const;
	virtual IAngle*											AsAngle() const;
	virtual IButton*										AsButton() const;
	virtual IDropList*										AsDropList() const;
	virtual IEdit*											AsEdit() const;
	virtual ILabel*											AsLabel() const;
	virtual IList*											AsList() const;
	virtual IOption*										AsOption() const;
	virtual IPicture*										AsPicture() const;
	virtual IProgress*										AsProgress() const;
	virtual ISlider*										AsSlider() const;
	virtual ISwitch*										AsSwitch() const;

protected:
	BaseUi*													_ui;
	IFrame*													_parent;
	P(over::IText)											_text;
	img::Color												_color;
	Float													_opacity;
	lang::Point												_location;
	lang::Size												_size;
	lang::Rect												_rect;
	lang::Rect												_visibleRect;
	Anchor													_anchor;
	UInt													_zOrder;
	UInt													_tabOrder;
	Pointer													_data;
	Bool													_active;
	Bool													_enabled;
	Bool													_visible;
	CursorType												_cursor;
	P(gfx::IOverlayRenderObject)							_object;
	P(gfx::IOverlayRenderObject)							_object2;
	P(gfx::IOverlayRenderObject)							_object3;
	gfx::ProgramParam*										_paramColor;
	gfx::ProgramParam*										_paramColor2;
	gfx::ProgramParam*										_paramColor3;
	P(gfx::IRect)											_scissorRect;
	P(WidgetEffect)											_effect;

	void													SetIndices( gfx::IOverlayRenderObject* object, const UShort* data, UInt start, UInt count );
	void													SetIndicesCentered( gfx::IOverlayRenderObject* object );
	void													SetPositions( gfx::IOverlayRenderObject* object, const math::Vector4* data, UInt start, UInt count );
	void													SetPositions( const math::Vector4* data, UInt start, UInt count );
	void													SetPositions2( const math::Vector4* data, UInt start, UInt count );
	void													SetPositions( gfx::IOverlayRenderObject* object, const lang::Point& location, const lang::Size& size, const lang::Rect& rect, const lang::Rect& center );
	void													SetTextureCoordinates( gfx::IOverlayRenderObject* object, const math::Vector2* data, UInt start, UInt count );
	void													SetTextureCoordinates( const math::Vector2* data, UInt start, UInt count );
	void													SetTextureCoordinates2( const math::Vector2* data, UInt start, UInt count );
	void													SetTextureCoordinates( gfx::IOverlayRenderObject* object, const lang::Rect& rect, const lang::Rect& center );
	void													SetColor( const img::Color& color, Bool update = true );
	void													CalcRect();
};


#include "WidgetImpl.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_WIDGETIMPL_
