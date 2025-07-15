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

// ����ü Ǯ��
/*
#include <iostream>
#include <queue>

using namespace std;

// �丶���� ��ǥ��
typedef struct coordinate {
    int x, y, z;
} xyz;


int M, N, H, tomato; 
int tomato_box[101][101][101];
int visited[101][101][101] = {}; // ���� 0���� �ʱ�ȭ
queue<xyz> q;

int day = 0; // �丶�� �ʹ� �� ���

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };


int bfs() {
    while (!q.empty()) {
        // ���� �丶�� ��ġ
        int now_x = q.front().x;
        int now_y = q.front().y;
        int now_z = q.front().z;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];
            int nz = now_z + dz[i];

            // ���� ���̸� continue
            if (nx < 0 or nx >= M or ny < 0 or ny >= N or nz < 0 or nz >= H) continue;

            // �� ���� �丶�䰡 �ְ� �湮�� ���� ������ ���� �丶��� �ٲٰ� queue�� �־��ֱ�
            if (tomato_box[nz][ny][nx] == 0 and visited[nz][ny][nx] == -1) {
                xyz add_tomato;

                tomato_box[nz][ny][nx] = 1;
                add_tomato.x = nx;
                add_tomato.y = ny;
                add_tomato.z = nz;

                q.push(add_tomato);
                
                visited[nz][ny][nx] = visited[now_z][now_y][now_x] + 1;
            }
        }
    }

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (tomato_box[h][n][m] == 0) return -1; // �丶�䰡 ��� ���� ���ϴ� ���
                day = max(day, visited[h][n][m]);
            }
        }
    }


    return day;
}

int main() {
    cin >> M >> N >> H;
    fill_n(&tomato_box[0][0][0], 101 * 101 * 101, -1);  // ���� �Է� ���� �ʾұ⿡ �丶�� ����!

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> tomato;
                tomato_box[h][n][m] = tomato;

                xyz tomato_coord;
                tomato_coord.x = m;
                tomato_coord.y = n;
                tomato_coord.z = h;

                if (tomato == 1) {  // ���� �丶�� ������ queue�� �����ϱ�
                    q.push(tomato_coord);
                }
                if (tomato == 0) visited[h][n][m] = -1;	// �丶�䰡 ���� �;��� ��츦 ����ؼ� 
            }
        }
    }

    cout << bfs();

    return 0;
}
*/