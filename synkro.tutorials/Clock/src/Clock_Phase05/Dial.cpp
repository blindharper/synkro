#include "Dial.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;
using namespace synkro::scene;
using namespace synkro::sound;

//------------------------------------------------------------------------------


Dial::Dial( ISynkro* synkro, ISceneEx* scene, ISound2D* sound, Float radius, const DialMode& mode ) :
	_synkro( synkro ),
	_timer( none ),
	_sound( sound ),
	_soundEnabled( true )
{
	constexpr Float HEIGHT = 1.0f;
	Matrix4x4 transRotation;
	Matrix4x4 transPosition;
	Matrix4x4 trans;

	// Create materials.
	_materialFace = CreateMaterial( Color::White );
	_materialBorder = CreateMaterial( Color::DimGray );
	_materialRed = CreateMaterial( Color::DarkScarlet );
	_materialRed->SetSpecularColor( Color::Black );
	_materialRed->SetSpecularPower( 150.0f );
	_materialMetal = CreateMaterial( Color::DarkGunmetal );
	_materialMetal->SetSpecularColor( Color::White );
	_materialMetal->SetSpecularPower( 20.0f );

	// Create face and border.
	_face = scene->CreateTriangleMesh( nullptr, L"Face", _materialFace, nullptr );
	_synkro->GetSceneManager()->BuildMesh( _face, MeshBuilder::Cylinder, Vector4(radius, HEIGHT, 0.0f, 0.0f), Size(1, TICK_COUNT), Matrix4x4::Identity );
	_border = scene->CreateTriangleMesh( _face, L"Border", _materialBorder, nullptr );
	_synkro->GetSceneManager()->BuildMesh( _border, MeshBuilder::Cylinder, Vector4(radius+0.1f, HEIGHT-0.1f, 0.0f, 0.0f), Size(1, TICK_COUNT), Matrix4x4::Identity );

	// Create ticks.
	_tick = scene->CreateTriangleMeshBatch( _materialMetal, nullptr, TICK_COUNT );
	_synkro->GetSceneManager()->BuildMesh( _tick, MeshBuilder::Box, Vector4(1.5f, 4.0f, 0.4f, 0.0f), Size(), Matrix4x4::Identity );
	for ( UInt i = 0; i < TICK_COUNT; ++i )
	{
		transRotation.SetOrientation( Quaternion(Vector3::Y, -CastFloat(i)*Math::TwoPi/CastFloat(TICK_COUNT)) );
		transPosition.SetTranslation( Vector3(0.0f, 0.8f, radius-4.0f) );
		_ticks[i] = _tick->CreateInstance( _face, transRotation*transPosition, Color::DimGray );
	}

	// Create arrows.
	trans.SetTranslation( Vector3(0.0f, 0.7f, 2.0f) );
	_hourArrow = CreateArrow( scene, L"Hour", _materialMetal, MeshBuilder::Box, Vector4(0.6f, 5.0f, 0.2f, 0.0f), Size(), trans, Math::TwoPi, 1.0f/43200.0f );
	_hourArrowCtrl = _hourArrow->CreateAnimationController( nullptr, nullptr );

	trans.SetTranslation( Vector3(0.0f, 0.9f, 3.5f) );
	_minuteArrow = CreateArrow( scene, L"Minute", _materialMetal, MeshBuilder::Box, Vector4(0.5f, 8.0f, 0.2f, 0.0f), Size(), trans, Math::TwoPi, 1.0f/3600.0f );
	_minuteArrowCtrl = _minuteArrow->CreateAnimationController( nullptr, nullptr );

	transPosition.SetTranslation( Vector3(0.0f, 1.1f, 4.5f) );
	transRotation.SetOrientation( Quaternion(Vector3::X, Math::HalfPi) );
	_secondArrow = CreateArrow( scene, L"Second", _materialRed, MeshBuilder::Cylinder, Vector4(0.1f, 11.0f, 0.0f, 0.0f), Size(2, 20), transPosition*transRotation, Math::TwoPi, 1.0f/60.0f );
	_secondArrowCtrl = _secondArrow->CreateAnimationController( nullptr, nullptr );
	_animationAnalog = _secondArrowCtrl->GetAnimation();

	_secondArrowCtrl->SetAnimation( _animationDigital = _synkro->GetAnimationSystem()->CreateAnimation() );
	IWaveFloatTrack* trackYaw = _secondArrowCtrl->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
	trackYaw->SetType( WaveType::Step );
	trackYaw->SetAmplitude( 1.0f );
	trackYaw->SetFrequency( 1.0f/60.0f );
	_secondArrowCtrl->SetAnimation( _animationDigital );
	_yawTrackName = trackYaw->GetName();

	_timer = _synkro->CreateTimer( 1000, this );
	SetMode( mode );
	SetTime( DateTime() );
}

