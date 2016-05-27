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

	if (appInstance->Initialize(
		"D:/MyFiles/Programming/CPlusPluse/Direct2D/D2D_Project/2016_D2D_Framework/D2DTestPart", "AppData.xml"))
		appInstance->Run();

	appInstance = nullptr;

	return 0;

}