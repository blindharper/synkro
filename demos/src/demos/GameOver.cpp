#include "../Demo.h"


class GameOver :
	public Demo
{
public:
	GameOver() :
		Demo( L"Game Over" )
	{
	}

	void InitScene() override
	{
		PtrOverlay overlay = _synkro->GetOverlayManager()->GetOverlay( _window );

		// Create sprite with aninmation sequence.
		_spriteLogo = overlay->CreateSprite( GetImage(L"simon.jpg"), Point(100, 700), Size(300, 300) );
		PtrSpriteAnimationController ctrlSpriteLogo = _spriteLogo->CreateAnimationController( nullptr, nullptr );

		// Animation #1.
		PtrKeyframedFloatTrack trackLocationX1 = ctrlSpriteLogo->CreateLocationXTrack();
		trackLocationX1->SetKey( 0.0, 100.0f );
		trackLocationX1->SetKey( 5.0, 900.0f );
		PtrKeyframedFloatTrack trackOrientation1 = ctrlSpriteLogo->CreateOrientationTrack();
		trackOrientation1->SetKey( 0.0, 0.0f );
		trackOrientation1->SetKey( 5.0, Math::TwoPi );
		PtrKeyframedFloatTrack trackOpacity1 = ctrlSpriteLogo->CreateOpacityTrack();
		trackOpacity1->SetKey( 0.0, 1.0f );

		// Animation #2.
		ctrlSpriteLogo->GetAnimations()->CreateAnimation( L"FadeOut" );
		PtrKeyframedFloatTrack trackOpacity2 = ctrlSpriteLogo->CreateOpacityTrack();
		trackOpacity2->SetKey( 0.0, 1.0f );
		trackOpacity2->SetKey( 5.0, 0.0f );

		// Animation #3.
		ctrlSpriteLogo->GetAnimations()->CreateAnimation( L"Escape" );
		PtrKeyframedFloatTrack trackLocationX3 = ctrlSpriteLogo->CreateLocationXTrack();
		trackLocationX3->SetKey( 0.0, 900.0f );
		trackLocationX3->SetKey( 5.0, 2000.0f );
		PtrKeyframedFloatTrack trackOrientation3 = ctrlSpriteLogo->CreateOrientationTrack();
		trackOrientation3->SetKey( 0.0, 0.0f );
		trackOrientation3->SetKey( 5.0, Math::TwoPi );
		PtrKeyframedFloatTrack trackOpacity3 = ctrlSpriteLogo->CreateOpacityTrack();
		trackOpacity3->SetKey( 0.0, 1.0f );

		ctrlSpriteLogo->SetMode( AnimationMode::Loop );
		ctrlSpriteLogo->SetSpeed( 2.0 );
		ctrlSpriteLogo->Start( true );

		// Create animated sprites.
		_spriteFlame = CreateAnimatedSprite( Point(1000, 400), L"flame.jpg", 8, 1.0 );

		_spriteRabbit = CreateAnimatedSprite( Point(1200, 300), L"jumping_rabbit.bmp", 8, 5.0 );
		PtrSpriteAnimationController ctrlSpriteRabbit = _spriteRabbit->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackX0 = ctrlSpriteRabbit->CreateLocationXTrack( AnimationTrack::FloatWave )->AsWave();
		trackX0->SetType( WaveType::Sine );
		trackX0->SetPhase( Math::HalfPi );
		trackX0->SetAmplitude( 50.0f );
		trackX0->SetOffset( 1200.0f );
		trackX0->SetFrequency( 5.0f );
		trackX0->SetLength( 5.0 );
		PtrWaveFloatTrack trackY0 = ctrlSpriteRabbit->CreateLocationYTrack( AnimationTrack::FloatWave )->AsWave();
		trackY0->SetType( WaveType::Sine );
		trackY0->SetAmplitude( 50.0f );
		trackY0->SetOffset( 300.0f );
		trackY0->SetFrequency( 5.0f );
		trackY0->SetLength( 5.0 );
		ctrlSpriteRabbit->SetMode( AnimationMode::Loop );
		ctrlSpriteRabbit->Start( true );

		_spriteMan = CreateAnimatedSprite( Point(1200, 200), L"walking_man.bmp", 16, 10.0 );
		PtrSpriteAnimationController ctrlSpriteMan = _spriteMan->CreateAnimationController( nullptr, nullptr );
		PtrKeyframedPointTrack trackLocation = ctrlSpriteMan->CreateLocationTrack();
		trackLocation->SetKey( 0.0, Point(800, 200) );
		trackLocation->SetKey( 10.0, Point(20, 200), Interpolation::EaseInOut );

		// Create rotating text.
		_synkro->GetOverlayManager()->CreateFont( L"text", _synkro->GetLanguage(), L"Arial", FontStyle::Bold, 20 );
		_synkro->GetOverlayManager()->CreateFont( L"pool", _synkro->GetLanguage(), L"Tahoma", FontStyle::Normal, 14 );
		PtrFont font = overlay->GetFont( L"text" );
		_textVersion = font->CreateText( ColorGradient(GradientType::Vertical, Color::Yellow, Color::Red), Point(500, 500), Version::Current.ToString(), Order::Highest, Order::High );
		
		PtrTextAnimationController ctrlTextVersion = _textVersion->CreateAnimationController( nullptr, nullptr );
		PtrNoiseFloatTrack trackOrientation = ctrlTextVersion->CreateOrientationTrack( AnimationTrack::FloatNoise )->AsNoise();
		trackOrientation->SetMagnitude( Math::Pi );
		ctrlTextVersion->SetMode( AnimationMode::Loop );
		ctrlTextVersion->Start( true );

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
		trackY->SetOffset( 100.0f );
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
		_viewport->SetColor( Color::Black );
	}

	void OnCredits( Bool active ) override
	{
		_spriteLogo->Show( !active );
		_spriteFlame->Show( !active );
		_spriteRabbit->Show( !active );
		_spriteMan->Show( !active );
		_textVersion->Show( !active );
		_textPool->Enable( !active );
	}

	ISprite* CreateAnimatedSprite( const Point& position, const String& name, UInt frameCount, Double length )
	{
		PtrImage image = GetImage( name );
		PtrOverlay overlay = _synkro->GetOverlayManager()->GetOverlay( _window );
		ISprite* sprite = overlay->CreateSprite( image, position, Size(image->GetWidth()/frameCount, image->GetHeight()) );

		PtrSpriteAnimationController ctrl = sprite->CreateAnimationController( nullptr, nullptr );
		PtrKeyframedFloatRectTrack track = ctrl->CreateFrameTrack();

		for ( UInt k = 0; k < CastULong(length); ++k )
		{
			for ( UInt i = 0; i < frameCount; ++i )
			{
				track->SetKey( (i+k*frameCount)/CastDouble(frameCount), RectF(i/CastFloat(frameCount), 0.0f, (i+1)/CastFloat(frameCount), 1.0f), Interpolation::Stepped );
			}
		}

		ctrl->SetMode( AnimationMode::Loop );
		ctrl->Start( true );

		return sprite;
	}

private:
	PtrSprite												_spriteLogo;
	PtrSprite												_spriteFlame;
	PtrSprite												_spriteRabbit;
	PtrSprite												_spriteMan;
	PtrText													_textVersion;
	PtrTextPool												_textPool;
	PtrText													_text;
	PtrText													_text2;
	PtrText													_text3;
};

SYNKRO_DEMO_BEGIN
	GameOver demo;
	demo.Run();
SYNKRO_DEMO_END
