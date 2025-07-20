#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, info, u, v;
vector<vector<int>> adj;
priority_queue<int, vector<int>, greater<>> pq;
vector<int> indegree;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> info;
	adj.resize(n + 1, vector<int>());
	indegree.resize(n + 1, 0);

	for (int i = 0; i < info; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	
	// 진입차수 0인 거 넣기
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty())
	{
		int now = pq.top();
		pq.pop();
		cout << now << ' ';

		for (int x: adj[now])
		{
			--indegree[x];
			if (indegree[x] == 0) {
				pq.push(x);
			}
		}
	}
}