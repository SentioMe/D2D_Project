#pragma once


#ifndef __DXLIB_LAYER_H__
#define __DXLIB_LAYER_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/

namespace DXLib
{

	/**
	@class Layer
	@brief 
	*/
	class Layer : public BagicNode
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		Layer(void);
		virtual~Layer(void) override;

	public:
		/** cocos2Dの方法で、割り当てます。*/
		static Layer* Create(const Rect& layerArea, const std::string& name = ExtendString::EMPTY);
		/** @warning 初期化の関数はパラメータが様様なので, 仮想関数で取り扱いして再定義する事を禁止します。*/
		bool Initialize(const Rect& layerArea, const std::string& name);

		

		//#########################################################################
#pragma region Convert Funtion
		inline std::string ToString(void) const override
		{
			return ExtendString::Format("%s_Layer (Tag : %d) Area : ", this->_name.c_str(), this->_tag) + _layerArea.ToString();
		}
#pragma endregion
		//#########################################################################

	protected:
		Rect _layerArea;
	};
}
#endif
