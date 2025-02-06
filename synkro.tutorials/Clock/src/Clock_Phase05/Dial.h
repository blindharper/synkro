#ifndef __DIAL__
#define __DIAL__


#include <synkro.h>


//------------------------------------------------------------------------------

using namespace synkro;

//------------------------------------------------------------------------------


class Dial :
	public core::TimerListener
{
public:
	enum DialMode
	{
		ANALOG,
		DIGITAL,
	};

	// Constructor.
	Dial( core::ISynkro* synkro, scene::ISceneEx* scene, sound::ISound2D* sound, Float radius, const DialMode& mode );

	// Methods.
	void													Start();
	void													Pause( Bool pause );
	void													SetMode( const DialMode& mode );
	void													SetTime( const lang::DateTime& time );
	void													EnableSound( Bool enable );
	DialMode												GetMode() const;
	Bool													IsRunning() const;
	Bool													IsSoundEnabled() const;

	// TimerListener methods.
	void													OnTimerTick( UInt timer );

private:
	enum
	{
		TICK_COUNT = 12,
	};

	PtrSynkro												_synkro;

	PtrTriangleMesh											_face;
	PtrTriangleMesh											_border;
	PtrTriangleMeshBatch									_tick;
	PtrTriangleMesh											_ticks[TICK_COUNT];

	PtrTriangleMesh											_hourArrow;
	PtrNodeAnimationController								_hourArrowCtrl;
	PtrTriangleMesh											_minuteArrow;
	PtrNodeAnimationController								_minuteArrowCtrl;
	PtrTriangleMesh											_secondArrow;
	PtrNodeAnimationController								_secondArrowCtrl;

	PtrOpaqueMaterial										_materialFace;
	PtrOpaqueMaterial										_materialBorder;
	PtrOpaqueMaterial										_materialMetal;
	PtrOpaqueMaterial										_materialRed;

	PtrAnimation											_animationAnalog;
	PtrAnimation											_animationDigital;
	lang::String											_yawTrackName;

	PtrSound2D												_sound;
	Bool													_soundEnabled;
	UInt													_timer;

	mat::IOpaqueMaterial*									CreateMaterial( const img::Color& color );
	scene::ITriangleMesh*									CreateArrow( scene::ISceneEx* scene, const lang::String& name, mat::IOpaqueMaterial* material, const scene::MeshBuilder& type, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform, Float amplitude, Float frequency );
	void													SetAngle( scene::ITriangleMesh* mesh, Float angle );
};


#endif // __DIAL__
