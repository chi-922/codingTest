#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int order[100001] = { 0, };
int cnt = 1;
int n, m, r, u, v;
int visited[100001] = { 0, };

void bfs(int r) {
	queue<int> q;
	q.push(r);
	visited[r] = 1;
	order[r] = cnt++;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();


		for (int next : graph[now])
		{
			if (!visited[next]) {
				visited[next] = 1; // 큐에 넣는 순간 visited 처리
				order[next] = cnt++;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> r;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	bfs(r);

	for (int i = 1; i <= n; i++)
	{
		cout << order[i] << '\n';
	}
}