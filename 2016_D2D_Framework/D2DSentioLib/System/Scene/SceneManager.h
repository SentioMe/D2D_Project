#pragma once

#ifndef __SENTIO_D2DLIB_SCENE_MANAGER_H__
#define __SENTIO_D2DLIB_SCENE_MANAGER_H__

#include <stack>
/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	class SceneManager sealed : public Singleton<SceneManager>, public IUpdatable
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		SceneManager(void);
		virtual~SceneManager(void) override;

	public:
		void Update(float deltaTime);

		inline bool IsWaitedNextScene(void){ return _nextScene != nullptr; }
		void SetNextScene(void);

		void ReplaceScene(const std::string& sceneName);
		void ReplaceScene(Scene* scene);
		void PushScene(const std::string& sceneName);
		void PushScene(Scene* scene);
		void PopScene(void);

		const Scene* GetLoadedScene(const std::string& sceneName);

		const Scene* LoadScene(Scene* scene);
		bool UnloadScene(Scene* scene);
		bool UnloadScene(const std::string& sceneName);

	private:
		void _UpdateSceneStack(Scene* scene, bool isReplace);
		void _ExitNextScene(void);

	private:
		Scene* _nextScene;
		std::stack<Scene*> _sceneStack;
		std::map<std::string, Scene*> _loadedSceneMap; 

		bool _requestedExitScene;

		PtrPropertyReadonly(Scene, _runningScene, CurrentScene);
	};
	
}
#endif //!__SENTIO_D2DLIB_SCENE_MANAGER_H__