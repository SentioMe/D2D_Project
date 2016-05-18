#include "stdafx.h"
#include "Test.h"


Test::Test()
{
}


Test::~Test()
{
}

int Test::RunTest()
{
	auto app = DXLib::Application::Create();

	

	return app->Run();
}