#include "SentioD2D.h"
#include "Application.h"

namespace DXLib
{
	static void PVRFrameEnableControlWindow(bool bEnable);

	int Application::Run(void)
	{
		PVRFrameEnableControlWindow(false);

		LARGE_INTEGER last;
		LARGE_INTEGER now;

		QueryPerformanceCounter(&last);

		auto director = Director::Create();

		while (true)
		{
			QueryPerformanceCounter(&now);

			if (now.QuadPart - last.QuadPart > _renderingInterval.QuadPart)
			{
				last.QuadPart = now.QuadPart - (now.QuadPart % _renderingInterval.QuadPart);

				director->Run();
			}
			else
			{
				Sleep(1);
			}

		}

		director->Destroy();

		return 0;
	}

	void Application::SetRenderingFrameCount(int frameCount)
	{
		float interval = 1.0f / (float)frameCount;
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		_renderingInterval.QuadPart = (LONGLONG)(interval * frequency.QuadPart);
	}


	static void PVRFrameEnableControlWindow(bool bEnable)
	{
		HKEY hKey = 0;

		// Open PVRFrame control key, if not exist create it.
		if (ERROR_SUCCESS != RegCreateKeyExW(HKEY_CURRENT_USER,
			L"Software\\Imagination Technologies\\PVRVFRame\\STARTUP\\",
			0,
			0,
			REG_OPTION_NON_VOLATILE,
			KEY_ALL_ACCESS,
			0,
			&hKey,
			nullptr))
		{
			return;
		}

		const WCHAR* wszValue = L"hide_gui";
		const WCHAR* wszNewData = (bEnable) ? L"NO" : L"YES";
		WCHAR wszOldData[256] = { 0 };
		DWORD   dwSize = sizeof(wszOldData);
		LSTATUS status = RegQueryValueExW(hKey, wszValue, 0, nullptr, (LPBYTE)wszOldData, &dwSize);
		if (ERROR_FILE_NOT_FOUND == status              // the key not exist
			|| (ERROR_SUCCESS == status                 // or the hide_gui value is exist
			&& 0 != wcscmp(wszNewData, wszOldData)))    // but new data and old data not equal
		{
			dwSize = sizeof(WCHAR) * (wcslen(wszNewData) + 1);
			RegSetValueEx(hKey, wszValue, 0, REG_SZ, (const BYTE *)wszNewData, dwSize);
		}

		RegCloseKey(hKey);
	}
}
