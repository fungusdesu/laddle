#pragma once
#include <unordered_set>
#include <utility>

using Neighbor = std::unordered_set<int>;
using AdjacencyListEntry = std::pair<int, Neighbor>;