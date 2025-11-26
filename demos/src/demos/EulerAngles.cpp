#include "../Demo.h"


class EulerAngles :
	public Demo
{
public:
	EulerAngles() :
		Demo( L"Euler Angles" )
	{
	}

	DebugMode GetDebugMode() const override
	{
		return DebugMode::Gizmos;
	}

	void InitScene() override
	{
		PtrStream stream = GetStream( L"airplane.x" );
		_airplane = _scene->LoadMesh( stream, nullptr, nullptr, 0 );
		Float sphere = _airplane->GetBoundSphere();
		_airplane->SetScale( 35.0f/sphere );
		_airplane->SetGizmoSize( 1.0f );

		_ctrlAirplane = _airplane->CreateAnimationController( nullptr, nullptr );
		_trackYaw = _ctrlAirplane->CreateOrientationYawTrack();
		_trackPitch = _ctrlAirplane->CreateOrientationPitchTrack();
		_trackRoll = _ctrlAirplane->CreateOrientationRollTrack();

		_ctrlAirplaneSmooth = _airplane->CreateAnimationController( nullptr, nullptr );
		_trackOrientation = _ctrlAirplaneSmooth->CreateOrientationTrack();
	}

	void InitView() override
	{
		_viewport->SetColor( Color::RoyalBlue );
		_camera->SetPosition( Vector3(0.0f, 50.0f, -150.0f) );
		_camera->LookAt( Vector3(0.0f, 0.0f, 0.0f) );
	}

	void InitUi() override
	{
		_labelYaw = CreateLabel( Point(_widgetLeft-85, 100), L"Yaw" );
		_angleYaw = CreateAngle( none, Point(_widgetLeft-35, 130), Color::Red );

		_labelPitch = CreateLabel( Point(_widgetLeft-20, 100), L"Pitch" );
		_anglePitch = CreateAngle( none, Point(_widgetLeft+30, 130), Color::Green );

		_labelRoll = CreateLabel( Point(_widgetLeft+45, 100), L"Roll" );
		_angleRoll = CreateAngle( none, Point(_widgetLeft+95, 130), Color::Blue );

		_btnReset = CreateButton( Point(_widgetLeft, 200), L"[R]eset", Anchor::TopRight, HotKey(Key::R, true) );
		_btnResetSmooth = CreateButton( Point(_widgetLeft, 230), L"[S]mooth Reset", Anchor::TopRight, HotKey(Key::S, true) );
	}

	// SynkroListener methods.
	void OnSynkroUpdate( Double delta ) override
	{
		Demo::OnSynkroUpdate( delta );

		if ( _ctrlAirplane->GetState() == ControllerState::Active )
		{
			_angleYaw->SetValue( Math::Abs(Math::ToDegrees(_airplane->GetOrientationYaw())) );
			_anglePitch->SetValue( Math::Abs(Math::ToDegrees(_airplane->GetOrientationPitch())) );
			_angleRoll->SetValue( Math::Abs(Math::ToDegrees(_airplane->GetOrientationRoll())) );
		}
	}

	// UiListener methods.
	Bool OnUiClick( IWidget* sender ) override
	{
		if ( Demo::OnUiClick(sender) )
			return true;

		if ( sender == _btnReset )
		{
			constexpr Double LENGTH = 1.0;

			_trackYaw->SetKey( 0.0, _airplane->GetOrientationYaw() );
			_trackYaw->SetKey( LENGTH, 0.0f, Interpolation::Ease );

			_trackPitch->SetKey( 0.0, _airplane->GetOrientationPitch() );
			_trackPitch->SetKey( LENGTH, 0.0f, Interpolation::Ease );

			_trackRoll->SetKey( 0.0, _airplane->GetOrientationRoll() );
			_trackRoll->SetKey( LENGTH, 0.0f, Interpolation::Ease );

			_ctrlAirplane->Reset();
			_ctrlAirplane->Start( true );

			return true;
		}
		else if ( sender == _btnResetSmooth )
		{
			Quaternion orientation;
			_airplane->GetOrientation( orientation );

			_trackOrientation->SetKey( 0.0, orientation );
			_trackOrientation->SetKey( 1.0, Quaternion::Identity, Interpolation::Ease );

			_ctrlAirplaneSmooth->Reset();
			_ctrlAirplaneSmooth->Start( true );

			return true;
		}

		return false;
	}

	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _angleYaw )
		{
			const Float yaw = Math::ToRadians( _angleYaw->GetValue() );
			_airplane->SetOrientationYaw( yaw );
			return true;
		}
		else if ( sender == _anglePitch )
		{
			const Float pitch = Math::ToRadians( _anglePitch->GetValue() );
			_airplane->SetOrientationPitch( pitch );
			return true;
		}
		else if ( sender == _angleRoll )
		{
			const Float roll = Math::ToRadians( _angleRoll->GetValue() );
			_airplane->SetOrientationRoll( roll );
			return true;
		}

		return false;
	}

private:
	PtrTriangleMesh											_airplane;
	PtrNodeAnimationController								_ctrlAirplane;
	PtrKeyframedFloatTrack									_trackYaw;
	PtrKeyframedFloatTrack									_trackPitch;
	PtrKeyframedFloatTrack									_trackRoll;
	PtrNodeAnimationController								_ctrlAirplaneSmooth;
	PtrKeyframedQuaternionTrack								_trackOrientation;

	PtrLabel												_labelYaw;
	PtrAngle												_angleYaw;

	PtrLabel												_labelPitch;
	PtrAngle												_anglePitch;

	PtrLabel												_labelRoll;
	PtrAngle												_angleRoll;

	PtrButton												_btnReset;
	PtrButton												_btnResetSmooth;
};

SYNKRO_DEMO_BEGIN
	EulerAngles demo;
	demo.Run();
SYNKRO_DEMO_END
