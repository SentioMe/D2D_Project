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
		static Scene* Create(const std::string& name = ExtendString::STRING_EMPTY);
		/** @warning 初期化の関数はパラメータが様様なので, 仮想関数で取り扱いして再定義する事を禁止します。*/
		bool Initialize(const std::string& name);

		/** C#の方法で、記述を定義します。*/
		virtual const std::string& ToString(void) const override;
	
	protected:
		/** メンバーのメモリーを解除します。
		@param　bool isDestroyImmediate_ trueならば、子供のノード達を破壊します。（基本 ： true）*/
		virtual void _OnRelease(void) override;

	protected:
		//PROPERTY(Camera* _defaultCamera, Camera);

	};

}
#endif //!__DXLIB_SCENE_H__