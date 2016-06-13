#include "stdafx.h"
#include "TestApplication.h"

using namespace DXLib;

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
					   _In_opt_ HINSTANCE hPrevInstance,
					   _In_ LPTSTR lpCmdLine,
					   _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	TestApplication app;

	auto appInstance = Application::Instance();

	if (appInstance->Initialize("Datas\\AppData.xml"))
		appInstance->Run();

	appInstance = nullptr;

	return 0;

}