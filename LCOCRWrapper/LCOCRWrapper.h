#pragma once

#include <windows.h>

#ifdef LCOCRWRAPPER_EXPORTS
#define LCOCRWRAPPER_API extern "C" __declspec(dllexport)
#else
#define LCOCRWRAPPER_API extern "C" __declspec(dllimport)
#endif

LCOCRWRAPPER_API HRESULT __cdecl OCRRecognizeFromBuffer(LPBYTE pImageSource, DWORD dwImageSourceSize, LPSTR *ppResult);