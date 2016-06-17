#include "SentioD2D.h"
#include "BagicNode.h"

namespace SentioD2DLib
{
	typedef BagicNode::NodeContainer NodeContainer;

	BagicNode* BagicNode::Create(const std::string& name)
	{
		ALLOCATE(BagicNode, newNode);
		
		if (nullptr == newNode || false == newNode->Initialize(name))
		{
			SAFE_DELETE(newNode);
		}

		newNode->SetActive(true);

		return newNode;
	}

	bool BagicNode::Initialize(const std::string& name)
	{
		this->_name = name;
		return _OnInitialize();
	}

	void BagicNode::Release(bool isDestroyImmediate)
	{
		this->SetActive(false);

		if (true == isDestroyImmediate)
		{
			for (BagicNode* child : _children)
			{
				SAFE_DELETE(child);
			}
		}

		this->_children.clear();

		_OnRelease();
	}

	void BagicNode::SetActive(bool active)
	{
		if (_isActive == active)
			return;

		_isActive = active;
		(_isActive) ? _OnActivate() : _OnDeactivate();
	}

	void BagicNode::SetParent(BagicNode* parent)
	{
		assert(parent != nullptr, "Passed parent is null!");

		if (nullptr != this->_parent)
		{
			if (this->_parent == parent)
				return;

			this->_parent->RemoveChild(this, false);
		}

		this->_parent = parent;
		this->_parent->_AddChild(this);
	}

	bool BagicNode::RemoveChild(BagicNode* child, bool isDestroyImmediate)
	{
		NodeContainerIter childIter;
		if (ExtendCollection::TryGetIterator(this->_children, child, childIter))
		{
			this->_children.erase(childIter);
			if (true == isDestroyImmediate)
			{
				SAFE_DELETE(child);
			}

			return true;
		}

		return false;
	}

	BagicNode* BagicNode::FindChild(const std::string& name)
	{
		if (this->_children.empty())
			return nullptr;

		size_t size = this->_children.size();

		for (size_t i = 0; i < size; ++i)
		{
			if (this->_children[i]->GetName() == name)
			{
				return _children[i];
			}
		}

		return nullptr;
	}

	BagicNode* BagicNode::FindChild(int tag)
	{
		if (this->_children.empty())
			return nullptr;

		size_t size = this->_children.size();

		for (size_t i = 0; i < size; ++i)
		{
			if (this->_children[i]->GetTag() == tag)
			{
				return _children[i];
			}
		}

		return nullptr;
	}

	NodeContainer& BagicNode::FindChildren(const std::string& name)
	{
		NodeContainer children;

		size_t size = this->_children.size();

		for (size_t i = 0; i < size; ++i)
		{
			if (this->_children[i]->GetName() == name)
			{
				children.push_back(this->_children[i]);
			}
		}

		return children;
	}

	NodeContainer& BagicNode::FindChildren(int tag)
	{
		NodeContainer children;

		size_t size = this->_children.size();

		for (size_t i = 0; i < size; ++i)
		{
			if (this->_children[i]->GetTag() == tag)
			{
				children.push_back(this->_children[i]);
			}
		}

		return children;
	}

	void BagicNode::_AddChild(BagicNode* child)
	{
		assert(child != nullptr, "Passed child is null!");

		this->_children.push_back(child);
	}

}