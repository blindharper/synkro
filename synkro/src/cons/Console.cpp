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
#include "config.h"
#include "Console.h"
#include <cons/IConsoleCommandFactory.h>
#include <core/Version.h>
#include <core/IResource.h>
#include <core/ResourceReader.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IFrameRenderWindowEx.h>
#include <over/IOverlay.h>
#include <over/IOverlayManager.h>
#include <over/ISpriteAnimationController.h>
#include <over/ITextPoolAnimationController.h>
#include <over/ITextAnimationController.h>
#include <over/IFont.h>
#include <img/IImage.h>
#include <img/ImageCodec.h>
#include <img/IImageManager.h>
#include <input/IKeyboardEx.h>
#include <io/IStreamDirectory.h>
#include <win/IWindowSystemEx.h>
#include <win/IFrameWindowEx.h>
#include <input/IInputSystemEx.h>
#include <script/IScriptSystemEx.h>
#include <script/ScriptException.h>
#include <anim/IKeyframedPointTrack.h>
#include <anim/IKeyframedBoolTrack.h>
#include <math/Math.h>
#include <ui/IUiEx.h>
#include <audio/IAudioSystemEx.h>
#include <io/IStreamSystemEx.h>
#include <io/IStream.h>
#include <sound/ISoundManager.h>
#include <input/KeyConst.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::over;
using namespace synkro::script;
using namespace synkro::sound;
using namespace synkro::ui;

//------------------------------------------------------------------------------


