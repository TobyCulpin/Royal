#pragma once

#ifdef RL_PLATFORM_WINDOWS
	#ifdef RL_BUILD_DLL
		#define ROYAL_API __declspec(dllexport)
	#else
		#define ROYAL_API __declspec(dllimport)
	#endif
#else
	#error Royal Engine only supports Windows!
#endif