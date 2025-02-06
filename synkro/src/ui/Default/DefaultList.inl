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
// Purpose: Default list widget implementation.
//==============================================================================
SYNKRO_INLINE void DefaultList::Activate( Bool activate )
{
	// Call base implementation.
	WidgetImpl<IList>::Activate( activate );

	img::Color color; _ui->Theme()->GetWidgetColor( activate ? WidgetState::Normal : WidgetState::Disabled, color );
	_highlight->SetColor( color );
}

SYNKRO_INLINE void DefaultList::Enable( Bool enable )
{
	// Call base implementation.
	WidgetImpl<IList>::Enable( enable );

	img::Color color; _ui->Theme()->GetWidgetColor( _enabled ? WidgetState::Normal : WidgetState::Disabled, color );
	_highlight->SetColor( color );
}

SYNKRO_INLINE void DefaultList::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetImpl<IList>::SetLocation( location );

	Update();
}

SYNKRO_INLINE void DefaultList::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetImpl<IList>::SetSize( size );

	Update();
}

SYNKRO_INLINE void DefaultList::SetTheme( ITheme* theme )
{
	// Call base implementation.
	BaseThemeWidgetImpl<BaseThemeWidget>::SetTheme( theme );

	_object->SetFragmentResources( theme->GetResources() );
	
	const WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state], true );
	img::Color color; _ui->Theme()->GetWidgetColor( state, color );
	_highlight->SetColor( color );
}

SYNKRO_INLINE void DefaultList::UpdateRect()
{
	CalcRect();
	Update();
}
