#include "pch.h"
// ---------------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------------
BOOL APIENTRY DllMain( HMODULE hModule,DWORD  reason,LPVOID )
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
    {
       mhha::app_t::init_library(hModule);
       break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
// ---------------------------------------------------------------------------------------------------------------------------------------