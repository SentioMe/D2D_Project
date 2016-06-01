#pragma once

#ifndef __DXLIB_SCENE_LOADER_H__
#define __DXLIB_SCENE_LOADER_H__

#include <stack>
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class SceneLoader sealed : 
		public Singleton<SceneLoader>, public IXMLSerializable, public IUpdatable
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		SceneLoader(void)
			: _runningScene(nullptr)
		{
		}
		~SceneLoader(void) override
		{
		}


	public:
		bool Initialize(OPTIONAL const std::string& sceneFilePath = ExtendString::EMPTY);

		void Update(float deltaTime) override;

		void ReplaceScene(const Scene* scene);
		void PushScene(const Scene* scene);
		void PopScene(void);

		//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath) override
		{ return true; }
		bool Serialize(XMLSerializer* serializer) override;
		bool Deserialize(const char* filePath) override
		{ return true; }
		bool Deserialize(XMLSerializer* serializer) override;
#pragma endregion
		//#########################################################################
	private:
		Scene* _nextScene;
		std::stack<Scene*> _sceneStack;
		std::map<std::string, Scene*> _sceneMap; 
		
		PtrPropertyReadonly(Scene, _runningScene, CurrentScene);
	};
	
}
#endif //!__DXLIB_SCENE_LOADER_H__