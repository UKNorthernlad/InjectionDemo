// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        MessageBox(0, L"Hello from testlib!", L"DLL_PROCESS_ATTACH", MB_ICONINFORMATION);
        break;
    case DLL_THREAD_ATTACH:
        MessageBox(0, L"Hello from testlib!", L"DLL_THREAD_ATTACH", MB_ICONINFORMATION);
        break;
    case DLL_THREAD_DETACH:
        MessageBox(0, L"Hello from testlib!", L"DLL_THREAD_DETACH", MB_ICONINFORMATION);
        break;
    case DLL_PROCESS_DETACH:
        MessageBox(0, L"Hello from testlib!", L"DLL_PROCESS_DETACH", MB_ICONINFORMATION);
        break;
    }
    return TRUE;
}
