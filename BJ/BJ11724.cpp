#include <iostream>

using namespace std;

int N, M, u, v, cnt = 0;
// ����, ���� �ִ� ���� = 1000��
int arr[1001][1001];
int visited[1001];


void dfs(int now) {
	visited[now] = 1;

	for (int i = 1; i <= N; ++i)
	{
		// �� ���� ���̰� ���� ��ġ���� i���� ���� ���� �ִٸ� ����Ž��
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

	// ������ �׻� 1���� ������ �� ��
	for (int i = 1; i <= N; ++i)
	{
		if (visited[i] == 0) {
			dfs(i);
			cnt += 1;
		}
	}

	cout << cnt;
}