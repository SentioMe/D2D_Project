#pragma once

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
	class BagicNode
	{
	public:
		typedef std::vector<BagicNode*> NodeContainer;
		typedef std::vector<BagicNode*>::iterator NodeContainerIter;

	SL_CONSTRUCTOR_ACCESS_LEVEL:
		BagicNode(void)
			: _parent(nullptr), _isAlive(true), _isActive(false),
			_name(ExtendString::STRING_EMPTY), _tag(0)
		{
			this->_children.clear();
		}
		virtual~BagicNode(void)
		{
			this->Release();
		}

	public:
		/** cocos2Dの方法で、割り当てます。*/
		static BagicNode* Create(const std::string& name = ExtendString::STRING_EMPTY);
		/** @warning 初期化の関数はパラメータが様様なので, 仮想関数で取り扱いして再定義する事を禁止します。*/
		bool Initialize(const std::string& name);

//#########################################################################
#pragma region Virtual Function

		/** メンバーのメモリーを解除します。
		@param　bool isDestroyImmediate_ trueならば、子供のノード達を破壊します。（基本 ： true）*/
		virtual void Release(bool isDestroyImmediate = true);

		/** C#の方法で、記述を定義します。*/
		virtual std::string& ToString(void) const;
#pragma endregion
//#########################################################################

//#########################################################################
#pragma region Node Function

		/** このノードの親のノードを設定します。
		すでに親のノードが有れば、そのノードの子供のノードの集まりから削除します。*/
		void SetParent(BagicNode* parent);
		/** 子供のノードの集まりから伝達されたノードを削除します。
		@see BagicNode::Release(bool) ブーリアンの事はこの関数を参照してください。*/
		bool RemoveChild(BagicNode* child, bool isDestroyImmediate = true);
		/** このノードをシーングラフから削除しろ、とリクエストします。
		ノードはリクエストがあったフレームの次のフレームで削除します。*/
		inline void RequestDestroy(void) { this->_isAlive = false; }
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

#pragma endregion
//#########################################################################
	protected:
		bool _isAlive;
		NodeContainer _children;
		PROPERTY_GET(BagicNode*, _parent, Parent);
		PROPERTY(bool, _isActive, IsActive);
		PROPERTY(std::string, _name, Name);
		PROPERTY(int, _tag, Tag);
	};



}