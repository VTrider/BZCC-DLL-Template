# BZCC-DLL-Template

To break the tradition of gatekeepy POS bz2 modders, here is a simple template for BZCC DLL Missions. It has all the script utils and library dependencies included, and the project file is properly configured with the includes and set to x86 and C++20.

### How to use:
Simply open the solution in visual studio and configure the project name to your liking. Compile in release mode when you're ready to ship for best performance. In your bzn set the script path to your .dll file.

### Tips:
- Publish your DLL with an open source license, help the community grow its modding knowledge
- Follow the BZ naming convention outlined in ScriptUtils.h(camelCase variables and PascalCase functions/classes)
- Split up your modules and classes into sensible chunks, keep the stock event handlers like Update() clean and consise, no 1000 line Update functions
- Don't code like it's 1999:
  ```cpp
  int[] array = new int[10]; // BAD, don't use raw arrays and especially not with malloc or new
  std::array<int, 10> array{}; // Good if it's not resizable
  std::vector<int> array(10); // Good if it's resizable

  BOOL DoSomethingInGame(DWORD param); // BAD, don't use windows api macros or typedefs unless you are working with the windows api
  bool DoSomethingInGame(int param); // Good

  const char* message; // BAD, unless it's being used exclusively with functions in the ScriptUtils API
  // (if you find yourself needing strncmp and such it's time to use std::string)
  std::string message; // Good, use the c_str() method if you need to pass it into a bz function
  ```
