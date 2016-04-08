#pragma once

namespace DXLib
{
	class BagicNode
	{
	public:
		BagicNode(void)
			: _parent(nullptr)
		{
			this->_children.clear();
		}
		~BagicNode(void)
		{

		}

	public:
		BagicNode* AddChild(BagicNode* child_);
		bool RemoveChild(BagicNode* child_);


	private:

		BagicNode* _parent;
		std::vector<BagicNode*> _children;
		Decl(bool, _isActive, IsActive);

	};



}