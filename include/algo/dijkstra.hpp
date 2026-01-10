#pragma once
#include "Types.hpp"
#include <vector>

std::vector<int> dijkstra(const std::vector<AdjacencyListEntry>& adjList, const int& src, const int& dest);