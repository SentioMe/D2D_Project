#include "SentioD2D.h"
#include "Scene.h"

namespace DXLib
{
	Scene* Scene::Create(const std::string& name)
	{
		ALLOCATE(Scene, newScene);

		if (nullptr == newScene || false == newScene->Initialize(name))
		{
			SAFE_DELETE(newScene);
		}

		return newScene;
	}

	bool Scene::Initialize(const std::string& name)
	{
		Application* appInstance = Application::Instance();

		Rect rect;
		rect.size = appInstance->GetWinRect().size;

		_mainLayer = Layer::Create(rect, MAIN_LAYER_NAME);

		if (_mainLayer == nullptr)
			return false;

		this->_name = name;
		return _OnInitialize();
	}

	void Scene::Enter(void)
	{
		assert(_mainLayer != nullptr, "Main layer should not null");

		if (_isStay == true)
			return;

		_isStay = true;

		_OnEnter();
	}

	void Scene::Exit(void)
	{
		if (_isStay == false)
			return;

		_isStay = false;

		SAFE_DELETE(_mainLayer);

		_OnExit();
	}
}