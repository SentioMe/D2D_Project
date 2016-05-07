#include "SentioD2D.h"
#include "Scene.h"

namespace DXLib
{


#pragma region Virtual Function
	void Scene::Release(bool isDestroyImmediate)
	{
		BagicNode::Release(isDestroyImmediate);
		
	}

	const std::string& Scene::ToString(void) const
	{
		return ExtendString::Format(
			"%s_Node (Tag : %d)", this->_name.c_str(), this->_tag);
	}

#pragma endregion
}