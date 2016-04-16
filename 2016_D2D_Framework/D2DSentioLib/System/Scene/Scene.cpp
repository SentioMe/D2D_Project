#include "SentioD2D.h"
#include "Scene.h"

namespace DXLib
{


#pragma region Virtual Function
	void Scene::Release(bool isDestroyImmediate_)
	{
		BagicNode::Release(isDestroyImmediate_);
		
	}

	std::string& Scene::ToString(void) const
	{
		return StringUtil::Format(
			"%s_Node (Tag : %d)", this->_name.c_str(), this->_tag);
	}
#pragma endregion
}