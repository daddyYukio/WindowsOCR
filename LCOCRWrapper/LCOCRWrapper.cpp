#include "pch.h"
#include "LCOCRWrapper.h"

using namespace System;
using namespace System::Threading::Tasks;
using namespace System::Runtime::InteropServices;

HRESULT __cdecl OCRRecognizeFromBuffer(LPBYTE pImageSource, DWORD dwImageSourceSize, LPSTR* ppResult)
{
	try {
		cli::array< Byte >^ bmpFileData = gcnew cli::array< Byte >(dwImageSourceSize);
		Marshal::Copy((IntPtr)pImageSource, bmpFileData, 0, dwImageSourceSize);

		LCOCR::OCREngine^ ocr = gcnew LCOCR::OCREngine();

		String^ result = ocr->RecognizeFromBuffer(bmpFileData);

		int len = result->Length;
		char* res = (char*)(void*)Marshal::StringToHGlobalAnsi(result);

		*ppResult = new char[len + 1];
		ZeroMemory(*ppResult, len + 1);

		memcpy_s(*ppResult, len, res, len);

		Marshal::FreeHGlobal((IntPtr)res);
	}
	catch (Exception^ e) {
		return E_FAIL;
	}

	return S_OK;
}
