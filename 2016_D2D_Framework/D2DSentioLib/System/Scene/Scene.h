#pragma once

#ifndef __DXLIB_SCENE_H__
#define __DXLIB_SCENE_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
#define MAIN_LAYER_NAME "MainLayer"

	class Scene : public IConvertible
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		Scene(void)
			: _mainLayer(nullptr), _isStay(false)
		{
		}
		virtual~Scene(void)
		{
			this->Exit();
		}
	public:
		/** cocos2Dの方法で、割り当てます。*/
		static Scene* Create(const std::string& name = ExtendString::EMPTY);
		/** @warning 初期化の関数はパラメータが様様なので, 仮想関数で取り扱いして再定義する事を禁止します。*/
		bool Initialize(const std::string& name);

		void Enter(void);
		void Exit(void);

		void Update(float deltaTime){ _OnUpdate(deltaTime); }
		void LateUpdate(float deltaTime){ _OnLateUpdate(deltaTime); }
		
//#########################################################################
#pragma region Convert Funtion
		inline std::string ToString(void) const
		{ return ExtendString::Format("%s_Scene (Tag : %d)", this->_name.c_str()); }
#pragma endregion
//#########################################################################
	protected:
		virtual bool _OnInitialize(void){ return true; }
		virtual void _OnEnter(void){}
		virtual void _OnExit(void){}

		virtual void _OnUpdate(float deltaTime){}
		virtual void _OnLateUpdate(float deltaTime){}

	private:
		bool _isStay;

	protected:
		Property(std::string, _name, Name);
		PtrPropertyReadonly(Layer, _mainLayer, MainLayer);
		//PROPERTY(Camera* _defaultCamera, Camera);
	};

}
#endif //!__DXLIB_SCENE_H__