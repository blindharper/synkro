#include <core/IContext.h>
#include <core/ObjectImpl.h>


class Context :
	public synkro::core::ObjectImpl<synkro::core::IContext>
{
public:
	// IContext methods.
	synkro::anim::IAnimationSystem*									GetAnimationSystem() const { return nullptr; }
	synkro::audio::IAudioSystemEx*									GetAudioSystem() const{ return AudioSystem; }
	synkro::cons::IConsole*											GetConsole() const { return nullptr; }
	synkro::db::IDatabaseSystemEx*									GetDatabaseSystem() const { return nullptr; }
	synkro::diag::IDiag*											GetDiag() const { return nullptr; }
	synkro::gfx::IGraphicsSystemEx*									GetGraphicsSystem() const { return nullptr; }
	synkro::img::IImageManager*										GetImageManager() const { return nullptr; }
	synkro::input::IInputSystemEx*									GetInputSystem() const { return nullptr; }
	synkro::mat::IMaterialManager*									GetMaterialManager() const { return nullptr; }
	synkro::net::INetworkSystemEx*									GetNetworkSystem() const { return nullptr; }
	synkro::over::IOverlayManager*									GetOverlayManager() const { return nullptr; }
	synkro::phys::IPhysicsSystemEx*									GetPhysicsSystem() const { return nullptr; }
	synkro::scene::ISceneManager*									GetSceneManager() const { return nullptr; }
	synkro::script::IScriptSystemEx*								GetScriptSystem() const { return nullptr; }
	synkro::sound::ISoundManager*									GetSoundManager() const { return nullptr; }
	synkro::io::IStreamSystemEx*									GetStreamSystem() const { return nullptr; }
	synkro::ui::IUiEx*												GetUi() const { return nullptr; }
	synkro::view::IViewportManager*									GetViewportManager() const { return nullptr; }
	synkro::win::IWindowSystemEx*									GetWindowSystem() const { return WindowSystem; }

	synkro::audio::IAudioSystemEx*									AudioSystem;
	synkro::win::IWindowSystemEx*									WindowSystem;
};