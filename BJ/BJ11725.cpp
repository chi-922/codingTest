#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> par;
vector<int> visited;
vector<vector<int>> adj;

void bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while (!q.empty())
	{
		int parent = q.front();
		q.pop();
		for (int x : adj[parent])
		{
			if (!visited[x]) {
				visited[x] = 1;
				par[x] = parent;
				q.push(x);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	
	int a, b;
	par.resize(n + 1, 0);  // idx = node ¹øÈ£
	visited.resize(n + 1, 0);
	adj.resize(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bfs();

	for (int i = 2; i < n + 1; i++)
	{
		cout << par[i] << '\n';
	}
}