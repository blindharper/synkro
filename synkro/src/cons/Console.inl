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
// Purpose: Implements console.
//==============================================================================
SYNKRO_INLINE Bool Console::Update( Double delta )
{
	// Do nothing.
	return true;
}

SYNKRO_INLINE void Console::Clear()
{
	for ( UInt i = 0; i < _texts->GetTextCount(); ++i )
	{
		_texts->GetText( i )->Clear();
	}
	_texts->Enable( false );
	_lineIndex = 0;
	_lineCount = 0;
}

SYNKRO_INLINE void Console::EnableEcho( Bool enable )
{
	_echoEnabled = enable;
}

SYNKRO_INLINE void Console::EnableSound( Bool enable )
{
	_soundEnabled = enable;
}

SYNKRO_INLINE void Console::SetTextColor( const img::Color& color )
{
	_textColor = color;
	for ( UInt i = 0; i < _texts->GetTextCount(); ++i )
	{
		_texts->GetText( i )->SetColor( _textColor );
	}
	_cmd->SetColor( img::Color::White );
}

SYNKRO_INLINE void Console::SetOpacity( UInt opacity )
{
	opacity = Clamp( opacity, CastUInt( 0 ), CastUInt(100) );
	_console->SetOpacity( CastFloat(opacity*0.01f) );
	_opacity = opacity;
}

SYNKRO_INLINE void Console::SetScriptMachine( script::IScriptMachine* machine )
{
	assert( machine != nullptr );

	_scriptMachine = machine;
}

SYNKRO_INLINE void Console::Echo( const lang::String& message )
{
	if ( _echoEnabled )
	{
		Print( message );
	}
}

SYNKRO_INLINE Bool Console::IsActive() const
{
	return (_state != STATE_CLOSED);
}

SYNKRO_INLINE Bool Console::IsEchoEnabled() const
{
	return _echoEnabled;
}

SYNKRO_INLINE Bool Console::IsSoundEnabled() const
{
	return _soundEnabled;
}

SYNKRO_INLINE void Console::GetTextColor( img::Color& color ) const
{
	color = _textColor;
}

SYNKRO_INLINE UInt Console::GetOpacity() const
{
	return _opacity;
}

SYNKRO_INLINE script::IScriptMachine* Console::GetScriptMachine() const
{
	return _scriptMachine;
}

SYNKRO_INLINE gfx::IGraphicsSystemEx* Console::GetGraphicsSystem() const
{
	return _graphicsSystem;
}

SYNKRO_INLINE script::IScriptSystemEx* Console::GetScriptSystem() const
{
	return _scriptSystem;
}

SYNKRO_INLINE ui::IUiEx* Console::GetUi() const
{
	return _ui;
}
