#include <windows.h>
#include <string.h>
#include <string>
#include <iostream>
#include "VirtualDesktops.h"

HRESULT SwitchVirtualDesktop(IVirtualDesktopManagerInternal *pDesktopManager, UINT num) {
	IObjectArray *pDesktops;
	if (pDesktopManager == nullptr || FAILED(pDesktopManager->GetDesktops(&pDesktops))) {
		return E_FAIL;
	}

	HRESULT hres = S_OK;
	IVirtualDesktop *pDesktop;
	if (SUCCEEDED(pDesktops->GetAt(num, __uuidof(IVirtualDesktop), (void**)&pDesktop))) {
		hres = pDesktopManager->SwitchDesktop(pDesktop);
	}
	else {
		hres = E_FAIL;
	}

	return hres;
}

HRESULT InitializeVirtualDesktopManagerInternal(IVirtualDesktopManagerInternal **ppDesktopManager) {
	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	IServiceProvider* pServiceProvider = nullptr;
	if (FAILED(::CoCreateInstance(CLSID_ImmersiveShell, NULL, CLSCTX_LOCAL_SERVER, __uuidof(IServiceProvider), (PVOID*)&pServiceProvider))) {
		return E_FAIL;
	}
	if (FAILED(pServiceProvider->QueryService(CLSID_VirtualDesktopAPI_Unknown, ppDesktopManager))) {
		return E_FAIL;
	}

	return S_OK;
}

INT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR lpCmdLine, INT nCmdShow)
{
	wchar_t *numstr;
	numstr = wcstok_s(lpCmdLine, L" ", &numstr);
	if (numstr == NULL) {
		MessageBoxEx(NULL, TEXT("Desktop number is not specified.\nPass the number via commandline arguments."), TEXT("ERROR"), MB_OK | MB_ICONERROR, 0);
		return 1;
	}
	int num = _wtoi(numstr);

	IVirtualDesktopManagerInternal *pDesktopManager = nullptr;
	InitializeVirtualDesktopManagerInternal(&pDesktopManager);
	if (FAILED(SwitchVirtualDesktop(pDesktopManager, num))) {
		MessageBoxEx(NULL, TEXT("Some error occured. It is possible that the internal API has changed."), TEXT("ERROR"), MB_OK | MB_ICONERROR, 0);
		return 1;
	}

	return 0;
}