void Dial::Start()
{
	_hourArrowCtrl->Start( true );
	_minuteArrowCtrl->Start( true );
	_secondArrowCtrl->Start( true );
}

void Dial::Pause( Bool pause )
{
	_hourArrowCtrl->Pause( pause );
	_minuteArrowCtrl->Pause( pause );
	_secondArrowCtrl->Pause( pause );
}

void Dial::SetMode( const DialMode& mode )
{
	_secondArrowCtrl->SetAnimation( (mode == DialMode::DIGITAL) ? _animationDigital : _animationAnalog );
}

void Dial::SetTime( const DateTime& time )
{
	SetAngle( _hourArrow, time.TotalHours()*Math::TwoPi/CastFloat(TICK_COUNT) );
	SetAngle( _minuteArrow, time.TotalMinutes()*Math::TwoPi/60.0f );

	Float angle = time.TotalSeconds()*Math::TwoPi/60.0f;
	_secondArrow->SetOrientation( Quaternion(Vector3::Y, -angle) );
	_animationAnalog->GetTrack( 0 )->AsFloat()->AsProcedural()->AsWave()->SetOffset( -angle );
	_animationDigital->GetTrack( 0 )->AsFloat()->AsProcedural()->AsWave()->SetOffset( -angle );
}

void Dial::EnableSound( Bool enable )
{
	_soundEnabled = enable;
}

Dial::DialMode Dial::GetMode() const
{
	return (_secondArrowCtrl->GetAnimation() == _animationDigital) ? DialMode::DIGITAL : DialMode::ANALOG;
}

Bool Dial::IsRunning() const
{
	return (_secondArrowCtrl->GetState() != ControllerState::Suspended);
}

Bool Dial::IsSoundEnabled() const
{
	return _soundEnabled;
}

void Dial::OnTimerTick( UInt timer )
{
	if ( timer == _timer )
	{
		if ( (GetMode() == DialMode::DIGITAL) && IsRunning() && _soundEnabled )
		{
			_sound->Play( true );
		}
	}
}

IOpaqueMaterial* Dial::CreateMaterial( const Color& color )
{
	IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
	material->SetDiffuseColor( color );
	material->SetAmbientColor( color );
	return material;
}

ITriangleMesh* Dial::CreateArrow( ISceneEx* scene, const String& name, IOpaqueMaterial* material, const MeshBuilder& type, const Vector4& param1, const Size& param2, const Matrix4x4& transform, Float amplitude, Float frequency )
{
	ITriangleMesh* arrow = scene->CreateTriangleMesh( _face, name, material, nullptr );
	_synkro->GetSceneManager()->BuildMesh( arrow, type, param1, param2, transform );
	INodeAnimationController* ctrl = arrow->CreateAnimationController( nullptr, nullptr );
	ctrl->SetMode( AnimationMode::Loop );
	IWaveFloatTrack* trackYaw = ctrl->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
	trackYaw->SetType( WaveType::SawtoothDown );
	trackYaw->SetAmplitude( amplitude );
	trackYaw->SetFrequency( frequency );
	return arrow;
}

void Dial::SetAngle( ITriangleMesh* mesh, Float angle )
{
	mesh->SetOrientation( Quaternion(Vector3::Y, -angle) );
	mesh->CreateAnimationController( nullptr, nullptr )->GetAnimation()->GetTrack( _yawTrackName )->AsFloat()->AsProcedural()->AsWave()->SetOffset( -angle );
}
