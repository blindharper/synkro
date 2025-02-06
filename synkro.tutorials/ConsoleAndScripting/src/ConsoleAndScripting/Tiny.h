#ifndef __TINY__
#define __TINY__


#include <synkro.h>


using namespace synkro;


class Tiny :
	public anim::AnimationListener
{
public:
	Tiny( core::ISynkro* synkro, script::IScriptMachine* machine, scene::ISceneEx* scene, const lang::String& name, Float x, Float y );

	void													OnAnimationStop( anim::IAnimationController* sender );
	void													OnAnimationLoop( anim::IAnimationController* sender );
	void													WalkTo( Float x, Float y );
	lang::String											GetName() const;
	script::IScriptObject*									GetObject() const;

private:
	PtrSynkro												_synkro;
	PtrScriptMachine										_machine;
	PtrScriptObject											_object;
	PtrSceneEx												_scene;
	PtrTriangleMesh											_tiny;
	PtrSkeletonAnimationController							_skeletonCtrl;
	PtrNode													_target;
	PtrLookAtConstraint										_lookAt;
	PtrNodeAnimationController								_moveTo;
	PtrKeyframedVector3Track								_trackPosition;
	lang::String											_name;

	io::IStream*											GetStream( const lang::String& name );
};


#endif // __TINY__
