#pragma once
#include <stack>
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class SceneLoader sealed : public Singleton<SceneLoader>, public IUpdatable
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
		void Update(float deltaTime) override;

		void ReplaceScene(const Scene* scene_);
		void PushScene(const Scene* scene_);
		void PopScene(void);

		

	private:
		Scene* _nextScene;
		std::stack<Scene*> _sceneStack;
		std::map<std::string, Scene*> _sceneMap; 
		
		PROPERTY_GET(Scene*, _runningScene, CurrentScene);
	};
	
}