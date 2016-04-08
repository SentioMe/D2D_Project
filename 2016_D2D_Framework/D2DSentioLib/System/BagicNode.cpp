#include "SentioD2D.h"
#include "BagicNode.h"

namespace DXLib
{
	BagicNode * BagicNode::AddChild(BagicNode * child_)
	{
		assert(child_ != nullptr, "Parameter 'child_' is null!");
		this->_children.push_back(child_);

		return child_;
	}
	bool BagicNode::RemoveChild(BagicNode * child_)
	{
		return false;
	}
}