#pragma once
#include <string>
#include <vector>
#include <optional>
#include <cassert>
#include <iostream>
#include <type_traits>

template <typename It>
std::optional<It> binarySearch(It startIt, It endIt, typename std::iterator_traits<It>::value_type target)
{
	if (startIt == endIt) return std::nullopt;

	auto pivotIt = startIt + (endIt - startIt) / 2;
	if (*pivotIt == target) return pivotIt;
	else if (*pivotIt > target) return binarySearch(startIt, pivotIt, target);
	else return binarySearch(pivotIt + 1, endIt, target);
}