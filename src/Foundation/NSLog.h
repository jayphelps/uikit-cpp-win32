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
        vswprintf_s(buffer, 245, format.c_str(), args);
    va_end(args);

    // Output to Visual Studio Console
    OutputDebugStringW(buffer);
}

// NSLOG_H_
#endif