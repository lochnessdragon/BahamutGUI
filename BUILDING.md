# Building BahamutGUI

## Table of Contents
1. Setting up the environment
    - Premake Configuration 
    - Dependencies
    - Code Coverage
2.  Building the project
    - Configurations

## 1) Setting up the development environment

For our build system, we use [premake](https://premake.github.io/). To get started, just run the appropriate script file for your platform.

> For example, on windows, I would run setup_env_windows.bat on the command line.
> However, on MacOS, I would run ./setup_env_macosx.sh

Under the hood, these script files simply run the appropriate premake5 binary (found in tools/[platform])

### Premake Configuration
Premake is a cross platform build configurator. (kinda like cmake) It can generate files for visual studio, xcode, codelite and regular makefiles. By default, the setup scripts generate xcode files on macos, vs files on windows and makefiles on linux. 

> Note: macos support is **limited** at this time, as I do not have recent dev environments, and certainly not an M1. It's only been tested with Mac OS High Sierra.

### Dependencies
Configuring the build system will also download all dependencies. (There is a list of dependencies in the Read Me) There is no need to predownload the dependencies and there is no support for preinstalled libs. 

> You might be wondering why I didn't just use submodules, but that's because I hope to support multiple package managers/installation choices in the future.

### Code Coverage 
Code coverage support is **only** supported on linux with a configuration of debug_x86_64 (see [configurations](#configurations) below). To configure the project with code coverage, run premake with the flag `--code-coverage`. If you need help running premake, read the docs [here](https://premake.github.io/docs/Using-Premake).

To generate code coverage information, run the testing binary. (`./bin/Debug-linux-x86_64/tests/tests`) This will generate the appropriate `.gcna` files in bin-int/. After that, you can use `gcov` or similar to get a human readable form of the data. If you just want the gcov info for BahamutGUI, you can run `./code_coverage.sh`.

## 2) Building the project 

You should be able to easily import the project files into your favorite ide. There are some useful .vscode configurations for the makefile and c/c++ intellisense plugin that are preinstalled in this repo. 

To build with make on the command line, you can run `make config=[config]` where config is one of: debug_x86 | debug_x86_64 | release_x86 | release_x86_64. (see [configurations](#configurations) below)

All the binaries can be found in the `bin/` directory.

### Configurations

You can build the program targeting either debug or release modes. You can either change the setting in your ide or you can run make with a specific config with the argument `config=<config\>`. (See above [#2](#2-building-the-project))