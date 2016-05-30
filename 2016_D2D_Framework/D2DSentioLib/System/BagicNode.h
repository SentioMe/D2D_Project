#pragma once


#ifndef __DXLIB_BAGIC_NODE_H__
#define __DXLIB_BAGIC_NODE_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/

namespace DXLib
{
	
	/**
	@class BagicNode
	@brief シーングラフをなす様様のノード達の原型
	*/
	class BagicNode : public IConvertible
	{
	public:
		typedef std::vector<BagicNode*> NodeContainer;
		typedef std::vector<BagicNode*>::iterator NodeContainerIter;

	SL_CONSTRUCTOR_ACCESS_LEVEL:
		BagicNode(void)
			: _parent(nullptr), _isAlive(true), _isActive(false),
			_name(ExtendString::EMPTY), _tag(0)
		{
			this->_children.clear();
		}
		virtual~BagicNode(void)
		{
			this->Release();
		}

	public:
		/** cocos2Dの方法で、割り当てます。*/
		static BagicNode* Create(const std::string& name = ExtendString::EMPTY);
		/** @warning 初期化の関数はパラメータが様様なので, 仮想関数で取り扱いして再定義する事を禁止します。*/
		bool Initialize(const std::string& name);

		/** メンバーのメモリーを解除します。
		@param　bool isDestroyImmediate_ trueならば、子供のノード達を破壊します。（基本 ： true）*/
		void Release(bool isDestroyImmediate = true);

//#########################################################################
#pragma region Convert Funtion
		std::string		ToString(void)	const override;
#pragma endregion
//#########################################################################

		/** このノードの親のノードを設定します。
		すでに親のノードが有れば、そのノードの子供のノードの集まりから削除します。*/
		void SetParent(BagicNode* parent);
		/** 子供のノードの集まりから伝達されたノードを削除します。
		@see BagicNode::Release(bool) ブーリアンの事はこの関数を参照してください。*/
		bool RemoveChild(BagicNode* child, bool isDestroyImmediate = true);
		/** このノードをシーングラフから削除しろ、とリクエストします。
		ノードはリクエストがあったフレームの次のフレームで削除します。*/
		inline void RequestDestroy(void) { this->_isAlive = false; }
		/** 伝達されたノードをシーングラフから削除しろ、とリクエストします。*/
		inline static void RequestDestroy(BagicNode* node){ node->RequestDestroy(); }
		/** このノードが生存しているか確認するため使用されます。*/
		inline bool IsAlive(void) { return _isAlive; }
		/** 子供のノードの集まりから指定した名前のノードを探して返されします。*/
		BagicNode* FindChild(const std::string& name_);
		/** 子供のノードの集まりから指定したタグのノードを探して返されします。*/
		BagicNode* FindChild(int tag);
		/** 子供のノードの集まりから指定した名前のノード達を探して返されします。*/
		NodeContainer& FindChildren(const std::string& name_);
		/** 子供のノードの集まりから指定したタグのノード達を探して返されします。*/
		NodeContainer& FindChildren(int tag);

		
	protected:
		/** 伝達されたノードを子供のノードの集まりに追加します。
		@warning　この関数は例外処理をするために使用されます。*/
		void _AddChild(BagicNode* child);

		/** 継承したクラスでオーバーライド可能な初期化の関数*/
		virtual bool _OnInitialize(void){ return true; }
		/** 継承したクラスでオーバーライド可能なメモリーの解除の関数*/
		virtual void _OnRelease(void){}

	protected:
		bool _isAlive;
		NodeContainer _children;
		PtrPropertyReadonly(BagicNode, _parent, Parent);
		Property(bool, _isActive, IsActive);
		Property(std::string, _name, Name);
		Property(int, _tag, Tag);
	};



}

#endif //!__DXLIB_BAGIC_NODE_H__