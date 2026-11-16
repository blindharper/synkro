#include "../Demo.h"


class Texts :
	public Demo
{
public:
	Texts() :
		Demo( L"Texts" )
	{
	}

	void InitScene() override
	{
		PtrOverlay overlay = _synkro->GetOverlayManager()->GetOverlay( _window );

		// Create fonts.
		_synkro->GetOverlayManager()->CreateFont( L"text", _synkro->GetLanguage(), L"Arial", FontStyle::Bold, 20 );
		_synkro->GetOverlayManager()->CreateFont( L"pool", _synkro->GetLanguage(), L"Tahoma", FontStyle::Normal, 14 );
		PtrFont font = overlay->GetFont( L"text" );

		// Create rotating text.
		_textRotating = font->CreateText( ColorGradient(GradientType::Vertical, Color::Yellow, Color::Red), Point(500, 500), Version::Current.ToString(), Order::Highest, Order::High );
		PtrTextAnimationController ctrlTextRotating = _textRotating->CreateAnimationController( nullptr, nullptr );
		PtrNoiseFloatTrack trackOrientation = ctrlTextRotating->CreateOrientationTrack( AnimationTrack::FloatNoise )->AsNoise();
		trackOrientation->SetMagnitude( Math::Pi );
		ctrlTextRotating->SetMode( AnimationMode::Loop );
		ctrlTextRotating->Start( true );

		// Create scaling text.
		_textScaling = font->CreateText( Color::CrimsonRed, Point(300, 900), L"I'm a scaling text!", Order::Highest, Order::High );
		_textScaling->SetCenter( Point(400, 850) );
		_textScaling->EnableCenter( true );
		PtrTextAnimationController ctrlTextScaling = _textScaling->CreateAnimationController( nullptr, nullptr );
		PtrKeyframedFloatTrack trackScale = ctrlTextScaling->CreateScaleTrack();
		trackScale->SetKey( 0.0, 1.0f );
		trackScale->SetKey( 2.0, 1.5f, Interpolation::EaseInOut );
		trackScale->SetKey( 4.0, 2.0f );
		ctrlTextScaling->SetMode( AnimationMode::Loop );
		ctrlTextScaling->Start( true );

		// Create blinking text.
		_textBlinking = font->CreateText( Color::DarkOrange, Point(100, 600), L"I'm a blinking text!", Order::Highest, Order::High );
		_ctrlTextBlinking = _textBlinking->CreateAnimationController( nullptr, nullptr );
		_ctrlTextBlinking->CreateVisibilityTrack( AnimationTrack::BoolNoise );
		_ctrlTextBlinking->SetMode( AnimationMode::Loop );
		_ctrlTextBlinking->Start( true );

		// Create fading text.
		_textFading = font->CreateText( ColorGradient(GradientType::Vertical, Color::Cyan, Color::DarkMidnightBlue), Point(600, 700), L"I'm a fading text!", Order::Highest, Order::High );
		_textFading->SetScale( 2.0f );
		PtrTextAnimationController ctrlTextFading = _textFading->CreateAnimationController( nullptr, nullptr );
		PtrKeyframedFloatTrack trackOpacity = ctrlTextFading->CreateOpacityTrack();
		trackOpacity->SetKey( 0.0, 1.0f );
		trackOpacity->SetKey( 3.0, 0.05f, Interpolation::EaseIn );
		trackOpacity->SetKey( 6.0, 1.0f );
		ctrlTextFading->SetMode( AnimationMode::Loop );
		ctrlTextFading->Start( true );

		// Create text pool.
		PtrFont font2 = overlay->GetFont( L"pool" );
		_textPool = overlay->CreateTextPool( font2, Order::AboveNormal, Order::Normal, 1000 );

		_text = _textPool->CreateText( ColorGradient(GradientType::Horizontal, Color::Red, Color::RoyalBlue), Point(300, 50), L"This is a colored text in the pool." );
		PtrTextAnimationController ctrlText = _text->CreateAnimationController( nullptr, nullptr );
		PtrKeyframedColorGradientTrack trackGradient = ctrlText->CreateColorGradientTrack();
		trackGradient->SetKey( 0.0, ColorGradient(GradientType::Horizontal, Color::Red, Color::RoyalBlue) );
		trackGradient->SetKey( 1.0, ColorGradient(GradientType::Horizontal, Color::RoyalBlue, Color::Red), Interpolation::EaseIn );
		trackGradient->SetKey( 2.0, ColorGradient(GradientType::Horizontal, Color::Red, Color::RoyalBlue) );
		ctrlText->SetMode( AnimationMode::Loop );
		ctrlText->Start( true );

		_text2 = _textPool->CreateText( ColorGradient(GradientType::Vertical, Color::Lime, Color::Yellow), Point(350, 100), L"Another pool text" );
		PtrTextAnimationController ctrlText2 = _text2->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackX = ctrlText2->CreateLocationXTrack( AnimationTrack::FloatWave )->AsWave();
		trackX->SetType( WaveType::Sine );
		trackX->SetPhase( Math::HalfPi );
		trackX->SetAmplitude( 50.0f );
		trackX->SetOffset( 100.0f );
		trackX->SetFrequency( 7.5f );
		PtrWaveFloatTrack trackY = ctrlText2->CreateLocationYTrack( AnimationTrack::FloatWave )->AsWave();
		trackY->SetType( WaveType::Sine );
		trackY->SetAmplitude( 50.0f );
		trackY->SetOffset( 300.0f );
		trackY->SetFrequency( 2.5f );
		ctrlText2->SetMode( AnimationMode::Loop );
		ctrlText2->Start( true );

		_text3 = _textPool->CreateText( Color::Orange, Point(300, 350), L"Another animated pool text" );
		PtrTextAnimationController ctrlText3 = _text3->CreateAnimationController( nullptr, nullptr );
		PtrKeyframedFloatTrack trackLocationX = ctrlText3->CreateLocationXTrack();
		trackLocationX->SetKey( 0.0, 300 );
		trackLocationX->SetKey( 5.0, 800, Interpolation::EaseInOut );
		PtrWaveFloatTrack trackLocationY = ctrlText3->CreateLocationYTrack( AnimationTrack::FloatWave )->AsWave();
		trackLocationY->SetType( WaveType::Sine );
		trackLocationY->SetAmplitude( 100.0f );
		trackLocationY->SetOffset( 150.0f );
		trackLocationY->SetFrequency( 5.0f );
		PtrKeyframedColorTrack trackColor = ctrlText3->CreateColorTrack();
		trackColor->SetKey( 0.0, Color::Orange );
		trackColor->SetKey( 5.0, Color::RoyalBlue );
		ctrlText3->SetMode( AnimationMode::PingPong );
		ctrlText3->Start( true );
	}

	void InitView() override
	{
		_viewport->SetColor( Color::DarkMidnightBlue );
	}

	void OnCredits( Bool active ) override
	{
		_textRotating->Show( !active );
		_textScaling->Show( !active );
		_textBlinking->Show( !active );
		_ctrlTextBlinking->Pause( active );
		_textFading->Show( !active );
		_textPool->Enable( !active );
	}

private:
	PtrText													_textRotating;
	PtrText													_textScaling;
	PtrText													_textBlinking;
	PtrTextAnimationController								_ctrlTextBlinking;
	PtrText													_textFading;
	PtrTextPool												_textPool;
	PtrText													_text;
	PtrText													_text2;
	PtrText													_text3;
};

SYNKRO_DEMO_BEGIN
	Texts demo;
	demo.Run();
SYNKRO_DEMO_END