namespace synkro
{


namespace cons
{


Console::Console( ISynkro* synkro, IOverlay* overlay, ILog* log ) :
	_commands( A(CommandEntry) ),
	_aliases( A(AliasEntry) ),
	_history( A(String) ),
	Logger( log, LogFacility::Console ),
	_state( STATE_CLOSED ),
	_graphicsSystem( synkro->GetGraphicsSystem() ),
	_inputSystem( synkro->GetInputSystem() ),
	_soundManager( TryGetSoundManager(synkro) ),
	_scriptSystem( TryGetScriptSystem(synkro) ),
	_ui( TryGetUi(synkro) ),
	_echoEnabled( false ),
	_soundEnabled( false ),
	_badChars( L"\r\n\t\b`" ),
	_lineIndex( 0 ),
	_lineCount( 0 ),
	_textColor( Color::Orange ),
	_pos( 0 ),
	_cmdIndex( 0 )
{
	// Get access to the first untyped resource.
	P(IStreamDirectory) res; P(IStream) streamBack; P(IStream) streamKey;
	core::IResource* unknown = synkro->GetResource( ID_RESOURCE_CONSOLE );
	if ( unknown != nullptr )
	{
		res = unknown->Load();
		ResourceReader rd( res );
		streamBack = rd.GetResource( L"console.back" );
		streamKey = rd.GetResource( L"console.key" );
	}

	const UInt width = overlay->GetRenderWindow()->GetWidth();
	const UInt height = overlay->GetRenderWindow()->GetHeight();

	_height = CastFloat(height)/2.0f;
	_lineHeight = FONT_SIZE+10;
	const UInt lineCount = CastUInt(_height / CastFloat(_lineHeight)) - 1;
	_height = (lineCount+1)*CastFloat(_lineHeight) + 4;

	PixelFormat format = _graphicsSystem->GetFrameWindow( 0 )->GetClientPixelFormat();
	P(IImage) back = synkro->GetImageManager()->LoadImage( streamBack, format );
	_console = overlay->CreateSprite( back, Order::Highest, Order::High, Point(0, CastInt(-_height)), Size(width, CastUInt(_height)));
	_console->SetFrame( RectF(0.0f, 0.0f, CastFloat(width)/CastFloat(back->GetWidth()), CastFloat(_height)/CastFloat(back->GetHeight())) );
	_consoleCtrl = _console->CreateAnimationController( nullptr, this );
	_consoleTrack = _consoleCtrl->CreateLocationTrack();
	_consoleTrack->SetKey( 0.0, Point(0, CastInt(-_height)) );
	_consoleTrack->SetKey( 1.0, Point(0, 0) );
	synkro->GetWindowSystem()->GetFrameWindow( 0 )->Listen( this );

	// Initialize sound stuff.
	if ( (_soundManager != nullptr) && (synkro->GetAudioSystem()->GetTotalPlayerCount() > 0) )
	{
		synkro->GetAudioSystem()->CreatePlayer( 0 );
		_soundKey = _soundManager->LoadSound2D( streamKey );
	}

	// Create text lines.
	synkro->GetOverlayManager()->CreateFont( L"Console", Language::English, L"Courier New", FontStyle::Normal, FONT_SIZE );
	_font = overlay->GetFont( L"Console" );
	_texts = overlay->CreateTextPool( _font, Order::Highest, Order::Highest, LINE_WIDTH*(lineCount+1) );
	_textsCtrl = _texts->CreateAnimationController( nullptr, nullptr );
	_textsTrack = _textsCtrl->CreateOffsetTrack();
	_textsTrack->SetKey( 0.0, Point(0, CastInt(-_height)) );
	_textsTrack->SetKey( 1.0, Point(0, 0) );
	for ( UInt i = 0; i < lineCount; ++i )
	{
		_texts->CreateText( _textColor, Point(0, i*_lineHeight), String::Empty );
	}
	_cmd = _texts->CreateText( Color::White, Point(0, lineCount*_lineHeight), String::Empty );
	_caret = _font->CreateText( Color::White, Point(0, lineCount*_lineHeight-10), L"_", Order::Highest, Order::Highest );
	_caretCtrl = _caret->CreateAnimationController( nullptr, nullptr );
	_caretCtrl->SetMode( AnimationMode::Loop );
	IKeyframedBoolTrack* track = _caretCtrl->CreateVisibilityTrack();
	track->SetKey( 0.0, false );
	track->SetKey( 0.5, true );
	track->SetKey( 1.0, false );

	_caret->Show( false );
	_console->Show( false );
	_texts->Enable( false );
	_texts->SetOffset( Point(0, CastInt(-_height)) );

	SetOpacity( 80 );
	SetCaretPosition( 0 );
}

void Console::Activate( Bool activate )
{
	if ( activate && (_state == STATE_CLOSED) )
	{
		_consoleCtrl->SetDirection( AnimationDirection::Forward );
		_consoleCtrl->Reset();
		_consoleCtrl->SetOffset( 0.0 );
		_consoleCtrl->Start( true );
		_console->Show( true );

		_textsCtrl->SetDirection( AnimationDirection::Forward );
		_textsCtrl->Reset();
		_textsCtrl->SetOffset( 0.0 );
		_textsCtrl->Start( true );
		_texts->Enable( true );
		
		_state = STATE_OPENING;
	}
	else if ( !activate && (_state == STATE_OPENED) )
	{
		_consoleCtrl->SetDirection( AnimationDirection::Reverse );
		_consoleCtrl->SetOffset( 1.0 );
		_consoleCtrl->Start( true );
		_caretCtrl->Start( false );
		_caret->Show( false );

		_textsCtrl->SetDirection( AnimationDirection::Reverse );
		_textsCtrl->SetOffset( 1.0 );
		_textsCtrl->Start( true );

		_state = STATE_CLOSING;
	}
}

void Console::OnAnimationStop( IAnimationController* sender )
{
	if ( sender == _consoleCtrl )
	{
		if ( _state == STATE_CLOSING )
		{
			_caret->Show( false );
			_console->Show( false );
			_texts->Enable( false );
			_state = STATE_CLOSED;
			if ( _ui != nullptr )
			{
				_ui->Enable( true );
			}
		}
		else if ( _state == STATE_OPENING )
		{
			_caretCtrl->Start( true );
			_state = STATE_OPENED;
		}
	}
}

void Console::OnAnimationLoop( IAnimationController* sender )
{
}

Bool Console::ListenKeyboardInput() const
{
	return true;
}

Bool Console::OnKeyboardKeyDown( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
{
	if ( !IsActive() )
		return false;

	String text = _cmd->GetText();
	String start;
	String end;

	switch ( key )
	{
		case KEY_HOME:
		case KEY_NUMPAD7:
			SetCaretPosition( 0 );
			break;

		case KEY_END:
		case KEY_NUMPAD1:
			SetCaretPosition( text.Length() );
			break;

		case KEY_LEFT:
			if ( _pos > 0 )
				SetCaretPosition( _pos-1 );
			break;

		case KEY_RIGHT:
			if ( _pos < text.Length() )
				SetCaretPosition( _pos+1 );
			break;

		case KEY_UP:
			if ( _cmdIndex > 0 )
				--_cmdIndex;
			if ( _cmdIndex >= _history.Size() )
				_cmdIndex = _history.Size()-1;

			if ( _cmdIndex < _history.Size() )
			{
				_cmd->SetText( _history[_cmdIndex] );
				SetCaretPosition( text.Length() );
			}
			break;

		case KEY_DOWN:
			if ( _cmdIndex < _history.Size()-1 )
				++_cmdIndex;

			if ( _cmdIndex < _history.Size() )
			{
				_cmd->SetText( _history[_cmdIndex] );
				SetCaretPosition( text.Length() );
			}
			break;

		case KEY_DELETE:
		case KEY_DECIMAL:
			start = text.Substring( 0, _pos );
			end = text.Substring( _pos+1 );
			_cmd->SetText( start + end );
			SetCaretPosition( _pos );
			break;

		case KEY_BACK:
			if ( _pos > 0 )
			{
				start = text.Substring( 0, _pos-1 );
				end = text.Substring( _pos );
				_cmd->SetText( start + end );
				SetCaretPosition( _pos-1 );
				PlaySound();
			}
			break;

		case KEY_RETURN:
			SetCaretPosition( 0 );
			if ( !text.IsEmpty() )
			{
				ExecuteCommand( text );
			}
			_cmd->Clear();
			break;
	}

	return true;
}

Bool Console::OnKeyboardKeyUp( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
{
	if ( key == Key::Grave )
	{
		switch ( _state )
		{
			case STATE_CLOSED:
				if ( _ui != nullptr )
				{
					_ui->Enable( false );
				}
				Activate( true );
				return true;

			case STATE_OPENED:
				Activate( false );
				return true;
		}
	}

	return false;
}

Bool Console::OnKeyboardKeyPress( UInt device, Char key )
{
	if ( !IsActive() )
		return false;

	if ( _badChars.Contains(key) )
		return false;

	if ( _cmd->GetText().Length() >= LINE_WIDTH )
		return true;

	_texts->Enable( true );
	PlaySound();

	String ch( key );
	String start = _cmd->GetText().Substring( 0, _pos );
	String end = _cmd->GetText().Substring( _pos );
	_cmd->SetText( start + ch + end );
	SetCaretPosition( _pos+1 );
	return true;
}

void Console::OnWindowResize( UInt window, UInt width, UInt height )
{
	_height = CastFloat(height)/2.0f;
	const UInt lineCount = CastUInt(_height / CastFloat(_lineHeight)) - 1;
	_height = (lineCount+1) * CastFloat(_lineHeight) + 4;
	_console->SetSize( Size(width, _height) );
	_consoleTrack->SetKey( 0.0, Point(0, CastInt(-_height)) );
	_textsTrack->SetKey( 0.0, Point(0, CastInt(-_height)) );

	// TODO: texts & caret
}

void Console::OnWindowCommand( UInt window, UInt command )
{
}

void Console::OnWindowActivate( UInt window, Bool active )
{
}

Bool Console::OnWindowClosing( UInt window )
{
	return true;
}

void Console::Print( const String& text )
{
	if ( !text.IsEmpty() )
	{
		if ( _lineIndex >= _texts->GetTextCount()-2 )
		{
			_lineIndex = 0;
		}
		IText* line = _texts->GetText( _lineIndex );
		line->SetText( text );
		line->SetColor( _textColor );
		line->Show( this->IsActive() );
		_cmd->Clear();
		if ( _lineCount <= _texts->GetTextCount()-2 )
		{
			++_lineCount;
		}
		UpdateText();
		++_lineIndex;
	}
}

void Console::InitInput()
{
	Key keys[] = { Key::Home, Key::Numpad7, Key::End, Key::Numpad1, Key::Left, Key::Right, Key::Up, Key::Down, Key::Delete, Key::Decimal, Key::Back, Key::Return };
	_inputSystem->CreateKeyboard( 0 );
	IKeyboardEx* keyboard = _inputSystem->GetKeyboard( 0 );
	keyboard->ListenKeyUp( this, Key::Grave );
	keyboard->ListenKeyDown( this, keys, SizeOf(keys), true );
	keyboard->ListenKeyPress( this );
}

void Console::RegisterCommand( IConsoleCommandFactory* factory )
{
	assert( factory != nullptr );

	String name = factory->GetName();
	LogInfoStart( MessagePriority::Lowest, Formatter::Format(L"Registering console command {0,q}...", name) );
	if ( !_commands.ContainsKey(name) )
	{
		try
		{
			_commands[name] = factory->Create( this );
			String alias = factory->GetAlias();
			if ( !alias.IsEmpty() && !_aliases.ContainsKey(alias) )
			{
				_aliases[alias] = name;
			}
			LogInfoEnd( Formatter::Format(Str::Done) );
		}
		catch ( const Exception& ex )
		{
			LogInfoEnd( String::Empty );
			LogWarning( MessagePriority::Normal, ex.ToString() );
		}
	}
	else
	{
		LogInfoEnd( Formatter::Format(L"Command already registered.") );
	}
}

void Console::ShowHelp( const String& command )
{
	if ( command.IsEmpty() )
	{
		// Display help on all available commands.
		Vector<String> keys( A(String) );
		for ( MapIterator<String, P(IConsoleCommand)> it = _commands.Begin(); it != _commands.End(); ++it )
		{
			keys.Add( it.Key() );
		}
		keys.Sort();

		for ( UInt i = 0; i < keys.Size(); ++i )
		{
			String name = keys[i];
			IConsoleCommand* cmd = _commands[name];
			String help = String::Format( L"{0} {1}. Syntax: {2}", name, cmd->GetDescription(), cmd->GetSyntax() );
			Print( help.Substring(0, LINE_WIDTH) );
		}
	}
	else
	{
		IConsoleCommand* cmd = _commands[command];
		if ( cmd != nullptr )
		{
			String help = String::Format( L"{0}.Syntax: {1}", cmd->GetDescription(), cmd->GetSyntax() );
			Print( help.Substring(0, LINE_WIDTH) );
		}
		else
		{
			Print( String::Format(L"Unknown command: {0}", command) );
		}
	}
}

void Console::UpdateText()
{
	if ( _lineCount <= _texts->GetTextCount()-2 )
	{
		const UInt cnt = CastUInt( Math::Min(_texts->GetTextCount()-2, _lineCount) );
		for ( UInt i = 0; i < cnt; ++i )
		{
			const Point pt( 0, CastInt((_texts->GetTextCount()-2-_lineCount+i)*_lineHeight) );
			_texts->GetText( i )->SetLocation( pt );
		}
	}
	else
	{
		for ( UInt i = 0; i <= _lineIndex; ++i )
		{
			const Point pt( 0, CastInt((_texts->GetTextCount()-3-_lineIndex+i)*_lineHeight) );
			_texts->GetText( i )->SetLocation( pt );
		}
		for ( UInt i = _lineIndex+1; i < _texts->GetTextCount()-2; ++i )
		{
			const Point pt( 0, CastInt((i-_lineIndex-1)*_lineHeight) );
			_texts->GetText( i )->SetLocation( pt );
		}
	}
}

void Console::SetCaretPosition( UInt pos )
{
	_pos = pos;
	Size sz;
	if ( _pos > 0 )
	{
		_font->GetTextSize( _cmd->GetText().Substring(0, _pos), sz );
	}
	_caret->SetLocation( Point(sz.Width, (_texts->GetTextCount()-1)*_lineHeight-1) );
}

void Console::ExecuteCommand( const String& text )
{
	if ( _history.Size() < 20 )
	{
		const Bool duplicate = (_history.Size() > 0) && (_history.LastValue() == text);
		if ( !duplicate && !text.IsEmpty() )
		{
			_history.Add( text );
			_cmdIndex = _history.Size()-1;
		}
	}

	const UInt idx = text.IndexOf( L' ' );
	String cmd = (idx != none) ? text.Substring( 0, idx ) : text;
	if ( _aliases.ContainsKey(cmd) )
	{
		cmd = _aliases[cmd];
	}

	if ( _commands.ContainsKey(cmd) )
	{
		String arg = (idx != none) ? text.Substring( idx+1 ) : String::Empty;
		_commands[cmd]->Execute( arg );	
	}
	else if ( (_scriptMachine != nullptr) || (_scriptSystem->GetMachineCount() > 0) )
	{
		Print( text );
		try
		{
			IScriptMachine* machine = (_scriptMachine != nullptr) ? _scriptMachine : _scriptSystem->GetMachine( 0 );
			machine->Execute( text );
		}
		catch ( const ScriptException& ex )
		{
			Print( ex.ToString() );
		}
	}
	else
	{
		Print( String::Format(L"Unknown command: {0}", text) );
	}

	PlaySound();
}

void Console::PlaySound()
{
	if ( _soundEnabled && (_soundKey != nullptr) )
	{
		_soundKey->Play( true );
	}
}

ISoundManager* Console::TryGetSoundManager( ISynkro* synkro )
{
	try
	{
		return synkro->GetSoundManager();
	}
	catch ( const InvalidOperationException& )
	{
		return nullptr;
	}
}

IScriptSystemEx* Console::TryGetScriptSystem( ISynkro* synkro )
{
	try
	{
		return synkro->GetScriptSystem();
	}
	catch ( const InvalidOperationException& )
	{
		return nullptr;
	}
}

IUiEx* Console::TryGetUi( ISynkro* synkro )
{
	try
	{
		return synkro->GetUi();
	}
	catch ( const InvalidOperationException& )
	{
		return nullptr;
	}
}


} // cons


} // synkro
