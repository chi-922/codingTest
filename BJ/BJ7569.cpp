#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

int m, n, h;
vector<vector<vector<int>>> tomatos;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int bfs() {
    queue<array<int, 3>> q;
    int days = -1;  // ó�� ���۵� �Ϸ�� ���ֵ� (�������� +1 ����)

    // �ʱ� ���� �丶�� ť�� �ֱ�
    for (int z = 0; z < h; ++z)
        for (int y = 0; y < m; ++y)
            for (int x = 0; x < n; ++x)
                if (tomatos[z][y][x] == 1)
                    q.push({ z, y, x });

    while (!q.empty()) {
        int sz = q.size();
        days++;  // �Ϸ� ���

        while (sz--) {
            auto [z, y, x] = q.front(); q.pop();

            for (int d = 0; d < 6; d++) {
                int nz = z + dz[d];
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (nz < 0 || nz >= h || ny < 0 || ny >= m || nx < 0 || nx >= n)
                    continue;

                if (tomatos[nz][ny][nx] == 0) {
                    tomatos[nz][ny][nx] = 1;
                    q.push({ nz, ny, nx });
                }
            }
        }
    }

    // �˻�: ���� �� ���� �丶�� �ִ���
    for (int z = 0; z < h; z++)
        for (int y = 0; y < m; y++)
            for (int x = 0; x < n; x++)
                if (tomatos[z][y][x] == 0)
                    return -1;

    return days;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> h;

    tomatos.resize(h, vector<vector<int>>(m, vector<int>(n)));

    for (int z = 0; z < h; z++)
        for (int y = 0; y < m; y++)
            for (int x = 0; x < n; x++)
                cin >> tomatos[z][y][x];

    cout << bfs();
    return 0;
}
