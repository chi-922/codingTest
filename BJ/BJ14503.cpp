#include <iostream>
#include <vector>

using namespace std;

int n, m;
int x, y, d;
vector<vector<int>> room;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int solve() {
    int cnt = 0;
    while (true) {
        // 현재 칸 청소
        if (room[x][y] == 0) {
            room[x][y] = -1;
            cnt++;
        }

        // 주변 4칸 중 청소 안 한 칸 있는지 확인
        bool hasUnclean = false;
        for (int i = 0; i < 4; i++) {
            int nr = x + dr[i], nc = y + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (room[nr][nc] == 0) { hasUnclean = true; break; }
        }

        if (hasUnclean) {
            // 왼쪽 회전
            d = (d + 3) % 4;
            int nr = x + dr[d], nc = y + dc[d];
            if (room[nr][nc] == 0) {
                x = nr; y = nc;
            }
            // 아니라면 방향만 바꾸고 다시 루프
        }
        else {
            // 뒤로 이동
            int back = (d + 2) % 4;
            int nr = x + dr[back], nc = y + dc[back];
            if (room[nr][nc] == 1) return cnt; // 뒤가 벽이면 종료
            x = nr; y = nc;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	cin >> x >> y >> d;
	
	room.resize(n, vector<int>(m, 1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> room[i][j];
		}
	}

	cout << solve();
	return 0;
}