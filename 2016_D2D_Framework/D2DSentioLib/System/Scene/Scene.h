#pragma once

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
		static Scene* Create(const std::string& name_ = StringUtil::STRING_EMPTY);
		/** @warning 初期化の関数はパラメータが様様なので, 仮想関数で取り扱いして再定義する事を禁止します。*/
		bool Initialize(const std::string& name_);

		//#########################################################################
#pragma region Virtual Function
		/** メンバーのメモリーを解除します。
		@param　bool isDestroyImmediate_ trueならば、子供のノード達を破壊します。（基本 ： true）*/
		virtual void Release(bool isDestroyImmediate_ = true) override;

		/** C#の方法で、記述を定義します。*/
		virtual std::string& ToString(void) const override;
#pragma endregion
		//#########################################################################
	
	protected:
		//PROPERTY(Camera* _defaultCamera, Camera);

	};

}