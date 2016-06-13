#include "stdafx.h"
#include "TestApplication.h"
#include "Source\SceneFactory.h"

TestApplication::TestApplication(void)
{
}

TestApplication::~TestApplication(void)
{
}

bool TestApplication::_OnInitialize(void)
{

	SetRenderingFrame(60.0f);

	if (false == _PreLoadScene(SceneManager::Instance(), "Datas\\SceneList.xml"))
		return false;

	return true;
}

bool TestApplication::_PreLoadScene(SceneManager* sceneManager, const std::string& sceneFile)
{
	SceneFactory fac = SceneFactory(sceneManager);

	return fac.Deserialize(ExtendString::Format("%s\\%s", Application::GetResourceRootPath().c_str(), sceneFile.c_str()).c_str());
}