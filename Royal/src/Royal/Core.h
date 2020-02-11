#pragma once

#ifdef RL_PLATFORM_WINDOWS
	#ifdef RL_BUILD_DLL
		#define ROYAL_API __declspec(dllexport)
	#else
		#define ROYAL_API __declspec(dllimport)
	#endif
#elif RL_PLATFORM_LINUX
	#define ROYAL_API
#else
	#error Royal Engine only supports Windows and X11 Linux!
#endif

#ifdef RL_DEBUG
	#define RL_ENABLE_ASSERTS
#endif

#ifdef RL_ENABLE_ASSERTS
	#if defined(RL_PLATFORM_WINDOWS)
		#define RL_ASSERT(x, ...) { if(!(x)) { RL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
		#define RL_CORE_ASSERT(x, ...) { if(!(x)) { RL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#elif defined(RL_PLATFORM_LINUX)
		#define RL_ASSERT(x, ...) { if(!(x)) { RL_ERROR("Assertion Failed: {0}", __VA_ARGS__); } }
		#define RL_CORE_ASSERT(x, ...) { if(!(x)) { RL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); } }
	#endif
#else
	#define RL_ASSERT(x, ...)
	#define RL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define RL_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
