#pragma once

namespace DXLib
{
	class BagicNode
	{
	public:
		BagicNode(void)
			: _parent(nullptr), _isAlive(true), _isActive(false),
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
		void Release(bool isDestroyImmediate_ = true);

		/** C# style Define description function*/
		virtual std::string ToString(void) const;

		void SetParent(BagicNode* parent_);
		bool RemoveChild(BagicNode* child_, bool isDestroyImmediate_ = true);

		inline void RequestDestroy(void) { this->_isAlive = false; }
		inline bool IsAlive(void) { return _isAlive; }

	protected:
		void _AddChild(BagicNode* child_);

	protected:
		bool _isAlive;
		std::vector<BagicNode*> _children;
		PROPERTY_GET(BagicNode*, _parent, Parent);
		PROPERTY(bool, _isActive, IsActive);
		PROPERTY(std::string, _name, Name);
		PROPERTY(int, _tag, Tag);
	};



}