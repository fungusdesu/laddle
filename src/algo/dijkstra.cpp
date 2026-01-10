#include "algo/dijkstra.hpp"
#include <queue>
#include <climits>
#include <algorithm>

std::vector<int> dijkstra(const std::vector<AdjacencyListEntry>& adjList, const int& src, const int& dest)
{
	int WORD_COUNT = adjList.size();
	std::priority_queue<
		std::pair<int, int>,
		std::vector<std::pair<int, int>>,
		std::greater<std::pair<int, int>>
	> heap;

	std::vector<int> dist(WORD_COUNT, INT_MAX);
	std::vector<int> visited(WORD_COUNT, false);
	std::vector<int> parent(WORD_COUNT, -1);

	dist[src] = 0;
	heap.emplace(0, src);
	bool found = false;

	while (!heap.empty())
	{
		auto top = heap.top();
		heap.pop();

		int distance = top.first;
		int node = top.second;

		if (visited[node]) continue;
		else visited[node] = true;

		if (distance > dist[node]) continue;
		if (node == dest)
		{
			found = true;
			break;
		}

		for (const auto& neighbor : adjList[node].second)
		{
			if (dist[node] + 1 < dist[neighbor] && !visited[neighbor])
			{
				dist[neighbor] = dist[node] + 1;
				parent[neighbor] = node;
				heap.emplace(dist[neighbor], neighbor);
			}
		}
	}

	if (!found)
	{
		return {};
	}

	std::vector<int> path;
	int current = dest;
	while (parent[current] != -1)
	{
		path.push_back(current);
		current = parent[current];
	}
	path.push_back(src);
	std::reverse(path.begin(), path.end());
	return path;
}