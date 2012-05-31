#ifndef NSOBJCRUNTIME_H_
#define NSOBJCRUNTIME_H_
#pragma once

#ifdef __cplusplus
#define FOUNDATION_EXTERN extern "C"
#else
#define FOUNDATION_EXTERN extern
#endif

#define rgb(...) RGB(...)

#define YES (BOOL) 1
#define NO  (BOOL) 0

#define self this

#define readonly  1
#define writeonly 2
#define readwrite 3

typedef int NSInteger;
typedef unsigned int NSUInteger;

#define property(getter, setter)   __declspec( property(get=getter, put=setter) )
#define property_readonly(getter)  __declspec( property(get=getter) )
#define property_writeonly(setter) __declspec( property(put=setter) )

inline void NSLog(std::wstring format, ...) {
    wchar_t buffer[256];
    va_list args;

    format += L"\n";

    va_start(args, format);
        vswprintf_s(buffer, 245, format.c_str(), args);
    va_end(args);

    // Output to Visual Studio Console
    OutputDebugString(buffer);
}

// NSOBJCRUNTIME_H_
#endif