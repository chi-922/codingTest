#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> visited;
vector<vector<int>> dp;
int N, M;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int dfs(int r, int c) {
	// 홀이거나 보드 밖으로 나가리면 게임 종료
	if (r < 0 || r >= N || c < 0 || c >= M || board[r][c] == 0) return 0;
	
	// 이미 방문한 곳 == 사이클 발견, 무한반복 가능
	if (visited[r][c]) {
		cout << -1;
		exit(0);  // 바로 종료
	}

	// 보드 방문 시작
	if (dp[r][c] != -1) {
		return dp[r][c];
	}

	visited[r][c] = 1;
	dp[r][c] = 0;

	for (int d = 0; d < 4; d++) {
		int nr = r + (board[r][c] * dr[d]);
		int nc = c + (board[r][c] * dc[d]);
		dp[r][c] = max(dp[r][c], dfs(nr, nc) + 1);
	}

	visited[r][c] = 0;

	return dp[r][c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	board.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<int>(M, 0));
	dp.resize(N, vector<int>(M, -1));  // 안 간 곳 -1 세팅

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == 'H') continue;
			board[i][j] = s[j] - '0';
		}
	}

	cout << dfs(0, 0);

	return 0;
}