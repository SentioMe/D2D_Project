#include "stdafx.h"
#include "SceneFactory.h"

//#########################################################################
#pragma region Serialize Function
bool SceneFactory::Serialize(const char* filePath)
{
	XMLSerializer* serializer = new XMLSerializer(filePath);

	if (false == Serialize(serializer))
		return serializer->Close();

	serializer->Save();

	return serializer->Close();
}
bool SceneFactory::Serialize(XMLSerializer* serializer)
{
	return true;
}
bool SceneFactory::Deserialize(const char* filePath)
{
	assert(_sceneManager != nullptr, "SceneManager should not null");

	XMLSerializer* serializer = XMLSerializer::Load(filePath);
	if (serializer == nullptr)
		return false;

	this->Deserialize(serializer);

	return serializer->Close();
}
bool SceneFactory::Deserialize(XMLSerializer* serializer)
{
	int count;
	serializer->Read("SceneCount", count, 0);
	if (count <= 0)
		return false;

	int defaultIndex;
	serializer->Read("DefaultSceneID", defaultIndex, -1);
	if (defaultIndex == -1)
		return false;

	StringContainer sceneNames;
	serializer->ReadVector("SceneNames", sceneNames, count);

	for (int i = 0; i < count; ++i)
	{
		Scene* newScene = _AllocateScene(sceneNames[i].c_str());
		if (newScene != nullptr)
		{
			if (i == defaultIndex)
				_sceneManager->PushScene(newScene);
			else
				_sceneManager->LoadScene(newScene);
		}
	}

	return true;
}
#pragma endregion
//#########################################################################

Scene* SceneFactory::_AllocateScene(const char* key)
{
	if (key == "")
	{
		return nullptr;
	}
	else if (key == "")
	{
		return nullptr;
	}
	else if (key == "")
	{
		return nullptr;
	}
	else if (key == "")
	{
		return nullptr;
	}
	else if (key == "")
	{
		return nullptr;
	}
	else if (key == "")
	{
		return nullptr;
	}

	return Scene::Create(key);
}