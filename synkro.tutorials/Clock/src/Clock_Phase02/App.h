#ifndef __APP__
#define __APP__


#include <synkro.h>


//------------------------------------------------------------------------------

using namespace synkro;

//------------------------------------------------------------------------------


class App :
	public core::SynkroListener
{
public:
	// Constructor.
	App();

	// Runs the application.
	void													Run();

	// SynkroListener methods.
	void													OnSynkroInitialize();
	void													OnSynkroUpdate( Double delta );
	Bool													OnSynkroException( const lang::Exception& ex );

private:
	Bool													_running;
	PtrSynkro												_synkro;
	PtrConfiguration										_config;
	PtrViewport												_viewport;

	void													Configure();
	void													InitView();
};


#endif // __APP__
