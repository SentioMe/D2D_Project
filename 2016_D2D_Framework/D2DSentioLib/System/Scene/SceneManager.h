#pragma once

#ifndef __DXLIB_SCENE_MANAGER_H__
#define __DXLIB_SCENE_MANAGER_H__

#include <stack>
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class SceneManager sealed : 
		public Singleton<SceneManager>, public IUpdatable
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		SceneManager(void);
		virtual~SceneManager(void) override;


	public:
		void Release(void);
		void Update(float deltaTime);

		inline bool IsWaitedNextScene(void){ return _nextScene != nullptr; }
		void SetNextScene(void);

		void ReplaceScene(const std::string& sceneName);
		void ReplaceScene(Scene* scene);
		void PushScene(const std::string& sceneName);
		void PushScene(Scene* scene);
		void PopScene(void);

		inline const Scene* GetLoadedScene(const std::string& sceneName)
		{
			Scene* scene = nullptr;
			if (false == ExtendCollection::TryGetValue(_loadedSceneMap, sceneName, scene))
				ExtendString::Format(""); //@todo : add to logger

			return scene;
		}
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
#endif //!__DXLIB_SCENE_MANAGER_H__