#include "../Demo.h"


class Sprites :
	public Demo
{
public:
	Sprites() :
		Demo( L"Sprites" )
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
};

SYNKRO_DEMO_BEGIN
	Sprites demo;
	demo.Run();
SYNKRO_DEMO_END
