#include "SentioD2D.h"
#include "SceneManager.h"

namespace SentioD2DLib
{
	SceneManager::SceneManager(void)
		: _runningScene(nullptr), _nextScene(nullptr), _requestedExitScene(false)
	{
		ExtendCollection::Clear(_sceneStack);
		_loadedSceneMap.clear();

		LOG("Create a instacne of SceneManager");
	}
	SceneManager::~SceneManager(void)
	{
		ExtendCollection::Clear(_sceneStack);

		if (_runningScene != nullptr)
			_runningScene->Exit();

		_runningScene = nullptr;

		_ExitNextScene();

		ExtendCollection::Destroy(_loadedSceneMap);

		LOG("Destroy a instacne of SceneManager");
	}

	void SceneManager::Update(float deltaTime)
	{
		if (true == IsWaitedNextScene())
			this->SetNextScene();

		_runningScene->Update(deltaTime);
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
		{
			LOG_WARNING(ExtendString::Format("Is not found a scene : %s", sceneName.c_str()).c_str());
			return;
		}

		if (scene == _nextScene)
			return;

		_ExitNextScene();

		_UpdateSceneStack(scene, true);
	}

	void SceneManager::ReplaceScene(Scene* scene)
	{
		assert(scene != nullptr, "Passed scene is null");

		if (_runningScene == nullptr)
			return;

		if (scene == _nextScene)
			return;

		_ExitNextScene();

		LoadScene(scene);

		_UpdateSceneStack(scene, true);
	}

	void SceneManager::PushScene(const std::string& sceneName)
	{
		assert(sceneName.empty(), "Passed scene name is empty");

		Scene* scene = nullptr;
		if (false == ExtendCollection::TryGetValue(_loadedSceneMap, sceneName, scene))
		{
			LOG_WARNING(ExtendString::Format("Is not found a scene : %s", sceneName.c_str()).c_str());
			return;
		}

		_UpdateSceneStack(scene, false);
	}

	void SceneManager::PushScene(Scene* scene)
	{
		assert(scene != nullptr, "Passed scene is null");

		LoadScene(scene);

		_UpdateSceneStack(scene, false);
	}

	void SceneManager::PopScene(void)
	{
		assert(_runningScene != nullptr, "Running scene should not null");

		_sceneStack.pop();

		if (_sceneStack.empty())
		{
			Application::Instance().Stop();
			return;
		}

		_requestedExitScene = true;
		_nextScene = _sceneStack.top();
	}

	void SceneManager::_UpdateSceneStack(Scene* scene, bool isReplace)
	{
		if (true == isReplace)
			_sceneStack.pop();

		_sceneStack.push(scene);
		_nextScene = scene;

		_requestedExitScene = isReplace;
	}

	void SceneManager::_ExitNextScene(void)
	{
		if (false == IsWaitedNextScene())
			return;

		_nextScene->Exit();

		_nextScene = nullptr;
	}

	const Scene* SceneManager::GetLoadedScene(const std::string& sceneName)
	{
		Scene* scene = nullptr;
		if (false == ExtendCollection::TryGetValue(_loadedSceneMap, sceneName, scene))
			LOG_WARNING(ExtendString::Format("Is not found a scene : %s", sceneName.c_str()).c_str());

		return scene;
	}

	const Scene* SceneManager::LoadScene(Scene* scene)
	{
		assert(scene != nullptr, "Passed scene is null");

		if (false == ExtendCollection::IsContains(_loadedSceneMap, scene->GetName()))
			_loadedSceneMap.insert(std::pair<std::string, Scene*>(scene->GetName(), scene));

		return scene;
	}

	bool SceneManager::UnloadScene(Scene* scene)
	{
		assert(scene != nullptr, "Passed scene is null");

		return UnloadScene(scene->GetName());
	}

	bool SceneManager::UnloadScene(const std::string& sceneName)
	{
		assert(sceneName.empty(), "Passed scene name is empty");

		if (true == ExtendCollection::IsContains(_loadedSceneMap, sceneName))
		{
			_loadedSceneMap.erase(sceneName);
			return true;
		}

		LOG_WARNING(ExtendString::Format("Is not found a scene : %s", sceneName.c_str()).c_str());
		return false;
	}
}