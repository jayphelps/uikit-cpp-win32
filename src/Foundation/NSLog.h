#ifndef NSLOG_H_
#define NSLOG_H_
#pragma once

#include "../CoreFoundation/CoreFoundation.h"
#include "NSObjCRuntime.h"

inline void NSLog(std::wstring format, ...) {
    wchar_t buffer[256];
    va_list args;

    format += L"\n";

    va_start(args, format);
#ifdef _WIN32_WCE
    // @FIXME not safe, but CE doesn't have _s
    vswprintf(buffer, format.c_str(), args);
#else
    vswprintf_s(buffer, 245, format.c_str(), args);
#endif
    va_end(args);

    // Output to Visual Studio Console
    OutputDebugStringW(buffer);
}

// NSLOG_H_
#endif