#pragma once

#ifdef TAURUS_PLATFORM_WINDOWS
#	ifdef TAURUS_BUILD_DLL
#		define TAURUS_API __declspec(dllexport)
#	else
#		define TAURUS_API __declspec(dllimport)
#	endif
#else
#	error The Taurus engine only supports Windows for now.
#endif

#ifdef TAURUS_DEBUG
#	define TAURUS_ENABLE_ASSERTS
#endif

#ifdef TAURUS_ENABLE_ASSERTS
#	define TAURUS_ASSERT(x, ...) { if(!(x)) { TAURUS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#	define TAURUS_CORE_ASSERT(x, ...) { if(!(x)) { TAURUS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#	define TAURUS_ASSERT(x, ...)
#	define TAURUS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define TAURUS_BIND_EVENT_FUNCTION(function) std::bind(&function, this, std::placeholders::_1)
