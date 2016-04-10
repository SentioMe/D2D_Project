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
		Alloc(BagicNode, newNode);
		
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

	void BagicNode::Release(bool removeChild)
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

	BagicNode* BagicNode::AddChild(BagicNode* child_)
	{
		assert(child_ != nullptr, "Parameter 'child_' is null!");
		this->_children.push_back(child_);

		return child_;
	}

	bool BagicNode::RemoveChild(BagicNode* child_)
	{
		return false;
	}
}