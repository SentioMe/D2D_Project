#include "SentioD2D.h"
#include "Scene.h"

namespace DXLib
{


	void Scene::_OnRelease(void)
	{
		
	}

//#########################################################################
#pragma region Convert Funtion
	std::string		Scene::ToString(void)	const
	{
		return ExtendString::Format(
			"%s_Node (Tag : %d)", this->_name.c_str(), this->_tag);
	}

#pragma endregion
//#########################################################################
}