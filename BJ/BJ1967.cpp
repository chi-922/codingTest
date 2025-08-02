#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, u, v, w;
vector<vector<pair<int, int>>> tree;
vector<int> visited;
int maxPath = 0, farNode = 0;

void bfs() {
	visited[1] = 1;
	queue<pair<int, int>> q;
	q.push({ 1, 0 });

	while (!q.empty()) {
		int now = q.front().first;
		int load = q.front().second;
		q.pop();

		for (auto& x : tree[now])
		{
			int next = x.first;
			int weight = x.second;

			if (!visited[next]) {
				visited[next] = 1;
				q.push({ next, load + weight });

				if (load + weight > maxPath) {
					maxPath = load + weight;
					farNode = next;
				}
			}
		}
	}
}

void dfs(int st, int dis) {
	visited[st] = 1;

	if (dis > maxPath) {
		maxPath = dis;
	}

	for (auto& x : tree[st])
	{
		int next = x.first;
		int weight = x.second;

		if (!visited[next]) {
			dfs(next, dis + weight);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	tree.resize(n + 1);
	visited.resize(n + 1, 0);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v >> w;
		tree[u].push_back({ v, w });
		tree[v].push_back({ u, w });
	}

	bfs();
	visited.assign(n + 1, 0);
	maxPath = 0;
	dfs(farNode, 0);

	cout << maxPath;
}