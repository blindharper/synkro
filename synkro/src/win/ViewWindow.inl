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
// Purpose: View window implementation.
//==============================================================================
SYNKRO_INLINE Bool ViewWindow::Update()
{
	return false;
}

SYNKRO_INLINE void ViewWindow::Close()
{
	_window->Close();
}

SYNKRO_INLINE void ViewWindow::SetPosition( Int left, Int top )
{
	_window->SetPosition( left, top );
}

SYNKRO_INLINE void ViewWindow::SetSize( UInt width, UInt height )
{
	_window->SetSize( width, height );
}

SYNKRO_INLINE Int ViewWindow::GetLeft() const
{
	return _window->GetLeft();
}

SYNKRO_INLINE Int ViewWindow::GetTop() const
{
	return _window->GetTop();
}

SYNKRO_INLINE UInt ViewWindow::GetWidth() const
{
	return _window->GetWidth();
}

SYNKRO_INLINE UInt ViewWindow::GetHeight() const
{
	return _window->GetHeight();
}

SYNKRO_INLINE UInt ViewWindow::GetHandle() const
{
	return _window->GetHandle();
}

SYNKRO_INLINE UInt ViewWindow::GetDpi() const
{
	return _window->GetDpi();
}

SYNKRO_INLINE Bool ViewWindow::IsActive() const
{
	return _window->IsActive();
}

SYNKRO_INLINE Bool ViewWindow::IsClosing() const
{
	return _window->IsClosing();
}

SYNKRO_INLINE void ViewWindow::Show( Bool show )
{
	_window->Show( show );
}

SYNKRO_INLINE Bool ViewWindow::IsVisible() const
{
	return _window->IsVisible();
}

SYNKRO_INLINE IFrameWindow* ViewWindow::GetParent() const
{
	return _window->GetParent();
}
