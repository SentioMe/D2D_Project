#include "SentioD2D.h"
#include "BagicNode.h"

namespace DXLib
{
	BagicNode* BagicNode::Create(void)
	{
		/**
		@brief
			c++에서 동적할당 시, 실패하면 std::bad_alloc이 리턴된다
			이 값은 true/false같은 자료형이 아니므로
			할당 실패에 대한 예외처리가 어려워진다
			이 때문에 std::nothrow로 할당시켜 false로 판단할 수 있게 한다
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