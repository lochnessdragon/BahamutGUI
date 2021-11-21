#pragma once

#if defined(__linux__) || defined(__linux) || defined(linux) || defined(__gnu_linux__)
#define bGUI_PLATFORM_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
#define bGUI_PLATFORM_MACOSX
#elif defined(_WIN32) || defined(_WIN64)
#define bGUI_PLATFORM_WIN32
#endif