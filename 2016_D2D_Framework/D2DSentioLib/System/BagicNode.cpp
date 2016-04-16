#include "SentioD2D.h"
#include "BagicNode.h"

namespace DXLib
{
	typedef BagicNode::NodeContainer NodeContainer;


	BagicNode* BagicNode::Create(const std::string& name_)
	{
		ALLOCATE(BagicNode, newNode);
		
		if (false == newNode || false == newNode->Initialize(name_))
		{
			SAFE_DELETE(newNode);
		}

		return newNode;
	}

	bool BagicNode::Initialize(const std::string& name_)
	{
		this->_name = name_;
		return true;
	}
#pragma region Virtual Function
	void BagicNode::Release(bool isDestroyImmediate_)
	{
		if (true == isDestroyImmediate_)
		{
			for (BagicNode* child : _children)
			{
				SAFE_DELETE(child);
			}
		}

		this->_children.clear();

	}

	std::string& BagicNode::ToString(void) const
	{
		return StringUtil::Format(
			"%s_Node (Tag : %d)", this->_name.c_str(), this->_tag);
	}
#pragma endregion

#pragma region Node Function
	void BagicNode::SetParent(BagicNode* parent_)
	{
		assert(parent_ != nullptr, "Parameter 'parent_' is null!");

		if (nullptr != this->_parent)
		{
			if (this->_parent == parent_)
				return;

			this->_parent->RemoveChild(this, false);
		}

		this->_parent = parent_;
		this->_parent->_AddChild(this);
	}

	bool BagicNode::RemoveChild(BagicNode* child_, bool isDestroyImmediate_)
	{
		NodeContainerIter childIter;
		if (GenericUtil::TryGetIterator(this->_children, child_, childIter))
		{
			this->_children.erase(childIter);
		}

		if (true == isDestroyImmediate_)
		{
			SAFE_DELETE(child_);
		}
		
		return false;
	}

	BagicNode* BagicNode::FindChild(const std::string& name_)
	{
		if (this->_children.empty())
			return nullptr;

		size_t size = this->_children.size();

		for (size_t i = 0; i < size; ++i)
		{
			if (this->_children[i]->GetName() == name_)
			{
				return _children[i];
			}
		}

		return nullptr;
	}

	BagicNode* BagicNode::FindChild(int tag_)
	{
		if (this->_children.empty())
			return nullptr;

		size_t size = this->_children.size();

		for (size_t i = 0; i < size; ++i)
		{
			if (this->_children[i]->GetTag() == tag_)
			{
				return _children[i];
			}
		}

		return nullptr;
	}

	NodeContainer& BagicNode::FindChildren(const std::string& name_)
	{
		NodeContainer children;

		size_t size = this->_children.size();

		for (size_t i = 0; i < size; ++i)
		{
			if (this->_children[i]->GetName() == name_)
			{
				children.push_back(this->_children[i]);
			}
		}

		return children;
	}

	NodeContainer& BagicNode::FindChildren(int tag_)
	{
		NodeContainer children;

		size_t size = this->_children.size();

		for (size_t i = 0; i < size; ++i)
		{
			if (this->_children[i]->GetTag() == tag_)
			{
				children.push_back(this->_children[i]);
			}
		}

		return children;
	}

	void BagicNode::_AddChild(BagicNode* child_)
	{
		assert(child_ != nullptr, "Parameter 'child_' is null!");

		this->_children.push_back(child_);
	}
#pragma endregion
}