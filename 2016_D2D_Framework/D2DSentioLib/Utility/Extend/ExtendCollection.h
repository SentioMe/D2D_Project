#pragma once

#ifndef __DXLIB_EXTEND_COLLECTION_H__
#define __DXLIB_EXTEND_COLLECTION_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	/**
	@class ExtendCollection
	@brief テンプレートを使って作成された静的関数の集まり
	*/
	class ExtendCollection sealed
	{
	public:

		/** 伝達された変数二つを交換します。*/
		template <typename T>
		static void Swap(OUT T& a, OUT T& b)
		{
			T temp = a;
			a = b;
			b = temp;
		}

//#########################################################################
#pragma region Release Container

		/** 動的で割り当てたオブジェクト達を入れたvectorのメモリーを解除します。*/
		template <typename T>
		static bool FreeMemoryByVector(std::vector<T*>& container)
		{
			if (container.empty())
				return false;

			size_t size = container.size();
			for (size_t i = 0; i < size; ++i)
			{
				SAFE_DELETE(container[i]);
			}

			container.clear();

			return true;
		}
		/** 動的で割り当てたオブジェクト達を入れたmapのメモリーを解除します。*/
		template <typename key, typename value>
		static bool FreeMemoryByMap(std::map<key, value*>& container)
		{
			if (container.emplty())
				return false;

			std::map<key, value*>::iterator current = container.begin();
			std::map<key, value*>::iterator end = container.end();

			for (; current != end; ++current)
			{
				SAFE_DELETE(current->second);
			}

			container.clear();

			return true;
		}
		/** 動的で割り当てたCOMのオブジェクト達を入れたmapのメモリーを解除します。*/
		template <typename key, typename value>
		static bool ReleaseReferenceByMap(std::map<key, value*>& container)
		{
			if (container.emplty())
				return false;

			std::map<key, value*>::iterator current = container.begin();
			std::map<key, value*>::iterator end = container.end();

			for (; current != end; ++current)
			{
				SAFE_RELEASE(current->second);
			}

			container.clear();

			return true;
		}

#pragma endregion
//#########################################################################

//#########################################################################
#pragma region Check Container

		/** 動的で割り当てたオブジェクト達を入れたvectorに、指定したオブジェクトがあるか確認します。*/
		template<typename T>
		static bool IsContains(std::vector<T*>& container, T* searchedValue)
		{
			if (container.empty())
				return false;

			size_t size = container.size();
			for (size_t i = 0; i < size; ++i)
			{
				if (container[i] == searchedValue)
					return true;
			}

			return false;
		}
		/** 動的で割り当てたオブジェクト達を入れたmapに、指定したキーがあるか確認します。*/
		template <typename key, typename value>
		static bool IsContains(std::map<key, value*>& container, key searchedKey)
		{
			if (container.empty())
				return false;

			std::map<key, value*>::iterator iter = container.find(searchedKey);

			if (iter == container.end())
				return false;

			return true;
		}
		/** 動的で割り当てたオブジェクト達を入れたvectorに、指定したオブジェクトがあるか確認して、そのインデックスを代入します。*/
		template<typename T>
		static bool TryGetIndex(std::vector<T*>& container, T* searchedValue, OUT int& resultIndex)
		{
			resultIndex = -1;
			if (container.empty())
				return false;
				

			size_t size = container.size();
			for (size_t i = 0; i < size; ++i)
			{
				if (container[i] == searchedValue)
				{
					resultIndex = i;
					return true;
				}
					
			}

			return false;
		}
		/** 動的で割り当てたオブジェクト達を入れたvectorに、指定したオブジェクトがあるか確認して、そのイテレータを代入します。
		@warning タイプが明確でないイテレータは、パラメータとして使用することができないので、内部的にイテレータの演算を作成し、任意のタイプを宣言して代わりにする。*/
		template<typename T, typename TIter>
		static bool TryGetIterator(std::vector<T*>& container, T* searchedValue, OUT TIter& resultIter)
		{
			resultIter = container.end();
			if (container.empty())
				return false;


			size_t size = container.size();
			for (size_t i = 0; i < size; ++i)
			{
				if (container[i] == searchedValue)
				{
					resultIter = container.begin() + i;
					return true;
				}

			}

			return false;
		}
		/** 動的で割り当てたオブジェクト達を入れたmapに、指定したキーがあるか確認して、その値を代入します。*/
		template <typename key, typename value>
		static bool TryGetValue(std::map<key, value*>& container, key searchedKey, OUT value*& resultValue)
		{
			resultValue = nullptr;

			if (container.empty())
				return false;

			std::map<key, value*>::iterator iter = container.find(searchedKey);

			if (iter == container.end())
				return false;

			resultValue = iter->second;

			return true;
		}

#pragma endregion
//#########################################################################
	};

}

#endif //!__DXLIB_EXTEND_COLLECTION_H__