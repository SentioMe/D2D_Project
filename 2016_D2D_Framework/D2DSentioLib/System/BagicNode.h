#pragma once

namespace DXLib
{
	class BagicNode
	{
	public:
		BagicNode(void)
			: _parent(nullptr), _isActive(false), 
			_name(StringUtil::STRING_EMPTY), _tag(0)
		{
			this->_children.clear();
		}
		~BagicNode(void)
		{
		}

	public:
		/** cocos2D style Allocate function*/
		static BagicNode* Create(void);
		
		bool Initialize(void);
		void Release(bool removeChild = true);

		/** C# style Define description function*/
		virtual std::string ToString(void) const;

		BagicNode* AddChild(BagicNode* child_);
		bool RemoveChild(BagicNode* child_);


	private:


		BagicNode* _parent;
		std::vector<BagicNode*> _children;

		Decl(bool, _isActive, IsActive);
		Decl(std::string, _name, Name);
		Decl(int, _tag, Tag);
	};



}