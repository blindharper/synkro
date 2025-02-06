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
// Purpose: Generic user interface widget wrapper implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE WidgetWrapperImpl<T>::WidgetWrapperImpl( BaseUiEx* ui, UInt id, IFrame* parent, IWidget* widget ) :
	_ui( ui ),
	_parent( parent ),
	_widget( widget ),
	_widgetID( id ),
	_hotkey( HotKey::None )
{
	AsBaseFrame( parent )->AddWidget( this );
}

template <class T>
SYNKRO_INLINE WidgetWrapperImpl<T>::~WidgetWrapperImpl()
{
}

template <class T>
SYNKRO_INLINE UInt WidgetWrapperImpl<T>::ID() const
{
	return _widgetID;
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::Activate( Bool activate )
{
	if ( _widget->IsEnabled() )
	{
		_widget->Activate( activate );

		if ( activate )
		{
			_ui->ActivateWidget( AsBaseWidget(this) );
		}
	}
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::Enable( Bool enable )
{
	_widget->Enable( enable );
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::Show( Bool show )
{
	_widget->Show( show );
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::SetOpacity( Float opacity )
{
	_widget->SetOpacity( opacity );
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::SetLocation( const lang::Point& location )
{
	_widget->SetLocation( location );
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::SetSize( const lang::Size& size )
{
	_widget->SetSize( size );
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::SetHotKey( const HotKey& key )
{
	_ui->RegisterHotKey( _hotkey = key );
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::SetAnchor( const Anchor& anchor )
{
	_widget->SetAnchor( anchor );
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::SetZOrder( UInt order )
{
	_widget->SetZOrder( order );
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::SetTabOrder( UInt order )
{
	_widget->SetTabOrder( order );
	AsBaseFrame( _parent )->UpdateTabOrder();
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::SetData( Pointer data )
{
	_widget->SetData( data );
}

template <class T>
SYNKRO_INLINE Bool WidgetWrapperImpl<T>::IsActive() const
{
	return _widget->IsActive();
}

template <class T>
SYNKRO_INLINE Bool WidgetWrapperImpl<T>::IsEnabled() const
{
	return _widget->IsEnabled();
}

template <class T>
SYNKRO_INLINE Bool WidgetWrapperImpl<T>::IsVisible() const
{
	return _widget->IsVisible();
}

template <class T>
SYNKRO_INLINE Float WidgetWrapperImpl<T>::GetOpacity() const
{
	return _widget->GetOpacity();
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::GetLocation( lang::Point& location ) const
{
	_widget->GetLocation( location );
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::GetSize( lang::Size& size ) const
{
	_widget->GetSize( size );
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::GetRect( lang::Rect& rect ) const
{
	_widget->GetRect( rect );
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::GetVisibleRect( lang::Rect& rect ) const
{
	_widget->GetVisibleRect( rect );
}

template <class T>
SYNKRO_INLINE void WidgetWrapperImpl<T>::GetHotKey( HotKey& key ) const
{
	key = _hotkey;
}

template <class T>
SYNKRO_INLINE Anchor WidgetWrapperImpl<T>::GetAnchor() const
{
	return _widget->GetAnchor();
}

template <class T>
SYNKRO_INLINE UInt WidgetWrapperImpl<T>::GetZOrder() const
{
	return _widget->GetZOrder();
}

template <class T>
SYNKRO_INLINE UInt WidgetWrapperImpl<T>::GetTabOrder() const
{
	return _widget->GetTabOrder();
}

template <class T>
SYNKRO_INLINE Pointer WidgetWrapperImpl<T>::GetData() const
{
	return _widget->GetData();
}

template <class T>
SYNKRO_INLINE CursorType WidgetWrapperImpl<T>::GetCursor() const
{
	return _widget->GetCursor();
}

template <class T>
SYNKRO_INLINE IFrame* WidgetWrapperImpl<T>::GetParent() const
{
	return _parent;
}

template <class T>
SYNKRO_INLINE IAngle* WidgetWrapperImpl<T>::AsAngle() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IButton* WidgetWrapperImpl<T>::AsButton() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IDropList* WidgetWrapperImpl<T>::AsDropList() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IEdit* WidgetWrapperImpl<T>::AsEdit() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ILabel* WidgetWrapperImpl<T>::AsLabel() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IList* WidgetWrapperImpl<T>::AsList() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IOption* WidgetWrapperImpl<T>::AsOption() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IPicture* WidgetWrapperImpl<T>::AsPicture() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IProgress* WidgetWrapperImpl<T>::AsProgress() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ISlider* WidgetWrapperImpl<T>::AsSlider() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ISwitch* WidgetWrapperImpl<T>::AsSwitch() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE Bool WidgetWrapperImpl<T>::IsHot( const HotKey& key ) const
{
	return (key == _hotkey);
}
