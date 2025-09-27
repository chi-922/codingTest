#include <iostream>
#include <vector>
#include <queue>

#define INF 10e9

using namespace std;

vector<int> dis;
vector<vector<pair<int, int>>> graph;
int n, m, st, ed;

void dijkstra(int& st) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dis[st] = 0;
	pq.push({ 0, st });

	while (!pq.empty())
	{
		int city = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		if (weight > dis[city]) continue;

		for (int i = 0; i < graph[city].size(); i++)
		{
			int nextCity = graph[city][i].first;
			int load = graph[city][i].second;

			if (weight + load >= dis[nextCity]) continue;
			dis[nextCity] = weight + load;
			pq.push({ weight + load , nextCity });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	dis.resize(n + 1, INF);
	graph.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int u, v, s;
		cin >> u >> v >> s;

		graph[u].push_back({ v, s });
	}
	
	cin >> st >> ed;

	dijkstra(st);

	cout << dis[ed];
	return 0;
}