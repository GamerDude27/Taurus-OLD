#pragma once

#ifdef TAURUS_PLATFORM_WINDOWS
#	ifdef TAURUS_BUILD_DLL
#		define TAURUS_API __declspec(dllexport)
#	else
#		define TAURUS_API __declspec(dllimport)
#	endif
#else
#	error The Taurus engine only supports Windows!
#endif
