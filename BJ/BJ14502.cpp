#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> lab;
int n, m;
int maxv = 0;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int bfs() {
	queue<pair<int, int>> q;
	vector<vector<int>> virus;
	virus = lab; // ���� ����

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (lab[i][j] == 2)
			{
				q.push({ i, j });
			}
		}
	}

	// ���̷��� ��Ʈ����
	while (!q.empty())
	{
		int r = q.front().first, c = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i], nc = c + dc[i];
			if (virus[nr][nc] == 1) continue;
			if (virus[nr][nc] == 0)
			{
				virus[nr][nc] = 2;
				q.push({ nr, nc });
			}
		}
	}

	// �������� ����
	int cnt = 0;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (virus[i][j] == 0) cnt++;
		}
	}

	return cnt;
}

void dfs(int depth) {
	if (depth == 3) {
		// ���̷��� ��Ʈ���� �������� Ȯ��
		int cnt = bfs();
		if (maxv < cnt) maxv = cnt;
		return;
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (lab[i][j] == 0)
			{
				lab[i][j] = 1;
				dfs(depth + 1);
				lab[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	lab.resize(n + 2, vector<int>(m + 2, 1));  // ��� ������

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			cin >> lab[i][j];
		}
	}

	dfs(0);
	cout << maxv;
	return 0;
}