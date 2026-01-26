#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int a, b;
vector<vector<int>> board;
vector<vector<int>> visited;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ a, b });
	visited[a][b] = 0;

	while (!q.empty()) {
		int r = q.front().first, c = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int nr = r + dr[d], nc = c + dc[d];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (visited[nr][nc] != -1 || board[nr][nc] == 0) continue;

			visited[nr][nc] = visited[r][c] + 1;
			q.push({ nr, nc });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	board.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2) {
				a = i; b = j;
			}
		}
	}

	bfs();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == -1 && board[i][j] == 0) cout << 0 << ' ';
			else cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
}