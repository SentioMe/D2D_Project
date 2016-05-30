#pragma once

#ifndef __DXLIB_SCENE_H__
#define __DXLIB_SCENE_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class Scene : public BagicNode
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		Scene(void)
		{

		}
		virtual~Scene(void) override
		{

		}
	public:
		/** cocos2Dの方法で、割り当てます。*/
		static Scene* Create(const std::string& name = ExtendString::EMPTY);
		/** @warning 初期化の関数はパラメータが様様なので, 仮想関数で取り扱いして再定義する事を禁止します。*/
		bool Initialize(const std::string& name);

		
//#########################################################################
#pragma region Convert Funtion
		std::string		ToString(void)	const override;
#pragma endregion
//#########################################################################
	
	protected:
		virtual void _OnRelease(void) override;

	protected:
		//PROPERTY(Camera* _defaultCamera, Camera);

	};

}
#endif //!__DXLIB_SCENE_H__