#pragma once

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	/**
	@class GenericUtil
	@brief テンプレートを使って作成された静的関数の集まり
	*/
	class GenericUtil sealed
	{
	public:

		/** 伝達された変数二つを交換します。*/
		template <typename T>
		static void Swap(OUT T& a_, OUT T& b_)
		{
			T temp = a_;
			a_ = b_;
			b_ = temp;
		}

//#########################################################################
#pragma region Release Container

		/** 動的で割り当てたオブジェクト達を入れたvectorのメモリーを解除します。*/
		template <typename T>
		static bool FreeMemoryByVector(std::vector<T*>& vector_)
		{
			if (vector_.empty())
				return false;

			size_t size = vector_.size();
			for (size_t i = 0; i < size; ++i)
			{
				SAFE_DELETE(vector_[i]);
			}

			vector_.clear();

			return true;
		}
		/** 動的で割り当てたオブジェクト達を入れたmapのメモリーを解除します。*/
		template <typename key, typename value>
		static bool FreeMemoryByMap(std::map<key, value*>& map_)
		{
			if (map_.emplty())
				return false;

			std::map<key, value*>::iterator current = map_.begin();
			std::map<key, value*>::iterator end = map_.end();

			for (; current != end; ++current)
			{
				SAFE_DELETE(current->second);
			}

			map_.clear();

			return true;
		}
		/** 動的で割り当てたCOMのオブジェクト達を入れたmapのメモリーを解除します。*/
		template <typename key, typename value>
		static bool ReleaseReferenceByMap(std::map<key, value*>& map_)
		{
			if (map_.emplty())
				return false;

			std::map<key, value*>::iterator current = map_.begin();
			std::map<key, value*>::iterator end = map_.end();

			for (; current != end; ++current)
			{
				SAFE_RELEASE(current->second);
			}

			map_.clear();

			return true;
		}

#pragma endregion
//#########################################################################

//#########################################################################
#pragma region Check Container

		/** 動的で割り当てたオブジェクト達を入れたvectorに、指定したオブジェクトがあるか確認します。*/
		template<typename T>
		static bool IsContains(std::vector<T*>& vector_, T* value_)
		{
			if (vector_.empty())
				return false;

			size_t size = vector_.size();
			for (size_t i = 0; i < size; ++i)
			{
				if (vector_[i] == value_)
					return true;
			}

			return false;
		}
		/** 動的で割り当てたオブジェクト達を入れたmapに、指定したキーがあるか確認します。*/
		template <typename key, typename value>
		static bool IsContains(std::map<key, value*>& map_, key key_)
		{
			if (map_.empty())
				return false;

			std::map<key, value*>::iterator iter = map_.find(key_);

			if (iter == map_.end())
				return false;

			return true;
		}
		/** 動的で割り当てたオブジェクト達を入れたvectorに、指定したオブジェクトがあるか確認して、そのインデックスを代入します。*/
		template<typename T>
		static bool TryGetIndex(std::vector<T*>& vector_, T* value_, OUT int& index_)
		{
			index_ = -1;
			if (vector_.empty())
				return false;
				

			size_t size = vector_.size();
			for (size_t i = 0; i < size; ++i)
			{
				if (vector_[i] == value_)
				{
					index_ = i;
					return true;
				}
					
			}

			return false;
		}
		/** 動的で割り当てたオブジェクト達を入れたvectorに、指定したオブジェクトがあるか確認して、そのイテレータを代入します。
		@warning タイプが明確でないイテレータは、パラメータとして使用することができないので、内部的にイテレータの演算を作成し、任意のタイプを宣言して代わりにする。*/
		template<typename T, typename TIter>
		static bool TryGetIterator(std::vector<T*>& vector_, T* value_, OUT TIter& iterator_)
		{
			iterator_ = vector_.end();
			if (vector_.empty())
				return false;


			size_t size = vector_.size();
			for (size_t i = 0; i < size; ++i)
			{
				if (vector_[i] == value_)
				{
					iterator_ = vector_.begin() + i;
					return true;
				}

			}

			return false;
		}
		/** 動的で割り当てたオブジェクト達を入れたmapに、指定したキーがあるか確認して、その値を代入します。*/
		template <typename key, typename value>
		static bool TryGetValue(std::map<key, value*>& map_, key key_, OUT value*& value_)
		{
			value_ = nullptr;

			if (map_.empty())
				return false;

			std::map<key, value*>::iterator iter = map_.find(key_);

			if (iter == map_.end())
				return false;

			value_ = iter->second;

			return true;
		}

#pragma endregion
//#########################################################################
	};

}