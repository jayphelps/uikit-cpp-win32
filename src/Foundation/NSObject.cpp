#include "NSObject.h"
#include <windows.h>

int NSObjectCount = 0;

NSObject::NSObject() {
    NSObjectCount++;
    
    wchar_t *msg = new wchar_t[3000];
    StringCchPrintfW(msg, 3000, L"NSObject created - %i\n", NSObjectCount);

    OutputDebugStringW(msg);

    delete msg;
}

NSObject::~NSObject() {
    NSObjectCount--;

    wchar_t *msg = new wchar_t[3000];
    StringCchPrintfW(msg, 3000, L"NSObject destroyed - %i\n", NSObjectCount);

    OutputDebugStringW(msg);

    delete msg;
}
