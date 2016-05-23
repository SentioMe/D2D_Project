#include "stdafx.h"
#include "TestApplication.h"

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
					   _In_opt_ HINSTANCE hPrevInstance,
					   _In_ LPTSTR lpCmdLine,
					   _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	TestApplication app;

	auto appInstance = DXLib::Application::Instance();
	appInstance->Run();
	appInstance = nullptr;

	return 0;

}