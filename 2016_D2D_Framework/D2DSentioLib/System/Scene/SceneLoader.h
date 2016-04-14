#pragma once
#include <stack>
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class SceneLoader : Singleton<SceneLoader>
	{
	private:
		SceneLoader(void)
		{
		}
		~SceneLoader(void) override
		{
		}

	public:
		Scene* ReplaceScene(const Scene* scene_);
		Scene* PushScene(const Scene* scene_);
		void PopScene(void);

	private:
		Scene* _currentScene;
	};
	
}