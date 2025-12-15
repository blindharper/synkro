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
// Purpose: Frame window implementation.
//==============================================================================
SYNKRO_INLINE void FrameWindow::Close()
{
	_window->Close();
}

SYNKRO_INLINE void FrameWindow::SetPosition( Int left, Int top )
{
	_window->SetPosition( left, top );
}

SYNKRO_INLINE void FrameWindow::SetSize( UInt width, UInt height )
{
	_window->SetSize( width, height );
}

SYNKRO_INLINE Int FrameWindow::GetLeft() const
{
	return _window->GetLeft();
}

SYNKRO_INLINE Int FrameWindow::GetTop() const
{
	return _window->GetTop();
}

SYNKRO_INLINE UInt FrameWindow::GetWidth() const
{
	return _window->GetWidth();
}

SYNKRO_INLINE UInt FrameWindow::GetHeight() const
{
	return _window->GetHeight();
}

SYNKRO_INLINE Pointer FrameWindow::GetHandle() const
{
	return _window->GetHandle();
}

SYNKRO_INLINE UInt FrameWindow::GetDpi() const
{
	return _window->GetDpi();
}

SYNKRO_INLINE Bool FrameWindow::IsActive() const
{
	return _window->IsActive();
}

SYNKRO_INLINE Bool FrameWindow::IsClosing() const
{
	return _window->IsClosing();
}

SYNKRO_INLINE void FrameWindow::Center()
{
	_window->Center();
}

SYNKRO_INLINE void FrameWindow::Activate()
{
	_window->Activate();
}

SYNKRO_INLINE void FrameWindow::SetTitle( const lang::String& title )
{
	_window->SetTitle( title );
}

SYNKRO_INLINE void FrameWindow::SetPopup( Bool popup )
{
	_window->SetPopup( popup );
}

SYNKRO_INLINE UInt FrameWindow::GetIcon() const
{
	return _window->GetIcon();
}

SYNKRO_INLINE lang::String FrameWindow::GetTitle() const
{
	return _window->GetTitle();
}

SYNKRO_INLINE IMonitor* FrameWindow::GetMonitor() const
{
	return _window->GetMonitor();
}

SYNKRO_INLINE Bool FrameWindow::IsPopup() const
{
	return _window->IsPopup();
}

SYNKRO_INLINE Bool FrameWindow::IsSizeable() const
{
	return _window->IsSizeable();
}
