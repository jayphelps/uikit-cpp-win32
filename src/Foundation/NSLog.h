#ifndef NSLOG_H_
#define NSLOG_H_
#pragma once

#include "../CoreFoundation/CoreFoundation.h"
#include "NSObjCRuntime.h"

// CE5 doesn't have _s variants and their vswprintf is broken
#ifdef _WIN32_WCE
  #include <strsafe.h>
#endif

inline void NSLog(std::wstring format, ...) {
    wchar_t buffer[256];
    va_list args;

    format += L"\n";

    va_start(args, format);
#ifdef _WIN32_WCE
    // CE5 doesn't have _s variants of sprintf but these are
    // suppose to be "safe"
    StringCchVPrintf(buffer, 256, format.c_str(), args);
#else
    vswprintf_s(buffer, 256, format.c_str(), args);
#endif
    va_end(args);
        
// IMPORTANT: the va_list isn't working correctly in CE 5..
// its outputting an address instead? Removing until
// I can figure it out..that means NO NSLog will do anything
#ifndef _WIN32_WCE
    // Output to Visual Studio Console
    OutputDebugStringW(buffer);
#endif
}

// NSLOG_H_
#endif