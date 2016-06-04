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
		public Singleton<SceneManager>, public IXMLSerializable, public IUpdatable
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		SceneManager(void)
			: _runningScene(nullptr), _requestedExitScene(false)
		{
			_loadedSceneMap.clear();
		}
		~SceneManager(void) override
		{
		}


	public:
		bool Initialize(OPTIONAL const std::string& sceneFilePath = ExtendString::EMPTY);

		void Update(float deltaTime);

		inline bool IsWaitedNextScene(void){ return _nextScene != nullptr; }
		void SetNextScene(void);

		void ReplaceScene(const std::string& sceneName);
		void ReplaceScene(Scene* scene);
		void PushScene(const std::string& sceneName);
		void PushScene(Scene* scene);
		void PopScene(void);
		
		//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath) override
		{ return true; }
		bool Serialize(XMLSerializer* serializer) override
		{ return true; }
		bool Deserialize(const char* filePath) override
		{ return true; }
		bool Deserialize(XMLSerializer* serializer) override
		{
			return true;
		}
#pragma endregion
		//#########################################################################
	private:
		Scene* _nextScene;
		std::stack<Scene*> _sceneStack;
		std::map<std::string, Scene*> _loadedSceneMap; 

		bool _requestedExitScene;
		
		PtrPropertyReadonly(Scene, _runningScene, CurrentScene);
	};
	
}
#endif //!__DXLIB_SCENE_MANAGER_H__