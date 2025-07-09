#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, n, ar, ac, nr, nc;
vector<vector<int>> chess;
vector<vector<int>> visited;

void bfs() {
    queue<pair<int, int>> q;
    q.push({ nr, nc });
    visited[nr][nc] = 1;

    int dr[8] = { -2, -2, -1, +1, +2, +2, +1, -1 };
    int dc[8] = { -1, +1, +2, +2, +1, -1, -2, -2 };

    while (!q.empty())
    {
        int fr = q.front().first;
        int fc = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nr2 = fr + dr[i];
            int nc2 = fc + dc[i];

            if (nr2 == ar && nc2 == ac) {
                cout << chess[fr][fc] + 1 << '\n';
                return;
            }

            if (nr2 >= 0 && nr2 < n && nc2 >= 0 && nc2 < n && !visited[nr2][nc2]) {
                q.push({ nr2, nc2 });
                chess[nr2][nc2] = chess[fr][fc] + 1;
                visited[nr2][nc2] = 1;
            }
        }
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> n;

		chess.clear();
		visited.clear();

		chess.resize(n, vector<int>(n, 0));
		visited.resize(n, vector<int>(n, 0));

		cin >> nr >> nc >> ar >> ac;

		if (nr == ar && nc == ac) {
			cout << 0 << '\n';
			continue;
		}

		bfs();
	}
}