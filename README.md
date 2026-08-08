# BZCC-DLL-Template

Modern CMake project template for a BZCC dll mission. Uses vcpkg for external libraries. If you don't need that or don't want to set it up use the "no-vcpkg" branch.

### What you need
- CMake 4.0+
- Ninja build
- Latest MSVC build tools or supported IDE
- (Optional) [vcpkg](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started?pivots=shell-powershell) for external libraries

You can install these easily using winget.

### How to use:

Open the project in your IDE of choice or x86 visual studio developer command prompt to build. Only tested on windows using default MSVC build tools.

Set the "path" in the mission editor or in the bzn to the name of your dll to load it in game.
