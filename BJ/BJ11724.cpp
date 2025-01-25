#include <iostream>

using namespace std;

int N, M, u, v, cnt = 0;
// 정점, 간선 최대 개수 = 1000개
int arr[1001][1001];
int visited[1001];


void dfs(int now) {
	visited[now] = 1;

	for (int i = 1; i <= N; ++i)
	{
		// 안 가본 곳이고 지금 위치에서 i까지 가는 간선 있다면 깊이탐색
		if (visited[i] == 0 && arr[now][i] == 1) {
			dfs(i);
		}
	}
}


int main() {
	cin >> N >> M;
	while (M--)
	{
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	// 정점이 항상 1부터 나오는 듯 함
	for (int i = 1; i <= N; ++i)
	{
		if (visited[i] == 0) {
			dfs(i);
			cnt += 1;
		}
	}

	cout << cnt;
}