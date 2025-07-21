#include <iostream>
#include <queue>
#include <vector>
#include <functional> // greater

#define INF 1000000000

using namespace std;

int n, e, u, v, w, start;
vector<vector<pair<int, int>>> nodes;
vector<int> dist;

void dijkstra(int& st) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, st });
	dist[st] = 0;

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		// 이미 dist에 cost보다 최단 거리 있음 패스
		if (dist[now] < cost) continue;

		for (auto x : nodes[now])
		{
			int weight = cost + x.first;
			int next = x.second;

			if (weight < dist[next]) {
				dist[next] = weight;
				pq.push({ weight, next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> e;
	cin >> start;
	nodes.resize(n + 1);
	dist.resize(n + 1, INF);

	for (int i = 0; i < e; i++)
	{
		// {무게, 도착노드} 저장
		cin >> u >> v >> w;
		nodes[u].push_back(make_pair(w, v));
	}

	dijkstra(start);

	for (int i = 1; i < n + 1; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
}