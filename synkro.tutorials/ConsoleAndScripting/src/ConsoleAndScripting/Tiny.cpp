#include "Tiny.h"
#include "Scripting.h"


//------------------------------------------------------------------------------

using namespace synkro;
using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::scene;
using namespace synkro::script;

//------------------------------------------------------------------------------


SCRIPT_METHOD_BEGIN( Tiny_WalkTo, "walkTo", "nn", "" )
	void Call( void* object, const ScriptParam* in, ScriptParam* out )
	{
		Tiny* tiny = (Tiny*)object;
		tiny->WalkTo( CastFloat(in[0].GetNumber()), CastFloat(in[1].GetNumber()) );
	}
SCRIPT_METHOD_END( s_tiny_walkTo )

Tiny::Tiny( ISynkro* synkro, IScriptMachine* machine, ISceneEx* scene, const String& name, Float x, Float y ) :
	_synkro( synkro ),
	_machine( machine ),
	_scene( scene ),
	_name( name )
{
	ScriptMethod* methods[] =
	{
		&s_tiny_walkTo,
	};
	_object = _machine->CreateObject( this, nullptr, (const ScriptMethod**)&methods, sizeof(methods)/sizeof(methods[0]) );

	// Create target.
	_target = _scene->CreateDummy( nullptr, String::Empty );
	_target->SetPositionY( 31.0f );

	// Load model.
	PtrStream stream = GetStream( L"tiny.x" );
	ISkeleton* skeleton = _synkro->GetSceneManager()->CreateSkeleton();
	_tiny = _scene->LoadMesh( stream, nullptr, skeleton, 0 );
	const Float radius = _tiny->GetBoundSphere();
	_tiny->SetScale( 45.0f/radius );
	_tiny->SetPositionY( 31.0f );
	_tiny->SetPositionX( x );
	_tiny->SetPositionZ( y );

	// Create constraint and controller.
	_lookAt = _tiny->CreateLookAtConstraint( _target );
	_lookAt->Enable( false );
	_moveTo = _tiny->CreateAnimationController( nullptr, this );
	_moveTo->SetMode( AnimationMode::Single );
	_trackPosition = _moveTo->CreatePositionTrack();

	// Animate model.
	_skeletonCtrl = _tiny->GetSkeleton()->CreateAnimationController( nullptr, nullptr );
	_skeletonCtrl->SetMode( AnimationMode::Loop );
	_skeletonCtrl->SetDirection( AnimationDirection::Forward );
	_skeletonCtrl->SetLoopCount( 0 );
	_skeletonCtrl->SetSpeed( 4.0 );
}

void Tiny::OnAnimationStop( IAnimationController* sender )
{
	if ( (sender == _moveTo) && (_moveTo->GetState() == ControllerState::Inactive) )
	{
		_skeletonCtrl->Start( false );
	}
}

void Tiny::OnAnimationLoop( IAnimationController* sender )
{
	// Do nothing.
}

void Tiny::WalkTo( Float x, Float y )
{
	_target->SetPositionX( x );
	_target->SetPositionZ( y );
	_lookAt->Enable( true );

	Matrix4x4 transTiny;
	Matrix4x4 transTarget;
	_tiny->GetWorldTransform( transTiny );
	_target->GetWorldTransform( transTarget );

	const Vector3 posTiny = transTiny.Translation();
	const Vector3 posTarget = transTarget.Translation();
	const Float distance = (posTarget - posTiny).Length();
	constexpr Float SPEED = 40.0f;

	_trackPosition->Clear();
	_trackPosition->SetKey( 0.0, posTiny, Interpolation::Linear );
	_trackPosition->SetKey( CastDouble(distance/SPEED), posTarget, Interpolation::Linear );
	_moveTo->Reset();
	_moveTo->Start( true );

	_skeletonCtrl->Start( true );
}

String Tiny::GetName() const
{
	return _name;
}

IScriptObject* Tiny::GetObject() const
{
	return _object;
}

IStream* Tiny::GetStream( const String& name )
{
	PtrStream stream = _synkro->GetStreamSystem()->GetStream( name );
	if ( stream == nullptr )
		throw FileNotFoundException( name );
	return stream;
}
