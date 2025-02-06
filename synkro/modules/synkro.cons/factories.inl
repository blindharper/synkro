using namespace synkro::cons;

#include <cons/Command/ClearCommandFactory.h>
#include <cons/Command/ColorCommandFactory.h>
#include <cons/Command/DisplayCommandFactory.h>
#include <cons/Command/EchoCommandFactory.h>
#include <cons/Command/HelpCommandFactory.h>
#include <cons/Command/MachineCommandFactory.h>
#include <cons/Command/MemoryCommandFactory.h>
#include <cons/Command/SoundCommandFactory.h>
#include <cons/Command/QuitCommandFactory.h>
#include <cons/Command/VersionCommandFactory.h>
#include <cons/Command/ThemeCommandFactory.h>

static ClearCommandFactory		_factClearCommand;
static ColorCommandFactory		_factColorCommand;
static DisplayCommandFactory	_factDisplayCommand;
static EchoCommandFactory		_factEchoCommand;
static HelpCommandFactory		_factHelpCommand;
static MachineCommandFactory	_factMachineCommand;
static MemoryCommandFactory		_factMemoryCommand;
static SoundCommandFactory		_factSoundCommand;
static QuitCommandFactory		_factQuitCommand;
static VersionCommandFactory	_factVersionCommand;
static ThemeCommandFactory		_factThemeCommand;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Console commands.
	//--------------------------------------------------------------------------
	&_factClearCommand,
	&_factColorCommand,
	&_factDisplayCommand,
	&_factEchoCommand,
	&_factHelpCommand,
	&_factMachineCommand,
	&_factMemoryCommand,
	&_factSoundCommand,
	&_factQuitCommand,
	&_factVersionCommand,
	&_factThemeCommand,
};
