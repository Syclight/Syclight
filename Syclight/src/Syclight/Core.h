#pragma once

#ifndef __SYC_CORE_H__

#ifdef SYC_PLATFORM_WINDOWS
#if SYC_DYNAMIC_LINK
	#ifdef SYC_BUILD_DLL
		#define SYC_API __declspec(dllexport)
	#else
		#define SYC_API __declspec(dllimport)
	#endif // SYC_BUILD_DLL
#else // SYC_DYNAMIC_LINK
	#define SYC_API
#endif
	
#else
	#error Syclight only support Windows!
#endif // SYC_PLATFORM_WINDOWS

#ifdef SYC_DEBUG
	#define SYC_ENABLE_ASSERTS
#endif // DEBUG


#ifdef SYC_ENABLE_ASSERTS
	#define SYC_ASSERT(x, ...) { if(!(x)) { SYC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SYC_CORE_ASSERT(x, ...) { if(!(x)) { SYC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SYC_ASSERT(x, ...)
	#define SYC_CORE_ASSERT(x, ...)
#endif // define SYC_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define SYC_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#endif // !__SYC_CORE_H__
