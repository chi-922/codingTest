#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> trip;
vector<vector<int>> dp;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int dfs(int r, int c) {
    // 도착지에 도달하면 1가지 경로
    if (r == N - 1 && c == M - 1) {
        return 1;
    }

    if (dp[r][c] != -1) {
        return dp[r][c];
    }

    dp[r][c] = 0;  // 처음 방문한 경우 경로 수 0부터 시작

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
            if (trip[nr][nc] < trip[r][c]) {
                dp[r][c] += dfs(nr, nc);
            }
        }
    }

    return dp[r][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    trip.assign(N, vector<int>(M));
    dp.assign(N, vector<int>(M, -1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> trip[i][j];
        }
    }

    cout << dfs(0, 0);

    return 0;
}
