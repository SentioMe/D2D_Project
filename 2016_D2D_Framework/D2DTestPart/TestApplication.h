#pragma once

USING_SDL;

class TestApplication : public Application
{
public:
	TestApplication(void);
	virtual~TestApplication(void) override;

protected:
	virtual bool _OnInitialize(void) override;

	bool _PreLoadScene(SceneManager& sceneManager, const std::string& sceneFile);
};

