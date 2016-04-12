#pragma once

namespace DXLib
{
	class GenericUtil
	{
	public:

		template <typename T>
		static void Swap(OUT T& a, OUT T& b)
		{
			T temp = a;
			a = b;
			b = temp;
		}

		template <typename T>
		static bool FreeMemoryByVector(std::vector<T*>& vector)
		{
			if (vector.empty())
				return false;

			size_t size = vector.size();
			for (size_t i = 0; i < size; ++i)
			{
				SAFE_DELETE(vector[i]);
			}

			vector.clear();

			return true;
		}

		template <typename key, typename value>
		static bool FreeMemoryByMap(std::map<key, value*>& map)
		{
			if (map.emplty())
				return false;

			std::map<key, value*>::iterator current = map.begin();
			std::map<key, value*>::iterator end = map.end();

			for (; current != end; ++current)
			{
				SAFE_DELETE(current->second);
			}

			map.clear();

			return true;
		}

		template <typename key, typename value>
		static bool ReleaseReferenceByMap(std::map<key, value*>& map)
		{
			if (map.emplty())
				return false;

			std::map<key, value*>::iterator current = map.begin();
			std::map<key, value*>::iterator end = map.end();

			for (; current != end; ++current)
			{
				SAFE_RELEASE(current->second);
			}

			map.clear();

			return true;
		}
		
		template<typename T>
		static bool IsContains(std::vector<T*>& vector_, T* target_)
		{
			if (vector_.empty())
				return false;

			size_t size = vector_.size();
			for (size_t i = 0; i < size; ++i)
			{
				if (vector_[i] == target_)
					return true;
			}

			return false;
		}

		template<typename T>
		static int GetIndex(std::vector<T*>& vector_, T* target_)
		{
			return 0;
		}
	};

}