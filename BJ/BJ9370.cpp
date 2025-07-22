#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

#define INF 1000000000

using namespace std;

int T, n, m, t, s, g, h, a, b, d;
vector<vector<pair<int, int>>> adj;
vector<int> goal;
vector<int> dist;
vector<int> isvia;

void dijkstra(int& st) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, st });
	dist[st] = 0;

	while (!pq.empty())
	{
		int now = pq.top().second;
		int load = pq.top().first;
		pq.pop();

		if (dist[now] < load) continue;

		for (auto x : adj[now])
		{
			int weight = x.first;
			int next = x.second;

			if (dist[next] >= load + weight) {
				if (isvia[next] && dist[next] == load + weight) continue;
				dist[next] = load + weight;
				pq.push({ load + weight, next });

				isvia[next] = isvia[now];
				if (now == g && next == h) isvia[next] = 1;
				if (now == h && next == g) isvia[next] = 1;
			}
		}
	}
}

int main() {
	cin >> T;

	while (T--)
	{
		cin >> n >> m >> t >> s >> g >> h;
		adj.clear();
		goal.clear();
		dist.clear();
		isvia.clear();
		adj.resize(n + 1);
		dist.resize(n + 1, INF);
		isvia.resize(n + 1, 0);
		goal.resize(t, 0);


		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> d;
			adj[a].push_back({ d, b });   // {¹«°Ô, µµÂø}
			adj[b].push_back({ d, a });   // {¹«°Ô, µµÂø}
		}

		for (int i = 0; i < t; i++)
		{
			cin >> goal[i];
		}

		dijkstra(s);

		sort(goal.begin(), goal.end());

		for (int x : goal)
		{
			if (isvia[x]) cout << x << ' ';
		}
		cout << '\n';
	}
}