#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
vector<int> graph[100001];   // vertor<int>�� 100001�� ���ִ� �迭
int visited[100001] = { 0, };
int order[100001] = { 0, };
int cnt = 1;


void dfs(int& r) {
	visited[r] = 1;
	order[r] = cnt;
	cnt++;

	for (int next : graph[r])
	{
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> R;

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// ���� �� "���� ��ȣ�� ������������ �湮"
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(R);

	// ��� ���
	for (int i = 1; i <= N; i++) {
		cout << order[i] << '\n';
	}
}