﻿#pragma once
#include <assert.h>

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	template<typename T>
	class Singleton
	{
	private:
		static T* _instance;

	protected:
		Singleton(void)
		{

		}
		virtual ~Singleton(void)
		{
		}

	public:
		static T* Create(void);

		static bool Destroy(void);

		static T& Instance(void);


	};

	template<typename T>
	T*  Singleton<T>::_instance = nullptr;

	template<typename T>
	T* Singleton<T>::Create(void)
	{
		assert(!_instance && "A instance of singleton is already created");
		_instance = new (std::nothrow) T();
	}

	template<typename T>
	bool Singleton<T>::Destroy(void)
	{
		if (!_instance)
		{
			assert(_instance && "A instance of singleton is already destroyed");
			return false;
		}

		delete _instance;
		_instance = nullptr;

		return true;
	}

	template<typename T>
	T& Singleton<T>::Instance(void)
	{
		assert(_instance && "Maybe, You didn't create this singleton class or, This class was destroyed by your called methode");
		return *_instance;
	}
}