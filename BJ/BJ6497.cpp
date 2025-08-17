#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> city;
vector<int> visited;
int money = 0;
int m, n;

int prim(int st) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	visited[st] = 1;

	// 시작점의 모든 간선들을 pq 삽입
	for (auto& edge : city[st])
	{
		pq.push({ edge.second, edge.first });
	}

	int cnt = 0;
	int ans = 0;

	while (cnt < m && !pq.empty()) {
		int road = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur]) continue;

		visited[cur] = 1;
		ans += road;
		cnt++;

		for (auto& edge : city[cur])
		{
			if (visited[edge.first]) continue;
			pq.push({ edge.second, edge.first });
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		cin >> m >> n;

		if (m == 0 && n == 0) break;

		city.assign(m + 1, {});
		visited.assign(m + 1, 0);
		money = 0;

		for (int i = 0; i < n; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			city[u].push_back({ v, w });
			city[v].push_back({ u, w });
			money += w;
		}
		
		cout << money - prim(1) << '\n';
	}
}