#include "SentioD2D.h"
#include "BagicNode.h"

namespace DXLib
{
	BagicNode* BagicNode::Create(void)
	{
		/**
		@brief
			c++���� �����Ҵ� ��, �����ϸ� std::bad_alloc�� ���ϵȴ�
			�� ���� true/false���� �ڷ����� �ƴϹǷ�
			�Ҵ� ���п� ���� ����ó���� ���������
			�� ������ std::nothrow�� �Ҵ���� false�� �Ǵ��� �� �ְ� �Ѵ�
		*/
		ALLOCATE(BagicNode, newNode);
		
		if (false == newNode || false == newNode->Initialize())
		{
			SAFE_DELETE(newNode);
		}

		return newNode;
	}

	bool BagicNode::Initialize(void)
	{
		return false;
	}

	void BagicNode::Release(bool isDestroyImmediate_)
	{
		/*if (true == removeChild)
		{
			for (BagicNode* child : _children)
			{
				SAFE_DELETE(child);
			}
		}

		this->_children.clear();
*/


	}

	std::string BagicNode::ToString(void) const
	{
		return StringUtil::Format(
			"%s_Node (Tag : %d)", this->_name.c_str(), this->_tag);
	}


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
		if (true == isDestroyImmediate_)
		{
			SAFE_DELETE(child_);
		}

		return false;
	}

	void BagicNode::_AddChild(BagicNode* child_)
	{
		assert(child_ != nullptr, "Parameter 'child_' is null!");

		this->_children.push_back(child_);
	}
}