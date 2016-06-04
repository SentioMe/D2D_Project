#include "SentioD2D.h"
#include "SceneManager.h"

namespace DXLib
{
	bool SceneManager::Initialize(OPTIONAL const std::string& sceneFilePath)
	{
		return true;
	}

	void SceneManager::Update(float deltaTime)
	{
		if (IsWaitedNextScene())
			this->SetNextScene();

		//_runningScene->Render(deltaTime);
	}

	void SceneManager::SetNextScene(void)
	{
		if (_runningScene != nullptr && _requestedExitScene == true)
			_runningScene->Exit();

		_runningScene = _nextScene;
		_nextScene = nullptr;

		if (nullptr != _runningScene)
			_runningScene->Enter();
	}

	void SceneManager::ReplaceScene(const std::string& sceneName)
	{
		assert(sceneName.empty(), "Passed scene name is empty");

		if (_runningScene == nullptr)
			return;

		Scene* scene = nullptr;
		if (false == ExtendCollection::TryGetValue(_loadedSceneMap, sceneName, scene))
			return;

		if (scene == _nextScene)
			return;

		if (IsWaitedNextScene())
		{
			if (_nextScene->IsActive())
				_nextScene->Exit();

			_nextScene = nullptr;
		}

		_sceneStack.pop();
		_sceneStack.push(scene);
		_nextScene = scene;

		_requestedExitScene = true;
	}

	void SceneManager::ReplaceScene(Scene* scene)
	{
		assert(scene != nullptr, "Passed scene is null");

		if (_runningScene == nullptr)
			return;

		if (scene == _nextScene)
			return;

		if (IsWaitedNextScene())
		{
			if (_nextScene->IsActive())
				_nextScene->Exit();

			_nextScene = nullptr;
		}

		if (false == ExtendCollection::IsContains(_loadedSceneMap, scene->GetName()))
			_loadedSceneMap.insert(std::pair<std::string, Scene*>(scene->GetName(), scene));


		_sceneStack.pop();
		_sceneStack.push(scene);
		_nextScene = scene;

		_requestedExitScene = true;
	}

	void SceneManager::PushScene(const std::string& sceneName)
	{
		assert(sceneName.empty(), "Passed scene name is empty");

		Scene* scene = nullptr;
		if (false == ExtendCollection::TryGetValue(_loadedSceneMap, sceneName, scene))
			return;

		_sceneStack.push(scene);
		_nextScene = scene;

		_requestedExitScene = false;
	}

	void SceneManager::PushScene(Scene* scene)
	{
		assert(scene != nullptr, "Passed scene is null");
		if (false == ExtendCollection::IsContains(_loadedSceneMap, scene->GetName()))
			_loadedSceneMap.insert(std::pair<std::string, Scene*>(scene->GetName(), scene));

		_sceneStack.push(scene);
		_nextScene = scene;

		_requestedExitScene = false;
	}

	void SceneManager::PopScene(void)
	{
		assert(_runningScene != nullptr, "Running scene should not null");

		_sceneStack.pop();

		if (_sceneStack.empty())
		{
			Application::Instance()->Stop();
			return;
		}

		_requestedExitScene = true;
		_nextScene = _sceneStack.top();
	}
}