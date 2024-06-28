#ifndef UTILS_FUNCTIONS
#define UTILS_FUNCTIONS
#include <vector>
#include <unordered_set>

template<typename T>
std::vector<T> FindCommonVectorElements(const std::vector<T>& vectorA, const std::vector<T>& vectorB)
{
	std::vector<T> result;

	std::unordered_set<T> set(vectorA.begin(), vectorA.end());

	for (T element : vectorB)
	{
		if (set.find(element) != set.end())
		{
			result.push_back(element);
		}
	}

	return result;
}

#endif