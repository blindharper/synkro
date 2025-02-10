# Description
Synkro is a free 3d graphics framework for C++ developers

# Build instructions
Open synkro.build/buildall_msvs2022.sln in MS Visual Studio 2022
and choose the desired configuration then run build.

For dynamic build configuration (without "_static" suffix),
the dlls are placed into synkro/bin/win32 and synkro/bin/win64.
You need to add these paths to system search paths then restart.

For examples of using the dynamic libraries see demos, tools and tutorials.

For static build configuration (with "_static" suffix),
the libs are placed synkro/lib/win32 and synkro/lib/win64

To link with static libraries you need to call functions
like SynkroGfxDx11Init() declared in synkrostatic.h
prior to calling SynkroCreate declated in synkro.h

#Windows 11 notes
By default, the demos or tools run in windowed mode.
On very first run, the window size is wrong and the GUI can't be seen.
To fix this, use CTRL+F keystroke to switch to fullscreen mode and back.

# Donations
This project is a work in progress. You can donate for its further development.
BTC wallet: bc1qcc30ghv8gc8msrlf8mduessg3w8wj8jrm2cy68
