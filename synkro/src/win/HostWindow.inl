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
// Purpose: Host window implementation.
//==============================================================================
SYNKRO_INLINE void HostWindow::Close()
{
	_window->Close();
}

SYNKRO_INLINE void HostWindow::SetPosition( Int left, Int top )
{
	_window->SetPosition( left, top );
}

SYNKRO_INLINE void HostWindow::SetSize( UInt width, UInt height )
{
	_window->SetSize( width, height );
}

SYNKRO_INLINE Int HostWindow::GetLeft() const
{
	return _window->GetLeft();
}

SYNKRO_INLINE Int HostWindow::GetTop() const
{
	return _window->GetTop();
}

SYNKRO_INLINE UInt HostWindow::GetWidth() const
{
	return _window->GetWidth();
}

SYNKRO_INLINE UInt HostWindow::GetHeight() const
{
	return _window->GetHeight();
}

SYNKRO_INLINE Pointer HostWindow::GetHandle() const
{
	return _window->GetHandle();
}

SYNKRO_INLINE UInt HostWindow::GetDpi() const
{
	return _window->GetDpi();
}

SYNKRO_INLINE Bool HostWindow::IsActive() const
{
	return _window->IsActive();
}

SYNKRO_INLINE Bool HostWindow::IsClosing() const
{
	return _window->IsClosing();
}

SYNKRO_INLINE void HostWindow::SetTitle( const lang::String& title )
{
	_window->SetTitle( title );
}

SYNKRO_INLINE lang::String HostWindow::GetTitle() const
{
	return _window->GetTitle();
}

SYNKRO_INLINE UInt HostWindow::GetWindowCount() const
{
	return _windows.Size();
}

SYNKRO_INLINE IViewWindowEx* HostWindow::GetWindow( UInt index ) const
{
	assert( index < _windows.Size() );

	if ( index >= _windows.Size() )
		throw new lang::OutOfRangeException( index, _windows.Size() );

	return _windows[index];
}

SYNKRO_INLINE void HostWindow::AddWindow( IViewWindowEx* window )
{
	_windows.Add( window );
}
