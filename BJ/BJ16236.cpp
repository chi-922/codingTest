#include <iostream>
#include <queue>

using namespace std;

int n, m, ans;
int shark = 2, curx, cury, eat;
int board[20][20], visited[20][20];
int dx[4] = {0, 1, 0, -1};
int dy[4] = { 1, 0, -1, 0 };

int bfs() {
	int dist = 0;
	queue<pair<int, int>> q;
	priority_queue<pair< int, int >, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;

	q.push({ curx, cury });
	visited[curx][cury] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (visited[x][y] == dist) break;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (visited[nx][ny]) continue;

			if (!board[nx][ny] || board[nx][ny] == shark) {
				// 0이거나 내 몸집하고 같은 곳 이동가능
				q.push({ nx, ny });
				visited[nx][ny] = visited[x][y] + 1;
			}
			else if (board[nx][ny] < shark) {
				if (!dist) eat++;
				visited[nx][ny] = visited[x][y] + 1;
				// 최소거리 고정
				dist = visited[nx][ny];
				// 그곳 우선순위 큐에 넣기
				pq.push({ nx, ny });
			}
		}
	}

	if (pq.empty()) return 0;
	
	curx = pq.top().first;
	cury = pq.top().second;

	board[curx][cury] = 0;
	if (eat == shark) {
		shark++;
		eat = 0;
	}
	return visited[curx][cury] - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9) {
				curx = i;
				cury = j;
				// 나중에 상어가 있는 자리로도 이동할 수 있도록 0으로 바꿔줌
				board[i][j] = 0;
			}
		}
	}

	while (true)
	{
		int sec = bfs();
		ans += sec;
		// 더 이동 못 함 = 더 못 먹음
		if (!sec) break;
	}

	cout << ans;
}