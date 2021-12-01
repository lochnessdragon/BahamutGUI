# Bahamut GUI
![License](https://img.shields.io/github/license/lochnessdragon/BahamutGUI)
![Build Status](https://github.com/lochnessdragon/BahamutGUI/actions/workflows/build.yml/badge.svg)
[![codecov](https://codecov.io/gh/lochnessdragon/BahamutGUI/branch/main/graph/badge.svg?token=PGS5SMHb5A)](https://codecov.io/gh/lochnessdragon/BahamutGUI)

| Lines of Code | Repo Size | Monthly Commits | 
|---------------|-----------|-----------------|
|![Total Lines](https://img.shields.io/tokei/lines/github/lochnessdragon/BahamutGUI)|![GitHub repo size](https://img.shields.io/github/repo-size/lochnessdragon/BahamutGUI)|![Monthly Commits](https://img.shields.io/github/commit-activity/m/lochnessdragon/BahamutGUI)

An open source extensible GUI library. Lets take back the desktop space from electron!

## Usage

### Getting the code
Run this command to clone the code:

`git clone https://github.com/lochnessdragon/BahamutGUI.git`

### Building
**See BUILDING.md for more information**

The build system is set up with premake. In the future, we may add bazel or cmakebuild files, but you shouldn't have any issues with premake for now.

To setup the project for your operating system run the correct .sh or .bat file. For example, on windows, you would run `setup_env_windows.bat` whereas on linux you would run `./setup_env_linux.sh`.

After setting up the project you can open the `.xcworkspace` or `.sln` files in the appropriate code editor for your platform. If you're on linux, I'd suggest using vscode (but I'm not gonna force you) because I've already included some helpful settings in the `.vscode/` folder. However, the chosen build system for linux is make, so you can just run `make config=<config>` where config is one of \[ debug-x86_64 | release-x86_64 etc.\] FYI: If you build the tests with a debug configuration, gcov info will be generated for the tests.

> Note: Arm is not supported as a platform, however, if anyone wants to work on that, that would be much appreciated.

The project/makefile will produce a number of static libraries and executables. They should all be located in the `bin/` directory. I'd suggest running the example application to see what this puppy can do. If you look in the `premake5.lua` in the example directory then you should be able to figure out how to setup a proper build for your own projects.

## Attribution
Main Library:
- [GLFW](https://www.glfw.org/glfw)
- [YogaLayout](https://yogalayout.com/)
- [GLAD](https://glad.dav1d.de/)

Tests:
- [Catch2](https://github.com/catchorg/Catch2)

Example Application: 
- [spdlog](https://github.com/gabime/spdlog)
