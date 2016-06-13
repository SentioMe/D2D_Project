#include "SentioD2D.h"
#include "Layer.h"

namespace DXLib
{
	Layer::Layer(void)
	{
	}


	Layer::~Layer(void)
	{
	}


	/** cocos2Dの方法で、割り当てます。*/
	Layer* Layer::Create(const Rect& layerArea, const std::string& name)
	{
		ALLOCATE(Layer, newLayer);

		if (nullptr == newLayer || false == newLayer->Initialize(layerArea, name))
		{
			SAFE_DELETE(newLayer);
		}

		newLayer->SetActive(true);

		return newLayer;
	}

	/** @warning 初期化の関数はパラメータが様様なので, 仮想関数で取り扱いして再定義する事を禁止します。*/
	bool Layer::Initialize(const Rect& layerArea, const std::string& name)
	{
		this->_layerArea = layerArea;
		this->_name = name;

		return _OnInitialize();
	}
}

