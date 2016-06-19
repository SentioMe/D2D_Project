#pragma once

USING_SDL;

class SceneFactory : public IXMLSerializable
{
public:
	SceneFactory(SceneManager& sceneManager)
		: _sceneManager(&sceneManager)
	{
	}
	~SceneFactory(void)
	{
		_sceneManager = nullptr;
	}

//#########################################################################
#pragma region Serialize Function
	bool Serialize(const char* filePath) override;
	bool Serialize(XMLSerializer* serializer) override;
	bool Deserialize(const char* filePath) override;
	bool Deserialize(XMLSerializer* serializer) override;
#pragma endregion
//#########################################################################

private:
	Scene* _AllocateScene(const char* key);
	
private:
	SceneManager* _sceneManager;
};