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
#ifndef _SYNKRO_CONS_CONSOLE_
#define _SYNKRO_CONS_CONSOLE_


#include "config.h"
#include <lang/Map.h>
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <cons/IConsole.h>
#include <cons/IConsoleCommand.h>
#include <win/WindowListener.h>
#include <input/KeyboardListener.h>
#include <anim/AnimationListener.h>
#include <anim/IAnimation.h>
#include <anim/IAnimationPointTrack.h>
#include <script/IScriptMachine.h>
#include <sound/ISound2D.h>
#include <over/ISprite.h>
#include <over/IText.h>
#include <over/ITextPool.h>
#include <core/ISynkro.h>
#include "BaseConsole.h"


namespace synkro
{


namespace cons
{


// IConsole implementation.
class Console :
	public core::ObjectImpl<IConsole>,
	public BaseConsole,
	public anim::AnimationListener,
	public input::KeyboardListener,
	public win::WindowListener,
	public Logger
{
public:
	enum
	{
		ID_RESOURCE_CONSOLE = 1,
	};

	// Constructor.
	Console( core::ISynkro* synkro, over::IOverlay* overlay, diag::ILog* log );

	// ISystem methods.
	Bool													Update( Double delta );

	// IConsole methods.
	void													Clear();
	void													Activate( Bool activate );
	void													EnableEcho( Bool enable );
	void													EnableSound( Bool enable );
	void													SetTextColor( const img::Color& color );
	void													SetOpacity( UInt opacity );
	void													SetScriptMachine( script::IScriptMachine* machine );
	void													Echo( const lang::String& message );
	Bool													IsActive() const;
	Bool													IsEchoEnabled() const;
	Bool													IsSoundEnabled() const;
	void													GetTextColor( img::Color& color ) const;
	UInt													GetOpacity() const;
	script::IScriptMachine*									GetScriptMachine() const;

	// AnimationListener methods.
	void													OnAnimationStop( anim::IAnimationController* sender );
	void													OnAnimationLoop( anim::IAnimationController* sender );

	// KeyboardListener methods.
	Bool													ListenKeyboardInput() const;
	Bool													OnKeyboardKeyDown( UInt device, const input::Key& key, Bool alt, Bool shift, Bool control );
	Bool													OnKeyboardKeyUp( UInt device, const input::Key& key, Bool alt, Bool shift, Bool control );
	Bool													OnKeyboardKeyPress( UInt device, Char key );

	// WindowListener method.
	void													OnWindowResize( UInt window, UInt width, UInt height );
	void													OnWindowCommand( UInt window, UInt command );
	void													OnWindowActivate( UInt window, Bool active );
	Bool													OnWindowClosing( UInt window );

	// BaseConsole methods.
	void													Print( const lang::String& text );

	// Other methods.
	void													InitInput();
	void													RegisterCommand( IConsoleCommandFactory* factory );
	void													ShowHelp( const lang::String& command );
	gfx::IGraphicsSystemEx*									GetGraphicsSystem() const;
	script::IScriptSystemEx*								GetScriptSystem() const;
	ui::IUiEx*												GetUi() const;

private:
	enum ConsoleState
	{
		STATE_CLOSED,
		STATE_OPENING,
		STATE_OPENED,
		STATE_CLOSING,
	};

	enum
	{
		FONT_SIZE = 12,
		LINE_WIDTH = 100,
	};

	typedef lang::MapPair<lang::String, P(IConsoleCommand)>	CommandEntry;
	typedef lang::MapPair<lang::String, lang::String>		AliasEntry;

	lang::MapCI<lang::String, P(IConsoleCommand)>			_commands;
	lang::MapCI<lang::String, lang::String>					_aliases;
	lang::Vector<lang::String>								_history;
	gfx::IGraphicsSystemEx*									_graphicsSystem;
	input::IInputSystemEx*									_inputSystem;
	sound::ISoundManager*									_soundManager;
	script::IScriptSystemEx*								_scriptSystem;
	ui::IUiEx*												_ui;
	ConsoleState											_state;
	P(sound::ISound2D)										_soundKey;
	over::IText*											_cmd;
	P(over::IText)											_caret;
	over::ITextAnimationController*							_caretCtrl;
	Bool													_echoEnabled;
	Bool													_soundEnabled;
	Float													_height;
	UInt													_lineHeight;
	img::Color												_textColor;
	UInt													_opacity;
	P(over::ITextPool)										_texts;
	over::ITextPoolAnimationController*						_textsCtrl;
	anim::IKeyframedPointTrack*								_textsTrack;
	P(over::ISprite)										_console;
	over::ISpriteAnimationController*						_consoleCtrl;
	anim::IKeyframedPointTrack*								_consoleTrack;
	P(over::IFont)											_font;
	P(script::IScriptMachine)								_scriptMachine;
	lang::String											_badChars;
	UInt													_pos;
	UInt													_lineIndex;
	UInt													_lineCount;
	UInt													_cmdIndex;

	void													UpdateText();
	void													SetCaretPosition( UInt pos );
	void													ExecuteCommand( const lang::String& text );
	void													PlaySound();
	sound::ISoundManager*									TryGetSoundManager( core::ISynkro* synkro );
	script::IScriptSystemEx*								TryGetScriptSystem( core::ISynkro* synkro );
	ui::IUiEx*												TryGetUi( core::ISynkro* synkro );
};


#include "Console.inl"


} // cons


} // synkro


#endif // _SYNKRO_CONS_CONSOLE_
