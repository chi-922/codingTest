// 리코쳇 로봇

#include <string>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();

    pair<int,int> start, goal;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') start = {i, j};
            if (board[i][j] == 'G') goal = {i, j};
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;

    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == goal.first && c == goal.second)
            return dist[r][c];

        for (int d = 0; d < 4; d++) {
            int nr = r, nc = c;

            // 한 방향으로 끝까지 미끄러짐
            while (true) {
                int tr = nr + dr[d];
                int tc = nc + dc[d];

                if (tr < 0 || tr >= n || tc < 0 || tc >= m)
                    break;
                if (board[tr][tc] == 'D')
                    break;

                nr = tr;
                nc = tc;
            }

            if (dist[nr][nc] != -1)
                continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    return -1;
}
