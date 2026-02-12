#pragma once

#include <unordered_set>
#include <random>

// returns pseudorandom element in an unordered set. pseudorandom is because randomness is traded off for O(1)
template <typename T>
T undsetPseudorandom(std::unordered_set<T> undset)
{
	std::random_device rdev;
	std::mt19937 rgen(rdev());

	int bucket, bucket_size;
	do
	{
		std::uniform_int_distribution<int> idist(0, undset.bucket_count() - 1);
		bucket = idist(rgen);
	}
	while ( (bucket_size = undset.bucket_size(bucket)) == 0 );

	std::uniform_int_distribution<int> idist(0, bucket_size - 1);
	auto element = std::next(undset.begin(bucket), idist(rgen));
	return *element;
}