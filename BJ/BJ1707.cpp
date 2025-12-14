#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(int st, vector<vector<int>>& adj, vector<int>& color) {
	queue<int> q;
	q.push(st);
	color[st] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int near : adj[now]) {
			if (!color[near]) {
				color[near] = color[now] * -1;
				q.push(near);
			}
			else if (color[near] * color[now] == 1) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int v, e;
		cin >> v >> e;

		vector<vector<int>> adj(v + 1);
		vector<int> color(v + 1, 0);

		for (int i = 0; i < e; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bool answer;

		for (int i = 1; i < v + 1; i++) {
			if (color[i] == 0) {
				answer = bfs(i, adj, color);
				if (!answer) break;
			}
		}

		cout << (answer ? "YES" : "NO") << '\n';
	}
}