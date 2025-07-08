#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> list;
vector<int> visited;
int visitedOrder = 1;

void dfs(int start)
{
	queue<int> que;

	visited[start] = visitedOrder++;
	que.push(start);

	while (!que.empty())
	{
		int current = que.front();
		que.pop();

		for (int i = 0; i < list[current].size(); i++)
		{
			int next = list[current].at(i);
			if (!visited[next])
			{
				que.push(next);
				visited[next] = visitedOrder++;
			}
		}
	}
}

int main()
{
	int N, M, R;

	cin >> N >> M >> R;

	list = vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int u, v;

		cin >> u >> v;

		list[u].push_back(v);
		list[v].push_back(u);
	}

	for (int i = 0; i < N + 1; i++)
		sort(list[i].begin(), list[i].end(), greater<>());

	dfs(R);

	for (int i = 1; i < N + 1; i++)
		cout << visited[i] << '\n';

	return 0;
}