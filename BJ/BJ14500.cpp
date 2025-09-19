#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> visited;
int n, m;
int maxv = 0;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void dfs(int r, int c, int depth, int cnt) {
	if (depth == 4) {
		maxv = max(cnt, maxv);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i], nc = c + dc[i];
		if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
		if (visited[nr][nc]) continue;

		visited[nr][nc] = 1;
		dfs(nr, nc, depth + 1, cnt + board[nr][nc]);
		visited[nr][nc] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	board.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = 1;
			dfs(i, j, 1, board[i][j]);
			visited[i][j] = 0;

			// ぬ
			if (j + 2 < m && i + 1 < n)
				maxv = max(maxv, board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1]);
			// で
			if (j + 2 < m && i - 1 >= 0)
				maxv = max(maxv, board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i - 1][j + 1]);
			// た
			if (i + 2 < n && j + 1 < m)
				maxv = max(maxv, board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1]);
			// っ
			if (i + 2 < n && j - 1 >= 0)
				maxv = max(maxv, board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j - 1]);
		}
	}

	cout << maxv;
	return 0;
}