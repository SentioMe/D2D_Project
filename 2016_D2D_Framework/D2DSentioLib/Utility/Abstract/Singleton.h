#pragma once

#ifndef __SENTIO_D2DLIB_SINGLETON_H__
#define __SENTIO_D2DLIB_SINGLETON_H__

#include <assert.h>
#include "LibConfig.h"
/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	template<typename T>
	class Singleton
	{
	private:
		static T* _instance;

	SL_CONSTRUCTOR_ACCESS_LEVEL:
		Singleton(void)
		{

		}
		virtual ~Singleton(void)
		{
		}

	protected:
		void _Overwrite(T* instance);

	public:
		static T* Create(void);

		bool Destroy(void);

		static T* Instance(void);


	};

	template<typename T>
	T*  Singleton<T>::_instance = nullptr;

	template<typename T>
	void Singleton<T>::_Overwrite(T* instance)
	{
		if (_instance != nullptr)
			_instance->Destroy();

		assert(instance != nullptr && "Passed instance is null");
		_instance = instance;
	}

	template<typename T>
	T* Singleton<T>::Create(void)
	{
		assert(_instance == nullptr && "A instance of singleton is already created");
		_instance = new (std::nothrow) T();

		return _instance;
	}

	template<typename T>
	bool Singleton<T>::Destroy(void)
	{
		if (!_instance)
		{
			assert(_instance != nullptr && "A instance of singleton is already destroyed");
			return false;
		}

		delete _instance;
		_instance = nullptr;

		return true;
	}

	template<typename T>
	T* Singleton<T>::Instance(void)
	{
		assert(_instance != nullptr && "Maybe, You didn't create this singleton class or, This class was destroyed by your called methode");
		return _instance;
	}
}

#endif //!__SENTIO_D2DLIB_SINGLETON_H__